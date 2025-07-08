#include "tlb.h"
#include "memory.h"

void cache_tlb::initialize( uintptr_t cr3, cache_tlb_config tlb_config ) {
	m_cr3 = cr3;
	m_config = tlb_config;

	initialize_pml4_cache();
}

void cache_tlb::initialize_pml4_cache() {
	page_table_entry pml4[ 512 ] = {};
	if ( !read_physical_memory( m_cr3, &pml4, sizeof( pml4 ) ) )
		return;

	for ( int i = 0; i < 512; i++ ) {
		if ( !pml4[ i ].present() )
			continue;

		if ( !m_entries[ i ] ) {
			m_entries[ i ] = new tlb_cache_line;
			memset( m_entries[ i ], 0, sizeof( tlb_cache_line ) );
		}

		m_entries[ i ]->m_pml4e.m_valid = true;
		m_entries[ i ]->m_pml4e.m_entry = pml4[ i ];

		if ( m_config.m_pdpt_pre_cache ) {
			initialize_pdpt_cache( m_entries[ i ], pml4[ i ].address() );
		}
	}
}

void cache_tlb::initialize_pdpt_cache( tlb_cache_line* pml4, uintptr_t pdpt_phys ) {
	page_table_entry pdpt[ 512 ] = {};
	if ( !read_physical_memory( pdpt_phys, &pdpt, sizeof( pdpt ) ) )
		return;

	for ( int i = 0; i < 512; i++ ) {
		if ( !pml4->m_pml4e.m_entry.present() )
			continue;

		if ( !pml4->m_pdpt[ i ] ) {
			pml4->m_pdpt[ i ] = new pdpt_cache_line;
			memset( pml4->m_pdpt[ i ], 0, sizeof( pdpt_cache_line ) );
		}

		pml4->m_pdpt[ i ]->m_pdpte.m_valid = true;
		pml4->m_pdpt[ i ]->m_pdpte.m_entry = pdpt[ i ];

		if ( m_config.m_pd_pre_cache ) {
			initialize_pd_cache( pml4->m_pdpt[ i ], pdpt[ i ].address() );
		}
	}
}

void cache_tlb::initialize_pd_cache( pdpt_cache_line* pdpt, uintptr_t pd_phys ) {
	page_table_entry pd[ 512 ] = {};
	if ( !read_physical_memory( pd_phys, &pd, sizeof( pd ) ) ) 
		return;

	for ( int i = 0; i < 512; i++ ) {
		if ( !pd[ i ].present() )
			continue;

		if ( !pdpt->m_pd[ i ] ) {
			pdpt->m_pd[ i ] = new pd_cache_line;
			memset( pdpt->m_pd[ i ], 0, sizeof( pd_cache_line ) );
		}

		pdpt->m_pd[ i ]->m_pde.m_valid = true;
		pdpt->m_pd[ i ]->m_pde.m_entry = pd[ i ];

		if ( m_config.m_pt_pre_cache ) {
			// not implemented yet
		}
	}
}

tlb_cache_line* cache_tlb::get_or_load_pml4_entry( uint16_t pml4_index ) {
	if ( pml4_index >= 512 )
		return nullptr;

	if ( !m_entries[ pml4_index ] ) {
		m_entries[ pml4_index ] = new tlb_cache_line;
		memset( m_entries[ pml4_index ], 0, sizeof( tlb_cache_line ) );
	}

	tlb_cache_line* pml4 = m_entries[ pml4_index ];

	if ( pml4->m_pml4e.m_access_count > m_config.m_pml4_invalidation_access_count ) {
		for ( int i = 0; i < 512; i++ ) {
			if ( pml4->m_pdpt[ i ] ) {
				pml4->m_pdpt[ i ]->m_pdpte.m_valid = false;
			}
		}

		pml4->m_pml4e.m_valid = false;
	}

	if ( !pml4->m_pml4e.m_valid ) {
		page_table_entry new_pml4e = {};
		if ( !read_physical_memory( m_cr3 + ( pml4_index * sizeof( uintptr_t ) ), &new_pml4e, sizeof( new_pml4e ) ) ) {
			pml4->m_pml4e.m_valid = false;
			return nullptr;
		}

		if ( !new_pml4e.present() ) {
			pml4->m_pml4e.m_valid = false;
			return nullptr;
		}

		pml4->m_pml4e.m_valid = true;
		pml4->m_pml4e.m_access_count = 0;
		pml4->m_pml4e.m_entry = new_pml4e;
	}

	pml4->m_pml4e.m_access_count++;
	return pml4;
}

pdpt_cache_line* cache_tlb::get_or_load_pdpt_entry( tlb_cache_line* pml4, uint16_t pdpt_index ) {
	if ( pdpt_index >= 512 )
		return nullptr;

	if ( !pml4->m_pdpt[ pdpt_index ] ) {
		pml4->m_pdpt[ pdpt_index ] = new pdpt_cache_line;
		memset( pml4->m_pdpt[ pdpt_index ], 0, sizeof( pdpt_cache_line ) );
	}

	pdpt_cache_line* pdpt = pml4->m_pdpt[ pdpt_index ];

	if ( pdpt->m_pdpte.m_access_count > m_config.m_pdpt_invalidation_access_count ) {
		for ( int i = 0; i < 512; i++ ) {
			if ( pdpt->m_pd[ i ] ) {
				pdpt->m_pd[ i ]->m_pde.m_valid = false;
			}
		}

		pdpt->m_pdpte.m_valid = false;
	}

	if ( !pdpt->m_pdpte.m_valid ) {
		page_table_entry new_pdpt = {};
		if ( !read_physical_memory( pml4->m_pml4e.m_entry.address() + ( sizeof( uintptr_t ) * pdpt_index ), &new_pdpt, sizeof( new_pdpt ) ) ) {
			pdpt->m_pdpte.m_valid = false;
			return nullptr;
		}

		if ( !new_pdpt.present() ) {
			pdpt->m_pdpte.m_valid = false;
			return nullptr;
		}

		pdpt->m_pdpte.m_valid = true;
		pdpt->m_pdpte.m_access_count = 0;
		pdpt->m_pdpte.m_entry = new_pdpt;
	}

	pdpt->m_pdpte.m_access_count++;
	return pdpt;
}

pd_cache_line* cache_tlb::get_or_load_pd_entry( pdpt_cache_line* pdpt, uint16_t pd_index ) {
	if ( pd_index >= 512 )
		return nullptr;

	if ( !pdpt->m_pd[ pd_index ] ) {
		pdpt->m_pd[ pd_index ] = new pd_cache_line;
		memset( pdpt->m_pd[ pd_index ], 0, sizeof( pd_cache_line ) );
	}

	pd_cache_line* pd = pdpt->m_pd[ pd_index ];

	if ( pd->m_pde.m_access_count > m_config.m_pd_invalidation_access_count ) {
		for ( int i = 0; i < 512; i++ ) {
			if ( pd->m_pt[ i ] ) {
				pd->m_pt[ i ]->m_pte.m_valid = false;
			}
		}

		pd->m_pde.m_valid = false;
	}

	if ( !pd->m_pde.m_valid ) {
		page_table_entry new_pd = {};
		if ( !read_physical_memory( pdpt->m_pdpte.m_entry.address() + ( sizeof( uintptr_t ) * pd_index ), &new_pd, sizeof( new_pd ) ) ) {
			pd->m_pde.m_valid = false;
			return nullptr;
		}

		if ( !new_pd.present() ) {
			pd->m_pde.m_valid = false;
			return nullptr;
		}

		pd->m_pde.m_valid = true;
		pd->m_pde.m_access_count = 0;
		pd->m_pde.m_entry = new_pd;
	}

	pd->m_pde.m_access_count++;
	return pd;
}

pt_cache_line* cache_tlb::get_or_load_pt_entry( pd_cache_line* pd, uint16_t pt_index ) {
	if ( pt_index >= 512 )
		return nullptr;

	if ( !pd->m_pt[ pt_index ] ) {
		pd->m_pt[ pt_index ] = new pt_cache_line;
		memset( pd->m_pt[ pt_index ], 0, sizeof( pt_cache_line ) );
	}

	pt_cache_line* pt = pd->m_pt[ pt_index ];

	if ( pt->m_pte.m_access_count > m_config.m_pt_invalidation_access_count ) {
		pt->m_pte.m_valid = false;
	}

	if ( !pt->m_pte.m_valid ) {
		page_table_entry new_pt = {};
		if ( !read_physical_memory( pd->m_pde.m_entry.address() + ( sizeof( uintptr_t ) * pt_index ), &new_pt, sizeof( new_pt ) ) ) {
			pt->m_pte.m_valid = false;
			return nullptr;
		}

		if ( !new_pt.present() ) {
			pt->m_pte.m_valid = false;
			return nullptr;
		}

		pt->m_pte.m_valid = true;
		pt->m_pte.m_access_count = 0;
		pt->m_pte.m_entry = new_pt;
	}

	pt->m_pte.m_access_count++;
	return pt;
}

bool cache_tlb::translate( uintptr_t va, uintptr_t* pa ) {
	uint16_t pml4_index = ( va >> 39 ) & 0x1FF;
	uint16_t pdpt_index = ( va >> 30 ) & 0x1FF;
	uint16_t pd_index = ( va >> 21 ) & 0x1FF;
	uint16_t pt_index = ( va >> 12 ) & 0x1FF;
	uintptr_t offset = va & 0xFFF;

	tlb_cache_line* pml4_entry = get_or_load_pml4_entry( pml4_index );
	if ( !pml4_entry || !pml4_entry->m_pml4e.m_valid )
		return false;

	pdpt_cache_line* pdpt_entry = get_or_load_pdpt_entry( pml4_entry, pdpt_index );
	if ( !pdpt_entry || !pdpt_entry->m_pdpte.m_valid )
		return false;

	if ( pdpt_entry->m_pdpte.m_entry.large() ) {
		*pa = pdpt_entry->m_pdpte.m_entry.address() | ( va & 0x3FFFFFFF );
		return true;
	}

	pd_cache_line* pd_entry = get_or_load_pd_entry( pdpt_entry, pd_index );
	if ( !pd_entry || !pd_entry->m_pde.m_valid )
		return false;

	if ( pd_entry->m_pde.m_entry.large() ) {
		*pa = pd_entry->m_pde.m_entry.address() | ( va & 0x1FFFFF );
		return true;
	}

	pt_cache_line* pt_entry = get_or_load_pt_entry( pd_entry, pt_index );
	if ( !pt_entry || !pt_entry->m_pte.m_valid )
		return false;

	if ( pt_entry->m_pte.m_entry.present() ) {
		*pa = pt_entry->m_pte.m_entry.address() | offset;
		return true;
	}

	return false;
}