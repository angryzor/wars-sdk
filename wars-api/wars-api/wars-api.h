#pragma once

#include <cstdint>
#include <d3d11.h>

#ifndef EXPORTING_TYPES
#include <new>
#include <cassert>
#include <cstring>
#include <type_traits>
#include <synchapi.h>
#endif

#ifdef UpdateResource
#undef UpdateResource
#endif
#ifdef SendMessage
#undef SendMessage
#endif
#ifdef AddJob
#undef AddJob
#endif
#ifdef max
#undef max
#endif
#ifdef VOID
#undef VOID
#endif

#include "cslib/csl/math/math.h"
#include "cslib/csl/fnd/IAllocator.h"

#include <ucsl/newtype.h>

namespace warssdk::ucsl {
    struct AllocatorSystem {
        using allocator_type = csl::fnd::IAllocator;

        inline static csl::fnd::IAllocator* get_allocator();
    };
}

#include "cslib/csl/ut/Array.h"
#include "cslib/csl/ut/FixedArray.h"
#include "cslib/csl/ut/HashMap.h"
#include "cslib/csl/ut/List.h"
#include "cslib/csl/ut/LinkList.h"
#include "cslib/csl/ut/MoveArray.h"
#include "cslib/csl/ut/MoveArray32.h"
#include "cslib/csl/ut/InPlaceMoveArray.h"
#include "cslib/csl/ut/PointerMap.h"
#include "cslib/csl/ut/StringMap.h"
#include "cslib/csl/ut/Hash.h"
#include "cslib/csl/ut/BasicString.h"
#include "cslib/csl/ut/Bitset.h"
#include "cslib/csl/ut/Color.h"
#include "cslib/csl/ut/NonCopyable.h"
#include "cslib/csl/ut/Pair.h"
#include "cslib/csl/ut/String.h"
#include "cslib/csl/ut/VariableString.h"
#include "cslib/csl/ut/Enum.h"

#include "cslib/csl/fnd/Singleton.h"
#include "cslib/csl/fnd/Mutex.h"
#include "cslib/csl/fnd/HeapBase.h"
#include "cslib/csl/fnd/FreeListHeap.h"
#include "cslib/csl/fnd/OptimizedFreeListHeap.h"
#include "cslib/csl/fnd/StackHeap.h"
#include "cslib/csl/fnd/LinkHeap.h"
#include "cslib/csl/fnd/PoolHeap.h"
#include "cslib/csl/fnd/ExternalHeap.h"
#include "cslib/csl/fnd/Delegate.h"

#include "Hedgehog/Rsdx/hhMTSimpleJobJoint.h"
#include "Hedgehog/Rsdx/hhmtjobdispatchfunctions.h"

#include "Hedgehog/Foundation/System/hhAllocator.h"
#include "Hedgehog/Foundation/System/SingletonInitNode.h"

// Hedgehog Library
#include "Hedgehog/Foundation/System/MemoryRouter.h"
#include "Hedgehog/Foundation/System/hhBaseObject.h"
#include "Hedgehog/Foundation/System/hhReferencedObject.h"
#include "Hedgehog/Foundation/System/RefByHandleObject.h"
#include "Hedgehog/Foundation/System/hhProperty.h"
#include "Hedgehog/Foundation/System/HFrame.h"
#include "Hedgehog/Foundation/System/HandleManager.h"
#include "Hedgehog/Foundation/System/hhHandle.h"
#include "Hedgehog/Foundation/System/ReloaderListener.h"
#include "Hedgehog/Foundation/System/SUpdateInfo.h"
#include "Hedgehog/Foundation/System/UpdatingPhase.h"

#include "Hedgehog/Foundation/Universe/hhMessage.h"
#include "Hedgehog/Foundation/Universe/MessageQueue.h"
#include "Hedgehog/Foundation/Universe/MessageManager.h"
#include "Hedgehog/Foundation/Universe/hhMessenger.h"

#include "Hedgehog/Utility/TempString.h"
#include "Hedgehog/Utility/TempMoveArray.h"
#include "Hedgehog/Utility/FSM/TinyFsm.h"
#include "Hedgehog/Utility/FSM/StateDesc.h"
#include "Hedgehog/Utility/FSM/StateManager.h"
#include "Hedgehog/Utility/FSM/State.h"
#include "Hedgehog/Utility/FSM/Hsm.h"
#include "Hedgehog/Utility/BinaryFile.h"
#include "Hedgehog/Utility/AabbTree.h"
#include "Hedgehog/Utility/BvWorld.h"
#include "Hedgehog/Utility/KdTree.h"

#include "Hedgehog/Foundation/Type/hhBaseTypes.h"
#include "Hedgehog/Foundation/Type/WorldPosition.h"
#include "Hedgehog/Foundation/Type/LogData.h"
#include "Hedgehog/Foundation/Type/Triangle.h"
#include "Hedgehog/Foundation/Type/Geometry.h"
#include "Hedgehog/Foundation/Type/WireGeometry.h"
#include "Hedgehog/Foundation/Type/ResLightParameter.h"

#include "Hedgehog/TArray.h"

#include "Hedgehog/Filesystem/FileInfo.h"
#include "Hedgehog/Filesystem/FileBind.h"

#include "Hedgehog/Resource/Uri.h"
#include "Hedgehog/Resource/InplaceUri.h"
#include "Hedgehog/Resource/InplaceTempUri.h"
#include "Hedgehog/Resource/File.h"
#include "Hedgehog/Resource/ManagedResource.h"
#include "Hedgehog/Resource/ResourceTypeRegistry.h"
#include "Hedgehog/Resource/ResourceNameResolver.h"
#include "Hedgehog/Resource/FilePathResolver.h"
#include "Hedgehog/Resource/ResourceContainer.h"
#include "Hedgehog/Resource/SimpleResourceContainer.h"
#include "Hedgehog/Resource/StaticResourceContainer.h"
#include "Hedgehog/Resource/DynamicResourceContainer.h"
#include "Hedgehog/Resource/Packfile.h"
#include "Hedgehog/Resource/ResourceLoader.h"
#include "Hedgehog/Resource/ResourceManagerRelatedUnk1.h"
#include "Hedgehog/Resource/ResourceManager.h"
#include "Hedgehog/Resource/ResourceResolver.h"
#include "Hedgehog/Resource/FilePathResolverUtil.h"
#include "Hedgehog/Resource/FileCache.h"
#include "Hedgehog/Resource/FileLoader.h"

#include "Hedgehog/Game/ObjectId.h"

// Hedgehog Reflection Library
#include "Hedgehog/Reflection/RflSystem.h"
#include "Hedgehog/Reflection/hhRflTypeInfo.h"
#include "Hedgehog/Reflection/hhRflTypeInfoRegistry.h"
#include "Hedgehog/Reflection/hhRflClassNameRegistry.h"
#include "Hedgehog/Reflection/hhBuiltinTypeRegistry.h"
#include "Hedgehog/Reflection/DeepCopier.h"
#include "Hedgehog/Reflection/ResReflection.h"

#include "Heuristics/Reflection.h"

#include "Hedgehog/Rsdx/rsdx_noncopyable.h"
#include "Hedgehog/Needle/Utility/Binhash.h"
#include "Hedgehog/Needle/Types.h"
#include "Hedgehog/Needle/Rectangle.h"
#include "Hedgehog/Needle/Box.h"
#include "Hedgehog/Needle/EntryLink.h"
#include "Hedgehog/Needle/RsFlagMask.h"
#include "Hedgehog/Needle/CScratchMemoryContext.h"
#include "Hedgehog/Needle/NeedleObject.h"
#include "Hedgehog/Needle/NeedleRefcountObject.h"
#include "Hedgehog/Needle/Utility/intrusive_ptr.h"
#include "Hedgehog/Needle/NeedleSStr.h"
#include "Hedgehog/Needle/NeedleRefcountResource.h"
#include "Hedgehog/Needle/TNeedleRefcountResource.h"
#include "Hedgehog/Needle/TNeedleRefcountUniqueObjectBase.h"
#include "Hedgehog/Needle/CNameIDObject.h"
#include "Hedgehog/Needle/CNameIDObjectStatic.h"
#include "Hedgehog/Needle/SRawImageInfo.h"
#include "Hedgehog/Needle/ParameterValue.h"
#include "Hedgehog/Needle/MirageResource.h"
#include "Hedgehog/Needle/SurfaceBase.h"
#include "Hedgehog/Needle/Texture.h"
#include "Hedgehog/Needle/Buffer.h"
#include "Hedgehog/Needle/ConstantBuffer.h"
#include "Hedgehog/Needle/VertexShader.h"
#include "Hedgehog/Needle/PixelShader.h"
#include "Hedgehog/Needle/ComputeShader.h"
#include "Hedgehog/Needle/VertexLayout.h"
#include "Hedgehog/Needle/RenderTarget.h"
#include "Hedgehog/Needle/UnorderedAccessView.h"
#include "Hedgehog/Needle/DepthStencil.h"
#include "Hedgehog/Needle/MaterialResource.h"
#include "Hedgehog/Needle/MeshResource.h"
#include "Hedgehog/Needle/Model.h"
#include "Hedgehog/Needle/ModelInstance.h"
#include "Hedgehog/Needle/PBRModelInstance.h"
#include "Hedgehog/Needle/RenderingCommandList.h"
#include "Hedgehog/Needle/DisplaySwapDevice.h"

#include "Hedgehog/Needle/ViewportSetting.h"
#include "Hedgehog/Needle/UnorderedAccessViewsSetting.h"
#include "Hedgehog/Needle/RenderTargetsSetting.h"
#include "Hedgehog/Needle/SamplerStateSetting.h"

#include "Hedgehog/Needle/RenderingDeviceContext.h"
#include "Hedgehog/Needle/RenderingDevice.h"
#include "Hedgehog/Needle/ParameterValueObjectContainer.h"
#include "Hedgehog/Needle/PrimitiveRenderer.h"
#include "Hedgehog/Needle/Renderable.h"
#include "Hedgehog/Needle/FxCamera.h"
#include "Hedgehog/Needle/SceneContext.h"
#include "Hedgehog/Needle/SceneContextManager.h"
#include "Hedgehog/Needle/SupportFX.h"
#include "Hedgehog/Needle/SceneParamContainer.h"
#include "Hedgehog/Needle/RenderingPipeline.h"
#include "Hedgehog/Needle/GatherRenderingPassContext.h"
#include "Hedgehog/Needle/WorldRenderingPipelineExecContext.h"
#include "Hedgehog/Needle/WorldRenderingPipeline.h"
#include "Hedgehog/Needle/RenderTexturePipeline.h"
// #include "Hedgehog/Needle/RenderingPipelineRangers.h"
#include "Hedgehog/Needle/RenderUnit.h"
#include "Hedgehog/Needle/RenderTexture.h"

#include "Hedgehog/Needle/ImplDX11/Types.h"
#include "Hedgehog/Needle/ImplDX11/NeedleResourceContainer.h"
// #include "Hedgehog/Needle/ImplDX11/SDevStatus.h"
#include "Hedgehog/Needle/ImplDX11/CmdNeedleRefcountObject.h"
#include "Hedgehog/Needle/ImplDX11/TextureDX11Impl.h"
#include "Hedgehog/Needle/ImplDX11/BufferDX11Impl.h"
#include "Hedgehog/Needle/ImplDX11/ShaderDX11Impl.h"
#include "Hedgehog/Needle/ImplDX11/VertexLayoutImpl.h"
#include "Hedgehog/Needle/ImplDX11/SResourceInfo.h"
#include "Hedgehog/Needle/ImplDX11/SResourceContext.h"
#include "Hedgehog/Needle/ImplDX11/SShaderContext.h"
#include "Hedgehog/Needle/ImplDX11/DevicUniqueObjectContainerDX11.h"
#include "Hedgehog/Needle/ImplDX11/SFlushParameterContext.h"
#include "Hedgehog/Needle/ImplDX11/SParameterQueue.h"
#include "Hedgehog/Needle/ImplDX11/SParameterBuffer.h"
#include "Hedgehog/Needle/ImplDX11/DisplaySwapDeviceDX11.h"
#include "Hedgehog/Needle/ImplDX11/RenderingDeviceDispatchDX11.h"
#include "Hedgehog/Needle/ImplDX11/DeviceObjectDX11.h"
#include "Hedgehog/Needle/ImplDX11/RenderingDeviceContextDX11.h"
#include "Hedgehog/Needle/ImplDX11/RenderingDeviceDX11.h"

#include "Hedgehog/GraphicsFoundation/ResTexture.h"
#include "Hedgehog/GraphicsFoundation/ResVertexShader.h"
#include "Hedgehog/GraphicsFoundation/ResFragmentShader.h"
#include "Hedgehog/GraphicsFoundation/Renderable.h"
#include "Hedgehog/GraphicsFoundation/RenderableContainer.h"
#include "Hedgehog/GraphicsFoundation/ViewportData.h"
#include "Hedgehog/GraphicsFoundation/SharedDebugDrawResource.h"
#include "Hedgehog/GraphicsFoundation/SharedDebugDrawResourceNeedle.h"
#include "Hedgehog/GraphicsFoundation/DrawContext.h"
#include "Hedgehog/GraphicsFoundation/DrawContextNeedle.h"
#include "Hedgehog/GraphicsFoundation/GraphicsGeometry.h"
#include "Hedgehog/GraphicsFoundation/GraphicsGeometryNeedle.h"
#include "Hedgehog/GraphicsFoundation/GraphicsContext.h"
#include "Hedgehog/GraphicsFoundation/DrawSystem.h"
#include "Hedgehog/GraphicsFoundation/DrawSystemNeedle.h"

#include "Hedgehog/Font/ResBitmapFont.h"
#include "Hedgehog/Font/ResScalableFontSet.h"
#include "Hedgehog/Font/TextListener.h"
#include "Hedgehog/Font/FontContainer.h"

// Hedgehog Framework
#include "Hedgehog/Framework/LocalHeap.h"
#include "Hedgehog/Framework/EventStack.h"
#include "Hedgehog/Framework/Window.h"
#include "Hedgehog/Framework/WindowD3D11.h"
#include "Hedgehog/Framework/FrameworkEnvironment.h"
#include "Hedgehog/Framework/BaseFramework.h"
#include "Hedgehog/Framework/FrameworkWin32.h"
#include "Hedgehog/Framework/Framework.h"
#include "Hedgehog/Framework/AppModule.h"
#include "Hedgehog/Framework/Application.h"

// HID
#include "Hedgehog/HID/InputDevice.h"
#include "Hedgehog/HID/InputDeviceFactory.h"
#include "Hedgehog/HID/ActiveDeviceManager.h"
#include "Hedgehog/HID/InputMap.h"

// #include "Hedgehog/HID/InputDevices/Keyboard.h"
// #include "Hedgehog/HID/InputDevices/KeyboardWin32.h"
#include "Hedgehog/HID/InputDevices/Mouse.h"
#include "Hedgehog/HID/InputDevices/MouseWin32.h"
// #include "Hedgehog/HID/InputDevices/Gamepad.h"
// #include "Hedgehog/HID/InputDevices/GamepadSteam.h"
// #include "Hedgehog/HID/InputDevices/Pointing.h"
// #include "Hedgehog/HID/InputDevices/PointingWin32.h"
// #include "Hedgehog/HID/InputDevices/Vibration.h"
// #include "Hedgehog/HID/InputDevices/VibrationWin32.h"

#include "Hedgehog/HID/DeviceManager.h"
#include "Hedgehog/HID/DeviceManagerWin32.h"

#include "Hedgehog/Game/GameService.h"
#include "Hedgehog/Game/GOComponent.h"
#include "Hedgehog/Game/GameObject.h"
#include "Hedgehog/Game/GameObjectLayer.h"
#include "Hedgehog/Game/GameManager.h"
#include "Hedgehog/Game/GameJobQueue.h"
#include "Hedgehog/Game/GameUpdater.h"
#include "Hedgehog/Game/BucketedGameUpdater.h"
#include "Hedgehog/Game/GameApplication.h"
#include "Hedgehog/Game/InputManager.h"
#include "Hedgehog/Game/InputComponent.h"
#include "Hedgehog/Game/CameraComponent.h"
#include "Hedgehog/Game/CameraManager.h"
#include "Hedgehog/Game/ObjInfo.h"
#include "Hedgehog/Game/ObjInfoContainer.h"
#include "Hedgehog/Game/GameObjectRegistry.h"
#include "Hedgehog/Game/GOComponentRegistry.h"
#include "Hedgehog/Game/ObjInfoRegistry.h"
#include "Hedgehog/Game/GameObjectSystem.h"
#include "Hedgehog/Game/ResObjectWorld.h"
#include "Hedgehog/Game/ObjectMap.h"
#include "Hedgehog/Game/ObjectDataAccessor.h"
#include "Hedgehog/Game/WorldObjectStatus.h"
#include "Hedgehog/Game/ObjectWorldChunk.h"
#include "Hedgehog/Game/ObjectWorldChunkLayer.h"
#include "Hedgehog/Game/ObjectWorldChunk.def.h"
#include "Hedgehog/Game/ObjectWorldExtension.h"
#include "Hedgehog/Game/ObjectWorld.h"
#include "Hedgehog/Game/FreeCamera.h"

#include "Hedgehog/Game/GOComponents/GOCInput.h"
#include "Hedgehog/Game/GOComponents/GOCTransform.h"

#include "Hedgehog/GraphicsFoundation/RenderManagerBase.h"

#include "Hedgehog/Graphics/NeedleRenderer.h"
#include "Hedgehog/Graphics/RenderingWorld.h"
#include "Hedgehog/Graphics/RenderingComponent.h"
// #include "Hedgehog/Graphics/Components/CriComponent.h"
// #include "Hedgehog/Graphics/Components/LightComponent.h"
// #include "Hedgehog/Graphics/Components/CaptureComponent.h"
// #include "Hedgehog/Graphics/Components/ScreenShotComponent.h"
#include "Hedgehog/Graphics/RenderingEngine.h"
#include "Hedgehog/Graphics/RenderingEngineNeedle.h"
// #include "Hedgehog/Graphics/RenderingEngineRangers.h"
#include "Hedgehog/Graphics/RenderManager.h"
#include "Hedgehog/Graphics/ResMaterial.h"
#include "Hedgehog/Graphics/GOCVisual.h"
#include "Hedgehog/Graphics/GOCVisualTransformed.h"
#include "Hedgehog/Graphics/GOCVisualModel.h"
#include "Hedgehog/Graphics/GOCVisualDebugDraw.h"
#include "Hedgehog/Graphics/GOCOcclusionCapsule.h"
#include "Hedgehog/Graphics/VisualManager.h"
#include "Hedgehog/Graphics/VisibilityManager.h"
#include "Hedgehog/Graphics/FxParamEditor.h"
#include "Hedgehog/Graphics/ResModelParameterInterface.h"
#include "Hedgehog/Graphics/ResModelBase.h"
#include "Hedgehog/Graphics/ResModelNeedle.h"
#include "Hedgehog/Graphics/ResModel.h"
#include "Hedgehog/Graphics/ResTerrainModel.h"
#include "Hedgehog/Graphics/ResModelInstanceInfo.h"
#include "Hedgehog/Graphics/ResMirageTerrainInstanceInfo.h"
#include "Hedgehog/Graphics/ResMirageLight.h"
#include "Hedgehog/Graphics/ResMirageLightField.h"
#include "Hedgehog/Graphics/ResDecal.h"
#include "Hedgehog/Graphics/ResProbe.h"

#include "Hedgehog/Effect/ResEffect.h"

#include "Hedgehog/Sound/ResAtomConfig.h"
#include "Hedgehog/Sound/ResAtomCueSheet.h"

#include "Hedgehog/Text/ResText.h"
#include "Hedgehog/Text/ResTextMeta.h"
#include "Hedgehog/Text/ResTextProject.h"

#include "Hedgehog/Physics/ShapeHolder.h"
#include "Hedgehog/Physics/EventQueue.h"
#include "Hedgehog/Physics/GOCCollider.h"
#include "Hedgehog/Physics/GOCSphereCollider.h"
#include "Hedgehog/Physics/GOCBoxCollider.h"
#include "Hedgehog/Physics/GOCCapsuleCollider.h"
#include "Hedgehog/Physics/GOCCylinderCollider.h"
#include "Hedgehog/Physics/GOCMeshCollider.h"
#include "Hedgehog/Physics/PhysicsWorld.h"
#include "Hedgehog/Physics/PhysicsWorldHavok.h"
// #include "Hedgehog/Physics/PhysicsViewerContext.h"
// #include "Hedgehog/Physics/PhysicsViewerBase.h"
// #include "Hedgehog/Physics/PhysicsMousePickingViewer.h"
// #include "Hedgehog/Physics/PhysicsPickedObjectViewer.h"

#include "Hedgehog/Path/ResPathObject.h"
#include "Hedgehog/Path/PathComponent.h"
#include "Hedgehog/Path/PathCollisionHandler.h"
#include "Hedgehog/Path/PathManager.h"
#include "Hedgehog/Path/PathEvaluator.h"

#include "Hedgehog/Debug/Messages.h"

#include "Hedgehog/Scene/ResScene.h"
#include "Hedgehog/Scene/SceneObject.h"
#include "Hedgehog/Scene/SceneNode.h"
#include "Hedgehog/Scene/ObjectInfo.h"
#include "Hedgehog/Scene/SceneNodeBuilder.h"
#include "Hedgehog/Scene/SceneAnimation.h"
#include "Hedgehog/Scene/SceneBuilder.h"
#include "Hedgehog/Scene/SceneControl.h"
#include "Hedgehog/Scene/SceneManager.h"

#include "SurfRide/Types.h"
#include "SurfRide/Allocator.h"
#include "SurfRide/Base.h"
#include "SurfRide/ReferencedObject.h"
#include "SurfRide/UserData.h"
#include "SurfRide/Textures/Crop.h"
#include "SurfRide/Textures/Texture.h"
#include "SurfRide/Textures/TextureData.h"
#include "SurfRide/Textures/TextureList.h"
#include "SurfRide/Transform.h"
#include "SurfRide/Cell.h"
#include "SurfRide/Text.h"
#include "SurfRide/Camera.h"
#include "SurfRide/Effects/Blur.h"
#include "SurfRide/Effects/Reflect.h"
#include "SurfRide/Casts/Cast.h"
#include "SurfRide/Casts/ImageCast.h"
#include "SurfRide/Casts/ReferenceCast.h"
#include "SurfRide/Casts/SliceCast.h"
#include "SurfRide/Layer.h"
#include "SurfRide/Scene.h"
#include "SurfRide/Project.h"
#include "SurfRide/Calc.h"
#include "SurfRide/BinaryData.h"

#include "Hedgehog/UI/SurfRideTextureDataMIRAGE.h"
#include "Hedgehog/UI/ResSurfRideProject.h"
#include "Hedgehog/UI/SurfRideProjectContext.h"
#include "Hedgehog/UI/SurfRideHandle.h"
#include "Hedgehog/UI/Types.h"
#include "Hedgehog/UI/GOCSprite.h"
// #include "Hedgehog/UI/LayerController.h"
// #include "Hedgehog/UI/TextListenerObject.h"
// #include "Hedgehog/UI/UITextInterface.h"
// #include "Hedgehog/UI/TextObjectUpdater.h"
// #include "Hedgehog/UI/GOCUICollider.h"
// #include "Hedgehog/UI/GOCUIComposition.h"
// #include "Hedgehog/UI/UIObject.h"
// #include "Hedgehog/UI/UIElementBase.h"
// #include "Hedgehog/UI/UIElement.h"
// #include "Hedgehog/UI/UIElementGroup.h"
// #include "Hedgehog/UI/UIElementGroupContainer.h"
// #include "Hedgehog/UI/UITextElement.h"
// #include "Hedgehog/UI/CastTextContainer.h"
// #include "Hedgehog/UI/UIPanel.h"
// #include "Hedgehog/UI/UIStackPanel.h"
// #include "Hedgehog/UI/UIGridPanel.h"
// #include "Hedgehog/UI/UIScrollBarElement.h"
// #include "Hedgehog/UI/UIListViewElement.h"
// #include "Hedgehog/UI/UIListener.h"
// #include "Hedgehog/UI/UIManager.h"

#include "ApplicationCommon/Foundation/ResRflParameter.h"

#include "ApplicationCommon/Camera/Types.h"
#include "ApplicationCommon/Camera/CameraExtension.h"
#include "ApplicationCommon/Camera/CameraController.h"
#include "ApplicationCommon/Camera/CameraInterpolator.h"
#include "ApplicationCommon/Camera/CameraFrame.h"
#include "ApplicationCommon/Camera/GOCCamera.h"
#include "ApplicationCommon/Camera/Messages.h"

#include "Application/Player/CharacterId.h"
// #include "Application/Player/PlayerParameterService.h"
#include "Application/Player/GOCPlayerParameter.h"
// #include "Application/Player/GOCPlayerKinematicParams.h"
#include "Application/Graphics/ResFxColFile2.h"
#include "Application/Graphics/SceneParameters.h"
#include "Application/Graphics/FxParamManager.h"
#include "Application/Graphics/FxColManager.h"

#include "Application/ResSvCol2.h"

// #include "Application/Level/PlayerInformation.h"
#include "Application/Level/StageData.h"
#include "Application/Level/StageInfo.h"
// #include "Application/Level/LevelInfo.h"

#include "Application/Terrain/TerrainManager.h"

#include "Application/Camera/CameraBridge.h"
#include "Application/Camera/CameraService.h"

// #include "Application/VolumeTrigger.h"
// #include "Application/ObjCamera.h"
// #include "Application/ObjCameraVolume.h"

namespace warssdk::ucsl {
    inline csl::fnd::IAllocator* AllocatorSystem::get_allocator() { return hh::fnd::MemoryRouter::GetDebugAllocator(); }
	struct GameInterface {
        using AllocatorSystem = AllocatorSystem;
		using RflSystem = ::ucsl::rfl::wars;
		using RflClassNameRegistry = typename hh::fnd::RflClassNameRegistry;
		using RflTypeInfoRegistry = typename hh::fnd::RflTypeInfoRegistry;
		using GameObjectClass = typename hh::game::GameObjectClass;
		using GameObjectSystem = typename hh::game::GameObjectSystem;
		using GameObjectRegistry = typename hh::game::GameObjectRegistry;
		using GOComponentRegistry = typename hh::game::GOComponentRegistry;
	};
}
