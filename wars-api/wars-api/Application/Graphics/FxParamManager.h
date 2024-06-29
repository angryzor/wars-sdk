#pragma once

namespace app::gfx {
    class FxParamManager
        : public hh::game::GameService
        , public hh::game::GameManagerListener
        , public hh::fw::FrameworkFrameListener {
    public:
        class InterpolatorBase : public hh::fnd::ReferencedObject {
        public:
            InterpolatorBase(csl::fnd::IAllocator* allocator);
            virtual void Update(float deltaTime) = 0;
            virtual void SetTweenPosition(uint64_t ownerId, float position) = 0;
            virtual void UpdateInterpolationGroup(unsigned int value) = 0;
            virtual void AddJob(uint64_t ownerId, const void* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime, uint32_t unk6Param) = 0;
            virtual void ReverseJob(uint64_t ownerId, float interpolationTime) = 0;
            virtual bool NeedsUpdate() = 0;
        };

        template<typename T>
        class InterpolatorT : public InterpolatorBase {
            struct Unk1 {
                T parameters;
                uint64_t ownerId;
                unsigned int interpolationGroupMemberBits;
                unsigned int priority;
                float currentTweenPosition;
                float tweenPositionIncrementPerSecond;
                uint32_t unk6;
            };
        public:
            T* target;
            void (*interpolationFunction)(T* target, T* lower, T* upper, unsigned int flags, float delta);
            uint64_t pad;
            csl::ut::InplaceMoveArray<Unk1, 4> interpolationJobs;
            unsigned int interpolationGroupEnabledBits; // bit nr = index of group

            InterpolatorT(csl::fnd::IAllocator* allocator, T* target);
            virtual void Update(float deltaTime) override;
            virtual void SetTweenPosition(uint64_t ownerId, float position) override;
            virtual void AddJob(uint64_t ownerId, const void* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime, uint32_t unk6Param) override;
            virtual void ReverseJob(uint64_t ownerId, float interpolationTime) override;
            virtual bool NeedsUpdate() override;
        };

        template<typename T, size_t bucketCount>
        class Interpolator : public InterpolatorT<T> {
            virtual void UpdateInterpolationGroup(unsigned int value) override;
        };

        struct NeedleFXParameterInterpolators {
            Interpolator<hh::FxBloomParameter, 1>* bloomInterpolator;
            Interpolator<hh::FxDOFParameter, 1>* dofInterpolator;
            Interpolator<csl::ut::Enum<hh::NeedleFxParameter::ToneMapType, signed char>, 5>* toneMapTypeInterpolator;
            Interpolator<csl::ut::Enum<hh::NeedleFxParameter::ExposureMode, signed char>, 0>* exposureModeInterpolator;
            Interpolator<hh::FxColorContrastParameter, 1>* colorContrastInterpolator;
            Interpolator<hh::FxToneMapParameter, 5>* toneMapInterpolator;
            Interpolator<hh::FxExposureParameter, 0>* exposureInterpolator;
            Interpolator<hh::FxShadowMapParameter, 1>* shadowMapInterpolator;
            Interpolator<hh::FxScreenBlurParameter, 0>* blurInterpolator;
            Interpolator<hh::FxSSAOParameter, 0>* ssaoInterpolator;
            Interpolator<hh::FxLightFieldParameter, 0>* lightFieldInterpolator;
            Interpolator<hh::FxSHLightFieldParameter, 0>* shLightFieldInterpolator;
            Interpolator<hh::FxLightScatteringParameter, 0>* lightScatteringInterpolator;
            Interpolator<hh::FxRLRParameter, 1>* rlrInterpolator;
            Interpolator<hh::FxOcclusionCapsuleParameter, 0>* occlusionCapsuleInterpolator;
            Interpolator<hh::FxGodrayParameter, 0>* godrayInterpolator;
            Interpolator<hh::FxScreenSpaceGodrayParameter, 0>* ssGodrayInterpolator;
            Interpolator<hh::FxHeatHazeParameter, 0>* heatHazeInterpolator;
            Interpolator<hh::FxSceneEnvironmentParameter, 0>* sceneEnvironmentInterpolator;
            Interpolator<hh::FxRenderOption, 0>* renderOptionInterpolator;
            Interpolator<hh::FxSGGIParameter, 0>* sggiInterpolator;
            Interpolator<hh::FxTAAParameter, 0>* taaInterpolator;
            Interpolator<hh::FxEffectParameter, 0>* effectInterpolator;
        };

        hh::NeedleFxParameter parameters;
        NeedleFXParameterInterpolators paramInterpolators;
        uint32_t unk1;
        uint64_t unk2;
        uint64_t unk3;
        uint32_t unk4;
        void* effectManager;
        uint8_t unk5;

    protected:
        bool UpdateNeedleFxParameterInterpolators();

    public:
        virtual void* GetRuntimeTypeInfo() override;
        virtual void OnAddedToGame() override;
        virtual void OnRemovedFromGame() override;
		virtual void GameServiceAddedCallback(GameService* gameService) override;
		virtual void GameServiceRemovedCallback(GameService* gameService) override;
        virtual void FFL_UnkFunc3() override;

        // void SetSceneParameters(SceneParameters* parameters, int idx);

        void AddNeedleFxParameterInterpolationJob(uint64_t ownerId, hh::NeedleFxParameter* needleFxParameter, unsigned int priority, float interpolationTime);
        void AddDefaultNeedleFxParameterInterpolationJob(hh::NeedleFxParameter* needleFxParameter, unsigned int priority);
        void UpdateDefaultNeedleFxParameterInterpolationJob(hh::NeedleFxParameter* needleFxParameter);
        void UpdateNeedleFxParameterInterpolationJob(uint64_t ownerId, hh::NeedleFxParameter* needleFxParameter);
        void RemoveNeedleFxParameterInterpolationJob(uint64_t ownerId, float interpolationTime);
        //  {
        //     this->mutex.Lock();
        //     paramInterpolators.bloomInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.dofInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.colorContrastInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.tonemapInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.cameraControlInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.shadowmapInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.shadowHeightMapInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.volShadowInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.blurInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.ssaoInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.shlightfieldInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.lightscatteringInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.rlrInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.ssgiInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.planarReflectionInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.occlusionCapsuleInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.godrayInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.ssGodrayInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.heatHazeInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.sceneEnvInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.renderOptionInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.sggiInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.taaInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.effectInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.atmosphereInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.densityInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.windInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.gpuEnvironmentInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.interactiveWaveInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.chromaticAberrationInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.vignetteInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.terrainBlendInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.weatherInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.colorAccessibilityInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.cyberNoiseInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.cyberStartNoiseInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.cyberNPCSSInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.dentInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.fieldScanInterpolator->ReverseJob(ownerId, interpolationTime);
        //     paramInterpolators.ssssInterpolator->ReverseJob(ownerId, interpolationTime);
        //     this->mutex.Unlock();
        //     // updated |= UpdateNeedleFxParameterInterpolators();
        // }

		GAMESERVICE_CLASS_DECLARATION_INLINE_GETCLASS(FxParamManager)
    };
}
