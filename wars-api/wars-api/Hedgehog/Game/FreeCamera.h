#pragma once

namespace hh::game {
    class FreeCameraListener {
    public:
        virtual ~FreeCameraListener() = default;
        virtual void FCL_UnkFunc1();
    };

    class FreeCameraControllerBase;
    class FreeCamera : public fnd::ReferencedObject, public GameManagerListener, public GameUpdateListener {
    public:
        struct CreateInfo {
            CameraComponent::CreateInfo cameraComponentCreateInfo;
            uint32_t internalPlayerInputIndex;
            uint32_t inputPriority;
            bool captureInput;
        };

    private:
        fnd::Reference<GameManager> gameManager;
        fnd::Reference<CameraManager> cameraManager;
        fnd::Reference<InputManager> inputManager;
        fnd::Reference<CameraComponent> createdCameraComponent;
        fnd::Reference<CameraComponent> cameraComponent;
        fnd::Reference<InputComponent> inputComponent;
        fnd::Reference<FreeCameraControllerBase> controller;
        uint64_t unk1;
        CreateInfo createInfo;
        uint8_t unk2;
        csl::ut::MoveArray<void*> unk8;

    public:
        FreeCamera(const CreateInfo& createInfo);
        // void Initialize(csl::fnd::IAllocator* allocator);
        bool HasCamera();
		virtual void GameServiceRemovedCallback(GameService* gameService) override;
		virtual void PostGameUpdateCallback(GameManager* gameManager, const fnd::SUpdateInfo& updateInfo) override;

        inline void SetLocked(bool value) {
            inputComponent->SetListening(!value);
        }

        inline bool IsLocked() {
            return !inputComponent->IsListening();
        }
    };

    // class FreeCameraUnk2 {
    //     csl::math::Vector4 unk1;
    //     csl::math::Vector4 unk2;
    //     csl::math::Vector3 unk3;
    //     csl::math::Vector4 unk5;
    //     uint32_t unk6;
    //     csl::math::Vector4 unk7;

    //     FreeCameraUnk2(csl::fnd::IAllocator* allocator);
    // };

    // class FreeCameraControllerBase : public fnd::ReferencedObject {
    //     FreeCamera* camera;
    // public:
    //     FreeCameraControllerBase(csl::fnd::IAllocator* allocator);
    // };

    class FreeCameraController : public fnd::ReferencedObject, public FreeCameraListener {
        void* unk1;
        gfnd::ViewportData viewportData;
        // FreeCameraUnk2 unk3;
        float unk4;
        float unk5;
        float unk6;
        float unk7;
        float unk8;
        float unk9;
        csl::ut::MoveArray<void*> unk10;
        uint32_t unk11;
        bool unk12;
        float unk13;
        uint16_t unk14;
    public:
        FreeCameraController();
    };
    
    // class UnkPadFreeCameraController : public PadFreeCameraController {
    //     uint64_t unk101; // set from unk6 on defaultcontroller
    //     csl::math::Vector4 unk102;
    // public:
    //     UnkPadFreeCameraController(csl::fnd::IAllocator* allocator);
    // };

    // class ArcBallCameraController : public fnd::ReferencedObject {
    // public:
    //     struct CreateInfo {
    //         uint32_t resX;
    //         uint32_t resY;
    //         float unk1;
    //         csl::math::Vector4 unk2;
    //         float unk3;
    //         float unk4;
    //         float unk5;
    //         uint32_t axisMonitorOffset;
    //         uint32_t actionMonitorOffset;
    //     };
    // private:
    //     CreateInfo createInfo;
    //     fnd::Reference<InputComponent> inputComponent; // set in ctor
    //     uint32_t unk3;
    //     float unk4;
    //     float unk5;
    //     float unk6;
    //     float unk7;
    //     csl::math::Matrix44 unk8;
    //     uint32_t unk9;
    //     char unk10;

    // public:
    //     ArcBallCameraController(csl::fnd::IAllocator* allocator, const CreateInfo& createInfo, InputComponent* inputComponent);
    // };

    // class DefaultFreeCameraController : public FreeCameraControllerBase {
    //     fnd::Reference<UnkPadFreeCameraController> padController;
    //     fnd::Reference<ArcBallCameraController> arcBallController;
    //     bool unk4;
    //     bool unk5; // comes from unk4 on freeCamera createinfo
    //     uint64_t unk6;
    // public:
    //     DefaultFreeCameraController(csl::fnd::IAllocator* allocator);
    // };

    class DebugCameraManager : public fnd::ReferencedObject, public csl::fnd::Singleton<DebugCameraManager>, public FreeCameraListener {
    public:
        struct DebugCameraInitInfo {
            uint32_t inputPriority;
            uint32_t playerInputIndex;
            bool captureInput;
            const char* debugCameraName;
        };

    private:
        fnd::Reference<FreeCamera> camera;
        csl::ut::MoveArray<void*> maybeListeners{ GetAllocator() };
        uint64_t unk2;
        char unk3;
    public:
        bool isActive;
        virtual void FCL_UnkFunc1() override;
        DebugCameraManager() : fnd::ReferencedObject{} {}
        static DebugCameraManager* Create() {
            return new (hh::fnd::MemoryRouter::GetModuleAllocator()) DebugCameraManager();
        }
        void ActivateDebugCamera(const DebugCameraInitInfo& initInfo);
        void DeactivateDebugCamera();
        inline FreeCamera* GetCamera() {
            return camera;
        }
    };
}
