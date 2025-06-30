#pragma once

namespace Offsets {
	namespace Il2CppObject {
		constexpr const static size_t klass = 0x0;
	}

	namespace Il2CppClass {
		constexpr const static size_t name = 0x10;
		constexpr const static size_t namespaze = 0x18;
		constexpr const static size_t parent = 0x58;
		constexpr const static size_t static_fields = 0xB8;
	}

	namespace TerrainMap {
		constexpr const static size_t res = 0x38;
		constexpr const static size_t src = 0x40;
	}
}