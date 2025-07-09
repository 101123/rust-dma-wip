#pragma once

namespace Offsets {
    namespace Unity {
        constexpr const static size_t gContext = 0x1CA3940;

        namespace GameObject {
            constexpr const static size_t m_Object = 0x28;
            constexpr const static size_t m_Component = 0x30;
            constexpr const static size_t m_IsActive = 0x56;
            constexpr const static size_t m_Name = 0x60;
        }

        namespace Component {
            constexpr const static size_t m_Object = 0x28;
            constexpr const static size_t m_GameObject = 0x30;
        }

        namespace TransformHierarchy {
            constexpr const static size_t localTransforms = 0x18;
            constexpr const static size_t parentIndices = 0x20;
            constexpr const static size_t m_LocalPosition = 0x90;
        }

        namespace Transform {
            constexpr const static size_t m_TransformData = 0x38;
            constexpr const static size_t m_Children = 0x70;
        }

        namespace Camera {
            constexpr const static size_t m_CullingMatrix = 0x30C;
            constexpr const static size_t m_CullingMask = 0x43C;
            constexpr const static size_t m_LastPosition = 0x454;
        }

        namespace InputManager {
            constexpr const static size_t m_CurrentKeyState = 0x58;
            constexpr const static size_t m_ThisFrameKeyDown = 0x78;
            constexpr const static size_t m_ThisFrameKeyUp = 0x98;
            constexpr const static size_t m_MouseDelta = 0xB8;
            constexpr const static size_t m_MousePos = 0xC8;
        }

        namespace TimeManager {
            constexpr const static size_t m_RealTime = 0x70;
            constexpr const static size_t m_ActiveTime = 0x90;
            constexpr const static size_t m_FrameCount = 0xC8;
        }
    }

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