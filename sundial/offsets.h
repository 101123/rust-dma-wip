#pragma once

#include <cstdint>

namespace Offsets {
	namespace GameAssembly {
		constexpr const static size_t timestamp = 0x6846ff89;
		constexpr const static size_t gc_handles = 0xc191ca0;
		constexpr const static size_t il2cpp_resolve_icall = 0x6a15d0;
		constexpr const static size_t il2cpp_array_new = 0x6a15f0;
		constexpr const static size_t il2cpp_assembly_get_image = 0xd5f00;
		constexpr const static size_t il2cpp_class_from_name = 0x6a1760;
		constexpr const static size_t il2cpp_class_get_method_from_name = 0x6a1a70;
		constexpr const static size_t il2cpp_class_get_type = 0x6a1b10;
		constexpr const static size_t il2cpp_domain_get = 0x6a2070;
		constexpr const static size_t il2cpp_domain_get_assemblies = 0x6a2090;
		constexpr const static size_t il2cpp_gchandle_get_target = 0x6a2750;
		constexpr const static size_t il2cpp_gchandle_new = 0x6a2700;
		constexpr const static size_t il2cpp_gchandle_free = 0x6a27f0;
		constexpr const static size_t il2cpp_method_get_name = 0x2fb0;
		constexpr const static size_t il2cpp_object_new = 0x6a2eb0;
		constexpr const static size_t il2cpp_type_get_object = 0x6a36a0;
	}

#define Object_TypeDefinitionIndex 14832

	namespace Object {

		// Offsets
		constexpr const static size_t m_CachedPtr = 0x10;

		// Functions
		constexpr const static size_t Destroy = 0x104400;
		constexpr const static size_t DestroyImmediate = 0x104590;
		constexpr const static size_t DontDestroyOnLoad = 0x104d10;
		constexpr const static size_t FindObjectFromInstanceID = 0x106b70;
		constexpr const static size_t GetName = 0x1064b0;
		constexpr const static size_t get_hideFlags = 0x104e50;
		constexpr const static size_t set_hideFlags = 0x104f80;
	}

#define GameObject_TypeDefinitionIndex 14807

	namespace GameObject {

		// Functions
		constexpr const static size_t SetActive = 0xfc850;
		constexpr const static size_t Internal_AddComponentWithType = 0xfbc60;
		constexpr const static size_t GetComponent = 0xf96d0;
		constexpr const static size_t GetComponentCount = 0x6a3f0;
		constexpr const static size_t GetComponentInChildren = 0xfa820;
		constexpr const static size_t GetComponentInParent = 0xfaba0;
		constexpr const static size_t GetComponentsInternal = 0xfaf30;
		constexpr const static size_t Internal_CreateGameObject = 0xff2b0;
		constexpr const static size_t get_layer = 0x77100;
		constexpr const static size_t get_tag = 0xfce00;
		constexpr const static size_t get_transform = 0xfc270;
	}

#define Component_TypeDefinitionIndex 14800

	namespace Component {

		// Functions
		constexpr const static size_t get_gameObject = 0xf7b70;
		constexpr const static size_t get_transform = 0xf77d0;
	}

#define Behaviour_TypeDefinitionIndex 14794

	namespace Behaviour {

		// Functions
		constexpr const static size_t set_enabled = 0xa1de0;
	}

#define Transform_TypeDefinitionIndex 14866

	namespace Transform {

		// Functions
		constexpr const static size_t GetChild = 0x115600;
		constexpr const static size_t GetParent = 0x111e60;
		constexpr const static size_t GetRoot = 0x113f70;
		constexpr const static size_t InverseTransformDirection_Injected = 0x113150;
		constexpr const static size_t InverseTransformPoint_Injected = 0x113cb0;
		constexpr const static size_t InverseTransformVector_Injected = 0x1136d0;
		constexpr const static size_t SetLocalPositionAndRotation_Injected = 0x112650;
		constexpr const static size_t SetPositionAndRotation_Injected = 0x112510;
		constexpr const static size_t TransformDirection_Injected = 0x112e90;
		constexpr const static size_t TransformPoint_Injected = 0x1139f0;
		constexpr const static size_t TransformVector_Injected = 0x113410;
		constexpr const static size_t get_childCount = 0x773b0;
		constexpr const static size_t get_eulerAngles = 0x773b0;
		constexpr const static size_t get_localPosition_Injected = 0x111170;
		constexpr const static size_t get_localRotation_Injected = 0x111920;
		constexpr const static size_t get_localScale_Injected = 0x111be0;
		constexpr const static size_t get_lossyScale_Injected = 0x114e80;
		constexpr const static size_t get_position_Injected = 0x110ef0;
		constexpr const static size_t get_rotation_Injected = 0x111670;
		constexpr const static size_t set_localPosition_Injected = 0x1112b0;
		constexpr const static size_t set_localRotation_Injected = 0x111aa0;
		constexpr const static size_t set_localScale_Injected = 0x111d20;
		constexpr const static size_t set_position_Injected = 0x111030;
		constexpr const static size_t set_rotation_Injected = 0x1117e0;
	}

#define Camera_TypeDefinitionIndex 14614

	namespace Camera {

		// Functions
		constexpr const static size_t WorldToScreenPoint_Injected = 0x6f800;
	}

#define Time_TypeDefinitionIndex 14854

	namespace Time {

		// Functions
		constexpr const static size_t get_deltaTime = 0x10f8e0;
		constexpr const static size_t get_fixedDeltaTime = 0x10f9a0;
		constexpr const static size_t get_fixedTime = 0x10f8f0;
		constexpr const static size_t get_frameCount = 0x10fc80;
		constexpr const static size_t get_realtimeSinceStartup = 0x10fca0;
		constexpr const static size_t get_smoothDeltaTime = 0x10fa80;
		constexpr const static size_t get_time = 0x10f870;
	}

#define Material_TypeDefinitionIndex 14666

	namespace Material {

		// Functions
		constexpr const static size_t CreateWithMaterial = 0xaf1c0;
		constexpr const static size_t CreateWithShader = 0xaf050;
		constexpr const static size_t SetBufferImpl = 0xb7490;
	}

#define MaterialPropertyBlock_TypeDefinitionIndex 14662

	namespace MaterialPropertyBlock {

		// Functions
		constexpr const static size_t ctor = 0xa097cf0;
		constexpr const static size_t SetFloatImpl = 0x9bed0;
		constexpr const static size_t SetTextureImpl = 0x9c1c0;
	}

#define Shader_TypeDefinitionIndex 14665

	namespace Shader {

		// Functions
		constexpr const static size_t PropertyToID = 0xaa6a0;
	}

#define Mesh_TypeDefinitionIndex 14716

	namespace Mesh {

		// Functions
		constexpr const static size_t Internal_Create = 0xcba60;
		constexpr const static size_t MarkDynamicImpl = 0xd6cc0;
		constexpr const static size_t ClearImpl = 0xd6790;
		constexpr const static size_t set_subMeshCount = 0xd5900;
		constexpr const static size_t SetVertexBufferParamsFromPtr = 0xcc4d0;
		constexpr const static size_t SetIndexBufferParams = 0xcbf50;
		constexpr const static size_t InternalSetVertexBufferData = 0xcc7d0;
		constexpr const static size_t InternalSetIndexBufferData = 0xcc1c0;
		constexpr const static size_t SetAllSubMeshesAtOnceFromNativeArray = 0xd63a0;
		constexpr const static size_t UploadMeshDataImpl = 0xd6f70;
	}

#define Texture_TypeDefinitionIndex 14719

	namespace Texture {
		constexpr const static size_t set_filterMode = 0xda5e0;
		constexpr const static size_t GetNativeTexturePtr = 0xdab00;
	}

#define Texture2D_TypeDefinitionIndex 14721

	namespace Texture2D {
		constexpr const static size_t ctor = 0xa0b04d0;
		constexpr const static size_t Internal_CreateImpl = 0xdc200;
		constexpr const static size_t GetRawImageDataSize = 0xde1e0;
		constexpr const static size_t GetWritableImageData = 0xde090;
		constexpr const static size_t ApplyImpl = 0xdc5e0;
	}

#define CommandBuffer_TypeDefinitionIndex 15159

	namespace CommandBuffer {

		// Functions
		constexpr const static size_t ctor = 0xa0f2180;
		constexpr const static size_t Clear = 0x12f580;
		constexpr const static size_t ClearRenderTarget_Injected = 0x132050;
		constexpr const static size_t SetViewport_Injected = 0x131020;
		constexpr const static size_t SetViewProjectionMatrices_Injected = 0x136ef0;
		constexpr const static size_t EnableScissorRect_Injected = 0x131190;
		constexpr const static size_t DisableScissorRect = 0x131300;
		constexpr const static size_t Internal_DrawProceduralIndexedIndirect_Injected = 0x130300;
		constexpr const static size_t Internal_DrawMesh_Injected = 0x12f610;
	}

#define ComputeBuffer_TypeDefinitionIndex 14845

	namespace ComputeBuffer {

		// Functions
		constexpr const static size_t ctor = 0xa0d3e20;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Release = 0xa0d4070;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define GraphicsBuffer_TypeDefinitionIndex 14670

	namespace GraphicsBuffer {

		// Functions
		constexpr const static size_t ctor = 0xa0a0db0;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Dispose = 0xa0a0ae0;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define Event_TypeDefinitionIndex 19801

	namespace Event {

		// Functions
		constexpr const static size_t get_current = 0xa106f30;
		constexpr const static size_t get_type = 0x23a320;
		constexpr const static size_t PopEvent = 0x23b060;
		constexpr const static size_t Internal_Use = 0x23ac60;
	}

#define Graphics_TypeDefinitionIndex 14647

	namespace Graphics {

		// Functions
		constexpr const static size_t ExecuteCommandBuffer = 0x89bb0;
	}

#define Matrix4x4_TypeDefinitionIndex 14745

	namespace Matrix4x4 {

		// Functions
		constexpr const static size_t Ortho_Injected = 0xef280;
	}

#define AssetBundle_TypeDefinitionIndex -1

	namespace AssetBundle {

		// Functions
		constexpr const static size_t LoadFromMemory_Internal = 0x1cb490;
		constexpr const static size_t LoadFromFile_Internal = 0x1ca710;
		constexpr const static size_t LoadAsset_Internal = 0x1cc0c0;
		constexpr const static size_t Unload = 0x1cd090;
	}

#define Screen_TypeDefinitionIndex 14644

	namespace Screen {

		// Functions
		constexpr const static size_t get_width = 0x81630;
		constexpr const static size_t get_height = 0x81640;
	}

#define Input_TypeDefinitionIndex -1

	namespace Input {

		// Functions
		constexpr const static size_t get_mousePosition_Injected = 0x221990;
		constexpr const static size_t get_mouseScrollDelta_Injected = 0x221a90;
		constexpr const static size_t GetMouseButtonDown = 0x220c30;
		constexpr const static size_t GetMouseButtonUp = 0x220d00;
		constexpr const static size_t GetMouseButton = 0x220b30;
		constexpr const static size_t GetKeyDownInt = 0x220a60;
		constexpr const static size_t GetKeyUpInt = 0x220990;
		constexpr const static size_t GetKeyInt = 0x220880;
	}

#define Application_TypeDefinitionIndex 14597

	namespace Application {

		// Functions
		constexpr const static size_t Quit = 0x5d790;
	}

#define BaseNetworkable_TypeDefinitionIndex 666

	namespace BaseNetworkable {

		// Offsets
		constexpr const static size_t prefabID = 0x30;
		constexpr const static size_t net = 0x70;
		constexpr const static size_t parentEntity = 0x60;
		constexpr const static size_t children = 0x28;
	}

	// obf name: ::%b15691c3b3fb711a9d553cf026299a3fa731c5a1
#define BaseNetworkable_Static_ClassName "BaseNetworkable/%b15691c3b3fb711a9d553cf026299a3fa731c5a1"
#define BaseNetworkable_Static_ClassNameShort "%b15691c3b3fb711a9d553cf026299a3fa731c5a1"
#define BaseNetworkable_Static_TypeDefinitionIndex 665

	namespace BaseNetworkable_Static {

		// Offsets
		constexpr const static size_t clientEntities = 0x30;
	}

	// obf name: ::%17f44fcd5c74b4bc94453d09c45d68325513f07c
#define BaseNetworkable_EntityRealm_ClassName "BaseNetworkable/%17f44fcd5c74b4bc94453d09c45d68325513f07c"
#define BaseNetworkable_EntityRealm_ClassNameShort "%17f44fcd5c74b4bc94453d09c45d68325513f07c"
#define BaseNetworkable_EntityRealm_TypeDefinitionIndex 663

	namespace BaseNetworkable_EntityRealm {

		// Offsets
		constexpr const static size_t entityList = 0x10;

		// Functions
		constexpr const static size_t Find = 0x409b9a0;
	}

	// obf name: ::%c699a6b39570cc942aba613db85384ea44c8bd6a
#define System_ListDictionary_ClassName "%c699a6b39570cc942aba613db85384ea44c8bd6a<%e1f0191364a5f2d4ff329f15ef9e4f8d0c46a345,BaseNetworkable>"
#define System_ListDictionary_ClassNameShort "%c699a6b39570cc942aba613db85384ea44c8bd6a"
#define System_ListDictionary_TypeDefinitionIndex -1

	namespace System_ListDictionary {

		// Offsets
		constexpr const static size_t vals = 0x18;

		// Functions
		constexpr const static size_t TryGetValue = 0x6f48380;
		constexpr const static size_t TryGetValue_methodinfo = 0xbed34c0;
	}

	// obf name: ::%8855190f2f6f984bfb37c63171de9bc44f48decf
#define System_BufferList_ClassName "%8855190f2f6f984bfb37c63171de9bc44f48decf<BaseNetworkable>"
#define System_BufferList_ClassNameShort "%8855190f2f6f984bfb37c63171de9bc44f48decf"
#define System_BufferList_TypeDefinitionIndex -1

	namespace System_BufferList {

		// Offsets
		constexpr const static size_t count = 0x18;
		constexpr const static size_t buffer = 0x10;
	}

	// obf name: ::SingletonComponent`1
#define SingletonComponent_ClassName "SingletonComponent<MainCamera>"
#define SingletonComponent_ClassNameShort "SingletonComponent`1"
#define SingletonComponent_TypeDefinitionIndex -1

	namespace SingletonComponent {

		// Offsets
		constexpr const static size_t Instance = 0x18;
	}

#define Model_TypeDefinitionIndex 6027

	namespace Model {

		// Offsets
		constexpr const static size_t rootBone = 0x28;
		constexpr const static size_t headBone = 0x30;
		constexpr const static size_t boneTransforms = 0x50;
	}

#define BaseEntity_TypeDefinitionIndex 5760

	namespace BaseEntity {

		// Offsets
		constexpr const static size_t bounds = 0xa0;
		constexpr const static size_t model = 0xc8;
		constexpr const static size_t flags = 0xd0;
		constexpr const static size_t triggers = 0x80;
		constexpr const static size_t positionLerp = 0x150;

		// Functions
		constexpr const static size_t ServerRPC = 0x3b4a3f0;
		constexpr const static size_t FindBone = 0x3b143a0;
		constexpr const static size_t GetWorldVelocity = 0x3b32130;
		constexpr const static size_t GetParentVelocity = 0x3b1e730;
	}

	// obf name: ::%2dda4ef6d73a108253d007c724f8dd84018dc575
#define PositionLerp_ClassName "%2dda4ef6d73a108253d007c724f8dd84018dc575"
#define PositionLerp_ClassNameShort "%2dda4ef6d73a108253d007c724f8dd84018dc575"
#define PositionLerp_TypeDefinitionIndex 2105

	namespace PositionLerp {

		// Offsets
		constexpr const static size_t interpolator = 0x30;
	}

	// obf name: ::%27f4fa1cd7e215a00d0d69e7d6f035976241b7f9
#define Interpolator_ClassName "%27f4fa1cd7e215a00d0d69e7d6f035976241b7f9<%ee93f8dcf4822db804937f50e14734d3df587f07>"
#define Interpolator_ClassNameShort "%27f4fa1cd7e215a00d0d69e7d6f035976241b7f9"
#define Interpolator_TypeDefinitionIndex -1

	namespace Interpolator {
		constexpr const static size_t list = 0x30;
		constexpr const static size_t last = 0x10;
	}

#define BaseCombatEntity_TypeDefinitionIndex 3205

	namespace BaseCombatEntity {

		// Offsets
		constexpr const static size_t skeletonProperties = 0x1c0;
		constexpr const static size_t lifestate = 0x234;
		constexpr const static size_t markAttackerHostile = 0x23a;
		constexpr const static size_t _health = 0x23c;
		constexpr const static size_t _maxHealth = 0x240;
		constexpr const static size_t lastNotifyFrame = 0x24c;
	}

#define SkeletonProperties_TypeDefinitionIndex 1029

	namespace SkeletonProperties {

		// Offsets
		constexpr const static size_t bones = 0x20;
		constexpr const static size_t quickLookup = 0x28;
	}

#define SkeletonProperties_BoneProperty_TypeDefinitionIndex 1027

	namespace SkeletonProperties_BoneProperty {

		// Offsets
		constexpr const static size_t name = 0x18;
		constexpr const static size_t area = 0x20;
	}

#define ItemDefinition_TypeDefinitionIndex 3160

	namespace ItemDefinition {

		// Offsets
		constexpr const static size_t itemid = 0x20;
		constexpr const static size_t shortname = 0x28;
		constexpr const static size_t displayName = 0x38;
		constexpr const static size_t iconSprite = 0x48;
		constexpr const static size_t category = 0x50;
		constexpr const static size_t stackable = 0x68;
		constexpr const static size_t rarity = 0x80;
		constexpr const static size_t ItemModWearable = 0x138;
	}

#define RecoilProperties_TypeDefinitionIndex 6013

	namespace RecoilProperties {

		// Offsets
		constexpr const static size_t recoilYawMin = 0x18;
		constexpr const static size_t recoilYawMax = 0x1c;
		constexpr const static size_t recoilPitchMin = 0x20;
		constexpr const static size_t recoilPitchMax = 0x24;
		constexpr const static size_t overrideAimconeWithCurve = 0x5c;
		constexpr const static size_t aimconeProbabilityCurve = 0x70;
		constexpr const static size_t newRecoilOverride = 0x80;
	}

#define BaseProjectile_Magazine_TypeDefinitionIndex 5260

	namespace BaseProjectile_Magazine {

		// Offsets
		constexpr const static size_t capacity = 0x18;
		constexpr const static size_t contents = 0x1c;
		constexpr const static size_t ammoType = 0x20;
	}

#define AttackEntity_TypeDefinitionIndex 2476

	namespace AttackEntity {

		// Offsets
		constexpr const static size_t deployDelay = 0x230;
		constexpr const static size_t repeatDelay = 0x234;
		constexpr const static size_t animationDelay = 0x238;
		constexpr const static size_t noHeadshots = 0x286;
		constexpr const static size_t nextAttackTime = 0x288;
		constexpr const static size_t timeSinceDeploy = 0x2a0;

		// Functions
		constexpr const static size_t SpectatorNotifyTick = 0x16e7480;
		constexpr const static size_t StartAttackCooldown = 0x16ea430;
	}

#define BaseProjectile_TypeDefinitionIndex 5264

	namespace BaseProjectile {

		// Offsets
		constexpr const static size_t projectileVelocityScale = 0x2d4;
		constexpr const static size_t automatic = 0x2d8;
		constexpr const static size_t reloadTime = 0x310;
		constexpr const static size_t primaryMagazine = 0x318;
		constexpr const static size_t fractionalReload = 0x320;
		constexpr const static size_t aimSway = 0x334;
		constexpr const static size_t aimSwaySpeed = 0x338;
		constexpr const static size_t recoil = 0x340;
		constexpr const static size_t aimconeCurve = 0x348;
		constexpr const static size_t aimCone = 0x350;
		constexpr const static size_t hipAimCone = 0x354;
		constexpr const static size_t noAimingWhileCycling = 0x36d;
		constexpr const static size_t isBurstWeapon = 0x372;
		constexpr const static size_t cachedModHash = 0x3a4;
		constexpr const static size_t sightAimConeScale = 0x3a8;
		constexpr const static size_t sightAimConeOffset = 0x3ac;
		constexpr const static size_t hipAimConeScale = 0x3b0;
		constexpr const static size_t hipAimConeOffset = 0x3b4;

		// Functions
		constexpr const static size_t LaunchProjectile = 0x3551590;
		constexpr const static size_t LaunchProjectileClientSide = 0x35596a0;
		constexpr const static size_t ScaleRepeatDelay = 0x3544bc0;
		constexpr const static size_t GetAimCone = 0x35643d0;
		constexpr const static size_t GetAimCone_vtableoff = 0x3db8;
		constexpr const static size_t UpdateAmmoDisplay = 0x35656f0;
		constexpr const static size_t UpdateAmmoDisplay_vtableoff = 0x3dc8;
	}

#define BaseLauncher_TypeDefinitionIndex 1604

	namespace BaseLauncher {

		// Offsets
	}

#define SpinUpWeapon_TypeDefinitionIndex 6529

	namespace SpinUpWeapon {

		// Offsets
	}

	// obf name: ::%53b495cb8935bdf3936b2de0de7419e62c331320
#define HitTest_ClassName "%53b495cb8935bdf3936b2de0de7419e62c331320"
#define HitTest_ClassNameShort "%53b495cb8935bdf3936b2de0de7419e62c331320"
#define HitTest_TypeDefinitionIndex 4313

	namespace HitTest {

		// Offsets
		constexpr const static size_t type = 0xd8;
		constexpr const static size_t AttackRay = 0x74;
		constexpr const static size_t RayHit = 0xa0;
		constexpr const static size_t damageProperties = 0x40;
		constexpr const static size_t gameObject = 0x60;
		constexpr const static size_t collider = 0x50;
		constexpr const static size_t ignoredTypes = 0x20;
		constexpr const static size_t HitTransform = 0x90;
		constexpr const static size_t HitPart = 0xe0;
		constexpr const static size_t HitMaterial = 0xd0;
		constexpr const static size_t DidHit = 0xdc;
		constexpr const static size_t MaxDistance = 0x48;
		constexpr const static size_t HitPoint = 0x28;
		constexpr const static size_t HitNormal = 0x68;
		constexpr const static size_t ignoreEntity = 0x38;
		constexpr const static size_t HitEntity = 0x58;
	}

	// obf name: ::%a033a9260ddcaa631db5fa707143974fdd1248b7
#define GameTrace_ClassName "%a033a9260ddcaa631db5fa707143974fdd1248b7"
#define GameTrace_ClassNameShort "%a033a9260ddcaa631db5fa707143974fdd1248b7"
#define GameTrace_TypeDefinitionIndex 6194

	namespace GameTrace {

		// Functions
		constexpr const static size_t Trace = 0x400efa0;
	}

#define BaseMelee_TypeDefinitionIndex 842

	namespace BaseMelee {

		// Offsets
		constexpr const static size_t damageProperties = 0x2c8;
		constexpr const static size_t maxDistance = 0x2e0;
		constexpr const static size_t attackRadius = 0x2e4;
		constexpr const static size_t blockSprintOnAttack = 0x2e9;
		constexpr const static size_t gathering = 0x318;
		constexpr const static size_t canThrowAsProjectile = 0x321;

		// Functions
		constexpr const static size_t ProcessAttack = 0x44bf3e0;
		constexpr const static size_t DoThrow = 0x44c45c0;
	}

#define FlintStrikeWeapon_TypeDefinitionIndex 3914

	namespace FlintStrikeWeapon {

		// Offsets
		constexpr const static size_t successFraction = 0x3f0;
		constexpr const static size_t strikeRecoil = 0x3f8;
		constexpr const static size_t _didSparkThisFrame = 0x400;
	}

#define CompoundBowWeapon_TypeDefinitionIndex 4298

	namespace CompoundBowWeapon {

		// Offsets
		constexpr const static size_t stringHoldDurationMax = 0x408;
		constexpr const static size_t stringBonusVelocity = 0x414;

		// Functions
		constexpr const static size_t GetStringBonusScale = 0x2a9df10;
	}

	// obf name: ::%098b39a7899b57b3520549cddcf60f1e7fa5b9b8
#define ItemContainer_ClassName "%098b39a7899b57b3520549cddcf60f1e7fa5b9b8"
#define ItemContainer_ClassNameShort "%098b39a7899b57b3520549cddcf60f1e7fa5b9b8"
#define ItemContainer_TypeDefinitionIndex 5090

	namespace ItemContainer {

		// Offsets
		constexpr const static size_t uid = 0x30;
		constexpr const static size_t itemList = 0x40;

		// Functions
		constexpr const static size_t FindItemsByItemID = 0x3384310;
		constexpr const static size_t GetSlot = 0x33a4830;
	}

#define PlayerLoot_TypeDefinitionIndex 5977

	namespace PlayerLoot {

		// Offsets
		constexpr const static size_t containers = 0x38;
	}

#define PlayerInventory_TypeDefinitionIndex 4432

	namespace PlayerInventory {

		// Offsets
		constexpr const static size_t containerBelt = 0x28;
		constexpr const static size_t containerMain = 0x38;
		constexpr const static size_t containerWear = 0x58;
		constexpr const static size_t loot = 0x48;

		// Functions
		constexpr const static size_t Initialize = 0x2bfdfb0;
		constexpr const static size_t FindItemsByItemID = 0x2bf78c0;
	}

#define PlayerEyes_TypeDefinitionIndex 6330

	namespace PlayerEyes {

		// Offsets
		constexpr const static size_t viewOffset = 0x40;
		constexpr const static size_t bodyRotation = 0x50;

		// Functions
		constexpr const static size_t get_position = 0x417bc90;
		constexpr const static size_t get_rotation = 0x417a180;
		constexpr const static size_t set_rotation = 0x4183bb0;
		constexpr const static size_t HeadForward = 0x4181aa0;
	}

	// obf name: ::%87d55dd527578be3df89f3d23f66eeea9847996e
#define PlayerEyes_Static_ClassName "PlayerEyes/%87d55dd527578be3df89f3d23f66eeea9847996e"
#define PlayerEyes_Static_ClassNameShort "%87d55dd527578be3df89f3d23f66eeea9847996e"
#define PlayerEyes_Static_TypeDefinitionIndex 6329

	namespace PlayerEyes_Static {

		// Offsets
		constexpr const static size_t EyeOffset = 0x44;
	}

	// obf name: ::%544afb77076df98d2a09bd76062c8002708078bd
#define PlayerBelt_ClassName "%544afb77076df98d2a09bd76062c8002708078bd"
#define PlayerBelt_ClassNameShort "%544afb77076df98d2a09bd76062c8002708078bd"
#define PlayerBelt_TypeDefinitionIndex 4905

	namespace PlayerBelt {

		// Functions
		constexpr const static size_t ChangeSelect = 0x3152210;
		constexpr const static size_t GetActiveItem = 0x3153b30;
	}

	// obf name: ::%6017cc129cad0ea3544c123a110107de223d12c5
#define LocalPlayer_ClassName "%6017cc129cad0ea3544c123a110107de223d12c5"
#define LocalPlayer_ClassNameShort "%6017cc129cad0ea3544c123a110107de223d12c5"
#define LocalPlayer_TypeDefinitionIndex 1327

	namespace LocalPlayer {

		// Functions
		constexpr const static size_t ItemCommand = 0x4b4cf60;
		constexpr const static size_t MoveItem = 0x4b586d0;
		constexpr const static size_t get_Entity = 0x4b669e0;
	}

	// obf name: ::%86157f6cd7eede34b6d0c521934b1099021f450a
#define LocalPlayer_Static_ClassName "%6017cc129cad0ea3544c123a110107de223d12c5/%86157f6cd7eede34b6d0c521934b1099021f450a"
#define LocalPlayer_Static_ClassNameShort "%86157f6cd7eede34b6d0c521934b1099021f450a"
#define LocalPlayer_Static_TypeDefinitionIndex 1326

	namespace LocalPlayer_Static {

		// Offsets
		constexpr const static size_t Entity = 0xa0;
	}

	// obf name: ::%f649edb0da87b67a9220f2cb7e14612469acdf1f
#define BasePlayer_Static_ClassName "BasePlayer/%f649edb0da87b67a9220f2cb7e14612469acdf1f"
#define BasePlayer_Static_ClassNameShort "%f649edb0da87b67a9220f2cb7e14612469acdf1f"
#define BasePlayer_Static_TypeDefinitionIndex 145

	namespace BasePlayer_Static {

		// Offsets
		constexpr const static size_t visiblePlayerList = 0xe30;
	}

#define BasePlayer_TypeDefinitionIndex 146

	namespace BasePlayer {

		// Offsets
		constexpr const static size_t playerModel = 0x288;
		constexpr const static size_t input = 0x5c0;
		constexpr const static size_t movement = 0x598;
		constexpr const static size_t currentTeam = 0x430;
		constexpr const static size_t clActiveItem = 0x460;
		constexpr const static size_t modelState = 0x268;
		constexpr const static size_t playerFlags = 0x558;
		constexpr const static size_t eyes = 0x2a8;
		constexpr const static size_t playerRigidbody = 0x318;
		constexpr const static size_t userID = 0x5a0;
		constexpr const static size_t UserIDString = 0x590;
		constexpr const static size_t inventory = 0x478;
		constexpr const static size_t _displayName = 0x3f8;
		constexpr const static size_t _lookingAt = 0x2c0;
		constexpr const static size_t lastSentTickTime = 0x514;
		constexpr const static size_t lastSentTick = 0x330;
		constexpr const static size_t mounted = 0x4a0;
		constexpr const static size_t Belt = 0x280;
		constexpr const static size_t _lookingAtEntity = 0x270;
		constexpr const static size_t currentGesture = 0x250;
		constexpr const static size_t weaponMoveSpeedScale = 0x630;
		constexpr const static size_t clothingBlocksAiming = 0x634;
		constexpr const static size_t clothingMoveSpeedReduction = 0x638;
		constexpr const static size_t clothingWaterSpeedBonus = 0x63c;
		constexpr const static size_t equippingBlocked = 0x644;

		// Functions
		constexpr const static size_t ClientUpdateLocalPlayer = 0x4a7df20;
		constexpr const static size_t Menu_AssistPlayer = 0x4a97590;
		constexpr const static size_t OnViewModeChanged = 0x4970f70;
		constexpr const static size_t ChatMessage = 0x496ed80;
		constexpr const static size_t IsOnGround = 0x497c940;
		constexpr const static size_t GetSpeed = 0x49d0980;
		constexpr const static size_t SendProjectileUpdate = 0x4a1c0f0;
		constexpr const static size_t SendProjectileAttack = 0x4a93330;
		constexpr const static size_t CanBuild = 0x4a06640;
		constexpr const static size_t GetMounted = 0x4ae4000;
		constexpr const static size_t GetHeldEntity = 0x4972ed0;
		constexpr const static size_t get_inventory = 0x4a341b0;
		constexpr const static size_t get_eyes = 0x4a4c040;
		constexpr const static size_t SendClientTick = 0x4ab0c40;
		constexpr const static size_t ClientInput = 0x4a4ed50;
		constexpr const static size_t ClientInput_vtableoff = 0x38b8;
		constexpr const static size_t MaxHealth = 0x4a47f20;
		constexpr const static size_t MaxHealth_vtableoff = 0x1588;
	}

#define ScientistNPC_TypeDefinitionIndex 6055

	namespace ScientistNPC {

		// Offsets
	}

#define TunnelDweller_TypeDefinitionIndex 4231

	namespace TunnelDweller {

		// Offsets
	}

#define UnderwaterDweller_TypeDefinitionIndex 6378

	namespace UnderwaterDweller {

		// Offsets
	}

#define ScarecrowNPC_TypeDefinitionIndex 3766

	namespace ScarecrowNPC {

		// Offsets
	}

#define GingerbreadNPC_TypeDefinitionIndex 6521

	namespace GingerbreadNPC {

		// Offsets
	}

#define BaseMovement_TypeDefinitionIndex 6233

	namespace BaseMovement {

		// Offsets
		constexpr const static size_t adminCheat = 0x20;
		constexpr const static size_t Owner = 0x28;
	}

#define PlayerWalkMovement_TypeDefinitionIndex 4433

	namespace PlayerWalkMovement {

		// Offsets
		constexpr const static size_t capsule = 0xf0;
		constexpr const static size_t ladder = 0xd8;
		constexpr const static size_t modify = 0x1b8;

		// Functions
		constexpr const static size_t BlockJump = 0x2c386b0;
		constexpr const static size_t BlockSprint = 0x2c08840;
		constexpr const static size_t GroundCheck = 0x2c30760;
		constexpr const static size_t ClientInput = 0x2c2e320;
		constexpr const static size_t ClientInput_vtableoff = 0x348;
		constexpr const static size_t DoFixedUpdate = 0x2c2c6b0;
		constexpr const static size_t DoFixedUpdate_vtableoff = 0x378;
		constexpr const static size_t FrameUpdate = 0x2c13460;
		constexpr const static size_t FrameUpdate_vtableoff = 0x408;
	}

#define BuildingPrivlidge_TypeDefinitionIndex 3034

	namespace BuildingPrivlidge {

		// Offsets
		constexpr const static size_t allowedConstructionItems = 0x360;
		constexpr const static size_t cachedProtectedMinutes = 0x368;
	}

#define WorldItem_TypeDefinitionIndex 4202

	namespace WorldItem {

		// Offsets
		constexpr const static size_t allowPickup = 0x1a0;
		constexpr const static size_t item = 0x1a8;
	}

#define HackableLockedCrate_TypeDefinitionIndex 2482

	namespace HackableLockedCrate {

		// Offsets
		constexpr const static size_t timerText = 0x378;
		constexpr const static size_t hackSeconds = 0x388;
	}

#define ProjectileWeaponMod_TypeDefinitionIndex 5592

	namespace ProjectileWeaponMod {

		// Offsets
		constexpr const static size_t repeatDelay = 0x1c0;
		constexpr const static size_t projectileVelocity = 0x1cc;
		constexpr const static size_t projectileDamage = 0x1d8;
		constexpr const static size_t projectileDistance = 0x1e4;
		constexpr const static size_t aimsway = 0x1f0;
		constexpr const static size_t aimswaySpeed = 0x1fc;
		constexpr const static size_t recoil = 0x208;
		constexpr const static size_t sightAimCone = 0x214;
		constexpr const static size_t hipAimCone = 0x220;
	}

#define ProjectileWeaponMod_Modifier_TypeDefinitionIndex 5589

	namespace ProjectileWeaponMod_Modifier {
		constexpr const static size_t enabled = 0x0;
		constexpr const static size_t scalar = 0x4;
		constexpr const static size_t offset = 0x8;
	}

	// obf name: ::%c1c9de9f693a95b07e5d32bd9225dd0edb0bc5c9
#define ConsoleSystem_ClassName "%c1c9de9f693a95b07e5d32bd9225dd0edb0bc5c9"
#define ConsoleSystem_ClassNameShort "%c1c9de9f693a95b07e5d32bd9225dd0edb0bc5c9"
#define ConsoleSystem_TypeDefinitionIndex 20553

	namespace ConsoleSystem {

		// Functions
		constexpr const static size_t Run = 0x5cd1b90;
	}

#define ConsoleSystem_Option_ClassName "%c1c9de9f693a95b07e5d32bd9225dd0edb0bc5c9/%d8ad47b45a88798eac4366397b71a5602e65b63d"
#define ConsoleSystem_Option_ClassNameShort "%d8ad47b45a88798eac4366397b71a5602e65b63d"
#define ConsoleSystem_Command_ClassName "%c1c9de9f693a95b07e5d32bd9225dd0edb0bc5c9/%6faeaf667389cb3546847b5e6e6e45c84ad239ae"
#define ConsoleSystem_Command_ClassNameShort "%6faeaf667389cb3546847b5e6e6e45c84ad239ae"
	// obf name: ::%fbff1a0381264f30f37edbb8fe94c6b559da0a04
#define ConsoleSystem_Index_Static_ClassName "%c1c9de9f693a95b07e5d32bd9225dd0edb0bc5c9/%2f6ffaff57b841906d53d439ea53fb9f1a74d242.%fbff1a0381264f30f37edbb8fe94c6b559da0a04"
#define ConsoleSystem_Index_Static_ClassNameShort "%fbff1a0381264f30f37edbb8fe94c6b559da0a04"
#define ConsoleSystem_Index_Static_TypeDefinitionIndex 20548

	namespace ConsoleSystem_Index_Static {

		// Offsets
		constexpr const static size_t All = 0x70;
	}

	// obf name: ::%dd16bb022a859acb8855471924f3163db6aba394
#define ConsoleSystem_Arg_ClassName "%c1c9de9f693a95b07e5d32bd9225dd0edb0bc5c9/%dd16bb022a859acb8855471924f3163db6aba394"
#define ConsoleSystem_Arg_ClassNameShort "%dd16bb022a859acb8855471924f3163db6aba394"
// obf name: ::%c74b3b681ceaaddaccce9be70161463192651319
#define Facepunch_Network_SteamNetworking_ClassName "%c74b3b681ceaaddaccce9be70161463192651319"
#define Facepunch_Network_SteamNetworking_ClassNameShort "%c74b3b681ceaaddaccce9be70161463192651319"
#define LootableCorpse_TypeDefinitionIndex 1089

	namespace LootableCorpse {

		// Offsets
		constexpr const static size_t playerSteamID = 0x298;
		constexpr const static size_t _playerName = 0x2a8;
	}

#define DroppedItemContainer_TypeDefinitionIndex 1137

	namespace DroppedItemContainer {

		// Offsets
		constexpr const static size_t playerSteamID = 0x268;
		constexpr const static size_t _playerName = 0x250;
	}

#define MainCamera_TypeDefinitionIndex 4849

	namespace MainCamera {

		// Offsets 
		constexpr const static size_t mainCamera = 0x8;
		constexpr const static size_t mainCameraTransform = 0x58;

		// Functions
		constexpr const static size_t Update = 0x30e43b0;
		constexpr const static size_t Trace = 0x30e6100;
	}

#define CameraMan_TypeDefinitionIndex 6222

	namespace CameraMan {

		// Offsets
	}

	// obf name: ::%172d4d9054aba6dd1673d6a548ca68cff195c76e
#define PlayerTick_ClassName "%172d4d9054aba6dd1673d6a548ca68cff195c76e"
#define PlayerTick_ClassNameShort "%172d4d9054aba6dd1673d6a548ca68cff195c76e"
#define PlayerTick_TypeDefinitionIndex 6883

	namespace PlayerTick {

		// Offsets
		constexpr const static size_t inputState = 0x40;
		constexpr const static size_t modelState = 0x48;
		constexpr const static size_t activeItem = 0x20;
		constexpr const static size_t parentID = 0x50;
		constexpr const static size_t position = 0x28;
		constexpr const static size_t eyePos = 0x14;
	}

	// obf name: ::%8a46826413bc2197b60a5d7c36d65beb7b37d25f
#define InputMessage_ClassName "%8a46826413bc2197b60a5d7c36d65beb7b37d25f"
#define InputMessage_ClassNameShort "%8a46826413bc2197b60a5d7c36d65beb7b37d25f"
#define InputMessage_TypeDefinitionIndex 6539

	namespace InputMessage {

		// Offsets
		constexpr const static size_t buttons = 0x2c;
		constexpr const static size_t aimAngles = 0x10;
		constexpr const static size_t mouseDelta = 0x1c;
	}

	// obf name: ::%7f613c8ec7dc0cf1b4ce409a02c2c267d9c6c860
#define InputState_ClassName "%7f613c8ec7dc0cf1b4ce409a02c2c267d9c6c860"
#define InputState_ClassNameShort "%7f613c8ec7dc0cf1b4ce409a02c2c267d9c6c860"
#define InputState_TypeDefinitionIndex 5375

	namespace InputState {

		// Offsets
		constexpr const static size_t current = 0x18;
		constexpr const static size_t previous = 0x20;
	}

#define PlayerInput_TypeDefinitionIndex 2707

	namespace PlayerInput {

		// Offsets
		constexpr const static size_t state = 0x28;
		constexpr const static size_t bodyAngles = 0x44;
	}

	// obf name: ::%396edb853fc135253dd5e439398fa2724bd11eb9
#define ModelState_ClassName "%396edb853fc135253dd5e439398fa2724bd11eb9"
#define ModelState_ClassNameShort "%396edb853fc135253dd5e439398fa2724bd11eb9"
#define ModelState_TypeDefinitionIndex 6916

	namespace ModelState {

		// Offsets
		constexpr const static size_t flags = 0x78;
		constexpr const static size_t waterLevel = 0x58;
		constexpr const static size_t lookDir = 0x3c;
	}

	// obf name: ::%bc4886c510628f296333c326fbfb7865d165c9dd
#define Item_ClassName "%bc4886c510628f296333c326fbfb7865d165c9dd"
#define Item_ClassNameShort "%bc4886c510628f296333c326fbfb7865d165c9dd"
#define Item_TypeDefinitionIndex 306

	namespace Item {

		// Offsets
		constexpr const static size_t info = 0x70;
		constexpr const static size_t uid = 0x98;
		constexpr const static size_t _condition = 0xc8;
		constexpr const static size_t _maxCondition = 0xd0;
		constexpr const static size_t position = 0x24;
		constexpr const static size_t amount = 0xcc;
		constexpr const static size_t contents = 0x10;
		constexpr const static size_t parent = 0x60;
		constexpr const static size_t worldEnt = 0x50;
		constexpr const static size_t heldEntity = 0x88;

		// Functions
		constexpr const static size_t get_iconSprite = 0x1c682e0;
	}

	// obf name: ::%1efb1cab571d175e8f4d01eaa7e966b68d9314b7
#define WaterLevel_ClassName "%1efb1cab571d175e8f4d01eaa7e966b68d9314b7"
#define WaterLevel_ClassNameShort "%1efb1cab571d175e8f4d01eaa7e966b68d9314b7"
#define WaterLevel_TypeDefinitionIndex 5764

	namespace WaterLevel {

		// Functions
		constexpr const static size_t Test = 0x3b720d0;
		constexpr const static size_t GetWaterLevel = 0x3b68e90;
	}

	// obf name: ::%aa24786f97d7c94a1c614d6da6d391ecf5a500dc
#define ConVar_Graphics_Static_ClassName "%92bb8e339533cddd972431ff058c0bf9a9ae9cb6/%aa24786f97d7c94a1c614d6da6d391ecf5a500dc"
#define ConVar_Graphics_Static_ClassNameShort "%aa24786f97d7c94a1c614d6da6d391ecf5a500dc"
#define ConVar_Graphics_Static_TypeDefinitionIndex 1715

	namespace ConVar_Graphics_Static {

		// Offsets
		constexpr const static size_t _fov = 0x34c;

		// Functions
		constexpr const static size_t _fov_getter = 0x20f6db0;
		constexpr const static size_t _fov_setter = 0x20c3f60;
	}

#define BaseFishingRod_TypeDefinitionIndex 5246

	namespace BaseFishingRod {

		// Offsets
		constexpr const static size_t CurrentState = 0x250;
		constexpr const static size_t currentBobber = 0x258;
		constexpr const static size_t MaxCastDistance = 0x274;
		constexpr const static size_t BobberPreview = 0x280;
		constexpr const static size_t clientStrainAmountNormalised = 0x2c0;
		constexpr const static size_t strainGainMod = 0x2c8;
		constexpr const static size_t aimAnimationReady = 0x2d8;

		// Functions
		constexpr const static size_t UpdateLineRenderer = 0x3524310;
		constexpr const static size_t EvaluateFishingPosition = 0x35376c0;
	}

#define FishingBobber_TypeDefinitionIndex 3650

	namespace FishingBobber {

		// Offsets
		constexpr const static size_t bobberRoot = 0x268;
	}

#define GameManifest_TypeDefinitionIndex 5973

	namespace GameManifest {

		// Functions
		constexpr const static size_t GUIDToObject = 0x3d94240;
	}

	// obf name: ::%554304d0b6df7659cee9172184eaba3ab8d9f42d
#define GameManager_ClassName "%554304d0b6df7659cee9172184eaba3ab8d9f42d"
#define GameManager_ClassNameShort "%554304d0b6df7659cee9172184eaba3ab8d9f42d"
#define GameManager_TypeDefinitionIndex 2252

	namespace GameManager {

		// Offsets
		constexpr const static size_t pool = 0x18;

		// Functions
		constexpr const static size_t CreatePrefab = 0x14b7fa0;
	}

	// obf name: ::%b071624b2bfeea62b4d1b7daf91603af2fa9074a
#define GameManager_Static_ClassName "%554304d0b6df7659cee9172184eaba3ab8d9f42d/%b071624b2bfeea62b4d1b7daf91603af2fa9074a"
#define GameManager_Static_ClassNameShort "%b071624b2bfeea62b4d1b7daf91603af2fa9074a"
#define GameManager_Static_TypeDefinitionIndex 2251

	namespace GameManager_Static {

		// Offsets
		constexpr const static size_t client = 0x18;
	}

	// obf name: ::%ad92fd3a0a515a1ab6eeb25c1347a650ab2bac2b
#define PrefabPoolCollection_ClassName "%ad92fd3a0a515a1ab6eeb25c1347a650ab2bac2b"
#define PrefabPoolCollection_ClassNameShort "%ad92fd3a0a515a1ab6eeb25c1347a650ab2bac2b"
#define PrefabPoolCollection_TypeDefinitionIndex 4929

	namespace PrefabPoolCollection {

		// Offsets
		constexpr const static size_t storage = 0x10;
	}

	// obf name: ::%0c2dbc9e06d981f757022eb4f49648cfa9972c70
#define PrefabPool_ClassName "%0c2dbc9e06d981f757022eb4f49648cfa9972c70"
#define PrefabPool_ClassNameShort "%0c2dbc9e06d981f757022eb4f49648cfa9972c70"
#define PrefabPool_TypeDefinitionIndex 106

	namespace PrefabPool {

		// Offsets
		constexpr const static size_t stack = 0x18;
	}

#define ItemModProjectile_TypeDefinitionIndex 1792

	namespace ItemModProjectile {

		// Offsets
		constexpr const static size_t projectileObject = 0x20;
		constexpr const static size_t ammoType = 0x30;
		constexpr const static size_t projectileSpread = 0x38;
		constexpr const static size_t projectileVelocity = 0x3c;
		constexpr const static size_t projectileVelocitySpread = 0x40;
		constexpr const static size_t useCurve = 0x44;
		constexpr const static size_t spreadScalar = 0x48;
		constexpr const static size_t category = 0x60;
	}

#define Projectile_TypeDefinitionIndex 4022

	namespace Projectile {

		// Offsets
		constexpr const static size_t initialVelocity = 0x20;
		constexpr const static size_t drag = 0x2c;
		constexpr const static size_t gravityModifier = 0x30;
		constexpr const static size_t thickness = 0x34;
		constexpr const static size_t initialDistance = 0x3c;
		constexpr const static size_t swimScale = 0xe8;
		constexpr const static size_t swimSpeed = 0xf4;
		constexpr const static size_t owner = 0x118;
		constexpr const static size_t sourceProjectilePrefab = 0x108;
		constexpr const static size_t mod = 0x1d8;
		constexpr const static size_t hitTest = 0x110;
		constexpr const static size_t launchTime = 0x16c;
		constexpr const static size_t currentVelocity = 0x14c;
		constexpr const static size_t currentPosition = 0x158;
		constexpr const static size_t maxDistance = 0x130;
		constexpr const static size_t traveledDistance = 0x164;
		constexpr const static size_t traveledTime = 0x168;
		constexpr const static size_t previousTraveledTime = 0x194;
		constexpr const static size_t sentPosition = 0x170;
		constexpr const static size_t previousPosition = 0x17c;
		constexpr const static size_t previousVelocity = 0x188;
		constexpr const static size_t integrity = 0x12c;

		// Functions
		constexpr const static size_t CalculateEffectScale = 0x2804c10;
		constexpr const static size_t CalculateEffectScale_vtableoff = 0x2d8;
		constexpr const static size_t SetEffectScale = 0x2803080;
		constexpr const static size_t UpdateVelocity = 0x280dce0;
		constexpr const static size_t Retire = 0x2818550;
		constexpr const static size_t DoHit = 0x27fefd0;
	}

#define CraftingQueue_TypeDefinitionIndex 2742

	namespace CraftingQueue {

		// Offsets
		constexpr const static size_t icons = 0x30;
	}

	// obf name: ::%5732f0a2efeb0af9963855e46709753f635c4e9e
#define CraftingQueue_Static_ClassName "CraftingQueue/%5732f0a2efeb0af9963855e46709753f635c4e9e"
#define CraftingQueue_Static_ClassNameShort "%5732f0a2efeb0af9963855e46709753f635c4e9e"
#define CraftingQueue_Static_TypeDefinitionIndex 2741

	namespace CraftingQueue_Static {

		// Offsets
		constexpr const static size_t isCrafting = 0x22;
	}

#define CraftingQueueIcon_TypeDefinitionIndex 1687

	namespace CraftingQueueIcon {

		// Offsets
		constexpr const static size_t endTime = 0x4c;
		constexpr const static size_t item = 0x60;
	}

	// obf name: ::%3e192d6c3aacf7d4482e6383eaf6da372364362a
#define Planner_Static_ClassName "Planner/%3e192d6c3aacf7d4482e6383eaf6da372364362a"
#define Planner_Static_ClassNameShort "%3e192d6c3aacf7d4482e6383eaf6da372364362a"
#define Planner_Static_TypeDefinitionIndex 2883

	namespace Planner_Static {

		// Offsets
		constexpr const static size_t guide = 0x128;
	}

	// obf name: ::%acd22a0c3ed0ea82037e214d96ca84bf253b2b41
#define Planner_Guide_ClassName "Planner/%acd22a0c3ed0ea82037e214d96ca84bf253b2b41"
#define Planner_Guide_ClassNameShort "%acd22a0c3ed0ea82037e214d96ca84bf253b2b41"
#define Planner_Guide_TypeDefinitionIndex 2879

	namespace Planner_Guide {

		// Offsets
		constexpr const static size_t lastPlacement = 0x40;
	}

#define Planner_TypeDefinitionIndex 2884

	namespace Planner {

		// Offsets
		constexpr const static size_t _currentConstruction = 0x260;
	}

#define Construction_TypeDefinitionIndex 5196

	namespace Construction {

		// Offsets
		constexpr const static size_t holdToPlaceDuration = 0xf4;
		constexpr const static size_t grades = 0x128;
	}

#define BuildingBlock_TypeDefinitionIndex 1769

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t blockDefinition = 0x2f8;
	}

	// obf name: ::HeldEntity
#define HeldEntity_ClassName "HeldEntity"
#define HeldEntity_ClassNameShort "HeldEntity"
#define HeldEntity_TypeDefinitionIndex 1669

	namespace HeldEntity {

		// Offsets
		constexpr const static size_t ownerItemUID = 0x210;
		constexpr const static size_t _punches = 0x1c0;
		constexpr const static size_t viewModel = 0x218;

		// Functions
		constexpr const static size_t OnDeploy = 0xeba3b0;
	}

	// obf name: ::%9764421cc6664c47f52e5b7125b7b12eef3b41e1
#define PunchEntry_ClassName "HeldEntity/%9764421cc6664c47f52e5b7125b7b12eef3b41e1"
#define PunchEntry_ClassNameShort "%9764421cc6664c47f52e5b7125b7b12eef3b41e1"
#define PunchEntry_TypeDefinitionIndex 1667

	namespace PunchEntry {

		// Offsets
		constexpr const static size_t startTime = 0x10;
		constexpr const static size_t duration = 0x20;
		constexpr const static size_t amountAdded = 0x14;
		constexpr const static size_t amount = 0x24;
	}

#define IronSights_TypeDefinitionIndex 2967

	namespace IronSights {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t ironsightsOverride = 0x68;
	}

#define IronSightOverride_TypeDefinitionIndex 6466

	namespace IronSightOverride {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t fovBias = 0x30;
	}

#define BaseViewModel_TypeDefinitionIndex 3691

	namespace BaseViewModel {

		// Offsets
		constexpr const static size_t useViewModelCamera = 0x40;
		constexpr const static size_t ironSights = 0xd0;
		constexpr const static size_t model = 0xa8;
		constexpr const static size_t lower = 0xb8;

		// Functions
		constexpr const static size_t get_ActiveModel = 0x2532150;
	}

#define ViewModel_TypeDefinitionIndex 2179

	namespace ViewModel {

		// Offsets
		constexpr const static size_t instance = 0x28;

		// Functions
		constexpr const static size_t PlayInt = 0x1433620;
		constexpr const static size_t PlayString = 0x1432aa0;
	}

#define MedicalTool_TypeDefinitionIndex 6360

	namespace MedicalTool {

		// Offsets
		constexpr const static size_t resetTime = 0x2e8;
	}

#define WaterBody_TypeDefinitionIndex 4152

	namespace WaterBody {

		// Offsets
		constexpr const static size_t meshFilter = 0x68;
	}

	// obf name: ::%1b835264de624e6b9f90938864b3fb25345e1793
#define WaterSystem_Static_ClassName "WaterSystem/%1b835264de624e6b9f90938864b3fb25345e1793"
#define WaterSystem_Static_ClassNameShort "%1b835264de624e6b9f90938864b3fb25345e1793"
#define WaterSystem_Static_TypeDefinitionIndex 5366

	namespace WaterSystem_Static {

		// Offsets
		constexpr const static size_t Ocean = 0xe8;
	}

#define WaterSystem_TypeDefinitionIndex 5367

	namespace WaterSystem {

		// Functions
		constexpr const static size_t get_Ocean = 0x3664260;
	}

#define TerrainMeta_TypeDefinitionIndex 3952

	namespace TerrainMeta {

		// Offsets
		constexpr const static size_t Position = 0x18;
		constexpr const static size_t Size = 0x24;
		constexpr const static size_t OneOverSize = 0x30;
		constexpr const static size_t Collision = 0x100;
		constexpr const static size_t HeightMap = 0x4a0;
		constexpr const static size_t SplatMap = 0x4b8;
		constexpr const static size_t TopologyMap = 0x458;
		constexpr const static size_t Texturing = 0x530;
	}

#define TerrainCollision_TypeDefinitionIndex 2311

	namespace TerrainCollision {

		// Functions
		constexpr const static size_t GetIgnore = 0x154E420;
	}

#define TerrainHeightMap_TypeDefinitionIndex 1449

	namespace TerrainHeightMap {

		// Offsets
		constexpr const static size_t normY = 0x70;
	}

#define TerrainSplatMap_TypeDefinitionIndex 5475

	namespace TerrainSplatMap {

		// Offsets
		constexpr const static size_t num = 0x70;
	}

#define TerrainTexturing_TypeDefinitionIndex 5566

	namespace TerrainTexturing {

		// Offsets
		constexpr const static size_t shoreMapSize = 0x8c;
		constexpr const static size_t terrainSize = 0x88;
		constexpr const static size_t shoreDistanceScale = 0x90;
		constexpr const static size_t shoreVectors = 0xa8;
	}

	// obf name: ::%24b4086c0a7eb32d9f6fc446f8ccd805df8bf32c
#define World_Static_ClassName "%41dd23d860b2269bb2759291f9764297c2e80d9c/%24b4086c0a7eb32d9f6fc446f8ccd805df8bf32c"
#define World_Static_ClassNameShort "%24b4086c0a7eb32d9f6fc446f8ccd805df8bf32c"
#define World_Static_TypeDefinitionIndex 3635

	namespace World_Static {

		// Offsets
		constexpr const static size_t _size = 0x9c;
	}

#define ItemIcon_TypeDefinitionIndex 531

	namespace ItemIcon {

		// Functions
		constexpr const static size_t SetTimedLootAction = 0x319c330;
	}

	// obf name: ::%f4c2084e13a11d7e5f9703a64eadcecfb9f54162
#define ItemIcon_Static_ClassName "ItemIcon/%f4c2084e13a11d7e5f9703a64eadcecfb9f54162"
#define ItemIcon_Static_ClassNameShort "%f4c2084e13a11d7e5f9703a64eadcecfb9f54162"
#define ItemIcon_Static_TypeDefinitionIndex 530

	namespace ItemIcon_Static {

		// Offsets
		constexpr const static size_t containerLootStartTimes = 0x28;
	}

	// obf name: ::%b25e1ed5410509398c0b6d32783c5940d6316f05
#define Effect_ClassName "%b25e1ed5410509398c0b6d32783c5940d6316f05"
#define Effect_ClassNameShort "%b25e1ed5410509398c0b6d32783c5940d6316f05"
#define Effect_TypeDefinitionIndex 5526

	namespace Effect {

		// Offsets
		constexpr const static size_t pooledString = 0x58;
		constexpr const static size_t worldPos = 0x70;
	}

	// obf name: ::%b5a0b6ba1d7c212528176e378030ab9e0de6b7ec
#define EffectNetwork_ClassName "%b5a0b6ba1d7c212528176e378030ab9e0de6b7ec"
#define EffectNetwork_ClassNameShort "%b5a0b6ba1d7c212528176e378030ab9e0de6b7ec"
#define EffectNetwork_TypeDefinitionIndex 3235

	namespace EffectNetwork {

		// Functions
	}

	// obf name: ::%6ba9d1985fab60fe96f709bcb02a8db9d5cb29e0
#define EffectNetwork_Static_ClassName "%b5a0b6ba1d7c212528176e378030ab9e0de6b7ec/%6ba9d1985fab60fe96f709bcb02a8db9d5cb29e0"
#define EffectNetwork_Static_ClassNameShort "%6ba9d1985fab60fe96f709bcb02a8db9d5cb29e0"
#define EffectNetwork_Static_TypeDefinitionIndex 3234

	namespace EffectNetwork_Static {

		// Offsets
		constexpr const static size_t effect = 0x10;

		// Functions
		constexpr const static size_t cctor = 0x1f37d60;
	}

#define BuildingBlock_TypeDefinitionIndex 1769

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t grade = 0x2d8;

		// Functions
		constexpr const static size_t GetBuildMenu = 0xfe6ba0;
		constexpr const static size_t HasUpgradePrivilege = 0xfe3eb0;
		constexpr const static size_t CanAffordUpgrade = 0x10115d0;
	}

	// obf name: ::%ebfc130e6c582872f4f7d0f53734ff7a9ab4fee5
#define GameObjectEx_ClassName "%ebfc130e6c582872f4f7d0f53734ff7a9ab4fee5"
#define GameObjectEx_ClassNameShort "%ebfc130e6c582872f4f7d0f53734ff7a9ab4fee5"
#define GameObjectEx_TypeDefinitionIndex 866

	namespace GameObjectEx {

		// Functions
		constexpr const static size_t ToBaseEntity = 0x44f6650;
	}

#define UIDeathScreen_TypeDefinitionIndex 2745

	namespace UIDeathScreen {

		// Functions
		constexpr const static size_t SetVisible = 0x198d170;
	}

	// obf name: ::%06272af9ea8640bf6bb58b5c0bb1cf2d5a8a83cc
#define BaseScreenShake_Static_ClassName "BaseScreenShake/%06272af9ea8640bf6bb58b5c0bb1cf2d5a8a83cc"
#define BaseScreenShake_Static_ClassNameShort "%06272af9ea8640bf6bb58b5c0bb1cf2d5a8a83cc"
#define BaseScreenShake_Static_TypeDefinitionIndex 1752

	namespace BaseScreenShake_Static {

		// Offsets
		constexpr const static size_t list = 0x80;
	}

#define FlashbangOverlay_TypeDefinitionIndex 5031

	namespace FlashbangOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x18;
		constexpr const static size_t flashLength = 0x48;
	}

	// obf name: ::%e3590d8718100fb6de41c2a87606845b56fb5625
#define StringPool_ClassName "%e3590d8718100fb6de41c2a87606845b56fb5625"
#define StringPool_ClassNameShort "%e3590d8718100fb6de41c2a87606845b56fb5625"
#define StringPool_TypeDefinitionIndex 4987

	namespace StringPool {

		// Offsets
		constexpr const static size_t toNumber = 0x50;

		// Functions
		constexpr const static size_t Get = 0x3245a10;
	}

	// obf name: ::%d5c3143726828593e3ba295033c2dc60783ae7fa
#define Network_Networkable_ClassName "%d5c3143726828593e3ba295033c2dc60783ae7fa"
#define Network_Networkable_ClassNameShort "%d5c3143726828593e3ba295033c2dc60783ae7fa"
#define Network_Networkable_TypeDefinitionIndex 16749

	namespace Network_Networkable {

		// Offsets
		constexpr const static size_t ID = 0x50;
	}

	// obf name: ::%f907a9324601f78e44e9c84fdbf6b113086eeace
#define Network_Net_ClassName "%f907a9324601f78e44e9c84fdbf6b113086eeace"
#define Network_Net_ClassNameShort "%f907a9324601f78e44e9c84fdbf6b113086eeace"
#define Network_Net_TypeDefinitionIndex 8326

	namespace Network_Net {

		// Offsets
		constexpr const static size_t cl = 0x10;
	}

	// obf name: ::%0df9603831aa76abc35cda2c02a195ddb28d8354
#define Network_Client_ClassName "%0df9603831aa76abc35cda2c02a195ddb28d8354"
#define Network_Client_ClassNameShort "%0df9603831aa76abc35cda2c02a195ddb28d8354"
#define Network_Client_TypeDefinitionIndex 16728

	namespace Network_Client {

		// Offsets
		constexpr const static size_t Connection = 0xf8;
		constexpr const static size_t ConnectedPort = 0xe8;
		constexpr const static size_t ServerName = 0x108;
		constexpr const static size_t ConnectedAddress = 0x110;
	}

	// obf name: ::%ea6ae81ffa1b87c6cc9b4986da8fa19163da7161
#define Network_BaseNetwork_ClassName "%ea6ae81ffa1b87c6cc9b4986da8fa19163da7161"
#define Network_BaseNetwork_ClassNameShort "%ea6ae81ffa1b87c6cc9b4986da8fa19163da7161"
#define Network_BaseNetwork_TypeDefinitionIndex 16760

	namespace Network_BaseNetwork {

		// Functions
		constexpr const static size_t StartWrite = 0x5db2520;
	}

	// obf name: ::%e78f8093a5fa7b7e0b8f5b54e48e5bf45763b186
#define Network_SendInfo_ClassName "%e78f8093a5fa7b7e0b8f5b54e48e5bf45763b186"
#define Network_SendInfo_ClassNameShort "%e78f8093a5fa7b7e0b8f5b54e48e5bf45763b186"
#define Network_SendInfo_TypeDefinitionIndex 16710

	namespace Network_SendInfo {

		// Offsets
		constexpr const static size_t method = 0x0;
		constexpr const static size_t channel = 0x4;
		constexpr const static size_t priority = 0x8;
		constexpr const static size_t connections = 0x10;
		constexpr const static size_t connection = 0x18;
	}

	// obf name: ::%4ab5fcb9c32fa6b360e368aec657cc783d81fc2d
#define Network_Message_ClassName "%4ab5fcb9c32fa6b360e368aec657cc783d81fc2d"
#define Network_Message_ClassNameShort "%4ab5fcb9c32fa6b360e368aec657cc783d81fc2d"
#define Network_Message_TypeDefinitionIndex 16716

	namespace Network_Message {

		// Offsets
		constexpr const static size_t type = 0x18;
		constexpr const static size_t read = 0x10;
	}

	// obf name: ::%0cdb099a644e7653bd43e9a716d4075eb6802562
#define Network_NetRead_ClassName "%0cdb099a644e7653bd43e9a716d4075eb6802562"
#define Network_NetRead_ClassNameShort "%0cdb099a644e7653bd43e9a716d4075eb6802562"
#define Network_NetRead_TypeDefinitionIndex 16726

	namespace Network_NetRead {

		// Offsets
		constexpr const static size_t stream = 0x38;
	}

	// obf name: ::%86d83fe901804b611ea05f25f32da715f101a247
#define Network_NetWrite_ClassName "%86d83fe901804b611ea05f25f32da715f101a247"
#define Network_NetWrite_ClassNameShort "%86d83fe901804b611ea05f25f32da715f101a247"
#define Network_NetWrite_TypeDefinitionIndex 16730

	namespace Network_NetWrite {

		// Offsets
		constexpr const static size_t stream = 0x48;

		// Functions
		constexpr const static size_t UInt8 = 0x313620;
		constexpr const static size_t UInt32 = 0x3134F0;
		constexpr const static size_t UInt64 = 0x3136F0;
		constexpr const static size_t String = 0x5d85860;
		constexpr const static size_t Send = 0x5d83760;
	}

#define LootPanel_TypeDefinitionIndex 1123

	namespace LootPanel {

		// Functions
		constexpr const static size_t get_Container_00 = 0x479ce00;
	}

#define UIInventory_TypeDefinitionIndex 3460

	namespace UIInventory {

		// Functions
		constexpr const static size_t Close = 0x233e520;
	}

#define GrowableEntity_TypeDefinitionIndex 1722

	namespace GrowableEntity {

		// Offsets
		constexpr const static size_t Properties = 0x2a0;
		constexpr const static size_t State = 0x2b0;
	}

#define PlantProperties_TypeDefinitionIndex 4039

	namespace PlantProperties {

		// Offsets
		constexpr const static size_t stages = 0x28;
	}

#define PlantProperties_Stage_TypeDefinitionIndex 4038

	namespace PlantProperties_Stage {

		// Offsets
		constexpr const static size_t resources = 0xc;
	}

#define Text_TypeDefinitionIndex 18342

	namespace Text {

		// Offsets
		constexpr const static size_t m_Text = 0xd8;
	}

#define TOD_Sky_TypeDefinitionIndex 7786

	namespace TOD_Sky {

		// Offsets
		constexpr const static size_t Cycle = 0x40;
		constexpr const static size_t Atmosphere = 0x50;
		constexpr const static size_t Day = 0x58;
		constexpr const static size_t Night = 0x60;
		constexpr const static size_t Stars = 0x78;
		constexpr const static size_t Clouds = 0x80;
		constexpr const static size_t Ambient = 0x98;

		// Functions
		constexpr const static size_t get_Instance = 0x9d6c50;
	}

	// obf name: ::%78fb2c3ff3f8db151d7c8bcfb6444ed1fd2a0368
#define TOD_Sky_Static_ClassName "TOD_Sky/%78fb2c3ff3f8db151d7c8bcfb6444ed1fd2a0368"
#define TOD_Sky_Static_ClassNameShort "%78fb2c3ff3f8db151d7c8bcfb6444ed1fd2a0368"
#define TOD_Sky_Static_TypeDefinitionIndex 7785

	namespace TOD_Sky_Static {

		// Offsets
		constexpr const static size_t instances = 0x28;
	}

#define TOD_CycleParameters_TypeDefinitionIndex 8275

	namespace TOD_CycleParameters {

		// Functions
		constexpr const static size_t get_DateTime = 0xb2e970;
	}

#define TOD_AtmosphereParameters_TypeDefinitionIndex 9155

	namespace TOD_AtmosphereParameters {

		// Offsets
		constexpr const static size_t RayleighMultiplier = 0x10;
	}

#define TOD_DayParameters_TypeDefinitionIndex 8844

	namespace TOD_DayParameters {

		// Offsets
		constexpr const static size_t SkyColor = 0x28;
	}

#define TOD_NightParameters_TypeDefinitionIndex 8046

	namespace TOD_NightParameters {

		// Offsets
		constexpr const static size_t MoonColor = 0x10;
		constexpr const static size_t CloudColor = 0x38;
		constexpr const static size_t AmbientColor = 0x48;
	}

#define TOD_StarParameters_TypeDefinitionIndex 8668

	namespace TOD_StarParameters {

		// Offsets
		constexpr const static size_t Size = 0x10;
		constexpr const static size_t Brightness = 0x14;
	}

#define TOD_CloudParameters_TypeDefinitionIndex 8887

	namespace TOD_CloudParameters {

		// Offsets
		constexpr const static size_t Brightness = 0x30;
	}

#define TOD_AmbientParameters_TypeDefinitionIndex 8915

	namespace TOD_AmbientParameters {

		// Offsets
		constexpr const static size_t Saturation = 0x14;
	}

#define UIHUD_TypeDefinitionIndex 2053

	namespace UIHUD {

		// Offsets
		constexpr const static size_t Hunger = 0x28;
	}

#define HudElement_TypeDefinitionIndex 2513

	namespace HudElement {

		// Offsets
		constexpr const static size_t lastValue = 0x30;
	}

#define UIBelt_TypeDefinitionIndex 4271

	namespace UIBelt {

		// Offsets
		constexpr const static size_t ItemIcons = 0x20;
	}

#define ItemModCompostable_TypeDefinitionIndex 4862

	namespace ItemModCompostable {

		// Offsets
		constexpr const static size_t MaxBaitStack = 0x28;
	}

	// obf name: ::ResourceRef`1
#define GameObjectRef_ClassName "ResourceRef<UnityEngine/GameObject>"
#define GameObjectRef_ClassNameShort "ResourceRef`1"
#define GameObjectRef_TypeDefinitionIndex -1

	namespace GameObjectRef {

		// Offsets
		constexpr const static size_t guid = 0x10;
	}

#define EnvironmentManager_TypeDefinitionIndex 5835

	namespace EnvironmentManager {

		// Functions
		constexpr const static size_t Get = 0x3c45ef0;
	}

	// obf name: ::Phrase
#define Translate_Phrase_ClassName "%67f399529dde918417e74fcb5da9af39a0dc3fae/Phrase"
#define Translate_Phrase_ClassNameShort "Phrase"
#define Translate_Phrase_TypeDefinitionIndex -1

	namespace Translate_Phrase {

		// Offsets
		constexpr const static size_t english = 0x18;
	}

#define ResourceDispenser_GatherPropertyEntry_TypeDefinitionIndex 1524

	namespace ResourceDispenser_GatherPropertyEntry {

		// Offsets
		constexpr const static size_t gatherDamage = 0x10;
		constexpr const static size_t destroyFraction = 0x14;
		constexpr const static size_t conditionLost = 0x18;
	}

#define ResourceDispenser_GatherProperties_TypeDefinitionIndex 1525

	namespace ResourceDispenser_GatherProperties {

		// Offsets
		constexpr const static size_t Tree = 0x10;
		constexpr const static size_t Ore = 0x18;
		constexpr const static size_t Flesh = 0x20;
	}

#define UIChat_TypeDefinitionIndex 4725

	namespace UIChat {

		// Offsets
		constexpr const static size_t chatArea = 0x28;
	}

	// obf name: ::ListComponent`1
#define ListComponent_ClassName "ListComponent<UIChat>"
#define ListComponent_ClassNameShort "ListComponent`1"
#define ListComponent_TypeDefinitionIndex -1

	namespace ListComponent {

		// Offsets
		constexpr const static size_t InstanceList = 0x10;
	}

	// obf name: ::%228c52d9072c566f14d05e554fa2459785fd1ce8
#define ListHashSet_ClassName "%228c52d9072c566f14d05e554fa2459785fd1ce8<UIChat>"
#define ListHashSet_ClassNameShort "%228c52d9072c566f14d05e554fa2459785fd1ce8"
#define ListHashSet_TypeDefinitionIndex -1

	namespace ListHashSet {

		// Offsets
		constexpr const static size_t vals = 0x10;
	}

#define PatrolHelicopter_TypeDefinitionIndex 1791

	namespace PatrolHelicopter {

		// Offsets
		constexpr const static size_t mainRotor = 0x258;
		constexpr const static size_t weakspots = 0x3d8;
	}

#define Chainsaw_TypeDefinitionIndex 5384

	namespace Chainsaw {

		// Offsets
		constexpr const static size_t ammo = 0x374;
	}

	// obf name: ::%6b7e018494bed472e6b10003830f52f673adc6c1
#define CameraUpdateHook_Static_ClassName "CameraUpdateHook/%6b7e018494bed472e6b10003830f52f673adc6c1"
#define CameraUpdateHook_Static_ClassNameShort "%6b7e018494bed472e6b10003830f52f673adc6c1"
#define CameraUpdateHook_Static_TypeDefinitionIndex 2917

	namespace CameraUpdateHook_Static {

		// Offsets
		constexpr const static size_t action = 0x50;
	}

#define SteamClientWrapper_TypeDefinitionIndex 3759

	namespace SteamClientWrapper {

		// Functions
		constexpr const static size_t GetAvatarTexture = 0x2625580;
	}

	// obf name: ::%5720c36ff7efc8e2837e27ce4f55b8ac4279594a
#define AimConeUtil_ClassName "%5720c36ff7efc8e2837e27ce4f55b8ac4279594a"
#define AimConeUtil_ClassNameShort "%5720c36ff7efc8e2837e27ce4f55b8ac4279594a"
#define AimConeUtil_TypeDefinitionIndex 873

	namespace AimConeUtil {

		// Functions
		constexpr const static size_t GetModifiedAimConeDirection = 0x44fd1a0;
	}

	// obf name: ::%791e02b1e8014c0e46db6421a36580a131742046
#define Buttons_ConButton_ClassName "%415be8b87c99b5d8da5cf74fa8f30c528cabdac4/%791e02b1e8014c0e46db6421a36580a131742046"
#define Buttons_ConButton_ClassNameShort "%791e02b1e8014c0e46db6421a36580a131742046"
#define Buttons_ConButton_TypeDefinitionIndex 3065

	namespace Buttons_ConButton {

		// Offsets
		constexpr const static size_t IsDown = 0x14;
	}

	// obf name: ::%a858450af0eb92bd136f5ab90ecffff98a52128b
#define Buttons_Static_ClassName "%415be8b87c99b5d8da5cf74fa8f30c528cabdac4/%a858450af0eb92bd136f5ab90ecffff98a52128b"
#define Buttons_Static_ClassNameShort "%a858450af0eb92bd136f5ab90ecffff98a52128b"
#define Buttons_Static_TypeDefinitionIndex 3066

	namespace Buttons_Static {

		// Offsets
		constexpr const static size_t Pets = 0xa0;
		constexpr const static size_t Attack = 0x5a0;
		constexpr const static size_t Attack2 = 0x920;
		constexpr const static size_t Forward = 0xbb8;
		constexpr const static size_t Backward = 0x5b8;
		constexpr const static size_t Right = 0xbc0;
		constexpr const static size_t Left = 0xa08;
		constexpr const static size_t Sprint = 0x470;

		// Functions
		constexpr const static size_t Pets_setter = 0x20da7f0;
	}

#define PlayerModel_TypeDefinitionIndex 3289

	namespace PlayerModel {

		// Offsets
		constexpr const static size_t _multiMesh = 0x298;
		constexpr const static size_t position = 0x1d8;
		constexpr const static size_t newVelocity = 0x1fc;
	}

#define SkinnedMultiMesh_TypeDefinitionIndex 5179

	namespace SkinnedMultiMesh {

		// Offsets
		constexpr const static size_t Renderers = 0x58;
	}

#define BaseMountable_TypeDefinitionIndex 5599

	namespace BaseMountable {

		// Offsets
		constexpr const static size_t pitchClamp = 0x274;
		constexpr const static size_t yawClamp = 0x27c;
		constexpr const static size_t canWieldItems = 0x284;
	}

#define ProgressBar_TypeDefinitionIndex 4565

	namespace ProgressBar {

		// Offsets
		constexpr const static size_t Instance = 0x30;
		constexpr const static size_t timeCounter = 0x24;
	}

#define BowWeapon_TypeDefinitionIndex 6130

	namespace BowWeapon {

		// Offsets
		constexpr const static size_t attackReady = 0x3f0;
		constexpr const static size_t wasAiming = 0x400;
	}

#define CrossbowWeapon_TypeDefinitionIndex 3703

	namespace CrossbowWeapon {

		// Offsets
	}

#define MiniCrossbow_TypeDefinitionIndex 2072

	namespace MiniCrossbow {

		// Offsets
	}

	// obf name: ::%5defda04a2d11470da405ef12e4c34d2134fe3eb
#define ConVar_Admin_Static_ClassName "%a4151dac7d6a179441ca7fa7e1a963abf17a979f/%5defda04a2d11470da405ef12e4c34d2134fe3eb"
#define ConVar_Admin_Static_ClassNameShort "%5defda04a2d11470da405ef12e4c34d2134fe3eb"
#define ConVar_Admin_Static_TypeDefinitionIndex 3101

	namespace ConVar_Admin_Static {

		// Offsets
		constexpr const static size_t admintime = 0x9c;

		// Functions
		constexpr const static size_t admintime_getter = 0x20cb4a0;
		constexpr const static size_t admintime_setter = 0x20f2f80;
	}

	// obf name: ::%172e08204e1a891bb925dc939ee622979463a966
#define ConVar_Player_Static_ClassName "%0304f4fffe2c22843473ecf575a66d2d00bc7685/%172e08204e1a891bb925dc939ee622979463a966"
#define ConVar_Player_Static_ClassNameShort "%172e08204e1a891bb925dc939ee622979463a966"
#define ConVar_Player_Static_TypeDefinitionIndex 4800

	namespace ConVar_Player_Static {

		// Offsets
		constexpr const static size_t clientTickInterval = 0x174;

		// Functions
		constexpr const static size_t clientTickRate_getter = 0x20dd7e0;
		constexpr const static size_t clientTickRate_setter = 0x20d25a0;
	}

#define ColliderInfo_TypeDefinitionIndex 6029

	namespace ColliderInfo {

		// Offsets
		constexpr const static size_t flags = 0x20;
	}

#define CodeLock_TypeDefinitionIndex 2382

	namespace CodeLock {

		// Offsets
		constexpr const static size_t hasCode = 0x210;
		constexpr const static size_t hasAuth = 0x211;
		constexpr const static size_t hasGuestAuth = 0x212;
	}

#define AutoTurret_TypeDefinitionIndex 3217

	namespace AutoTurret {

		// Offsets
		constexpr const static size_t authorizedPlayers = 0x318;
		constexpr const static size_t lastYaw = 0x3b0;
		constexpr const static size_t muzzlePos = 0x3d0;
		constexpr const static size_t gun_yaw = 0x3e8;
		constexpr const static size_t gun_pitch = 0x3f0;
		constexpr const static size_t sightRange = 0x3f8;

		// Functions
		constexpr const static size_t IsAuthed = 0x1ee9c10;
	}

#define Client_TypeDefinitionIndex 3198

	namespace Client {

		// Functions
		constexpr const static size_t OnNetworkMessage = 0x1ec1680;
		constexpr const static size_t OnNetworkMessage_vtableoff = 0x1c8;
		constexpr const static size_t CreateOrUpdateEntity = 0x1e95e20;
	}

#define BaseNetworkable_TypeDefinitionIndex 666

	namespace BaseNetworkable {

		// Functions
		constexpr const static size_t Load = 0x3f2aa30;
		constexpr const static size_t Load_vtableoff = 0x638;
	}

	// obf name: ::%79617ed8f9dabdd40677d3cdf62a3820a29c0c08
#define ItemManager_Static_ClassName "%644f0cb7d471c3d8e1d4a71c80879347b7105f5d/%79617ed8f9dabdd40677d3cdf62a3820a29c0c08"
#define ItemManager_Static_ClassNameShort "%79617ed8f9dabdd40677d3cdf62a3820a29c0c08"
#define ItemManager_Static_TypeDefinitionIndex 337

	namespace ItemManager_Static {

		// Offsets
		constexpr const static size_t itemList = 0xb8;
		constexpr const static size_t itemDictionary = 0x150;
		constexpr const static size_t itemDictionaryByName = 0x140;
	}

	// obf name: ::%371bf29d87beb425eea8896f28f91911aa9932c0
#define ConVar_Server_Static_ClassName "%3e10becc27ee4025db5ec9a03bc5e6ac3e291607/%371bf29d87beb425eea8896f28f91911aa9932c0"
#define ConVar_Server_Static_ClassNameShort "%371bf29d87beb425eea8896f28f91911aa9932c0"
#define ConVar_Server_Static_TypeDefinitionIndex 2123

	namespace ConVar_Server_Static {

		// Offsets
	}

#define ServerAdminUGCEntry_TypeDefinitionIndex 5909

	namespace ServerAdminUGCEntry {

		// Functions
		constexpr const static size_t ReceivedDataFromServer = 0x3d0e390;
	}

#define LoadingScreen_TypeDefinitionIndex 4810

	namespace LoadingScreen {

		// Offsets
		constexpr const static size_t panel = 0x20;
	}

#define MixerSnapshotManager_TypeDefinitionIndex 6459

	namespace MixerSnapshotManager {

		// Offsets
		constexpr const static size_t defaultSnapshot = 0x20;
		constexpr const static size_t loadingSnapshot = 0x30;
	}

#define MapView_Static_ClassName "MapView/%9751370a443d64603df9fc5fabc978aa3803b5c4"
#define MapView_Static_ClassNameShort "%9751370a443d64603df9fc5fabc978aa3803b5c4"
#define MapView_TypeDefinitionIndex 510

	namespace MapView {

		// Functions
		constexpr const static size_t WorldPosToImagePos = 0x2ea0b40;
	}

	// obf name: ::%fed6a02431f3d82481ea23d7968c333ac67cf6c1
#define GamePhysics_ClassName "%fed6a02431f3d82481ea23d7968c333ac67cf6c1"
#define GamePhysics_ClassNameShort "%fed6a02431f3d82481ea23d7968c333ac67cf6c1"
#define GamePhysics_TypeDefinitionIndex 1148

	namespace GamePhysics {

		// Functions
		constexpr const static size_t Trace = 0x4809840;
		constexpr const static size_t LineOfSightInternal = 0x480ffd0;
		constexpr const static size_t Verify = 0x480a640;
	}

#define DDraw_TypeDefinitionIndex 2823

	namespace DDraw {

		// Functions
		constexpr const static size_t Sphere = 0x1a6a450;
		constexpr const static size_t Line = 0x1a6c260;
	}

	// obf name: ::%f918dcbdfcba6d2781047f85eae3555c1cf162da
#define RaycastHitEx_ClassName "%f918dcbdfcba6d2781047f85eae3555c1cf162da"
#define RaycastHitEx_ClassNameShort "%f918dcbdfcba6d2781047f85eae3555c1cf162da"
#define RaycastHitEx_TypeDefinitionIndex 3057

	namespace RaycastHitEx {

		// Functions
		constexpr const static size_t GetEntity = 0x1d23310;
	}

	// obf name: ::%80c5366c47181328449cf8c7203dd9919f042df1
#define OnParentDestroyingEx_ClassName "%80c5366c47181328449cf8c7203dd9919f042df1"
#define OnParentDestroyingEx_ClassNameShort "%80c5366c47181328449cf8c7203dd9919f042df1"
#define OnParentDestroyingEx_TypeDefinitionIndex 3082

	namespace OnParentDestroyingEx {

		// Functions
		constexpr const static size_t BroadcastOnParentDestroying = 0x1d56540;
	}

	// obf name: ::%f44ee7f6c972da919ba38d9bb32096c2a3629157
#define ConsoleNetwork_ClassName "%f44ee7f6c972da919ba38d9bb32096c2a3629157"
#define ConsoleNetwork_ClassNameShort "%f44ee7f6c972da919ba38d9bb32096c2a3629157"
#define ConsoleNetwork_TypeDefinitionIndex 2438

	namespace ConsoleNetwork {

		// Functions
		constexpr const static size_t ClientRunOnServer = 0x169a7f0;
	}

#define ThrownWeapon_TypeDefinitionIndex 4665

	namespace ThrownWeapon {

		// Offsets
		constexpr const static size_t maxThrowVelocity = 0x2d0;
	}

#define MapInterface_TypeDefinitionIndex 2479

	namespace MapInterface {

		// Offsets
		constexpr const static size_t scrollRectZoom = 0x30;
	}

#define ScrollRectZoom_TypeDefinitionIndex 2743

	namespace ScrollRectZoom {

		// Offsets
		constexpr const static size_t zoom = 0x28;
	}

#define MapView_TypeDefinitionIndex 510

	namespace MapView {

		// Offsets
		constexpr const static size_t scrollRect = 0x30;
	}

#define StorageContainer_TypeDefinitionIndex 945

	namespace StorageContainer {

		// Offsets
		constexpr const static size_t inventorySlots = 0x2a0;
	}

#define PlayerCorpse_TypeDefinitionIndex 4631

	namespace PlayerCorpse {

		// Offsets
		constexpr const static size_t clientClothing = 0x2d0;
	}

#define TimedExplosive_TypeDefinitionIndex 5465

	namespace TimedExplosive {

		// Offsets
		constexpr const static size_t explosionRadius = 0x1ac;
	}

	// obf name: ::%614bd33fcb25973c30c7c7eb8eb6e277d607104e
#define SmokeGrenade_Static_ClassName "SmokeGrenade/%614bd33fcb25973c30c7c7eb8eb6e277d607104e"
#define SmokeGrenade_Static_ClassNameShort "%614bd33fcb25973c30c7c7eb8eb6e277d607104e"
#define SmokeGrenade_Static_TypeDefinitionIndex 4582

	namespace SmokeGrenade_Static {

		// Offsets
		constexpr const static size_t activeGrenades = 0x38;
	}

#define SmokeGrenade_TypeDefinitionIndex 4583

	namespace SmokeGrenade {

		// Offsets
		constexpr const static size_t smokeEffectInstance = 0x250;
	}

#define GrenadeWeapon_TypeDefinitionIndex 2441

	namespace GrenadeWeapon {

		// Offsets
		constexpr const static size_t drop = 0x2e8;
	}

#define ViewmodelLower_TypeDefinitionIndex 5519

	namespace ViewmodelLower {

		// Offsets
		constexpr const static size_t lowerOnSprint = 0x20;
		constexpr const static size_t lowerWhenCantAttack = 0x21;
		constexpr const static size_t shouldLower = 0x28;
		constexpr const static size_t rotateAngle = 0x2c;
	}

	// obf name: ::%45c7caedeb92ac0ee639cd5e813ac7619cc1ed53
#define ConVar_Client_Static_ClassName "%0ae8f6c0e7778d6caf6ccb6ae7749147f6c355ed/%45c7caedeb92ac0ee639cd5e813ac7619cc1ed53"
#define ConVar_Client_Static_ClassNameShort "%45c7caedeb92ac0ee639cd5e813ac7619cc1ed53"
#define ConVar_Client_Static_TypeDefinitionIndex 2984

	namespace ConVar_Client_Static {

		// Offsets
		constexpr const static size_t camlerp = 0x110;
		constexpr const static size_t camspeed = 0x6d8;
	}

#define SamSite_TypeDefinitionIndex 6192

	namespace SamSite {

		// Offsets
		constexpr const static size_t staticRespawn = 0x390;
		constexpr const static size_t Flag_TargetMode = 0x3cc;
	}

#define ServerProjectile_TypeDefinitionIndex 6481

	namespace ServerProjectile {

		// Offsets
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t speed = 0x3c;
		constexpr const static size_t radius = 0x5c;
	}

#define UIFogOverlay_TypeDefinitionIndex 5851

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t group = 0x20;
	}

#define FoliageGrid_TypeDefinitionIndex 6180

	namespace FoliageGrid {

		// Offsets
		constexpr const static size_t CellSize = 0x28;
	}

#define ItemModWearable_TypeDefinitionIndex 3211

	namespace ItemModWearable {

		// Offsets
		constexpr const static size_t movementProperties = 0x48;
	}

#define ClothingMovementProperties_TypeDefinitionIndex 3660

	namespace ClothingMovementProperties {

		// Offsets
		constexpr const static size_t speedReduction = 0x18;
		constexpr const static size_t minSpeedReduction = 0x1c;
	}

#define GestureConfig_TypeDefinitionIndex 4330

	namespace GestureConfig {

		// Offsets
		constexpr const static size_t actionType = 0x90;
	}

#define RCMenu_TypeDefinitionIndex 765

	namespace RCMenu {

		// Offsets
		constexpr const static size_t autoTurretFogDistance = 0x124;
	}

	// obf name: ::%3d0ace5632d929ae875e4226014bace05337f5dc
#define Facepunch_Network_Raknet_Client_ClassName "%3d0ace5632d929ae875e4226014bace05337f5dc"
#define Facepunch_Network_Raknet_Client_ClassNameShort "%3d0ace5632d929ae875e4226014bace05337f5dc"
#define Facepunch_Network_Raknet_Client_TypeDefinitionIndex 19847

	namespace Facepunch_Network_Raknet_Client {

		// Functions
		constexpr const static size_t IsConnected = 0x5e05090;
		constexpr const static size_t IsConnected_vtableoff = 0x3a8;
	}

	// obf name: ::%ad2e45cd2dffb4ed5426c14cbdff7a18a3010eb3
#define EncryptedValue_ClassName "%ad2e45cd2dffb4ed5426c14cbdff7a18a3010eb3<System/Int32>"
#define EncryptedValue_ClassNameShort "%ad2e45cd2dffb4ed5426c14cbdff7a18a3010eb3"
#define EncryptedValue_TypeDefinitionIndex -1

	namespace EncryptedValue {

		// Offsets
		constexpr const static size_t _value = 0x0;
		constexpr const static size_t _padding = 0x10;
	}

	// obf name: ::%494527185fce1b5d64a82741f89ed1f4768009b7
#define HiddenValue_ClassName "%494527185fce1b5d64a82741f89ed1f4768009b7<BaseNetworkable/%17f44fcd5c74b4bc94453d09c45d68325513f07c>"
#define HiddenValue_ClassNameShort "%494527185fce1b5d64a82741f89ed1f4768009b7"
#define HiddenValue_TypeDefinitionIndex -1

	namespace HiddenValue {

		// Offsets
		constexpr const static size_t _handle = 0x18;
		constexpr const static size_t _accessCount = 0x20;
		constexpr const static size_t _hasValue = 0x10;
	}

#define SimplePrivilege___c__DisplayClass3_0_TypeDefinitionIndex 3653

	namespace SimplePrivilege___c__DisplayClass3_0 {

		// Functions
		constexpr const static size_t IsAuthed = 0x24d7920;
	}

#define ItemModRFListener_TypeDefinitionIndex 198

	namespace ItemModRFListener {

		// Functions
		constexpr const static size_t ConfigureClicked = 0x12061f0;
	}

#define UIFogOverlay_TypeDefinitionIndex 5851

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x10;
	}

	// obf name: ::%c66091d13b801583abed31c380225072184d79cc
#define BufferStream_ClassName "%c66091d13b801583abed31c380225072184d79cc"
#define BufferStream_ClassNameShort "%c66091d13b801583abed31c380225072184d79cc"
#define BufferStream_TypeDefinitionIndex 6804

	namespace BufferStream {
		constexpr const static size_t EnsureCapacity = 0x7ddb070;
	}

#define FreeableLootContainer_TypeDefinitionIndex 2227

	namespace FreeableLootContainer {

		// Offsets
	}

#define BlowPipeWeapon_TypeDefinitionIndex 2442

	namespace BlowPipeWeapon {

		// Offsets
	}

	// obf name: ::%b775e4c8a87d377f222c3c9cb1f36689a8ca037f
#define ProtoBuf_ProjectileShoot_ClassName "%b775e4c8a87d377f222c3c9cb1f36689a8ca037f"
#define ProtoBuf_ProjectileShoot_ClassNameShort "%b775e4c8a87d377f222c3c9cb1f36689a8ca037f"
#define ProtoBuf_ProjectileShoot_TypeDefinitionIndex 6774

	namespace ProtoBuf_ProjectileShoot {

		// Offsets
		constexpr const static size_t projectiles = 0x18;
	}

	// obf name: ::%5ddf3f484368e4691d46e1a2a62dc0246ed48b7a
#define ProtoBuf_ProjectileShoot_Projectile_ClassName "%b775e4c8a87d377f222c3c9cb1f36689a8ca037f/%5ddf3f484368e4691d46e1a2a62dc0246ed48b7a"
#define ProtoBuf_ProjectileShoot_Projectile_ClassNameShort "%5ddf3f484368e4691d46e1a2a62dc0246ed48b7a"
#define ProtoBuf_ProjectileShoot_Projectile_TypeDefinitionIndex 6773

	namespace ProtoBuf_ProjectileShoot_Projectile {

		// Offsets
		constexpr const static size_t projectileID = 0x14;
		constexpr const static size_t startPos = 0x2c;
		constexpr const static size_t startVel = 0x1c;
		constexpr const static size_t seed = 0x28;
	}

	// obf name: ::%545270bf0118d29248fcea1dd7f8295ebc2127aa
#define ProtoBuf_PlayerProjectileUpdate_ClassName "%545270bf0118d29248fcea1dd7f8295ebc2127aa"
#define ProtoBuf_PlayerProjectileUpdate_ClassNameShort "%545270bf0118d29248fcea1dd7f8295ebc2127aa"
#define ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex 6730

	namespace ProtoBuf_PlayerProjectileUpdate {

		// Offsets
		constexpr const static size_t projectileID = 0x14;
		constexpr const static size_t curPosition = 0x28;
		constexpr const static size_t curVelocity = 0x1c;
		constexpr const static size_t travelTime = 0x10;
		constexpr const static size_t ShouldPool = 0x19;

		// Functions
		constexpr const static size_t Dispose = 0x8bae110;
	}

	// obf name: ::%0b814b96d5d033d6d261dec98496963940f5e0fb
#define ProtoBuf_PlayerProjectileAttack_ClassName "%0b814b96d5d033d6d261dec98496963940f5e0fb"
#define ProtoBuf_PlayerProjectileAttack_ClassNameShort "%0b814b96d5d033d6d261dec98496963940f5e0fb"
#define ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex 6569

	namespace ProtoBuf_PlayerProjectileAttack {

		// Offsets
		constexpr const static size_t hitVelocity = 0x28;
		constexpr const static size_t hitDistance = 0x24;
		constexpr const static size_t travelTime = 0x10;
		constexpr const static size_t playerAttack = 0x18;
	}

	// obf name: ::%ce1b35ca8ad4b45c554bf136415c68499b41dbb4
#define ProtoBuf_PlayerAttack_ClassName "%ce1b35ca8ad4b45c554bf136415c68499b41dbb4"
#define ProtoBuf_PlayerAttack_ClassNameShort "%ce1b35ca8ad4b45c554bf136415c68499b41dbb4"
#define ProtoBuf_PlayerAttack_TypeDefinitionIndex 6656

	namespace ProtoBuf_PlayerAttack {

		// Offsets
		constexpr const static size_t projectileID = 0x10;
		constexpr const static size_t attack = 0x18;
	}

	// obf name: ::%b3f69bfc94cc2c2ae7fbaeb8516f0abde6f4148f
#define ProtoBuf_Attack_ClassName "%b3f69bfc94cc2c2ae7fbaeb8516f0abde6f4148f"
#define ProtoBuf_Attack_ClassNameShort "%b3f69bfc94cc2c2ae7fbaeb8516f0abde6f4148f"
#define ProtoBuf_Attack_TypeDefinitionIndex 6642

	namespace ProtoBuf_Attack {

		// Offsets
		constexpr const static size_t pointStart = 0x80;
		constexpr const static size_t pointEnd = 0x70;
		constexpr const static size_t hitID = 0x10;
		constexpr const static size_t hitBone = 0x7c;
		constexpr const static size_t hitNormalLocal = 0x18;
		constexpr const static size_t hitPositionLocal = 0x30;
		constexpr const static size_t hitNormalWorld = 0x60;
		constexpr const static size_t hitPositionWorld = 0x40;
		constexpr const static size_t hitPartID = 0x50;
		constexpr const static size_t hitMaterialID = 0x3c;
		constexpr const static size_t srcParentID = 0x28;
		constexpr const static size_t dstParentID = 0x58;
	}
}