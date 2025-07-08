#pragma once

#include <cstdint>

struct page_table_entry {
	uintptr_t m_value;

	bool present() const {
		return m_value & 1;
	}

	bool large() const {
		return m_value & ( 1ULL << 7 );
	}

	uintptr_t address() const {
		return m_value & 0x000FFFFFFFFFF000ULL;
	}
};

struct entry_info {
	bool m_valid;
	uint32_t m_access_count;
	page_table_entry m_entry;
};

struct pt_cache_line {
	entry_info m_pte;
};

struct pd_cache_line {
	entry_info m_pde;
	pt_cache_line* m_pt[ 512 ];
};

struct pdpt_cache_line {
	entry_info m_pdpte;
	pd_cache_line* m_pd[ 512 ];
};

struct tlb_cache_line {
	entry_info m_pml4e;
	pdpt_cache_line* m_pdpt[ 512 ];
};

struct cache_tlb_config {
	bool m_pml4_pre_cache;
	bool m_pdpt_pre_cache;
	bool m_pd_pre_cache;
	bool m_pt_pre_cache;
	uint16_t m_pml4_invalidation_access_count;
	uint16_t m_pdpt_invalidation_access_count;
	uint16_t m_pd_invalidation_access_count;
	uint16_t m_pt_invalidation_access_count;
};

class cache_tlb {
public:
	void initialize( uintptr_t cr3, cache_tlb_config tlb_config );
	bool translate( uintptr_t va, uintptr_t* pa );

private:
	void initialize_pml4_cache();
	void initialize_pdpt_cache( tlb_cache_line* pml4, uintptr_t pdpt_phys );
	void initialize_pd_cache( pdpt_cache_line* pdpt, uintptr_t pd_phys );

	tlb_cache_line* get_or_load_pml4_entry( uint16_t pml4_index );
	pdpt_cache_line* get_or_load_pdpt_entry( tlb_cache_line* pml4, uint16_t pdpt_index );
	pd_cache_line* get_or_load_pd_entry( pdpt_cache_line* pdpt, uint16_t pd_index );
	pt_cache_line* get_or_load_pt_entry( pd_cache_line* pd, uint16_t pt_index );

	uintptr_t m_cr3;
	cache_tlb_config m_config;
	tlb_cache_line* m_entries[ 512 ];
};

