#pragma once

#include <cstdint>
#include "offsets_manual.h"

namespace Offsets {
	namespace GameAssembly {
		constexpr const static size_t timestamp = 0x68690170;
		constexpr const static size_t gc_handles = 0xc2ebd80;
		constexpr const static size_t il2cpp_resolve_icall = 0x6a45a0;
		constexpr const static size_t il2cpp_array_new = 0x6a45c0;
		constexpr const static size_t il2cpp_assembly_get_image = 0x1c5440;
		constexpr const static size_t il2cpp_class_from_name = 0x6a4730;
		constexpr const static size_t il2cpp_class_get_method_from_name = 0x6a4a40;
		constexpr const static size_t il2cpp_class_get_type = 0x6a4ae0;
		constexpr const static size_t il2cpp_domain_get = 0x6a5040;
		constexpr const static size_t il2cpp_domain_get_assemblies = 0x6a5060;
		constexpr const static size_t il2cpp_gchandle_get_target = 0x6a5720;
		constexpr const static size_t il2cpp_gchandle_new = 0x6a56d0;
		constexpr const static size_t il2cpp_gchandle_free = 0x6a57c0;
		constexpr const static size_t il2cpp_method_get_name = 0x6570;
		constexpr const static size_t il2cpp_object_new = 0x6a5e80;
		constexpr const static size_t il2cpp_type_get_object = 0x6a6660;
	}

#define Object_TypeDefinitionIndex 14900

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

#define GameObject_TypeDefinitionIndex 14875

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

#define Component_TypeDefinitionIndex 14868

	namespace Component {

		// Functions
		constexpr const static size_t get_gameObject = 0xf7b70;
		constexpr const static size_t get_transform = 0xf77d0;
	}

#define Behaviour_TypeDefinitionIndex 14862

	namespace Behaviour {

		// Functions
		constexpr const static size_t set_enabled = 0xa1de0;
	}

#define Transform_TypeDefinitionIndex 14934

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

#define Camera_TypeDefinitionIndex 14682

	namespace Camera {

		// Functions
		constexpr const static size_t WorldToScreenPoint_Injected = 0x6f800;
	}

#define Time_TypeDefinitionIndex 14922

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

#define Material_TypeDefinitionIndex 14734

	namespace Material {

		// Functions
		constexpr const static size_t CreateWithMaterial = 0xaf1c0;
		constexpr const static size_t CreateWithShader = 0xaf050;
		constexpr const static size_t SetBufferImpl = 0xb7490;
	}

#define MaterialPropertyBlock_TypeDefinitionIndex 14730

	namespace MaterialPropertyBlock {

		// Functions
		constexpr const static size_t ctor = 0xa1c2180;
		constexpr const static size_t SetFloatImpl = 0x9bed0;
		constexpr const static size_t SetTextureImpl = 0x9c1c0;
	}

#define Shader_TypeDefinitionIndex 14733

	namespace Shader {

		// Functions
		constexpr const static size_t PropertyToID = 0xaa6a0;
	}

#define Mesh_TypeDefinitionIndex 14784

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

#define Texture_TypeDefinitionIndex 14787

	namespace Texture {
		constexpr const static size_t set_filterMode = 0xda5e0;
		constexpr const static size_t GetNativeTexturePtr = 0xdab00;
	}

#define Texture2D_TypeDefinitionIndex 14789

	namespace Texture2D {
		constexpr const static size_t ctor = 0xa1dad90;
		constexpr const static size_t Internal_CreateImpl = 0xdc200;
		constexpr const static size_t GetRawImageDataSize = 0xde1e0;
		constexpr const static size_t GetWritableImageData = 0xde090;
		constexpr const static size_t ApplyImpl = 0xdc5e0;
	}

#define CommandBuffer_TypeDefinitionIndex 15228

	namespace CommandBuffer {

		// Functions
		constexpr const static size_t ctor = 0xa21ce60;
		constexpr const static size_t Clear = 0x12f580;
		constexpr const static size_t ClearRenderTarget_Injected = 0x132050;
		constexpr const static size_t SetViewport_Injected = 0x131020;
		constexpr const static size_t SetViewProjectionMatrices_Injected = 0x136ef0;
		constexpr const static size_t EnableScissorRect_Injected = 0x131190;
		constexpr const static size_t DisableScissorRect = 0x131300;
		constexpr const static size_t Internal_DrawProceduralIndexedIndirect_Injected = 0x130300;
		constexpr const static size_t Internal_DrawMesh_Injected = 0x12f610;
	}

#define ComputeBuffer_TypeDefinitionIndex 14913

	namespace ComputeBuffer {

		// Functions
		constexpr const static size_t ctor = 0xa1fe5e0;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Release = 0xa1fe830;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define GraphicsBuffer_TypeDefinitionIndex 14738

	namespace GraphicsBuffer {

		// Functions
		constexpr const static size_t ctor = 0xa1cb420;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Dispose = 0xa1cb150;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define Event_TypeDefinitionIndex 19893

	namespace Event {

		// Functions
		constexpr const static size_t get_current = 0xa231c00;
		constexpr const static size_t get_type = 0x23a320;
		constexpr const static size_t PopEvent = 0x23b060;
		constexpr const static size_t Internal_Use = 0x23ac60;
	}

#define Graphics_TypeDefinitionIndex 14715

	namespace Graphics {

		// Functions
		constexpr const static size_t ExecuteCommandBuffer = 0x89bb0;
	}

#define Matrix4x4_TypeDefinitionIndex 14813

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

#define Screen_TypeDefinitionIndex 14712

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

#define Application_TypeDefinitionIndex 14665

	namespace Application {

		// Functions
		constexpr const static size_t Quit = 0x5d790;
	}

#define BaseNetworkable_TypeDefinitionIndex 5877

	namespace BaseNetworkable {

		// Offsets
		constexpr const static size_t prefabID = 0x30;
		constexpr const static size_t net = 0x48;
		constexpr const static size_t parentEntity = 0x60;
		constexpr const static size_t children = 0x50;
	}

	// obf name: ::%300e38d27de721a6644f9bd450d400404ec81948
#define BaseNetworkable_Static_ClassName "BaseNetworkable/%300e38d27de721a6644f9bd450d400404ec81948"
#define BaseNetworkable_Static_ClassNameShort "%300e38d27de721a6644f9bd450d400404ec81948"
#define BaseNetworkable_Static_TypeDefinitionIndex 5876

	namespace BaseNetworkable_Static {

		// Offsets
		constexpr const static size_t clientEntities = 0x8;
	}

	// obf name: ::%7b6e63c051c8a109569abe6afcde6ddaca3a6be2
#define BaseNetworkable_EntityRealm_ClassName "BaseNetworkable/%7b6e63c051c8a109569abe6afcde6ddaca3a6be2"
#define BaseNetworkable_EntityRealm_ClassNameShort "%7b6e63c051c8a109569abe6afcde6ddaca3a6be2"
#define BaseNetworkable_EntityRealm_TypeDefinitionIndex 5874

	namespace BaseNetworkable_EntityRealm {

		// Offsets
		constexpr const static size_t entityList = 0x10;

		// Functions
		constexpr const static size_t Find = 0x3f6d590;
	}

	// obf name: ::%cdab1f31169e5a1760e6747259094b28271c15f3
#define System_ListDictionary_ClassName "%cdab1f31169e5a1760e6747259094b28271c15f3<%91af58d8db327165ec86da6f6f9195fd3ae5606d,BaseNetworkable>"
#define System_ListDictionary_ClassNameShort "%cdab1f31169e5a1760e6747259094b28271c15f3"
#define System_ListDictionary_TypeDefinitionIndex -1

	namespace System_ListDictionary {

		// Offsets
		constexpr const static size_t vals = 0x18;

		// Functions
		constexpr const static size_t TryGetValue = 0x6fe6300;
		constexpr const static size_t TryGetValue_methodinfo = 0xc00abc0;
	}

	// obf name: ::%5da09bfcae02f93e90cbc96d6edf9ae35d980830
#define System_BufferList_ClassName "%5da09bfcae02f93e90cbc96d6edf9ae35d980830<BaseNetworkable>"
#define System_BufferList_ClassNameShort "%5da09bfcae02f93e90cbc96d6edf9ae35d980830"
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
		constexpr const static size_t Instance = 0x8;
	}

#define Model_TypeDefinitionIndex 2201

	namespace Model {

		// Offsets
		constexpr const static size_t rootBone = 0x28;
		constexpr const static size_t headBone = 0x30;
		constexpr const static size_t boneTransforms = 0x50;
	}

#define BaseEntity_TypeDefinitionIndex 4173

	namespace BaseEntity {

		// Offsets
		constexpr const static size_t bounds = 0xa0;
		constexpr const static size_t model = 0xc8;
		constexpr const static size_t flags = 0xd0;
		constexpr const static size_t triggers = 0x160;
		constexpr const static size_t positionLerp = 0x120;

		// Functions
		constexpr const static size_t ServerRPC = 0x298aa00;
		constexpr const static size_t FindBone = 0x296f9a0;
		constexpr const static size_t GetWorldVelocity = 0x29364b0;
		constexpr const static size_t GetParentVelocity = 0x29813e0;
	}

	// obf name: ::%20c4fe4274dfc0328decd8e5c62e448074b726d6
#define PositionLerp_ClassName "%20c4fe4274dfc0328decd8e5c62e448074b726d6"
#define PositionLerp_ClassNameShort "%20c4fe4274dfc0328decd8e5c62e448074b726d6"
#define PositionLerp_TypeDefinitionIndex 4607

	namespace PositionLerp {

		// Offsets
		constexpr const static size_t interpolator = 0x38;
	}

	// obf name: ::%253bcb0d84049c19ba259c114757f7667bd2c79a
#define Interpolator_ClassName "%253bcb0d84049c19ba259c114757f7667bd2c79a<%58c41fea895778d4b7162f3471036c7aec240a3c>"
#define Interpolator_ClassNameShort "%253bcb0d84049c19ba259c114757f7667bd2c79a"
#define Interpolator_TypeDefinitionIndex -1

	namespace Interpolator {
		constexpr const static size_t list = 0x30;
		constexpr const static size_t last = 0x10;
	}

#define BaseCombatEntity_TypeDefinitionIndex 3414

	namespace BaseCombatEntity {

		// Offsets
		constexpr const static size_t skeletonProperties = 0x1c0;
		constexpr const static size_t lifestate = 0x234;
		constexpr const static size_t markAttackerHostile = 0x23a;
		constexpr const static size_t _health = 0x23c;
		constexpr const static size_t _maxHealth = 0x240;
		constexpr const static size_t lastNotifyFrame = 0x24c;
	}

#define SkeletonProperties_TypeDefinitionIndex 4322

	namespace SkeletonProperties {

		// Offsets
		constexpr const static size_t bones = 0x20;
		constexpr const static size_t quickLookup = 0x28;
	}

#define SkeletonProperties_BoneProperty_TypeDefinitionIndex 4320

	namespace SkeletonProperties_BoneProperty {

		// Offsets
		constexpr const static size_t name = 0x18;
		constexpr const static size_t area = 0x20;
	}

#define ItemDefinition_TypeDefinitionIndex 1183

	namespace ItemDefinition {

		// Offsets
		constexpr const static size_t itemid = 0x20;
		constexpr const static size_t shortname = 0x28;
		constexpr const static size_t displayName = 0x38;
		constexpr const static size_t iconSprite = 0x48;
		constexpr const static size_t category = 0x50;
		constexpr const static size_t stackable = 0x68;
		constexpr const static size_t rarity = 0x80;
		constexpr const static size_t ItemModWearable = 0x168;
	}

#define RecoilProperties_TypeDefinitionIndex 4791

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

#define BaseProjectile_Magazine_TypeDefinitionIndex 4746

	namespace BaseProjectile_Magazine {

		// Offsets
		constexpr const static size_t capacity = 0x18;
		constexpr const static size_t contents = 0x1c;
		constexpr const static size_t ammoType = 0x20;
	}

#define AttackEntity_TypeDefinitionIndex 97

	namespace AttackEntity {

		// Offsets
		constexpr const static size_t deployDelay = 0x230;
		constexpr const static size_t repeatDelay = 0x234;
		constexpr const static size_t animationDelay = 0x238;
		constexpr const static size_t noHeadshots = 0x286;
		constexpr const static size_t nextAttackTime = 0x288;
		constexpr const static size_t timeSinceDeploy = 0x2a0;

		// Functions
		constexpr const static size_t SpectatorNotifyTick = 0x493db80;
		constexpr const static size_t StartAttackCooldown = 0x4943840;
	}

#define BaseProjectile_TypeDefinitionIndex 4750

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
		constexpr const static size_t LaunchProjectile = 0x2fd6470;
		constexpr const static size_t LaunchProjectileClientSide = 0x2ff9e20;
		constexpr const static size_t ScaleRepeatDelay = 0x2fd5c80;
		constexpr const static size_t GetAimCone = 0x2fcb6a0;
		constexpr const static size_t GetAimCone_vtableoff = 0x3be8;
		constexpr const static size_t UpdateAmmoDisplay = 0x2fde7a0;
		constexpr const static size_t UpdateAmmoDisplay_vtableoff = 0x3e48;
	}

#define BaseLauncher_TypeDefinitionIndex 767

	namespace BaseLauncher {

		// Offsets
	}

#define SpinUpWeapon_TypeDefinitionIndex 5472

	namespace SpinUpWeapon {

		// Offsets
	}

	// obf name: ::%e7fbcc7f4ed9a37370da8c531ee44e1e7501826b
#define HitTest_ClassName "%e7fbcc7f4ed9a37370da8c531ee44e1e7501826b"
#define HitTest_ClassNameShort "%e7fbcc7f4ed9a37370da8c531ee44e1e7501826b"
#define HitTest_TypeDefinitionIndex 2762

	namespace HitTest {

		// Offsets
		constexpr const static size_t type = 0xc8;
		constexpr const static size_t AttackRay = 0x44;
		constexpr const static size_t RayHit = 0x88;
		constexpr const static size_t damageProperties = 0x60;
		constexpr const static size_t gameObject = 0xb8;
		constexpr const static size_t collider = 0xc0;
		constexpr const static size_t ignoredTypes = 0x80;
		constexpr const static size_t HitTransform = 0x70;
		constexpr const static size_t HitPart = 0x78;
		constexpr const static size_t HitMaterial = 0x38;
		constexpr const static size_t DidHit = 0x40;
		constexpr const static size_t MaxDistance = 0x30;
		constexpr const static size_t HitPoint = 0x10;
		constexpr const static size_t HitNormal = 0x1c;
		constexpr const static size_t HitEntity = 0x28;
		constexpr const static size_t ignoreEntity = 0x68;
	}

	// obf name: ::%ee3f242871ef5f5c194dd22390aa36188c996f88
#define GameTrace_ClassName "%ee3f242871ef5f5c194dd22390aa36188c996f88"
#define GameTrace_ClassNameShort "%ee3f242871ef5f5c194dd22390aa36188c996f88"
#define GameTrace_TypeDefinitionIndex 2336

	namespace GameTrace {

		// Functions
		constexpr const static size_t Trace = 0x1843850;
	}

#define BaseMelee_TypeDefinitionIndex 5087

	namespace BaseMelee {

		// Offsets
		constexpr const static size_t damageProperties = 0x2c8;
		constexpr const static size_t maxDistance = 0x2e0;
		constexpr const static size_t attackRadius = 0x2e4;
		constexpr const static size_t blockSprintOnAttack = 0x2e9;
		constexpr const static size_t gathering = 0x318;
		constexpr const static size_t canThrowAsProjectile = 0x321;

		// Functions
		constexpr const static size_t ProcessAttack = 0x34dfde0;
		constexpr const static size_t DoThrow = 0x34e3720;
	}

#define FlintStrikeWeapon_TypeDefinitionIndex 557

	namespace FlintStrikeWeapon {

		// Offsets
		constexpr const static size_t successFraction = 0x3f0;
		constexpr const static size_t strikeRecoil = 0x3f8;
		constexpr const static size_t _didSparkThisFrame = 0x400;
	}

#define CompoundBowWeapon_TypeDefinitionIndex 2420

	namespace CompoundBowWeapon {

		// Offsets
		constexpr const static size_t stringHoldDurationMax = 0x408;
		constexpr const static size_t stringBonusVelocity = 0x414;

		// Functions
		constexpr const static size_t GetStringBonusScale = 0x19221b0;
	}

	// obf name: ::%6529fbdabdf0f33533ca87a6eb9436f7031729b8
#define ItemContainer_ClassName "%6529fbdabdf0f33533ca87a6eb9436f7031729b8"
#define ItemContainer_ClassNameShort "%6529fbdabdf0f33533ca87a6eb9436f7031729b8"
#define ItemContainer_TypeDefinitionIndex 6277

	namespace ItemContainer {

		// Offsets
		constexpr const static size_t uid = 0x28;
		constexpr const static size_t itemList = 0x50;

		// Functions
		constexpr const static size_t FindItemsByItemID = 0x433afb0;
		constexpr const static size_t GetSlot = 0x4346c70;
	}

#define PlayerLoot_TypeDefinitionIndex 5135

	namespace PlayerLoot {

		// Offsets
		constexpr const static size_t containers = 0x38;
	}

#define PlayerInventory_TypeDefinitionIndex 1115

	namespace PlayerInventory {

		// Offsets
		constexpr const static size_t containerBelt = 0x28;
		constexpr const static size_t containerWear = 0x58;
		constexpr const static size_t containerMain = 0x78;
		constexpr const static size_t loot = 0x48;

		// Functions
		constexpr const static size_t Initialize = 0x4b8b2d0;
		constexpr const static size_t FindItemsByItemID = 0x4b946f0;
	}

#define PlayerEyes_TypeDefinitionIndex 5365

	namespace PlayerEyes {

		// Offsets
		constexpr const static size_t viewOffset = 0x40;
		constexpr const static size_t bodyRotation = 0x50;

		// Functions
		constexpr const static size_t get_position = 0x3822b70;
		constexpr const static size_t get_rotation = 0x38219d0;
		constexpr const static size_t set_rotation = 0x3805bf0;
		constexpr const static size_t HeadForward = 0x382c3b0;
	}

	// obf name: ::%c2694519889aeaff19c1c7a8c16070fea9ff6f40
#define PlayerEyes_Static_ClassName "PlayerEyes/%c2694519889aeaff19c1c7a8c16070fea9ff6f40"
#define PlayerEyes_Static_ClassNameShort "%c2694519889aeaff19c1c7a8c16070fea9ff6f40"
#define PlayerEyes_Static_TypeDefinitionIndex 5364

	namespace PlayerEyes_Static {

		// Offsets
		constexpr const static size_t EyeOffset = 0x74;
	}

	// obf name: ::%6bb72ddff6500d67cb32e9daee17f47999358fa5
#define PlayerBelt_ClassName "%6bb72ddff6500d67cb32e9daee17f47999358fa5"
#define PlayerBelt_ClassNameShort "%6bb72ddff6500d67cb32e9daee17f47999358fa5"
#define PlayerBelt_TypeDefinitionIndex 729

	namespace PlayerBelt {

		// Functions
		constexpr const static size_t ChangeSelect = 0x477ec90;
		constexpr const static size_t GetActiveItem = 0x4781370;
	}

	// obf name: ::%4c1192af3be6954e19a1e6d022414959372595f6
#define LocalPlayer_ClassName "%4c1192af3be6954e19a1e6d022414959372595f6"
#define LocalPlayer_ClassNameShort "%4c1192af3be6954e19a1e6d022414959372595f6"
#define LocalPlayer_TypeDefinitionIndex 1728

	namespace LocalPlayer {

		// Functions
		constexpr const static size_t ItemCommand = 0x10a6ac0;
		constexpr const static size_t MoveItem = 0x10af1c0;
		constexpr const static size_t get_Entity = 0x10a1b30;
	}

	// obf name: ::%290bb8b705015bf9bc36b931faad0f4a11b43d52
#define LocalPlayer_Static_ClassName "%4c1192af3be6954e19a1e6d022414959372595f6/%290bb8b705015bf9bc36b931faad0f4a11b43d52"
#define LocalPlayer_Static_ClassNameShort "%290bb8b705015bf9bc36b931faad0f4a11b43d52"
#define LocalPlayer_Static_TypeDefinitionIndex 1727

	namespace LocalPlayer_Static {

		// Offsets
		constexpr const static size_t Entity = 0x230;
	}

	// obf name: ::%a5961a17023d7b5d3a99391bcc4ff66b05a0d6e8
#define BasePlayer_Static_ClassName "BasePlayer/%a5961a17023d7b5d3a99391bcc4ff66b05a0d6e8"
#define BasePlayer_Static_ClassNameShort "%a5961a17023d7b5d3a99391bcc4ff66b05a0d6e8"
#define BasePlayer_Static_TypeDefinitionIndex 5490

	namespace BasePlayer_Static {

		// Offsets
		constexpr const static size_t visiblePlayerList = 0x320;
	}

#define BasePlayer_TypeDefinitionIndex 5491

	namespace BasePlayer {

		// Offsets
		constexpr const static size_t playerModel = 0x528;
		constexpr const static size_t input = 0x330;
		constexpr const static size_t movement = 0x340;
		constexpr const static size_t currentTeam = 0x430;
		constexpr const static size_t clActiveItem = 0x460;
		constexpr const static size_t modelState = 0x2b8;
		constexpr const static size_t playerFlags = 0x558;
		constexpr const static size_t eyes = 0x580;
		constexpr const static size_t playerRigidbody = 0x2c8;
		constexpr const static size_t userID = 0x5a0;
		constexpr const static size_t UserIDString = 0x418;
		constexpr const static size_t inventory = 0x650;
		constexpr const static size_t _displayName = 0x498;
		constexpr const static size_t _lookingAt = 0x4f8;
		constexpr const static size_t lastSentTickTime = 0x514;
		constexpr const static size_t lastSentTick = 0x288;
		constexpr const static size_t mounted = 0x4a0;
		constexpr const static size_t Belt = 0x300;
		constexpr const static size_t _lookingAtEntity = 0x2d0;
		constexpr const static size_t currentGesture = 0x280;
		constexpr const static size_t weaponMoveSpeedScale = 0x630;
		constexpr const static size_t clothingBlocksAiming = 0x634;
		constexpr const static size_t clothingMoveSpeedReduction = 0x638;
		constexpr const static size_t clothingWaterSpeedBonus = 0x63c;
		constexpr const static size_t equippingBlocked = 0x644;

		// Functions
		constexpr const static size_t ClientUpdateLocalPlayer = 0x394ab20;
		constexpr const static size_t Menu_AssistPlayer = 0x3a4bf90;
		constexpr const static size_t OnViewModeChanged = 0x3a357f0;
		constexpr const static size_t ChatMessage = 0x3a1d350;
		constexpr const static size_t IsOnGround = 0x392bed0;
		constexpr const static size_t GetSpeed = 0x39a75b0;
		constexpr const static size_t SendProjectileUpdate = 0x3a71310;
		constexpr const static size_t SendProjectileAttack = 0x3a1f7a0;
		constexpr const static size_t CanBuild = 0x3a4fc30;
		constexpr const static size_t GetMounted = 0x39a8880;
		constexpr const static size_t GetHeldEntity = 0x3997630;
		constexpr const static size_t get_inventory = 0x3a512f0;
		constexpr const static size_t get_eyes = 0x3abfa70;
		constexpr const static size_t SendClientTick = 0x3a7e4a0;
		constexpr const static size_t ClientInput = 0x399a8b0;
		constexpr const static size_t ClientInput_vtableoff = 0x38f8;
		constexpr const static size_t MaxHealth = 0x39ac7b0;
		constexpr const static size_t MaxHealth_vtableoff = 0x1d08;
	}

#define ScientistNPC_TypeDefinitionIndex 1048

	namespace ScientistNPC {

		// Offsets
	}

#define TunnelDweller_TypeDefinitionIndex 1678

	namespace TunnelDweller {

		// Offsets
	}

#define UnderwaterDweller_TypeDefinitionIndex 2541

	namespace UnderwaterDweller {

		// Offsets
	}

#define ScarecrowNPC_TypeDefinitionIndex 4540

	namespace ScarecrowNPC {

		// Offsets
	}

#define GingerbreadNPC_TypeDefinitionIndex 429

	namespace GingerbreadNPC {

		// Offsets
	}

#define BaseMovement_TypeDefinitionIndex 2428

	namespace BaseMovement {

		// Offsets
		constexpr const static size_t adminCheat = 0x20;
		constexpr const static size_t Owner = 0x28;
	}

#define PlayerWalkMovement_TypeDefinitionIndex 298

	namespace PlayerWalkMovement {

		// Offsets
		constexpr const static size_t capsule = 0xd8;
		constexpr const static size_t ladder = 0xe8;
		constexpr const static size_t modify = 0x1b8;

		// Functions
		constexpr const static size_t BlockJump = 0x1ba5550;
		constexpr const static size_t BlockSprint = 0x1b93ae0;
		constexpr const static size_t GroundCheck = 0x1bd1cb0;
		constexpr const static size_t ClientInput = 0x1bbf450;
		constexpr const static size_t ClientInput_vtableoff = 0x228;
		constexpr const static size_t DoFixedUpdate = 0x1ba6350;
		constexpr const static size_t DoFixedUpdate_vtableoff = 0x2b8;
		constexpr const static size_t FrameUpdate = 0x1bb78b0;
		constexpr const static size_t FrameUpdate_vtableoff = 0x1a8;
	}

#define BuildingPrivlidge_TypeDefinitionIndex 3081

	namespace BuildingPrivlidge {

		// Offsets
		constexpr const static size_t allowedConstructionItems = 0x360;
		constexpr const static size_t cachedProtectedMinutes = 0x368;
	}

#define WorldItem_TypeDefinitionIndex 923

	namespace WorldItem {

		// Offsets
		constexpr const static size_t allowPickup = 0x1a0;
		constexpr const static size_t item = 0x1a8;
	}

#define HackableLockedCrate_TypeDefinitionIndex 379

	namespace HackableLockedCrate {

		// Offsets
		constexpr const static size_t timerText = 0x378;
		constexpr const static size_t hackSeconds = 0x388;
	}

#define ProjectileWeaponMod_TypeDefinitionIndex 2228

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

#define ProjectileWeaponMod_Modifier_TypeDefinitionIndex 2225

	namespace ProjectileWeaponMod_Modifier {
		constexpr const static size_t enabled = 0x0;
		constexpr const static size_t scalar = 0x4;
		constexpr const static size_t offset = 0x8;
	}

	// obf name: ::%5df6fc9397f533a6e799081fc9b4f6772bfa81e8
#define ConsoleSystem_ClassName "%5df6fc9397f533a6e799081fc9b4f6772bfa81e8"
#define ConsoleSystem_ClassNameShort "%5df6fc9397f533a6e799081fc9b4f6772bfa81e8"
#define ConsoleSystem_TypeDefinitionIndex 20575

	namespace ConsoleSystem {

		// Functions
		constexpr const static size_t Run = 0x5d77ae0;
	}

#define ConsoleSystem_Option_ClassName "%5df6fc9397f533a6e799081fc9b4f6772bfa81e8/%aa2992b94e4d72e2a2e36dde63362a2b527b2780"
#define ConsoleSystem_Option_ClassNameShort "%aa2992b94e4d72e2a2e36dde63362a2b527b2780"
#define ConsoleSystem_Command_ClassName "%5df6fc9397f533a6e799081fc9b4f6772bfa81e8/%ca7ad4aa874b0385d979a842e7a1904118d14c17"
#define ConsoleSystem_Command_ClassNameShort "%ca7ad4aa874b0385d979a842e7a1904118d14c17"
	// obf name: ::%6d55de1085dfafeddc87e245e7019102da1ea4ba
#define ConsoleSystem_Index_Static_ClassName "%5df6fc9397f533a6e799081fc9b4f6772bfa81e8/%169c0943f2d92bbdabb1a5e0e8ee8c7d82243758.%6d55de1085dfafeddc87e245e7019102da1ea4ba"
#define ConsoleSystem_Index_Static_ClassNameShort "%6d55de1085dfafeddc87e245e7019102da1ea4ba"
#define ConsoleSystem_Index_Static_TypeDefinitionIndex 20570

	namespace ConsoleSystem_Index_Static {

		// Offsets
		constexpr const static size_t All = 0x20;
	}

	// obf name: ::%2c90725ec6565d60c9299cd8496dea8581831af8
#define ConsoleSystem_Arg_ClassName "%5df6fc9397f533a6e799081fc9b4f6772bfa81e8/%2c90725ec6565d60c9299cd8496dea8581831af8"
#define ConsoleSystem_Arg_ClassNameShort "%2c90725ec6565d60c9299cd8496dea8581831af8"
// obf name: ::%c84ca124d8748cc68b5349d446cfbbddd05dd981
#define Facepunch_Network_SteamNetworking_ClassName "%c84ca124d8748cc68b5349d446cfbbddd05dd981"
#define Facepunch_Network_SteamNetworking_ClassNameShort "%c84ca124d8748cc68b5349d446cfbbddd05dd981"
#define LootableCorpse_TypeDefinitionIndex 3644

	namespace LootableCorpse {

		// Offsets
		constexpr const static size_t playerSteamID = 0x298;
		constexpr const static size_t _playerName = 0x2a8;
	}

#define DroppedItemContainer_TypeDefinitionIndex 1025

	namespace DroppedItemContainer {

		// Offsets
		constexpr const static size_t playerSteamID = 0x268;
		constexpr const static size_t _playerName = 0x250;
	}

#define MainCamera_TypeDefinitionIndex 829

	namespace MainCamera {

		// Offsets 
		constexpr const static size_t mainCamera = 0x38;
		constexpr const static size_t mainCameraTransform = 0x10;

		// Functions
		constexpr const static size_t Update = 0x489d930;
		constexpr const static size_t Trace = 0x48a0320;
	}

#define CameraMan_TypeDefinitionIndex 3970

	namespace CameraMan {

		// Offsets
	}

	// obf name: ::%8f6efa35c8ee9f96ac5fa2606d35012878c10572
#define PlayerTick_ClassName "%8f6efa35c8ee9f96ac5fa2606d35012878c10572"
#define PlayerTick_ClassNameShort "%8f6efa35c8ee9f96ac5fa2606d35012878c10572"
#define PlayerTick_TypeDefinitionIndex 6732

	namespace PlayerTick {

		// Offsets
		constexpr const static size_t inputState = 0x20;
		constexpr const static size_t modelState = 0x50;
		constexpr const static size_t activeItem = 0x38;
		constexpr const static size_t parentID = 0x10;
		constexpr const static size_t position = 0x28;
		constexpr const static size_t eyePos = 0x40;
	}

	// obf name: ::%535175f6e9f8f011f219cb8fd2e4ea9290120077
#define InputMessage_ClassName "%535175f6e9f8f011f219cb8fd2e4ea9290120077"
#define InputMessage_ClassNameShort "%535175f6e9f8f011f219cb8fd2e4ea9290120077"
#define InputMessage_TypeDefinitionIndex 6766

	namespace InputMessage {

		// Offsets
		constexpr const static size_t buttons = 0x2c;
		constexpr const static size_t mouseDelta = 0x10;
		constexpr const static size_t aimAngles = 0x20;
	}

	// obf name: ::%9f90b9251f1a680224e9a70c63354e164218f55f
#define InputState_ClassName "%9f90b9251f1a680224e9a70c63354e164218f55f"
#define InputState_ClassNameShort "%9f90b9251f1a680224e9a70c63354e164218f55f"
#define InputState_TypeDefinitionIndex 5657

	namespace InputState {

		// Offsets
		constexpr const static size_t current = 0x10;
		constexpr const static size_t previous = 0x20;
	}

#define PlayerInput_TypeDefinitionIndex 1654

	namespace PlayerInput {

		// Offsets
		constexpr const static size_t state = 0x28;
		constexpr const static size_t bodyAngles = 0x44;
	}

	// obf name: ::%6c4c7c5b6b041cac1748b585c0a7e4df62942f14
#define ModelState_ClassName "%6c4c7c5b6b041cac1748b585c0a7e4df62942f14"
#define ModelState_ClassNameShort "%6c4c7c5b6b041cac1748b585c0a7e4df62942f14"
#define ModelState_TypeDefinitionIndex 6696

	namespace ModelState {

		// Offsets
		constexpr const static size_t flags = 0x50;
		constexpr const static size_t waterLevel = 0x3c;
		constexpr const static size_t lookDir = 0x54;
	}

	// obf name: ::%26c17b8afa8b063b4bd55d7415a77891c866b920
#define Item_ClassName "%26c17b8afa8b063b4bd55d7415a77891c866b920"
#define Item_ClassNameShort "%26c17b8afa8b063b4bd55d7415a77891c866b920"
#define Item_TypeDefinitionIndex 1959

	namespace Item {

		// Offsets
		constexpr const static size_t info = 0x88;
		constexpr const static size_t uid = 0x28;
		constexpr const static size_t _maxCondition = 0x24;
		constexpr const static size_t _condition = 0x48;
		constexpr const static size_t position = 0x20;
		constexpr const static size_t amount = 0xc0;
		constexpr const static size_t parent = 0x98;
		constexpr const static size_t contents = 0xc8;
		constexpr const static size_t heldEntity = 0x68;
		constexpr const static size_t worldEnt = 0x78;

		// Functions
		constexpr const static size_t get_iconSprite = 0x138a600;
	}

	// obf name: ::%6e776d41ae6ca282dc20c2d234bdf3225f9f683b
#define WaterLevel_ClassName "%6e776d41ae6ca282dc20c2d234bdf3225f9f683b"
#define WaterLevel_ClassNameShort "%6e776d41ae6ca282dc20c2d234bdf3225f9f683b"
#define WaterLevel_TypeDefinitionIndex 3373

	namespace WaterLevel {

		// Functions
		constexpr const static size_t Test = 0x22282b0;
		constexpr const static size_t GetWaterLevel = 0x22273f0;
	}

	// obf name: ::%1e5fa42972ed919632a022151b02a3d7a336b5e7
#define ConVar_Graphics_Static_ClassName "%35b12e39f88eafe30dbd2c58b7bd98a7185295e5/%1e5fa42972ed919632a022151b02a3d7a336b5e7"
#define ConVar_Graphics_Static_ClassNameShort "%1e5fa42972ed919632a022151b02a3d7a336b5e7"
#define ConVar_Graphics_Static_TypeDefinitionIndex 1278

	namespace ConVar_Graphics_Static {

		// Offsets
		constexpr const static size_t _fov = 0x484;

		// Functions
		constexpr const static size_t _fov_getter = 0x320c9f0;
		constexpr const static size_t _fov_setter = 0x320d4a0;
	}

#define BaseFishingRod_TypeDefinitionIndex 5532

	namespace BaseFishingRod {

		// Offsets
		constexpr const static size_t CurrentState = 0x250;
		constexpr const static size_t currentBobber = 0x258;
		constexpr const static size_t MaxCastDistance = 0x274;
		constexpr const static size_t BobberPreview = 0x280;
		constexpr const static size_t clientStrainAmountNormalised = 0x2c0;
		constexpr const static size_t strainGainMod = 0x2e8;
		constexpr const static size_t aimAnimationReady = 0x2d8;

		// Functions
		constexpr const static size_t UpdateLineRenderer = 0x3b4bb30;
		constexpr const static size_t EvaluateFishingPosition = 0x3b553f0;
	}

#define FishingBobber_TypeDefinitionIndex 5665

	namespace FishingBobber {

		// Offsets
		constexpr const static size_t bobberRoot = 0x268;
	}

#define GameManifest_TypeDefinitionIndex 1359

	namespace GameManifest {

		// Functions
		constexpr const static size_t GUIDToObject = 0x4e8a300;
	}

	// obf name: ::%fcf0da737aa80cd73ee51646bf8e1bd5b14ed26f
#define GameManager_ClassName "%fcf0da737aa80cd73ee51646bf8e1bd5b14ed26f"
#define GameManager_ClassNameShort "%fcf0da737aa80cd73ee51646bf8e1bd5b14ed26f"
#define GameManager_TypeDefinitionIndex 4508

	namespace GameManager {

		// Offsets
		constexpr const static size_t pool = 0x18;

		// Functions
		constexpr const static size_t CreatePrefab = 0x2d30ee0;
	}

	// obf name: ::%f014b0c2985d4b6c4ccf0b01aaa2a3aa2efe9853
#define GameManager_Static_ClassName "%fcf0da737aa80cd73ee51646bf8e1bd5b14ed26f/%f014b0c2985d4b6c4ccf0b01aaa2a3aa2efe9853"
#define GameManager_Static_ClassNameShort "%f014b0c2985d4b6c4ccf0b01aaa2a3aa2efe9853"
#define GameManager_Static_TypeDefinitionIndex 4507

	namespace GameManager_Static {

		// Offsets
		constexpr const static size_t client = 0x28;
	}

	// obf name: ::%fbb849fb14f2bebac71abe8dfcd9fe2283af2460
#define PrefabPoolCollection_ClassName "%fbb849fb14f2bebac71abe8dfcd9fe2283af2460"
#define PrefabPoolCollection_ClassNameShort "%fbb849fb14f2bebac71abe8dfcd9fe2283af2460"
#define PrefabPoolCollection_TypeDefinitionIndex 2223

	namespace PrefabPoolCollection {

		// Offsets
		constexpr const static size_t storage = 0x10;
	}

	// obf name: ::%644a23235e51f4a53a83d62137eebd4d6e96e315
#define PrefabPool_ClassName "%644a23235e51f4a53a83d62137eebd4d6e96e315"
#define PrefabPool_ClassNameShort "%644a23235e51f4a53a83d62137eebd4d6e96e315"
#define PrefabPool_TypeDefinitionIndex 2719

	namespace PrefabPool {

		// Offsets
		constexpr const static size_t stack = 0x10;
	}

#define ItemModProjectile_TypeDefinitionIndex 5308

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

#define Projectile_TypeDefinitionIndex 461

	namespace Projectile {

		// Offsets
		constexpr const static size_t initialVelocity = 0x20;
		constexpr const static size_t drag = 0x2c;
		constexpr const static size_t gravityModifier = 0x30;
		constexpr const static size_t thickness = 0x34;
		constexpr const static size_t initialDistance = 0x3c;
		constexpr const static size_t swimScale = 0xe8;
		constexpr const static size_t swimSpeed = 0xf4;
		constexpr const static size_t owner = 0x110;
		constexpr const static size_t sourceProjectilePrefab = 0x1d8;
		constexpr const static size_t mod = 0x100;
		constexpr const static size_t hitTest = 0x1c8;
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
		constexpr const static size_t CalculateEffectScale = 0x2dcb3e0;
		constexpr const static size_t CalculateEffectScale_vtableoff = 0x3a8;
		constexpr const static size_t SetEffectScale = 0x2dc1f80;
		constexpr const static size_t UpdateVelocity = 0x2daf9e0;
		constexpr const static size_t Retire = 0x2dbfbb0;
		constexpr const static size_t DoHit = 0x2dca700;
	}

#define CraftingQueue_TypeDefinitionIndex 1513

	namespace CraftingQueue {

		// Offsets
		constexpr const static size_t icons = 0x30;
	}

	// obf name: ::%890ab21ffda31348746fe06001ff88dabe25b073
#define CraftingQueue_Static_ClassName "CraftingQueue/%890ab21ffda31348746fe06001ff88dabe25b073"
#define CraftingQueue_Static_ClassNameShort "%890ab21ffda31348746fe06001ff88dabe25b073"
#define CraftingQueue_Static_TypeDefinitionIndex 1512

	namespace CraftingQueue_Static {

		// Offsets
		constexpr const static size_t isCrafting = 0x41;
	}

#define CraftingQueueIcon_TypeDefinitionIndex 824

	namespace CraftingQueueIcon {

		// Offsets
		constexpr const static size_t endTime = 0x4c;
		constexpr const static size_t item = 0x60;
	}

	// obf name: ::%3b892b5dba9367d69802ab6ddbf75c0dc17e3091
#define Planner_Static_ClassName "Planner/%3b892b5dba9367d69802ab6ddbf75c0dc17e3091"
#define Planner_Static_ClassNameShort "%3b892b5dba9367d69802ab6ddbf75c0dc17e3091"
#define Planner_Static_TypeDefinitionIndex 17

	namespace Planner_Static {

		// Offsets
		constexpr const static size_t guide = 0xb0;
	}

	// obf name: ::%8a9914bcf19d8b1bbc63234841e438f84088f50e
#define Planner_Guide_ClassName "Planner/%8a9914bcf19d8b1bbc63234841e438f84088f50e"
#define Planner_Guide_ClassNameShort "%8a9914bcf19d8b1bbc63234841e438f84088f50e"
#define Planner_Guide_TypeDefinitionIndex 13

	namespace Planner_Guide {

		// Offsets
		constexpr const static size_t lastPlacement = 0x58;
	}

#define Planner_TypeDefinitionIndex 18

	namespace Planner {

		// Offsets
		constexpr const static size_t _currentConstruction = 0x260;
	}

#define Construction_TypeDefinitionIndex 1240

	namespace Construction {

		// Offsets
		constexpr const static size_t holdToPlaceDuration = 0xfc;
		constexpr const static size_t grades = 0x140;
	}

#define BuildingBlock_TypeDefinitionIndex 1908

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t blockDefinition = 0x2e0;
	}

	// obf name: ::HeldEntity
#define HeldEntity_ClassName "HeldEntity"
#define HeldEntity_ClassNameShort "HeldEntity"
#define HeldEntity_TypeDefinitionIndex 987

	namespace HeldEntity {

		// Offsets
		constexpr const static size_t ownerItemUID = 0x210;
		constexpr const static size_t _punches = 0x1c0;
		constexpr const static size_t viewModel = 0x218;

		// Functions
		constexpr const static size_t OnDeploy = 0x4a26890;
	}

	// obf name: ::%dcb309ee8c4cf38844b91133777819b957254481
#define PunchEntry_ClassName "HeldEntity/%dcb309ee8c4cf38844b91133777819b957254481"
#define PunchEntry_ClassNameShort "%dcb309ee8c4cf38844b91133777819b957254481"
#define PunchEntry_TypeDefinitionIndex 985

	namespace PunchEntry {

		// Offsets
		constexpr const static size_t duration = 0x28;
		constexpr const static size_t startTime = 0x2c;
		constexpr const static size_t amountAdded = 0x10;
		constexpr const static size_t amount = 0x1c;
	}

#define IronSights_TypeDefinitionIndex 71

	namespace IronSights {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t ironsightsOverride = 0x68;
	}

#define IronSightOverride_TypeDefinitionIndex 6337

	namespace IronSightOverride {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t fovBias = 0x30;
	}

#define BaseViewModel_TypeDefinitionIndex 2282

	namespace BaseViewModel {

		// Offsets
		constexpr const static size_t useViewModelCamera = 0x40;
		constexpr const static size_t ironSights = 0xc8;
		constexpr const static size_t model = 0x90;
		constexpr const static size_t lower = 0xc0;

		// Functions
		constexpr const static size_t get_ActiveModel = 0x17e5d60;
	}

#define ViewModel_TypeDefinitionIndex 2760

	namespace ViewModel {

		// Offsets
		constexpr const static size_t instance = 0x28;

		// Functions
		constexpr const static size_t PlayInt = 0x1c27160;
		constexpr const static size_t PlayString = 0x1c29c10;
	}

#define MedicalTool_TypeDefinitionIndex 2197

	namespace MedicalTool {

		// Offsets
		constexpr const static size_t resetTime = 0x2e8;
	}

#define WaterBody_TypeDefinitionIndex 1703

	namespace WaterBody {

		// Offsets
		constexpr const static size_t meshFilter = 0x60;
	}

	// obf name: ::%13c584414e9dd97d88d20d53d52c940664b87b96
#define WaterSystem_Static_ClassName "WaterSystem/%13c584414e9dd97d88d20d53d52c940664b87b96"
#define WaterSystem_Static_ClassNameShort "%13c584414e9dd97d88d20d53d52c940664b87b96"
#define WaterSystem_Static_TypeDefinitionIndex 5201

	namespace WaterSystem_Static {

		// Offsets
		constexpr const static size_t Ocean = 0x250;
	}

#define WaterSystem_TypeDefinitionIndex 5202

	namespace WaterSystem {

		// Functions
		constexpr const static size_t get_Ocean = 0x35bd890;
	}

#define TerrainMeta_TypeDefinitionIndex 2046

	namespace TerrainMeta {

		// Offsets
		constexpr const static size_t Position = 0x18;
		constexpr const static size_t Size = 0x24;
		constexpr const static size_t OneOverSize = 0x30;
		constexpr const static size_t Collision = 0x730;
		constexpr const static size_t HeightMap = 0x5c0;
		constexpr const static size_t SplatMap = 0x468;
		constexpr const static size_t TopologyMap = 0x5e8;
		constexpr const static size_t Texturing = 0x5f0;
	}

#define TerrainCollision_TypeDefinitionIndex 8

	namespace TerrainCollision {

		// Functions
		constexpr const static size_t GetIgnore = 0xD7FA00;
	}

#define TerrainHeightMap_TypeDefinitionIndex 4436

	namespace TerrainHeightMap {

		// Offsets
		constexpr const static size_t normY = 0x70;
	}

#define TerrainSplatMap_TypeDefinitionIndex 5563

	namespace TerrainSplatMap {

		// Offsets
		constexpr const static size_t num = 0x70;
	}

#define TerrainTexturing_TypeDefinitionIndex 2974

	namespace TerrainTexturing {

		// Offsets
		constexpr const static size_t shoreMapSize = 0x8c;
		constexpr const static size_t terrainSize = 0x88;
		constexpr const static size_t shoreDistanceScale = 0x90;
		constexpr const static size_t shoreVectors = 0xa8;
	}

	// obf name: ::%58f4f7bfcf54a86d88d37568cc95d5d39c288439
#define World_Static_ClassName "%b8248c31755e0609b86b74ab9dec94b5e6e013a1/%58f4f7bfcf54a86d88d37568cc95d5d39c288439"
#define World_Static_ClassNameShort "%58f4f7bfcf54a86d88d37568cc95d5d39c288439"
#define World_Static_TypeDefinitionIndex 4818

	namespace World_Static {

		// Offsets
		constexpr const static size_t _size = 0x138;
	}

#define ItemIcon_TypeDefinitionIndex 6594

	namespace ItemIcon {

		// Functions
		constexpr const static size_t SetTimedLootAction = 0x468d4e0;
	}

	// obf name: ::%0dde20fa2ce3a2f02e17883eb6f21b95666dcc48
#define ItemIcon_Static_ClassName "ItemIcon/%0dde20fa2ce3a2f02e17883eb6f21b95666dcc48"
#define ItemIcon_Static_ClassNameShort "%0dde20fa2ce3a2f02e17883eb6f21b95666dcc48"
#define ItemIcon_Static_TypeDefinitionIndex 6593

	namespace ItemIcon_Static {

		// Offsets
		constexpr const static size_t containerLootStartTimes = 0x28;
	}

	// obf name: ::%c9715ac3d87bfbd764e2d67ab68ac8e4da7c4677
#define Effect_ClassName "%c9715ac3d87bfbd764e2d67ab68ac8e4da7c4677"
#define Effect_ClassNameShort "%c9715ac3d87bfbd764e2d67ab68ac8e4da7c4677"
#define Effect_TypeDefinitionIndex 3890

	namespace Effect {

		// Offsets
		constexpr const static size_t pooledString = 0xa0;
		constexpr const static size_t worldPos = 0x7c;
	}

	// obf name: ::%1419d413f4ab7329a95c143e684bf86e6d4e68b5
#define EffectNetwork_ClassName "%1419d413f4ab7329a95c143e684bf86e6d4e68b5"
#define EffectNetwork_ClassNameShort "%1419d413f4ab7329a95c143e684bf86e6d4e68b5"
#define EffectNetwork_TypeDefinitionIndex 857

	namespace EffectNetwork {

		// Functions
	}

	// obf name: ::%3f5c52ab3e7295fd9b0132337f02d871eaf10932
#define EffectNetwork_Static_ClassName "%1419d413f4ab7329a95c143e684bf86e6d4e68b5/%3f5c52ab3e7295fd9b0132337f02d871eaf10932"
#define EffectNetwork_Static_ClassNameShort "%3f5c52ab3e7295fd9b0132337f02d871eaf10932"
#define EffectNetwork_Static_TypeDefinitionIndex 856

	namespace EffectNetwork_Static {

		// Offsets
		constexpr const static size_t effect = 0x28;

		// Functions
		constexpr const static size_t cctor = 0x48e9170;
	}

#define BuildingBlock_TypeDefinitionIndex 1908

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t grade = 0x2d8;

		// Functions
		constexpr const static size_t GetBuildMenu = 0x12f89d0;
		constexpr const static size_t HasUpgradePrivilege = 0x12e9bf0;
		constexpr const static size_t CanAffordUpgrade = 0x130c430;
	}

	// obf name: ::%65942591a9fb72d0c52af577d0a0c6636f548bb3
#define GameObjectEx_ClassName "%65942591a9fb72d0c52af577d0a0c6636f548bb3"
#define GameObjectEx_ClassNameShort "%65942591a9fb72d0c52af577d0a0c6636f548bb3"
#define GameObjectEx_TypeDefinitionIndex 2010

	namespace GameObjectEx {

		// Functions
		constexpr const static size_t ToBaseEntity = 0x1429670;
	}

#define UIDeathScreen_TypeDefinitionIndex 692

	namespace UIDeathScreen {

		// Functions
		constexpr const static size_t SetVisible = 0x4701280;
	}

	// obf name: ::%9ef4a41d0fa88997d582a5e0c6c02233a854586c
#define BaseScreenShake_Static_ClassName "BaseScreenShake/%9ef4a41d0fa88997d582a5e0c6c02233a854586c"
#define BaseScreenShake_Static_ClassNameShort "%9ef4a41d0fa88997d582a5e0c6c02233a854586c"
#define BaseScreenShake_Static_TypeDefinitionIndex 6302

	namespace BaseScreenShake_Static {

		// Offsets
		constexpr const static size_t list = 0x50;
	}

#define FlashbangOverlay_TypeDefinitionIndex 6495

	namespace FlashbangOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x20;
		constexpr const static size_t flashLength = 0x48;
	}

	// obf name: ::%bf47b2ce353a6d7223f14378bf1a14294568efb4
#define StringPool_ClassName "%bf47b2ce353a6d7223f14378bf1a14294568efb4"
#define StringPool_ClassNameShort "%bf47b2ce353a6d7223f14378bf1a14294568efb4"
#define StringPool_TypeDefinitionIndex 1086

	namespace StringPool {

		// Offsets
		constexpr const static size_t toNumber = 0x60;

		// Functions
		constexpr const static size_t Get = 0x4b09950;
	}

	// obf name: ::%ce3027003577f8b7264d4d9d968a3dfea3755289
#define Network_Networkable_ClassName "%ce3027003577f8b7264d4d9d968a3dfea3755289"
#define Network_Networkable_ClassNameShort "%ce3027003577f8b7264d4d9d968a3dfea3755289"
#define Network_Networkable_TypeDefinitionIndex 16820

	namespace Network_Networkable {

		// Offsets
		constexpr const static size_t ID = 0x20;
	}

	// obf name: ::%f2c83ed3a652308a609aa84c372f1124108dd6f2
#define Network_Net_ClassName "%f2c83ed3a652308a609aa84c372f1124108dd6f2"
#define Network_Net_ClassNameShort "%f2c83ed3a652308a609aa84c372f1124108dd6f2"
#define Network_Net_TypeDefinitionIndex 7997

	namespace Network_Net {

		// Offsets
		constexpr const static size_t cl = 0x10;
	}

	// obf name: ::%7eb36d75b55de6ecea413734aa47dbeb200407c7
#define Network_Client_ClassName "%7eb36d75b55de6ecea413734aa47dbeb200407c7"
#define Network_Client_ClassNameShort "%7eb36d75b55de6ecea413734aa47dbeb200407c7"
#define Network_Client_TypeDefinitionIndex 16790

	namespace Network_Client {

		// Offsets
		constexpr const static size_t Connection = 0xf0;
		constexpr const static size_t ConnectedPort = 0xe8;
		constexpr const static size_t ServerName = 0x108;
		constexpr const static size_t ConnectedAddress = 0x110;
	}

	// obf name: ::%b045235f5577bc50e856012fff0d4a1006920fd3
#define Network_BaseNetwork_ClassName "%b045235f5577bc50e856012fff0d4a1006920fd3"
#define Network_BaseNetwork_ClassNameShort "%b045235f5577bc50e856012fff0d4a1006920fd3"
#define Network_BaseNetwork_TypeDefinitionIndex 16828

	namespace Network_BaseNetwork {

		// Functions
		constexpr const static size_t StartWrite = 0x5e41810;
	}

	// obf name: ::%606f745dfdf7a0e6fa26c2a3ecb78e44c6c8ac9d
#define Network_SendInfo_ClassName "%606f745dfdf7a0e6fa26c2a3ecb78e44c6c8ac9d"
#define Network_SendInfo_ClassNameShort "%606f745dfdf7a0e6fa26c2a3ecb78e44c6c8ac9d"
#define Network_SendInfo_TypeDefinitionIndex 16788

	namespace Network_SendInfo {

		// Offsets
		constexpr const static size_t method = 0x0;
		constexpr const static size_t channel = 0x4;
		constexpr const static size_t priority = 0x8;
		constexpr const static size_t connections = 0x10;
		constexpr const static size_t connection = 0x18;
	}

	// obf name: ::%f3aa6a51b6b03c4b0525c49a50bba0ebaeba6224
#define Network_Message_ClassName "%f3aa6a51b6b03c4b0525c49a50bba0ebaeba6224"
#define Network_Message_ClassNameShort "%f3aa6a51b6b03c4b0525c49a50bba0ebaeba6224"
#define Network_Message_TypeDefinitionIndex 16802

	namespace Network_Message {

		// Offsets
		constexpr const static size_t type = 0x18;
		constexpr const static size_t read = 0x10;
	}

	// obf name: ::%9f01e3f9446ff84701909482b22afe770a78630c
#define Network_NetRead_ClassName "%9f01e3f9446ff84701909482b22afe770a78630c"
#define Network_NetRead_ClassNameShort "%9f01e3f9446ff84701909482b22afe770a78630c"
#define Network_NetRead_TypeDefinitionIndex 16792

	namespace Network_NetRead {

		// Offsets
		constexpr const static size_t stream = 0x30;
	}

	// obf name: ::%0aec1dd1ca4b813b73a442e7f5c5792a8c7e57c8
#define Network_NetWrite_ClassName "%0aec1dd1ca4b813b73a442e7f5c5792a8c7e57c8"
#define Network_NetWrite_ClassNameShort "%0aec1dd1ca4b813b73a442e7f5c5792a8c7e57c8"
#define Network_NetWrite_TypeDefinitionIndex 16763

	namespace Network_NetWrite {

		// Offsets
		constexpr const static size_t stream = 0x40;

		// Functions
		constexpr const static size_t UInt8 = 0x30EF40;
		constexpr const static size_t UInt32 = 0x30F3B0;
		constexpr const static size_t UInt64 = 0x30F0E0;
		constexpr const static size_t String = 0x5debdb0;
		constexpr const static size_t Send = 0x5ded120;
	}

#define LootPanel_TypeDefinitionIndex 3294

	namespace LootPanel {

		// Functions
		constexpr const static size_t get_Container_00 = 0x2152770;
	}

#define UIInventory_TypeDefinitionIndex 1533

	namespace UIInventory {

		// Functions
		constexpr const static size_t Close = 0xee5870;
	}

#define GrowableEntity_TypeDefinitionIndex 626

	namespace GrowableEntity {

		// Offsets
		constexpr const static size_t Properties = 0x2a0;
		constexpr const static size_t State = 0x2b0;
	}

#define PlantProperties_TypeDefinitionIndex 4296

	namespace PlantProperties {

		// Offsets
		constexpr const static size_t stages = 0x28;
	}

#define PlantProperties_Stage_TypeDefinitionIndex 4295

	namespace PlantProperties_Stage {

		// Offsets
		constexpr const static size_t resources = 0xc;
	}

#define Text_TypeDefinitionIndex 18424

	namespace Text {

		// Offsets
		constexpr const static size_t m_Text = 0xd8;
	}

#define TOD_Sky_TypeDefinitionIndex 7580

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
		constexpr const static size_t get_Instance = 0x8c4210;
	}

	// obf name: ::%cdc5c3a3debf27458d296354096422753db158bd
#define TOD_Sky_Static_ClassName "TOD_Sky/%cdc5c3a3debf27458d296354096422753db158bd"
#define TOD_Sky_Static_ClassNameShort "%cdc5c3a3debf27458d296354096422753db158bd"
#define TOD_Sky_Static_TypeDefinitionIndex 7579

	namespace TOD_Sky_Static {

		// Offsets
		constexpr const static size_t instances = 0x40;
	}

#define TOD_CycleParameters_TypeDefinitionIndex 8593

	namespace TOD_CycleParameters {

		// Functions
		constexpr const static size_t get_DateTime = 0xb74110;
	}

#define TOD_AtmosphereParameters_TypeDefinitionIndex 7189

	namespace TOD_AtmosphereParameters {

		// Offsets
		constexpr const static size_t RayleighMultiplier = 0x10;
	}

#define TOD_DayParameters_TypeDefinitionIndex 8294

	namespace TOD_DayParameters {

		// Offsets
		constexpr const static size_t SkyColor = 0x28;
	}

#define TOD_NightParameters_TypeDefinitionIndex 7485

	namespace TOD_NightParameters {

		// Offsets
		constexpr const static size_t MoonColor = 0x10;
		constexpr const static size_t CloudColor = 0x38;
		constexpr const static size_t AmbientColor = 0x48;
	}

#define TOD_StarParameters_TypeDefinitionIndex 7187

	namespace TOD_StarParameters {

		// Offsets
		constexpr const static size_t Size = 0x10;
		constexpr const static size_t Brightness = 0x14;
	}

#define TOD_CloudParameters_TypeDefinitionIndex 7221

	namespace TOD_CloudParameters {

		// Offsets
		constexpr const static size_t Brightness = 0x30;
	}

#define TOD_AmbientParameters_TypeDefinitionIndex 7370

	namespace TOD_AmbientParameters {

		// Offsets
		constexpr const static size_t Saturation = 0x14;
	}

#define UIHUD_TypeDefinitionIndex 5691

	namespace UIHUD {

		// Offsets
		constexpr const static size_t Hunger = 0x28;
	}

#define HudElement_TypeDefinitionIndex 3861

	namespace HudElement {

		// Offsets
		constexpr const static size_t lastValue = 0x30;
	}

#define UIBelt_TypeDefinitionIndex 2661

	namespace UIBelt {

		// Offsets
		constexpr const static size_t ItemIcons = 0x20;
	}

#define ItemModCompostable_TypeDefinitionIndex 3076

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

#define EnvironmentManager_TypeDefinitionIndex 6439

	namespace EnvironmentManager {

		// Functions
		constexpr const static size_t Get = 0x44d9800;
	}

	// obf name: ::Phrase
#define Translate_Phrase_ClassName "%ef5ff90c37d8f78fce3ed9b97b88a3bd668c2813/Phrase"
#define Translate_Phrase_ClassNameShort "Phrase"
#define Translate_Phrase_TypeDefinitionIndex -1

	namespace Translate_Phrase {

		// Offsets
		constexpr const static size_t english = 0x18;
	}

#define ResourceDispenser_GatherPropertyEntry_TypeDefinitionIndex 2936

	namespace ResourceDispenser_GatherPropertyEntry {

		// Offsets
		constexpr const static size_t gatherDamage = 0x10;
		constexpr const static size_t destroyFraction = 0x14;
		constexpr const static size_t conditionLost = 0x18;
	}

#define ResourceDispenser_GatherProperties_TypeDefinitionIndex 2937

	namespace ResourceDispenser_GatherProperties {

		// Offsets
		constexpr const static size_t Tree = 0x10;
		constexpr const static size_t Ore = 0x18;
		constexpr const static size_t Flesh = 0x20;
	}

#define UIChat_TypeDefinitionIndex 1886

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
		constexpr const static size_t InstanceList = 0x8;
	}

	// obf name: ::%9c0d9d3d2859b1710df07a0837a1afe1626d91d2
#define ListHashSet_ClassName "%9c0d9d3d2859b1710df07a0837a1afe1626d91d2<UIChat>"
#define ListHashSet_ClassNameShort "%9c0d9d3d2859b1710df07a0837a1afe1626d91d2"
#define ListHashSet_TypeDefinitionIndex -1

	namespace ListHashSet {

		// Offsets
		constexpr const static size_t vals = 0x18;
	}

#define PatrolHelicopter_TypeDefinitionIndex 5801

	namespace PatrolHelicopter {

		// Offsets
		constexpr const static size_t mainRotor = 0x258;
		constexpr const static size_t weakspots = 0x3d0;
	}

#define Chainsaw_TypeDefinitionIndex 1827

	namespace Chainsaw {

		// Offsets
		constexpr const static size_t ammo = 0x374;
	}

	// obf name: ::%9b7f58087f877e5c88dadb589e79ff50e241b574
#define CameraUpdateHook_Static_ClassName "CameraUpdateHook/%9b7f58087f877e5c88dadb589e79ff50e241b574"
#define CameraUpdateHook_Static_ClassNameShort "%9b7f58087f877e5c88dadb589e79ff50e241b574"
#define CameraUpdateHook_Static_TypeDefinitionIndex 3130

	namespace CameraUpdateHook_Static {

		// Offsets
		constexpr const static size_t action = 0x90;
	}

#define SteamClientWrapper_TypeDefinitionIndex 2381

	namespace SteamClientWrapper {

		// Functions
		constexpr const static size_t GetAvatarTexture = 0x18e7de0;
	}

	// obf name: ::%b20fb4c215315d3c76289ee929b512c2333cc70b
#define AimConeUtil_ClassName "%b20fb4c215315d3c76289ee929b512c2333cc70b"
#define AimConeUtil_ClassNameShort "%b20fb4c215315d3c76289ee929b512c2333cc70b"
#define AimConeUtil_TypeDefinitionIndex 5950

	namespace AimConeUtil {

		// Functions
		constexpr const static size_t GetModifiedAimConeDirection = 0x40461f0;
	}

	// obf name: ::%a395ba8c7e36c3754f94dcbcffffb9e486d217ad
#define Buttons_ConButton_ClassName "%a708af91cff4487604e6916995d99c3874d33133/%a395ba8c7e36c3754f94dcbcffffb9e486d217ad"
#define Buttons_ConButton_ClassNameShort "%a395ba8c7e36c3754f94dcbcffffb9e486d217ad"
#define Buttons_ConButton_TypeDefinitionIndex 5459

	namespace Buttons_ConButton {

		// Offsets
		constexpr const static size_t IsDown = 0x18;
	}

	// obf name: ::%b5be4c958ede2c84551fce68653117b7b7c8957e
#define Buttons_Static_ClassName "%a708af91cff4487604e6916995d99c3874d33133/%b5be4c958ede2c84551fce68653117b7b7c8957e"
#define Buttons_Static_ClassNameShort "%b5be4c958ede2c84551fce68653117b7b7c8957e"
#define Buttons_Static_TypeDefinitionIndex 5460

	namespace Buttons_Static {

		// Offsets
		constexpr const static size_t Pets = 0x9b0;
		constexpr const static size_t Attack = 0x828;
		constexpr const static size_t Attack2 = 0xeb8;
		constexpr const static size_t Forward = 0xe00;
		constexpr const static size_t Backward = 0x390;
		constexpr const static size_t Right = 0x550;
		constexpr const static size_t Left = 0xc8;
		constexpr const static size_t Sprint = 0x3a0;

		// Functions
		constexpr const static size_t Pets_setter = 0x31fb430;
	}

#define PlayerModel_TypeDefinitionIndex 818

	namespace PlayerModel {

		// Offsets
		constexpr const static size_t _multiMesh = 0x268;
		constexpr const static size_t position = 0x1d8;
		constexpr const static size_t newVelocity = 0x1fc;
	}

#define SkinnedMultiMesh_TypeDefinitionIndex 3755

	namespace SkinnedMultiMesh {

		// Offsets
		constexpr const static size_t Renderers = 0x58;
	}

#define BaseMountable_TypeDefinitionIndex 6176

	namespace BaseMountable {

		// Offsets
		constexpr const static size_t pitchClamp = 0x274;
		constexpr const static size_t yawClamp = 0x27c;
		constexpr const static size_t canWieldItems = 0x284;
	}

#define ProgressBar_TypeDefinitionIndex 57

	namespace ProgressBar {

		// Offsets
		constexpr const static size_t Instance = 0x20;
		constexpr const static size_t timeCounter = 0x2c;
	}

#define BowWeapon_TypeDefinitionIndex 1669

	namespace BowWeapon {

		// Offsets
		constexpr const static size_t attackReady = 0x3f0;
		constexpr const static size_t wasAiming = 0x400;
	}

#define CrossbowWeapon_TypeDefinitionIndex 4786

	namespace CrossbowWeapon {

		// Offsets
	}

#define MiniCrossbow_TypeDefinitionIndex 5979

	namespace MiniCrossbow {

		// Offsets
	}

	// obf name: ::%985fc600ed3f15e37285912821b96af8f1e67f08
#define ConVar_Admin_Static_ClassName "%23b8833415cfb69d59bdedb4d5063d10b6cba148/%985fc600ed3f15e37285912821b96af8f1e67f08"
#define ConVar_Admin_Static_ClassNameShort "%985fc600ed3f15e37285912821b96af8f1e67f08"
#define ConVar_Admin_Static_TypeDefinitionIndex 2920

	namespace ConVar_Admin_Static {

		// Offsets
		constexpr const static size_t admintime = 0x114;

		// Functions
		constexpr const static size_t admintime_getter = 0x31faca0;
		constexpr const static size_t admintime_setter = 0x31ebca0;
	}

	// obf name: ::%c406c9aa3ab58cbc7fab08093dde39921ba2ff47
#define ConVar_Player_Static_ClassName "%8e1e54a21ba1e763b7528276f1299598fe7efeca/%c406c9aa3ab58cbc7fab08093dde39921ba2ff47"
#define ConVar_Player_Static_ClassNameShort "%c406c9aa3ab58cbc7fab08093dde39921ba2ff47"
#define ConVar_Player_Static_TypeDefinitionIndex 442

	namespace ConVar_Player_Static {

		// Offsets
		constexpr const static size_t clientTickInterval = 0x18c;

		// Functions
		constexpr const static size_t clientTickRate_getter = 0x31fe8c0;
		constexpr const static size_t clientTickRate_setter = 0x3203bc0;
	}

#define ColliderInfo_TypeDefinitionIndex 5907

	namespace ColliderInfo {

		// Offsets
		constexpr const static size_t flags = 0x20;
	}

#define CodeLock_TypeDefinitionIndex 5222

	namespace CodeLock {

		// Offsets
		constexpr const static size_t hasCode = 0x210;
		constexpr const static size_t hasAuth = 0x211;
		constexpr const static size_t hasGuestAuth = 0x212;
	}

#define AutoTurret_TypeDefinitionIndex 2718

	namespace AutoTurret {

		// Offsets
		constexpr const static size_t authorizedPlayers = 0x358;
		constexpr const static size_t lastYaw = 0x3b0;
		constexpr const static size_t muzzlePos = 0x3d0;
		constexpr const static size_t gun_yaw = 0x3e8;
		constexpr const static size_t gun_pitch = 0x3f0;
		constexpr const static size_t sightRange = 0x3f8;

		// Functions
		constexpr const static size_t IsAuthed = 0x1bee090;
	}

#define Client_TypeDefinitionIndex 6492

	namespace Client {

		// Functions
		constexpr const static size_t OnNetworkMessage = 0x45626e0;
		constexpr const static size_t OnNetworkMessage_vtableoff = 0x1c8;
		constexpr const static size_t CreateOrUpdateEntity = 0x4574a10;
	}

#define BaseNetworkable_TypeDefinitionIndex 5877

	namespace BaseNetworkable {

		// Functions
		constexpr const static size_t Load = 0x3f6c620;
		constexpr const static size_t Load_vtableoff = 0xc08;
	}

	// obf name: ::%5d46eee0a4d2d97b4ad229c3530dcc1b1a75a576
#define ItemManager_Static_ClassName "%e414e589d92ae3b4640ed6d9708e8213169e92ea/%5d46eee0a4d2d97b4ad229c3530dcc1b1a75a576"
#define ItemManager_Static_ClassNameShort "%5d46eee0a4d2d97b4ad229c3530dcc1b1a75a576"
#define ItemManager_Static_TypeDefinitionIndex 4856

	namespace ItemManager_Static {

		// Offsets
		constexpr const static size_t itemList = 0xe8;
		constexpr const static size_t itemDictionary = 0x1e8;
		constexpr const static size_t itemDictionaryByName = 0x130;
	}

	// obf name: ::%9db8caca2573592705476cb1ba153fabf5793b0b
#define ConVar_Server_Static_ClassName "%7320c4536d7a0442dddfeb146218368512bc7360/%9db8caca2573592705476cb1ba153fabf5793b0b"
#define ConVar_Server_Static_ClassNameShort "%9db8caca2573592705476cb1ba153fabf5793b0b"
#define ConVar_Server_Static_TypeDefinitionIndex 1250

	namespace ConVar_Server_Static {

		// Offsets
	}

#define ServerAdminUGCEntry_TypeDefinitionIndex 2255

	namespace ServerAdminUGCEntry {

		// Functions
		constexpr const static size_t ReceivedDataFromServer = 0x17b2170;
	}

#define LoadingScreen_TypeDefinitionIndex 6068

	namespace LoadingScreen {

		// Offsets
		constexpr const static size_t panel = 0x20;
	}

#define MixerSnapshotManager_TypeDefinitionIndex 1495

	namespace MixerSnapshotManager {

		// Offsets
		constexpr const static size_t defaultSnapshot = 0x20;
		constexpr const static size_t loadingSnapshot = 0x30;
	}

#define MapView_Static_ClassName "MapView/%23b2e1c3b8c0f10687324d4757333cc91ee6ff54"
#define MapView_Static_ClassNameShort "%23b2e1c3b8c0f10687324d4757333cc91ee6ff54"
#define MapView_TypeDefinitionIndex 5547

	namespace MapView {

		// Functions
		constexpr const static size_t WorldPosToImagePos = 0x3b983b0;
	}

	// obf name: ::%7e61b6f4af4d289a5fd0ec707d132b32496b9fbf
#define GamePhysics_ClassName "%7e61b6f4af4d289a5fd0ec707d132b32496b9fbf"
#define GamePhysics_ClassNameShort "%7e61b6f4af4d289a5fd0ec707d132b32496b9fbf"
#define GamePhysics_TypeDefinitionIndex 6237

	namespace GamePhysics {

		// Functions
		constexpr const static size_t Trace = 0x42a4ce0;
		constexpr const static size_t LineOfSightInternal = 0x42c9580;
		constexpr const static size_t Verify = 0x4299c30;
	}

#define DDraw_TypeDefinitionIndex 6143

	namespace DDraw {

		// Functions
		constexpr const static size_t Sphere = 0x41c31a0;
		constexpr const static size_t Line = 0x41b4a30;
	}

	// obf name: ::%78dbff6ec7c887532f63c1bb2ba12fb5fbdb42b4
#define RaycastHitEx_ClassName "%78dbff6ec7c887532f63c1bb2ba12fb5fbdb42b4"
#define RaycastHitEx_ClassNameShort "%78dbff6ec7c887532f63c1bb2ba12fb5fbdb42b4"
#define RaycastHitEx_TypeDefinitionIndex 3707

	namespace RaycastHitEx {

		// Functions
		constexpr const static size_t GetEntity = 0x25296a0;
	}

	// obf name: ::%23877975e80b7c76a418845ffb4d88c3a1aa43f2
#define OnParentDestroyingEx_ClassName "%23877975e80b7c76a418845ffb4d88c3a1aa43f2"
#define OnParentDestroyingEx_ClassNameShort "%23877975e80b7c76a418845ffb4d88c3a1aa43f2"
#define OnParentDestroyingEx_TypeDefinitionIndex 4575

	namespace OnParentDestroyingEx {

		// Functions
		constexpr const static size_t BroadcastOnParentDestroying = 0x2debb20;
	}

	// obf name: ::%581285bd5fa0efd0f092420b0dbd9157719709a4
#define ConsoleNetwork_ClassName "%581285bd5fa0efd0f092420b0dbd9157719709a4"
#define ConsoleNetwork_ClassNameShort "%581285bd5fa0efd0f092420b0dbd9157719709a4"
#define ConsoleNetwork_TypeDefinitionIndex 4090

	namespace ConsoleNetwork {

		// Functions
		constexpr const static size_t ClientRunOnServer = 0x28c1820;
	}

#define ThrownWeapon_TypeDefinitionIndex 5768

	namespace ThrownWeapon {

		// Offsets
		constexpr const static size_t maxThrowVelocity = 0x2d0;
	}

#define MapInterface_TypeDefinitionIndex 4216

	namespace MapInterface {

		// Offsets
		constexpr const static size_t scrollRectZoom = 0x30;
	}

#define ScrollRectZoom_TypeDefinitionIndex 2351

	namespace ScrollRectZoom {

		// Offsets
		constexpr const static size_t zoom = 0x28;
	}

#define MapView_TypeDefinitionIndex 5547

	namespace MapView {

		// Offsets
		constexpr const static size_t scrollRect = 0x30;
	}

#define StorageContainer_TypeDefinitionIndex 75

	namespace StorageContainer {

		// Offsets
		constexpr const static size_t inventorySlots = 0x2a0;
	}

#define PlayerCorpse_TypeDefinitionIndex 6053

	namespace PlayerCorpse {

		// Offsets
		constexpr const static size_t clientClothing = 0x2d0;
	}

#define TimedExplosive_TypeDefinitionIndex 1058

	namespace TimedExplosive {

		// Offsets
		constexpr const static size_t explosionRadius = 0x1ac;
	}

	// obf name: ::%23120084c53e28fa8dd9e17e32f29420974ad7e8
#define SmokeGrenade_Static_ClassName "SmokeGrenade/%23120084c53e28fa8dd9e17e32f29420974ad7e8"
#define SmokeGrenade_Static_ClassNameShort "%23120084c53e28fa8dd9e17e32f29420974ad7e8"
#define SmokeGrenade_Static_TypeDefinitionIndex 1946

	namespace SmokeGrenade_Static {

		// Offsets
		constexpr const static size_t activeGrenades = 0x30;
	}

#define SmokeGrenade_TypeDefinitionIndex 1947

	namespace SmokeGrenade {

		// Offsets
		constexpr const static size_t smokeEffectInstance = 0x250;
	}

#define GrenadeWeapon_TypeDefinitionIndex 6011

	namespace GrenadeWeapon {

		// Offsets
		constexpr const static size_t drop = 0x2e8;
	}

#define ViewmodelLower_TypeDefinitionIndex 1152

	namespace ViewmodelLower {

		// Offsets
		constexpr const static size_t lowerOnSprint = 0x20;
		constexpr const static size_t lowerWhenCantAttack = 0x21;
		constexpr const static size_t shouldLower = 0x28;
		constexpr const static size_t rotateAngle = 0x2c;
	}

	// obf name: ::%cd7b05c67e02e95c99333c23b89fca6be356cea0
#define ConVar_Client_Static_ClassName "%c2314e728edc852460b4da5ed39a05508b7be379/%cd7b05c67e02e95c99333c23b89fca6be356cea0"
#define ConVar_Client_Static_ClassNameShort "%cd7b05c67e02e95c99333c23b89fca6be356cea0"
#define ConVar_Client_Static_TypeDefinitionIndex 1305

	namespace ConVar_Client_Static {

		// Offsets
		constexpr const static size_t camlerp = 0x4b0;
		constexpr const static size_t camspeed = 0x330;
	}

#define SamSite_TypeDefinitionIndex 4578

	namespace SamSite {

		// Offsets
		constexpr const static size_t staticRespawn = 0x390;
		constexpr const static size_t Flag_TargetMode = 0x3cc;
	}

#define ServerProjectile_TypeDefinitionIndex 6038

	namespace ServerProjectile {

		// Offsets
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t speed = 0x3c;
		constexpr const static size_t radius = 0x5c;
	}

#define UIFogOverlay_TypeDefinitionIndex 4093

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t group = 0x20;
	}

#define FoliageGrid_TypeDefinitionIndex 4205

	namespace FoliageGrid {

		// Offsets
		constexpr const static size_t CellSize = 0x28;
	}

#define ItemModWearable_TypeDefinitionIndex 4053

	namespace ItemModWearable {

		// Offsets
		constexpr const static size_t movementProperties = 0x48;
	}

#define ClothingMovementProperties_TypeDefinitionIndex 5724

	namespace ClothingMovementProperties {

		// Offsets
		constexpr const static size_t speedReduction = 0x18;
		constexpr const static size_t minSpeedReduction = 0x1c;
	}

#define GestureConfig_TypeDefinitionIndex 6065

	namespace GestureConfig {

		// Offsets
		constexpr const static size_t actionType = 0x90;
	}

#define RCMenu_TypeDefinitionIndex 3701

	namespace RCMenu {

		// Offsets
		constexpr const static size_t autoTurretFogDistance = 0x124;
	}

	// obf name: ::%11b52991171a66824d4bcf937d4c37d2e30d0e43
#define Facepunch_Network_Raknet_Client_ClassName "%11b52991171a66824d4bcf937d4c37d2e30d0e43"
#define Facepunch_Network_Raknet_Client_ClassNameShort "%11b52991171a66824d4bcf937d4c37d2e30d0e43"
#define Facepunch_Network_Raknet_Client_TypeDefinitionIndex 19943

	namespace Facepunch_Network_Raknet_Client {

		// Functions
		constexpr const static size_t IsConnected = 0x5eba340;
		constexpr const static size_t IsConnected_vtableoff = 0x358;
	}

	// obf name: ::%90020b6bcad5e07d8a4431bd7dd333aa44ac093e
#define EncryptedValue_ClassName "%90020b6bcad5e07d8a4431bd7dd333aa44ac093e<System/Int32>"
#define EncryptedValue_ClassNameShort "%90020b6bcad5e07d8a4431bd7dd333aa44ac093e"
#define EncryptedValue_TypeDefinitionIndex -1

	namespace EncryptedValue {

		// Offsets
		constexpr const static size_t _value = 0x0;
		constexpr const static size_t _padding = 0x10;
	}

	// obf name: ::%40493f66f5768d7fef6e20e1d27955f3b606b9eb
#define HiddenValue_ClassName "%40493f66f5768d7fef6e20e1d27955f3b606b9eb<BaseNetworkable/%7b6e63c051c8a109569abe6afcde6ddaca3a6be2>"
#define HiddenValue_ClassNameShort "%40493f66f5768d7fef6e20e1d27955f3b606b9eb"
#define HiddenValue_TypeDefinitionIndex -1

	namespace HiddenValue {

		// Offsets
		constexpr const static size_t _handle = 0x18;
		constexpr const static size_t _accessCount = 0x20;
		constexpr const static size_t _hasValue = 0x10;
	}

#define SimplePrivilege___c__DisplayClass3_0_TypeDefinitionIndex 3843

	namespace SimplePrivilege___c__DisplayClass3_0 {

		// Functions
		constexpr const static size_t IsAuthed = 0x267f450;
	}

#define ItemModRFListener_TypeDefinitionIndex 2324

	namespace ItemModRFListener {

		// Functions
		constexpr const static size_t ConfigureClicked = 0x182dbc0;
	}

#define UIFogOverlay_TypeDefinitionIndex 4093

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x18;
	}

	// obf name: ::%6b5943179bb195c26345ed571771f4335c4a0de8
#define BufferStream_ClassName "%6b5943179bb195c26345ed571771f4335c4a0de8"
#define BufferStream_ClassNameShort "%6b5943179bb195c26345ed571771f4335c4a0de8"
#define BufferStream_TypeDefinitionIndex 6681

	namespace BufferStream {

		// Functions
		constexpr const static size_t EnsureCapacity = 0x875cde0;
	}

#define FreeableLootContainer_TypeDefinitionIndex 448

	namespace FreeableLootContainer {

		// Offsets
	}

#define BlowPipeWeapon_TypeDefinitionIndex 76

	namespace BlowPipeWeapon {

		// Offsets
	}

#define AttackHelicopterRockets_TypeDefinitionIndex 6558

	namespace AttackHelicopterRockets {

		// Functions
		constexpr const static size_t GetProjectedHitPos = 0x4633fd0;
	}

	// obf name: ::%36e9aa2ccdf943add97d730228fe291e3a0070b2
#define ProtoBuf_ProjectileShoot_ClassName "%36e9aa2ccdf943add97d730228fe291e3a0070b2"
#define ProtoBuf_ProjectileShoot_ClassNameShort "%36e9aa2ccdf943add97d730228fe291e3a0070b2"
#define ProtoBuf_ProjectileShoot_TypeDefinitionIndex 6728

	namespace ProtoBuf_ProjectileShoot {

		// Offsets
		constexpr const static size_t projectiles = 0x10;
	}

	// obf name: ::%6213e212d415fc3d16fbf55e7e1f260ce89250a1
#define ProtoBuf_ProjectileShoot_Projectile_ClassName "%36e9aa2ccdf943add97d730228fe291e3a0070b2/%6213e212d415fc3d16fbf55e7e1f260ce89250a1"
#define ProtoBuf_ProjectileShoot_Projectile_ClassNameShort "%6213e212d415fc3d16fbf55e7e1f260ce89250a1"
#define ProtoBuf_ProjectileShoot_Projectile_TypeDefinitionIndex 6727

	namespace ProtoBuf_ProjectileShoot_Projectile {

		// Offsets
		constexpr const static size_t projectileID = 0x24;
		constexpr const static size_t startPos = 0x10;
		constexpr const static size_t startVel = 0x2c;
		constexpr const static size_t seed = 0x20;
	}

	// obf name: ::%12aefa5616b25fbf0edb85322f2d20d76a87559a
#define ProtoBuf_PlayerProjectileUpdate_ClassName "%12aefa5616b25fbf0edb85322f2d20d76a87559a"
#define ProtoBuf_PlayerProjectileUpdate_ClassNameShort "%12aefa5616b25fbf0edb85322f2d20d76a87559a"
#define ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex 6738

	namespace ProtoBuf_PlayerProjectileUpdate {

		// Offsets
		constexpr const static size_t ShouldPool = 0x24;
		constexpr const static size_t projectileID = 0x28;
		constexpr const static size_t curPosition = 0x18;
		constexpr const static size_t curVelocity = 0x2c;
		constexpr const static size_t travelTime = 0x14;

		// Functions
		constexpr const static size_t Dispose = 0x89833b0;
	}

	// obf name: ::%b00ee6b31ab88818642e851bdc41b79bfd71fbe9
#define ProtoBuf_PlayerProjectileAttack_ClassName "%b00ee6b31ab88818642e851bdc41b79bfd71fbe9"
#define ProtoBuf_PlayerProjectileAttack_ClassNameShort "%b00ee6b31ab88818642e851bdc41b79bfd71fbe9"
#define ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex 6880

	namespace ProtoBuf_PlayerProjectileAttack {

		// Offsets
		constexpr const static size_t playerAttack = 0x18;
		constexpr const static size_t hitVelocity = 0x28;
		constexpr const static size_t hitDistance = 0x24;
		constexpr const static size_t travelTime = 0x10;
	}

	// obf name: ::%a0ddcde1754507886d97382c67e164e8331a7eca
#define ProtoBuf_PlayerAttack_ClassName "%a0ddcde1754507886d97382c67e164e8331a7eca"
#define ProtoBuf_PlayerAttack_ClassNameShort "%a0ddcde1754507886d97382c67e164e8331a7eca"
#define ProtoBuf_PlayerAttack_TypeDefinitionIndex 6899

	namespace ProtoBuf_PlayerAttack {

		// Offsets
		constexpr const static size_t attack = 0x18;
		constexpr const static size_t projectileID = 0x20;
	}

	// obf name: ::%ab509eeebfbd542381d427c325e1441ca97a0de3
#define ProtoBuf_Attack_ClassName "%ab509eeebfbd542381d427c325e1441ca97a0de3"
#define ProtoBuf_Attack_ClassNameShort "%ab509eeebfbd542381d427c325e1441ca97a0de3"
#define ProtoBuf_Attack_TypeDefinitionIndex 6800

	namespace ProtoBuf_Attack {

		// Offsets
		constexpr const static size_t pointStart = 0x24;
		constexpr const static size_t pointEnd = 0x48;
		constexpr const static size_t hitID = 0x78;
		constexpr const static size_t hitBone = 0x3c;
		constexpr const static size_t hitNormalLocal = 0x14;
		constexpr const static size_t hitPositionLocal = 0x30;
		constexpr const static size_t hitNormalWorld = 0x60;
		constexpr const static size_t hitPositionWorld = 0x54;
		constexpr const static size_t hitPartID = 0x80;
		constexpr const static size_t hitMaterialID = 0x20;
		constexpr const static size_t srcParentID = 0x70;
		constexpr const static size_t dstParentID = 0x40;
	}
}