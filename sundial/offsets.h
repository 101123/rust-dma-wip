#pragma once

#include <cstdint>
#include "offsets_manual.h"

namespace Offsets {
	namespace GameAssembly {
		constexpr const static size_t timestamp = 0x6867adfd;
		constexpr const static size_t gc_handles = 0xc3198a0;
		constexpr const static size_t il2cpp_resolve_icall = 0x6a4c10;
		constexpr const static size_t il2cpp_array_new = 0x6a4c30;
		constexpr const static size_t il2cpp_assembly_get_image = 0x126590;
		constexpr const static size_t il2cpp_class_from_name = 0x6a4da0;
		constexpr const static size_t il2cpp_class_get_method_from_name = 0x6a50b0;
		constexpr const static size_t il2cpp_class_get_type = 0x6a5150;
		constexpr const static size_t il2cpp_domain_get = 0x6a56b0;
		constexpr const static size_t il2cpp_domain_get_assemblies = 0x6a56d0;
		constexpr const static size_t il2cpp_gchandle_get_target = 0x6a5d90;
		constexpr const static size_t il2cpp_gchandle_new = 0x6a5d40;
		constexpr const static size_t il2cpp_gchandle_free = 0x6a5e30;
		constexpr const static size_t il2cpp_method_get_name = 0x3a00;
		constexpr const static size_t il2cpp_object_new = 0x6a64f0;
		constexpr const static size_t il2cpp_type_get_object = 0x6a6ce0;
	}

#define Object_TypeDefinitionIndex 14907

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

#define GameObject_TypeDefinitionIndex 14882

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

#define Component_TypeDefinitionIndex 14875

	namespace Component {

		// Functions
		constexpr const static size_t get_gameObject = 0xf7b70;
		constexpr const static size_t get_transform = 0xf77d0;
	}

#define Behaviour_TypeDefinitionIndex 14869

	namespace Behaviour {

		// Functions
		constexpr const static size_t set_enabled = 0xa1de0;
	}

#define Transform_TypeDefinitionIndex 14941

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

#define Camera_TypeDefinitionIndex 14689

	namespace Camera {

		// Functions
		constexpr const static size_t WorldToScreenPoint_Injected = 0x6f800;
	}

#define Time_TypeDefinitionIndex 14929

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

#define Material_TypeDefinitionIndex 14741

	namespace Material {

		// Functions
		constexpr const static size_t CreateWithMaterial = 0xaf1c0;
		constexpr const static size_t CreateWithShader = 0xaf050;
		constexpr const static size_t SetBufferImpl = 0xb7490;
	}

#define MaterialPropertyBlock_TypeDefinitionIndex 14737

	namespace MaterialPropertyBlock {

		// Functions
		constexpr const static size_t ctor = 0xa1f0390;
		constexpr const static size_t SetFloatImpl = 0x9bed0;
		constexpr const static size_t SetTextureImpl = 0x9c1c0;
	}

#define Shader_TypeDefinitionIndex 14740

	namespace Shader {

		// Functions
		constexpr const static size_t PropertyToID = 0xaa6a0;
	}

#define Mesh_TypeDefinitionIndex 14791

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

#define Texture_TypeDefinitionIndex 14794

	namespace Texture {
		constexpr const static size_t set_filterMode = 0xda5e0;
		constexpr const static size_t GetNativeTexturePtr = 0xdab00;
	}

#define Texture2D_TypeDefinitionIndex 14796

	namespace Texture2D {
		constexpr const static size_t ctor = 0xa208a10;
		constexpr const static size_t Internal_CreateImpl = 0xdc200;
		constexpr const static size_t GetRawImageDataSize = 0xde1e0;
		constexpr const static size_t GetWritableImageData = 0xde090;
		constexpr const static size_t ApplyImpl = 0xdc5e0;
	}

#define CommandBuffer_TypeDefinitionIndex 15235

	namespace CommandBuffer {

		// Functions
		constexpr const static size_t ctor = 0xa24b2e0;
		constexpr const static size_t Clear = 0x12f580;
		constexpr const static size_t ClearRenderTarget_Injected = 0x132050;
		constexpr const static size_t SetViewport_Injected = 0x131020;
		constexpr const static size_t SetViewProjectionMatrices_Injected = 0x136ef0;
		constexpr const static size_t EnableScissorRect_Injected = 0x131190;
		constexpr const static size_t DisableScissorRect = 0x131300;
		constexpr const static size_t Internal_DrawProceduralIndexedIndirect_Injected = 0x130300;
		constexpr const static size_t Internal_DrawMesh_Injected = 0x12f610;
	}

#define ComputeBuffer_TypeDefinitionIndex 14920

	namespace ComputeBuffer {

		// Functions
		constexpr const static size_t ctor = 0xa22c370;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Release = 0xa22c5c0;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define GraphicsBuffer_TypeDefinitionIndex 14745

	namespace GraphicsBuffer {

		// Functions
		constexpr const static size_t ctor = 0xa1f9160;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Dispose = 0xa1f8e90;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define Event_TypeDefinitionIndex 19899

	namespace Event {

		// Functions
		constexpr const static size_t get_current = 0xa25ff50;
		constexpr const static size_t get_type = 0x23a320;
		constexpr const static size_t PopEvent = 0x23b060;
		constexpr const static size_t Internal_Use = 0x23ac60;
	}

#define Graphics_TypeDefinitionIndex 14722

	namespace Graphics {

		// Functions
		constexpr const static size_t ExecuteCommandBuffer = 0x89bb0;
	}

#define Matrix4x4_TypeDefinitionIndex 14820

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

#define Screen_TypeDefinitionIndex 14719

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

#define Application_TypeDefinitionIndex 14672

	namespace Application {

		// Functions
		constexpr const static size_t Quit = 0x5d790;
	}

#define BaseNetworkable_TypeDefinitionIndex 2350

	namespace BaseNetworkable {

		// Offsets
		constexpr const static size_t prefabID = 0x30;
		constexpr const static size_t net = 0x50;
		constexpr const static size_t parentEntity = 0x60;
		constexpr const static size_t children = 0x48;
	}

	// obf name: ::%e90e1a33f08c3c9af5e1a9a01d56f417f88e5647
#define BaseNetworkable_Static_ClassName "BaseNetworkable/%e90e1a33f08c3c9af5e1a9a01d56f417f88e5647"
#define BaseNetworkable_Static_ClassNameShort "%e90e1a33f08c3c9af5e1a9a01d56f417f88e5647"
#define BaseNetworkable_Static_TypeDefinitionIndex 2349

	namespace BaseNetworkable_Static {

		// Offsets
		constexpr const static size_t clientEntities = 0x40;
	}

	// obf name: ::%6fb7f00a4393472b77628e4786ae5dad8937806a
#define BaseNetworkable_EntityRealm_ClassName "BaseNetworkable/%6fb7f00a4393472b77628e4786ae5dad8937806a"
#define BaseNetworkable_EntityRealm_ClassNameShort "%6fb7f00a4393472b77628e4786ae5dad8937806a"
#define BaseNetworkable_EntityRealm_TypeDefinitionIndex 2347

	namespace BaseNetworkable_EntityRealm {

		// Offsets
		constexpr const static size_t entityList = 0x10;

		// Functions
		constexpr const static size_t Find = 0x18d6570;
	}

	// obf name: ::%3555e77fc2932d22b64bd7dd449fcaca5e2b5fe6
#define System_ListDictionary_ClassName "%3555e77fc2932d22b64bd7dd449fcaca5e2b5fe6<%e7301f363b74214fb649d86145e6bb97913e79c7,BaseNetworkable>"
#define System_ListDictionary_ClassNameShort "%3555e77fc2932d22b64bd7dd449fcaca5e2b5fe6"
#define System_ListDictionary_TypeDefinitionIndex -1

	namespace System_ListDictionary {

		// Offsets
		constexpr const static size_t vals = 0x10;

		// Functions
		constexpr const static size_t TryGetValue = 0x667de90;
		constexpr const static size_t TryGetValue_methodinfo = 0xc015510;
	}

	// obf name: ::%40e076c56c380cddaa47e71a518348c36ea2eed7
#define System_BufferList_ClassName "%40e076c56c380cddaa47e71a518348c36ea2eed7<BaseNetworkable>"
#define System_BufferList_ClassNameShort "%40e076c56c380cddaa47e71a518348c36ea2eed7"
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
		constexpr const static size_t Instance = 0x28;
	}

#define Model_TypeDefinitionIndex 1751

	namespace Model {

		// Offsets
		constexpr const static size_t rootBone = 0x28;
		constexpr const static size_t headBone = 0x30;
		constexpr const static size_t boneTransforms = 0x50;
	}

#define BaseEntity_TypeDefinitionIndex 3121

	namespace BaseEntity {

		// Offsets
		constexpr const static size_t bounds = 0xa0;
		constexpr const static size_t model = 0xc8;
		constexpr const static size_t flags = 0xd0;
		constexpr const static size_t triggers = 0x120;
		constexpr const static size_t positionLerp = 0x130;

		// Functions
		constexpr const static size_t ServerRPC = 0x22766e0;
		constexpr const static size_t FindBone = 0x2224030;
		constexpr const static size_t GetWorldVelocity = 0x227b820;
		constexpr const static size_t GetParentVelocity = 0x224bf10;
	}

	// obf name: ::%4f5badd7b73008f6da2d807393c542a415420284
#define PositionLerp_ClassName "%4f5badd7b73008f6da2d807393c542a415420284"
#define PositionLerp_ClassNameShort "%4f5badd7b73008f6da2d807393c542a415420284"
#define PositionLerp_TypeDefinitionIndex 1796

	namespace PositionLerp {

		// Offsets
		constexpr const static size_t interpolator = 0x30;
	}

	// obf name: ::%84e63acf9c9767c22da0256d1dcdeec3945711b5
#define Interpolator_ClassName "%84e63acf9c9767c22da0256d1dcdeec3945711b5<%831e4372890d5aad6da3aaf328acf01567d5c197>"
#define Interpolator_ClassNameShort "%84e63acf9c9767c22da0256d1dcdeec3945711b5"
#define Interpolator_TypeDefinitionIndex -1

	namespace Interpolator {
		constexpr const static size_t list = 0x30;
		constexpr const static size_t last = 0x10;
	}

#define BaseCombatEntity_TypeDefinitionIndex 176

	namespace BaseCombatEntity {

		// Offsets
		constexpr const static size_t skeletonProperties = 0x1c0;
		constexpr const static size_t lifestate = 0x234;
		constexpr const static size_t markAttackerHostile = 0x23a;
		constexpr const static size_t _health = 0x23c;
		constexpr const static size_t _maxHealth = 0x240;
		constexpr const static size_t lastNotifyFrame = 0x24c;
	}

#define SkeletonProperties_TypeDefinitionIndex 3823

	namespace SkeletonProperties {

		// Offsets
		constexpr const static size_t bones = 0x20;
		constexpr const static size_t quickLookup = 0x28;
	}

#define SkeletonProperties_BoneProperty_TypeDefinitionIndex 3821

	namespace SkeletonProperties_BoneProperty {

		// Offsets
		constexpr const static size_t name = 0x18;
		constexpr const static size_t area = 0x20;
	}

#define ItemDefinition_TypeDefinitionIndex 4842

	namespace ItemDefinition {

		// Offsets
		constexpr const static size_t itemid = 0x20;
		constexpr const static size_t shortname = 0x28;
		constexpr const static size_t displayName = 0x38;
		constexpr const static size_t iconSprite = 0x48;
		constexpr const static size_t category = 0x50;
		constexpr const static size_t stackable = 0x68;
		constexpr const static size_t rarity = 0x80;
		constexpr const static size_t ItemModWearable = 0x180;
	}

#define RecoilProperties_TypeDefinitionIndex 815

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

#define BaseProjectile_Magazine_TypeDefinitionIndex 4897

	namespace BaseProjectile_Magazine {

		// Offsets
		constexpr const static size_t capacity = 0x18;
		constexpr const static size_t contents = 0x1c;
		constexpr const static size_t ammoType = 0x20;
	}

#define AttackEntity_TypeDefinitionIndex 3198

	namespace AttackEntity {

		// Offsets
		constexpr const static size_t deployDelay = 0x230;
		constexpr const static size_t repeatDelay = 0x234;
		constexpr const static size_t animationDelay = 0x238;
		constexpr const static size_t noHeadshots = 0x286;
		constexpr const static size_t nextAttackTime = 0x288;
		constexpr const static size_t timeSinceDeploy = 0x2a0;

		// Functions
		constexpr const static size_t SpectatorNotifyTick = 0x23304d0;
		constexpr const static size_t StartAttackCooldown = 0x2331490;
	}

#define BaseProjectile_TypeDefinitionIndex 4901

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
		constexpr const static size_t LaunchProjectile = 0x35e1fe0;
		constexpr const static size_t LaunchProjectileClientSide = 0x35d8e50;
		constexpr const static size_t ScaleRepeatDelay = 0x3604d90;
		constexpr const static size_t GetAimCone = 0x35dba40;
		constexpr const static size_t GetAimCone_vtableoff = 0x3ab8;
		constexpr const static size_t UpdateAmmoDisplay = 0x35dcd10;
		constexpr const static size_t UpdateAmmoDisplay_vtableoff = 0x3ae8;
	}

#define BaseLauncher_TypeDefinitionIndex 2702

	namespace BaseLauncher {

		// Offsets
	}

#define SpinUpWeapon_TypeDefinitionIndex 1993

	namespace SpinUpWeapon {

		// Offsets
	}

	// obf name: ::%7150740a20ed326197f89326e01eb3419861da25
#define HitTest_ClassName "%7150740a20ed326197f89326e01eb3419861da25"
#define HitTest_ClassNameShort "%7150740a20ed326197f89326e01eb3419861da25"
#define HitTest_TypeDefinitionIndex 3889

	namespace HitTest {

		// Offsets
		constexpr const static size_t type = 0x58;
		constexpr const static size_t AttackRay = 0x28;
		constexpr const static size_t RayHit = 0xa4;
		constexpr const static size_t damageProperties = 0x98;
		constexpr const static size_t gameObject = 0x80;
		constexpr const static size_t collider = 0x68;
		constexpr const static size_t ignoredTypes = 0x90;
		constexpr const static size_t HitTransform = 0x60;
		constexpr const static size_t HitPart = 0x88;
		constexpr const static size_t HitMaterial = 0x10;
		constexpr const static size_t DidHit = 0x70;
		constexpr const static size_t MaxDistance = 0xd4;
		constexpr const static size_t HitNormal = 0x40;
		constexpr const static size_t HitPoint = 0x4c;
		constexpr const static size_t HitEntity = 0x18;
		constexpr const static size_t ignoreEntity = 0x20;
	}

	// obf name: ::%bc3cdd910d53d8c43b1e41f7c16e33b6635bfc08
#define GameTrace_ClassName "%bc3cdd910d53d8c43b1e41f7c16e33b6635bfc08"
#define GameTrace_ClassNameShort "%bc3cdd910d53d8c43b1e41f7c16e33b6635bfc08"
#define GameTrace_TypeDefinitionIndex 3836

	namespace GameTrace {

		// Functions
		constexpr const static size_t Trace = 0x2b00b70;
	}

#define BaseMelee_TypeDefinitionIndex 4919

	namespace BaseMelee {

		// Offsets
		constexpr const static size_t damageProperties = 0x2c8;
		constexpr const static size_t maxDistance = 0x2e0;
		constexpr const static size_t attackRadius = 0x2e4;
		constexpr const static size_t blockSprintOnAttack = 0x2e9;
		constexpr const static size_t gathering = 0x318;
		constexpr const static size_t canThrowAsProjectile = 0x321;

		// Functions
		constexpr const static size_t ProcessAttack = 0x3646f50;
		constexpr const static size_t DoThrow = 0x363d030;
	}

#define FlintStrikeWeapon_TypeDefinitionIndex 2252

	namespace FlintStrikeWeapon {

		// Offsets
		constexpr const static size_t successFraction = 0x3f0;
		constexpr const static size_t strikeRecoil = 0x3f8;
		constexpr const static size_t _didSparkThisFrame = 0x400;
	}

#define CompoundBowWeapon_TypeDefinitionIndex 1300

	namespace CompoundBowWeapon {

		// Offsets
		constexpr const static size_t stringHoldDurationMax = 0x408;
		constexpr const static size_t stringBonusVelocity = 0x414;

		// Functions
		constexpr const static size_t GetStringBonusScale = 0x4e90880;
	}

	// obf name: ::%ca45ae4c53971c2942659b45ababe6083f9dc77b
#define ItemContainer_ClassName "%ca45ae4c53971c2942659b45ababe6083f9dc77b"
#define ItemContainer_ClassNameShort "%ca45ae4c53971c2942659b45ababe6083f9dc77b"
#define ItemContainer_TypeDefinitionIndex 4391

	namespace ItemContainer {

		// Offsets
		constexpr const static size_t uid = 0x40;
		constexpr const static size_t itemList = 0x58;

		// Functions
		constexpr const static size_t FindItemsByItemID = 0x3125a20;
		constexpr const static size_t GetSlot = 0x3136f10;
	}

#define PlayerLoot_TypeDefinitionIndex 3903

	namespace PlayerLoot {

		// Offsets
		constexpr const static size_t containers = 0x38;
	}

#define PlayerInventory_TypeDefinitionIndex 2819

	namespace PlayerInventory {

		// Offsets
		constexpr const static size_t containerBelt = 0x28;
		constexpr const static size_t containerWear = 0x30;
		constexpr const static size_t containerMain = 0x60;
		constexpr const static size_t loot = 0x48;

		// Functions
		constexpr const static size_t Initialize = 0x1e1e050;
		constexpr const static size_t FindItemsByItemID = 0x1e18090;
	}

#define PlayerEyes_TypeDefinitionIndex 2066

	namespace PlayerEyes {

		// Offsets
		constexpr const static size_t viewOffset = 0x40;
		constexpr const static size_t bodyRotation = 0x50;

		// Functions
		constexpr const static size_t get_position = 0x1565750;
		constexpr const static size_t get_rotation = 0x1553680;
		constexpr const static size_t set_rotation = 0x15796f0;
		constexpr const static size_t HeadForward = 0x155f0d0;
	}

	// obf name: ::%9c1f10d8d019af62b7deb44ac49e9be239cb2933
#define PlayerEyes_Static_ClassName "PlayerEyes/%9c1f10d8d019af62b7deb44ac49e9be239cb2933"
#define PlayerEyes_Static_ClassNameShort "%9c1f10d8d019af62b7deb44ac49e9be239cb2933"
#define PlayerEyes_Static_TypeDefinitionIndex 2065

	namespace PlayerEyes_Static {

		// Offsets
		constexpr const static size_t EyeOffset = 0xa8;
	}

	// obf name: ::%8bc7e96552fdbfd2a9af72319657917a3db157df
#define PlayerBelt_ClassName "%8bc7e96552fdbfd2a9af72319657917a3db157df"
#define PlayerBelt_ClassNameShort "%8bc7e96552fdbfd2a9af72319657917a3db157df"
#define PlayerBelt_TypeDefinitionIndex 4025

	namespace PlayerBelt {

		// Functions
		constexpr const static size_t ChangeSelect = 0x2cd4690;
		constexpr const static size_t GetActiveItem = 0x2cd0fe0;
	}

	// obf name: ::%96389fe8a56458417aa4fba6c35e5010b7fde454
#define LocalPlayer_ClassName "%96389fe8a56458417aa4fba6c35e5010b7fde454"
#define LocalPlayer_ClassNameShort "%96389fe8a56458417aa4fba6c35e5010b7fde454"
#define LocalPlayer_TypeDefinitionIndex 480

	namespace LocalPlayer {

		// Functions
		constexpr const static size_t ItemCommand = 0x37042f0;
		constexpr const static size_t MoveItem = 0x3718bb0;
		constexpr const static size_t get_Entity = 0x3719720;
	}

	// obf name: ::%57e622315165cbb66651527de5802fecf00ee4d0
#define LocalPlayer_Static_ClassName "%96389fe8a56458417aa4fba6c35e5010b7fde454/%57e622315165cbb66651527de5802fecf00ee4d0"
#define LocalPlayer_Static_ClassNameShort "%57e622315165cbb66651527de5802fecf00ee4d0"
#define LocalPlayer_Static_TypeDefinitionIndex 479

	namespace LocalPlayer_Static {

		// Offsets
		constexpr const static size_t Entity = 0x288;
	}

	// obf name: ::%df6111968807c6a22c49d7e4d06505746a41c7c5
#define BasePlayer_Static_ClassName "BasePlayer/%df6111968807c6a22c49d7e4d06505746a41c7c5"
#define BasePlayer_Static_ClassNameShort "%df6111968807c6a22c49d7e4d06505746a41c7c5"
#define BasePlayer_Static_TypeDefinitionIndex 3608

	namespace BasePlayer_Static {

		// Offsets
		constexpr const static size_t visiblePlayerList = 0x530;
	}

#define BasePlayer_TypeDefinitionIndex 3609

	namespace BasePlayer {

		// Offsets
		constexpr const static size_t playerModel = 0x2d0;
		constexpr const static size_t input = 0x2b8;
		constexpr const static size_t movement = 0x340;
		constexpr const static size_t currentTeam = 0x430;
		constexpr const static size_t clActiveItem = 0x460;
		constexpr const static size_t modelState = 0x288;
		constexpr const static size_t playerFlags = 0x558;
		constexpr const static size_t eyes = 0x258;
		constexpr const static size_t playerRigidbody = 0x418;
		constexpr const static size_t userID = 0x5a0;
		constexpr const static size_t UserIDString = 0x400;
		constexpr const static size_t inventory = 0x588;
		constexpr const static size_t _displayName = 0x268;
		constexpr const static size_t _lookingAt = 0x590;
		constexpr const static size_t lastSentTickTime = 0x514;
		constexpr const static size_t lastSentTick = 0x4f8;
		constexpr const static size_t mounted = 0x4a0;
		constexpr const static size_t Belt = 0x300;
		constexpr const static size_t _lookingAtEntity = 0x308;
		constexpr const static size_t currentGesture = 0x318;
		constexpr const static size_t weaponMoveSpeedScale = 0x630;
		constexpr const static size_t clothingBlocksAiming = 0x634;
		constexpr const static size_t clothingMoveSpeedReduction = 0x638;
		constexpr const static size_t clothingWaterSpeedBonus = 0x63c;
		constexpr const static size_t equippingBlocked = 0x644;

		// Functions
		constexpr const static size_t ClientUpdateLocalPlayer = 0x271c940;
		constexpr const static size_t Menu_AssistPlayer = 0x26d5770;
		constexpr const static size_t OnViewModeChanged = 0x27d2740;
		constexpr const static size_t ChatMessage = 0x26a8660;
		constexpr const static size_t IsOnGround = 0x2688660;
		constexpr const static size_t GetSpeed = 0x27b5c20;
		constexpr const static size_t SendProjectileUpdate = 0x26f0550;
		constexpr const static size_t SendProjectileAttack = 0x277b010;
		constexpr const static size_t CanBuild = 0x2747220;
		constexpr const static size_t GetMounted = 0x269ce30;
		constexpr const static size_t GetHeldEntity = 0x27c4010;
		constexpr const static size_t get_inventory = 0x2792210;
		constexpr const static size_t get_eyes = 0x27c5770;
		constexpr const static size_t SendClientTick = 0x26cb720;
		constexpr const static size_t ClientInput = 0x27b7640;
		constexpr const static size_t ClientInput_vtableoff = 0x3a98;
		constexpr const static size_t MaxHealth = 0x27757c0;
		constexpr const static size_t MaxHealth_vtableoff = 0x2e58;
	}

#define ScientistNPC_TypeDefinitionIndex 5987

	namespace ScientistNPC {

		// Offsets
	}

#define TunnelDweller_TypeDefinitionIndex 2279

	namespace TunnelDweller {

		// Offsets
	}

#define UnderwaterDweller_TypeDefinitionIndex 1429

	namespace UnderwaterDweller {

		// Offsets
	}

#define ScarecrowNPC_TypeDefinitionIndex 4764

	namespace ScarecrowNPC {

		// Offsets
	}

#define GingerbreadNPC_TypeDefinitionIndex 2603

	namespace GingerbreadNPC {

		// Offsets
	}

#define BaseMovement_TypeDefinitionIndex 2723

	namespace BaseMovement {

		// Offsets
		constexpr const static size_t adminCheat = 0x20;
		constexpr const static size_t Owner = 0x28;
	}

#define PlayerWalkMovement_TypeDefinitionIndex 3768

	namespace PlayerWalkMovement {

		// Offsets
		constexpr const static size_t capsule = 0xf0;
		constexpr const static size_t ladder = 0xd8;
		constexpr const static size_t modify = 0x1b8;

		// Functions
		constexpr const static size_t BlockJump = 0x2a36ca0;
		constexpr const static size_t BlockSprint = 0x2a0d980;
		constexpr const static size_t GroundCheck = 0x2a27c30;
		constexpr const static size_t ClientInput = 0x2a350e0;
		constexpr const static size_t ClientInput_vtableoff = 0x2a8;
		constexpr const static size_t DoFixedUpdate = 0x2a135c0;
		constexpr const static size_t DoFixedUpdate_vtableoff = 0x2d8;
		constexpr const static size_t FrameUpdate = 0x2a387d0;
		constexpr const static size_t FrameUpdate_vtableoff = 0x418;
	}

#define BuildingPrivlidge_TypeDefinitionIndex 485

	namespace BuildingPrivlidge {

		// Offsets
		constexpr const static size_t allowedConstructionItems = 0x360;
		constexpr const static size_t cachedProtectedMinutes = 0x368;
	}

#define WorldItem_TypeDefinitionIndex 1346

	namespace WorldItem {

		// Offsets
		constexpr const static size_t allowPickup = 0x1a0;
		constexpr const static size_t item = 0x1a8;
	}

#define HackableLockedCrate_TypeDefinitionIndex 4981

	namespace HackableLockedCrate {

		// Offsets
		constexpr const static size_t timerText = 0x378;
		constexpr const static size_t hackSeconds = 0x388;
	}

#define ProjectileWeaponMod_TypeDefinitionIndex 3034

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

#define ProjectileWeaponMod_Modifier_TypeDefinitionIndex 3031

	namespace ProjectileWeaponMod_Modifier {
		constexpr const static size_t enabled = 0x0;
		constexpr const static size_t scalar = 0x4;
		constexpr const static size_t offset = 0x8;
	}

	// obf name: ::%eccb33797a9ae2134097403d009690ac7af73a4a
#define ConsoleSystem_ClassName "%eccb33797a9ae2134097403d009690ac7af73a4a"
#define ConsoleSystem_ClassNameShort "%eccb33797a9ae2134097403d009690ac7af73a4a"
#define ConsoleSystem_TypeDefinitionIndex 20600

	namespace ConsoleSystem {

		// Functions
		constexpr const static size_t Run = 0x5d72750;
	}

#define ConsoleSystem_Option_ClassName "%eccb33797a9ae2134097403d009690ac7af73a4a/%a657d9e268ed5d7a4fc9c47b51755d88165c8db6"
#define ConsoleSystem_Option_ClassNameShort "%a657d9e268ed5d7a4fc9c47b51755d88165c8db6"
#define ConsoleSystem_Command_ClassName "%eccb33797a9ae2134097403d009690ac7af73a4a/%51bd352f496e87385dea655c19a91f5cf2e534c7"
#define ConsoleSystem_Command_ClassNameShort "%51bd352f496e87385dea655c19a91f5cf2e534c7"
	// obf name: ::%6e810df022913fd8e535d35be4139e8a1949df97
#define ConsoleSystem_Index_Static_ClassName "%eccb33797a9ae2134097403d009690ac7af73a4a/%f1f6c6dad22dc7533a5171b3e7f04c2621aa79f8.%6e810df022913fd8e535d35be4139e8a1949df97"
#define ConsoleSystem_Index_Static_ClassNameShort "%6e810df022913fd8e535d35be4139e8a1949df97"
#define ConsoleSystem_Index_Static_TypeDefinitionIndex 20595

	namespace ConsoleSystem_Index_Static {

		// Offsets
		constexpr const static size_t All = 0x30;
	}

	// obf name: ::%dfe6f22cddfe4b749c44253192f8bdbebd206509
#define ConsoleSystem_Arg_ClassName "%eccb33797a9ae2134097403d009690ac7af73a4a/%dfe6f22cddfe4b749c44253192f8bdbebd206509"
#define ConsoleSystem_Arg_ClassNameShort "%dfe6f22cddfe4b749c44253192f8bdbebd206509"
// obf name: ::%8f293873f6467711afdb26fe166a6522ce5bc3dc
#define Facepunch_Network_SteamNetworking_ClassName "%8f293873f6467711afdb26fe166a6522ce5bc3dc"
#define Facepunch_Network_SteamNetworking_ClassNameShort "%8f293873f6467711afdb26fe166a6522ce5bc3dc"
#define LootableCorpse_TypeDefinitionIndex 6014

	namespace LootableCorpse {

		// Offsets
		constexpr const static size_t playerSteamID = 0x298;
		constexpr const static size_t _playerName = 0x288;
	}

#define DroppedItemContainer_TypeDefinitionIndex 2756

	namespace DroppedItemContainer {

		// Offsets
		constexpr const static size_t playerSteamID = 0x268;
		constexpr const static size_t _playerName = 0x250;
	}

#define MainCamera_TypeDefinitionIndex 5172

	namespace MainCamera {

		// Offsets 
		constexpr const static size_t mainCamera = 0xd8;
		constexpr const static size_t mainCameraTransform = 0x38;

		// Functions
		constexpr const static size_t Update = 0x3873a80;
		constexpr const static size_t Trace = 0x3871c80;
	}

#define CameraMan_TypeDefinitionIndex 4058

	namespace CameraMan {

		// Offsets
	}

	// obf name: ::%fefcac38ac30ca3ae154429b54dd671967858a0a
#define PlayerTick_ClassName "%fefcac38ac30ca3ae154429b54dd671967858a0a"
#define PlayerTick_ClassNameShort "%fefcac38ac30ca3ae154429b54dd671967858a0a"
#define PlayerTick_TypeDefinitionIndex 6976

	namespace PlayerTick {

		// Offsets
		constexpr const static size_t inputState = 0x50;
		constexpr const static size_t modelState = 0x10;
		constexpr const static size_t activeItem = 0x18;
		constexpr const static size_t parentID = 0x40;
		constexpr const static size_t position = 0x34;
		constexpr const static size_t eyePos = 0x24;
	}

	// obf name: ::%4efae7dd0e6f679f1dd5920ca927212113cb17cb
#define InputMessage_ClassName "%4efae7dd0e6f679f1dd5920ca927212113cb17cb"
#define InputMessage_ClassNameShort "%4efae7dd0e6f679f1dd5920ca927212113cb17cb"
#define InputMessage_TypeDefinitionIndex 6761

	namespace InputMessage {

		// Offsets
		constexpr const static size_t buttons = 0x20;
		constexpr const static size_t aimAngles = 0x10;
		constexpr const static size_t mouseDelta = 0x24;
	}

	// obf name: ::%61f367db7d6d6f835cc5969e9b09a1c5480cf12a
#define InputState_ClassName "%61f367db7d6d6f835cc5969e9b09a1c5480cf12a"
#define InputState_ClassNameShort "%61f367db7d6d6f835cc5969e9b09a1c5480cf12a"
#define InputState_TypeDefinitionIndex 1450

	namespace InputState {

		// Offsets
		constexpr const static size_t current = 0x10;
		constexpr const static size_t previous = 0x20;
	}

#define PlayerInput_TypeDefinitionIndex 6201

	namespace PlayerInput {

		// Offsets
		constexpr const static size_t state = 0x28;
		constexpr const static size_t bodyAngles = 0x44;
	}

	// obf name: ::%1d73e66e8cd5004fd83020a0d0db2aa893f07d26
#define ModelState_ClassName "%1d73e66e8cd5004fd83020a0d0db2aa893f07d26"
#define ModelState_ClassNameShort "%1d73e66e8cd5004fd83020a0d0db2aa893f07d26"
#define ModelState_TypeDefinitionIndex 6924

	namespace ModelState {

		// Offsets
		constexpr const static size_t flags = 0x10;
		constexpr const static size_t waterLevel = 0x6c;
		constexpr const static size_t lookDir = 0x48;
	}

	// obf name: ::%2ad41e9563f28775ecf515a02d5084062664b4ab
#define Item_ClassName "%2ad41e9563f28775ecf515a02d5084062664b4ab"
#define Item_ClassNameShort "%2ad41e9563f28775ecf515a02d5084062664b4ab"
#define Item_TypeDefinitionIndex 519

	namespace Item {

		// Offsets
		constexpr const static size_t info = 0xc0;
		constexpr const static size_t uid = 0x78;
		constexpr const static size_t _maxCondition = 0x58;
		constexpr const static size_t _condition = 0xd0;
		constexpr const static size_t position = 0x18;
		constexpr const static size_t amount = 0x5c;
		constexpr const static size_t parent = 0x28;
		constexpr const static size_t contents = 0x70;
		constexpr const static size_t worldEnt = 0x30;
		constexpr const static size_t heldEntity = 0x80;

		// Functions
		constexpr const static size_t get_iconSprite = 0x39adfb0;
	}

	// obf name: ::%ddaca128942534167e09255888a1874831641cdf
#define WaterLevel_ClassName "%ddaca128942534167e09255888a1874831641cdf"
#define WaterLevel_ClassNameShort "%ddaca128942534167e09255888a1874831641cdf"
#define WaterLevel_TypeDefinitionIndex 1014

	namespace WaterLevel {

		// Functions
		constexpr const static size_t Test = 0x4b2d3a0;
		constexpr const static size_t GetWaterLevel = 0x4b0cbf0;
	}

	// obf name: ::%fcbbcae26410a405a74dc76e5f85fe10541e30dc
#define ConVar_Graphics_Static_ClassName "%ca8fa5a4a3eca21088739d9519c7a4fc9cbc1c73/%fcbbcae26410a405a74dc76e5f85fe10541e30dc"
#define ConVar_Graphics_Static_ClassNameShort "%fcbbcae26410a405a74dc76e5f85fe10541e30dc"
#define ConVar_Graphics_Static_TypeDefinitionIndex 1265

	namespace ConVar_Graphics_Static {

		// Offsets
		constexpr const static size_t _fov = 0x2f8;

		// Functions
		constexpr const static size_t _fov_getter = 0x202dc00;
		constexpr const static size_t _fov_setter = 0x20106d0;
	}

#define BaseFishingRod_TypeDefinitionIndex 3991

	namespace BaseFishingRod {

		// Offsets
		constexpr const static size_t CurrentState = 0x250;
		constexpr const static size_t currentBobber = 0x258;
		constexpr const static size_t MaxCastDistance = 0x274;
		constexpr const static size_t BobberPreview = 0x280;
		constexpr const static size_t clientStrainAmountNormalised = 0x2c0;
		constexpr const static size_t strainGainMod = 0x2a8;
		constexpr const static size_t aimAnimationReady = 0x2d8;

		// Functions
		constexpr const static size_t UpdateLineRenderer = 0x2c55020;
		constexpr const static size_t EvaluateFishingPosition = 0x2c5f710;
	}

#define FishingBobber_TypeDefinitionIndex 2602

	namespace FishingBobber {

		// Offsets
		constexpr const static size_t bobberRoot = 0x268;
	}

#define GameManifest_TypeDefinitionIndex 5688

	namespace GameManifest {

		// Functions
		constexpr const static size_t GUIDToObject = 0x3d01420;
	}

	// obf name: ::%add0c74caba8936d29c6bf4c7d9eb291d4990db1
#define GameManager_ClassName "%add0c74caba8936d29c6bf4c7d9eb291d4990db1"
#define GameManager_ClassNameShort "%add0c74caba8936d29c6bf4c7d9eb291d4990db1"
#define GameManager_TypeDefinitionIndex 6521

	namespace GameManager {

		// Offsets
		constexpr const static size_t pool = 0x20;

		// Functions
		constexpr const static size_t CreatePrefab = 0x45a88c0;
	}

	// obf name: ::%33477fab98700db4622b5bbd30ee80e193631228
#define GameManager_Static_ClassName "%add0c74caba8936d29c6bf4c7d9eb291d4990db1/%33477fab98700db4622b5bbd30ee80e193631228"
#define GameManager_Static_ClassNameShort "%33477fab98700db4622b5bbd30ee80e193631228"
#define GameManager_Static_TypeDefinitionIndex 6520

	namespace GameManager_Static {

		// Offsets
		constexpr const static size_t client = 0x20;
	}

	// obf name: ::%fcd98629f292c0cadf2bfa58620f6dda674bf3a1
#define PrefabPoolCollection_ClassName "%fcd98629f292c0cadf2bfa58620f6dda674bf3a1"
#define PrefabPoolCollection_ClassNameShort "%fcd98629f292c0cadf2bfa58620f6dda674bf3a1"
#define PrefabPoolCollection_TypeDefinitionIndex 4661

	namespace PrefabPoolCollection {

		// Offsets
		constexpr const static size_t storage = 0x18;
	}

	// obf name: ::%eeda889756fd88c825cae2cf66aebbe8889fa4b2
#define PrefabPool_ClassName "%eeda889756fd88c825cae2cf66aebbe8889fa4b2"
#define PrefabPool_ClassNameShort "%eeda889756fd88c825cae2cf66aebbe8889fa4b2"
#define PrefabPool_TypeDefinitionIndex 1970

	namespace PrefabPool {

		// Offsets
		constexpr const static size_t stack = 0x28;
	}

#define ItemModProjectile_TypeDefinitionIndex 6524

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

#define Projectile_TypeDefinitionIndex 4237

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
		constexpr const static size_t sourceProjectilePrefab = 0x118;
		constexpr const static size_t mod = 0x1c8;
		constexpr const static size_t hitTest = 0x108;
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
		constexpr const static size_t CalculateEffectScale = 0x2f7bd00;
		constexpr const static size_t CalculateEffectScale_vtableoff = 0x2b8;
		constexpr const static size_t SetEffectScale = 0x2f9afc0;
		constexpr const static size_t UpdateVelocity = 0x2f92710;
		constexpr const static size_t Retire = 0x2fa0f20;
		constexpr const static size_t DoHit = 0x2f81950;
	}

#define CraftingQueue_TypeDefinitionIndex 1712

	namespace CraftingQueue {

		// Offsets
		constexpr const static size_t icons = 0x30;
	}

	// obf name: ::%f76c9e2e9efc1072581b02a814dc912b10c07320
#define CraftingQueue_Static_ClassName "CraftingQueue/%f76c9e2e9efc1072581b02a814dc912b10c07320"
#define CraftingQueue_Static_ClassNameShort "%f76c9e2e9efc1072581b02a814dc912b10c07320"
#define CraftingQueue_Static_TypeDefinitionIndex 1711

	namespace CraftingQueue_Static {

		// Offsets
		constexpr const static size_t isCrafting = 0x10;
	}

#define CraftingQueueIcon_TypeDefinitionIndex 1379

	namespace CraftingQueueIcon {

		// Offsets
		constexpr const static size_t endTime = 0x4c;
		constexpr const static size_t item = 0x60;
	}

	// obf name: ::%0e61c3ceea322cb7aaceb95e0242dff2f01ce2ae
#define Planner_Static_ClassName "Planner/%0e61c3ceea322cb7aaceb95e0242dff2f01ce2ae"
#define Planner_Static_ClassNameShort "%0e61c3ceea322cb7aaceb95e0242dff2f01ce2ae"
#define Planner_Static_TypeDefinitionIndex 4670

	namespace Planner_Static {

		// Offsets
		constexpr const static size_t guide = 0x20;
	}

	// obf name: ::%469ef72292e0a55fb22becfeba14246417914ec6
#define Planner_Guide_ClassName "Planner/%469ef72292e0a55fb22becfeba14246417914ec6"
#define Planner_Guide_ClassNameShort "%469ef72292e0a55fb22becfeba14246417914ec6"
#define Planner_Guide_TypeDefinitionIndex 4666

	namespace Planner_Guide {

		// Offsets
		constexpr const static size_t lastPlacement = 0x98;
	}

#define Planner_TypeDefinitionIndex 4671

	namespace Planner {

		// Offsets
		constexpr const static size_t _currentConstruction = 0x278;
	}

#define Construction_TypeDefinitionIndex 5794

	namespace Construction {

		// Offsets
		constexpr const static size_t holdToPlaceDuration = 0xfc;
		constexpr const static size_t grades = 0x198;
	}

#define BuildingBlock_TypeDefinitionIndex 5721

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t blockDefinition = 0x2e0;
	}

	// obf name: ::HeldEntity
#define HeldEntity_ClassName "HeldEntity"
#define HeldEntity_ClassNameShort "HeldEntity"
#define HeldEntity_TypeDefinitionIndex 4417

	namespace HeldEntity {

		// Offsets
		constexpr const static size_t ownerItemUID = 0x210;
		constexpr const static size_t _punches = 0x1c0;
		constexpr const static size_t viewModel = 0x218;

		// Functions
		constexpr const static size_t OnDeploy = 0x3180d10;
	}

	// obf name: ::%077659907cbb05a9ceb7c92b57226d303afacee6
#define PunchEntry_ClassName "HeldEntity/%077659907cbb05a9ceb7c92b57226d303afacee6"
#define PunchEntry_ClassNameShort "%077659907cbb05a9ceb7c92b57226d303afacee6"
#define PunchEntry_TypeDefinitionIndex 4415

	namespace PunchEntry {

		// Offsets
		constexpr const static size_t startTime = 0x1c;
		constexpr const static size_t duration = 0x2c;
		constexpr const static size_t amountAdded = 0x10;
		constexpr const static size_t amount = 0x20;
	}

#define IronSights_TypeDefinitionIndex 551

	namespace IronSights {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t ironsightsOverride = 0x68;
	}

#define IronSightOverride_TypeDefinitionIndex 5540

	namespace IronSightOverride {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t fovBias = 0x30;
	}

#define BaseViewModel_TypeDefinitionIndex 457

	namespace BaseViewModel {

		// Offsets
		constexpr const static size_t useViewModelCamera = 0x40;
		constexpr const static size_t ironSights = 0xd0;
		constexpr const static size_t model = 0xa8;
		constexpr const static size_t lower = 0xe0;

		// Functions
		constexpr const static size_t get_ActiveModel = 0x33ac450;
	}

#define ViewModel_TypeDefinitionIndex 3788

	namespace ViewModel {

		// Offsets
		constexpr const static size_t instance = 0x28;

		// Functions
		constexpr const static size_t PlayInt = 0x2a79780;
		constexpr const static size_t PlayString = 0x2a7b220;
	}

#define MedicalTool_TypeDefinitionIndex 4434

	namespace MedicalTool {

		// Offsets
		constexpr const static size_t resetTime = 0x2e8;
	}

#define WaterBody_TypeDefinitionIndex 2935

	namespace WaterBody {

		// Offsets
		constexpr const static size_t meshFilter = 0x58;
	}

	// obf name: ::%d2a44f43440cadc0567a3912f4bb3a978457de8b
#define WaterSystem_Static_ClassName "WaterSystem/%d2a44f43440cadc0567a3912f4bb3a978457de8b"
#define WaterSystem_Static_ClassNameShort "%d2a44f43440cadc0567a3912f4bb3a978457de8b"
#define WaterSystem_Static_TypeDefinitionIndex 43

	namespace WaterSystem_Static {

		// Offsets
		constexpr const static size_t Ocean = 0x60;
	}

#define WaterSystem_TypeDefinitionIndex 44

	namespace WaterSystem {

		// Functions
		constexpr const static size_t get_Ocean = 0x1d2da70;
	}

#define TerrainMeta_TypeDefinitionIndex 2474

	namespace TerrainMeta {

		// Offsets
		constexpr const static size_t Position = 0x18;
		constexpr const static size_t Size = 0x24;
		constexpr const static size_t OneOverSize = 0x30;
		constexpr const static size_t Collision = 0x3c0;
		constexpr const static size_t HeightMap = 0x690;
		constexpr const static size_t SplatMap = 0x78;
		constexpr const static size_t TopologyMap = 0x3c8;
		constexpr const static size_t Texturing = 0x618;
	}

#define TerrainCollision_TypeDefinitionIndex 5988

	namespace TerrainCollision {

		// Functions
		constexpr const static size_t GetIgnore = 0x40756E0;
	}

#define TerrainHeightMap_TypeDefinitionIndex 3529

	namespace TerrainHeightMap {

		// Offsets
		constexpr const static size_t normY = 0x70;
	}

#define TerrainSplatMap_TypeDefinitionIndex 4576

	namespace TerrainSplatMap {

		// Offsets
		constexpr const static size_t num = 0x70;
	}

#define TerrainTexturing_TypeDefinitionIndex 2717

	namespace TerrainTexturing {

		// Offsets
		constexpr const static size_t shoreMapSize = 0x8c;
		constexpr const static size_t terrainSize = 0x88;
		constexpr const static size_t shoreDistanceScale = 0x90;
		constexpr const static size_t shoreVectors = 0xa8;
	}

	// obf name: ::%fac23a419183ce94a8994a8031f6285e2b263d00
#define World_Static_ClassName "%33de24b7a4b52045c1ebb12a9b6c1c8988946d48/%fac23a419183ce94a8994a8031f6285e2b263d00"
#define World_Static_ClassNameShort "%fac23a419183ce94a8994a8031f6285e2b263d00"
#define World_Static_TypeDefinitionIndex 6217

	namespace World_Static {

		// Offsets
		constexpr const static size_t _size = 0x38;
	}

#define ItemIcon_TypeDefinitionIndex 1344

	namespace ItemIcon {

		// Functions
		constexpr const static size_t SetTimedLootAction = 0x4ed9950;
	}

	// obf name: ::%8d295d93101aabce6f91f74608947e0097056637
#define ItemIcon_Static_ClassName "ItemIcon/%8d295d93101aabce6f91f74608947e0097056637"
#define ItemIcon_Static_ClassNameShort "%8d295d93101aabce6f91f74608947e0097056637"
#define ItemIcon_Static_TypeDefinitionIndex 1343

	namespace ItemIcon_Static {

		// Offsets
		constexpr const static size_t containerLootStartTimes = 0x28;
	}

	// obf name: ::%c9b85b27502eaf8c3e22e28e087531bb905e4493
#define Effect_ClassName "%c9b85b27502eaf8c3e22e28e087531bb905e4493"
#define Effect_ClassNameShort "%c9b85b27502eaf8c3e22e28e087531bb905e4493"
#define Effect_TypeDefinitionIndex 1247

	namespace Effect {

		// Offsets
		constexpr const static size_t pooledString = 0x78;
		constexpr const static size_t worldPos = 0x60;
	}

	// obf name: ::%5abee67033baa865c16baa27147e1120aea158e8
#define EffectNetwork_ClassName "%5abee67033baa865c16baa27147e1120aea158e8"
#define EffectNetwork_ClassNameShort "%5abee67033baa865c16baa27147e1120aea158e8"
#define EffectNetwork_TypeDefinitionIndex 3300

	namespace EffectNetwork {

		// Functions
	}

	// obf name: ::%476eb2816241f6fa0f4a769b2419d8f39e5f84a3
#define EffectNetwork_Static_ClassName "%5abee67033baa865c16baa27147e1120aea158e8/%476eb2816241f6fa0f4a769b2419d8f39e5f84a3"
#define EffectNetwork_Static_ClassNameShort "%476eb2816241f6fa0f4a769b2419d8f39e5f84a3"
#define EffectNetwork_Static_TypeDefinitionIndex 3299

	namespace EffectNetwork_Static {

		// Offsets
		constexpr const static size_t effect = 0x38;

		// Functions
		constexpr const static size_t cctor = 0x23f2ef0;
	}

#define BuildingBlock_TypeDefinitionIndex 5721

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t grade = 0x2d8;

		// Functions
		constexpr const static size_t GetBuildMenu = 0x3d84f30;
		constexpr const static size_t HasUpgradePrivilege = 0x3d61ff0;
		constexpr const static size_t CanAffordUpgrade = 0x3d6b8c0;
	}

	// obf name: ::%54b8d768d9a5b6a86945c071a76a9a6b770ce307
#define GameObjectEx_ClassName "%54b8d768d9a5b6a86945c071a76a9a6b770ce307"
#define GameObjectEx_ClassNameShort "%54b8d768d9a5b6a86945c071a76a9a6b770ce307"
#define GameObjectEx_TypeDefinitionIndex 2191

	namespace GameObjectEx {

		// Functions
		constexpr const static size_t ToBaseEntity = 0x17185d0;
	}

#define UIDeathScreen_TypeDefinitionIndex 149

	namespace UIDeathScreen {

		// Functions
		constexpr const static size_t SetVisible = 0xdb43f0;
	}

	// obf name: ::%a978a8908377a9428a4a7012c4ea049037e60404
#define BaseScreenShake_Static_ClassName "BaseScreenShake/%a978a8908377a9428a4a7012c4ea049037e60404"
#define BaseScreenShake_Static_ClassNameShort "%a978a8908377a9428a4a7012c4ea049037e60404"
#define BaseScreenShake_Static_TypeDefinitionIndex 4292

	namespace BaseScreenShake_Static {

		// Offsets
		constexpr const static size_t list = 0x88;
	}

#define FlashbangOverlay_TypeDefinitionIndex 5315

	namespace FlashbangOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x18;
		constexpr const static size_t flashLength = 0x40;
	}

	// obf name: ::%4246584ef5d8becdca959a9ec2fb3308c8ab85af
#define StringPool_ClassName "%4246584ef5d8becdca959a9ec2fb3308c8ab85af"
#define StringPool_ClassNameShort "%4246584ef5d8becdca959a9ec2fb3308c8ab85af"
#define StringPool_TypeDefinitionIndex 3162

	namespace StringPool {

		// Offsets
		constexpr const static size_t toNumber = 0x58;

		// Functions
		constexpr const static size_t Get = 0x22efb70;
	}

	// obf name: ::%75c4072fe331c35bd2de98ef2541b5b451e33d64
#define Network_Networkable_ClassName "%75c4072fe331c35bd2de98ef2541b5b451e33d64"
#define Network_Networkable_ClassNameShort "%75c4072fe331c35bd2de98ef2541b5b451e33d64"
#define Network_Networkable_TypeDefinitionIndex 16782

	namespace Network_Networkable {

		// Offsets
		constexpr const static size_t ID = 0x40;
	}

	// obf name: ::%24b00d54a83a2a9c3f108a16611059d43e5d6e14
#define Network_Net_ClassName "%24b00d54a83a2a9c3f108a16611059d43e5d6e14"
#define Network_Net_ClassNameShort "%24b00d54a83a2a9c3f108a16611059d43e5d6e14"
#define Network_Net_TypeDefinitionIndex 9241

	namespace Network_Net {

		// Offsets
		constexpr const static size_t cl = 0x0;
	}

	// obf name: ::%b97c1ca9f1403eb9cc9e8414b6baa8226b70d8d9
#define Network_Client_ClassName "%b97c1ca9f1403eb9cc9e8414b6baa8226b70d8d9"
#define Network_Client_ClassNameShort "%b97c1ca9f1403eb9cc9e8414b6baa8226b70d8d9"
#define Network_Client_TypeDefinitionIndex 16834

	namespace Network_Client {

		// Offsets
		constexpr const static size_t Connection = 0xf0;
		constexpr const static size_t ConnectedPort = 0xd8;
		constexpr const static size_t ServerName = 0xf8;
		constexpr const static size_t ConnectedAddress = 0x110;
	}

	// obf name: ::%5e991ab383e1c1ff589fb75dc0b03e6c5ded3e65
#define Network_BaseNetwork_ClassName "%5e991ab383e1c1ff589fb75dc0b03e6c5ded3e65"
#define Network_BaseNetwork_ClassNameShort "%5e991ab383e1c1ff589fb75dc0b03e6c5ded3e65"
#define Network_BaseNetwork_TypeDefinitionIndex 16822

	namespace Network_BaseNetwork {

		// Functions
		constexpr const static size_t StartWrite = 0x5e405f0;
	}

	// obf name: ::%2947fa3898306e433247e0c3ac1c90e03c19e0b2
#define Network_SendInfo_ClassName "%2947fa3898306e433247e0c3ac1c90e03c19e0b2"
#define Network_SendInfo_ClassNameShort "%2947fa3898306e433247e0c3ac1c90e03c19e0b2"
#define Network_SendInfo_TypeDefinitionIndex 16810

	namespace Network_SendInfo {

		// Offsets
		constexpr const static size_t method = 0x0;
		constexpr const static size_t channel = 0x4;
		constexpr const static size_t priority = 0x8;
		constexpr const static size_t connections = 0x10;
		constexpr const static size_t connection = 0x18;
	}

	// obf name: ::%3037cf842cf2c9689054b22e1c0da3d841f800bd
#define Network_Message_ClassName "%3037cf842cf2c9689054b22e1c0da3d841f800bd"
#define Network_Message_ClassNameShort "%3037cf842cf2c9689054b22e1c0da3d841f800bd"
#define Network_Message_TypeDefinitionIndex 16796

	namespace Network_Message {

		// Offsets
		constexpr const static size_t type = 0x18;
		constexpr const static size_t read = 0x10;
	}

	// obf name: ::%f1a11ffbaa61bb6f9e5caff612a46cac06b8dda3
#define Network_NetRead_ClassName "%f1a11ffbaa61bb6f9e5caff612a46cac06b8dda3"
#define Network_NetRead_ClassNameShort "%f1a11ffbaa61bb6f9e5caff612a46cac06b8dda3"
#define Network_NetRead_TypeDefinitionIndex 16809

	namespace Network_NetRead {

		// Offsets
		constexpr const static size_t stream = 0x30;
	}

	// obf name: ::%7e5b3c2bb6daef80757cc72f025de6dddb7b6936
#define Network_NetWrite_ClassName "%7e5b3c2bb6daef80757cc72f025de6dddb7b6936"
#define Network_NetWrite_ClassNameShort "%7e5b3c2bb6daef80757cc72f025de6dddb7b6936"
#define Network_NetWrite_TypeDefinitionIndex 16777

	namespace Network_NetWrite {

		// Offsets
		constexpr const static size_t stream = 0x40;

		// Functions
		constexpr const static size_t UInt8 = 0x30FDA0;
		constexpr const static size_t UInt32 = 0x30FFA0;
		constexpr const static size_t UInt64 = 0x30FED0;
		constexpr const static size_t String = 0x5dfaa60;
		constexpr const static size_t Send = 0x5dfdb90;
	}

#define LootPanel_TypeDefinitionIndex 3994

	namespace LootPanel {

		// Functions
		constexpr const static size_t get_Container_00 = 0x2c7ee60;
	}

#define UIInventory_TypeDefinitionIndex 2745

	namespace UIInventory {

		// Functions
		constexpr const static size_t Close = 0x1d18b50;
	}

#define GrowableEntity_TypeDefinitionIndex 5277

	namespace GrowableEntity {

		// Offsets
		constexpr const static size_t Properties = 0x2a0;
		constexpr const static size_t State = 0x2b0;
	}

#define PlantProperties_TypeDefinitionIndex 2577

	namespace PlantProperties {

		// Offsets
		constexpr const static size_t stages = 0x28;
	}

#define PlantProperties_Stage_TypeDefinitionIndex 2576

	namespace PlantProperties_Stage {

		// Offsets
		constexpr const static size_t resources = 0xc;
	}

#define Text_TypeDefinitionIndex 18429

	namespace Text {

		// Offsets
		constexpr const static size_t m_Text = 0xd8;
	}

#define TOD_Sky_TypeDefinitionIndex 7479

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
		constexpr const static size_t get_Instance = 0x8541e0;
	}

	// obf name: ::%ff26a45a3466bac29629506dfe41b64a1b82285b
#define TOD_Sky_Static_ClassName "TOD_Sky/%ff26a45a3466bac29629506dfe41b64a1b82285b"
#define TOD_Sky_Static_ClassNameShort "%ff26a45a3466bac29629506dfe41b64a1b82285b"
#define TOD_Sky_Static_TypeDefinitionIndex 7478

	namespace TOD_Sky_Static {

		// Offsets
		constexpr const static size_t instances = 0xb0;
	}

#define TOD_CycleParameters_TypeDefinitionIndex 7370

	namespace TOD_CycleParameters {

		// Functions
		constexpr const static size_t get_DateTime = 0x7facd0;
	}

#define TOD_AtmosphereParameters_TypeDefinitionIndex 8760

	namespace TOD_AtmosphereParameters {

		// Offsets
		constexpr const static size_t RayleighMultiplier = 0x10;
	}

#define TOD_DayParameters_TypeDefinitionIndex 7986

	namespace TOD_DayParameters {

		// Offsets
		constexpr const static size_t SkyColor = 0x28;
	}

#define TOD_NightParameters_TypeDefinitionIndex 7070

	namespace TOD_NightParameters {

		// Offsets
		constexpr const static size_t MoonColor = 0x10;
		constexpr const static size_t CloudColor = 0x38;
		constexpr const static size_t AmbientColor = 0x48;
	}

#define TOD_StarParameters_TypeDefinitionIndex 8260

	namespace TOD_StarParameters {

		// Offsets
		constexpr const static size_t Size = 0x10;
		constexpr const static size_t Brightness = 0x14;
	}

#define TOD_CloudParameters_TypeDefinitionIndex 8111

	namespace TOD_CloudParameters {

		// Offsets
		constexpr const static size_t Brightness = 0x30;
	}

#define TOD_AmbientParameters_TypeDefinitionIndex 9011

	namespace TOD_AmbientParameters {

		// Offsets
		constexpr const static size_t Saturation = 0x14;
	}

#define UIHUD_TypeDefinitionIndex 3210

	namespace UIHUD {

		// Offsets
		constexpr const static size_t Hunger = 0x28;
	}

#define HudElement_TypeDefinitionIndex 5799

	namespace HudElement {

		// Offsets
		constexpr const static size_t lastValue = 0x30;
	}

#define UIBelt_TypeDefinitionIndex 5135

	namespace UIBelt {

		// Offsets
		constexpr const static size_t ItemIcons = 0x20;
	}

#define ItemModCompostable_TypeDefinitionIndex 373

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

#define EnvironmentManager_TypeDefinitionIndex 617

	namespace EnvironmentManager {

		// Functions
		constexpr const static size_t Get = 0x4542170;
	}

	// obf name: ::Phrase
#define Translate_Phrase_ClassName "%0d2cbf6998ea8f1fc0bfd0bd78a571a40296720e/Phrase"
#define Translate_Phrase_ClassNameShort "Phrase"
#define Translate_Phrase_TypeDefinitionIndex -1

	namespace Translate_Phrase {

		// Offsets
		constexpr const static size_t english = 0x18;
	}

#define ResourceDispenser_GatherPropertyEntry_TypeDefinitionIndex 1508

	namespace ResourceDispenser_GatherPropertyEntry {

		// Offsets
		constexpr const static size_t gatherDamage = 0x10;
		constexpr const static size_t destroyFraction = 0x14;
		constexpr const static size_t conditionLost = 0x18;
	}

#define ResourceDispenser_GatherProperties_TypeDefinitionIndex 1509

	namespace ResourceDispenser_GatherProperties {

		// Offsets
		constexpr const static size_t Tree = 0x10;
		constexpr const static size_t Ore = 0x18;
		constexpr const static size_t Flesh = 0x20;
	}

#define UIChat_TypeDefinitionIndex 3027

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
		constexpr const static size_t InstanceList = 0x30;
	}

	// obf name: ::%2ebdc5e5c6ee8c9919977c10475912f24ff86801
#define ListHashSet_ClassName "%2ebdc5e5c6ee8c9919977c10475912f24ff86801<UIChat>"
#define ListHashSet_ClassNameShort "%2ebdc5e5c6ee8c9919977c10475912f24ff86801"
#define ListHashSet_TypeDefinitionIndex -1

	namespace ListHashSet {

		// Offsets
		constexpr const static size_t vals = 0x18;
	}

#define PatrolHelicopter_TypeDefinitionIndex 3550

	namespace PatrolHelicopter {

		// Offsets
		constexpr const static size_t mainRotor = 0x258;
		constexpr const static size_t weakspots = 0x3d0;
	}

#define Chainsaw_TypeDefinitionIndex 3290

	namespace Chainsaw {

		// Offsets
		constexpr const static size_t ammo = 0x374;
	}

	// obf name: ::%8dcd8de9386cfbac30bfddd5a67306c525aa4df0
#define CameraUpdateHook_Static_ClassName "CameraUpdateHook/%8dcd8de9386cfbac30bfddd5a67306c525aa4df0"
#define CameraUpdateHook_Static_ClassNameShort "%8dcd8de9386cfbac30bfddd5a67306c525aa4df0"
#define CameraUpdateHook_Static_TypeDefinitionIndex 6358

	namespace CameraUpdateHook_Static {

		// Offsets
		constexpr const static size_t action = 0x20;
	}

#define SteamClientWrapper_TypeDefinitionIndex 2680

	namespace SteamClientWrapper {

		// Functions
		constexpr const static size_t GetAvatarTexture = 0x1c63f20;
	}

	// obf name: ::%ec6c59c565910dbf183e6cb49651c548e46fbee4
#define AimConeUtil_ClassName "%ec6c59c565910dbf183e6cb49651c548e46fbee4"
#define AimConeUtil_ClassNameShort "%ec6c59c565910dbf183e6cb49651c548e46fbee4"
#define AimConeUtil_TypeDefinitionIndex 670

	namespace AimConeUtil {

		// Functions
		constexpr const static size_t GetModifiedAimConeDirection = 0x46f6910;
	}

	// obf name: ::%0bb9fcbc90375f37812e21e874480829f5944fab
#define Buttons_ConButton_ClassName "%580e0213ebce4060561c417c9b2b442b38927aec/%0bb9fcbc90375f37812e21e874480829f5944fab"
#define Buttons_ConButton_ClassNameShort "%0bb9fcbc90375f37812e21e874480829f5944fab"
#define Buttons_ConButton_TypeDefinitionIndex 3924

	namespace Buttons_ConButton {

		// Offsets
		constexpr const static size_t IsDown = 0x18;
	}

	// obf name: ::%6c902953899aaf89af96d655d0749feb76ef5b61
#define Buttons_Static_ClassName "%580e0213ebce4060561c417c9b2b442b38927aec/%6c902953899aaf89af96d655d0749feb76ef5b61"
#define Buttons_Static_ClassNameShort "%6c902953899aaf89af96d655d0749feb76ef5b61"
#define Buttons_Static_TypeDefinitionIndex 3925

	namespace Buttons_Static {

		// Offsets
		constexpr const static size_t Pets = 0x930;
		constexpr const static size_t Attack = 0xb88;
		constexpr const static size_t Attack2 = 0x398;
		constexpr const static size_t Forward = 0x7a8;
		constexpr const static size_t Backward = 0xb68;
		constexpr const static size_t Right = 0xb98;
		constexpr const static size_t Left = 0xe78;
		constexpr const static size_t Sprint = 0x540;

		// Functions
		constexpr const static size_t Pets_setter = 0x202bf40;
	}

#define PlayerModel_TypeDefinitionIndex 1027

	namespace PlayerModel {

		// Offsets
		constexpr const static size_t _multiMesh = 0x288;
		constexpr const static size_t position = 0x1d8;
		constexpr const static size_t newVelocity = 0x1fc;
	}

#define SkinnedMultiMesh_TypeDefinitionIndex 4273

	namespace SkinnedMultiMesh {

		// Offsets
		constexpr const static size_t Renderers = 0x58;
	}

#define BaseMountable_TypeDefinitionIndex 3572

	namespace BaseMountable {

		// Offsets
		constexpr const static size_t pitchClamp = 0x274;
		constexpr const static size_t yawClamp = 0x27c;
		constexpr const static size_t canWieldItems = 0x284;
	}

#define ProgressBar_TypeDefinitionIndex 4340

	namespace ProgressBar {

		// Offsets
		constexpr const static size_t Instance = 0x10;
		constexpr const static size_t timeCounter = 0x24;
	}

#define BowWeapon_TypeDefinitionIndex 2733

	namespace BowWeapon {

		// Offsets
		constexpr const static size_t attackReady = 0x3f0;
		constexpr const static size_t wasAiming = 0x400;
	}

#define CrossbowWeapon_TypeDefinitionIndex 3195

	namespace CrossbowWeapon {

		// Offsets
	}

#define MiniCrossbow_TypeDefinitionIndex 5660

	namespace MiniCrossbow {

		// Offsets
	}

	// obf name: ::%68fdadd662d1811d0d73913d2fd5f68d2433bf19
#define ConVar_Admin_Static_ClassName "%374e93f2cc465408a523154d221c206a19849323/%68fdadd662d1811d0d73913d2fd5f68d2433bf19"
#define ConVar_Admin_Static_ClassNameShort "%68fdadd662d1811d0d73913d2fd5f68d2433bf19"
#define ConVar_Admin_Static_TypeDefinitionIndex 987

	namespace ConVar_Admin_Static {

		// Offsets
		constexpr const static size_t admintime = 0x154;

		// Functions
		constexpr const static size_t admintime_getter = 0x200d0a0;
		constexpr const static size_t admintime_setter = 0x201bb80;
	}

	// obf name: ::%aadc4253ae01f3e071cc5b9c4d30fac4f6b5d320
#define ConVar_Player_Static_ClassName "%e6de18712e752a16a8be64041f5576ad813e8c73/%aadc4253ae01f3e071cc5b9c4d30fac4f6b5d320"
#define ConVar_Player_Static_ClassNameShort "%aadc4253ae01f3e071cc5b9c4d30fac4f6b5d320"
#define ConVar_Player_Static_TypeDefinitionIndex 708

	namespace ConVar_Player_Static {

		// Offsets
		constexpr const static size_t clientTickInterval = 0x130;

		// Functions
		constexpr const static size_t clientTickRate_getter = 0x2024450;
		constexpr const static size_t clientTickRate_setter = 0x202abe0;
	}

#define ColliderInfo_TypeDefinitionIndex 3188

	namespace ColliderInfo {

		// Offsets
		constexpr const static size_t flags = 0x20;
	}

#define CodeLock_TypeDefinitionIndex 4051

	namespace CodeLock {

		// Offsets
		constexpr const static size_t hasCode = 0x210;
		constexpr const static size_t hasAuth = 0x211;
		constexpr const static size_t hasGuestAuth = 0x212;
	}

#define AutoTurret_TypeDefinitionIndex 1414

	namespace AutoTurret {

		// Offsets
		constexpr const static size_t authorizedPlayers = 0x3a0;
		constexpr const static size_t lastYaw = 0x3b0;
		constexpr const static size_t muzzlePos = 0x3d0;
		constexpr const static size_t gun_yaw = 0x3e8;
		constexpr const static size_t gun_pitch = 0x3f0;
		constexpr const static size_t sightRange = 0x3f8;

		// Functions
		constexpr const static size_t IsAuthed = 0xe98d60;
	}

#define Client_TypeDefinitionIndex 1835

	namespace Client {

		// Functions
		constexpr const static size_t OnNetworkMessage = 0x12d5a00;
		constexpr const static size_t OnNetworkMessage_vtableoff = 0x1c8;
		constexpr const static size_t CreateOrUpdateEntity = 0x12f92e0;
	}

#define BaseNetworkable_TypeDefinitionIndex 2350

	namespace BaseNetworkable {

		// Functions
		constexpr const static size_t Load = 0x18d3ea0;
		constexpr const static size_t Load_vtableoff = 0xab8;
	}

	// obf name: ::%557cb233dd81d64c10948993d7d65c68801c66ba
#define ItemManager_Static_ClassName "%732be2734652937b7b865eff24804d2793f5fdfc/%557cb233dd81d64c10948993d7d65c68801c66ba"
#define ItemManager_Static_ClassNameShort "%557cb233dd81d64c10948993d7d65c68801c66ba"
#define ItemManager_Static_TypeDefinitionIndex 2869

	namespace ItemManager_Static {

		// Offsets
		constexpr const static size_t itemList = 0xb0;
		constexpr const static size_t itemDictionary = 0x190;
		constexpr const static size_t itemDictionaryByName = 0x158;
	}

	// obf name: ::%72ba3aa5330f5c5d1cce76578f080abfa976e46f
#define ConVar_Server_Static_ClassName "%08d01d293cb67f815c3520fb095bece7687932ef/%72ba3aa5330f5c5d1cce76578f080abfa976e46f"
#define ConVar_Server_Static_ClassNameShort "%72ba3aa5330f5c5d1cce76578f080abfa976e46f"
#define ConVar_Server_Static_TypeDefinitionIndex 153

	namespace ConVar_Server_Static {

		// Offsets
	}

#define ServerAdminUGCEntry_TypeDefinitionIndex 4622

	namespace ServerAdminUGCEntry {

		// Functions
		constexpr const static size_t ReceivedDataFromServer = 0x3341df0;
	}

#define LoadingScreen_TypeDefinitionIndex 3642

	namespace LoadingScreen {

		// Offsets
		constexpr const static size_t panel = 0x20;
	}

#define MixerSnapshotManager_TypeDefinitionIndex 1877

	namespace MixerSnapshotManager {

		// Offsets
		constexpr const static size_t defaultSnapshot = 0x20;
		constexpr const static size_t loadingSnapshot = 0x30;
	}

#define MapView_Static_ClassName "MapView/%080eb0d926287acd68ac399e22fc1cf5811c5739"
#define MapView_Static_ClassNameShort "%080eb0d926287acd68ac399e22fc1cf5811c5739"
#define MapView_TypeDefinitionIndex 2454

	namespace MapView {

		// Functions
		constexpr const static size_t WorldPosToImagePos = 0x1999b10;
	}

	// obf name: ::%170348e0f6cdd9f4389b9e25046978c85c2743c4
#define GamePhysics_ClassName "%170348e0f6cdd9f4389b9e25046978c85c2743c4"
#define GamePhysics_ClassNameShort "%170348e0f6cdd9f4389b9e25046978c85c2743c4"
#define GamePhysics_TypeDefinitionIndex 4118

	namespace GamePhysics {

		// Functions
		constexpr const static size_t Trace = 0x2dc6de0;
		constexpr const static size_t LineOfSightInternal = 0x2db6210;
		constexpr const static size_t Verify = 0x2dc2a50;
	}

#define DDraw_TypeDefinitionIndex 5459

	namespace DDraw {

		// Functions
		constexpr const static size_t Sphere = 0x3b40640;
		constexpr const static size_t Line = 0x3b47ca0;
	}

	// obf name: ::%ea46e71014a17d7fd3f938370e85fa6c5eeb557e
#define RaycastHitEx_ClassName "%ea46e71014a17d7fd3f938370e85fa6c5eeb557e"
#define RaycastHitEx_ClassNameShort "%ea46e71014a17d7fd3f938370e85fa6c5eeb557e"
#define RaycastHitEx_TypeDefinitionIndex 5385

	namespace RaycastHitEx {

		// Functions
		constexpr const static size_t GetEntity = 0x3a98e10;
	}

	// obf name: ::%ed8e3dc446a8fb29423f39d105e5530584ad7a40
#define OnParentDestroyingEx_ClassName "%ed8e3dc446a8fb29423f39d105e5530584ad7a40"
#define OnParentDestroyingEx_ClassNameShort "%ed8e3dc446a8fb29423f39d105e5530584ad7a40"
#define OnParentDestroyingEx_TypeDefinitionIndex 4499

	namespace OnParentDestroyingEx {

		// Functions
		constexpr const static size_t BroadcastOnParentDestroying = 0x320b620;
	}

	// obf name: ::%784e7a79ba1967e60024a30e47ee8c2197b81ad6
#define ConsoleNetwork_ClassName "%784e7a79ba1967e60024a30e47ee8c2197b81ad6"
#define ConsoleNetwork_ClassNameShort "%784e7a79ba1967e60024a30e47ee8c2197b81ad6"
#define ConsoleNetwork_TypeDefinitionIndex 5133

	namespace ConsoleNetwork {

		// Functions
		constexpr const static size_t ClientRunOnServer = 0x37ee980;
	}

#define ThrownWeapon_TypeDefinitionIndex 5912

	namespace ThrownWeapon {

		// Offsets
		constexpr const static size_t maxThrowVelocity = 0x2d0;
	}

#define MapInterface_TypeDefinitionIndex 4368

	namespace MapInterface {

		// Offsets
		constexpr const static size_t scrollRectZoom = 0x30;
	}

#define ScrollRectZoom_TypeDefinitionIndex 2439

	namespace ScrollRectZoom {

		// Offsets
		constexpr const static size_t zoom = 0x28;
	}

#define MapView_TypeDefinitionIndex 2454

	namespace MapView {

		// Offsets
		constexpr const static size_t scrollRect = 0x30;
	}

#define StorageContainer_TypeDefinitionIndex 3314

	namespace StorageContainer {

		// Offsets
		constexpr const static size_t inventorySlots = 0x2a0;
	}

#define PlayerCorpse_TypeDefinitionIndex 705

	namespace PlayerCorpse {

		// Offsets
		constexpr const static size_t clientClothing = 0x2d0;
	}

#define TimedExplosive_TypeDefinitionIndex 3537

	namespace TimedExplosive {

		// Offsets
		constexpr const static size_t explosionRadius = 0x1ac;
	}

	// obf name: ::%55d9ce0631e1310b1ad28494e70197dd8982ce1c
#define SmokeGrenade_Static_ClassName "SmokeGrenade/%55d9ce0631e1310b1ad28494e70197dd8982ce1c"
#define SmokeGrenade_Static_ClassNameShort "%55d9ce0631e1310b1ad28494e70197dd8982ce1c"
#define SmokeGrenade_Static_TypeDefinitionIndex 4312

	namespace SmokeGrenade_Static {

		// Offsets
		constexpr const static size_t activeGrenades = 0x0;
	}

#define SmokeGrenade_TypeDefinitionIndex 4313

	namespace SmokeGrenade {

		// Offsets
		constexpr const static size_t smokeEffectInstance = 0x250;
	}

#define GrenadeWeapon_TypeDefinitionIndex 3582

	namespace GrenadeWeapon {

		// Offsets
		constexpr const static size_t drop = 0x2e8;
	}

#define ViewmodelLower_TypeDefinitionIndex 1483

	namespace ViewmodelLower {

		// Offsets
		constexpr const static size_t lowerOnSprint = 0x20;
		constexpr const static size_t lowerWhenCantAttack = 0x21;
		constexpr const static size_t shouldLower = 0x28;
		constexpr const static size_t rotateAngle = 0x2c;
	}

	// obf name: ::%1935be7f47451cf09256b0a586de0b9db544cfcc
#define ConVar_Client_Static_ClassName "%e67356d239b6ca6fef9f24df1f85f385c5b2972d/%1935be7f47451cf09256b0a586de0b9db544cfcc"
#define ConVar_Client_Static_ClassNameShort "%1935be7f47451cf09256b0a586de0b9db544cfcc"
#define ConVar_Client_Static_TypeDefinitionIndex 5831

	namespace ConVar_Client_Static {

		// Offsets
		constexpr const static size_t camlerp = 0x2c;
		constexpr const static size_t camspeed = 0x52c;
	}

#define SamSite_TypeDefinitionIndex 608

	namespace SamSite {

		// Offsets
		constexpr const static size_t staticRespawn = 0x390;
		constexpr const static size_t Flag_TargetMode = 0x3cc;
	}

#define ServerProjectile_TypeDefinitionIndex 3545

	namespace ServerProjectile {

		// Offsets
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t speed = 0x3c;
		constexpr const static size_t radius = 0x5c;
	}

#define UIFogOverlay_TypeDefinitionIndex 5813

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t group = 0x20;
	}

#define FoliageGrid_TypeDefinitionIndex 5978

	namespace FoliageGrid {

		// Offsets
		constexpr const static size_t CellSize = 0x28;
	}

#define ItemModWearable_TypeDefinitionIndex 5701

	namespace ItemModWearable {

		// Offsets
		constexpr const static size_t movementProperties = 0x48;
	}

#define ClothingMovementProperties_TypeDefinitionIndex 4676

	namespace ClothingMovementProperties {

		// Offsets
		constexpr const static size_t speedReduction = 0x18;
		constexpr const static size_t minSpeedReduction = 0x1c;
	}

#define GestureConfig_TypeDefinitionIndex 2082

	namespace GestureConfig {

		// Offsets
		constexpr const static size_t actionType = 0x90;
	}

#define RCMenu_TypeDefinitionIndex 5252

	namespace RCMenu {

		// Offsets
		constexpr const static size_t autoTurretFogDistance = 0x124;
	}

	// obf name: ::%5a4e3687259270b4bd91394b9e6402a471afe9da
#define Facepunch_Network_Raknet_Client_ClassName "%5a4e3687259270b4bd91394b9e6402a471afe9da"
#define Facepunch_Network_Raknet_Client_ClassNameShort "%5a4e3687259270b4bd91394b9e6402a471afe9da"
#define Facepunch_Network_Raknet_Client_TypeDefinitionIndex 19938

	namespace Facepunch_Network_Raknet_Client {

		// Functions
		constexpr const static size_t IsConnected = 0x5e9afb0;
		constexpr const static size_t IsConnected_vtableoff = 0x2e8;
	}

	// obf name: ::%f13b178805b3c96a2bc3f2e81309eca7f5fb21b0
#define EncryptedValue_ClassName "%f13b178805b3c96a2bc3f2e81309eca7f5fb21b0<System/Int32>"
#define EncryptedValue_ClassNameShort "%f13b178805b3c96a2bc3f2e81309eca7f5fb21b0"
#define EncryptedValue_TypeDefinitionIndex -1

	namespace EncryptedValue {

		// Offsets
		constexpr const static size_t _value = 0x0;
		constexpr const static size_t _padding = 0x10;
	}

	// obf name: ::%277130a4d5d1b7ba53677117c9a4f97ca7957b6c
#define HiddenValue_ClassName "%277130a4d5d1b7ba53677117c9a4f97ca7957b6c<BaseNetworkable/%6fb7f00a4393472b77628e4786ae5dad8937806a>"
#define HiddenValue_ClassNameShort "%277130a4d5d1b7ba53677117c9a4f97ca7957b6c"
#define HiddenValue_TypeDefinitionIndex -1

	namespace HiddenValue {

		// Offsets
		constexpr const static size_t _handle = 0x18;
		constexpr const static size_t _accessCount = 0x20;
		constexpr const static size_t _hasValue = 0x10;
	}

#define SimplePrivilege___c__DisplayClass3_0_TypeDefinitionIndex 464

	namespace SimplePrivilege___c__DisplayClass3_0 {

		// Functions
		constexpr const static size_t IsAuthed = 0x3571030;
	}

#define ItemModRFListener_TypeDefinitionIndex 19

	namespace ItemModRFListener {

		// Functions
		constexpr const static size_t ConfigureClicked = 0xd9a330;
	}

#define UIFogOverlay_TypeDefinitionIndex 5813

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x30;
	}

	// obf name: ::%6c4a3e0059f578447b2ea81808560f2b86b7707d
#define BufferStream_ClassName "%6c4a3e0059f578447b2ea81808560f2b86b7707d"
#define BufferStream_ClassNameShort "%6c4a3e0059f578447b2ea81808560f2b86b7707d"
#define BufferStream_TypeDefinitionIndex 6811

	namespace BufferStream {

		// Functions
		constexpr const static size_t EnsureCapacity = 0x8c11470;
	}

#define FreeableLootContainer_TypeDefinitionIndex 2230

	namespace FreeableLootContainer {

		// Offsets
	}

#define BlowPipeWeapon_TypeDefinitionIndex 2681

	namespace BlowPipeWeapon {

		// Offsets
	}

#define AttackHelicopterRockets_TypeDefinitionIndex 6545

	namespace AttackHelicopterRockets {

		// Functions
		constexpr const static size_t GetProjectedHitPos = 0x45efe70;
	}

	// obf name: ::%e4d1c047a7ebb810f940356b8aa5e0b14dc320e2
#define ProtoBuf_ProjectileShoot_ClassName "%e4d1c047a7ebb810f940356b8aa5e0b14dc320e2"
#define ProtoBuf_ProjectileShoot_ClassNameShort "%e4d1c047a7ebb810f940356b8aa5e0b14dc320e2"
#define ProtoBuf_ProjectileShoot_TypeDefinitionIndex 6670

	namespace ProtoBuf_ProjectileShoot {

		// Offsets
		constexpr const static size_t projectiles = 0x18;
	}

	// obf name: ::%94363c4b04ab1cf76e3a639e069e2aedd8f78724
#define ProtoBuf_ProjectileShoot_Projectile_ClassName "%e4d1c047a7ebb810f940356b8aa5e0b14dc320e2/%94363c4b04ab1cf76e3a639e069e2aedd8f78724"
#define ProtoBuf_ProjectileShoot_Projectile_ClassNameShort "%94363c4b04ab1cf76e3a639e069e2aedd8f78724"
#define ProtoBuf_ProjectileShoot_Projectile_TypeDefinitionIndex 6669

	namespace ProtoBuf_ProjectileShoot_Projectile {

		// Offsets
		constexpr const static size_t projectileID = 0x14;
		constexpr const static size_t startPos = 0x28;
		constexpr const static size_t startVel = 0x1c;
		constexpr const static size_t seed = 0x34;
	}

	// obf name: ::%06c5e58814ef9c716314e8e9ddaef95b098123c6
#define ProtoBuf_PlayerProjectileUpdate_ClassName "%06c5e58814ef9c716314e8e9ddaef95b098123c6"
#define ProtoBuf_PlayerProjectileUpdate_ClassNameShort "%06c5e58814ef9c716314e8e9ddaef95b098123c6"
#define ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex 6687

	namespace ProtoBuf_PlayerProjectileUpdate {

		// Offsets
		constexpr const static size_t projectileID = 0x30;
		constexpr const static size_t curPosition = 0x10;
		constexpr const static size_t curVelocity = 0x24;
		constexpr const static size_t travelTime = 0x1c;
		constexpr const static size_t ShouldPool = 0x34;

		// Functions
		constexpr const static size_t Dispose = 0x878ecd0;
	}

	// obf name: ::%22080440bb9308462fea44ef805a8063311596ac
#define ProtoBuf_PlayerProjectileAttack_ClassName "%22080440bb9308462fea44ef805a8063311596ac"
#define ProtoBuf_PlayerProjectileAttack_ClassNameShort "%22080440bb9308462fea44ef805a8063311596ac"
#define ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex 6799

	namespace ProtoBuf_PlayerProjectileAttack {

		// Offsets
		constexpr const static size_t playerAttack = 0x30;
		constexpr const static size_t hitVelocity = 0x18;
		constexpr const static size_t hitDistance = 0x24;
		constexpr const static size_t travelTime = 0x10;
	}

	// obf name: ::%1a828c1c727f547abaf9a1e2c6de76d37f75af39
#define ProtoBuf_PlayerAttack_ClassName "%1a828c1c727f547abaf9a1e2c6de76d37f75af39"
#define ProtoBuf_PlayerAttack_ClassNameShort "%1a828c1c727f547abaf9a1e2c6de76d37f75af39"
#define ProtoBuf_PlayerAttack_TypeDefinitionIndex 6694

	namespace ProtoBuf_PlayerAttack {

		// Offsets
		constexpr const static size_t attack = 0x18;
		constexpr const static size_t projectileID = 0x24;
	}

	// obf name: ::%940ad042140100060d8c73f5f0f3e3c0ed9144ab
#define ProtoBuf_Attack_ClassName "%940ad042140100060d8c73f5f0f3e3c0ed9144ab"
#define ProtoBuf_Attack_ClassNameShort "%940ad042140100060d8c73f5f0f3e3c0ed9144ab"
#define ProtoBuf_Attack_TypeDefinitionIndex 6623

	namespace ProtoBuf_Attack {

		// Offsets
		constexpr const static size_t pointStart = 0x1c;
		constexpr const static size_t pointEnd = 0x2c;
		constexpr const static size_t hitID = 0x60;
		constexpr const static size_t hitBone = 0x28;
		constexpr const static size_t hitNormalLocal = 0x6c;
		constexpr const static size_t hitPositionLocal = 0x48;
		constexpr const static size_t hitNormalWorld = 0x10;
		constexpr const static size_t hitPositionWorld = 0x78;
		constexpr const static size_t hitPartID = 0x3c;
		constexpr const static size_t hitMaterialID = 0x54;
		constexpr const static size_t srcParentID = 0x58;
		constexpr const static size_t dstParentID = 0x40;
	}
}