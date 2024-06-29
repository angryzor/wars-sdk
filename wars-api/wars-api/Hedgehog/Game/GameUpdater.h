#pragma once

namespace hh::anim {
    class AnimationInterface;
};

namespace hh::game {
    class GameUpdater : public fnd::ReferencedObject {
    public:
        struct SetupInfo {
            GameManager* gameManager;
            uint32_t layersActiveDuringNormalOperation;
            uint32_t layersActiveDuringIngamePause;
            uint32_t layersActiveDuringDebugPause;
            uint32_t layersActiveDuringObjectPause;
        };

        enum class Flags : uint8_t {
            INGAME_PAUSE = 0,
            DEBUG_PAUSE = 1,
            DEBUG_STEP_FRAME = 4,
            OBJECT_PAUSE = 5,
        };

        struct Unk1 {
            struct Unk3 {
                csl::ut::MoveArray<void*> unk1;
                csl::ut::MoveArray<void*> unk2;
                csl::ut::MoveArray<void*> unk3;
            };

            Unk3 unk2[32];
            void* unk7[2]; // function pointers assigned in constructor
        public:
            Unk1(csl::fnd::IAllocator* allocator);
        };

    // private:
        csl::ut::Bitset<Flags> flags;
        uint32_t layersActiveDuringNormalOperation;
        uint32_t layersActiveDuringIngamePause;
        uint32_t layersActiveDuringDebugPause;
        uint32_t layersActiveDuringObjectPause;
        float unk1;
        float timeScale; // 1.0f = normal
        float layerTimeScale[32];
        GameManager* gameManager;
        fnd::Reference<anim::AnimationInterface> animationInterface;
        GameJobQueue* jobQueue;
        Unk1 unk7;
    
    public:
        GameUpdater(const SetupInfo& setupInfo);

        virtual void* DoStep(const GameStepInfo& stepInfo);

        void Update(const fnd::SUpdateInfo& updateInfo, GameApplication* application);
        void UpdateGlobalTime(const GameStepInfo& gameStepInfo);
        void SetGlobalTimeScale(float timeScale);
        void SetLayerTimeScale(uint32_t layerMask, float timeScale);
        void ResetTimeScale(uint32_t layerMask, float timeScale);

        // inline bool GetRunning() const {
        //     return flags.test(Flags::RUNNING);
        // }

        // inline void SetRunning(bool state) {
        //     flags.set(Flags::RUNNING, state);
        // }

        // inline void ToggleRunning() {
        //     flags.flip(Flags::RUNNING);
        // }
    };
}
