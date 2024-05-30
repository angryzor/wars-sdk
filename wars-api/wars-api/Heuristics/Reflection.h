#pragma once

namespace heur::rfl {
    struct DecoBlurParam {
        int32_t radius;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DecoBlurParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DecoBlurParam* pInstance);
        static void Clean(DecoBlurParam* pInstance);
    };
}

namespace heur::rfl {
    struct DecoGradationParam {
        enum class Orientation : int8_t {
            ORIENTATION_NONE = 0,
            ORIENTATION_HORIZONTAL = 1,
            ORIENTATION_VERTICAL = 2,
            ORIENTATION_DIAGONAL = 3,
        };

        Orientation orientation;
        int8_t srcPosX;
        int8_t srcPosY;
        int8_t dstPosX;
        int8_t dstPosY;
        csl::ut::Color<uint8_t> srcColor;
        csl::ut::Color<uint8_t> dstColor;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DecoGradationParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DecoGradationParam* pInstance);
        static void Clean(DecoGradationParam* pInstance);
    };
}

namespace heur::rfl {
    struct DecoRimParam {
        csl::ut::Color<uint8_t> color;
        int32_t thickness;
        int32_t offsetX;
        int32_t offsetY;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DecoRimParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DecoRimParam* pInstance);
        static void Clean(DecoRimParam* pInstance);
    };
}

namespace heur::rfl {
    struct DecoPassParam {
        DecoRimParam rim;
        DecoGradationParam gradation;
        DecoBlurParam blur;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DecoPassParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DecoPassParam* pInstance);
        static void Clean(DecoPassParam* pInstance);
    };
}

namespace heur::rfl {
    struct DecoTechParam {
        enum class DecoLayerBlendOp : int8_t {
            DECO_LAYER_BLEND_OP_BLEND = 0,
            DECO_LAYER_BLEND_OP_SUBTRACT_ALPHA = 1,
        };

        csl::ut::VariableString memo;
        csl::ut::Color<uint8_t> fontColor;
        DecoGradationParam fontGradParam;
        DecoLayerBlendOp layerBlendOp;
        int32_t numPasses;
        DecoPassParam passParams[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DecoTechParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DecoTechParam* pInstance);
        static void Clean(DecoTechParam* pInstance);
    };
}

namespace heur::rfl {
    struct DecoTechParams {
        DecoTechParam params[256];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DecoTechParams* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DecoTechParams* pInstance);
        static void Clean(DecoTechParams* pInstance);
    };
}

namespace heur::rfl {
    struct DecoConfigParam {
        csl::ut::Color<uint8_t> clientColor;
        uint8_t windowAlpha;
        csl::ut::Color<uint8_t> startGradationGuideColor;
        csl::ut::Color<uint8_t> endGradationGuideColor;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DecoConfigParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DecoConfigParam* pInstance);
        static void Clean(DecoConfigParam* pInstance);
    };
}

namespace hh {
    struct FxBloomParameter {
        enum class GlareType : int8_t {
            GLARE_DISABLE = 0,
            GLARE_CAMERA = 1,
            GLARE_NATURAL = 2,
            GLARE_CHEAP_LENS = 3,
            GLARE_FILTER_CROSS_SCREEN = 4,
            GLARE_FILTER_CROSS_SCREEN_SPECTRAL = 5,
            GLARE_FILTER_SNOW_CROSS = 6,
            GLARE_FILTER_SNOW_CROSS_SPECTRAL = 7,
            GLARE_FILTER_SUNNY_CROSS = 8,
            GLARE_FILTER_SUNNY_CROSS_SPECTRAL = 9,
            GLARE_CINECAM_VERTICAL_SLITS = 10,
            GLARE_CINECAM_HORIZONTAL_SLITS = 11,
        };

        bool enable;
        float bloomThreshold;
        float bloomMax;
        float bloomScale;
        float starScale;
        int32_t ghostCount;
        float ghostScale;
        float haloScale;
        float sampleRadiusScale;
        int32_t blurQuality;
        GlareType glareType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxBloomParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxBloomParameter* pInstance);
        static void Clean(FxBloomParameter* pInstance);
    };
}

namespace hh {
    struct FxColorContrastParameter {
        enum class LutIndex : int32_t {
            LUT_INDEX_DEFAULT = 0,
            LUT_INDEX_WB = 1,
            LUT_INDEX_USER_0 = 2,
            LUT_INDEX_USER_1 = 3,
            LUT_INDEX_USER_2 = 4,
            LUT_INDEX_USER_3 = 5,
            LUT_INDEX_USER_4 = 6,
            LUT_INDEX_USER_5 = 7,
        };

        bool enable;
        float contrast;
        float dynamicRange;
        float crushShadows;
        float crushHilights;
        bool useLut;
        LutIndex lutIndex0;
        LutIndex lutIndex1;
        float blendRatio;
        float minContrast;
        bool useHlsCorrection;
        float hlsHueOffset;
        float hlsLightnessOffset;
        float hlsSaturationOffset;
        int32_t hlsColorOffset[3];
        uint8_t padding;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxColorContrastParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxColorContrastParameter* pInstance);
        static void Clean(FxColorContrastParameter* pInstance);
    };
}

namespace hh {
    struct FxDOFParameter {
        bool enable;
        bool useFocusLookAt;
        float foregroundBokehMaxDepth;
        float foregroundBokehStartDepth;
        float backgroundBokehStartDepth;
        float backgroundBokehMaxDepth;
        bool enableCircleDOF;
        float cocMaxRadius;
        float bokehRadiusScale;
        int32_t bokehSampleCount;
        float skyFocusDistance;
        float bokehBias;
        bool drawFocalPlane;
        bool enableSWA;
        float swaFocus;
        float swaFocusRange;
        float swaNear;
        float swaFar;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxDOFParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxDOFParameter* pInstance);
        static void Clean(FxDOFParameter* pInstance);
    };
}

namespace hh {
    struct FxExposureParameter {
        float exposureValue;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxExposureParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxExposureParameter* pInstance);
        static void Clean(FxExposureParameter* pInstance);
    };
}

namespace hh {
    struct FxToneMapParameter {
        float middleGray;
        float lumMax;
        float lumMin;
        float adaptedRatio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxToneMapParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxToneMapParameter* pInstance);
        static void Clean(FxToneMapParameter* pInstance);
    };
}

namespace hh {
    struct FxShadowMapParameter {
        enum class ShadowFilter : int8_t {
            SHADOW_FILTER_POINT = 0,
            SHADOW_FILTER_PCF = 1,
            SHADOW_FILTER_ESM = 2,
            SHADOW_FILTER_MSM = 3,
            SHADOW_FILTER_VSM_POINT = 4,
            SHADOW_FILTER_VSM_LINEAR = 5,
            SHADOW_FILTER_VSM_ANISO_2 = 6,
            SHADOW_FILTER_VSM_ANISO_4 = 7,
            SHADOW_FILTER_VSM_ANISO_8 = 8,
            SHADOW_FILTER_VSM_ANISO_16 = 9,
        };

        enum class ShadowRangeType : int8_t {
            SHADOW_RANGE_TYPE_CAMERA_LOOKAT = 0,
            SHADOW_RANGE_TYPE_POSITION_MANUAL = 1,
            SHADOW_RANGE_TYPE_FULL_MANUAL = 2,
        };

        enum class FitProjection : int8_t {
            FIT_PROJECTION_TO_CASCADES = 0,
            FIT_PROJECTION_TO_SCENE = 1,
        };

        enum class FitNearFar : int8_t {
            FIT_NEARFAR_ZERO_ONE = 0,
            FIT_NEARFAR_AABB = 1,
            FIT_NEARFAR_SCENE_AABB = 2,
        };

        enum class CascadeSelection : int8_t {
            CASCADE_SELECTION_MAP = 0,
            CASCADE_SELECTION_INTERVAL = 1,
        };

        bool enable;
        ShadowFilter shadowFilter;
        ShadowRangeType shadowRangeType;
        FitProjection fitProjection;
        FitNearFar fitNearFar;
        CascadeSelection cascadeSelection;
        float sceneRange;
        float sceneCenter[3];
        float manualLightPos[3];
        int32_t cascadeLevel;
        float cascadeSplits[4];
        int32_t blurQuality;
        int32_t blurSize;
        float bias;
        float fadeoutDistance;
        csl::math::Matrix44 shadowCameraViewMatrix;
        csl::math::Matrix44 shadowCameraProjectionMatrix;
        float shadowCameraNearDepth;
        float shadowCameraFarDepth;
        float shadowCameraLookAtDepth;
        bool enableShadowCamera;
        bool enableMoveLightTexelSize;
        bool enableDrawSceneAABB;
        bool enableDrawShadowFrustum;
        bool enableDrawCascade;
        bool enableDrawCameraFrustum;
        bool enablePauseCamera;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxShadowMapParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxShadowMapParameter* pInstance);
        static void Clean(FxShadowMapParameter* pInstance);
    };
}

namespace hh {
    struct FxLightFieldParameter {
        enum class ScalingType : int8_t {
            SCALING_PHOTOSHOP_FILETER = 2,
            SCALING_NONE = 3,
            SCALING_IGNORE_DATA = 4,
        };

        enum class DebugDrawType : int8_t {
            DEBUG_DRAW_TYPE_NONE = 0,
            DEBUG_DRAW_TYPE_LOOKAT = 1,
            DEBUG_DRAW_TYPE_NODE = 2,
        };

        enum class DebugColorType : int8_t {
            DEBUG_COLOR_TYPE_COLOR = 0,
            DEBUG_COLOR_TYPE_SHADOW = 1,
            DEBUG_COLOR_TYPE_LUMINANCE = 2,
        };

        ScalingType saturationScalingType;
        float saturationScalingRate;
        float luminanceScalingRate;
        bool forceUpdate;
        bool ignoreData;
        bool ignoreFinalLightColorAdjestment;
        float intensityThreshold;
        float intensityBias;
        float luminanceMax;
        float luminanceMin;
        float luminanceCenter;
        csl::math::Vector3 defaultColorUp;
        csl::math::Vector3 defaultColorDown;
        csl::math::Vector3 offsetColorUp;
        csl::math::Vector3 offsetColorDown;
        DebugDrawType debugDrawType;
        DebugColorType debugColorType;
        int32_t drawNodeStart;
        int32_t drawNodeCount;
        float debugColorScale;
        float debugBoxScale;
        float debugLookAtRange;
        bool lockLookAt;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxLightFieldParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxLightFieldParameter* pInstance);
        static void Clean(FxLightFieldParameter* pInstance);
    };
}

namespace hh {
    struct FxLightScatteringParameter {
        bool enable;
        csl::math::Vector3 color;
        float depthScale;
        float inScatteringScale;
        float rayleigh;
        float mie;
        float g;
        float znear;
        float zfar;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxLightScatteringParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxLightScatteringParameter* pInstance);
        static void Clean(FxLightScatteringParameter* pInstance);
    };
}

namespace hh {
    struct FxOcclusionCapsuleParameter {
        bool enable;
        bool enableOcclusion;
        csl::ut::Color<uint8_t> occlusionColor;
        float occlusionPower;
        bool enableSpecularOcclusion;
        float specularOcclusionPower;
        float specularOcclusionConeAngle;
        bool enableShadow;
        csl::ut::Color<uint8_t> shadowColor;
        float shadowPower;
        float shadowConeAngle;
        float cullingDistance;
        bool enableManualLight;
        int32_t manualLightCount;
        csl::math::Vector3 manualLightPos[4];
        bool debugDraw;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxOcclusionCapsuleParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxOcclusionCapsuleParameter* pInstance);
        static void Clean(FxOcclusionCapsuleParameter* pInstance);
    };
}

namespace hh {
    struct FxRLRParameter {
        bool enable;
        float num;
        float travelFadeStart;
        float travelFadeEnd;
        float borderFadeStart;
        float borderFadeEnd;
        float overrideRatio;
        float maxRoughness;
        float hizStartLevel;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxRLRParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxRLRParameter* pInstance);
        static void Clean(FxRLRParameter* pInstance);
    };
}

namespace hh {
    struct FxGodrayParameter {
        bool enable;
        csl::math::Matrix34 box;
        csl::math::Vector3 color;
        float num;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxGodrayParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxGodrayParameter* pInstance);
        static void Clean(FxGodrayParameter* pInstance);
    };
}

namespace hh {
    struct FxScreenSpaceGodrayParameter {
        bool enable;
        float num;
        float density;
        float decay;
        float threshold;
        float lumMax;
        float intensity;
        bool enableDither;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxScreenSpaceGodrayParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxScreenSpaceGodrayParameter* pInstance);
        static void Clean(FxScreenSpaceGodrayParameter* pInstance);
    };
}

namespace hh {
    struct FxEffectParameter {
        float lightFieldColorCoefficient;
        csl::math::Vector3 shadowColor;
        csl::math::Vector3 directionalLightOverwrite;
        float directionalLightIntensityOverwrite;
        bool overwriteDirectionalLight;
        bool renderWireframe;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxEffectParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxEffectParameter* pInstance);
        static void Clean(FxEffectParameter* pInstance);
    };
}

namespace hh {
    struct FxDebugScreenOption {
        enum class ViewMode : int8_t {
            VIEWMODE_RGB = 0,
            VIEWMODE_RRR = 1,
            VIEWMODE_GGG = 2,
            VIEWMODE_BBB = 3,
            VIEWMODE_AAA = 4,
        };

        enum class DebugScreenType : int8_t {
            DEBUG_SCREEN_GBUFFER0 = 0,
            DEBUG_SCREEN_GBUFFER1 = 1,
            DEBUG_SCREEN_GBUFFER2 = 2,
            DEBUG_SCREEN_GBUFFER3 = 3,
            DEBUG_SCREEN_DEPTHBUFFER = 4,
            DEBUG_SCREEN_CSM0 = 5,
            DEBUG_SCREEN_CSM1 = 6,
            DEBUG_SCREEN_CSM2 = 7,
            DEBUG_SCREEN_CSM3 = 8,
            DEBUG_SCREEN_HDR = 9,
            DEBUG_SCREEN_BLOOM = 10,
            DEBUG_SCREEN_RLR = 11,
            DEBUG_SCREEN_GODRAY = 12,
            DEBUG_SCREEN_SSAO = 13,
            DEBUG_SCREEN_CUSTOM0 = 14,
            DEBUG_SCREEN_CUSTOM1 = 15,
            DEBUG_SCREEN_CUSTOM2 = 16,
            DEBUG_SCREEN_CUSTOM3 = 17,
        };

        enum class ErrorCheckType : int8_t {
            ERROR_CHECK_NONE = 0,
            ERROR_CHECK_NAN = 1,
            ERROR_CHECK_ALBEDO = 2,
            ERROR_CHECK_NORMAL = 3,
        };

        bool enable;
        bool fullScreen;
        ViewMode viewMode;
        float exposure;
        DebugScreenType screenType;
        ErrorCheckType errorCheck;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxDebugScreenOption* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxDebugScreenOption* pInstance);
        static void Clean(FxDebugScreenOption* pInstance);
    };
}

namespace hh {
    struct FxRenderOption {
        enum class DebugViewType : int8_t {
            DEBUG_VIEW_DEFAULT = 0,
            DEBUG_VIEW_DIR_DIFFUSE = 1,
            DEBUG_VIEW_DIR_SPECULAR = 2,
            DEBUG_VIEW_AMB_DIFFUSE = 3,
            DEBUG_VIEW_AMB_SPECULAR = 4,
            DEBUG_VIEW_ONLY_IBL = 5,
            DEBUG_VIEW_ONLY_IBL_SURF_NORMAL = 6,
            DEBUG_VIEW_SHADOW = 7,
            DEBUG_VIEW_WHITE_ALBEDO = 8,
            DEBUG_VIEW_USER0 = 9,
            DEBUG_VIEW_USER1 = 10,
            DEBUG_VIEW_USER2 = 11,
            DEBUG_VIEW_USER3 = 12,
            DEBUG_VIEW_ALBEDO = 13,
            DEBUG_VIEW_ALBEDO_CHECK_OUTLIER = 14,
            DEBUG_VIEW_OPACITY = 15,
            DEBUG_VIEW_NORMAL = 16,
            DEBUG_VIEW_ROUGHNESS = 17,
            DEBUG_VIEW_AMBIENT = 18,
            DEBUG_VIEW_CAVITY = 19,
            DEBUG_VIEW_REFLECTANCE = 20,
            DEBUG_VIEW_METALLIC = 21,
            DEBUG_VIEW_LOCAL_LIGHT = 22,
            DEBUG_VIEW_SCATTERING_FEX = 23,
            DEBUG_VIEW_SCATTERING_LIN = 24,
            DEBUG_VIEW_SSAO = 25,
            DEBUG_VIEW_RLR = 26,
            DEBUG_VIEW_IBL_DIFFUSE = 27,
            DEBUG_VIEW_IBL_SPECULAR = 28,
            DEBUG_VIEW_ENV_BRDF = 29,
            DEBUG_VIEW_WORLD_POSITION = 30,
            DEBUG_VIEW_SHADING_MODEL_ID = 31,
            DEBUG_VIEW_IBL_CAPTURE = 32,
            DEBUG_VIEW_IBL_SKY_TERRAIN = 33,
            DEBUG_VIEW_WRITE_DEPTH_TO_ALPHA = 34,
        };

        enum class LocalLightCullingType : int8_t {
            LOCAL_LIGHT_CULLING_TYPE_NONE = 0,
            LOCAL_LIGHT_CULLING_TYPE_CPU_TILE = 1,
            LOCAL_LIGHT_CULLING_TYPE_GPU_TILE = 2,
        };

        enum class TextureViewType : int8_t {
            TEXTURE_VIEW_NONE = 0,
            TEXTURE_VIEW_DEPTH = 1,
            TEXTURE_VIEW_BLOOM_POWER = 2,
            TEXTURE_VIEW_BLOOM_BRIGHT = 3,
            TEXTURE_VIEW_BLOOM_FINAL = 4,
            TEXTURE_VIEW_GLARE = 5,
            TEXTURE_VIEW_LUMINANCE = 6,
            TEXTURE_VIEW_DOF_BOKEH = 7,
            TEXTURE_VIEW_DOF_BOKEH_NEAR = 8,
            TEXTURE_VIEW_SSAO_SOURCE = 9,
            TEXTURE_VIEW_DOWNSAMPLE = 10,
            TEXTURE_VIEW_CASCADED_SHADOW_MAPS_0 = 11,
            TEXTURE_VIEW_CASCADED_SHADOW_MAPS_1 = 12,
            TEXTURE_VIEW_CASCADED_SHADOW_MAPS_2 = 13,
            TEXTURE_VIEW_CASCADED_SHADOW_MAPS_3 = 14,
        };

        enum class AmbientSpecularType : int8_t {
            AMBIENT_SPECULAR_NONE = 0,
            AMBIENT_SPECULAR_SG = 1,
            AMBIENT_SPECULAR_IBL = 2,
            AMBIENT_SPECULAR_BLEND = 3,
        };

        enum class DebugScreenView : int8_t {
            DEBUG_SCREEN_VIEW_DEFAULT = 0,
            DEBUG_SCREEN_VIEW_ALL_ENABLE = 1,
            DEBUG_SCREEN_VIEW_ALL_DISABLE = 2,
        };

        DebugViewType debugViewType;
        bool clearRenderTarget;
        int32_t maxCubeProbe;
        bool enableDrawCubeProbe;
        bool enableDirectionalLight;
        bool enablePointLight;
        bool enableEffectDeformation;
        bool enableReverseDepth;
        float cullingTooSmallThrehold;
        LocalLightCullingType localLightCullingType;
        float localLightScale;
        bool debugEnableDrawLocalLight;
        TextureViewType debugTextureViewType;
        bool debugEnableOutputTextureView;
        float debugViewDepthNear;
        float debugViewDepthFar;
        AmbientSpecularType debugAmbientSpecularType;
        bool debugIBLPlusDirectionalSpecular;
        bool debugEnableSGGIVer2nd;
        bool debugEnableOcclusionCullingView;
        int32_t debugOccluderVertThreshold;
        FxDebugScreenOption debugScreen[16];
        DebugScreenView debugScreenView;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxRenderOption* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxRenderOption* pInstance);
        static void Clean(FxRenderOption* pInstance);
    };
}

namespace hh {
    struct FxHDROption {
        bool enable;
        uint8_t padding;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxHDROption* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxHDROption* pInstance);
        static void Clean(FxHDROption* pInstance);
    };
}

namespace hh {
    struct FxSGGIParameter {
        float sgStartSmoothness;
        float sgEndSmoothness;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSGGIParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSGGIParameter* pInstance);
        static void Clean(FxSGGIParameter* pInstance);
    };
}

namespace hh {
    struct FxSSAOParameter {
        bool enable;
        float intensity;
        float radius;
        float fadeoutDistance;
        float fadeoutRadius;
        float power;
        float bias;
        float occlusionDistance;
        int32_t renderTargetSizeEnumIndex;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSSAOParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSSAOParameter* pInstance);
        static void Clean(FxSSAOParameter* pInstance);
    };
}

namespace hh {
    struct FxSHLightFieldParameter {
        enum class DebugDrawType : int8_t {
            NONE = 0,
            ONLY_ENABLED = 1,
            ALL = 2,
        };

        bool enable;
        DebugDrawType debugDrawType;
        bool showSkyVisibility;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSHLightFieldParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSHLightFieldParameter* pInstance);
        static void Clean(FxSHLightFieldParameter* pInstance);
    };
}

namespace hh {
    struct FxScreenBlurParameter {
        enum class BlurType : int8_t {
            BLURTYPE_PREV_SURFACE = 0,
            BLURTYPE_RADIAL = 1,
            BLURTYPE_CAMERA = 2,
        };

        enum class FocusType : int8_t {
            FOCUSTYPE_CENTER = 0,
            FOCUSTYPE_LOOKAT = 1,
            FOCUSTYPE_USER_SETTING = 2,
        };

        bool enable;
        BlurType blurType;
        float blurPower;
        FocusType focusType;
        csl::math::Vector3 focusPosition;
        float focusRange;
        float alphaSlope;
        int32_t sampleNum;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxScreenBlurParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxScreenBlurParameter* pInstance);
        static void Clean(FxScreenBlurParameter* pInstance);
    };
}

namespace hh {
    struct FxHeatHazeParameter {
        bool enable;
        float speed;
        float scale;
        float cycle;
        float nearDepth;
        float farDepth;
        float maxHeight;
        float parallaxCorrectFactor;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxHeatHazeParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxHeatHazeParameter* pInstance);
        static void Clean(FxHeatHazeParameter* pInstance);
    };
}

namespace hh {
    struct FxSceneEnvironmentParameter {
        float wind_rotation_y;
        float wind_strength;
        float wind_noise;
        float wind_amplitude;
        float wind_frequencies[4];
        csl::math::Vector4 grass_lod_distance;
        bool enable_tread_grass;
        bool enableHighLight;
        float highLightThreshold;
        float highLightObjectAmbientScale;
        float highLightObjectAlbedoHeighten;
        float highLightCharaAmbientScale;
        float highLightCharaAlbedoHeighten;
        float highLightCharaFalloffScale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSceneEnvironmentParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSceneEnvironmentParameter* pInstance);
        static void Clean(FxSceneEnvironmentParameter* pInstance);
    };
}

namespace hh {
    struct FxTAAParameter {
        float blendRatio;
        float sharpnessPower;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxTAAParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxTAAParameter* pInstance);
        static void Clean(FxTAAParameter* pInstance);
    };
}

namespace hh {
    struct NeedleFxParameter {
        enum class ToneMapType : int8_t {
            TONEMAPTYPE_MANUAL_EXPOSURE = 0,
            TONEMAPTYPE_AUTO = 1,
        };

        enum class ExposureMode : int8_t {
            FXEXPOSUREMODE_DISNEY = 0,
            FXEXPOSUREMODE_FILMIC = 1,
        };

        FxHDROption hdrOption;
        FxRenderOption renderOption;
        FxSGGIParameter sggi;
        FxRLRParameter rlr;
        FxBloomParameter bloom;
        ToneMapType tonemapType;
        ExposureMode exposureMode;
        FxToneMapParameter tonemap;
        FxExposureParameter exposure;
        FxColorContrastParameter colorContrast;
        FxLightScatteringParameter lightscattering;
        FxDOFParameter dof;
        FxShadowMapParameter shadowmap;
        FxSSAOParameter ssao;
        FxLightFieldParameter lightfield;
        FxSHLightFieldParameter shlightfield;
        FxScreenBlurParameter blur;
        FxOcclusionCapsuleParameter occlusionCapsule;
        FxEffectParameter effect;
        FxScreenSpaceGodrayParameter ssGodray;
        FxGodrayParameter godray;
        FxHeatHazeParameter heatHaze;
        FxSceneEnvironmentParameter sceneEnv;
        FxTAAParameter taa;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(NeedleFxParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(NeedleFxParameter* pInstance);
        static void Clean(NeedleFxParameter* pInstance);
    };
}

namespace hh {
    struct FxRenderTargetSetting {
        enum class BloomRenderTargetSize : int8_t {
            RTSIZE_ONE_FOURTH = 0,
            RTSIZE_ONE_EIGHTH = 1,
            RTSIZE_ONE_SIXTEENTH = 2,
        };

        enum class DOFRenderTargetSize : int32_t {
            RTSIZE_FULL_SCALE = 0,
            RTSIZE_HALF_SCALE = 1,
            RTSIZE_QUARTER_SCALE = 2,
        };

        BloomRenderTargetSize bloomRenderTargetScale;
        DOFRenderTargetSize dofRenderTargetScale;
        int32_t shadowMapWidth;
        int32_t shadowMapHeight;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxRenderTargetSetting* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxRenderTargetSetting* pInstance);
        static void Clean(FxRenderTargetSetting* pInstance);
    };
}

namespace hh {
    struct FxAntiAliasing {
        enum class AntiAliasingType : int8_t {
            AATYPE_NONE = 0,
            AATYPE_TAA = 1,
            AATYPE_FXAA = 2,
            AATYPE_LAST = 3,
        };

        AntiAliasingType aaType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxAntiAliasing* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxAntiAliasing* pInstance);
        static void Clean(FxAntiAliasing* pInstance);
    };
}

namespace hh {
    struct NeedleFxSceneConfig {
        FxRenderTargetSetting rendertarget;
        FxAntiAliasing antialiasing;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(NeedleFxSceneConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(NeedleFxSceneConfig* pInstance);
        static void Clean(NeedleFxSceneConfig* pInstance);
    };
}

namespace hh {
    struct StageCommonParameter {
        float deadline;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageCommonParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageCommonParameter* pInstance);
        static void Clean(StageCommonParameter* pInstance);
    };
}

namespace hh {
    struct StageCameraParameter {
        float zNear;
        float zFar;
        float fovy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageCameraParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageCameraParameter* pInstance);
        static void Clean(StageCameraParameter* pInstance);
    };
}

namespace hh {
    struct StageConfig {
        StageCommonParameter common;
        StageCameraParameter camera;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageConfig* pInstance);
        static void Clean(StageConfig* pInstance);
    };
}

namespace hh {
    struct NeedleFxSceneData {
        NeedleFxSceneConfig config;
        NeedleFxParameter items[16];
        StageConfig stageConfig;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(NeedleFxSceneData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(NeedleFxSceneData* pInstance);
        static void Clean(NeedleFxSceneData* pInstance);
    };
}

namespace heur::rfl {
    struct SwayParamNode {
        bool enable;
        float gravity;
        float resist;
        float resist_decay;
        float recover;
        float recover_decay;
        float spring;
        float radius;
        float transmit;
        float inertia;
        float angle_limit;
        csl::ut::VariableString nodeName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SwayParamNode* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SwayParamNode* pInstance);
        static void Clean(SwayParamNode* pInstance);
    };
}

namespace heur::rfl {
    struct SwayParamIndivisual {
        csl::ut::VariableString idName;
        SwayParamNode nodeParam[16];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SwayParamIndivisual* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SwayParamIndivisual* pInstance);
        static void Clean(SwayParamIndivisual* pInstance);
    };
}

namespace heur::rfl {
    struct GravityFieldSpawner {
        int8_t prio;
        bool defaultON;
        bool fixed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GravityFieldSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GravityFieldSpawner* pInstance);
        static void Clean(GravityFieldSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GFieldConcaveBoxSpawner : GravityFieldSpawner {
        float x;
        float y;
        float z;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GFieldConcaveBoxSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GFieldConcaveBoxSpawner* pInstance);
        static void Clean(GFieldConcaveBoxSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GFieldConstantSpawner : GravityFieldSpawner {
        float x;
        float y;
        float z;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GFieldConstantSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GFieldConstantSpawner* pInstance);
        static void Clean(GFieldConstantSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GFieldCylinderSplineSpawner : GravityFieldSpawner {
        float radius;
        uint32_t path;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GFieldCylinderSplineSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GFieldCylinderSplineSpawner* pInstance);
        static void Clean(GFieldCylinderSplineSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GFieldFaceSplineSpawner : GFieldCylinderSplineSpawner {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GFieldFaceSplineSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GFieldFaceSplineSpawner* pInstance);
        static void Clean(GFieldFaceSplineSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GFieldHemisphereSpawner : GravityFieldSpawner {
        enum class Type : int8_t {
            TYPE_OUTER = 0,
            TYPE_INNER = 1,
        };

        float radius;
        float innerRadius;
        Type type;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GFieldHemisphereSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GFieldHemisphereSpawner* pInstance);
        static void Clean(GFieldHemisphereSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GFieldInsideCylinderSplineSpawner : GFieldCylinderSplineSpawner {
        float innerRadius;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GFieldInsideCylinderSplineSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GFieldInsideCylinderSplineSpawner* pInstance);
        static void Clean(GFieldInsideCylinderSplineSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GFieldInsidePrismSplineSpawner : GFieldCylinderSplineSpawner {
        float innerRadius;
        int8_t divide;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GFieldInsidePrismSplineSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GFieldInsidePrismSplineSpawner* pInstance);
        static void Clean(GFieldInsidePrismSplineSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GFieldOutsideCylinderSplineSpawner : GFieldCylinderSplineSpawner {
        float innerRadius;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GFieldOutsideCylinderSplineSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GFieldOutsideCylinderSplineSpawner* pInstance);
        static void Clean(GFieldOutsideCylinderSplineSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GFieldOutsidePrismSplineSpawner : GFieldCylinderSplineSpawner {
        float innerRadius;
        int8_t divide;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GFieldOutsidePrismSplineSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GFieldOutsidePrismSplineSpawner* pInstance);
        static void Clean(GFieldOutsidePrismSplineSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GFieldSphereSpawner : GravityFieldSpawner {
        float radius;
        float innerRadius;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GFieldSphereSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GFieldSphereSpawner* pInstance);
        static void Clean(GFieldSphereSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GFieldSvSplineSpawner : GravityFieldSpawner {
        uint32_t path;
        float x;
        float y;
        float z;
        float tolerance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GFieldSvSplineSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GFieldSvSplineSpawner* pInstance);
        static void Clean(GFieldSvSplineSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct BossBigZavokSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBigZavokSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBigZavokSpawner* pInstance);
        static void Clean(BossBigZavokSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct BossEggDragoonSpawner {
        uint32_t PathId;
        hh::game::ObjectId MoveLimitMobileA;
        hh::game::ObjectId MoveLimitMobileB;
        csl::ut::MoveArray32<uint32_t> BreakFloor;
        float MobileAreaMargin;
        hh::game::ObjectId MoveLimitDragoonA;
        hh::game::ObjectId MoveLimitDragoonB;
        csl::math::Vector3 StartupColliderHalfExtents;
        csl::math::Vector3 StartupColliderOffset;
        csl::math::Vector3 CameraPointPosition;
        csl::math::Vector3 CameraOffsetPosition;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossEggDragoonSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossEggDragoonSpawner* pInstance);
        static void Clean(BossEggDragoonSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggpawnSpawner {
        enum class ShotType : int8_t {
            SHOT_BOTH_HANDS = 0,
            SHOT_ONE_HAND = 1,
        };

        enum class BehaviorType : int8_t {
            TYPE_NORMAL = 0,
            TYPE_INFINITE = 1,
            TYPE_INFINITE_VIOLET = 2,
        };

        ShotType shotType;
        float approachLimit;
        float serachDistance;
        float serachAngle;
        float moveDistance;
        bool shotCoolDown;
        bool attackConst;
        float attackConstAngle;
        bool isFV;
        bool eventDriven;
        bool isGravity;
        bool isFallStart;
        bool isTreadGrass;
        bool updateMaterial;
        bool isStatic;
        BehaviorType behaviorType;
        float toSVPathDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggpawnSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggpawnSpawner* pInstance);
        static void Clean(EnemyEggpawnSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct BossFinalDeathEggRoboSpawner {
        uint32_t PathID;
        csl::math::Vector3 DebrisOffsetPos;
        hh::game::ObjectId FloorObj;
        hh::game::ObjectId BlockObj;
        hh::game::ObjectId Camera1stAtkLaserObj;
        hh::game::ObjectId Camera1stAtkMissileObj;
        hh::game::ObjectId Camera1stAtkDebrisObj;
        hh::game::ObjectId BossPoint2nd;
        hh::game::ObjectId PlayePoint2nd;
        hh::game::ObjectId Camera2ndAtkImpacktObj;
        hh::game::ObjectId Boss3rdObject;
        hh::game::ObjectId PlayePoint3rd;
        hh::game::ObjectId CrushEventPoint;
        EnemyEggpawnSpawner EggpawnSpawner;
        csl::ut::MoveArray32<uint32_t> EggpawnSpawnPointList;
        csl::ut::MoveArray32<uint32_t> ValkeenList;
        csl::ut::MoveArray32<uint32_t> ObjectList1;
        csl::ut::MoveArray32<uint32_t> ObjectList2;
        csl::ut::MoveArray32<uint32_t> ObjectList3;
        uint32_t EggpawnSpawnNum;
        bool DebugCharaChange;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossFinalDeathEggRoboSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossFinalDeathEggRoboSpawner* pInstance);
        static void Clean(BossFinalDeathEggRoboSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct BossFinalDeathEggRoboLastSpawner {
        uint32_t PathID;
        hh::game::ObjectId BoxSky;
        hh::game::ObjectId BoxRoad;
        hh::game::ObjectId CrushPos;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossFinalDeathEggRoboLastSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossFinalDeathEggRoboLastSpawner* pInstance);
        static void Clean(BossFinalDeathEggRoboLastSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite1stLayerParameter {
        uint32_t areaNo;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite1stLayerParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite1stLayerParameter* pInstance);
        static void Clean(Infinite1stLayerParameter* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite1stAttackPattern {
        enum class AttackType : int8_t {
            TYPE_NONE = 0,
            TYPE_PIPE = 1,
            TYPE_TWIST = 2,
            TYPE_RECTANGLE = 3,
            TYPE_CLOSE = 4,
        };

        int32_t hp;
        AttackType attackType[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite1stAttackPattern* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite1stAttackPattern* pInstance);
        static void Clean(Infinite1stAttackPattern* pInstance);
    };
}

namespace heur::rfl {
    struct BossInfinite1stSpawner {
        uint32_t pathID;
        uint32_t airPathID;
        uint32_t enableLayerNo;
        Infinite1stLayerParameter disableLayerNo[2];
        Infinite1stAttackPattern attackPattern[5];
        hh::game::ObjectId gFieldObject;
        hh::game::ObjectId snakeRoadObject;
        csl::ut::MoveArray32<uint32_t> copyEnableObjects;
        csl::ut::MoveArray32<uint32_t> copyDisableObjects;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossInfinite1stSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossInfinite1stSpawner* pInstance);
        static void Clean(BossInfinite1stSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite2ndLayerParameter {
        uint32_t areaNo;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite2ndLayerParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite2ndLayerParameter* pInstance);
        static void Clean(Infinite2ndLayerParameter* pInstance);
    };
}

namespace heur::rfl {
    struct BossInfinite2ndSpawner {
        uint32_t pathID;
        uint32_t enableLayerNo;
        Infinite2ndLayerParameter disableLayerNo[2];
        csl::ut::MoveArray32<uint32_t> eggpawnGenerators;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossInfinite2ndSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossInfinite2ndSpawner* pInstance);
        static void Clean(BossInfinite2ndSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjInfiniteCannonLSpawner {
        float appearRange;
        float phase;
        float speed;
        float respawnTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjInfiniteCannonLSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjInfiniteCannonLSpawner* pInstance);
        static void Clean(ObjInfiniteCannonLSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjInfiniteCannonSSpawner {
        float appearRange;
        float phase;
        float speed;
        float respawnTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjInfiniteCannonSSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjInfiniteCannonSSpawner* pInstance);
        static void Clean(ObjInfiniteCannonSSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjInfiniteEggpawnGeneratorSpawner {
        uint32_t pathID;
        float interval;
        EnemyEggpawnSpawner eggpawnSpawner;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjInfiniteEggpawnGeneratorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjInfiniteEggpawnGeneratorSpawner* pInstance);
        static void Clean(ObjInfiniteEggpawnGeneratorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3stLayerParameter {
        uint32_t areaNo;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3stLayerParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3stLayerParameter* pInstance);
        static void Clean(Infinite3stLayerParameter* pInstance);
    };
}

namespace heur::rfl {
    struct BossInfinite3rdSpawner {
        uint32_t pathID;
        uint32_t groundPathID;
        Infinite3stLayerParameter layerParams[2];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossInfinite3rdSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossInfinite3rdSpawner* pInstance);
        static void Clean(BossInfinite3rdSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct BossQueenBeetonSpawner {
        enum class Event : int8_t {
            EVENT_ON = 0,
            EVENT_OFF = 1,
        };

        hh::game::ObjectId beehive;
        csl::ut::MoveArray32<uint32_t> targets0;
        Event event0;
        float timer0;
        csl::ut::MoveArray32<uint32_t> targets1;
        Event event1;
        float timer1;
        csl::ut::MoveArray32<uint32_t> targets2;
        Event event2;
        float timer2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossQueenBeetonSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossQueenBeetonSpawner* pInstance);
        static void Clean(BossQueenBeetonSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjAzimuthOffsetDisableVolumeSpawner {
        enum class ShapeType : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
        };

        enum class BasePoint : int8_t {
            BASE_CENTER = 0,
            BASE_Z_PLANE = 1,
        };

        ShapeType shape;
        BasePoint basePoint;
        float width;
        float height;
        float depth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjAzimuthOffsetDisableVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjAzimuthOffsetDisableVolumeSpawner* pInstance);
        static void Clean(ObjAzimuthOffsetDisableVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraSpawner {
        bool IsCameraView;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraSpawner* pInstance);
        static void Clean(ObjCameraSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCamera2DSpawner : ObjCameraSpawner {
        float FovY;
        float BaseSpacePathPosition;
        float SphericalPositionX;
        float SphericalPositionY;
        float SphericalPositionZ;
        float TargetUpOffset;
        float TargetFrontOffset;
        float TargetFrontOffsetMax;
        float TargetFrontOffsetSpeedScale;
        bool IsBaseSpacePlayer;
        bool IsPositionBasePlayer;
        float TargetRightOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCamera2DSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCamera2DSpawner* pInstance);
        static void Clean(ObjCamera2DSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCamera3DSpawner : ObjCameraSpawner {
        float Fovy;
        float Distance;
        float VerticalOffset;
        float TargetPitch;
        float TargetYaw;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCamera3DSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCamera3DSpawner* pInstance);
        static void Clean(ObjCamera3DSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraClassicSpawner : ObjCameraSpawner {
        float fovy;
        float distance;
        float screenUpLimit;
        float screenDownLimit;
        bool limitViewField;
        float viewFieldBottom;
        float azimuth;
        float elevation;
        csl::math::Vector3 targetOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraClassicSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraClassicSpawner* pInstance);
        static void Clean(ObjCameraClassicSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct VolumeTriggerSpawner {
        enum class Shape : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
            SHAPE_CAPSULE = 3,
        };

        enum class BasePoint : int8_t {
            BASE_CENTER = 0,
            BASE_Z_PLANE = 1,
            BASE_X_PLANE = 2,
            BASE_Y_PLANE = 3,
        };

        enum class ColliFilter : int8_t {
            FILTER_DEFAULT = 0,
            FILTER_HITENEMY = 1,
            FILTER_ALL = 2,
        };

        Shape ShapeType;
        BasePoint basePoint;
        ColliFilter CollisionFilter;
        float CollisionWidth;
        float CollisionHeight;
        float CollisionDepth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(VolumeTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(VolumeTriggerSpawner* pInstance);
        static void Clean(VolumeTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraClassicChangeParamVolumeSpawner : VolumeTriggerSpawner {
        hh::game::ObjectId target;
        int32_t priority;
        float viewFieldBottom;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraClassicChangeParamVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraClassicChangeParamVolumeSpawner* pInstance);
        static void Clean(ObjCameraClassicChangeParamVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraClassicLimitSpawner : ObjCameraSpawner {
        uint32_t pathId;
        hh::game::ObjectId limitPointA;
        hh::game::ObjectId limitPointB;
        float fovy;
        float distance;
        float screenUpLimit;
        float screenDownLimit;
        bool limitViewField;
        float viewFieldBottom;
        float azimuth;
        float elevation;
        csl::math::Vector3 targetOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraClassicLimitSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraClassicLimitSpawner* pInstance);
        static void Clean(ObjCameraClassicLimitSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraCylindricalInnerSpawner : ObjCameraSpawner {
        float fovy;
        int32_t gravityPathID;
        float distance;
        float azimuthOffsetDeg;
        float elevationOffsetDeg;
        float gravityOffset;
        float fixBorderAngleDeg;
        float rollSensitivity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraCylindricalInnerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraCylindricalInnerSpawner* pInstance);
        static void Clean(ObjCameraCylindricalInnerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraCylindricalOuterSpawner : ObjCameraSpawner {
        int32_t gravityPathID;
        float pitch;
        float dist;
        float offset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraCylindricalOuterSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraCylindricalOuterSpawner* pInstance);
        static void Clean(ObjCameraCylindricalOuterSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraDoubleBoostSpawner : ObjCameraSpawner {
        float fovy;
        float distance;
        float distanceOutOfEnergy;
        uint32_t pathID;
        float pathOffset;
        bool reversePathFront;
        csl::math::Vector3 targetOffset;
        csl::math::Vector3 targetOffsetOutOfEnergy;
        float azimuthOffsetDeg;
        float elevationOffsetDeg;
        float sideFollowRate;
        float upFollowRate;
        float shakeOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraDoubleBoostSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraDoubleBoostSpawner* pInstance);
        static void Clean(ObjCameraDoubleBoostSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraFixSpawner : ObjCameraSpawner {
        enum class TargetType : int8_t {
            TARGETTYPE_ABS_COORD = 0,
            TARGETTYPE_LOCATOR = 1,
        };

        float Fovy;
        float ZRot;
        TargetType targetType;
        csl::math::Vector3 TargetPosition;
        hh::game::ObjectId targetID;
        bool IsRotateUpDir;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraFixSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraFixSpawner* pInstance);
        static void Clean(ObjCameraFixSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraFollowSpawner : ObjCameraSpawner {
        enum class FollowType : int8_t {
            FOLLOWTYPE_INTELLIGENT = 0,
            FOLLOWTYPE_SIMPLE = 1,
        };

        float Fovy;
        float ZRot;
        float Distance;
        float Yaw;
        float Pitch;
        csl::math::Vector3 targetOffset;
        float gravityOffset;
        csl::math::Vector3 playerOffset;
        FollowType followType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraFollowSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraFollowSpawner* pInstance);
        static void Clean(ObjCameraFollowSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraPanSpawner : ObjCameraSpawner {
        enum class PositionMode : int8_t {
            POS_MODE_FIX = 0,
            POS_MODE_MAINTAIN_DISTANCE = 1,
        };

        float fovy;
        bool enableLimitAngle;
        float azimuthLimitAngle;
        float elevationLimitAngle;
        float gravityOffset;
        csl::math::Vector3 playerOffset;
        csl::math::Vector3 worldOffset;
        PositionMode positionMode;
        float distance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraPanSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraPanSpawner* pInstance);
        static void Clean(ObjCameraPanSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraPanVerticalSpawner : ObjCameraSpawner {
        enum class PositionMode : int8_t {
            POS_MODE_FIX = 0,
            POS_MODE_MAINTAIN_DISTANCE = 1,
        };

        float fovy;
        bool enableLimitAngle;
        float azimuthLimitAngle;
        float gravityOffset;
        csl::math::Vector3 playerOffset;
        float lineOffset;
        PositionMode positionMode;
        float distance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraPanVerticalSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraPanVerticalSpawner* pInstance);
        static void Clean(ObjCameraPanVerticalSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraParallelSpawner : ObjCameraSpawner {
        float Fovy;
        float ZRot;
        uint8_t TargetType;
        hh::game::ObjectId Target;
        csl::math::Vector3 TargetPositionFix;
        float Distance;
        float Yaw;
        float Pitch;
        float TargetOffsetRight;
        float TargetOffsetUp;
        float TargetOffsetFront;
        bool IsRotateUpDir;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraParallelSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraParallelSpawner* pInstance);
        static void Clean(ObjCameraParallelSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraPointSpawner : ObjCameraSpawner {
        float fovy;
        float distance;
        float gravityOffset;
        csl::math::Vector3 playerOffset;
        csl::math::Vector3 worldOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraPointSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraPointSpawner* pInstance);
        static void Clean(ObjCameraPointSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraRailSpawner : ObjCameraSpawner {
        float fovy;
        uint32_t pathID;
        float pathOffset;
        float gravityOffset;
        csl::math::Vector3 playerOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraRailSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraRailSpawner* pInstance);
        static void Clean(ObjCameraRailSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraRailAnimationSpawner : ObjCameraSpawner {
        enum class UpDirectionType : int8_t {
            UPDIR_Y_UP = 0,
            UPDIR_OBJ_TRANSFORM = 1,
        };

        enum class Type : int8_t {
            TIME_DRIVEN = 0,
            PLAYER_POSITION_DRIVEN = 1,
            EYE_PATH_NEAREST_BASE = 2,
            AT_PATH_NEAREST_BASE = 3,
        };

        float fovy;
        UpDirectionType upDirType;
        uint32_t eyePathID;
        float eyePathOffset;
        uint32_t atPathID;
        float atPathOffset;
        Type type;
        float motionLength;
        bool reversePathAdvance;
        bool correctTargetPoint;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraRailAnimationSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraRailAnimationSpawner* pInstance);
        static void Clean(ObjCameraRailAnimationSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraRailForwardViewSpawner : ObjCameraSpawner {
        enum class PlayerOffsetType : int8_t {
            PLAYER_OFFSET_NORMAL = 0,
            PLAYER_OFFSET_ABSOLUTE = 1,
        };

        enum class FollowType : int8_t {
            FOLLOWTYPE_INTELLIGENT = 0,
            FOLLOWTYPE_SIMPLE = 1,
        };

        float fovy;
        float zRot;
        float distance;
        uint32_t pathID;
        float pathOffset;
        bool reversePathFront;
        bool usePathVerticalComponent;
        float angleSensitivity;
        float angleSensitivityBoost;
        float azimuthOffsetDeg;
        float elevationOffsetDeg;
        float gravityOffset;
        csl::math::Vector3 playerOffset;
        PlayerOffsetType playerOffsetType;
        FollowType followType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraRailForwardViewSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraRailForwardViewSpawner* pInstance);
        static void Clean(ObjCameraRailForwardViewSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraRailLookSpawner : ObjCameraSpawner {
        float fovy;
        float distance;
        uint32_t pathID;
        float pathOffset;
        float gravityOffset;
        csl::math::Vector3 playerOffset;
        csl::math::Vector3 worldOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraRailLookSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraRailLookSpawner* pInstance);
        static void Clean(ObjCameraRailLookSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraRailSideViewSpawner : ObjCameraSpawner {
        enum class ORIENTATION_MODE : int8_t {
            ORIENTATION_GRAVITY = 0,
            ORIENTATION_PATH_NORMAL = 1,
        };

        float fovy;
        float distance;
        uint32_t pathID;
        float elevation;
        float azimuth;
        float limitLeftRatio;
        float limitRightRatio;
        float upScrollRatio;
        float limitUpScrollDistance;
        float downScrollRatio;
        float limitDownScrollDistance;
        bool isLimitPathDistance;
        float limitPathDistanceMin;
        float limitPathDistanceMax;
        ORIENTATION_MODE orientationMode;
        bool isEnableAzimuthOffset;
        bool isSmoothPath;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraRailSideViewSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraRailSideViewSpawner* pInstance);
        static void Clean(ObjCameraRailSideViewSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraShakeTriggerSpawner {
        enum class Type : int8_t {
            TYPE_ONESHOT = 0,
            TYPE_CONTINUANCE = 1,
        };

        enum class ShakeType : int8_t {
            SHAKE_DIRECTIONAL = 0,
            SHAKE_RANDOM = 1,
        };

        enum class ShapeType : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
            SHAPE_EVENT = 3,
        };

        Type type;
        float shakeTime;
        float shakeRange;
        bool oneTimeOnly;
        ShakeType shakeType;
        float magnitude;
        int32_t freq;
        float zRot;
        float attnRatio;
        bool enableDistAttn;
        ShapeType shape;
        float width;
        float height;
        float depth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraShakeTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraShakeTriggerSpawner* pInstance);
        static void Clean(ObjCameraShakeTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraSliderSpawner : ObjCameraSpawner {
        float fovy;
        float distance;
        float distanceAir;
        float elevationAir;
        float angleSensitive;
        float elevationOffset;
        float pathOffset;
        float targetOffsetY;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraSliderSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraSliderSpawner* pInstance);
        static void Clean(ObjCameraSliderSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraSubVolumeSpawner {
        enum class ShapeType : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
        };

        enum class BasePoint : int8_t {
            BASE_CENTER = 0,
            BASE_Z_PLANE = 1,
        };

        hh::game::ObjectId target;
        ShapeType shape;
        BasePoint basePoint;
        float width;
        float height;
        float depth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraSubVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraSubVolumeSpawner* pInstance);
        static void Clean(ObjCameraSubVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraVerticalSpawner : ObjCameraSpawner {
        float fovy;
        float distance;
        float elevationOffsetDeg;
        float gravityOffset;
        csl::math::Vector3 playerOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraVerticalSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraVerticalSpawner* pInstance);
        static void Clean(ObjCameraVerticalSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraVolumeSpawner {
        enum class InterpolateType : int8_t {
            INTERPOLATE_RELATIVE = 0,
            INTERPOLATE_ABSOLUTE = 1,
            INTERPOLATE_ABSOLUTE_COORD = 2,
        };

        enum class StateType : int8_t {
            DEFAULTSTATE_ON = 0,
            DEFAULTSTATE_OFF = 1,
        };

        enum class ActionType : int8_t {
            ACTION_EACHTIME = 0,
            ACTION_ONCE = 1,
        };

        enum class ShapeType : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
        };

        enum class BasePoint : int8_t {
            BASE_CENTER = 0,
            BASE_Z_PLANE = 1,
        };

        hh::game::ObjectId target;
        uint32_t priority;
        bool useHighPriority;
        float easeTimeEnter;
        float easeTimeLeave;
        InterpolateType interpolateTypeEnter;
        InterpolateType interpolateTypeLeave;
        StateType state;
        ActionType action;
        ShapeType shape;
        BasePoint basePoint;
        float width;
        float height;
        float depth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraVolumeSpawner* pInstance);
        static void Clean(ObjCameraVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDefaultCameraSettingSpawner {
        hh::game::ObjectId cameraObjectID;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDefaultCameraSettingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDefaultCameraSettingSpawner* pInstance);
        static void Clean(ObjDefaultCameraSettingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFarChangeVolumeSpawner {
        enum class ShapeType : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
        };

        float farDist;
        uint32_t priority;
        ShapeType shape;
        float width;
        float height;
        float depth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFarChangeVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFarChangeVolumeSpawner* pInstance);
        static void Clean(ObjFarChangeVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct AutorunTriggerSpawner {
        enum class ActionType : int8_t {
            ACT_START = 0,
            ACT_FINISH = 1,
        };

        enum class MoveType : int8_t {
            MOVE_FREE = 0,
            MOVE_CAPTURE_PATH = 1,
        };

        ActionType action;
        MoveType move;
        float width;
        float height;
        uint32_t pathID;
        float speed;
        float outOfControlTime;
        bool forceFall;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AutorunTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AutorunTriggerSpawner* pInstance);
        static void Clean(AutorunTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBallLaunchTriggerSpawner {
        float width;
        float height;
        uint32_t pathID;
        float minSpeed;
        float maxSpeed;
        bool reverse;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBallLaunchTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBallLaunchTriggerSpawner* pInstance);
        static void Clean(ObjBallLaunchTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBallMoveTriggerSpawner {
        csl::math::Vector2 size;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBallMoveTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBallMoveTriggerSpawner* pInstance);
        static void Clean(ObjBallMoveTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBoosterSpawner {
        enum class Event : int8_t {
            EVENT_ON = 0,
            EVENT_OFF = 1,
        };

        float ocTime;
        float speed;
        bool isVisible;
        bool isDirectionPath;
        bool isForceLanding;
        csl::ut::MoveArray32<uint32_t> targets0;
        Event event0;
        float timer0;
        csl::ut::MoveArray32<uint32_t> targets1;
        Event event1;
        float timer1;
        csl::ut::MoveArray32<uint32_t> targets2;
        Event event2;
        float timer2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBoosterSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBoosterSpawner* pInstance);
        static void Clean(ObjBoosterSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBubbleGeneratorSpawner {
        float vanishHeight;
        bool isEventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBubbleGeneratorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBubbleGeneratorSpawner* pInstance);
        static void Clean(ObjBubbleGeneratorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCaptionVolumeSpawner {
        enum class ShapeType : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
        };

        int32_t id;
        ShapeType shape;
        float width;
        float height;
        float depth;
        float waitTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCaptionVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCaptionVolumeSpawner* pInstance);
        static void Clean(ObjCaptionVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCautionVolumeSpawner {
        enum class ShapeType : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
        };

        enum class CautionType : int8_t {
            CAUTIONTYPE_NONE = -1,
            CAUTIONTYPE_EXCLAMATION = 0,
            CAUTIONTYPE_QUICK_STEP = 1,
            CAUTIONTYPE_DRIFT = 2,
        };

        enum class NaviType : int8_t {
            NAVITYPE_NONE = 0,
            NAVITYPE_JUMP = 1,
            NAVITYPE_SLIDING = 2,
            NAVITYPE_BOOST = 3,
            NAVITYPE_WISPON_R = 4,
            NAVITYPE_WISPON_L = 5,
            NAVITYPE_STEP_BOTH = 6,
            NAVITYPE_STEP_L = 7,
            NAVITYPE_STEP_R = 8,
            NAVITYPE_HORMING_ATTACK = 9,
            NAVITYPE_STOMPING = 10,
            NAVITYPE_SPIN_DASH = 11,
            NAVITYPE_GRIND_MOVE = 12,
            NAVITYPE_BADDY_CHANGE = 13,
            NAVITYPE_COUNT = 14,
        };

        ShapeType shape;
        float width;
        float height;
        float depth;
        bool isHideIfInput;
        CautionType cautionType;
        NaviType naviType;
        bool isSwitch;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCautionVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCautionVolumeSpawner* pInstance);
        static void Clean(ObjCautionVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjChainFloorSpawner {
        enum class FloorSize : int8_t {
            SIZE_A = 0,
            SIZE_B = 1,
            SIZE_C = 2,
        };

        enum class RotateType : int8_t {
            ROT_LEFT = 0,
            ROT_RIGHT = 1,
        };

        enum class VisualType : int8_t {
            VISUAL_A = 0,
            VISUAL_B = 1,
            NUM_VISUAL_TYPE = 2,
        };

        float radius;
        uint32_t floorCount;
        float angularSpeed;
        float phase;
        FloorSize floorSize;
        RotateType rotateType;
        VisualType visualType;
        bool isOneway;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjChainFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjChainFloorSpawner* pInstance);
        static void Clean(ObjChainFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjClassicItemBoxSpawner {
        enum class ItemType : int8_t {
            ITEMTYPE_TENRINGS = 0,
            ITEMTYPE_HISPEED = 1,
            ITEMTYPE_INVINCIBLE = 2,
            ITEMTYPE_BARRIOR = 3,
        };

        enum class BoxType : int8_t {
            BOX_TYPE_ONGROUND = 0,
            BOX_TYPE_AIR = 1,
        };

        ItemType Type;
        BoxType BoxType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjClassicItemBoxSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjClassicItemBoxSpawner* pInstance);
        static void Clean(ObjClassicItemBoxSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjClassicSpringSpawner {
        enum class MotionType : int8_t {
            MOTION_VERTICAL = 0,
            MOTION_ANGLE = 1,
        };

        enum class ColorType : int8_t {
            YELLOW = 0,
            RED = 1,
        };

        float velocity;
        float outOfControl;
        float motionTime;
        MotionType motionType;
        ColorType colorType;
        bool isHorizon;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjClassicSpringSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjClassicSpringSpawner* pInstance);
        static void Clean(ObjClassicSpringSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjectEventData {
        enum class Event : int8_t {
            EVENT_ON = 0,
            EVENT_OFF = 1,
        };

        csl::ut::MoveArray32<uint32_t> target;
        Event eventType;
        float timer;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjectEventData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjectEventData* pInstance);
        static void Clean(ObjectEventData* pInstance);
    };
}

namespace heur::rfl {
    struct ObjClassicLinkedSpringSpawner {
        int32_t placeNum;
        float interval;
        bool isEventOn;
        ObjClassicSpringSpawner springSpawner;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjClassicLinkedSpringSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjClassicLinkedSpringSpawner* pInstance);
        static void Clean(ObjClassicLinkedSpringSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjClassicPointMarkerSpawner {
        float Dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjClassicPointMarkerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjClassicPointMarkerSpawner* pInstance);
        static void Clean(ObjClassicPointMarkerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjClassicPopupSpringSpawner {
        enum class MotionType : int8_t {
            MOTION_VERTICAL = 0,
            MOTION_ANGLE = 1,
        };

        enum class ColorType : int8_t {
            YELLOW = 0,
            RED = 1,
        };

        float velocity;
        float outOfControl;
        float motionTime;
        MotionType motionType;
        ColorType colorType;
        bool isHorizon;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjClassicPopupSpringSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjClassicPopupSpringSpawner* pInstance);
        static void Clean(ObjClassicPopupSpringSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCorrectPathVolumeSpawner {
        enum class CorrectType : int8_t {
            ALWAYS = 0,
            INPUT = 1,
        };

        csl::math::Vector3 size;
        uint32_t pathID;
        float force;
        CorrectType type;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCorrectPathVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCorrectPathVolumeSpawner* pInstance);
        static void Clean(ObjCorrectPathVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCorrectPathVolume2Spawner {
        csl::math::Vector3 size;
        uint32_t pathID;
        float force;
        float forceInPath;
        float minDistance;
        float maxDistance;
        bool correctNormal;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCorrectPathVolume2Spawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCorrectPathVolume2Spawner* pInstance);
        static void Clean(ObjCorrectPathVolume2Spawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDashPanelSpawner {
        enum class Event : int8_t {
            EVENT_ON = 0,
            EVENT_OFF = 1,
        };

        float ocTime;
        float speed;
        bool isVisible;
        bool isSideView;
        bool isDirectionPath;
        bool isForceLanding;
        csl::ut::MoveArray32<uint32_t> targets0;
        Event event0;
        float timer0;
        csl::ut::MoveArray32<uint32_t> targets1;
        Event event1;
        float timer1;
        csl::ut::MoveArray32<uint32_t> targets2;
        Event event2;
        float timer2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDashPanelSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDashPanelSpawner* pInstance);
        static void Clean(ObjDashPanelSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDashRingSpawner {
        enum class DashRingType : int8_t {
            TYPE_DASH_RING = 0,
            TYPE_RAINBOW_RING = 1,
            NUM_TYPE = 2,
        };

        DashRingType Type;
        float OutOfControl;
        float KeepVelocity;
        float Speed;
        bool VisibleModel;
        bool PosConst;
        bool VeloConst;
        bool Spin;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDashRingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDashRingSpawner* pInstance);
        static void Clean(ObjDashRingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDebugNoteSpawner {
        enum class ColorType : int8_t {
            TYPE_WHITE = 0,
            TYPE_BLACK = 1,
            TYPE_RED = 2,
            TYPE_GREEN = 3,
            TYPE_BLUE = 4,
            TYPE_YELLOW = 5,
        };

        csl::ut::VariableString memoText;
        ColorType colorType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDebugNoteSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDebugNoteSpawner* pInstance);
        static void Clean(ObjDebugNoteSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDimensionShiftVolumeSpawner : VolumeTriggerSpawner {
        int32_t pathNo;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDimensionShiftVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDimensionShiftVolumeSpawner* pInstance);
        static void Clean(ObjDimensionShiftVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDimensionVolumeSpawner {
        enum class DimensionType : int8_t {
            DIM_2D = 0,
            DIM_3D = 1,
            DIM_2D_BACK = 2,
        };

        enum class BasePoint : int8_t {
            BASE_CENTER = 0,
            BASE_Z_PLANE = 1,
        };

        enum class InterpolateType : int8_t {
            INTERPOLATE_RELATIVE = 0,
            INTERPOLATE_ABSOLUTE = 1,
        };

        float width;
        float height;
        float depth;
        DimensionType dimension;
        int32_t pathNo;
        int32_t priority;
        BasePoint basePoint;
        hh::game::ObjectId camera;
        float easeTimeEnter;
        float easeTimeLeave;
        InterpolateType interpolateTypeEnter;
        InterpolateType interpolateTypeLeave;
        bool active;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDimensionVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDimensionVolumeSpawner* pInstance);
        static void Clean(ObjDimensionVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDisableQuickStepCheckVolumeSpawner : VolumeTriggerSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDisableQuickStepCheckVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDisableQuickStepCheckVolumeSpawner* pInstance);
        static void Clean(ObjDisableQuickStepCheckVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDivingVolumeSpawner {
        enum class BasePoint : int8_t {
            BASE_CENTER = 0,
            BASE_Y_PLANE = 1,
        };

        float height;
        float width;
        float depth;
        BasePoint basePoint;
        bool limit;
        float easeTimeEnter;
        float easeTimeLeave;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDivingVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDivingVolumeSpawner* pInstance);
        static void Clean(ObjDivingVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDoubleBoostSpawner {
        uint32_t pathID;
        float autorunSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDoubleBoostSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDoubleBoostSpawner* pInstance);
        static void Clean(ObjDoubleBoostSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDoubleBoostTriggerSpawner : ObjDoubleBoostSpawner {
        enum class ActionType : int8_t {
            ACT_START = 0,
            ACT_END = 1,
            ACT_END_AUTORON = 2,
        };

        ActionType type;
        float width;
        float height;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDoubleBoostTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDoubleBoostTriggerSpawner* pInstance);
        static void Clean(ObjDoubleBoostTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDoubleBoostVolumeSpawner : ObjDoubleBoostSpawner {
        enum class BasePoint : int8_t {
            BASE_CENTER = 0,
            BASE_Z_PLANE = 1,
        };

        csl::math::Vector3 size;
        BasePoint basePoint;
        bool endToAutorun;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDoubleBoostVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDoubleBoostVolumeSpawner* pInstance);
        static void Clean(ObjDoubleBoostVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjEventSetterSpawner {
        enum class TriggerType : int8_t {
            TRIGERTYPE_DEAD = 0,
        };

        enum class ConditionType : int8_t {
            CONDITION_ALL = 0,
            CONDITION_OR = 1,
        };

        enum class Time : int8_t {
            TIMESTYPE_ONCE = 0,
            TIMESTYPE_SEVERAL = 1,
        };

        enum class EventType : int8_t {
            EVENT_ON = 0,
            EVENT_OFF = 1,
        };

        csl::ut::MoveArray32<uint32_t> TargetList;
        TriggerType Trigger;
        ConditionType Condition;
        Time TimesType;
        csl::ut::MoveArray32<uint32_t> EventList;
        EventType EventNotifier;
        float EventTimer;
        csl::ut::MoveArray32<uint32_t> EventList2;
        EventType EventNotifier2;
        float EventTimer2;
        csl::ut::MoveArray32<uint32_t> EventList3;
        EventType EventNotifier3;
        float EventTimer3;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjEventSetterSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjEventSetterSpawner* pInstance);
        static void Clean(ObjEventSetterSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFallDeadTriggerSpawner {
        enum class DrivenType : int8_t {
            DRIVE_RANGE = 0,
            DRIVE_EVENT = 1,
        };

        csl::math::Vector3 size;
        DrivenType drive;
        float distance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFallDeadTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFallDeadTriggerSpawner* pInstance);
        static void Clean(ObjFallDeadTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFanSpawner {
        enum class Type : int8_t {
            TYPE_ON = 0,
            TYPE_CYCLE = 1,
        };

        Type type;
        float length;
        float velocity;
        float onTime;
        float offTime;
        float phase;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFanSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFanSpawner* pInstance);
        static void Clean(ObjFanSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFlowEffectVolumeBaseSpawner {
        enum class EffectType : int8_t {
            EFFECTTYPE_FIRE_DUST = 0,
            EFFECTTYPE_SNOW = 1,
            EFFECTTYPE_NOISE = 2,
            EFFECTTYPE_HIDE = 3,
            EFFECTTYPE_NUM = 4,
        };

        EffectType effectType;
        bool isOnlyScreenSpace;
        uint32_t emitterCount;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFlowEffectVolumeBaseSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFlowEffectVolumeBaseSpawner* pInstance);
        static void Clean(ObjFlowEffectVolumeBaseSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFlowEffectVolumeBroadAreaSpawner : ObjFlowEffectVolumeBaseSpawner {
        float zOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFlowEffectVolumeBroadAreaSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFlowEffectVolumeBroadAreaSpawner* pInstance);
        static void Clean(ObjFlowEffectVolumeBroadAreaSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFlowEffectVolumeLocalAreaSpawner : ObjFlowEffectVolumeBaseSpawner {
        enum class Shape : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
        };

        Shape shapeType;
        uint32_t priority;
        float width;
        float height;
        float depth;
        float zOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFlowEffectVolumeLocalAreaSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFlowEffectVolumeLocalAreaSpawner* pInstance);
        static void Clean(ObjFlowEffectVolumeLocalAreaSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFootStepSpawner {
        enum class MoveType : int8_t {
            MOVE_PATH = 0,
            MOVE_STRAIGHT = 1,
        };

        csl::ut::VariableString soundName;
        MoveType moveType;
        float speed;
        uint32_t pathID;
        csl::math::Vector3 moveVector;
        bool enableMoveEnd;
        float interval;
        bool eventDriven;
        float rotZ;
        float shakeTime;
        int32_t freq;
        float magnitude;
        bool enableDistAttn;
        float attanRatio;
        float shakeRange;
        bool debug;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFootStepSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFootStepSpawner* pInstance);
        static void Clean(ObjFootStepSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGadgetVolumeSpawner {
        csl::math::Vector3 size;
        bool enable;
        int32_t priority;
        bool ui_sleep;
        bool del_asteroid;
        bool del_model;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGadgetVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGadgetVolumeSpawner* pInstance);
        static void Clean(ObjGadgetVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGismoSpawner {
        csl::ut::VariableString name;
        float scale;
        csl::ut::VariableString giTextureName;
        csl::ut::VariableString giOcclusionTextureName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGismoSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGismoSpawner* pInstance);
        static void Clean(ObjGismoSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGoalCharacterSpawner {
        enum class MotionType : int8_t {
            TYPE_A = 0,
            TYPE_B = 1,
        };

        MotionType motionType;
        float scale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGoalCharacterSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGoalCharacterSpawner* pInstance);
        static void Clean(ObjGoalCharacterSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGoalPlateSpawner : VolumeTriggerSpawner {
        hh::game::ObjectId camera;
        uint32_t cameraPriority;
        float cameraEaseTime;
        float goalTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGoalPlateSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGoalPlateSpawner* pInstance);
        static void Clean(ObjGoalPlateSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGoalTriggerSpawner : VolumeTriggerSpawner {
        enum class GoalActionType : int8_t {
            GOALACTIONTYPE_STOP = 0,
            GOALACTIONTYPE_BRAKE = 1,
            GOALACTIONTYPE_DASH = 2,
        };

        enum class PlateModelType : int8_t {
            PLATEMODEL_01 = 0,
            PLATEMODEL_02 = 1,
            NUM_PLATEMODEL = 2,
        };

        enum class PlateActionType : int8_t {
            PLATEACTION_IDLE = 0,
            PLATEACTION_PATH = 1,
        };

        enum class PlateSpeedType : int8_t {
            PLATESPEED_OWN = 0,
            PLATESPEED_PLAYER = 1,
        };

        float goalTime;
        GoalActionType actionType;
        uint32_t pathId;
        PlateModelType plateModelType;
        PlateActionType plateActionType;
        PlateSpeedType plateSpeedType;
        float plateAngle;
        csl::math::Vector3 plateOffsetTrans;
        csl::math::Vector3 plateOffsetRot;
        uint32_t platePathId;
        float plateMoveSpeed;
        float plateMoveDistance;
        float plateScale;
        uint32_t textureResolutionScale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGoalTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGoalTriggerSpawner* pInstance);
        static void Clean(ObjGoalTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGodraySpawner {
        csl::math::Vector3 color;
        csl::math::Vector3 size;
        float fadeStart;
        float fadeEnd;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGodraySpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGodraySpawner* pInstance);
        static void Clean(ObjGodraySpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGrindBoosterSpawner {
        float ocTime;
        float speed;
        bool isVisible;
        bool reverse;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGrindBoosterSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGrindBoosterSpawner* pInstance);
        static void Clean(ObjGrindBoosterSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGrindThornSpawner {
        bool reverse;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGrindThornSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGrindThornSpawner* pInstance);
        static void Clean(ObjGrindThornSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjHintRingSpawner {
        csl::ut::VariableString sheetID;
        csl::ut::VariableString cellID;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjHintRingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjHintRingSpawner* pInstance);
        static void Clean(ObjHintRingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjHomingVolumeSpawner {
        csl::math::Vector3 size;
        bool enable;
        int32_t priority;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjHomingVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjHomingVolumeSpawner* pInstance);
        static void Clean(ObjHomingVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjIBLChangeVolumeSpawner {
        enum class ShapeType : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
        };

        uint32_t iblNo;
        uint32_t priority;
        ShapeType shape;
        float width;
        float height;
        float depth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjIBLChangeVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjIBLChangeVolumeSpawner* pInstance);
        static void Clean(ObjIBLChangeVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjIronBoxSpawner {
        int32_t BoxNumX;
        int32_t BoxNumY;
        int32_t BoxNumZ;
        bool dropShadow;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjIronBoxSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjIronBoxSpawner* pInstance);
        static void Clean(ObjIronBoxSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjJumpBoardSpawner {
        enum class DrawType : int8_t {
            DRAW_NORMAL = 0,
            DRAW_RIGIDBODY = 1,
            DRAW_NOTHING = 2,
        };

        enum class SizeType : int8_t {
            SIZE_S = 0,
            SIZE_M = 1,
            SIZE_L = 2,
            SIZE_COUNT = 3,
        };

        float ImpulseSpeedOnNormal;
        float ImpulseSpeedOnBoost;
        float OutOfControl;
        float MotionTime;
        DrawType DrawType;
        SizeType SizeType;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjJumpBoardSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjJumpBoardSpawner* pInstance);
        static void Clean(ObjJumpBoardSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjJumpBoardPathSpawner {
        enum class SizeType : int8_t {
            SIZE_S = 0,
            SIZE_M = 1,
            SIZE_L = 2,
            SIZE_COUNT = 3,
        };

        float DistanceNormal;
        float DistanceBoost;
        float HeightNormal;
        float HeightBoost;
        float OutStrengthNormal;
        float OutStrengthBoost;
        float InStrengthNormal;
        float InStrengthBoost;
        float InAngleNormal;
        float InAngleBoost;
        float ImpulseSpeedOnNormal;
        float ImpulseSpeedOnBoost;
        float OutOfControlNormal;
        float OutOfControlBoost;
        float MotionTime;
        SizeType SizeType;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjJumpBoardPathSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjJumpBoardPathSpawner* pInstance);
        static void Clean(ObjJumpBoardPathSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjJumpPanelSpawner {
        float ImpulseSpeedOnNormal;
        float OutOfControl;
        float ImpulseDegree;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjJumpPanelSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjJumpPanelSpawner* pInstance);
        static void Clean(ObjJumpPanelSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct NormalSpringParameter {
        float velocity;
        float outOfControl;
        float keepVelocityDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(NormalSpringParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(NormalSpringParameter* pInstance);
        static void Clean(NormalSpringParameter* pInstance);
    };
}

namespace heur::rfl {
    struct PathSpringParameter {
        float velocity;
        float beginAngle;
        float beginForce;
        csl::math::Vector3 targetPos;
        float endAngle;
        float endForce;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PathSpringParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PathSpringParameter* pInstance);
        static void Clean(PathSpringParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjLinkedSpringSpawner {
        enum class PlaceType : int8_t {
            LINE = 0,
            CIRCLE = 1,
        };

        enum class BehaviorType : int8_t {
            NORMAL = 0,
            PATH = 1,
        };

        int32_t placeNum;
        PlaceType placeType;
        float circleRadius;
        BehaviorType behavior;
        float interval;
        float angle;
        bool isEventOn;
        NormalSpringParameter normalParam;
        PathSpringParameter pathParam;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjLinkedSpringSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjLinkedSpringSpawner* pInstance);
        static void Clean(ObjLinkedSpringSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjLocatorSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjLocatorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjLocatorSpawner* pInstance);
        static void Clean(ObjLocatorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjLoopAreaVolumeSpawner {
        float width;
        float height;
        float depth;
        int32_t pathID;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjLoopAreaVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjLoopAreaVolumeSpawner* pInstance);
        static void Clean(ObjLoopAreaVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjNormalFloorSpawner {
        enum class SizeType : int8_t {
            SIZE_SMALL = 0,
            SIZE_MEDIUM = 1,
            SIZE_LARGE = 2,
            NUM_SIZE_TYPE = 3,
        };

        enum class VisualType : int8_t {
            VISUAL_A = 0,
            VISUAL_B = 1,
            NUM_VISUAL_TYPE = 2,
        };

        enum class MoveType : int8_t {
            MOVE_NONE = 0,
            MOVE_POINT = 1,
            MOVE_PATH = 2,
        };

        enum class PatrolType : int8_t {
            PATROL_RETURN = 0,
            PATROL_LOOP = 1,
            PATROL_ONEWAY = 2,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        SizeType sizeType;
        VisualType visualType;
        MoveType moveType;
        PatrolType patrolType;
        TimeType timeType;
        bool eventDriven;
        bool isFv;
        bool isOneway;
        bool isFall;
        bool isBreak;
        bool isSyncRot;
        bool isSmoothMove;
        bool isReverse;
        bool isPressDead;
        csl::math::Vector3 moveVector;
        uint32_t pathID;
        csl::ut::MoveArray32<uint32_t> locaterList;
        float waitTime;
        float phase;
        float speed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjNormalFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjNormalFloorSpawner* pInstance);
        static void Clean(ObjNormalFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjNumberRingSpawner {
        enum class NumberType : int8_t {
            NUMBER_5 = 0,
            NUMBER_4 = 1,
            NUMBER_3 = 2,
            NUMBER_2 = 3,
            NUMBER_1 = 4,
        };

        NumberType type;
        bool separateTranslucent;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjNumberRingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjNumberRingSpawner* pInstance);
        static void Clean(ObjNumberRingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjNumberRingManagerSpawner {
        csl::ut::MoveArray32<uint32_t> rings;
        ObjectEventData event0;
        ObjectEventData event1;
        ObjectEventData event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjNumberRingManagerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjNumberRingManagerSpawner* pInstance);
        static void Clean(ObjNumberRingManagerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjObjectLayerTriggerSpawner : VolumeTriggerSpawner {
        csl::ut::VariableString layerName;
        bool enabled;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjObjectLayerTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjObjectLayerTriggerSpawner* pInstance);
        static void Clean(ObjObjectLayerTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjOutOfControlTriggerSpawner {
        csl::math::Vector2 size;
        float outOfControlTime;
        bool releaseByGround;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjOutOfControlTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjOutOfControlTriggerSpawner* pInstance);
        static void Clean(ObjOutOfControlTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjOutOfControlVolumeSpawner {
        csl::math::Vector3 size;
        bool releaseByGround;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjOutOfControlVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjOutOfControlVolumeSpawner* pInstance);
        static void Clean(ObjOutOfControlVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPathSpeedControlCollisionSpawner {
        enum class TurnType : int8_t {
            TURN_LEFT = 0,
            TURN_RIGHT = 1,
        };

        float Radius;
        float SlowSpeed;
        float BrakeTime;
        float SlowTime;
        float AcceleTime;
        TurnType TurnDirection;
        float Speed;
        uint32_t PathID;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPathSpeedControlCollisionSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPathSpeedControlCollisionSpawner* pInstance);
        static void Clean(ObjPathSpeedControlCollisionSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPipeMoveTriggerSpawner {
        enum class SpeedType : int8_t {
            SPEED_FIX = 0,
            SPEED_MIN = 1,
        };

        float width;
        float height;
        uint32_t pathID;
        SpeedType speedType;
        float speed;
        float outOfControlTime;
        float launchSpeed;
        float launchAttackTime;
        bool isPoseToReverseGravity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPipeMoveTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPipeMoveTriggerSpawner* pInstance);
        static void Clean(ObjPipeMoveTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct MoveParameter {
        enum class MoveType : int8_t {
            MOVE_NONE = 0,
            MOVE_CONSTANT = 1,
            MOVE_ROTATE = 2,
        };

        MoveType type;
        float distance;
        float cycle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MoveParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MoveParameter* pInstance);
        static void Clean(MoveParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPointLightSpawner {
        float colorR;
        float colorG;
        float colorB;
        float sourceRadius;
        float halfLength;
        float attenuationRadius;
        MoveParameter move;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPointLightSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPointLightSpawner* pInstance);
        static void Clean(ObjPointLightSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPointMarkerSpawner {
        enum class ViewType : int8_t {
            FORWARDVIEW = 0,
            SIDEVIEW = 1,
            SIDEVIEW_REV = 2,
        };

        float Width;
        float Height;
        ViewType StageType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPointMarkerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPointMarkerSpawner* pInstance);
        static void Clean(ObjPointMarkerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPopupSpringSpawner {
        float FirstSpeed;
        float OutOfControl;
        float KeepVelocityDistance;
        float VisibleTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPopupSpringSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPopupSpringSpawner* pInstance);
        static void Clean(ObjPopupSpringSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPulleySpawner {
        uint32_t pathID;
        float startPosition1D;
        float endPosition1D;
        bool isJumpCancel;
        csl::math::Vector3 offset;
        float minSpeed;
        float maxSpeed;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPulleySpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPulleySpawner* pInstance);
        static void Clean(ObjPulleySpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPulleyColumnSpawner {
        uint32_t height;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPulleyColumnSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPulleyColumnSpawner* pInstance);
        static void Clean(ObjPulleyColumnSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPulley2Spawner {
        enum class ColumnType : int8_t {
            COLUMN_TYPE_SHORT = 0,
            COLUMN_TYPE_LONG = 1,
            NUM_COLUMN_TYPES = 2,
        };

        uint32_t pathID;
        csl::ut::MoveArray32<uint32_t> nodeList;
        float startPosition1D;
        float endPosition1D;
        float minSpeed;
        float maxSpeed;
        ColumnType columnType;
        ObjectEventData event0;
        ObjectEventData event1;
        ObjectEventData event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPulley2Spawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPulley2Spawner* pInstance);
        static void Clean(ObjPulley2Spawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPulley2NodeSpawner {
        enum class ColumnType : int8_t {
            COLUMN_TYPE_SHORT = 0,
            COLUMN_TYPE_LONG = 1,
            NUM_COLUMN_TYPES = 2,
        };

        ColumnType columnType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPulley2NodeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPulley2NodeSpawner* pInstance);
        static void Clean(ObjPulley2NodeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjQuickStepSpawner {
        enum class ModeType : int8_t {
            MODE_NORMAL = 0,
            MODE_ONLYRUN = 1,
        };

        enum class LineType : int8_t {
            LINE2_LEFT = 0,
            LINE2_RIGHT = 1,
            LINE3 = 2,
            LINE5 = 3,
        };

        ModeType mode;
        LineType line;
        uint32_t pathID;
        float speed;
        float stepWidth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjQuickStepSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjQuickStepSpawner* pInstance);
        static void Clean(ObjQuickStepSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjQuickStepTriggerSpawner : ObjQuickStepSpawner {
        enum class ActionType : int8_t {
            ACT_START = 0,
            ACT_END = 1,
        };

        ActionType type;
        float width;
        float height;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjQuickStepTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjQuickStepTriggerSpawner* pInstance);
        static void Clean(ObjQuickStepTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjQuickStepVolumeSpawner : ObjQuickStepSpawner {
        enum class BasePoint : int8_t {
            BASE_CENTER = 0,
            BASE_Z_PLANE = 1,
        };

        BasePoint basePoint;
        csl::math::Vector3 size;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjQuickStepVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjQuickStepVolumeSpawner* pInstance);
        static void Clean(ObjQuickStepVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRedRingSpawner {
        enum class Event : int8_t {
            EVENT_NONE = 0,
            EVENT_VISIBLE = 1,
            EVENT_INVISIBLE = 2,
        };

        enum class Rotate : int8_t {
            OBJ_Y_UP = 0,
            WORLD_Y_UP = 1,
        };

        int32_t ItemId;
        Event EventType;
        Rotate RotateType;
        bool SeparateTranslucent;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRedRingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRedRingSpawner* pInstance);
        static void Clean(ObjRedRingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjReleaseBoxSpawner {
        enum class Direction : int8_t {
            DIR_FRONT = 0,
            DIR_LEFT = 1,
            DIR_RIGHT = 2,
        };

        Direction direction;
        int32_t id;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjReleaseBoxSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjReleaseBoxSpawner* pInstance);
        static void Clean(ObjReleaseBoxSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRestrictControlVolumeSpawner : VolumeTriggerSpawner {
        enum class ControlType : int8_t {
            RESTRICT_AXIS = 0,
        };

        ControlType type;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRestrictControlVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRestrictControlVolumeSpawner* pInstance);
        static void Clean(ObjRestrictControlVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRingSpawner {
        enum class EventType : int8_t {
            EVENT_NONE = 0,
            EVENT_VISIBLE = 1,
            EVENT_INVISIBLE = 2,
        };

        enum class RotateType : int8_t {
            OBJ_Y_UP = 0,
            WORLD_Y_UP = 1,
        };

        float ResetTime;
        EventType EventType;
        RotateType RotateType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRingSpawner* pInstance);
        static void Clean(ObjRingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSceneChangeVolumeSpawner {
        enum class ShapeType : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
        };

        bool visibleS0;
        bool visibleS1;
        bool visibleS2;
        bool visibleS3;
        bool visibleS4;
        bool visibleS5;
        bool visibleS6;
        bool visibleS7;
        ShapeType shape;
        float width;
        float height;
        float depth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSceneChangeVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSceneChangeVolumeSpawner* pInstance);
        static void Clean(ObjSceneChangeVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetParticleBaseSoundParam {
        csl::ut::VariableString name;
        bool is3D;
        float volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetParticleBaseSoundParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetParticleBaseSoundParam* pInstance);
        static void Clean(ObjSetParticleBaseSoundParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetParticleBaseRumbleParam {
        csl::ut::VariableString name;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetParticleBaseRumbleParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetParticleBaseRumbleParam* pInstance);
        static void Clean(ObjSetParticleBaseRumbleParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetParticleBaseSpawner {
        csl::ut::VariableString effectName;
        float scale;
        uint8_t colorR;
        uint8_t colorG;
        uint8_t colorB;
        uint8_t colorA;
        ObjSetParticleBaseSoundParam sound;
        ObjSetParticleBaseRumbleParam rumble;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetParticleBaseSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetParticleBaseSpawner* pInstance);
        static void Clean(ObjSetParticleBaseSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetParticleSpawner : ObjSetParticleBaseSpawner {
        enum class TriggerType : int8_t {
            RANGE = 0,
            MESSAGE = 1,
        };

        TriggerType trigger;
        int32_t sectorId;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetParticleSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetParticleSpawner* pInstance);
        static void Clean(ObjSetParticleSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetParticleVolumeSpawner : ObjSetParticleBaseSpawner {
        enum class Shape : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
        };

        enum class Emit : int8_t {
            EMIT_OBJECT = 0,
            EMIT_PLAYER = 1,
            EMIT_CONTACT = 2,
            EMIT_CAMERA = 3,
        };

        enum class Gravity : int8_t {
            GRAVITY_OBJECT = 0,
            GRAVITY_EMIT = 1,
        };

        Shape shapeType;
        float width;
        float height;
        float depth;
        float zOffset;
        bool isStay;
        Emit emitPointType;
        Gravity gravityPointType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetParticleVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetParticleVolumeSpawner* pInstance);
        static void Clean(ObjSetParticleVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetParticleExtentSpawner {
        enum class Shape : int8_t {
            SHAPE_SPHERE = 0,
            SHAPE_BOX = 1,
        };

        enum class Emit : int8_t {
            EMIT_VOLUME = 0,
            EMIT_FACE = 1,
        };

        enum class Direction : int8_t {
            DIRECTION_Y_UP = 0,
            DIRECTION_NORMAL = 1,
            DIRECTION_RANDOM = 2,
        };

        enum class ActiveType : int8_t {
            TYPE_ACTIVE = 0,
            TYPE_NONACTIVE = 1,
        };

        csl::ut::VariableString effectName;
        float scale;
        uint8_t colorR;
        uint8_t colorG;
        uint8_t colorB;
        uint8_t colorA;
        Shape shapeType;
        csl::math::Vector3 extents;
        Emit emitPointType;
        Direction directionType;
        float interval;
        float loopTime;
        bool bottomExclusion;
        bool upperHalfOnly;
        ActiveType active;
        int32_t sectorId;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetParticleExtentSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetParticleExtentSpawner* pInstance);
        static void Clean(ObjSetParticleExtentSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetPathNodeSpawner {
        enum class LineType : int8_t {
            LINETYPE_SNS = 0,
            LINETYPE_STRAIGHT = 1,
        };

        uint32_t nodeId;
        LineType lineType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetPathNodeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetPathNodeSpawner* pInstance);
        static void Clean(ObjSetPathNodeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetPathSpawner {
        enum class PathType : int8_t {
            OBJ_PATH = 0,
            SV_PATH = 1,
            GR_PATH = 2,
        };

        enum class LineType : int8_t {
            LINETYPE_SNS = 0,
            LINETYPE_STRAIGHT = 1,
        };

        uint32_t PathUID;
        PathType Type;
        csl::ut::MoveArray32<uint32_t> NodeList;
        bool IsLoopPath;
        LineType startLineType;
        float divideLength;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetPathSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetPathSpawner* pInstance);
        static void Clean(ObjSetPathSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetPathLoopSpawner {
        enum class PathType : int8_t {
            OBJ_PATH = 0,
            SV_PATH = 1,
            GR_PATH = 2,
        };

        int32_t pathUID;
        PathType type;
        float inRadius;
        float outRadius;
        float angle;
        float shiftDistance;
        float inDistance;
        float outDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetPathLoopSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetPathLoopSpawner* pInstance);
        static void Clean(ObjSetPathLoopSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetPathSpiralSpawner {
        enum class PathType : int8_t {
            OBJ_PATH = 0,
            SV_PATH = 1,
            GR_PATH = 2,
        };

        enum class RotDir : int8_t {
            ROT_DIR_LEFT = 0,
            ROT_DIR_RIGHT = 1,
        };

        int32_t pathUID;
        PathType type;
        RotDir rotDir;
        float inRadius;
        float outRadius;
        float angle;
        float shiftDistance;
        float inDistance;
        float outDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetPathSpiralSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetPathSpiralSpawner* pInstance);
        static void Clean(ObjSetPathSpiralSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetPathLineSpawner {
        enum class PathType : int8_t {
            OBJ_PATH = 0,
            SV_PATH = 1,
            GR_PATH = 2,
        };

        int32_t pathUID;
        PathType type;
        float distance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetPathLineSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetPathLineSpawner* pInstance);
        static void Clean(ObjSetPathLineSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetPathCircleSpawner {
        enum class PathType : int8_t {
            OBJ_PATH = 0,
            SV_PATH = 1,
            GR_PATH = 2,
        };

        enum class NormalType : int8_t {
            NOR_DEFAULT = 0,
            NOR_OUTSIDE = 1,
            NOR_INSIDE = 2,
        };

        int32_t pathUID;
        PathType type;
        NormalType normalType;
        float radius;
        bool isReverse;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetPathCircleSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetPathCircleSpawner* pInstance);
        static void Clean(ObjSetPathCircleSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetPathPolygonSpawner {
        enum class PathType : int8_t {
            OBJ_PATH = 0,
            SV_PATH = 1,
            GR_PATH = 2,
        };

        enum class PolygonType : int8_t {
            TRIANGLE_PATH = 0,
            SQUARE_PATH = 1,
        };

        enum class NormalType : int8_t {
            NOR_DEFAULT = 0,
            NOR_OUTSIDE = 1,
            NOR_INSIDE = 2,
        };

        int32_t pathUID;
        PathType type;
        PolygonType polygonType;
        NormalType normalType;
        float width;
        float height;
        float offsetHeight;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetPathPolygonSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetPathPolygonSpawner* pInstance);
        static void Clean(ObjSetPathPolygonSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetRigidBodySpawner {
        enum class ActionType : int8_t {
            ACT_TERRAIN = 0,
            ACT_RAYBLOCK = 1,
        };

        csl::math::Vector3 size;
        bool initial;
        ActionType action;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetRigidBodySpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetRigidBodySpawner* pInstance);
        static void Clean(ObjSetRigidBodySpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSliderParamTriggerSpawner {
        csl::math::Vector2 size;
        float speed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSliderParamTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSliderParamTriggerSpawner* pInstance);
        static void Clean(ObjSliderParamTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSliderTriggerSpawner {
        enum class ActionType : int8_t {
            ACT_BEGIN = 0,
            ACT_END = 1,
        };

        csl::math::Vector2 size;
        ActionType action;
        float speed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSliderTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSliderTriggerSpawner* pInstance);
        static void Clean(ObjSliderTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSpiralVolumeSpawner {
        csl::math::Vector3 size;
        uint32_t pathUID;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSpiralVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSpiralVolumeSpawner* pInstance);
        static void Clean(ObjSpiralVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSpotLightSpawner {
        float colorR;
        float colorG;
        float colorB;
        float innerConeAngle;
        float outerConeAngle;
        float attenuationRadius;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSpotLightSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSpotLightSpawner* pInstance);
        static void Clean(ObjSpotLightSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSpringSpawner {
        float FirstSpeed;
        float OutOfControl;
        float KeepVelocityDistance;
        bool IsEventOn;
        bool IsHorizon;
        bool isVisible;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSpringSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSpringSpawner* pInstance);
        static void Clean(ObjSpringSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSpringPoleSpawner {
        float speedMin;
        float speedMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSpringPoleSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSpringPoleSpawner* pInstance);
        static void Clean(ObjSpringPoleSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjStartPositionSpawner {
        enum class StartType : int8_t {
            STAND = 0,
            RUNNING = 1,
            FALL = 2,
        };

        StartType m_startType;
        float m_speed;
        float m_time;
        float m_outOfControlTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjStartPositionSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjStartPositionSpawner* pInstance);
        static void Clean(ObjStartPositionSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSuperRingSpawner {
        enum class EventType : int8_t {
            EVENT_NONE = 0,
            EVENT_VISIBLE = 1,
            EVENT_INVISIBLE = 2,
        };

        enum class RotateType : int8_t {
            OBJ_Y_UP = 0,
            WORLD_Y_UP = 1,
        };

        EventType EventType;
        RotateType RotateType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSuperRingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSuperRingSpawner* pInstance);
        static void Clean(ObjSuperRingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSuperSonicDisallowVolumeSpawner : VolumeTriggerSpawner {
        bool allowWhenLeave;
        bool initial;
        uint8_t pad1[2];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSuperSonicDisallowVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSuperSonicDisallowVolumeSpawner* pInstance);
        static void Clean(ObjSuperSonicDisallowVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSwitchVolumeSpawner {
        enum class Event : int8_t {
            EVENT_ON = 0,
            EVENT_OFF = 1,
        };

        enum class Shape : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
        };

        enum class BasePoint : int8_t {
            BASE_CENTER = 0,
            BASE_Z_PLANE = 1,
        };

        enum class Condition : int8_t {
            COND_ON_TRIGGER = 0,
            COND_PULSE = 1,
            COND_TIMER_ONCE = 2,
            COND_TIMER = 3,
            COND_ON_STAY = 4,
        };

        enum class Filter : int8_t {
            FILTER_PLAYER = 0,
        };

        csl::ut::MoveArray32<uint32_t> targets0;
        Event event0;
        float timer0;
        csl::ut::MoveArray32<uint32_t> targets1;
        Event event1;
        float timer1;
        csl::ut::MoveArray32<uint32_t> targets2;
        Event event2;
        float timer2;
        Shape shape;
        BasePoint basePoint;
        csl::math::Vector3 size;
        Condition condition;
        float lifetime;
        Filter filter;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSwitchVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSwitchVolumeSpawner* pInstance);
        static void Clean(ObjSwitchVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTerrainBlockSpawner {
        enum class Block : int8_t {
            BLOCK_BOX = 0,
            BLOCK_ARCH_CURVE_UP = 1,
            BLOCK_ARCH_CURVE_DOWN = 2,
            BLOCK_ARCH_CURVE_RIGHT = 3,
            BLOCK_ARCH_CURVE_LEFT = 4,
        };

        enum class Layer : int8_t {
            LAYER_LAND = 0,
            LAYER_MOVELAND = 1,
            LAYER_ONEWAY = 2,
        };

        enum class WallType : int8_t {
            WALL_NONE = 0,
            WALL_EXIST = 1,
            WALL_COLLISION = 2,
        };

        enum class Color : int8_t {
            COLOR_GREEN = 0,
            COLOR_BROWN = 1,
            COLOR_BLUE = 2,
            COLOR_WHITE = 3,
            COLOR_RED = 4,
            COLOR_YELLOW = 5,
        };

        Block BlockType;
        float BlockWidth;
        float BlockWidthEnd;
        float BlockHeight;
        float BlockDepth;
        float BlockDepthOffset;
        float ArchRadius;
        float ArchDegree;
        uint32_t ArchDivNum;
        float SlopeHeight;
        Layer LayerGroup;
        bool AttrEnableParkour;
        bool AttrBreakable;
        bool AttrNotStand;
        WallType WallLeft;
        WallType WallRight;
        WallType WallFront;
        WallType WallBack;
        float WallHeight;
        Color ColorType;
        float Interval;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTerrainBlockSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTerrainBlockSpawner* pInstance);
        static void Clean(ObjTerrainBlockSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct Point {
        float z;
        float y;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Point* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Point* pInstance);
        static void Clean(Point* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTerrainBlocksSpawner {
        enum class Layer : int8_t {
            LAYER_LAND = 0,
            LAYER_MOVELAND = 1,
            LAYER_ONEWAY = 2,
        };

        enum class WallType : int8_t {
            WALL_NONE = 0,
            WALL_EXIST = 1,
            WALL_COLLISION = 2,
        };

        enum class Color : int8_t {
            COLOR_GREEN = 0,
            COLOR_BROWN = 1,
            COLOR_BLUE = 2,
            COLOR_WHITE = 3,
            COLOR_RED = 4,
            COLOR_YELLOW = 5,
        };

        float Width;
        float Height;
        Point Blocks[30];
        Layer LayerGroup;
        bool AttrEnableParkour;
        WallType WallLeft;
        WallType WallRight;
        WallType WallFront;
        WallType WallBack;
        float WallHeight;
        Color ColorType;
        float Interval;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTerrainBlocksSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTerrainBlocksSpawner* pInstance);
        static void Clean(ObjTerrainBlocksSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTerrainPathSpawner {
        enum class WallType : int8_t {
            WALL_NONE = 0,
            WALL_EXIST = 1,
            WALL_COLLISION = 2,
        };

        enum class WallAttribute : int8_t {
            WALLATTR_NONE = 0,
            WALLATTR_NOT_PARKOUR = 1,
        };

        enum class NormalType : int8_t {
            NORMAL_BY_YUP = 0,
            NORMAL_BY_PATH = 1,
        };

        uint32_t pathID;
        float widthStart;
        float widthEnd;
        float height;
        float wallHeight;
        int32_t split;
        WallType rightWallType;
        WallType leftWallType;
        WallType frontWallType;
        WallType backWallType;
        WallAttribute wallAttr;
        NormalType normalType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTerrainPathSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTerrainPathSpawner* pInstance);
        static void Clean(ObjTerrainPathSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTerrainPathCylinderSpawner {
        uint32_t pathID;
        float radius;
        int32_t numPlain;
        float splitDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTerrainPathCylinderSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTerrainPathCylinderSpawner* pInstance);
        static void Clean(ObjTerrainPathCylinderSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjThornSpawner {
        enum class MoveType : int8_t {
            TYPE_APPEAR = 0,
            TYPE_DISAPPEAR = 1,
            TYPE_MOVE = 2,
        };

        csl::math::Vector2 size;
        csl::math::Vector2 interval;
        float offTime;
        float onTime;
        float phase;
        MoveType type;
        bool eventDriven;
        bool showBase;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjThornSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjThornSpawner* pInstance);
        static void Clean(ObjThornSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjThornBallMoveParam {
        enum class Direction : int8_t {
            DIR_HORIZONTAL = 0,
            DIR_VERTICAL = 1,
        };

        float time;
        float distance;
        float phase;
        Direction direction;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjThornBallMoveParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjThornBallMoveParam* pInstance);
        static void Clean(ObjThornBallMoveParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjThornBallRollingParam {
        enum class Direction : int8_t {
            DIR_HORIZONTAL = 0,
            DIR_VERTICAL = 1,
        };

        float time;
        float radius;
        float phase;
        Direction direction;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjThornBallRollingParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjThornBallRollingParam* pInstance);
        static void Clean(ObjThornBallRollingParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjThornBallAppearParam {
        float time;
        float distance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjThornBallAppearParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjThornBallAppearParam* pInstance);
        static void Clean(ObjThornBallAppearParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTornBallPendulumParam {
        enum class EffectType : int8_t {
            EFFECTTYPE_DEFAULT = 0,
            EFFECTTYPE_SAND = 1,
            EFFECTTYPE_WATER = 2,
            EFFECTTYPE_METAL = 3,
        };

        float time;
        float radius;
        float amplitude;
        float stopTime;
        bool isConstant;
        float phase;
        EffectType effectType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTornBallPendulumParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTornBallPendulumParam* pInstance);
        static void Clean(ObjTornBallPendulumParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTornBallTumbleParam {
        enum class EffectType : int8_t {
            EFFECTTYPE_DEFAULT = 0,
            EFFECTTYPE_SAND = 1,
            EFFECTTYPE_WATER = 2,
            EFFECTTYPE_METAL = 3,
        };

        uint32_t pathId;
        float speed;
        float limitTime;
        EffectType effectType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTornBallTumbleParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTornBallTumbleParam* pInstance);
        static void Clean(ObjTornBallTumbleParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjThornBallSpawner {
        enum class Type : int8_t {
            TYPE_NORMAL = 0,
            TYPE_MOVE = 1,
            TYPE_ROLLING = 2,
            TYPE_APPEAR = 3,
            TYPE_PENDULUM = 4,
            TYPE_TUMBLE = 5,
        };

        Type type;
        bool hitEnemy;
        ObjThornBallMoveParam moveParam;
        ObjThornBallRollingParam rollingParam;
        ObjThornBallAppearParam appearParam;
        ObjTornBallPendulumParam pendulumParam;
        ObjTornBallTumbleParam tumbleParam;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjThornBallSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjThornBallSpawner* pInstance);
        static void Clean(ObjThornBallSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjThornCylinderSpawner {
        enum class Type : int8_t {
            TYPE_SHORT = 0,
            TYPE_LONG = 1,
            NUM_TYPES = 2,
        };

        Type type;
        bool rigidbody;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjThornCylinderSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjThornCylinderSpawner* pInstance);
        static void Clean(ObjThornCylinderSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTreadGrassVolumeSpawner : VolumeTriggerSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTreadGrassVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTreadGrassVolumeSpawner* pInstance);
        static void Clean(ObjTreadGrassVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTreadGrassSettingSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTreadGrassSettingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTreadGrassSettingSpawner* pInstance);
        static void Clean(ObjTreadGrassSettingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjUpReelSpawner {
        float length;
        float upSpeedMax;
        float firstSpeed;
        float outOfControl;
        bool isOneTimeUp;
        bool eventDriven;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjUpReelSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjUpReelSpawner* pInstance);
        static void Clean(ObjUpReelSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjVoidVolumeSpawner {
        csl::math::Vector3 size;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjVoidVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjVoidVolumeSpawner* pInstance);
        static void Clean(ObjVoidVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWallRunEventTriggerSpawner {
        enum class ActionType : int8_t {
            ACT_BEGIN = 0,
            ACT_END = 1,
        };

        csl::math::Vector2 size;
        ActionType action;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWallRunEventTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWallRunEventTriggerSpawner* pInstance);
        static void Clean(ObjWallRunEventTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWallRunEventVolumeSpawner {
        csl::math::Vector3 size;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWallRunEventVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWallRunEventVolumeSpawner* pInstance);
        static void Clean(ObjWallRunEventVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWarpTriggerSpawner {
        enum class StatusType : int8_t {
            RESET = 0,
            CONTINUANCE = 1,
        };

        csl::math::Vector2 size;
        hh::game::ObjectId warpPoint;
        StatusType status;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWarpTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWarpTriggerSpawner* pInstance);
        static void Clean(ObjWarpTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWaterVolumeSpawner {
        csl::math::Vector3 size;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWaterVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWaterVolumeSpawner* pInstance);
        static void Clean(ObjWaterVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWideSpringSpawner {
        float FirstSpeed;
        float OutOfControl;
        float KeepVelocityDistance;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWideSpringSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWideSpringSpawner* pInstance);
        static void Clean(ObjWideSpringSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWireDriftSpawner {
        csl::math::Vector2 size;
        uint32_t pathID;
        float minLength;
        float speed;
        float outOfControlTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWireDriftSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWireDriftSpawner* pInstance);
        static void Clean(ObjWireDriftSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWireGiantSwingSpawner {
        float radius;
        float rotateSpeed;
        float successSpeed;
        float failSpeed;
        float launchAngle;
        bool enableCamera;
        csl::math::Vector3 eyeOffset;
        csl::math::Vector3 lookatOffset;
        bool visibility;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWireGiantSwingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWireGiantSwingSpawner* pInstance);
        static void Clean(ObjWireGiantSwingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWireLauncherSpawner {
        enum class OffsetType : int8_t {
            FIX = 0,
            REVERSE_Z = 1,
            CIRCLE = 2,
        };

        float speed;
        OffsetType type;
        csl::math::Vector3 offset;
        float launchTime;
        bool visibility;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWireLauncherSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWireLauncherSpawner* pInstance);
        static void Clean(ObjWireLauncherSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWireTargetSpawner {
        float trapezeRadius;
        float maxSpeed;
        float launchMaxSpeed;
        float accele;
        float endAngle;
        float outOfControlTime;
        bool forceAxis;
        bool enableSideSwing;
        bool visibility;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWireTargetSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWireTargetSpawner* pInstance);
        static void Clean(ObjWireTargetSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWireTargetPathSpawner {
        enum class MotionType : int8_t {
            MOTION_TRAPEZE = 0,
            MOTION_LAUNCH = 1,
            MOTION_CONTINUOUS_TRAPEZE = 2,
            MOTION_CONTINUOUS_LAUNCH = 3,
        };

        enum class StartPos : int8_t {
            START_BEGINNING_POINT = 0,
            START_NEAR_POINT = 1,
        };

        enum class IntpType : int8_t {
            INTP_LINEAR = 0,
            INTP_SQRT = 1,
        };

        MotionType motion;
        uint32_t pathUID;
        float initialSpeed;
        float speed;
        float launchSpeed;
        float shiftRatio1;
        float shiftRatio2;
        hh::game::ObjectId cameraID;
        float easeInTime;
        float easeOutTime;
        StartPos startPos;
        float finishDist;
        IntpType intpType;
        float intpFinishDist;
        float outOfControlTime;
        bool visibility;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWireTargetPathSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWireTargetPathSpawner* pInstance);
        static void Clean(ObjWireTargetPathSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWireTargetPathTriggerSpawner {
        enum class MotionType : int8_t {
            MOTION_TRAPEZE = 0,
            MOTION_LAUNCH = 1,
            MOTION_CONTINUOUS_TRAPEZE = 2,
            MOTION_CONTINUOUS_LAUNCH = 3,
        };

        enum class StartPos : int8_t {
            START_BEGINNING_POINT = 0,
            START_NEAR_POINT = 1,
        };

        enum class IntpType : int8_t {
            INTP_LINEAR = 0,
            INTP_SQRT = 1,
        };

        MotionType motion;
        csl::math::Vector3 point;
        csl::math::Vector2 size;
        uint32_t pathUID;
        float initialSpeed;
        float speed;
        float launchSpeed;
        float shiftRatio1;
        float shiftRatio2;
        hh::game::ObjectId cameraID;
        float easeInTime;
        float easeOutTime;
        StartPos startPos;
        float finishDist;
        IntpType intpType;
        float intpFinishDist;
        float outOfControlTime;
        bool visibility;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWireTargetPathTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWireTargetPathTriggerSpawner* pInstance);
        static void Clean(ObjWireTargetPathTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWireTrackSpawner {
        csl::math::Vector2 size;
        float speed;
        float accele;
        uint32_t pathID;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWireTrackSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWireTrackSpawner* pInstance);
        static void Clean(ObjWireTrackSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWireTurnSpawner {
        enum class TurnDirection : int8_t {
            TURN_LEFT = 0,
            TURN_RIGHT = 1,
        };

        float width;
        float height;
        hh::game::ObjectId pillar;
        TurnDirection direction;
        float beginAngle;
        float endAngle;
        float radius;
        float speed;
        float outOfControlTime;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWireTurnSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWireTurnSpawner* pInstance);
        static void Clean(ObjWireTurnSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWireTurnPathSpawner {
        enum class TurnDirection : int8_t {
            TURN_LEFT = 0,
            TURN_RIGHT = 1,
        };

        float width;
        float height;
        uint32_t wirePathUID;
        uint32_t movePathUID;
        TurnDirection direction;
        float speed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWireTurnPathSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWireTurnPathSpawner* pInstance);
        static void Clean(ObjWireTurnPathSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWispCapsuleSpawner {
        enum class ItemType : int8_t {
            GADGET_WHISP = 0,
            WHITE_WHISP = 1,
        };

        enum class Event : int8_t {
            EVENT_ON = 0,
            EVENT_OFF = 1,
        };

        ItemType itemType;
        float resetTime;
        bool eventDriven;
        bool useAsteroid;
        bool useLightning;
        bool useCube;
        bool useDrill;
        bool useBurst;
        bool useVoid;
        bool useHover;
        csl::ut::MoveArray32<uint32_t> targets0;
        Event event0;
        float timer0;
        csl::ut::MoveArray32<uint32_t> targets1;
        Event event1;
        float timer1;
        csl::ut::MoveArray32<uint32_t> targets2;
        Event event2;
        float timer2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWispCapsuleSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWispCapsuleSpawner* pInstance);
        static void Clean(ObjWispCapsuleSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWoodBoxSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWoodBoxSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWoodBoxSpawner* pInstance);
        static void Clean(ObjWoodBoxSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjYellowMoonRingSpawner {
        bool separateTranslucent;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjYellowMoonRingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjYellowMoonRingSpawner* pInstance);
        static void Clean(ObjYellowMoonRingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjYellowMoonRingManagerSpawner {
        float blinkTime0;
        float blinkTime1;
        float blinkSpan0;
        float blinkSpan1;
        csl::ut::MoveArray32<uint32_t> rings;
        ObjectEventData event0;
        ObjectEventData event1;
        ObjectEventData event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjYellowMoonRingManagerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjYellowMoonRingManagerSpawner* pInstance);
        static void Clean(ObjYellowMoonRingManagerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyBatabataSpawner {
        float velocity;
        float searchDistance;
        bool isSwitch;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyBatabataSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyBatabataSpawner* pInstance);
        static void Clean(EnemyBatabataSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyBeetonSpawner {
        float SerchLength;
        float SerchMoveSpeed;
        float ViewBoxHalfLengthX;
        float ViewBoxHalfLengthY;
        float ViewBoxHalfLengthZ;
        csl::math::Vector3 ViewBoxOffset;
        float AttackRangeRatio;
        float AttackRangeHeightRatio;
        float AttackRangeOffset;
        bool IsMove;
        bool CheckShielding;
        bool AttackConst;
        float AttackConstAngle;
        float StraightDistance;
        float RespawnTime;
        csl::math::Vector3 RespawnOffsetPos;
        uint32_t RespawnPathId;
        bool isFV;
        bool isEscape;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyBeetonSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyBeetonSpawner* pInstance);
        static void Clean(EnemyBeetonSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyBeetonDollSpawner {
        csl::ut::MoveArray32<uint32_t> positionList;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyBeetonDollSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyBeetonDollSpawner* pInstance);
        static void Clean(EnemyBeetonDollSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyBeetonDollPointSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyBeetonDollPointSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyBeetonDollPointSpawner* pInstance);
        static void Clean(EnemyBeetonDollPointSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjEggChaserBeginAttackVolumeSpawner {
        csl::math::Vector3 size;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjEggChaserBeginAttackVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjEggChaserBeginAttackVolumeSpawner* pInstance);
        static void Clean(ObjEggChaserBeginAttackVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggChaserSpawner {
        enum class AttackType : int8_t {
            ATTACK_TYPE_TIME = 0,
            ATTACK_TYPE_VOLUME = 1,
            NUM_ATTACK_TYPE = 2,
        };

        AttackType attackType;
        float appearSpeed;
        float escapeSpeed;
        float playerDistance;
        float pathHeight;
        bool isEventTurn;
        float swingSpeed;
        float swingPhase;
        float laserTime;
        float attackInterval;
        float attackPhase;
        uint32_t numAttack;
        uint32_t pathID;
        bool useLaserRaycast;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggChaserSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggChaserSpawner* pInstance);
        static void Clean(EnemyEggChaserSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjEggpawnReturnCollisionSpawner {
        csl::math::Vector3 size;
        bool isDebug;
        csl::ut::MoveArray32<uint32_t> debugTargets;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjEggpawnReturnCollisionSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjEggpawnReturnCollisionSpawner* pInstance);
        static void Clean(ObjEggpawnReturnCollisionSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggpawnDollSpawner {
        csl::ut::MoveArray32<uint32_t> positionList;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggpawnDollSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggpawnDollSpawner* pInstance);
        static void Clean(EnemyEggpawnDollSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggpawnDollPointSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggpawnDollPointSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggpawnDollPointSpawner* pInstance);
        static void Clean(EnemyEggpawnDollPointSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggTankSpawner {
        enum class MoveType : int32_t {
            MOVE_NONE = 0,
            MOVE_FORWARD = 1,
            MOVE_BACK = 2,
        };

        float serachDistance;
        MoveType moveType;
        float moveDistance;
        float moveSpeed;
        bool isRespawn;
        bool eventDriven;
        bool isFV;
        float bulletSpeed;
        float bulletMaxFlyingDistance;
        uint32_t bulletContinuousShellingNum;
        float bulletShellingInterval;
        float bulletCoolDownTime;
        float bulletFiringAngle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggTankSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggTankSpawner* pInstance);
        static void Clean(EnemyEggTankSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggWalkerSpawner {
        enum class JumpType : int8_t {
            JUMP_QUICK = 0,
            JUMP_SLOW = 1,
            JUMP_AUTO = 2,
        };

        uint32_t pathID;
        float moveSpeed;
        float maxDistance;
        csl::ut::MoveArray32<uint32_t> locaterList;
        float jumpSpeed;
        float jumpHeight;
        JumpType jumpType;
        hh::game::ObjectId endPosObj;
        float range;
        float missileRizeLength;
        uint32_t launchMissileNum;
        float fallOffsetHeight;
        csl::math::Vector3 pathOffsetPosition;
        bool isFV;
        bool isFallStart;
        bool isTreadGrass;
        bool isEndTrun;
        bool updateMaterial;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggWalkerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggWalkerSpawner* pInstance);
        static void Clean(EnemyEggWalkerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyMetalSonicSpawner {
        uint32_t pathID;
        hh::game::ObjectId doubleBoostCameraTarget;
        float doubleboostCameraInterporateTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyMetalSonicSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyMetalSonicSpawner* pInstance);
        static void Clean(EnemyMetalSonicSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTestBridgeSpawner {
        float dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTestBridgeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTestBridgeSpawner* pInstance);
        static void Clean(ObjTestBridgeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicBattleSpawner {
        uint32_t pathID;
        float quickstepWidth;
        float autoRunSpeed;
        hh::game::ObjectId entryStart;
        hh::game::ObjectId entryGoal;
        hh::game::ObjectId battle1Start;
        hh::game::ObjectId battle1Goal;
        hh::game::ObjectId battle2Start;
        hh::game::ObjectId battle2Goal;
        hh::game::ObjectId battle3Start;
        hh::game::ObjectId battle3Goal;
        hh::game::ObjectId EntryOutCamera;
        hh::game::ObjectId battle1InCamera;
        hh::game::ObjectId battle1OutCamera;
        hh::game::ObjectId battle2InCamera;
        hh::game::ObjectId battle2OutCamera;
        hh::game::ObjectId battle3InCamera;
        hh::game::ObjectId battle3OutCamera;
        hh::game::ObjectId doubleBoostStartPos;
        hh::game::ObjectId doubleBoostCameraTarget;
        float doubleboostCameraInterporateTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicBattleSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicBattleSpawner* pInstance);
        static void Clean(MetalSonicBattleSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyMotoraSpawner {
        float SerachDistance;
        float Speed;
        float MaxMoveDistance;
        bool IsEventOn;
        bool JumpAttack;
        bool IsFV;
        bool IsFallStart;
        bool isTreadGrass;
        bool updateMaterial;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyMotoraSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyMotoraSpawner* pInstance);
        static void Clean(EnemyMotoraSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct SliderMotoraDiveParameter {
        uint32_t divePathID;
        float diveSpeed;
        float phase;
        float rollStartRatio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SliderMotoraDiveParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SliderMotoraDiveParameter* pInstance);
        static void Clean(SliderMotoraDiveParameter* pInstance);
    };
}

namespace heur::rfl {
    struct EnemySliderMotoraDiveManagerSpawner {
        uint32_t pathID;
        float radius;
        float acceleration;
        float deceleration;
        float minSpeed;
        float deadDistance;
        float toExitTime;
        float brakeDistance;
        float stopTime;
        float fallTime;
        SliderMotoraDiveParameter diveParam[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemySliderMotoraDiveManagerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemySliderMotoraDiveManagerSpawner* pInstance);
        static void Clean(EnemySliderMotoraDiveManagerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct SliderMotoraGroupParameter {
        uint32_t num;
        float toNextGroupTime;
        float toExitTime;
        float offset;
        float pathOffset;
        float allOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SliderMotoraGroupParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SliderMotoraGroupParameter* pInstance);
        static void Clean(SliderMotoraGroupParameter* pInstance);
    };
}

namespace heur::rfl {
    struct EnemySliderMotoraGroupManagerSpawner {
        uint32_t pathID;
        float radius;
        float acceleration;
        float deceleration;
        float minSpeed;
        float deadDistance;
        float brakeDistance;
        float stopTime;
        float fallTime;
        SliderMotoraGroupParameter groupParam[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemySliderMotoraGroupManagerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemySliderMotoraGroupManagerSpawner* pInstance);
        static void Clean(EnemySliderMotoraGroupManagerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemySliderMotoraManagerSpawner {
        uint32_t pathID;
        float radius;
        uint32_t maxNum;
        uint32_t minNum;
        float respawnTime;
        float acceleration;
        float deceleration;
        float minSpeed;
        float offset;
        float pathOffset;
        float allOffset;
        float deadDistance;
        float brakeDistance;
        float stopTime;
        float fallTime;
        bool isRedRing;
        uint32_t ringId;
        float ringSpeed;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemySliderMotoraManagerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemySliderMotoraManagerSpawner* pInstance);
        static void Clean(EnemySliderMotoraManagerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyNarlSpawner {
        enum class NarlType : int8_t {
            TYPE_SHOT = 0,
            TYPE_FLAME = 1,
            NUM_TYPE = 2,
        };

        enum class CollisionShape : int8_t {
            SHAPE_SPHERE = 0,
            SHAPE_BOX = 1,
            NUM_SHAPE = 2,
        };

        NarlType type;
        bool isFV;
        CollisionShape collisionShape;
        csl::math::Vector3 searchExtents;
        csl::math::Vector3 searchOffset;
        float headAngle;
        bool isEventOn;
        float headPitch;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyNarlSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyNarlSpawner* pInstance);
        static void Clean(EnemyNarlSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyPotosSpawner {
        enum class StartType : int8_t {
            TYPE_IN_SEARCH_BOX = 0,
            TYPE_EVENT_ON = 1,
        };

        StartType startType;
        float moveSpeed;
        csl::ut::MoveArray32<uint32_t> locateList;
        float attackInterval;
        float searchBoxWidth;
        float searchBoxHeight;
        float searchBoxLength;
        float respawnTime;
        bool isFV;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyPotosSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyPotosSpawner* pInstance);
        static void Clean(EnemyPotosSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyValKeenSpawner {
        enum class AttackType : int8_t {
            ATK_NORMAL = 0,
            ATK_PASSING = 1,
            ATK_REVERSAL = 2,
        };

        enum class CaptureType : int8_t {
            CAP_NORMAL = 0,
            CAP_PASSING = 1,
        };

        uint32_t PathId;
        float AttackDelay;
        float MoveSpeed;
        float EscapeMoveSpeed;
        float PopSpeed;
        float PassingAddSpeed;
        float DropTime;
        float CaptureDistance;
        float CaptureDistancePassing;
        float TurnRoll;
        csl::math::Vector3 PopPosition;
        csl::math::Vector3 PathOffsetPosition;
        AttackType AtkType;
        CaptureType CapType;
        bool IsGravity;
        bool IsFV;
        bool IsRespawn;
        bool IsAttack;
        float MoveTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyValKeenSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyValKeenSpawner* pInstance);
        static void Clean(EnemyValKeenSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ChangeAisacInfo {
        csl::ut::VariableString aisacName;
        float targetAisacValue;
        float fadeTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ChangeAisacInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ChangeAisacInfo* pInstance);
        static void Clean(ChangeAisacInfo* pInstance);
    };
}

namespace heur::rfl {
    struct ObjChangeAisacVolumeSpawner {
        enum class ShapeType : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
        };

        enum class BasePoint : int8_t {
            BASE_CENTER = 0,
            BASE_Z_PLANE = 1,
        };

        ChangeAisacInfo bgm;
        ChangeAisacInfo amb;
        ShapeType shape;
        BasePoint basePoint;
        float width;
        float height;
        float depth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjChangeAisacVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjChangeAisacVolumeSpawner* pInstance);
        static void Clean(ObjChangeAisacVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjChangeBGMTriggerSpawner {
        csl::ut::VariableString cueName;
        float fadeOutTime;
        float playDelayTime;
        float fadeInTime;
        float width;
        float height;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjChangeBGMTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjChangeBGMTriggerSpawner* pInstance);
        static void Clean(ObjChangeBGMTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjChangeGlobalAmbSoundCollisionSpawner {
        csl::ut::VariableString ambSEName;
        float fadeTime;
        float width;
        float height;
        float length;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjChangeGlobalAmbSoundCollisionSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjChangeGlobalAmbSoundCollisionSpawner* pInstance);
        static void Clean(ObjChangeGlobalAmbSoundCollisionSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjChangeGlobalAmbSoundPlaneSpawner {
        csl::ut::VariableString ambSEName;
        float fadeTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjChangeGlobalAmbSoundPlaneSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjChangeGlobalAmbSoundPlaneSpawner* pInstance);
        static void Clean(ObjChangeGlobalAmbSoundPlaneSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSoundSourceSpawner {
        enum class PlayMode : int8_t {
            PLAYMODE_LOOP = 0,
            PLAYMODE_ONE_SHOT = 1,
            PLAYMODE_PERIODIC = 2,
        };

        csl::ut::VariableString cueName;
        PlayMode playMode;
        float timeOffset;
        float playInterval;
        float volume;
        float hearingRange;
        float undampedRange;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSoundSourceSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSoundSourceSpawner* pInstance);
        static void Clean(ObjSoundSourceSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjOneShotSoundTriggerSpawner {
        enum class SoundPositionType : int8_t {
            SOUND_POS_CENTER = 0,
            SOUND_POS_MANUAL = 1,
        };

        enum class ShapeType : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
        };

        enum class BasePoint : int8_t {
            BASE_CENTER = 0,
            BASE_Z_PLANE = 1,
        };

        csl::ut::VariableString cueName;
        float volume;
        bool isPlay3D;
        SoundPositionType soundPositionType;
        csl::math::Vector3 soundPosition;
        ShapeType shape;
        BasePoint basePoint;
        float width;
        float height;
        float depth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjOneShotSoundTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjOneShotSoundTriggerSpawner* pInstance);
        static void Clean(ObjOneShotSoundTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPathSoundSourceSpawner : ObjSoundSourceSpawner {
        uint32_t pathID;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPathSoundSourceSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPathSoundSourceSpawner* pInstance);
        static void Clean(ObjPathSoundSourceSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPointSoundSourceSpawner : ObjSoundSourceSpawner {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPointSoundSourceSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPointSoundSourceSpawner* pInstance);
        static void Clean(ObjPointSoundSourceSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBalloon2Spawner {
        enum class Dimension : int8_t {
            DIM_SV = 0,
            DIM_FV = 1,
        };

        Dimension dimension;
        float upSpeed;
        float speedMin;
        float speedMax;
        float respawnTime;
        bool isDefaultPositionRespawn;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBalloon2Spawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBalloon2Spawner* pInstance);
        static void Clean(ObjBalloon2Spawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyGalagaBeeGeneratorSpawner {
        enum class HomingDirection : int8_t {
            Forward = 0,
            Reverse = 1,
        };

        uint32_t pathID;
        uint32_t numBees;
        uint32_t numFirstBees;
        float appearSpan;
        float moveSpeed;
        hh::game::ObjectId startPosObj;
        hh::game::ObjectId endPosObj;
        bool repat;
        uint8_t pad1[3];
        float repeatSpanTime;
        bool homingReBound;
        HomingDirection homingDir;
        uint8_t pad2[2];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyGalagaBeeGeneratorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyGalagaBeeGeneratorSpawner* pInstance);
        static void Clean(EnemyGalagaBeeGeneratorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGoldenMotoraSpawner {
        enum class RingType : int8_t {
            TYPE_NORMAL = 0,
            TYPE_SUPER = 1,
            TYPE_RED = 2,
        };

        float speed;
        float moveSpeed;
        float maxMoveDist;
        bool isFV;
        bool eventDriven;
        csl::ut::MoveArray32<uint32_t> locaterList;
        RingType ringType;
        int32_t ringId;
        bool isBound;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;
        bool updateMaterial;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGoldenMotoraSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGoldenMotoraSpawner* pInstance);
        static void Clean(ObjGoldenMotoraSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRotateThornBallSpawner {
        enum class RotateType : int8_t {
            TYPE_RIGHT = 0,
            TYPE_LEFT = 1,
        };

        enum class AreaType : int8_t {
            AREA_FV = 0,
            AREA_SV = 1,
            AREA_AIR = 2,
        };

        enum class StartType : int8_t {
            START_WAIT = 0,
            START_ROTATE = 1,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        RotateType rotateType;
        uint16_t radius;
        float angularVelocity;
        AreaType areaType;
        StartType startType;
        TimeType timeType;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRotateThornBallSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRotateThornBallSpawner* pInstance);
        static void Clean(ObjRotateThornBallSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSliderThornBallBuilderSpawner {
        enum class BuildeType : int8_t {
            BUILDE_NONE = 0,
            BUILDE_LOOP = 1,
        };

        BuildeType BuildeType;
        uint32_t BuildeNum;
        float BuildeInterval;
        uint32_t PathId;
        bool IsReverse;
        float OffsetRadius;
        float MoveSpeed;
        float MeanderingDistance;
        float MeanderingCycle;
        float MeanderingPhase;
        float limitTime;
        float OverTime;
        uint32_t ColumnNum;
        uint32_t RowNum;
        float ColumnOffset;
        float RowOffset;
        bool IsEvent;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSliderThornBallBuilderSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSliderThornBallBuilderSpawner* pInstance);
        static void Clean(ObjSliderThornBallBuilderSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjVirtronInfernoSpawner {
        float angle;
        float radius;
        float speed;
        float aliveTime;
        float waitTime;
        float phase;
        bool isGlobalTime;
        bool isSpawnImm;
        bool eventDriven;
        bool disappearAll;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjVirtronInfernoSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjVirtronInfernoSpawner* pInstance);
        static void Clean(ObjVirtronInfernoSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjVirtronKillerSpawner {
        enum class SizeType : int8_t {
            TYPE_LARGE = 0,
            TYPE_NORMAL = 1,
            TYPE_SMALL = 2,
        };

        SizeType sizeType;
        bool isTrace;
        float speed;
        float lifeTime;
        float endTime;
        float rotateMax;
        float despawnRange;
        float scalingTime;
        float dashRange;
        float chargeTime;
        float dashSpeed;
        float dashEndLength;
        float firstSpeed;
        float firstTime;
        uint32_t repeatNum;
        float repeatInterval;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjVirtronKillerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjVirtronKillerSpawner* pInstance);
        static void Clean(ObjVirtronKillerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBalloonSpawner {
        enum class Color : int8_t {
            COLOR_BLUE = 0,
            COLOR_GREEN = 1,
            COLOR_RED = 2,
            COLOR_YELLOW = 3,
            NUM_COLORS = 4,
        };

        enum class Dimension : int8_t {
            DIM_SV = 0,
            DIM_FV = 1,
        };

        Color balloonColor;
        Dimension dimension;
        float upSpeed;
        float speedMin;
        float speedMax;
        float respawnTime;
        bool isDefaultPositionRespawn;
        bool isGroupSet;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBalloonSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBalloonSpawner* pInstance);
        static void Clean(ObjBalloonSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBombBlockSpawner {
        enum class ModelType : int8_t {
            DEFAULT = 0,
            DARK_PLACE = 1,
        };

        enum class LODType : int8_t {
            LOD_LOW = 0,
            LOD_HIGH = 1,
        };

        uint32_t count;
        ModelType modelType;
        LODType lodType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBombBlockSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBombBlockSpawner* pInstance);
        static void Clean(ObjBombBlockSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFlameSpawner {
        enum class LengthType : int8_t {
            LENGTH_2M = 0,
            LENGTH_4M = 1,
            LENGTH_6M = 2,
            LENGTH_8M = 3,
            LENGTH_10M = 4,
            NUM_LENGTH_TYPES = 5,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        enum class Type : int8_t {
            TYPE_ON_OFF = 0,
            TYPE_ON_ONLY = 1,
            TYPE_OFF_ONLY = 2,
        };

        float offTime;
        float onTime;
        LengthType lengthType;
        TimeType timeType;
        float phase;
        Type type;
        bool eventDriven;
        float pitchRotation;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFlameSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFlameSpawner* pInstance);
        static void Clean(ObjFlameSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFlyingPodSpawner {
        enum class ThrowType : int8_t {
            THROWTYPE_TOPLAYER = 0,
            THROWTYPE_RANDOM = 1,
        };

        float relativePos;
        uint32_t pathId;
        float maxDistanceLeft;
        float maxDistanceRight;
        float firstShotInterval;
        float shotInterval;
        float ringOdds;
        bool isPlayAppearAnim;
        float appearTime;
        ThrowType throwType;
        float escapeTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFlyingPodSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFlyingPodSpawner* pInstance);
        static void Clean(ObjFlyingPodSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPlasmaCannonSpawner {
        enum class BarrageType : int8_t {
            BARRAGE_ONE_ROLL = 0,
            BARRAGE_FIREWORKS = 1,
            BARRAGE_PROPELLER = 2,
            BARRAGE_FAN = 3,
            BARRAGE_FAN_WAVE = 4,
        };

        float shotSpeed;
        float shotInterval;
        float barrageInterval;
        float shotLifeTime;
        BarrageType barrageType;
        float phase;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPlasmaCannonSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPlasmaCannonSpawner* pInstance);
        static void Clean(ObjPlasmaCannonSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjReproductionBlockSpawner {
        enum class BasePoint : int8_t {
            BASE_BOTTOM = 0,
            BASE_TOP = 1,
        };

        float respawnTime;
        BasePoint basePoint;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjReproductionBlockSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjReproductionBlockSpawner* pInstance);
        static void Clean(ObjReproductionBlockSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSpinLaserSpawner {
        enum class SpinType : int8_t {
            SPINTYPE_CLOCK = 0,
            SPINTYPE_UNTICLOCK = 1,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        SpinType spinType;
        float spinSpeed;
        float initialAngle;
        float laserLength;
        TimeType timeType;
        bool isPenetration;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSpinLaserSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSpinLaserSpawner* pInstance);
        static void Clean(ObjSpinLaserSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTimePeriodLightFloorSpawner {
        enum class FloorType : int8_t {
            FLOORTYPE_2x3 = 0,
            FLOORTYPE_3x3 = 1,
            FLOORTYPE_5x3 = 2,
            NUM_FLOORS = 3,
        };

        enum class PivotType : int8_t {
            PIVOTTYPE_LEFT = 0,
            PIVOTTYPE_CENTER = 1,
            PIVOTTYPE_RIGHT = 2,
        };

        FloorType floorType;
        PivotType pivotType;
        float timeUntilBlink;
        float blinkTime;
        float respawnTime;
        bool isOneway;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTimePeriodLightFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTimePeriodLightFloorSpawner* pInstance);
        static void Clean(ObjTimePeriodLightFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBombEventSpawner {
        enum class Scene : int8_t {
            SCENE_ALL = 0,
            SCENE_SOUND = 1,
            SCENE_BALLISTIC = 2,
        };

        enum class EffectLodType : int8_t {
            EFFECT_LOW = 0,
            EFFECT_HIGH = 1,
        };

        enum class Event : int8_t {
            EVENT_ON = 0,
            EVENT_OFF = 1,
        };

        uint32_t pathid;
        float speed;
        bool once;
        Scene scene;
        EffectLodType effectLod;
        float effectScale;
        csl::ut::MoveArray32<uint32_t> targets0;
        Event event0;
        float timer0;
        csl::ut::MoveArray32<uint32_t> targets1;
        Event event1;
        float timer1;
        csl::ut::MoveArray32<uint32_t> targets2;
        Event event2;
        float timer2;
        csl::ut::MoveArray32<uint32_t> gismoTargets;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBombEventSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBombEventSpawner* pInstance);
        static void Clean(ObjBombEventSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBreakableBridgeSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBreakableBridgeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBreakableBridgeSpawner* pInstance);
        static void Clean(ObjBreakableBridgeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBreakableRoadBarricadeSpawner {
        uint32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBreakableRoadBarricadeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBreakableRoadBarricadeSpawner* pInstance);
        static void Clean(ObjBreakableRoadBarricadeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBreakableRoadConeSpawner {
        uint32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBreakableRoadConeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBreakableRoadConeSpawner* pInstance);
        static void Clean(ObjBreakableRoadConeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBreakableWallSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBreakableWallSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBreakableWallSpawner* pInstance);
        static void Clean(ObjBreakableWallSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBreakableWoodBoxSpawner {
        uint32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBreakableWoodBoxSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBreakableWoodBoxSpawner* pInstance);
        static void Clean(ObjBreakableWoodBoxSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDeathEggRoboSpawner {
        uint32_t pathID;
        float initialSpeed;
        float acceleration;
        float minSpeed;
        float maxSpeed;
        hh::game::ObjectId bridge;
        hh::game::ObjectId platform;
        csl::math::Vector3 point;
        hh::game::ObjectId eventEnd;
        csl::math::Vector3 endVelocity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDeathEggRoboSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDeathEggRoboSpawner* pInstance);
        static void Clean(ObjDeathEggRoboSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDeathEggRoboBGMStopColSpawner {
        float height;
        float wide;
        float length;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDeathEggRoboBGMStopColSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDeathEggRoboBGMStopColSpawner* pInstance);
        static void Clean(ObjDeathEggRoboBGMStopColSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDeathEggRoboFarSpawner {
        float startTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDeathEggRoboFarSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDeathEggRoboFarSpawner* pInstance);
        static void Clean(ObjDeathEggRoboFarSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjAuraTrainSpawner {
        enum class PoleType : int8_t {
            POLETYPE_LEFT = 0,
            POLETYPE_RIGHT = 1,
        };

        uint32_t pathId;
        float moveSpeed;
        PoleType poleType;
        float coutDownTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjAuraTrainSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjAuraTrainSpawner* pInstance);
        static void Clean(ObjAuraTrainSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBeehiveSpawner {
        enum class Color : int8_t {
            COLOR_A = 0,
            COLOR_B = 1,
            COLOR_C = 2,
            COLOR_D = 3,
            NUM_COLORS = 4,
            COLOR_RANDOM = 5,
        };

        float radius;
        int32_t baseNum;
        int32_t fallRounds;
        Color color;
        bool existWall;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBeehiveSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBeehiveSpawner* pInstance);
        static void Clean(ObjBeehiveSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBeltConveyorSpawner {
        enum class Rotatedir : int8_t {
            ROTATEDIR_CLOCK = 0,
            ROTATEDIR_ANTICLOCK = 1,
        };

        uint32_t segmentNum;
        Rotatedir rotateDir;
        float rotateSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBeltConveyorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBeltConveyorSpawner* pInstance);
        static void Clean(ObjBeltConveyorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBeltConveyorMoveSpawner {
        enum class Rotatedir : int8_t {
            ROTATEDIR_CLOCK = 0,
            ROTATEDIR_ANTICLOCK = 1,
        };

        enum class PlayType : int8_t {
            PLAYTYPE_STOP = 0,
            PLAYTYPE_ROUND_TRIP = 1,
            PLAYTYPE_LOOP = 2,
        };

        enum class PoleType : int8_t {
            POLE_TYPE_1 = 0,
            POLE_TYPE_2 = 1,
            POLE_TYPE_3 = 2,
        };

        uint32_t pathId;
        Rotatedir rotateDir;
        float rotateSpeed;
        float moveSpeed;
        PlayType playType;
        PoleType poleType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBeltConveyorMoveSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBeltConveyorMoveSpawner* pInstance);
        static void Clean(ObjBeltConveyorMoveSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCupFootingSpawner {
        enum class MoveType : int8_t {
            MOVETYPE_LEFT_TO_TOP = 0,
            MOVETYPE_LEFT_TO_BOTTOM = 1,
            MOVETYPE_RIGHT_TO_TOP = 2,
            MOVETYPE_RIGHT_TO_BOTTOM = 3,
            MOVETYPE_TOP_TO_LEFT = 4,
            MOVETYPE_TOP_TO_RIGHT = 5,
            MOVETYPE_BOTTOM_TO_LEFT = 6,
            MOVETYPE_BOTTOM_TO_RIGHT = 7,
        };

        float chainLength;
        MoveType moveType;
        float rotateVelocity;
        float waitTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCupFootingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCupFootingSpawner* pInstance);
        static void Clean(ObjCupFootingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDamageHeaterSpawner {
        uint32_t segmentNum;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDamageHeaterSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDamageHeaterSpawner* pInstance);
        static void Clean(ObjDamageHeaterSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDownCeilingSpawner {
        enum class SizeType : int8_t {
            SIZE_SMALL = 0,
            SIZE_BIG = 1,
        };

        SizeType sizeType;
        bool hide;
        float height;
        float fallTime;
        float fastFallDistance;
        float fastFallTime;
        bool isLoop;
        float riseWaitTime;
        float riseTime;
        float fallWaitTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDownCeilingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDownCeilingSpawner* pInstance);
        static void Clean(ObjDownCeilingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDownCeilingAppearVolumeSpawner {
        enum class Type : int8_t {
            TYPE_APPEAR = 0,
            TYPE_DISAPPEAR = 1,
        };

        Type type;
        csl::ut::MoveArray32<uint32_t> targets;
        csl::math::Vector3 size;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDownCeilingAppearVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDownCeilingAppearVolumeSpawner* pInstance);
        static void Clean(ObjDownCeilingAppearVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDownLiftSpawner {
        float startTimeLag;
        float distance;
        float speed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDownLiftSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDownLiftSpawner* pInstance);
        static void Clean(ObjDownLiftSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjElevatorSpawner {
        bool isLoop;
        csl::math::Vector3 moveVector;
        float speed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjElevatorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjElevatorSpawner* pInstance);
        static void Clean(ObjElevatorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjInductionLaserTurretSpawner {
        csl::math::Vector3 searchBoxExtents;
        csl::math::Vector3 searchBoxOffset;
        float laserSpeed;
        float laserHomingKeepTime;
        float laserRotateAngleMax;
        float laserNonHomingLength;
        float chargeTime;
        float laserRange;
        float fireInterval;
        float attackAfterWaitTime;
        uint32_t launchLaserNum;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjInductionLaserTurretSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjInductionLaserTurretSpawner* pInstance);
        static void Clean(ObjInductionLaserTurretSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjLaserFootingSpawner {
        uint32_t pathId;
        float lightingTime;
        float lightOffTime;
        float firstWaitTime;
        bool isOnewayFooting;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjLaserFootingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjLaserFootingSpawner* pInstance);
        static void Clean(ObjLaserFootingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraLimitedPanSpawner : ObjCameraSpawner {
        enum class PositionMode : int8_t {
            POS_MODE_FIX = 0,
            POS_MODE_MAINTAIN_DISTANCE = 1,
        };

        float fovy;
        csl::math::Vector3 atBase;
        float atRadius;
        float playerRadius;
        float atOffsetY;
        PositionMode positionMode;
        float distance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraLimitedPanSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraLimitedPanSpawner* pInstance);
        static void Clean(ObjCameraLimitedPanSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRotBlocksSpawner {
        enum class MoveType : int8_t {
            AROUND = 0,
            STAIRS = 1,
        };

        MoveType moveType;
        bool eventDriven;
        bool isClockWise;
        float rotateTime;
        float rotateWaitTime;
        float phase;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRotBlocksSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRotBlocksSpawner* pInstance);
        static void Clean(ObjRotBlocksSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjClassicRotBlocksSpawner {
        enum class MoveType : int8_t {
            MOVE_VERTICAL = 0,
            MOVE_HORIZONTAL = 1,
            AROUND_LEFT = 2,
            AROUND_RIGHT = 3,
        };

        MoveType moveType;
        uint32_t numBlock;
        float blockExtents;
        bool eventDriven;
        float moveRatio;
        float offsetRatio;
        float moveTime;
        float moveWaitTime;
        float phase;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjClassicRotBlocksSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjClassicRotBlocksSpawner* pInstance);
        static void Clean(ObjClassicRotBlocksSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjShutterSpawner {
        float slideTime;
        float fastSlideDistance;
        float fastSlideTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjShutterSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjShutterSpawner* pInstance);
        static void Clean(ObjShutterSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjStairsBlocksSpringSpawner {
        bool eventDriven;
        bool isClockWise;
        float moveTime;
        float velocity;
        float outOfControl;
        float keepVelocityDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjStairsBlocksSpringSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjStairsBlocksSpringSpawner* pInstance);
        static void Clean(ObjStairsBlocksSpringSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWallCannonSpawner {
        float chargeTime;
        float waitTime;
        float bulletSpeed;
        float firstShotTime;
        float existDistance;
        float phase;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWallCannonSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWallCannonSpawner* pInstance);
        static void Clean(ObjWallCannonSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBigFanSpawner {
        enum class RotationType : int8_t {
            CLOCK_ROTATION = 0,
            COUNTERCLOCKWISE_ROTATION = 1,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        float rotationalSpeed;
        float phase;
        RotationType rotationType;
        TimeType timeType;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBigFanSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBigFanSpawner* pInstance);
        static void Clean(ObjBigFanSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCircleDoorSpawner {
        float openDistance;
        float closeDistance;
        bool onlyFirstTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCircleDoorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCircleDoorSpawner* pInstance);
        static void Clean(ObjCircleDoorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCraneFookSpawner {
        int32_t pathId;
        float startPos;
        float dropFrondDistance;
        float wireLength;
        float minSpeed;
        float maxSpeed;
        float shootAngle;
        float shootSpeed;
        float outOfControl;
        ObjectEventData event0;
        ObjectEventData event1;
        ObjectEventData event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCraneFookSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCraneFookSpawner* pInstance);
        static void Clean(ObjCraneFookSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPipeCoverSpawner {
        float dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPipeCoverSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPipeCoverSpawner* pInstance);
        static void Clean(ObjPipeCoverSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPipeExitSpawner {
        enum class SpringType : int8_t {
            SPRINGTYPE_YELLOW = 0,
            SPRINGTYPE_RED = 1,
            SPRINGTYPE_MODERN = 2,
        };

        SpringType springType;
        float velocity;
        float outOfControl;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPipeExitSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPipeExitSpawner* pInstance);
        static void Clean(ObjPipeExitSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSprayWaterColliderSpawner {
        csl::math::Vector3 colliderHalfExtents;
        csl::math::Vector3 offset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSprayWaterColliderSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSprayWaterColliderSpawner* pInstance);
        static void Clean(ObjSprayWaterColliderSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTrainSceneSpawner {
        csl::math::Vector3 playerPositionOnSuccess;
        csl::math::Vector3 playerPositionOnFailed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTrainSceneSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTrainSceneSpawner* pInstance);
        static void Clean(ObjTrainSceneSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjUpWaterLevelSpawner {
        float upSpeed;
        float maxSizeX;
        float maxSizeY;
        float maxSizeZ;
        float underSize;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjUpWaterLevelSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjUpWaterLevelSpawner* pInstance);
        static void Clean(ObjUpWaterLevelSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWaterFallSpawner {
        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        enum class ModelType : int8_t {
            MODEL_1 = 0,
            MODEL_2 = 1,
            MODEL_3 = 2,
            MODEL_NUMS = 3,
        };

        float foretasteTime;
        float bigEffectStartCountTime;
        float modelFallBeforeSpeed;
        float modelFallAfterSpeed;
        float fallingTime;
        float waitingTime;
        float fallingSpeed;
        float phase;
        TimeType timeType;
        ModelType modelType;
        bool eventDriven;
        bool userOwnParam;
        bool ornament;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWaterFallSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWaterFallSpawner* pInstance);
        static void Clean(ObjWaterFallSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWaterWheelFloorSpawner {
        enum class FloorSize : int8_t {
            SIZE_A = 0,
            SIZE_B = 1,
            SIZE_C = 2,
        };

        float maxAngularSpeed;
        float accelerationTime;
        float autoDecelerationTime;
        float waterDecelerationTime;
        float speedKeepTime;
        float initPhase;
        float stopPhase;
        float radius;
        uint32_t floorCount;
        FloorSize floorSize;
        bool isOneway;
        bool isStopPosition;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWaterWheelFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWaterWheelFloorSpawner* pInstance);
        static void Clean(ObjWaterWheelFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDeathEggRoboNearSpawner {
        float accele;
        float decele;
        float max;
        float maxAngle;
        float blendRatio;
        float headAngle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDeathEggRoboNearSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDeathEggRoboNearSpawner* pInstance);
        static void Clean(ObjDeathEggRoboNearSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjAutoFlipperSpawner {
        float impluse;
        float outOfControlTime;
        float reactionRange;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjAutoFlipperSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjAutoFlipperSpawner* pInstance);
        static void Clean(ObjAutoFlipperSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBigSnakeSpawner {
        csl::math::Vector3 playerPositionOnSuccess;
        csl::math::Vector3 playerPositionOnFail;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBigSnakeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBigSnakeSpawner* pInstance);
        static void Clean(ObjBigSnakeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBomberSpawner {
        enum class MoveType : int8_t {
            MOVE_ONCE = 0,
            MOVE_LOOP = 1,
        };

        int32_t num;
        float interval;
        float lineOffset;
        MoveType moveType;
        float distance;
        float speed;
        bool dropBomb;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBomberSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBomberSpawner* pInstance);
        static void Clean(ObjBomberSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBrambleThornSpawner {
        enum class Type : int8_t {
            TYPE_FV_A = 0,
            TYPE_FV_B = 1,
            TYPE_SV = 2,
            TYPE_SLIDER = 3,
            TYPE_SLIDER_SPLASH = 4,
            NUM_TYPES = 5,
        };

        Type type;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBrambleThornSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBrambleThornSpawner* pInstance);
        static void Clean(ObjBrambleThornSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBumperSpawner {
        float impluse;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBumperSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBumperSpawner* pInstance);
        static void Clean(ObjBumperSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCasinoPocketSpawner {
        enum class BehaviorType : int8_t {
            SCORE = 0,
            SLOT = 1,
        };

        BehaviorType type;
        uint32_t rateJackpot;
        uint32_t rateSonic;
        uint32_t rateSonicJP1;
        uint32_t rateSonicJP2;
        uint32_t rateTails;
        uint32_t rateTailsJP1;
        uint32_t rateTailsJP2;
        uint32_t rateBar3;
        uint32_t rateBar2;
        uint32_t rateBar1;
        uint32_t rateRing;
        uint32_t rateRingJP1;
        uint32_t rateRingJP2;
        uint32_t rateEggman;
        uint32_t rateEggmanJP1;
        uint32_t rateEggmanJP2;
        uint32_t rateOut;
        hh::game::ObjectId targetSlot;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCasinoPocketSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCasinoPocketSpawner* pInstance);
        static void Clean(ObjCasinoPocketSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCasinoSlotSpawner {
        int32_t cashJackpot;
        int32_t cashSonic;
        int32_t cashTails;
        int32_t cashBar3;
        int32_t cashBar2;
        int32_t cashBar1;
        int32_t cashRing;
        int32_t cashEggman;
        float rateJP1;
        float rateJP2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCasinoSlotSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCasinoSlotSpawner* pInstance);
        static void Clean(ObjCasinoSlotSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFlipperSpawner {
        float firstSpeed;
        float outOfControlTime;
        float keepVelocityTime;
        float minAngle;
        float maxAngle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFlipperSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFlipperSpawner* pInstance);
        static void Clean(ObjFlipperSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjHexagonBumperSpawner {
        float moveSpeed;
        csl::math::Vector3 destination;
        float phase;
        bool eventDriven;
        float firstSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjHexagonBumperSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjHexagonBumperSpawner* pInstance);
        static void Clean(ObjHexagonBumperSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMiniIronBallBarSpawner {
        enum class RotateDir : int8_t {
            ROTATEDIR_CLOCK = 0,
            FRONTDIR_ANTICLOCK = 1,
        };

        enum class StandDir : int8_t {
            STANDDIR_UP = 0,
            STANDDIR_DOWN = 1,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        RotateDir rotateDir;
        float velocity;
        int32_t numIronBall;
        float phase;
        StandDir standDir;
        TimeType timeType;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMiniIronBallBarSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMiniIronBallBarSpawner* pInstance);
        static void Clean(ObjMiniIronBallBarSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMoveRingBuilderSpawner {
        enum class RingType : int8_t {
            RING_NORMAL = 0,
            RING_SUPER = 1,
            RING_RED = 2,
        };

        enum class BuildeType : int8_t {
            BUILDE_NONE = 0,
            BUILDE_LOOP = 1,
        };

        RingType RingType;
        BuildeType BuildeType;
        uint32_t BuildeNum;
        float BuildeInterval;
        uint32_t ItemId;
        uint32_t PathId;
        bool IsReverse;
        float OffsetRadius;
        float MoveSpeed;
        float MeanderingDistance;
        float MeanderingCycle;
        float MeanderingPhase;
        float limitTime;
        float OverTime;
        uint32_t ColumnNum;
        uint32_t RowNum;
        float ColumnOffset;
        float RowOffset;
        bool IsEvent;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMoveRingBuilderSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMoveRingBuilderSpawner* pInstance);
        static void Clean(ObjMoveRingBuilderSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjObstacleWallSpawner {
        int32_t maxHealthPoint;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjObstacleWallSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjObstacleWallSpawner* pInstance);
        static void Clean(ObjObstacleWallSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPlungerSpawner {
        float minImpulse;
        float maxImpulse;
        float outOfControlTime;
        float keepVelocityTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPlungerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPlungerSpawner* pInstance);
        static void Clean(ObjPlungerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSelfBreakWallSpawner {
        float toBreakTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSelfBreakWallSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSelfBreakWallSpawner* pInstance);
        static void Clean(ObjSelfBreakWallSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSlingshotSpawner {
        float impluse;
        float angle;
        bool useAngleL;
        float angleL;
        bool useAngleR;
        float angleR;
        bool mirror;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSlingshotSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSlingshotSpawner* pInstance);
        static void Clean(ObjSlingshotSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSnakeRoadSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSnakeRoadSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSnakeRoadSpawner* pInstance);
        static void Clean(ObjSnakeRoadSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSpringBigSpawner {
        uint32_t pathUID;
        float speed;
        float keepVelocityTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSpringBigSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSpringBigSpawner* pInstance);
        static void Clean(ObjSpringBigSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTorrentWallSpawner {
        int32_t maxHealthPoint;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTorrentWallSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTorrentWallSpawner* pInstance);
        static void Clean(ObjTorrentWallSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTriangleBumperSpawner {
        enum class ShapeType : int8_t {
            SHAPE_TYPE_CORNER = 0,
            SHAPE_TYPE_SPATULATE = 1,
        };

        enum class RiditType : int8_t {
            RIDIT_TYPE_CORNER = 0,
            RIDIT_TYPE_CENTER = 1,
        };

        ShapeType shapeType;
        RiditType riditType;
        float firstSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTriangleBumperSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTriangleBumperSpawner* pInstance);
        static void Clean(ObjTriangleBumperSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjVanishBumperSpawner {
        float impluse;
        float outOfControlTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjVanishBumperSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjVanishBumperSpawner* pInstance);
        static void Clean(ObjVanishBumperSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjVirtualRealityThornSpawner {
        enum class MoveType : int8_t {
            TYPE_APPEAR = 0,
            TYPE_DISAPPEAR = 1,
            TYPE_MOVE = 2,
            TYPE_ONESHOT = 3,
        };

        uint32_t pathID;
        csl::math::Vector2 interval;
        float depth;
        float offTime;
        float onTime;
        float phase;
        MoveType type;
        bool showBase;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjVirtualRealityThornSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjVirtualRealityThornSpawner* pInstance);
        static void Clean(ObjVirtualRealityThornSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjVirtualRealityThornBallSpawner {
        enum class Direction : int8_t {
            TYPE_RIGHT = 0,
            TYPE_LEFT = 1,
        };

        Direction type;
        uint32_t pathID;
        float time;
        float phase;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjVirtualRealityThornBallSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjVirtualRealityThornBallSpawner* pInstance);
        static void Clean(ObjVirtualRealityThornBallSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBossStageFloorSpawner {
        enum class FrontDir : int8_t {
            FRONTDIR_LEFT = 0,
            FRONTDIR_RIGHT = 1,
        };

        FrontDir frontDir;
        float signTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBossStageFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBossStageFloorSpawner* pInstance);
        static void Clean(ObjBossStageFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBreakableArchSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBreakableArchSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBreakableArchSpawner* pInstance);
        static void Clean(ObjBreakableArchSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBreakCliffSpawner {
        enum class FrontDir : int8_t {
            FRONTDIR_LEFT = 0,
            FRONTDIR_RIGHT = 1,
        };

        int32_t numCliff;
        FrontDir frontDir;
        float toSignTime;
        float signTime;
        float resetTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBreakCliffSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBreakCliffSpawner* pInstance);
        static void Clean(ObjBreakCliffSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFloatingFloorSpawner {
        enum class SizeType : int8_t {
            SIZE_3M = 0,
            SIZE_4M = 1,
            SIZE_5M = 2,
            SIZE_7M = 3,
            SIZE_10M = 4,
            SIZE_TYPE_MAX = 5,
        };

        enum class MoveType : int8_t {
            MOVE_NONE = 0,
            MOVE_POINT = 1,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        SizeType sizeType;
        MoveType moveType;
        TimeType timeType;
        bool eventDriven;
        bool isOneway;
        csl::math::Vector3 moveVector;
        float waitTime;
        float phase;
        float speed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFloatingFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFloatingFloorSpawner* pInstance);
        static void Clean(ObjFloatingFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGCLegSpawner {
        enum class EffectType : int8_t {
            TYPE_GROUND_A = 0,
            TYPE_GROUND_B = 1,
            TYPE_FLOOR = 2,
        };

        float fallWait;
        float riseWait;
        float phase;
        csl::ut::MoveArray32<uint32_t> targetWoodBridge;
        EffectType effectType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGCLegSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGCLegSpawner* pInstance);
        static void Clean(ObjGCLegSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGCLegEventSwitchVolumeSpawner {
        csl::ut::MoveArray32<uint32_t> targets;
        csl::math::Vector3 size;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGCLegEventSwitchVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGCLegEventSwitchVolumeSpawner* pInstance);
        static void Clean(ObjGCLegEventSwitchVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGearFootingSpawner {
        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        enum class GearType : int8_t {
            GEAR_TYPE_STANDING_8M = 0,
            GEAR_TYPE_STANDING_12M = 1,
            GEAR_TYPE_LIE_DOWN_8M = 2,
            GEAR_TYPE_LIE_DOWN_10M = 3,
            GEAR_TYPE_LIE_DOWN_16M = 4,
            GEAR_TYPE_LIE_DOWN_10M_5 = 5,
            GEAR_TYPE_MAX = 6,
        };

        enum class RotateType : int8_t {
            ROTATE_LEFT = 0,
            ROTATE_RIGHT = 1,
        };

        enum class AxisType : int8_t {
            AXIS_ON = 0,
            AXIS_OFF = 1,
        };

        enum class EasingType : int8_t {
            EASE_LINER = 0,
            EASE_QUADRATIC = 1,
            EASE_CUBIC = 2,
            EASE_QUARTIC = 3,
            EASE_QUINTIC = 4,
            EASE_SINE = 5,
            EASE_EXPONENTIAL = 6,
            EASE_CIRCULAR = 7,
            EASE_BACK = 8,
            EASE_BOUNCE = 9,
            EASE_ELASTIC = 10,
        };

        TimeType timeType;
        GearType gearType;
        int8_t numGears;
        RotateType rotateType;
        AxisType axisType;
        bool eventDriven;
        float speed;
        float moveTime;
        float idleTime;
        float phase;
        float moveDistance;
        EasingType easingType;
        int32_t numRepeats;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGearFootingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGearFootingSpawner* pInstance);
        static void Clean(ObjGearFootingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBrokenGiantCrabSpawner {
        float scale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBrokenGiantCrabSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBrokenGiantCrabSpawner* pInstance);
        static void Clean(ObjBrokenGiantCrabSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGiantCrabSpawner {
        uint32_t pathID;
        uint32_t goalPathID;
        float speed;
        float stepWidth;
        hh::game::ObjectId eventStartPosObj;
        hh::game::ObjectId eventEndPosObj;
        hh::game::ObjectId eventBrokenObject;
        hh::game::ObjectId cameraObj;
        float cameraEaseTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGiantCrabSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGiantCrabSpawner* pInstance);
        static void Clean(ObjGiantCrabSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ChangeMotionData {
        enum class MotionType : int8_t {
            TYPE_IDLE = 0,
            TYPE_WALK = 1,
            TYPE_WALK_STAGE_START = 2,
            TYPE_RAGE = 3,
            TYPE_JUMP = 4,
        };

        enum class MotionChangeType : int8_t {
            CHANGE_TYPE_EVENT = 0,
            CHANGE_TYPE_TIME = 1,
        };

        bool isNext;
        MotionType motionType;
        MotionChangeType motionChangeType;
        float changeWaitTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ChangeMotionData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ChangeMotionData* pInstance);
        static void Clean(ChangeMotionData* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGiantCrabFarSpawner {
        uint32_t pathID;
        float speedRatio;
        float scale;
        bool defaultVisible;
        bool isSoundON;
        ChangeMotionData motionDatas[3];
        csl::ut::MoveArray32<uint32_t> targets;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGiantCrabFarSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGiantCrabFarSpawner* pInstance);
        static void Clean(ObjGiantCrabFarSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjHangingFloorSpawner {
        enum class SizeType : int8_t {
            SIZE_3M = 0,
            SIZE_4M = 1,
            SIZE_5M = 2,
            SIZE_7M = 3,
            SIZE_TYPE_MAX = 4,
        };

        enum class StartPoint : int8_t {
            START_LEFT = 0,
            START_RIGHT = 1,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        SizeType sizeType;
        StartPoint startPoint;
        TimeType timeType;
        uint16_t chainNum;
        float rotation;
        float speed;
        float phase;
        bool isOneway;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjHangingFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjHangingFloorSpawner* pInstance);
        static void Clean(ObjHangingFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjInfraredLaserSpawner {
        float speed;
        float phase;
        bool eventDriven;
        bool isGrew;
        bool randomPhase;
        float phaseMin;
        float phaseMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjInfraredLaserSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjInfraredLaserSpawner* pInstance);
        static void Clean(ObjInfraredLaserSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjInfraredLaserWallSpawner {
        enum class LaserOrder : int8_t {
            LEFT_TO_RIGHT = 0,
            RIGTH_TO_LEFT = 1,
            CENTER_TO_SIDE = 2,
        };

        float radius;
        LaserOrder setOrder;
        int32_t num;
        float setInterval;
        float offset;
        float speed;
        float firingPhase;
        bool eventDriven;
        bool isDrawRing;
        bool isRotate;
        float rotatePhase;
        float rotateSpeed;
        bool isGrew;
        bool randomPhase;
        float phaseMin;
        float phaseMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjInfraredLaserWallSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjInfraredLaserWallSpawner* pInstance);
        static void Clean(ObjInfraredLaserWallSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPalmTreeSpawner {
        enum class TreeType : int8_t {
            TREE_A01 = 0,
            TREE_A02 = 1,
            TREE_A03 = 2,
            TREE_B01 = 3,
            TREE_B02 = 4,
            TREE_B03 = 5,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        TreeType m_type;
        float m_scale;
        TimeType m_timeType;
        float m_windHorzAngle;
        float m_windHorzAngleWidth;
        float m_windHorzAngleCycle;
        float m_windVertAngle;
        float m_windVertAngleWidth;
        float m_windVertAngleCycle;
        float m_windSpeedMin;
        float m_windSpeedMax;
        float m_windSpeedCycle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPalmTreeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPalmTreeSpawner* pInstance);
        static void Clean(ObjPalmTreeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRockSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRockSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRockSpawner* pInstance);
        static void Clean(ObjRockSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSandWormSpawner {
        float speed;
        uint32_t curlNum;
        float scale;
        float phase;
        bool muteSE;
        bool hideEffect;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSandWormSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSandWormSpawner* pInstance);
        static void Clean(ObjSandWormSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSVShiftingSandSpawner {
        enum class Slidetype : int8_t {
            TYPE_SLOPE = 0,
            TYPE_FALL = 1,
        };

        float length;
        Slidetype slideType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSVShiftingSandSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSVShiftingSandSpawner* pInstance);
        static void Clean(ObjSVShiftingSandSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct BreakParam {
        float toSignTime;
        float signTime;
        float resetTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BreakParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BreakParam* pInstance);
        static void Clean(BreakParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWoodBridgeSpawner {
        enum class SizeType : int8_t {
            SIZETYPE_SMALL = 0,
            SIZETYPE_LARGE = 1,
        };

        float flexure;
        int32_t numWood;
        SizeType sizeType;
        bool isBreak;
        bool isBreakEvent;
        BreakParam breakParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWoodBridgeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWoodBridgeSpawner* pInstance);
        static void Clean(ObjWoodBridgeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjAirCarSpawner {
        uint32_t pathId;
        float speed;
        uint32_t num;
        float distance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjAirCarSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjAirCarSpawner* pInstance);
        static void Clean(ObjAirCarSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBoxRoadSpawner {
        int32_t pathID;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBoxRoadSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBoxRoadSpawner* pInstance);
        static void Clean(ObjBoxRoadSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBreakableTerrainSpawner {
        enum class EffectType : int8_t {
            EFFECT_TYPE_01 = 0,
            EFFECT_TYPE_02 = 1,
            EFFECT_TYPE_03 = 2,
            EFFECT_TYPE_NUM = 3,
        };

        EffectType effectType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBreakableTerrainSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBreakableTerrainSpawner* pInstance);
        static void Clean(ObjBreakableTerrainSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ContinuousShakeStatus {
        float m_magnitude;
        int32_t m_freq;
        float m_zRot;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ContinuousShakeStatus* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ContinuousShakeStatus* pInstance);
        static void Clean(ContinuousShakeStatus* pInstance);
    };
}

namespace heur::rfl {
    struct PeriodicShakeStatus : ContinuousShakeStatus {
        float m_shakeTime;
        float m_cycleTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PeriodicShakeStatus* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PeriodicShakeStatus* pInstance);
        static void Clean(PeriodicShakeStatus* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraShakeTriggerW6TrainSpawner {
        ContinuousShakeStatus continuousShakeStatus;
        PeriodicShakeStatus periodicShakeStatus;
        float width;
        float heigth;
        float depth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraShakeTriggerW6TrainSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraShakeTriggerW6TrainSpawner* pInstance);
        static void Clean(ObjCameraShakeTriggerW6TrainSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFallBlockSpawner {
        enum class FallType : int8_t {
            TYPE_LINEAR = 0,
            TYPE_ACCELERATE = 1,
        };

        enum class FallTimeType : int8_t {
            TYPE_SET_SPEED = 0,
            TYPE_SET_TIME = 1,
        };

        FallType fallType;
        FallTimeType fallTimeType;
        float length;
        float fallTime;
        float waitTime;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFallBlockSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFallBlockSpawner* pInstance);
        static void Clean(ObjFallBlockSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGolemSpawner {
        enum class MotionType : int8_t {
            MOTION_IDLE_00 = 0,
            MOTION_IDLE_01 = 1,
            MOTION_IDLE_02 = 2,
            MOTION_NUM = 3,
        };

        MotionType motionType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGolemSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGolemSpawner* pInstance);
        static void Clean(ObjGolemSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGolemTailSpawner {
        enum class BehaviorType : int8_t {
            BEHAVIOR_IDLE = 0,
            BEHAVIOR_ATTAK = 1,
            BEHAVIOR_IDLE_01 = 2,
            BEHAVIOR_NUM = 3,
        };

        BehaviorType behaviorType;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGolemTailSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGolemTailSpawner* pInstance);
        static void Clean(ObjGolemTailSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGridSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGridSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGridSpawner* pInstance);
        static void Clean(ObjGridSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjHugeRobotSpawner {
        enum class MotionType : int8_t {
            TYPE_DESTROY_A = 0,
        };

        bool eventDrivenMotion;
        csl::ut::MoveArray32<uint32_t> targets;
        MotionType motionType;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjHugeRobotSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjHugeRobotSpawner* pInstance);
        static void Clean(ObjHugeRobotSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjImaginarySpaceVolumeSpawner {
        enum class StateType : int8_t {
            DEFAULTSTATE_ON = 0,
            DEFAULTSTATE_OFF = 1,
        };

        enum class ShapeType : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
        };

        enum class BasePoint : int8_t {
            BASE_CENTER = 0,
            BASE_Z_PLANE = 1,
        };

        hh::game::ObjectId target;
        StateType state;
        ShapeType shape;
        BasePoint basePoint;
        float width;
        float height;
        float depth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjImaginarySpaceVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjImaginarySpaceVolumeSpawner* pInstance);
        static void Clean(ObjImaginarySpaceVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjInfiniteSpawner {
        enum class ActionType : int8_t {
            PLAY_FIRST = 0,
            PLAY_AFTER_SECOND = 1,
        };

        enum class SlowType : int8_t {
            SLOW_ALL = 0,
            SLOW_OBJECT = 1,
            NONE = 2,
        };

        ActionType actionType;
        SlowType slowMotion;
        float slowTime;
        bool startAppearMotion;
        csl::math::Vector3 playerPositionOnFinish;
        ObjectEventData Event0;
        ObjectEventData Event1;
        ObjectEventData Event2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjInfiniteSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjInfiniteSpawner* pInstance);
        static void Clean(ObjInfiniteSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjShowTimeEffectSpawner {
        enum class SlowType : int8_t {
            SLOW_ALL = 0,
            SLOW_OBJECT = 1,
            NONE = 2,
        };

        float time;
        SlowType slowMotion;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjShowTimeEffectSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjShowTimeEffectSpawner* pInstance);
        static void Clean(ObjShowTimeEffectSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjJetFighterSpawner {
        enum class FormationType : int8_t {
            FORMATION_1_JET = 0,
            FORMATION_2_JET = 1,
            FORMATION_3_JET = 2,
            FORMATION_4_JET = 3,
            FORMATION_5_JET = 4,
            FORMATION_NUM = 5,
        };

        FormationType formationType;
        uint32_t pathID;
        float frontInterval;
        float widthInterval;
        float speed;
        float initScale;
        float scalingTime;
        float aliveTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjJetFighterSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjJetFighterSpawner* pInstance);
        static void Clean(ObjJetFighterSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjJetFighterSceneSpawner {
        uint32_t pathID;
        float apperSpeed;
        float relativeDistance;
        float decelerationTime;
        float decelerationDicetance;
        float takeHomingTime;
        float flyawayAccele;
        float maxFlyawaySpeed;
        float collider_radius;
        csl::math::Vector3 allOffset;
        csl::math::Vector3 jetOffest_01;
        csl::math::Vector3 jetOffest_02;
        csl::math::Vector3 jetOffest_03;
        csl::math::Vector3 jetOffest_04;
        csl::math::Vector3 jetOffest_05;
        csl::math::Vector3 jetOffest_target;
        csl::math::Vector3 playerPositionOnSuccess;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjJetFighterSceneSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjJetFighterSceneSpawner* pInstance);
        static void Clean(ObjJetFighterSceneSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjLaserTurretSpawner {
        enum class FireType : int8_t {
            TYPE_SAME_TIME = 0,
            TYPE_PHASE = 1,
            TYPE_PHASE_INV = 2,
        };

        float laserLength;
        FireType fireType;
        uint32_t turretNum;
        float firstSpeed;
        float secondSpeed;
        float phase;
        float shotPhase;
        float shotTime;
        float beforeShotWait;
        float beforeDownWait;
        float waitDownKeep;
        float interval;
        uint32_t shotNum;
        bool checkBarricade;
        bool cycle;
        bool eventDriven;
        bool noFrame;
        bool hitEffect;
        bool sideview;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjLaserTurretSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjLaserTurretSpawner* pInstance);
        static void Clean(ObjLaserTurretSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMissileTurretSpawner {
        enum class MissileType : int8_t {
            TYPE_STRAIGHT = 0,
            TYPE_PATH = 1,
        };

        float speed;
        float length;
        float phase;
        uint32_t pathID;
        MissileType missileType;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMissileTurretSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMissileTurretSpawner* pInstance);
        static void Clean(ObjMissileTurretSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMoveLiftSpawner {
        float startTimeLag;
        float distance;
        float speed;
        bool isSmoothMove;
        bool isFall;
        float predictiveTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMoveLiftSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMoveLiftSpawner* pInstance);
        static void Clean(ObjMoveLiftSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjShadowHandSpawner {
        enum class StartType : int8_t {
            TYPE_EVENT = 0,
            TYPE_DISTANCE = 1,
        };

        float searchDistance;
        StartType startType;
        float upTime;
        float downTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjShadowHandSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjShadowHandSpawner* pInstance);
        static void Clean(ObjShadowHandSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWhiteOutTriggerSpawner : VolumeTriggerSpawner {
        enum class FadeType : int8_t {
            TYPE_WHITE_OUT = 0,
            TYPE_WHITE_IN = 1,
        };

        FadeType type;
        float fadeTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWhiteOutTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWhiteOutTriggerSpawner* pInstance);
        static void Clean(ObjWhiteOutTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjArtificalSunSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjArtificalSunSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjArtificalSunSpawner* pInstance);
        static void Clean(ObjArtificalSunSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjAutoScrollSpawner {
        hh::game::ObjectId EndPoint;
        uint32_t PathId;
        float AreaSize;
        float Speed;
        float Fovy;
        float Distance;
        float ScreenUpLimit;
        float ScreenDownLimit;
        bool ScreenLimitViewField;
        float ScreenViewFieldBottom;
        float Azimuth;
        float Elevation;
        csl::math::Vector3 TargetOffset;
        bool IsReverse;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjAutoScrollSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjAutoScrollSpawner* pInstance);
        static void Clean(ObjAutoScrollSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBigCrankSpawner {
        enum class ActionType : int8_t {
            ACT_UP = 0,
            ACT_DOWN = 1,
            NUM_ACT_TYPE = 2,
        };

        ActionType actionType;
        float distance;
        float time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBigCrankSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBigCrankSpawner* pInstance);
        static void Clean(ObjBigCrankSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBigGearSpawner {
        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        enum class SizeType : int8_t {
            SIZE_S = 0,
            SIZE_L = 1,
        };

        TimeType timeType;
        SizeType sizeType;
        float speed;
        float phase;
        bool isDamage;
        bool isRigidbody;
        bool isReversal;
        bool isEventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBigGearSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBigGearSpawner* pInstance);
        static void Clean(ObjBigGearSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBigGearShaftSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBigGearShaftSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBigGearShaftSpawner* pInstance);
        static void Clean(ObjBigGearShaftSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBoxSkySpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBoxSkySpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBoxSkySpawner* pInstance);
        static void Clean(ObjBoxSkySpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCrawlingBallSpawner {
        enum class MovePathType : int8_t {
            PATH_SELF = 0,
            PATH_SET = 1,
        };

        enum class RotateDirection : int8_t {
            ROTATE_RIGHT = 0,
            ROTATE_LEFT = 1,
            ROTATE_TURN_BACK = 2,
        };

        enum class FloorSizeType : int8_t {
            SIZE_NONE = 0,
            SIZE_2M = 1,
            SIZE_4M = 2,
            SIZE_6M = 3,
            SIZE_8M = 4,
            NUM_SIZE = 5,
        };

        MovePathType moveType;
        RotateDirection rotateType;
        FloorSizeType floorSizeType;
        uint32_t pathID;
        uint32_t ballNum;
        uint32_t childNum;
        float width;
        float height;
        float phase;
        float speed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCrawlingBallSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCrawlingBallSpawner* pInstance);
        static void Clean(ObjCrawlingBallSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDisappearFloorSpawner {
        uint32_t PathId;
        uint32_t setNum;
        float interval;
        float returnInterval;
        float startDelay;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDisappearFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDisappearFloorSpawner* pInstance);
        static void Clean(ObjDisappearFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct CannonParameter {
        float cannonDistance;
        float appearDistanceFront;
        float appearDistanceBack;
        float attackDistanceFront;
        float attackDistanceEnd;
        float moveSpeed;
        float laserSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CannonParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CannonParameter* pInstance);
        static void Clean(CannonParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDoubleSpiralSpawner {
        uint32_t pathId;
        float radius;
        float distance;
        CannonParameter DNACannonParam;
        CannonParameter groundCannonParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDoubleSpiralSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDoubleSpiralSpawner* pInstance);
        static void Clean(ObjDoubleSpiralSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjEventEffectSpawner {
        csl::ut::VariableString name;
        float delay;
        float interval;
        uint32_t playNum;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjEventEffectSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjEventEffectSpawner* pInstance);
        static void Clean(ObjEventEffectSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjExplosionSpawner {
        enum class ExpType : int8_t {
            EXP_1 = 0,
            EXP_2 = 1,
            EXP_3 = 2,
            EXP_LOOP = 3,
            NUM_EXP_TYPE = 4,
        };

        enum class SizeType : int8_t {
            SIZE_1M = 0,
            SIZE_2M = 1,
            SIZE_3M = 2,
            NUM_SIZE_TYPE = 3,
        };

        ExpType expType;
        SizeType sizeType;
        float waitTime;
        float phase;
        bool isDamage;
        bool isEventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjExplosionSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjExplosionSpawner* pInstance);
        static void Clean(ObjExplosionSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjExplosionMissileSpawner {
        enum class ActionType : int8_t {
            ACT_LOOP = 0,
            ACT_ONCE = 1,
            NUM_ACT_TYPE = 2,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        ActionType actionType;
        TimeType timeType;
        float attackDistance;
        csl::math::Vector3 landingAngleMin;
        csl::math::Vector3 landingAngleMax;
        float landingTime;
        float speed;
        float delay;
        float phase;
        bool isEventDriven;
        bool isExpEffect;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjExplosionMissileSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjExplosionMissileSpawner* pInstance);
        static void Clean(ObjExplosionMissileSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjHeatPipeSpawner {
        enum class ActionType : int8_t {
            ACT_LOOP = 0,
            ACT_ON = 1,
            ACT_OFF = 2,
            NUM_ACT_TYPE = 3,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        ActionType actionType;
        TimeType timeType;
        float waitTime;
        float heatTime;
        float phase;
        bool isEventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjHeatPipeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjHeatPipeSpawner* pInstance);
        static void Clean(ObjHeatPipeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjHexagonFloorSpawner {
        uint32_t rowNum;
        uint32_t columnNum;
        int8_t curvatureFrontParam;
        int8_t curvatureBackParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjHexagonFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjHexagonFloorSpawner* pInstance);
        static void Clean(ObjHexagonFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjLaserCannonSpawner {
        uint32_t pathId;
        hh::game::ObjectId endPoint;
        float speed;
        float activeTime;
        float moveWaitTime;
        float acceleTime;
        float acceleStartSpeedRate;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjLaserCannonSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjLaserCannonSpawner* pInstance);
        static void Clean(ObjLaserCannonSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjLaserFenceSpawner {
        enum class ActionType : int8_t {
            ACT_LOOP = 0,
            ACT_ONCE = 1,
            ACT_KEEP = 2,
            NUM_ACT_TYPE = 3,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        ActionType actionType;
        TimeType timeType;
        float laserLength;
        float waitTime;
        float activeTime;
        float phase;
        bool isEventDriven;
        bool isSE;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjLaserFenceSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjLaserFenceSpawner* pInstance);
        static void Clean(ObjLaserFenceSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPlayerChaseExpSpawner {
        enum class ExpType : int8_t {
            EXP_01 = 0,
            EXP_02 = 1,
            EXP_LIGHT = 2,
            NUM_EXP_TYPE = 3,
        };

        ExpType expType;
        uint32_t pathId;
        bool isDebris;
        bool isCameraShake;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPlayerChaseExpSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPlayerChaseExpSpawner* pInstance);
        static void Clean(ObjPlayerChaseExpSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct CoreParameter {
        enum class BEventType : int8_t {
            EVENT_NONE = 0,
            EVENT_ON = 1,
            EVENT_OFF = 2,
        };

        float DefenseTime;
        float OmenTime;
        float WaitTime;
        float InitWaitTime;
        csl::ut::MoveArray32<uint32_t> BreakEventTarget;
        BEventType BreakEventType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CoreParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CoreParameter* pInstance);
        static void Clean(CoreParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPowerReactorSpawner {
        uint32_t PathId;
        csl::math::Vector3 CoreOffset;
        CoreParameter Core1;
        CoreParameter Core2;
        CoreParameter Core3;
        csl::ut::MoveArray32<uint32_t> ExpList;
        hh::game::ObjectId PlayePoint;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPowerReactorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPowerReactorSpawner* pInstance);
        static void Clean(ObjPowerReactorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjResearchMissilePodSpawner {
        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        TimeType timeType;
        float delay;
        float phase;
        float attackDistance;
        float shotAngleMin;
        float shotAngleMax;
        float shotSpeed;
        float shotTime;
        float missileSpeed;
        float missileAccelTime;
        float missileHomingWait;
        int32_t missileHomingRotation;
        bool isEventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjResearchMissilePodSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjResearchMissilePodSpawner* pInstance);
        static void Clean(ObjResearchMissilePodSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRotationFloorSpawner {
        float phase;
        bool isReverse;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRotationFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRotationFloorSpawner* pInstance);
        static void Clean(ObjRotationFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjShockPanelSpawner {
        enum class ActionType : int8_t {
            ACT_LOOP = 0,
            ACT_ONCE = 1,
            ACT_KEEP = 2,
            ACT_STOP = 3,
            NUM_ACT_TYPE = 4,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        ActionType actionType;
        TimeType timeType;
        float waitTime;
        float activeTime;
        float phase;
        bool isEventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjShockPanelSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjShockPanelSpawner* pInstance);
        static void Clean(ObjShockPanelSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWhiteOutGoalTriggerSpawner : VolumeTriggerSpawner {
        float goalTime;
        float fadeOutTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWhiteOutGoalTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWhiteOutGoalTriggerSpawner* pInstance);
        static void Clean(ObjWhiteOutGoalTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct AnimatorTestSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AnimatorTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AnimatorTestSpawner* pInstance);
        static void Clean(AnimatorTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBulletHoleTestSpawner {
        float scale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBulletHoleTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBulletHoleTestSpawner* pInstance);
        static void Clean(ObjBulletHoleTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct CharacterRbTestSpawner {
        float speed;
        float gravity;
        float supportDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CharacterRbTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CharacterRbTestSpawner* pInstance);
        static void Clean(CharacterRbTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjColliderTestSpawner {
        enum class LayerType : int8_t {
            NONE_GROUP = 0,
            LAND = 1,
            RAYBLOCK = 2,
            THROUGH = 3,
            PLAYER_NORMAL = 4,
            DEBRIS = 5,
            OBJECT = 6,
            ENEMY = 7,
            RING = 8,
            RING_HIT = 9,
            ITEM = 10,
            EVENT = 11,
            SENSOR_PLAYER = 12,
            SENSOR_GIMMICK = 13,
            SENSOR_LAND = 14,
            SENSOR_ALL = 15,
            CHARA_ENEMY = 16,
        };

        LayerType layer;
        float size;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjColliderTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjColliderTestSpawner* pInstance);
        static void Clean(ObjColliderTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeData {
        enum class SexType : int8_t {
            MALE = 0,
            FEMALE = 1,
            NUM_SEX = 2,
        };

        enum class RaceType : int8_t {
            DOG = 0,
            WOLF = 1,
            RABBIT = 2,
            BEAR = 3,
            CAT = 4,
            BIRD = 5,
            HEDGEHOG = 6,
            NUM_RACES = 7,
        };

        SexType sex;
        RaceType race;
        uint8_t rank;
        uint8_t gadgetNo;
        uint8_t head;
        uint8_t eye;
        uint8_t voice;
        uint8_t baseColor;
        uint8_t skinColor;
        uint8_t beakColor;
        uint8_t eyeColor;
        uint8_t headPart;
        uint8_t glassPart;
        uint8_t facePart;
        uint8_t glovePart;
        uint8_t shoesPart;
        uint8_t bodyPart;
        uint8_t suitNo;
        uint8_t innerColor;
        uint8_t resultMotionNo;
        uint32_t experiencePoint;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeData* pInstance);
        static void Clean(CustomizeData* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCustomizeDollSpawner {
        CustomizeData customizeData;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCustomizeDollSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCustomizeDollSpawner* pInstance);
        static void Clean(ObjCustomizeDollSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCustomizeTestSpawner {
        csl::ut::VariableString modelName;
        csl::ut::VariableString srcTextureName;
        csl::ut::VariableString dstTextureName;
        int32_t shaderVariationNo;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCustomizeTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCustomizeTestSpawner* pInstance);
        static void Clean(ObjCustomizeTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjEasingTestSpawner {
        enum class EasingType : int8_t {
            EASE_IN = 0,
            EASE_OUT = 1,
            EASE_INOUT = 2,
        };

        enum class CalculateType : int8_t {
            LINEAR = 0,
            QUADRATIC = 1,
            CUBIC = 2,
            QUARTIC = 3,
            QUINTIC = 4,
            SIN = 5,
            EXPONENTIAL = 6,
            CIRCULAR = 7,
            BACK = 8,
            BOUNCE = 9,
            ELASTIC = 10,
        };

        enum class ParamType : int8_t {
            PARAM_ONE = 0,
            PARAM_INV_ONE = 1,
            PARAM_HALF = 2,
            PARAM_INV_HALF = 3,
            PARAM_DOUBLE = 4,
            PARAM_INV_DOUBLE = 5,
        };

        enum class OperationType : int8_t {
            OP_NONE = 0,
            OP_ADD = 1,
            OP_SUB = 2,
            OP_MULTI = 3,
            OP_NEST = 4,
        };

        EasingType m_ease1;
        CalculateType m_calc1;
        ParamType m_param1;
        EasingType m_ease2;
        CalculateType m_calc2;
        ParamType m_param2;
        OperationType m_op;
        float m_previewTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjEasingTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjEasingTestSpawner* pInstance);
        static void Clean(ObjEasingTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct MoveParam {
        enum class MoveType : int8_t {
            MOVE_NONE = 0,
            MOVE_CONSTANT = 1,
            MOVE_ROTATE = 2,
        };

        MoveType type;
        float distance;
        float cycle;
        csl::math::Vector3 axis;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MoveParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MoveParam* pInstance);
        static void Clean(MoveParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjEffectTestSpawner {
        csl::ut::VariableString name;
        float cycle;
        csl::math::Vector3 offset;
        MoveParam move;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjEffectTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjEffectTestSpawner* pInstance);
        static void Clean(ObjEffectTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct TestObjFloorRotateSpawner {
        enum class AxisType : int8_t {
            AXIS_TYPE_X = 0,
            AXIS_TYPE_Y = 1,
            AXIS_TYPE_Z = 2,
        };

        float omega;
        float offset;
        bool useGlobalTime;
        AxisType axis;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(TestObjFloorRotateSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(TestObjFloorRotateSpawner* pInstance);
        static void Clean(TestObjFloorRotateSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct TestObjFloorSeesawSpawner {
        enum class AxisType : int8_t {
            AXIS_TYPE_X = 0,
            AXIS_TYPE_Y = 1,
            AXIS_TYPE_Z = 2,
        };

        float cycle;
        float amplitude;
        float offset;
        bool useGlobalTime;
        AxisType axis;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(TestObjFloorSeesawSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(TestObjFloorSeesawSpawner* pInstance);
        static void Clean(TestObjFloorSeesawSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFxParamChangerSpawner {
        enum class TypeInterpolate : int8_t {
            LINEAR = 0,
            SIN_CURVE = 1,
        };

        uint32_t sourceParamNo;
        uint32_t targetParamNo;
        float time;
        TypeInterpolate interpolateType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFxParamChangerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFxParamChangerSpawner* pInstance);
        static void Clean(ObjFxParamChangerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjHmdVisualizerSpawner {
        enum class SrcType : int8_t {
            SRC_TYPE_DEVICE = 0,
            SRC_TYPE_LEFT = 1,
            SRC_TYPE_RIGHT = 2,
            SRC_TYPE_COUNT = 3,
            NUM_SRC_TYPES = 3,
        };

        SrcType m_srcType;
        bool m_applyPosition;
        bool m_primitive;
        csl::math::Vector3 m_bodySize;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjHmdVisualizerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjHmdVisualizerSpawner* pInstance);
        static void Clean(ObjHmdVisualizerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjHomingTargetTestSpawner {
        bool isRepeatTarget;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjHomingTargetTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjHomingTargetTestSpawner* pInstance);
        static void Clean(ObjHomingTargetTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMasterPoseTestSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMasterPoseTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMasterPoseTestSpawner* pInstance);
        static void Clean(ObjMasterPoseTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMirageAnimationTestSpawner {
        csl::ut::VariableString modelName;
        csl::ut::VariableString animTexSrtName;
        csl::ut::VariableString animTexPatName;
        csl::ut::VariableString animMaterialName;
        csl::ut::VariableString animVisName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMirageAnimationTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMirageAnimationTestSpawner* pInstance);
        static void Clean(ObjMirageAnimationTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct OverlapTestSpawner {
        enum class LayerType : int8_t {
            NONE_GROUP = 0,
            LAND = 1,
            RAYBLOCK = 2,
            THROUGH = 3,
        };

        LayerType layer;
        bool childLoopLeft;
        bool childLoopRight;
        bool childSolid;
        bool childLiquid;
        bool childThrough;
        bool childOneway;
        float searchSize;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(OverlapTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(OverlapTestSpawner* pInstance);
        static void Clean(OverlapTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPassPlaneTestSpawner {
        csl::math::Vector3 size;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPassPlaneTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPassPlaneTestSpawner* pInstance);
        static void Clean(ObjPassPlaneTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRaycastTestSpawner {
        enum class LayerType : int8_t {
            NONE_GROUP = 0,
            LAND = 1,
            RAYBLOCK = 2,
            THROUGH = 3,
            LAND_THROUGH = 4,
        };

        LayerType layer;
        bool childLoopLeft;
        bool childLoopRight;
        bool childSolid;
        bool childLiquid;
        bool childThrough;
        bool childOneway;
        bool useCache;
        float searchSize;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRaycastTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRaycastTestSpawner* pInstance);
        static void Clean(ObjRaycastTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct TestObjRollFloorBoxSpawner {
        enum class AxisType : int8_t {
            AXIS_TYPE_X = 0,
            AXIS_TYPE_Y = 1,
            AXIS_TYPE_Z = 2,
        };

        float radius;
        float speed;
        float offset;
        bool useGlobalTime;
        AxisType axis;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(TestObjRollFloorBoxSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(TestObjRollFloorBoxSpawner* pInstance);
        static void Clean(TestObjRollFloorBoxSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct TestObjRollFloorCapsuleSpawner {
        float radius;
        float omega;
        float offset;
        bool useGlobalTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(TestObjRollFloorCapsuleSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(TestObjRollFloorCapsuleSpawner* pInstance);
        static void Clean(TestObjRollFloorCapsuleSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSampleShapeSpawner {
        enum class Shape : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
        };

        enum class PhysicsLayerType : int8_t {
            GROUP_LAND = 0,
            GROUP_ONEWAY = 1,
        };

        enum class PhysicsAttributeType : int8_t {
            ATTR_NONE = 0,
            ATTR_BREAKABLE = 1,
            ATTR_NOT_STAND = 2,
        };

        Shape ShapeType;
        float Width;
        float Height;
        float Depth;
        uint8_t Red;
        uint8_t Green;
        uint8_t Blue;
        bool IsEnableModel;
        bool IsEnableRigidbody;
        PhysicsLayerType PhysicsGroup;
        PhysicsAttributeType PhysicsAttr;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSampleShapeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSampleShapeSpawner* pInstance);
        static void Clean(ObjSampleShapeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSceneTestSpawner {
        enum class ShapeType : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
        };

        csl::ut::VariableString sceneName;
        csl::math::Vector3 scenePosition;
        csl::math::Vector3 sceneRotation;
        ShapeType shape;
        float width;
        float height;
        float depth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSceneTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSceneTestSpawner* pInstance);
        static void Clean(ObjSceneTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSearchPathSpawner {
        enum class PathType : int8_t {
            PATH_ALL = 0,
            PATH_OBJ = 1,
            PATH_GRIND = 2,
            PATH_SV = 3,
            PATH_SLIDER = 4,
        };

        enum class SearchType : int8_t {
            SEARCH_OVERLAP_SPHERE = 0,
            SEARCH_OVERLAP_AABB = 1,
            SEARCH_RAYCAST = 2,
        };

        PathType pathType;
        SearchType searchType;
        float searchSize;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSearchPathSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSearchPathSpawner* pInstance);
        static void Clean(ObjSearchPathSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjShadingReferenceSpawner {
        float dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjShadingReferenceSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjShadingReferenceSpawner* pInstance);
        static void Clean(ObjShadingReferenceSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjShadowCameraTestSpawner {
        float nearPlane;
        float farPlane;
        float lookAtDepth;
        float sceneRange;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjShadowCameraTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjShadowCameraTestSpawner* pInstance);
        static void Clean(ObjShadowCameraTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSwayTestSpawner {
        float speed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSwayTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSwayTestSpawner* pInstance);
        static void Clean(ObjSwayTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct SweepTestSpawner {
        enum class LayerType : int8_t {
            NONE_GROUP = 0,
            LAND = 1,
            RAYBLOCK = 2,
            THROUGH = 3,
        };

        float distance;
        float radius;
        LayerType layer;
        bool childLoopLeft;
        bool childLoopRight;
        bool childSolid;
        bool childLiquid;
        bool childThrough;
        bool childOneway;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SweepTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SweepTestSpawner* pInstance);
        static void Clean(SweepTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTargetTestSpawner {
        enum class ShapeType : int8_t {
            SPHERE = 0,
            BOX = 1,
        };

        enum class ColorType : int8_t {
            WHITE = 0,
            GLAY = 1,
            BLACK = 2,
            RED = 3,
            GREEN = 4,
            BLUE = 5,
            YELLOW = 6,
            CYAN = 7,
            MAGENTA = 8,
        };

        enum class MoveType : int8_t {
            NONE = 0,
            SWING = 1,
        };

        ShapeType shape;
        float width;
        float height;
        float depth;
        ColorType color;
        bool visible;
        bool enemy;
        bool breakable;
        MoveType move;
        float cycle;
        float distance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTargetTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTargetTestSpawner* pInstance);
        static void Clean(ObjTargetTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct TinyFsmTestSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(TinyFsmTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(TinyFsmTestSpawner* pInstance);
        static void Clean(TinyFsmTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjUserModelMaterialTestSpawner {
        csl::math::Vector3 albedo;
        float reflectance;
        float smoothness;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjUserModelMaterialTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjUserModelMaterialTestSpawner* pInstance);
        static void Clean(ObjUserModelMaterialTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjUserModelShaderTestSpawner {
        csl::ut::VariableString texturePack;
        csl::ut::VariableString texture;
        csl::ut::VariableString vertexShaderName;
        csl::ut::VariableString pixelShaderName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjUserModelShaderTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjUserModelShaderTestSpawner* pInstance);
        static void Clean(ObjUserModelShaderTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjUserModelTestSpawner {
        enum class RenderPresetType : int8_t {
            RENDER_PRESET_OPAQUE = 0,
            RENDER_PRESET_PUNCHTHROUGH = 1,
            RENDER_PRESET_TRANSPARENT = 2,
            RENDER_PRESET_ADD = 3,
        };

        enum class MoveType : int8_t {
            MOVE_NONE = 0,
            MOVE_SWING = 1,
            MOVE_ROTATE = 2,
        };

        RenderPresetType preset;
        csl::ut::VariableString texturePack;
        csl::ut::VariableString texture;
        uint8_t red;
        uint8_t green;
        uint8_t blue;
        uint8_t alpha;
        float scale;
        csl::ut::VariableString vertexShaderName;
        csl::ut::VariableString pixelShaderName;
        bool shadowCaster;
        bool shadowReceiver;
        bool dynamic;
        MoveType move;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjUserModelTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjUserModelTestSpawner* pInstance);
        static void Clean(ObjUserModelTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjVibrationTestSpawner : VolumeTriggerSpawner {
        enum class RumbleType : int8_t {
            RUMBLE_AUTO = 0,
            RUMBLE_ONESHOT = 1,
            RUMBLE_LOOP = 2,
        };

        csl::ut::VariableString name;
        RumbleType type;
        float time;
        bool enabledTimeAttn;
        bool enabledDistAttn;
        float distance;
        float easeoutTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjVibrationTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjVibrationTestSpawner* pInstance);
        static void Clean(ObjVibrationTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjVirtronTestSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjVirtronTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjVirtronTestSpawner* pInstance);
        static void Clean(ObjVirtronTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWallJumpTestSpawner {
        csl::math::Vector3 size;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWallJumpTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWallJumpTestSpawner* pInstance);
        static void Clean(ObjWallJumpTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct AddDatabaseInfo {
        uint8_t recordNo;
        uint8_t numRecords;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AddDatabaseInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AddDatabaseInfo* pInstance);
        static void Clean(AddDatabaseInfo* pInstance);
    };
}

namespace heur::rfl {
    struct ContentParameter {
        AddDatabaseInfo databases[11];
        int8_t numEvents;
        csl::ut::VariableString customizeThumbPackName;
        csl::ut::VariableString stagedata;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ContentParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ContentParameter* pInstance);
        static void Clean(ContentParameter* pInstance);
    };
}

namespace heur::rfl {
    struct Record {
        uint8_t no;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Record* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Record* pInstance);
        static void Clean(Record* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeRecordBase : Record {
        enum class SexExclusiveType : int8_t {
            EXCLU_COMMON = 0,
            EXCLU_MEN = 1,
            EXCLU_WOMEN = 2,
            NUM_SEX_EXCLUSIVES = 3,
        };

        enum class ColorVariationType : int8_t {
            COLOR_VAR_A = 0,
            COLOR_VAR_B = 1,
            COLOR_VAR_C = 2,
            COLOR_VAR_D = 3,
            COLOR_VAR_E = 4,
            COLOR_VAR_F = 5,
            COLOR_VAR_G = 6,
            COLOR_VAR_H = 7,
            NUM_COLOR_VARIATIONS = 8,
        };

        uint8_t partNo;
        SexExclusiveType sex;
        ColorVariationType color;
        int16_t missionID;
        csl::math::Vector3 cameraPosition;
        csl::math::Vector3 cameraUp;
        csl::math::Vector3 cameraTarget;
        float cameraFovy;
        uint32_t commonFlags;
        uint32_t padding0;
        uint32_t padding1;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeRecordBase* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeRecordBase* pInstance);
        static void Clean(CustomizeRecordBase* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeBodyPartRecord : CustomizeRecordBase {
        bool invisibles[11];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeBodyPartRecord* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeBodyPartRecord* pInstance);
        static void Clean(CustomizeBodyPartRecord* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeBodyPartRecordBaseTable {
        CustomizeBodyPartRecord data[144];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeBodyPartRecordBaseTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeBodyPartRecordBaseTable* pInstance);
        static void Clean(CustomizeBodyPartRecordBaseTable* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeBodyPartRecordTable {
        CustomizeBodyPartRecord data[255];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeBodyPartRecordTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeBodyPartRecordTable* pInstance);
        static void Clean(CustomizeBodyPartRecordTable* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeFacePartRecord : CustomizeRecordBase {
        enum class ConstrainType : int8_t {
            CONSTRAIN_NONE = 0,
            CONSTRAIN_NOSE = 1,
            NUM_CONSTRAINS = 2,
        };

        bool invisibles[11];
        ConstrainType constrain;
        uint8_t numMaterialAnims;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeFacePartRecord* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeFacePartRecord* pInstance);
        static void Clean(CustomizeFacePartRecord* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeFacePartRecordBaseTable {
        CustomizeFacePartRecord data[30];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeFacePartRecordBaseTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeFacePartRecordBaseTable* pInstance);
        static void Clean(CustomizeFacePartRecordBaseTable* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeFacePartRecordTable {
        CustomizeFacePartRecord data[128];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeFacePartRecordTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeFacePartRecordTable* pInstance);
        static void Clean(CustomizeFacePartRecordTable* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeGlassPartRecord : CustomizeRecordBase {
        bool flags[4];
        uint8_t numUvAnims;
        uint8_t numMaterialAnims;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeGlassPartRecord* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeGlassPartRecord* pInstance);
        static void Clean(CustomizeGlassPartRecord* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeGlassPartRecordBaseTable {
        CustomizeGlassPartRecord data[69];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeGlassPartRecordBaseTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeGlassPartRecordBaseTable* pInstance);
        static void Clean(CustomizeGlassPartRecordBaseTable* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeGlassPartRecordTable {
        CustomizeGlassPartRecord data[128];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeGlassPartRecordTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeGlassPartRecordTable* pInstance);
        static void Clean(CustomizeGlassPartRecordTable* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeGlovePartRecord : CustomizeRecordBase {
        bool flags[1];
        uint8_t numUvAnims;
        uint8_t numMaterialAnims;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeGlovePartRecord* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeGlovePartRecord* pInstance);
        static void Clean(CustomizeGlovePartRecord* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeGlovePartRecordBaseTable {
        CustomizeGlovePartRecord data[108];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeGlovePartRecordBaseTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeGlovePartRecordBaseTable* pInstance);
        static void Clean(CustomizeGlovePartRecordBaseTable* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeGlovePartRecordTable {
        CustomizeGlovePartRecord data[255];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeGlovePartRecordTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeGlovePartRecordTable* pInstance);
        static void Clean(CustomizeGlovePartRecordTable* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeHeadPartRecord : CustomizeRecordBase {
        bool invisibles[11];
        uint8_t numUvAnims;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeHeadPartRecord* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeHeadPartRecord* pInstance);
        static void Clean(CustomizeHeadPartRecord* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeHeadPartRecordBaseTable {
        CustomizeHeadPartRecord data[93];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeHeadPartRecordBaseTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeHeadPartRecordBaseTable* pInstance);
        static void Clean(CustomizeHeadPartRecordBaseTable* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeHeadPartRecordTable {
        CustomizeHeadPartRecord data[255];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeHeadPartRecordTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeHeadPartRecordTable* pInstance);
        static void Clean(CustomizeHeadPartRecordTable* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizePatternRecord : CustomizeRecordBase {
        bool flags[1];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizePatternRecord* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizePatternRecord* pInstance);
        static void Clean(CustomizePatternRecord* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizePatternRecordBaseTable {
        CustomizePatternRecord data[151];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizePatternRecordBaseTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizePatternRecordBaseTable* pInstance);
        static void Clean(CustomizePatternRecordBaseTable* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizePatternRecordTable {
        CustomizePatternRecord data[255];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizePatternRecordTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizePatternRecordTable* pInstance);
        static void Clean(CustomizePatternRecordTable* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeShoesPartRecord : CustomizeRecordBase {
        uint8_t numMaterialAnims;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeShoesPartRecord* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeShoesPartRecord* pInstance);
        static void Clean(CustomizeShoesPartRecord* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeShoesPartRecordBaseTable {
        CustomizeShoesPartRecord data[159];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeShoesPartRecordBaseTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeShoesPartRecordBaseTable* pInstance);
        static void Clean(CustomizeShoesPartRecordBaseTable* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeShoesPartRecordTable {
        CustomizeShoesPartRecord data[255];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeShoesPartRecordTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeShoesPartRecordTable* pInstance);
        static void Clean(CustomizeShoesPartRecordTable* pInstance);
    };
}

namespace heur::rfl {
    struct EventMovieRecord : Record {
        enum class DataType : int8_t {
            DATA_TYPE_SCENE = 0,
            DATA_TYPE_NARRATION = 1,
        };

        enum class ChunkType : int8_t {
            CHUNKTYPE_INITIAL = 0,
            CHUNKTYPE_AFTER = 1,
        };

        csl::ut::VariableString eventName;
        DataType dataType;
        csl::ut::VariableString sceneName;
        uint8_t numNarrationTexts;
        ChunkType chunkType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EventMovieRecord* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EventMovieRecord* pInstance);
        static void Clean(EventMovieRecord* pInstance);
    };
}

namespace heur::rfl {
    struct EventMovieRecordBaseTable {
        EventMovieRecord data[31];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EventMovieRecordBaseTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EventMovieRecordBaseTable* pInstance);
        static void Clean(EventMovieRecordBaseTable* pInstance);
    };
}

namespace heur::rfl {
    struct EventMovieRecordTable {
        EventMovieRecord data[128];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EventMovieRecordTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EventMovieRecordTable* pInstance);
        static void Clean(EventMovieRecordTable* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetRecord : Record {
        enum class GadgetType : int8_t {
            GADGET_NONE = -1,
            GADGET_ASTEROID = 0,
            GADGET_LIGHTNING = 1,
            GADGET_CUBE = 2,
            GADGET_DRILL = 3,
            GADGET_BURST = 4,
            GADGET_VOID = 5,
            GADGET_HOVER = 6,
            NUM_GADGETS = 7,
        };

        enum class GadgetSkillType : int8_t {
            SKILL_NONE = 0,
            SKILL_ACCELE_GRIND = 1,
            SKILL_ACCELE_RING = 2,
            SKILL_REDUCE_DAMAGE = 3,
            SKILL_RESTORE_RING = 4,
            SKILL_HIGH_GRIP = 5,
            SKILL_TAKE_BARRIER = 6,
            SKILL_DROP_RING = 7,
            SKILL_RING_INVINCIBLE = 8,
            SKILL_RING_BONUS = 9,
            SKILL_INLET_RING = 10,
            SKILL_POWER_RESTART = 11,
            SKILL_LANDING_DASH = 12,
            SKILL_BALANCE = 13,
            SKILL_CANCEL_DASH = 14,
            SKILL_SKIMMER = 15,
            SKILL_RING_UP = 16,
            SKILL_HA_TURBO = 17,
            SKILL_BRAKE_GUARD = 18,
            SKILL_HOMING_BLOW = 19,
            SKILL_CHAIN_RING = 20,
            SKILL_COMBO_ENEMY = 21,
            SKILL_DAMAGED_INVINCIBLE = 22,
            SKILL_DOUBLE_JUMP = 23,
            SKILL_HA_STABILITY = 24,
            SKILL_HUNDRED_BONUS = 25,
            NUM_GADGET_SKILLS = 26,
        };

        GadgetType type;
        GadgetSkillType skill[3];
        int16_t missionID;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetRecord* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetRecord* pInstance);
        static void Clean(GadgetRecord* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetRecordBaseTable {
        GadgetRecord data[200];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetRecordBaseTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetRecordBaseTable* pInstance);
        static void Clean(GadgetRecordBaseTable* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetRecordTable {
        GadgetRecord data[255];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetRecordTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetRecordTable* pInstance);
        static void Clean(GadgetRecordTable* pInstance);
    };
}

namespace heur::rfl {
    struct GameScoreRecord : Record {
        enum class GameScoreType : int8_t {
            GAMESCORE_NONE = -1,
            GAMESCORE_VALUE = 0,
            GAMESCORE_QTE_GOOD = 1,
            GAMESCORE_QTE_GREAT = 2,
            GAMESCORE_QTE_PERFECT = 3,
            GAMESCORE_GRIND = 4,
            GAMESCORE_GRIND_STEP = 5,
            GAMESCORE_DOUBLE_BOOST = 6,
            GAMESCORE_QUICK_STEP = 7,
            GAMESCORE_TRICK_JUMP = 8,
            GAMESCORE_GIANT_SWING = 9,
            GAMESCORE_USE_GADGET = 10,
            GAMESCORE_RING = 11,
            GAMESCORE_SUPER_RING = 12,
            GAMESCORE_RED_RING = 13,
            GAMESCORE_WISP_CAPSULE = 14,
            GAMESCORE_BOOST_ITEM = 15,
            GAMESCORE_ITEM_BOX = 16,
            GAMESCORE_RAINBOW_RING = 17,
            GAMESCORE_CHECK_POINT = 18,
            GAMESCORE_THORN_PANEL = 19,
            GAMESCORE_RELEASE_BOX = 20,
            GAMESCORE_BREAKABLE_OBJ = 21,
            GAMESCORE_BUMPER = 22,
            GAMESCORE_VANISH_BUMPER = 23,
            GAMESCORE_CASINO_POCKET = 24,
            GAMESCORE_DROPPED_RING = 25,
            GAMESCORE_SHADOW_HAND = 26,
            GAMESCORE_BLUE_RING = 27,
            GAMESCORE_NUMBER_RING = 28,
            GAMESCORE_NUMBER_RING_COMP = 29,
            GAMESCORE_YELLOWMOON_RING = 30,
            GAMESCORE_YELLOWMOON_RING_COMP = 31,
            GAMESCORE_ZAVOK = 32,
            GAMESCORE_EGGDRAGOON = 33,
            GAMESCORE_INFINITE_1 = 34,
            GAMESCORE_INFINITE_2 = 35,
            GAMESCORE_INFINITE_3 = 36,
            GAMESCORE_GIANT_DEATHEGG = 37,
            GAMESCORE_BEETON = 38,
            GAMESCORE_MOTORA = 39,
            GAMESCORE_SLIDERMOTORA = 40,
            GAMESCORE_NARL = 41,
            GAMESCORE_EGGCHASER = 42,
            GAMESCORE_EGGPAWN = 43,
            GAMESCORE_EGGWALKER = 44,
            GAMESCORE_POTOS = 45,
            GAMESCORE_EGGTANK = 46,
            GAMESCORE_EGGTANK_BULLET = 47,
            GAMESCORE_VALKEEN = 48,
            GAMESCORE_BATABATA = 49,
            GAMESCORE_SHADOW_BUDDY = 50,
            GAMESCORE_METAL_SONIC = 51,
            GAMESCORE_DEATHEGGROBO = 52,
            GAMESCORE_GIANT_CRAB = 53,
            GAMESCORE_GOLD_MOTORA = 54,
            GAMESCORE_GALAGABEE = 55,
            GAMESCORE_GOLD_SLIDERMOTORA = 56,
            GAMESCORE_TRANSFORM_SUPERONIC = 57,
            NUM_GAMESCORES = 58,
        };

        enum class ScoreCategory : int8_t {
            SCORE_ACTION = 0,
            SCORE_OBJECT = 1,
            SCORE_ENEMY = 2,
            SCORE_QTE = 3,
            NUM_SCORE_CATEGORIES = 4,
        };

        GameScoreType scoreType;
        ScoreCategory categoryType;
        uint32_t score;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameScoreRecord* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameScoreRecord* pInstance);
        static void Clean(GameScoreRecord* pInstance);
    };
}

namespace heur::rfl {
    struct GameScoreRecordBaseTable {
        GameScoreRecord data[70];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameScoreRecordBaseTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameScoreRecordBaseTable* pInstance);
        static void Clean(GameScoreRecordBaseTable* pInstance);
    };
}

namespace heur::rfl {
    struct GameScoreRecordTable {
        GameScoreRecord data[128];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameScoreRecordTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameScoreRecordTable* pInstance);
        static void Clean(GameScoreRecordTable* pInstance);
    };
}

namespace heur::rfl {
    struct StageScoreRecord : Record {
        uint32_t timeMax;
        uint32_t timeDeduct;
        uint32_t noMiss[6];
        uint32_t rank[4];
        csl::ut::VariableString stageCode;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageScoreRecord* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageScoreRecord* pInstance);
        static void Clean(StageScoreRecord* pInstance);
    };
}

namespace heur::rfl {
    struct StageScoreRecordBaseTable {
        StageScoreRecord data[70];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageScoreRecordBaseTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageScoreRecordBaseTable* pInstance);
        static void Clean(StageScoreRecordBaseTable* pInstance);
    };
}

namespace heur::rfl {
    struct StageScoreRecordTable {
        StageScoreRecord data[128];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageScoreRecordTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageScoreRecordTable* pInstance);
        static void Clean(StageScoreRecordTable* pInstance);
    };
}

namespace heur::rfl {
    struct EventMovieCaption {
        csl::ut::VariableString label;
        int32_t beginFrame;
        int32_t endFrame;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EventMovieCaption* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EventMovieCaption* pInstance);
        static void Clean(EventMovieCaption* pInstance);
    };
}

namespace heur::rfl {
    struct EventMovieCaptionTable {
        EventMovieCaption captions[30];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EventMovieCaptionTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EventMovieCaptionTable* pInstance);
        static void Clean(EventMovieCaptionTable* pInstance);
    };
}

namespace heur::rfl {
    struct OnceCreditParameter {
        enum class ColumnType : int16_t {
            COLUMN_ONE = 0,
            COLUMN_TWO = 1,
            COLUMN_THREE = 2,
            COLUMN_MAX = 3,
        };

        enum class ExpandSetting : int16_t {
            EXPAND_NONE = 0,
            EXPAND_VOICE_ACTOR = 1,
            EXPAND_LOGO_SEGA = 2,
            EXPAND_LOGO_SONICTEAM = 3,
            EXPAND_LOGO_HAVOK = 4,
            EXPAND_LOGO_HARDLIGHT = 5,
            EXPAND_LOGO_SIMPLYGON = 6,
            EXPAND_FADE_IN = 7,
            EXPAND_ONLY_NX = 8,
        };

        csl::ut::VariableString labelName;
        uint32_t partStaffNum;
        float spacePrevPart;
        float spacePartName;
        float spaceStaffName;
        ColumnType columnType;
        ExpandSetting expand;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(OnceCreditParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(OnceCreditParameter* pInstance);
        static void Clean(OnceCreditParameter* pInstance);
    };
}

namespace heur::rfl {
    struct OnceCutParameter {
        uint8_t worldNo;
        uint16_t cutNo;
        float waitTime;
        float time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(OnceCutParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(OnceCutParameter* pInstance);
        static void Clean(OnceCutParameter* pInstance);
    };
}

namespace heur::rfl {
    struct VrStageCameraParameter {
        bool useFovSetting;
        float fovY;
        float zNear;
        float zFar;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(VrStageCameraParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(VrStageCameraParameter* pInstance);
        static void Clean(VrStageCameraParameter* pInstance);
    };
}

namespace heur::rfl {
    struct VrStageFpsParameter {
        csl::math::Vector3 eyeOffset;
        float distance;
        float angleSensitivity;
        float turnAngleLerpFactor;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(VrStageFpsParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(VrStageFpsParameter* pInstance);
        static void Clean(VrStageFpsParameter* pInstance);
    };
}

namespace heur::rfl {
    struct VrStageTitleParameter {
        csl::math::Vector3 eye;
        csl::math::Vector3 lookat;
        float zNear;
        float zFar;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(VrStageTitleParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(VrStageTitleParameter* pInstance);
        static void Clean(VrStageTitleParameter* pInstance);
    };
}

namespace heur::rfl {
    struct EffectParameters {
        float localLightIntensityScale;
        int8_t dropPriority;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EffectParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EffectParameters* pInstance);
        static void Clean(EffectParameters* pInstance);
    };
}

namespace heur::rfl {
    struct LerpNode {
        float distance;
        float noiseTextureScrollSpeed;
        float blurScale;
        float colorGain;
        float noiseGain;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(LerpNode* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(LerpNode* pInstance);
        static void Clean(LerpNode* pInstance);
    };
}

namespace heur::rfl {
    struct AuraEffectLerpParameter {
        bool enable;
        LerpNode node[2];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AuraEffectLerpParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AuraEffectLerpParameter* pInstance);
        static void Clean(AuraEffectLerpParameter* pInstance);
    };
}

namespace heur::rfl {
    struct AuraEffectParameter {
        bool enable;
        float noiseTextureScrollSpeed;
        float blurScale;
        float colorGain;
        float noiseGain;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AuraEffectParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AuraEffectParameter* pInstance);
        static void Clean(AuraEffectParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GraphicsParameters {
        AuraEffectLerpParameter aura;
        EffectParameters effect;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GraphicsParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GraphicsParameters* pInstance);
        static void Clean(GraphicsParameters* pInstance);
    };
}

namespace heur::rfl {
    struct ExpLevelData {
        uint32_t nextLevelNecessaryPoint[29];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ExpLevelData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ExpLevelData* pInstance);
        static void Clean(ExpLevelData* pInstance);
    };
}

namespace heur::rfl {
    struct ExpStageData {
        float stageCoefficient[70];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ExpStageData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ExpStageData* pInstance);
        static void Clean(ExpStageData* pInstance);
    };
}

namespace heur::rfl {
    struct MaxScoreData {
        uint32_t total;
        uint32_t grind;
        uint32_t graindStep;
        uint32_t doubleBoost;
        uint32_t quickStep;
        uint32_t useGadget;
        uint32_t getWisp;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MaxScoreData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MaxScoreData* pInstance);
        static void Clean(MaxScoreData* pInstance);
    };
}

namespace heur::rfl {
    struct MissionDataBase {
        int16_t missionID;
        int32_t prevMissionID;
        bool completedDisplay;
        csl::ut::VariableString developText;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MissionDataBase* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MissionDataBase* pInstance);
        static void Clean(MissionDataBase* pInstance);
    };
}

namespace heur::rfl {
    struct MissionDataSingle : MissionDataBase {
        enum class EventID : int16_t {
            EVENT_NONE = 0,
            CHARA_CUSTOMIZE_GADGET = 1,
            CHARA_CUSTOMIZE_HEAD = 2,
            CHARA_CUSTOMIZE_GRASS = 3,
            CHARA_CUSTOMIZE_FACE = 4,
            CHARA_CUSTOMIZE_GLOVE = 5,
            CHARA_CUSTOMIZE_SHOSE = 6,
            CHARA_CUSTOMIZE_BODY = 7,
            CHARA_CUSTOMIZE_PATTERN = 8,
            DO_SLIDING = 9,
            DO_STOMPING = 10,
            DO_BOOST = 11,
            DO_AIRBOOST = 12,
            DO_HOMING_ATTACK = 13,
            DO_QUICK_STEP = 14,
            DO_BOOST_GOAL = 15,
            DO_SPIN = 16,
            DO_SPINDASH = 17,
            JUMP_AND_STOMPING = 18,
            AIRBOOST_AND_STOMPING = 19,
            STOMPING_CANCEL_SLIDING = 20,
            STOMPING_CANCEL_BOOST = 21,
            DEFEAT_ENEMY_ONCE_SLIDING = 22,
            DEFEAT_ENEMY_ONCE_BOOST = 23,
            DEFEAT_ENEMY_ONCE_HOMING_ATTACK = 24,
            DEFEAT_ENEMY_ONCE_STOMPING = 25,
            DEFEAT_ENEMY_ONCE_SPIN = 26,
            DEFEAT_ENEMY_ONCE_SPINDASH = 27,
            DEFEAT_ENEMY_ONCE_ASTEROID = 28,
            DEFEAT_ENEMY_ONCE_LIGHTNING = 29,
            DEFEAT_ENEMY_ONCE_CUBE = 30,
            DEFEAT_ENEMY_ONCE_DRILL = 31,
            DEFEAT_ENEMY_ONCE_VOID = 32,
            DEFEAT_ENEMY_ONCE_BURST = 33,
            DEFEAT_ENEMY_ONCE_HOVER = 34,
            USE_ASTEROID = 35,
            USE_LIGHTNING = 36,
            USE_CUBE = 37,
            USE_DRILL = 38,
            USE_VOID = 39,
            USE_BURST = 40,
            USE_HOVER = 41,
            GET_REDSTARRING = 42,
            STAGE_CLEAR = 43,
            STAGE_CLEAR_RANK = 44,
            STAGE_CLEAR_TIME = 45,
            STAGE_CLEAR_EX = 46,
            STAGE_CLEAR_SECRET = 47,
            STAGE_CLEAR_EX_RANK = 48,
            STAGE_CLEAR_EX_TIME = 49,
            STAGE_CLEAR_SONIC = 50,
            STAGE_CLEAR_CLASSIC = 51,
            STAGE_CLEAR_BUDDY = 52,
            STAGE_CLEAR_TAG = 53,
            STAGE_CLEAR_SOS = 54,
            LEVEL_DOG = 55,
            LEVEL_WOLF = 56,
            LEVEL_RABBIT = 57,
            LEVEL_BEAR = 58,
            LEVEL_CAT = 59,
            LEVEL_BIRD = 60,
            LEVEL_HEDGEHOG = 61,
            ID_MAX = 62,
        };

        EventID missionEventID;
        int32_t clearValue;
        int32_t stageNo;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MissionDataSingle* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MissionDataSingle* pInstance);
        static void Clean(MissionDataSingle* pInstance);
    };
}

namespace heur::rfl {
    struct StageClearMissionDataSingle : MissionDataBase {
        int32_t stageNo;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageClearMissionDataSingle* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageClearMissionDataSingle* pInstance);
        static void Clean(StageClearMissionDataSingle* pInstance);
    };
}

namespace heur::rfl {
    struct StageMissionDataSingle : MissionDataBase {
        int32_t clearValue;
        int32_t stageNo;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageMissionDataSingle* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageMissionDataSingle* pInstance);
        static void Clean(StageMissionDataSingle* pInstance);
    };
}

namespace heur::rfl {
    struct ValueMissionDataSingle : MissionDataBase {
        int32_t clearValue;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ValueMissionDataSingle* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ValueMissionDataSingle* pInstance);
        static void Clean(ValueMissionDataSingle* pInstance);
    };
}

namespace heur::rfl {
    struct AllMissionData {
        MissionDataSingle m_dailyMission[20];
        MissionDataSingle m_sonicChallenge[30];
        MissionDataSingle m_buddyChallenge[30];
        StageClearMissionDataSingle m_clearChallenge[50];
        StageMissionDataSingle m_resultChallenge[50];
        StageMissionDataSingle m_timeChallenge[50];
        ValueMissionDataSingle m_dogChallenge[5];
        ValueMissionDataSingle m_wolfChallenge[5];
        ValueMissionDataSingle m_rabbitChallenge[5];
        ValueMissionDataSingle m_bearChallenge[5];
        ValueMissionDataSingle m_catChallenge[5];
        ValueMissionDataSingle m_birdChallenge[5];
        ValueMissionDataSingle m_hedgehogChallenge[5];
        ValueMissionDataSingle m_redStarRingChallenge[10];
        ValueMissionDataSingle m_sosChallenge[10];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AllMissionData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AllMissionData* pInstance);
        static void Clean(AllMissionData* pInstance);
    };
}

namespace heur::rfl {
    struct DailyMissionParameter {
        float bonusValue[10];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DailyMissionParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DailyMissionParameter* pInstance);
        static void Clean(DailyMissionParameter* pInstance);
    };
}

namespace heur::rfl {
    struct MissionTextLabel {
        enum class EventID : int16_t {
            EVENT_NONE = 0,
            CHARA_CUSTOMIZE_GADGET = 1,
            CHARA_CUSTOMIZE_HEAD = 2,
            CHARA_CUSTOMIZE_GRASS = 3,
            CHARA_CUSTOMIZE_FACE = 4,
            CHARA_CUSTOMIZE_GLOVE = 5,
            CHARA_CUSTOMIZE_SHOSE = 6,
            CHARA_CUSTOMIZE_BODY = 7,
            CHARA_CUSTOMIZE_PATTERN = 8,
            DO_SLIDING = 9,
            DO_STOMPING = 10,
            DO_BOOST = 11,
            DO_AIRBOOST = 12,
            DO_HOMING_ATTACK = 13,
            DO_QUICK_STEP = 14,
            DO_BOOST_GOAL = 15,
            DO_SPIN = 16,
            DO_SPINDASH = 17,
            JUMP_AND_STOMPING = 18,
            AIRBOOST_AND_STOMPING = 19,
            STOMPING_CANCEL_SLIDING = 20,
            STOMPING_CANCEL_BOOST = 21,
            DEFEAT_ENEMY_ONCE_SLIDING = 22,
            DEFEAT_ENEMY_ONCE_BOOST = 23,
            DEFEAT_ENEMY_ONCE_HOMING_ATTACK = 24,
            DEFEAT_ENEMY_ONCE_STOMPING = 25,
            DEFEAT_ENEMY_ONCE_SPIN = 26,
            DEFEAT_ENEMY_ONCE_SPINDASH = 27,
            DEFEAT_ENEMY_ONCE_ASTEROID = 28,
            DEFEAT_ENEMY_ONCE_LIGHTNING = 29,
            DEFEAT_ENEMY_ONCE_CUBE = 30,
            DEFEAT_ENEMY_ONCE_DRILL = 31,
            DEFEAT_ENEMY_ONCE_VOID = 32,
            DEFEAT_ENEMY_ONCE_BURST = 33,
            DEFEAT_ENEMY_ONCE_HOVER = 34,
            USE_ASTEROID = 35,
            USE_LIGHTNING = 36,
            USE_CUBE = 37,
            USE_DRILL = 38,
            USE_VOID = 39,
            USE_BURST = 40,
            USE_HOVER = 41,
            GET_REDSTARRING = 42,
            STAGE_CLEAR = 43,
            STAGE_CLEAR_RANK = 44,
            STAGE_CLEAR_TIME = 45,
            STAGE_CLEAR_EX = 46,
            STAGE_CLEAR_SECRET = 47,
            STAGE_CLEAR_EX_RANK = 48,
            STAGE_CLEAR_EX_TIME = 49,
            STAGE_CLEAR_SONIC = 50,
            STAGE_CLEAR_CLASSIC = 51,
            STAGE_CLEAR_BUDDY = 52,
            STAGE_CLEAR_TAG = 53,
            STAGE_CLEAR_SOS = 54,
            LEVEL_DOG = 55,
            LEVEL_WOLF = 56,
            LEVEL_RABBIT = 57,
            LEVEL_BEAR = 58,
            LEVEL_CAT = 59,
            LEVEL_BIRD = 60,
            LEVEL_HEDGEHOG = 61,
            ID_MAX = 62,
        };

        EventID eventID;
        csl::ut::VariableString label;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MissionTextLabel* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MissionTextLabel* pInstance);
        static void Clean(MissionTextLabel* pInstance);
    };
}

namespace heur::rfl {
    struct MissionTextLabels {
        MissionTextLabel labelList[62];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MissionTextLabels* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MissionTextLabels* pInstance);
        static void Clean(MissionTextLabels* pInstance);
    };
}

namespace heur::rfl {
    struct NetBuddyData {
        uint8_t dummy;
        uint8_t pad[3];
        CustomizeData customizeData;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(NetBuddyData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(NetBuddyData* pInstance);
        static void Clean(NetBuddyData* pInstance);
    };
}

namespace heur::rfl {
    struct PlatformData {
        uint8_t data[16];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlatformData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlatformData* pInstance);
        static void Clean(PlatformData* pInstance);
    };
}

namespace heur::rfl {
    struct FriendData {
        int8_t name[80];
        uint16_t country;
        uint8_t padding[2];
        NetBuddyData buddyData;
        PlatformData platformData;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FriendData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FriendData* pInstance);
        static void Clean(FriendData* pInstance);
    };
}

namespace heur::rfl {
    struct BossBigZavokParameter {
        bool battleCheck;
        int32_t maxHealthPoint;
        int32_t berserkHealthPoint;
        int32_t turnCount;
        int32_t turnCountBerserk;
        float turnStartupTime;
        float turnTime;
        float maxTurnDistance;
        float punchChargeTime;
        float punchChargeTimeBerserk;
        float punchTurnSpeed;
        float punchTurnSpeedBerserk;
        bool startupPunchIfNear;
        bool startupPunchIfNearBerserk;
        float punchMinChargeTime;
        float punchMinChargeTimeBerserk;
        float punchStartupTime;
        float punchStartupTimeBerserk;
        float punchActiveTime;
        float punchActiveTimeBerserk;
        float punchRecoveryTime;
        float punchRecoveryTimeBerserk;
        float punchHitSphereRadius;
        bool generateQuakeByPunch;
        bool generateQuakeByPunchBerserk;
        float beamStartupTime;
        float beamStartupTimeBerserk;
        float beamActiveTime;
        float beamActiveTimeBerserk;
        float beamHitSphereRadius;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBigZavokParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBigZavokParameter* pInstance);
        static void Clean(BossBigZavokParameter* pInstance);
    };
}

namespace heur::rfl {
    struct BossEggDragoonParameter {
        uint32_t firstHalfHealthPoint;
        uint32_t latterHalfHealthPoint;
        float tailMoveCycleTime;
        float shotTime;
        float shotDelay;
        float shotSpeed;
        uint32_t drilNum;
        float drilAttackTime;
        float drilSpeed;
        float boosHpGaugeTimeMobile;
        float boosHpGaugeTimeDragoon;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossEggDragoonParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossEggDragoonParameter* pInstance);
        static void Clean(BossEggDragoonParameter* pInstance);
    };
}

namespace heur::rfl {
    struct StoneData {
        int32_t use;
        float distance;
        float time;
        float topHieght;
        float topPoint;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StoneData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StoneData* pInstance);
        static void Clean(StoneData* pInstance);
    };
}

namespace heur::rfl {
    struct StonePattern {
        StoneData stoneData[10];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StonePattern* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StonePattern* pInstance);
        static void Clean(StonePattern* pInstance);
    };
}

namespace heur::rfl {
    struct BossEggDragoonStoneAttackParameter {
        StonePattern stonePattern[10];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossEggDragoonStoneAttackParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossEggDragoonStoneAttackParameter* pInstance);
        static void Clean(BossEggDragoonStoneAttackParameter* pInstance);
    };
}

namespace heur::rfl {
    struct DebrisParam {
        int32_t use;
        float distance;
        float time;
        float topHieght;
        float topPoint;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DebrisParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DebrisParam* pInstance);
        static void Clean(DebrisParam* pInstance);
    };
}

namespace heur::rfl {
    struct DebrisPattern {
        DebrisParam debrisParam[10];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DebrisPattern* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DebrisPattern* pInstance);
        static void Clean(DebrisPattern* pInstance);
    };
}

namespace heur::rfl {
    struct BossFinalDeathEggRoboDebrisAttackParameter {
        DebrisPattern debrisPattern[10];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossFinalDeathEggRoboDebrisAttackParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossFinalDeathEggRoboDebrisAttackParameter* pInstance);
        static void Clean(BossFinalDeathEggRoboDebrisAttackParameter* pInstance);
    };
}

namespace heur::rfl {
    struct FDENormalDamageParameter {
        float homingDamage;
        float boostDamage;
        float spinDamage;
        float fatalDamage;
        float etcDamage;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FDENormalDamageParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FDENormalDamageParameter* pInstance);
        static void Clean(FDENormalDamageParameter* pInstance);
    };
}

namespace heur::rfl {
    struct FDEGadgetDamageParameter {
        float asteroidDamage;
        float drillDamage;
        float cubeDamage;
        float lightningDamage;
        float burstDamage;
        float voidDamage;
        float hoverDamage;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FDEGadgetDamageParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FDEGadgetDamageParameter* pInstance);
        static void Clean(FDEGadgetDamageParameter* pInstance);
    };
}

namespace heur::rfl {
    struct FDE1stLaserPattern {
        uint32_t shotNum;
        float shotAngle;
        float shotTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FDE1stLaserPattern* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FDE1stLaserPattern* pInstance);
        static void Clean(FDE1stLaserPattern* pInstance);
    };
}

namespace heur::rfl {
    struct FDE1stLaser {
        FDE1stLaserPattern laserPattern[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FDE1stLaser* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FDE1stLaser* pInstance);
        static void Clean(FDE1stLaser* pInstance);
    };
}

namespace heur::rfl {
    struct FDE1stMissilePattern {
        uint32_t shotNum;
        float shotAnimRate;
        float speed;
        float homingParam;
        float homingLimitDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FDE1stMissilePattern* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FDE1stMissilePattern* pInstance);
        static void Clean(FDE1stMissilePattern* pInstance);
    };
}

namespace heur::rfl {
    struct FDE1stMissile {
        FDE1stMissilePattern missilePattern[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FDE1stMissile* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FDE1stMissile* pInstance);
        static void Clean(FDE1stMissile* pInstance);
    };
}

namespace heur::rfl {
    struct FDE1stDebrisWave {
        uint32_t debrisNum;
        bool isUse;
        float addDistance;
        float throwingTime;
        float hitPathHeight;
        float topHeight;
        float topPoint;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FDE1stDebrisWave* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FDE1stDebrisWave* pInstance);
        static void Clean(FDE1stDebrisWave* pInstance);
    };
}

namespace heur::rfl {
    struct FDE1stDebrisPattern {
        FDE1stDebrisWave debrisWave[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FDE1stDebrisPattern* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FDE1stDebrisPattern* pInstance);
        static void Clean(FDE1stDebrisPattern* pInstance);
    };
}

namespace heur::rfl {
    struct FDE1stDebris {
        FDE1stDebrisPattern debrisPattern[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FDE1stDebris* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FDE1stDebris* pInstance);
        static void Clean(FDE1stDebris* pInstance);
    };
}

namespace heur::rfl {
    struct FDE1stState {
        enum class FDE1stStatePatternType : int8_t {
            SPT_1ST_NONE = 0,
            SPT_1ST_LASER = 1,
            SPT_1ST_MISSILE = 2,
            SPT_1ST_DBRIS = 3,
        };

        FDE1stStatePatternType stateType;
        int32_t nextStateInedx;
        int32_t damageNextStateInedx;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FDE1stState* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FDE1stState* pInstance);
        static void Clean(FDE1stState* pInstance);
    };
}

namespace heur::rfl {
    struct FDE1st {
        float boosAttackLv2HpRate;
        float boosAttackLv3HpRate;
        FDE1stLaser laserParam;
        FDE1stMissile missileParam;
        FDE1stDebris debrisParam;
        bool isAutoDebris;
        FDE1stState statePatternList[16];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FDE1st* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FDE1st* pInstance);
        static void Clean(FDE1st* pInstance);
    };
}

namespace heur::rfl {
    struct FDE2ndImpact {
        float readyTimeR;
        float readyTimeL;
        float delayR;
        float delayL;
        float invisibleWaveRadius;
        float invisibleWaveSpeed;
        float waveRadiusMin;
        float waveRadiusMax;
        float waveDamageRadius;
        float waveSpeed;
        float waveAddSpeed;
        uint32_t waveNum;
        uint32_t attackNumLv1R;
        uint32_t attackNumLv2R;
        uint32_t attackNumLv3R;
        uint32_t attackNumLv1L;
        uint32_t attackNumLv2L;
        uint32_t attackNumLv3L;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FDE2ndImpact* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FDE2ndImpact* pInstance);
        static void Clean(FDE2ndImpact* pInstance);
    };
}

namespace heur::rfl {
    struct FDE2ndLaserAttackLvPattern {
        float shotTime;
        float readyTime;
        uint32_t attackNum;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FDE2ndLaserAttackLvPattern* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FDE2ndLaserAttackLvPattern* pInstance);
        static void Clean(FDE2ndLaserAttackLvPattern* pInstance);
    };
}

namespace heur::rfl {
    struct FDE2ndLaser {
        FDE2ndLaserAttackLvPattern laserPattern[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FDE2ndLaser* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FDE2ndLaser* pInstance);
        static void Clean(FDE2ndLaser* pInstance);
    };
}

namespace heur::rfl {
    struct FDE2ndMissileAttackLvPattern {
        uint32_t shotNum;
        uint32_t attackNum;
        float speed;
        float homingParam;
        float homingLimitDistance;
        float shotAnimRate;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FDE2ndMissileAttackLvPattern* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FDE2ndMissileAttackLvPattern* pInstance);
        static void Clean(FDE2ndMissileAttackLvPattern* pInstance);
    };
}

namespace heur::rfl {
    struct FDE2ndMissile {
        FDE2ndMissileAttackLvPattern missilePattern[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FDE2ndMissile* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FDE2ndMissile* pInstance);
        static void Clean(FDE2ndMissile* pInstance);
    };
}

namespace heur::rfl {
    struct FDE2ndState {
        enum class FDE2ndStatePatternType : int8_t {
            SPT_2ND_NONE = 0,
            SPT_2ND_MISSILE = 1,
            SPT_2ND_LASER = 2,
            SPT_2ND_IMPACT = 3,
            SPT_2ND_IMPACT_R = 4,
        };

        FDE2ndStatePatternType stateType;
        int32_t nextStateInedx;
        int32_t damageNextStateInedx;
        bool isEnemySpawn;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FDE2ndState* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FDE2ndState* pInstance);
        static void Clean(FDE2ndState* pInstance);
    };
}

namespace heur::rfl {
    struct FDE2nd {
        float boosAttackLv2HpRate;
        float boosAttackLv3HpRate;
        FDE2ndImpact impactParam;
        FDE2ndLaser laserParam;
        FDE2ndMissile missileParam;
        FDE2ndState statePatternList[16];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FDE2nd* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FDE2nd* pInstance);
        static void Clean(FDE2nd* pInstance);
    };
}

namespace heur::rfl {
    struct BossFinalDeathEggRoboParameter {
        uint32_t battle1stHealthPoint;
        uint32_t battle2ndHealthPoint;
        float boosHpGaugeTime1st;
        float boosHpGaugeTime2nd;
        FDENormalDamageParameter normalDamageParam;
        FDENormalDamageParameter normalArmDamageParam;
        FDEGadgetDamageParameter gadgetDamageParam;
        FDEGadgetDamageParameter gadgetArmDamageParam;
        FDE1st battle1stParam;
        FDE2nd battle2ndParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossFinalDeathEggRoboParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossFinalDeathEggRoboParameter* pInstance);
        static void Clean(BossFinalDeathEggRoboParameter* pInstance);
    };
}

namespace heur::rfl {
    struct RocketAttackLvPattern {
        float aimTime;
        float reAimTime;
        float aimParam;
        float moveSpeed;
        uint32_t attackNum;
        float approachBonusRate;
        float approachBonusStartDelay;
        float approachBonusChangeUpSpeed;
        float approachBonusChangeDownSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(RocketAttackLvPattern* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(RocketAttackLvPattern* pInstance);
        static void Clean(RocketAttackLvPattern* pInstance);
    };
}

namespace heur::rfl {
    struct RocketParam {
        float changeDelay;
        RocketAttackLvPattern rocketPattern[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(RocketParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(RocketParam* pInstance);
        static void Clean(RocketParam* pInstance);
    };
}

namespace heur::rfl {
    struct LaserAttackLvPattern {
        uint32_t attackNum;
        float motionSpeedRate;
        float approachBonusRate;
        float approachBonusChangeUpSpeed;
        float approachBonusChangeDownSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(LaserAttackLvPattern* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(LaserAttackLvPattern* pInstance);
        static void Clean(LaserAttackLvPattern* pInstance);
    };
}

namespace heur::rfl {
    struct LaserParam {
        float changeDelay;
        LaserAttackLvPattern laserPattern[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(LaserParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(LaserParam* pInstance);
        static void Clean(LaserParam* pInstance);
    };
}

namespace heur::rfl {
    struct PillarAttackLvPattern {
        uint32_t attackLine;
        float moveAreaWidth;
        float cycleDistance;
        float createDelay;
        float attackWait;
        float endDelay;
        float approachBonusRate;
        float approachBonusStartDelay;
        float approachBonusTime;
        float approachBonusChangeUpSpeed;
        float approachBonusChangeDownSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PillarAttackLvPattern* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PillarAttackLvPattern* pInstance);
        static void Clean(PillarAttackLvPattern* pInstance);
    };
}

namespace heur::rfl {
    struct PillarParam {
        PillarAttackLvPattern pillerPattern[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PillarParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PillarParam* pInstance);
        static void Clean(PillarParam* pInstance);
    };
}

namespace heur::rfl {
    struct StateParam {
        enum class StatePatternType : int8_t {
            SPT_NONE = 0,
            SPT_ROCKET = 1,
            SPT_LASER_L = 2,
            SPT_LASER_R = 3,
            SPT_PILLAR_0 = 4,
            SPT_PILLAR_1 = 5,
            SPT_PILLAR_2 = 6,
        };

        StatePatternType stateType;
        int32_t nextStateInedx;
        int32_t changeNextStateInedx;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StateParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StateParam* pInstance);
        static void Clean(StateParam* pInstance);
    };
}

namespace heur::rfl {
    struct AttackParam {
        float boosAttackLv2HpRate;
        float boosAttackLv3HpRate;
        RocketParam rocketParam;
        LaserParam laserParam;
        PillarParam pillarParam;
        StateParam statePatternList[16];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AttackParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AttackParam* pInstance);
        static void Clean(AttackParam* pInstance);
    };
}

namespace heur::rfl {
    struct BombLandingParameter {
        float phase;
        csl::math::Vector3 landingPos;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BombLandingParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BombLandingParameter* pInstance);
        static void Clean(BombLandingParameter* pInstance);
    };
}

namespace heur::rfl {
    struct BombLandingPattrnParameter {
        bool isUse;
        float shotSpeed;
        BombLandingParameter BombLanding[50];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BombLandingPattrnParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BombLandingPattrnParameter* pInstance);
        static void Clean(BombLandingPattrnParameter* pInstance);
    };
}

namespace heur::rfl {
    struct BombPositionParameter {
        bool isUse;
        float phase;
        csl::math::Vector3 offset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BombPositionParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BombPositionParameter* pInstance);
        static void Clean(BombPositionParameter* pInstance);
    };
}

namespace heur::rfl {
    struct BombPositionListParameter {
        float shotReadyTime;
        BombPositionParameter BombPosition[50];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BombPositionListParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BombPositionListParameter* pInstance);
        static void Clean(BombPositionListParameter* pInstance);
    };
}

namespace heur::rfl {
    struct BossFinalDeathEggRoboLastBombParameter {
        BombPositionListParameter bombPositionListParam;
        BombLandingPattrnParameter bombLandingPattrnParam[6];
        uint32_t useLandingPattern;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossFinalDeathEggRoboLastBombParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossFinalDeathEggRoboLastBombParameter* pInstance);
        static void Clean(BossFinalDeathEggRoboLastBombParameter* pInstance);
    };
}

namespace heur::rfl {
    struct DebrisBlock {
        enum class DebrisType : int8_t {
            DPT_NONE = 0,
            DPT_WISP = 1,
            DPT_RING = 2,
        };

        DebrisType type;
        float offsetDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DebrisBlock* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DebrisBlock* pInstance);
        static void Clean(DebrisBlock* pInstance);
    };
}

namespace heur::rfl {
    struct DebrisBlockPattern {
        DebrisBlock debrisParam[5];
        float delay;
        bool isUse;
        bool isInit;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DebrisBlockPattern* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DebrisBlockPattern* pInstance);
        static void Clean(DebrisBlockPattern* pInstance);
    };
}

namespace heur::rfl {
    struct StageParam {
        uint32_t singleHAMax;
        uint32_t singleHADamage;
        uint32_t trioHADamage;
        float haSlowmotionRate;
        float haDamageSlowmotionRate;
        float haDamageSlowmotionDelay;
        float haDamageSlowmotionLastDelay;
        float haCameraChangeDelay;
        float haCameraChangeLastDelay;
        float toBossDistanceMin;
        float toBossDistanceMax;
        float homingArea;
        float lastTBArea;
        float assumedSpeedLow;
        float assumedSpeedMiddle;
        float assumedSpeedHi;
        float increaseDistanceSpeed;
        float shortenDistanceSpeed;
        float piyoriTime;
        csl::math::Vector3 cameraOffset;
        csl::math::Vector3 cameraOffsetHA;
        DebrisBlockPattern debrisPatternList[10];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageParam* pInstance);
        static void Clean(StageParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossFinalDeathEggRoboLastParameter {
        uint32_t battleHealthPoint;
        float boosHpGaugeTime;
        StageParam stageParam;
        AttackParam attackParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossFinalDeathEggRoboLastParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossFinalDeathEggRoboLastParameter* pInstance);
        static void Clean(BossFinalDeathEggRoboLastParameter* pInstance);
    };
}

namespace heur::rfl {
    struct InfiniteHomingCameraParameter {
        float fovy;
        float minDistanceToTarget;
        float minDistanceToPlayer;
        csl::math::Vector3 targetOffset;
        csl::math::Vector3 playerOffset;
        float easeTimeEnter;
        float easeTimeLeave;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(InfiniteHomingCameraParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(InfiniteHomingCameraParameter* pInstance);
        static void Clean(InfiniteHomingCameraParameter* pInstance);
    };
}

namespace heur::rfl {
    struct InfiniteCopyParameter {
        csl::math::Vector3 pos;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(InfiniteCopyParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(InfiniteCopyParameter* pInstance);
        static void Clean(InfiniteCopyParameter* pInstance);
    };
}

namespace heur::rfl {
    struct BossInfinite1stParameter {
        float modelScale;
        float hp;
        float startRageModeHp;
        float snakeDamage;
        float skyDamage;
        float height;
        float maxDistance;
        float minDistance;
        float playerAutoRunSpeed;
        float speed;
        float boostSpeed;
        float homingSpeed;
        float rollSpeed;
        float distanceResetTime;
        float backTime;
        float attackInterval;
        float slowmotionRate;
        float slowmotionTime;
        float damageTime;
        float homingDistance;
        float homingAngle;
        InfiniteHomingCameraParameter homingCameraParam;
        float homingSlowmotionRate;
        float virtualRealityTime;
        float pipeRadius;
        float pipeLength;
        float pipeStartDistance;
        float pipeSpeed;
        int32_t pipeNum;
        float pipeIntervalDistance;
        float pipeNoticeTime;
        float pipeWaitTime;
        float pipeRadius2;
        float pipeLength2;
        float pipeStartDistance2;
        float pipeSpeed2;
        int32_t pipeNum2;
        float pipeIntervalDistance2;
        float pipeNoticeTime2;
        float pipeWaitTime2;
        float twistRadius;
        float twistLength;
        float twistStartDistance;
        float twistSpeed;
        float twistAngle;
        float twistRotateSpeed;
        float twistHitRadius;
        float twistNoticeTime;
        float twistWaitTime;
        float twistRadius2;
        float twistLength2;
        float twistStartDistance2;
        float twistSpeed2;
        float twistAngle2;
        float twistRotateSpeed2;
        float twistHitRadius2;
        float twistNoticeTime2;
        float twistWaitTime2;
        csl::math::Vector3 rectangleExtents;
        float rectangleStartDistance;
        float rectangleSpeed;
        float rectangleAngle;
        float rectangleRotateSpeed;
        float rectangleHitSize;
        int32_t rectangleNum;
        float rectangleIntervalDistance;
        float rectangleNoticeTime;
        float rectangleWaitTime;
        csl::math::Vector3 rectangleExtents2;
        float rectangleStartDistance2;
        float rectangleSpeed2;
        float rectangleAngle2;
        float rectangleRotateSpeed2;
        float rectangleHitSize2;
        int32_t rectangleNum2;
        float rectangleIntervalDistance2;
        float rectangleNoticeTime2;
        float rectangleWaitTime2;
        csl::math::Vector3 closeExtents;
        float closeRadius;
        float closeStartDistance;
        float closeStartAngle;
        float closeAppearTime;
        float closeTime;
        float closeNoticeTime;
        float closeWaitTime;
        csl::math::Vector3 closeExtents2;
        float closeRadius2;
        float closeStartDistance2;
        float closeStartAngle2;
        float closeAppearTime2;
        float closeTime2;
        float closeNoticeTime2;
        float closeWaitTime2;
        float runStartPathDistance;
        float jumpStartPathDistance;
        float jumpWaitTime;
        float jumpSpeed;
        float jumpOutOfControl;
        float jumpkeepVelocityTime;
        bool jumpTargetAirPath;
        csl::math::Vector3 jumpTargetPos;
        float jumpWaitTime2;
        float jumpSpeed2;
        float jumpOutOfControl2;
        float jumpkeepVelocityTime2;
        bool jumpTargetAirPath2;
        csl::math::Vector3 jumpTargetPos2;
        float skyPathAdvanceSpeed;
        float skyDamageKnockBack;
        float skyDamageKnockBackTime;
        float skyDeadKnockBack;
        float skyDeadKnockBackTime;
        float noiseCycleMax;
        float noiseCycleMin;
        float copyDeadExplosinTime;
        float copyDeadExplosinSpeed;
        uint32_t copyNum;
        uint32_t copyNum2;
        InfiniteCopyParameter copyList[30];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossInfinite1stParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossInfinite1stParameter* pInstance);
        static void Clean(BossInfinite1stParameter* pInstance);
    };
}

namespace heur::rfl {
    struct BossInfinite2ndParameter {
        float modelScale;
        float hp;
        float height;
        float noticeTime;
        float moveSpeed;
        float moveStartDistance;
        float moveDistance;
        float attackInterval;
        bool countWhileVirtron;
        float damageTime;
        float damagePoint;
        float criticalDamagePoint;
        float gadgetDamageWaitTime;
        float asteroidDamage;
        float drillDamage;
        float cubeDamage;
        float lightningDamage;
        float burstDamage;
        float hoverDamage;
        float voidDamage;
        float powerUpTime;
        float moveSpeedUpRate;
        float DefenceUpRate;
        float chargeSpeed;
        float chargeAffterWaitTime;
        float chargeAffterRiseTime;
        float chargeSpeed2;
        float charge2ndWaitTime;
        float chargeAffterWaitTime2;
        float chargeAffterRiseTime2;
        float toBackSpeed;
        csl::math::Vector3 pillarStartPos;
        float pillarHeight;
        float pillarDepth;
        float pillarNoticeTime;
        float pillarRiseTime;
        float pillarLifeTime;
        float pillarEndTime;
        csl::math::Vector3 pillarStartPos2;
        float pillarHeight2;
        float pillarDepth2;
        float pillarNoticeTime2;
        float pillarRiseTime2;
        float pillarLifeTime2;
        float pillarEndTime2;
        float beamRadius;
        float beamSpeed;
        float beamRotateMax;
        float beamLifeTime;
        float beamTailLifeTime;
        csl::math::Vector3 beamStartPos[8];
        float beamMoveStartTime;
        float beamEndTime;
        float beamRadius2;
        float beamSpeed2;
        float beamRotateMax2;
        float beamLifeTime2;
        float beamTailLifeTime2;
        csl::math::Vector3 beamStartPos2[8];
        float beamMoveStartTime2;
        float beamEndTime2;
        float virtualRealityTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossInfinite2ndParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossInfinite2ndParameter* pInstance);
        static void Clean(BossInfinite2ndParameter* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite2ndPillarData {
        float width;
        float pathPos;
        float phase;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite2ndPillarData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite2ndPillarData* pInstance);
        static void Clean(Infinite2ndPillarData* pInstance);
    };
}

namespace heur::rfl {
    struct BossInfinite2ndPillarParameter {
        Infinite2ndPillarData pillarData[30];
        Infinite2ndPillarData pillarData2[30];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossInfinite2ndPillarParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossInfinite2ndPillarParameter* pInstance);
        static void Clean(BossInfinite2ndPillarParameter* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdDoubleBoostParameter {
        float playerSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdDoubleBoostParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdDoubleBoostParameter* pInstance);
        static void Clean(Infinite3rdDoubleBoostParameter* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdParamAvoid {
        float speedMax;
        float accele;
        float decele;
        float startDistance;
        float marginDistance;
        float angleSpeedMin;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdParamAvoid* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdParamAvoid* pInstance);
        static void Clean(Infinite3rdParamAvoid* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdParamAvoidEvnet {
        float waitRandomTime;
        float apartTime;
        float apartSpeed;
        float apartRotateSpeed;
        float scaleDownTime;
        float scaleUpTime;
        float gatherTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdParamAvoidEvnet* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdParamAvoidEvnet* pInstance);
        static void Clean(Infinite3rdParamAvoidEvnet* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdParamCameraShakeBoost {
        float time;
        float magnitude;
        int32_t freq;
        float attenRatio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdParamCameraShakeBoost* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdParamCameraShakeBoost* pInstance);
        static void Clean(Infinite3rdParamCameraShakeBoost* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdParamChase {
        float baseMinDistance;
        float baseMaxDistance;
        float approachSpeed;
        float approachRatio;
        float homingApproachRatio;
        float awaySpeed;
        float awayRatio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdParamChase* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdParamChase* pInstance);
        static void Clean(Infinite3rdParamChase* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdParamCommon {
        int32_t lifepoint;
        int32_t angryLifepoint;
        float shieldpoint;
        float ableToHomingDistance;
        float entryDistance;
        float modelHeightOffset;
        float modelScale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdParamCommon* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdParamCommon* pInstance);
        static void Clean(Infinite3rdParamCommon* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdParamCrossType {
        float distance;
        int32_t numRows;
        float rowSpan;
        float sideOffset;
        float heightOffset;
        float avoidOffset;
        float startAngle;
        float rotSpeedMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdParamCrossType* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdParamCrossType* pInstance);
        static void Clean(Infinite3rdParamCrossType* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdParamCross {
        Infinite3rdParamChase beforeChase;
        Infinite3rdParamChase afterChase;
        float radius;
        float height;
        float attackDistance;
        float createTime;
        float chargeTime;
        float releaseTime;
        float chargeRadius;
        float releaseRatio;
        float awayDistance;
        Infinite3rdParamCrossType normal0[10];
        Infinite3rdParamCrossType high0[10];
        Infinite3rdParamAvoid avoid;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdParamCross* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdParamCross* pInstance);
        static void Clean(Infinite3rdParamCross* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdParamDamage {
        Infinite3rdParamChase chase;
        float homingDamagePoint;
        float boostDamagePoint;
        float spinDamagePoint;
        float asteroidDamage;
        float drillDamage;
        float cubeDamage;
        float lightningDamage;
        float burstDamage;
        float hoverDamage;
        float asteroidCounter;
        float drillCounter;
        float cubeCounter;
        float lightningCounter;
        float burstCounter;
        float damageIntervalTime;
        uint32_t homingDamageLimit;
        float damageTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdParamDamage* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdParamDamage* pInstance);
        static void Clean(Infinite3rdParamDamage* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdParamDamageCamera {
        float easeTimeEnter;
        float easeTimeLeave;
        float slowRatioShield;
        float slowTimeShield;
        float slowRatioDamage;
        float slowTimeDamage;
        float slowRatioCounter;
        float slowTimeCounter;
        float slowRatioFinish;
        float slowTimeFinish;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdParamDamageCamera* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdParamDamageCamera* pInstance);
        static void Clean(Infinite3rdParamDamageCamera* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdParamDashAtack {
        float endWait;
        float endWarpWait;
        float affterDistance;
        float waitTime;
        float followMaxSpeed;
        float speed;
        float endDistance;
        float colWidth;
        float colLength;
        float colHeight;
        float colSpeed;
        float effPlaySpeed;
        float heightOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdParamDashAtack* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdParamDashAtack* pInstance);
        static void Clean(Infinite3rdParamDashAtack* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdParamEntryEvnet {
        float waitTime;
        float waitRandomTime;
        float rotateTime;
        float backTime;
        float rotateSpeed;
        float radiusMax;
        float scaleUpTime;
        float boostSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdParamEntryEvnet* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdParamEntryEvnet* pInstance);
        static void Clean(Infinite3rdParamEntryEvnet* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdParamSeqUnit {
        enum class ActionType : int8_t {
            ACT_FLY = 0,
            ACT_KEEPAWAY = 1,
            ACT_SPAWN = 2,
            ACT_SHIELD = 3,
            ACT_ELECTLIC = 4,
            ACT_DASH = 5,
            ACT_LOOP = 6,
        };

        ActionType action;
        bool beforeKeepAway;
        float keepAwayDistance;
        float keepAwayAccele;
        float actionTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdParamSeqUnit* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdParamSeqUnit* pInstance);
        static void Clean(Infinite3rdParamSeqUnit* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdParamSeq {
        Infinite3rdParamSeqUnit before[10];
        Infinite3rdParamSeqUnit after[10];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdParamSeq* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdParamSeq* pInstance);
        static void Clean(Infinite3rdParamSeq* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdParamShieldType {
        float openedDistance;
        int32_t numShields;
        int32_t numRings;
        float radiusAppear;
        float radiusMin;
        float radiusSpan;
        float angularSpeed;
        float idleTime;
        float heightOffset;
        float tiltBase;
        float tiltSpan;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdParamShieldType* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdParamShieldType* pInstance);
        static void Clean(Infinite3rdParamShieldType* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdParamShield {
        Infinite3rdParamChase beforeChase;
        Infinite3rdParamChase afterChase;
        Infinite3rdParamShieldType normal;
        Infinite3rdParamShieldType high;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdParamShield* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdParamShield* pInstance);
        static void Clean(Infinite3rdParamShield* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdParamSpawnType {
        enum class SpawnType : int8_t {
            SPAWN_PAWN = 0,
            SPAWN_RING = 1,
            SPAWN_WHITE_WISP = 2,
            SPAWN_COLOR_WISP = 3,
        };

        SpawnType type;
        float distance;
        int32_t numSpawns;
        int32_t numRows;
        float sideOffset;
        float distanceSpan;
        float rowSpan;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdParamSpawnType* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdParamSpawnType* pInstance);
        static void Clean(Infinite3rdParamSpawnType* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdParamSpawn {
        Infinite3rdParamChase chase;
        Infinite3rdParamSpawnType types0[10];
        Infinite3rdParamSpawnType high0[10];
        float distance;
        float spawnDistance;
        float despawnDistance;
        bool useAsteroid;
        bool useLightning;
        bool useCube;
        bool useDrill;
        bool useBurst;
        bool useVoid;
        bool useHover;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdParamSpawn* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdParamSpawn* pInstance);
        static void Clean(Infinite3rdParamSpawn* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdParamVirtualReality {
        float time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdParamVirtualReality* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdParamVirtualReality* pInstance);
        static void Clean(Infinite3rdParamVirtualReality* pInstance);
    };
}

namespace heur::rfl {
    struct Infinite3rdParmaWarp {
        float changeStateTime;
        float endDistance;
        float threatenWarpDistance;
        float startTime;
        float waitTime;
        float endTime;
        float width;
        float height;
        int32_t warpNum;
        bool isThreaten;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Infinite3rdParmaWarp* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Infinite3rdParmaWarp* pInstance);
        static void Clean(Infinite3rdParmaWarp* pInstance);
    };
}

namespace heur::rfl {
    struct BeehiveSummonParam {
        enum class ObjectType : int8_t {
            OBJ_NONE = 0,
            OBJ_NEXT = 1,
            OBJ_BEETON = 2,
            OBJ_IDLE_BEETON = 3,
            OBJ_CHARGE_BEETON = 4,
            OBJ_H_CHARGE_BEETON = 5,
            OBJ_RING = 6,
            OBJ_SUPERRING = 7,
        };

        float timing;
        ObjectType objectType;
        int16_t placeId;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BeehiveSummonParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BeehiveSummonParam* pInstance);
        static void Clean(BeehiveSummonParam* pInstance);
    };
}

namespace heur::rfl {
    struct BeehiveSummonTable {
        enum class QueenActionType : int8_t {
            QUEEN_ACTION_LASER = 0,
            QUEEN_ACTION_MOVE_AWAY = 1,
        };

        QueenActionType queenActionType;
        BeehiveSummonParam params[20];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BeehiveSummonTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BeehiveSummonTable* pInstance);
        static void Clean(BeehiveSummonTable* pInstance);
    };
}

namespace heur::rfl {
    struct BossLockonCameraParameter {
        float fovy;
        float minDistanceToTarget;
        float minDistanceToPlayer;
        csl::math::Vector3 targetOffset;
        csl::math::Vector3 playerOffset;
        float azimuthOffset;
        float elevationOffset;
        float easeTimeEnter;
        float easeTimeLeave;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossLockonCameraParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossLockonCameraParameter* pInstance);
        static void Clean(BossLockonCameraParameter* pInstance);
    };
}

namespace heur::rfl {
    struct BossQueenBeetonParameter {
        bool battleCheck;
        bool debugDraw;
        bool bodyAttack;
        bool beetonInducedExplosion;
        bool laserTargetMove;
        float laserTargetSpeed;
        int32_t maxHealthPoint;
        int32_t berserkHealthPoint;
        float speed;
        float angularSpeed;
        float height;
        float maxAngle;
        float floorEdgeOffset;
        float roundTime;
        float laserHeight;
        float laserVisualRadius;
        float laserHitRadius;
        float laserNoticeTime;
        float laserIrradiateTime;
        float laserIrradiateEndTime;
        float laserAngularSpeed;
        float kamikazeHeight;
        float summonHeight;
        float chainHomingTime;
        float chainHomingSlowSpeed;
        float chainHomingAttackSlowSpeed;
        float chargeAngularSpeed;
        float chargeWaitTime;
        float chargeHeight;
        float chargeSpeed;
        float chargeHitSphereRadius;
        csl::math::Vector3 chargeHitSphereOffset;
        float meteorHomingTime;
        float meteorHomingSpeed;
        float meteorHomingAccele;
        float meteorHomingDeceleDist;
        float meteorSpeed;
        float sonicJumpUpVelocity;
        csl::math::Vector3 sonicBoundVelocity;
        float zavokHitStopTime;
        float zavokHitGameSpeed;
        float stickTime;
        ObjCameraVerticalSpawner stickCameraParam;
        BossLockonCameraParameter lockonCameraParam;
        BossLockonCameraParameter chainHomingCameraParam;
        bool useDummyTable;
        float dummyInterval;
        int32_t dummyNumBeetons;
        int32_t dummyNumSuperRing;
        int32_t numSummonTables;
        BeehiveSummonTable summonTables[10];
        int32_t numBerserkSummonTables;
        BeehiveSummonTable berserkSummonTables[10];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossQueenBeetonParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossQueenBeetonParameter* pInstance);
        static void Clean(BossQueenBeetonParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjVirtronWaveParameter {
        float maxDistance;
        float speed;
        float attackPower;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjVirtronWaveParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjVirtronWaveParameter* pInstance);
        static void Clean(ObjVirtronWaveParameter* pInstance);
    };
}

namespace heur::rfl {
    struct PhysicsParam {
        float mass;
        float friction;
        float gravityFactor;
        float restitution;
        float linearDamping;
        float angularDamping;
        float maxLinearVelocity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PhysicsParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PhysicsParam* pInstance);
        static void Clean(PhysicsParam* pInstance);
    };
}

namespace heur::rfl {
    struct MotionData {
        csl::ut::VariableString motionName;
        bool syncFrame;
        bool stopEndFrame;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MotionData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MotionData* pInstance);
        static void Clean(MotionData* pInstance);
    };
}

namespace heur::rfl {
    struct MirageAnimData {
        csl::ut::VariableString texSrtAnimName0;
        csl::ut::VariableString texSrtAnimName1;
        csl::ut::VariableString texSrtAnimName2;
        csl::ut::VariableString texPatAnimName0;
        csl::ut::VariableString texPatAnimName1;
        csl::ut::VariableString texPatAnimName2;
        csl::ut::VariableString matAnimName0;
        csl::ut::VariableString matAnimName1;
        csl::ut::VariableString matAnimName2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MirageAnimData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MirageAnimData* pInstance);
        static void Clean(MirageAnimData* pInstance);
    };
}

namespace heur::rfl {
    struct ProgramMotionData {
        enum class MotionType : int8_t {
            MOTION_SWING = 0,
            MOTION_ROTATE = 1,
            MOTION_LINEAR_SWING = 2,
        };

        MotionType motionType;
        csl::math::Vector3 axis;
        float power;
        float speedScale;
        float time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ProgramMotionData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ProgramMotionData* pInstance);
        static void Clean(ProgramMotionData* pInstance);
    };
}

namespace heur::rfl {
    struct EffectData {
        csl::ut::VariableString effectName;
        bool linkMotionStop;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EffectData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EffectData* pInstance);
        static void Clean(EffectData* pInstance);
    };
}

namespace heur::rfl {
    struct SoundData {
        csl::ut::VariableString cueName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SoundData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SoundData* pInstance);
        static void Clean(SoundData* pInstance);
    };
}

namespace heur::rfl {
    struct DebrisData {
        float gravity;
        float lifeTime;
        float mass;
        float explosionScale;
        float impulseScale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DebrisData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DebrisData* pInstance);
        static void Clean(DebrisData* pInstance);
    };
}

namespace heur::rfl {
    struct KillData {
        enum class KillType : int8_t {
            KILL_TYPE_NOT_KILL = 0,
            KILL_TYPE_KILL = 1,
            KILL_TYPE_BREAK = 2,
            KILL_TYPE_MOTION = 3,
        };

        KillType killType;
        float killTime;
        csl::ut::VariableString breakMotionName;
        DebrisData debrisData;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(KillData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(KillData* pInstance);
        static void Clean(KillData* pInstance);
    };
}

namespace heur::rfl {
    struct ReactionData {
        MotionData motionData;
        MirageAnimData mirageAnimData;
        ProgramMotionData programMotionData;
        EffectData effectData;
        SoundData soundData;
        KillData killData;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ReactionData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ReactionData* pInstance);
        static void Clean(ReactionData* pInstance);
    };
}

namespace heur::rfl {
    struct ConfigData {
        enum class ShapeType : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
            SHAPE_MESH = 3,
            SHAPE_NONE = 4,
        };

        enum class RigidBodyType : int8_t {
            RIGID_BODY_NONE = 0,
            RIGID_BODY_STATIC = 1,
            RIGID_BODY_DYNAMIC = 2,
        };

        enum class RigidBodyMaterial : int8_t {
            RIGID_BODY_MAT_NONE = 0,
            RIGID_BODY_MAT_WOOD = 1,
            RIGID_BODY_MAT_IRON = 2,
            NUM_RIGID_BODY_MATS = 3,
        };

        enum class ContactDamageType : int8_t {
            CONTACT_DAMAGE_NONE = 0,
            CONTACT_DAMAGE_LOW_SPEED = 1,
            CONTACT_DAMAGE_MIDDLE_SPEED = 2,
            CONTACT_DAMAGE_HIGH_SPEED = 3,
        };

        float rangeIn;
        float rangeDistance;
        csl::ut::VariableString modelName;
        csl::ut::VariableString skeltonName;
        ShapeType shape;
        float width;
        float height;
        float depth;
        csl::ut::VariableString meshName;
        csl::math::Vector3 shapeOffset;
        float shapeSizeOffset;
        RigidBodyType rigidBodyType;
        RigidBodyMaterial rigidBodyMaterial;
        PhysicsParam physicsParam;
        ContactDamageType contactDamageType;
        bool rideOnDamage;
        bool aerialBounce;
        ReactionData reactionIdle;
        ReactionData reactionEnter;
        ReactionData reactionLeave;
        ReactionData reactionStay;
        ReactionData reactionStayMove;
        ReactionData reactionDamage;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ConfigData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ConfigData* pInstance);
        static void Clean(ConfigData* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyParameterBase {
        float addBoostEnergy;
        float addDoubleBoostEnergy;
        float cubeSizeX;
        float cubeSizeY;
        float cubeSizeZ;
        float cubeOffsetY;
        float cubeOffsetZ;
        int32_t cubeGetBlueRing;
        float fallSpeed;
        float rigidbodyMaxSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyParameterBase* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyParameterBase* pInstance);
        static void Clean(EnemyParameterBase* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyBeetonParameter : EnemyParameterBase {
        float shotSpeedFV;
        float shotSpeedSV;
        float bulletScaleFV;
        float bulletScaleSV;
        float shotInterval;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyBeetonParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyBeetonParameter* pInstance);
        static void Clean(EnemyBeetonParameter* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggChaserParameter : EnemyParameterBase {
        float laserSpeed;
        float laserLength;
        float laserRadius;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggChaserParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggChaserParameter* pInstance);
        static void Clean(EnemyEggChaserParameter* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggpawnParameter : EnemyParameterBase {
        float shotSpeedFV;
        float shotSpeedSV;
        float bulletScaleFV;
        float bulletScaleSV;
        float bulletMaxDistanceFV;
        float bulletMaxDistanceSV;
        uint32_t shotContinuousShotNum;
        uint32_t shotContinuousShotNumConst;
        float shotCoolDownTime;
        float shotCoolDownTimeConst;
        float damageCoolDownTime;
        float shotInterval;
        float serachAngleY;
        float oneHandShotSpeedFV;
        float oneHandShotSpeedSV;
        float oneHandBulletScaleFV;
        float oneHandBulletScaleSV;
        float oneHandBulletMaxDistanceFV;
        float oneHandBulletMaxDistanceSV;
        uint32_t oneHandShotContinuousShotNum;
        float oneHandShotCoolDownTime;
        float oneHandDamageCoolDownTime;
        float oneHandShotInterval;
        float oneHandChargeTime;
        float oneHandSerachAngleY;
        float fallDeadTime;
        float threadGrassRadius;
        float threadGrassTime;
        float checkOnGroundUpOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggpawnParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggpawnParameter* pInstance);
        static void Clean(EnemyEggpawnParameter* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggTankParameter : EnemyParameterBase {
        csl::math::Vector3 respawnOffset;
        float respawnTime;
        float bulletFallSpeed;
        float addBulletBoostEnergy;
        float addBulletDoubleBoostEnergy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggTankParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggTankParameter* pInstance);
        static void Clean(EnemyEggTankParameter* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggWalkerParameter : EnemyParameterBase {
        float shotSpeedFV;
        float shotSpeedSV;
        float shotDelayFV;
        float shotDelaySV;
        float AttackWaitFV;
        float AttackWaitSV;
        float threadGrassRadius;
        float threadGrassTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggWalkerParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggWalkerParameter* pInstance);
        static void Clean(EnemyEggWalkerParameter* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicDoubleBoostParameter {
        float playerSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicDoubleBoostParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicDoubleBoostParameter* pInstance);
        static void Clean(MetalSonicDoubleBoostParameter* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicParamAvoid {
        float speedMax;
        float accele;
        float decele;
        float startDistance;
        float marginDistance;
        float angleSpeedMin;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicParamAvoid* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicParamAvoid* pInstance);
        static void Clean(MetalSonicParamAvoid* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicParamCameraShakeBoost {
        float time;
        float magnitude;
        int32_t freq;
        float attenRatio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicParamCameraShakeBoost* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicParamCameraShakeBoost* pInstance);
        static void Clean(MetalSonicParamCameraShakeBoost* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicParamChase {
        float baseMinDistance;
        float baseMaxDistance;
        float approachSpeed;
        float approachRatio;
        float homingApproachRatio;
        float awaySpeed;
        float awayRatio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicParamChase* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicParamChase* pInstance);
        static void Clean(MetalSonicParamChase* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicParamCommon {
        int32_t lifepoint;
        int32_t angryLifepoint;
        float shieldpoint;
        float ableToHomingDistance;
        float entryDistance;
        float modelHeightOffset;
        float noiseCycleMin;
        float noiseCycleMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicParamCommon* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicParamCommon* pInstance);
        static void Clean(MetalSonicParamCommon* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicParamDamage {
        MetalSonicParamChase chase;
        float homingDamagePoint;
        float boostDamagePoint;
        float spinDamagePoint;
        float asteroidDamage;
        float drillDamage;
        float cubeDamage;
        float lightningDamage;
        float burstDamage;
        float hoverDamage;
        float asteroidCounter;
        float drillCounter;
        float cubeCounter;
        float lightningCounter;
        float burstCounter;
        float damageIntervalTime;
        uint32_t homingDamageLimit;
        float damageTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicParamDamage* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicParamDamage* pInstance);
        static void Clean(MetalSonicParamDamage* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicParamDamageCamera {
        float easeTimeEnter;
        float easeTimeLeave;
        float slowRatioShield;
        float slowTimeShield;
        float slowRatioDamage;
        float slowTimeDamage;
        float slowRatioCounter;
        float slowTimeCounter;
        float slowRatioFinish;
        float slowTimeFinish;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicParamDamageCamera* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicParamDamageCamera* pInstance);
        static void Clean(MetalSonicParamDamageCamera* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicParamDamageEffect {
        float middleDiffScale;
        float middleWaitTime;
        float middleConstractWaitTime;
        float middleScalingTimeMax;
        float middleScaleMax;
        float middleScaleMin;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicParamDamageEffect* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicParamDamageEffect* pInstance);
        static void Clean(MetalSonicParamDamageEffect* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicParamDashAtack {
        float endWait;
        float endWarpWait;
        float affterDistance;
        float waitTime;
        float followMaxSpeed;
        float speed;
        float endDistance;
        float colWidth;
        float colLength;
        float colHeight;
        float colSpeed;
        float effPlaySpeed;
        float heightOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicParamDashAtack* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicParamDashAtack* pInstance);
        static void Clean(MetalSonicParamDashAtack* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicParamDeadEvent {
        float voxelScaleMin;
        float voxelScaleMax;
        float voxelScalingSpeed;
        float voxelExplosionSpeed;
        float voxelExplosionTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicParamDeadEvent* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicParamDeadEvent* pInstance);
        static void Clean(MetalSonicParamDeadEvent* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicParamElectroType {
        float distance;
        int32_t numRows;
        float rowSpan;
        float sideOffset;
        float avoidOffset;
        bool isHorizontal;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicParamElectroType* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicParamElectroType* pInstance);
        static void Clean(MetalSonicParamElectroType* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicParamElectro {
        MetalSonicParamChase beforeChase;
        MetalSonicParamChase afterChase;
        float attackDistance;
        float createTime;
        float chargeTime;
        float releaseTime;
        float chargeRadius;
        float releaseRatio;
        float awayDistance;
        MetalSonicParamElectroType normal0[10];
        MetalSonicParamElectroType high0[10];
        MetalSonicParamAvoid avoid;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicParamElectro* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicParamElectro* pInstance);
        static void Clean(MetalSonicParamElectro* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicParamEntryEvnet {
        float radiusMin;
        float radiusMax;
        float rotateSpeed;
        float unionSpeed;
        float startTimeMax;
        float startScale;
        float stopPlayerTime;
        float changeStateWait;
        float flySpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicParamEntryEvnet* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicParamEntryEvnet* pInstance);
        static void Clean(MetalSonicParamEntryEvnet* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicParamSeqUnit {
        enum class ActionType : int8_t {
            ACT_FLY = 0,
            ACT_KEEPAWAY = 1,
            ACT_SPAWN = 2,
            ACT_SHIELD = 3,
            ACT_ELECTLIC = 4,
            ACT_DASH = 5,
            ACT_LOOP = 6,
        };

        ActionType action;
        bool beforeKeepAway;
        float keepAwayDistance;
        float keepAwayAccele;
        float actionTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicParamSeqUnit* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicParamSeqUnit* pInstance);
        static void Clean(MetalSonicParamSeqUnit* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicParamSeq {
        MetalSonicParamSeqUnit before[10];
        MetalSonicParamSeqUnit after[10];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicParamSeq* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicParamSeq* pInstance);
        static void Clean(MetalSonicParamSeq* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicParamShieldType {
        float openedDistance;
        int32_t numShields;
        int32_t numRings;
        float radiusAppear;
        float radiusMin;
        float radiusSpan;
        float angularSpeed;
        float idleTime;
        float heightOffset;
        float tiltBase;
        float tiltSpan;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicParamShieldType* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicParamShieldType* pInstance);
        static void Clean(MetalSonicParamShieldType* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicParamShield {
        MetalSonicParamChase beforeChase;
        MetalSonicParamChase afterChase;
        MetalSonicParamShieldType normal;
        MetalSonicParamShieldType high;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicParamShield* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicParamShield* pInstance);
        static void Clean(MetalSonicParamShield* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicParamSpawnType {
        enum class SpawnType : int8_t {
            SPAWN_PAWN = 0,
            SPAWN_RING = 1,
            SPAWN_WHITE_WISP = 2,
            SPAWN_COLOR_WISP = 3,
        };

        SpawnType type;
        float distance;
        int32_t numSpawns;
        int32_t numRows;
        float sideOffset;
        float distanceSpan;
        float rowSpan;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicParamSpawnType* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicParamSpawnType* pInstance);
        static void Clean(MetalSonicParamSpawnType* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicParamSpawn {
        MetalSonicParamChase chase;
        MetalSonicParamSpawnType types0[10];
        MetalSonicParamSpawnType high0[10];
        float distance;
        float spawnDistance;
        float despawnDistance;
        bool useAsteroid;
        bool useLightning;
        bool useCube;
        bool useDrill;
        bool useBurst;
        bool useVoid;
        bool useHover;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicParamSpawn* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicParamSpawn* pInstance);
        static void Clean(MetalSonicParamSpawn* pInstance);
    };
}

namespace heur::rfl {
    struct MetalSonicParmaWarp {
        float changeStateTime;
        float endDistance;
        float threatenWarpDistance;
        float startTime;
        float waitTime;
        float endTime;
        float width;
        float height;
        int32_t warpNum;
        bool isThreaten;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MetalSonicParmaWarp* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MetalSonicParmaWarp* pInstance);
        static void Clean(MetalSonicParmaWarp* pInstance);
    };
}

namespace heur::rfl {
    struct ShotSetData {
        enum class ErectricAttackType : int8_t {
            TYPE_POLE = 0,
            TYPE_BAR = 1,
            TYPE_MOVE_POINT = 2,
            TYPE_SOUND_POINT = 3,
            TYPE_BOOST_ITEM = 4,
            TYPE_GADGET_ITEM = 5,
            TYPE_RING = 6,
            TYPE_SUPER_RING = 7,
            TYPE_CROSS = 8,
        };

        enum class LineType : int8_t {
            TYPE_LENGTHWAYS = 0,
            TYPE_SIDEWAYS = 1,
        };

        bool enable;
        ErectricAttackType type;
        csl::math::Vector3 position;
        float angle;
        uint32_t count;
        LineType lineType;
        float interval;
        bool sniper;
        bool isWorldPos;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ShotSetData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ShotSetData* pInstance);
        static void Clean(ShotSetData* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMetalSonicElectricAttackParameter {
        float endTime;
        float depthOffset;
        ShotSetData shotData[35];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMetalSonicElectricAttackParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMetalSonicElectricAttackParameter* pInstance);
        static void Clean(ObjMetalSonicElectricAttackParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMetalSonicParameter {
        MetalSonicParamCommon common;
        MetalSonicParamSeq seq;
        MetalSonicParamChase chase;
        MetalSonicParamSpawn spawn;
        MetalSonicParamShield shield;
        MetalSonicParamElectro electro;
        MetalSonicParamDashAtack dashattack;
        MetalSonicParamDamage damage;
        MetalSonicParamDamageCamera damageCamera;
        MetalSonicParamDamageEffect damageEffect;
        MetalSonicParmaWarp warp;
        MetalSonicParamEntryEvnet entryEvent;
        MetalSonicParamDeadEvent deadEvent;
        MetalSonicParamCameraShakeBoost cameraShakeBoost;
        MetalSonicDoubleBoostParameter doubleboost;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMetalSonicParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMetalSonicParameter* pInstance);
        static void Clean(ObjMetalSonicParameter* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyMotoraParameter : EnemyParameterBase {
        float threadGrassRadius;
        float threadGrassTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyMotoraParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyMotoraParameter* pInstance);
        static void Clean(EnemyMotoraParameter* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyNarlParameter : EnemyParameterBase {
        float hatchAnimTime;
        float leanAngle;
        float rotateSpeed;
        float attackIntervalFV;
        float attackIntervalSV;
        float shotSpeedFV;
        float shotSpeedSV;
        float shotRadiusFV;
        float shotRadiusSV;
        float shotDistanceFV;
        float shotDistanceSV;
        uint32_t shotNum;
        float shotInterval;
        float flameSpeedFV;
        float flameSpeedSV;
        float flameDistanceFV;
        float flameDistanceSV;
        float flameCollisionRadius;
        float flameNoDamageLength;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyNarlParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyNarlParameter* pInstance);
        static void Clean(EnemyNarlParameter* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyPotosParameter : EnemyParameterBase {
        float bombFallSpeedMax;
        float scaleFV;
        float scaleSV;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyPotosParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyPotosParameter* pInstance);
        static void Clean(EnemyPotosParameter* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyValKeenParameter : EnemyParameterBase {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyValKeenParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyValKeenParameter* pInstance);
        static void Clean(EnemyValKeenParameter* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyGalagaBeeParameter : EnemyParameterBase {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyGalagaBeeParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyGalagaBeeParameter* pInstance);
        static void Clean(EnemyGalagaBeeParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFlameCollisionParameter {
        csl::math::Vector3 collision02MSize;
        csl::math::Vector3 collision04MSize;
        csl::math::Vector3 collision06MSize;
        csl::math::Vector3 collision08MSize;
        csl::math::Vector3 collision10MSize;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFlameCollisionParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFlameCollisionParameter* pInstance);
        static void Clean(ObjFlameCollisionParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjAuraTrainParameter {
        float frontDistance;
        float effectInterval;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjAuraTrainParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjAuraTrainParameter* pInstance);
        static void Clean(ObjAuraTrainParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWaterFallRflParameter {
        float foretasteTime;
        float bigEffectStartCountTime;
        float modelFallBeforeSpeed;
        float modelFallAfterSpeed;
        float fallingSpeed;
        float modelHeight[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWaterFallRflParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWaterFallRflParameter* pInstance);
        static void Clean(ObjWaterFallRflParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBumperParameter {
        float lightColorR;
        float lightColorG;
        float lightColorB;
        float lightIntensity;
        float lightRadius;
        float lightAliveTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBumperParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBumperParameter* pInstance);
        static void Clean(ObjBumperParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjHexagonBumperParameter {
        float lightColorR;
        float lightColorG;
        float lightColorB;
        float lightIntensity;
        float lightRadius;
        float lightAliveTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjHexagonBumperParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjHexagonBumperParameter* pInstance);
        static void Clean(ObjHexagonBumperParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTriangleBumperParameter {
        float lightColorR;
        float lightColorG;
        float lightColorB;
        float lightIntensity;
        float lightRadius;
        float lightAliveTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTriangleBumperParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTriangleBumperParameter* pInstance);
        static void Clean(ObjTriangleBumperParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjVanishBumperParameter {
        float lightColorR;
        float lightColorG;
        float lightColorB;
        float lightIntensity;
        float lightRadius;
        float lightAliveTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjVanishBumperParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjVanishBumperParameter* pInstance);
        static void Clean(ObjVanishBumperParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GiantCrabDebrisData {
        bool sniper;
        bool left;
        bool center;
        bool right;
        float wait;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GiantCrabDebrisData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GiantCrabDebrisData* pInstance);
        static void Clean(GiantCrabDebrisData* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGiantCrabDebrisParameter {
        uint32_t debrisUseWaveNum;
        GiantCrabDebrisData debrisData[30];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGiantCrabDebrisParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGiantCrabDebrisParameter* pInstance);
        static void Clean(ObjGiantCrabDebrisParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGiantCrabParameter {
        bool enableDebris;
        float approachDistance;
        float playerStartDistance;
        float approachSpeedRatio;
        float chaceSpeedRatio;
        float homingWaitSpeedRatio;
        float homingWaitTime;
        float endSpeedRatio;
        float debrisImpactTime;
        float debrisHeight;
        float debrisRotateSpeed;
        float debrisRotateSpeedMin;
        float debrisRotateSpeed2;
        float debrisRotateSpeed3;
        float damageSpeed;
        float damageTime;
        uint32_t debrisMode1Num;
        float debrisMode1Interval;
        float waitMode1;
        uint32_t debrisMode2Num;
        float debrisMode2Interval;
        float waitMode2;
        float debrisMode3Interval;
        float breakFloorLength;
        float breakFloorHeight;
        float breakFloorAngle;
        float cameraShakeZRot;
        float cameraShakeTime;
        float cameraShakeMagn;
        uint32_t cameraShakeFreq;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGiantCrabParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGiantCrabParameter* pInstance);
        static void Clean(ObjGiantCrabParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBoxRoadParameter {
        enum class EaseType : int8_t {
            NONE = 0,
            EASE_IN = 1,
            EASE_OUT = 2,
            EASE_IN_OUT = 3,
        };

        uint32_t boxNumForward;
        uint32_t boxNumBehind;
        float addBoxRate;
        float decreaseBoxRate;
        EaseType easeType;
        uint32_t discreteNum;
        float curveCorrection;
        float maxHeight;
        float minHeight;
        float flatDistanceForward;
        float flatDistanceForwardRand;
        float flatDistanceBehind;
        float flatDistanceBehindRand;
        float scaleDistance;
        float fallDistance;
        uint32_t forwardBoxNumTable[20];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBoxRoadParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBoxRoadParameter* pInstance);
        static void Clean(ObjBoxRoadParameter* pInstance);
    };
}

namespace heur::rfl {
    struct PRCoreNormalDamageParameter {
        float homingDamage;
        float boostDamage;
        float spinDamage;
        float etcDamage;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PRCoreNormalDamageParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PRCoreNormalDamageParameter* pInstance);
        static void Clean(PRCoreNormalDamageParameter* pInstance);
    };
}

namespace heur::rfl {
    struct PRCoreGadgetDamageParameter {
        float asteroidDamage;
        float drillDamage;
        float cubeDamage;
        float lightningDamage;
        float burstDamage;
        float voidDamage;
        float hoverDamage;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PRCoreGadgetDamageParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PRCoreGadgetDamageParameter* pInstance);
        static void Clean(PRCoreGadgetDamageParameter* pInstance);
    };
}

namespace heur::rfl {
    struct PRLaserParameter {
        bool isUse;
        float phase;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PRLaserParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PRLaserParameter* pInstance);
        static void Clean(PRLaserParameter* pInstance);
    };
}

namespace heur::rfl {
    struct PRLaserWaveParameter {
        float rotationSpeed;
        float rotationSpeedChangeTime;
        float activeTime;
        float omenTime;
        float waitTime;
        float initWaitTime;
        PRLaserParameter laserData[8];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PRLaserWaveParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PRLaserWaveParameter* pInstance);
        static void Clean(PRLaserWaveParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPowerReactorParameter {
        uint32_t coreHp;
        PRCoreNormalDamageParameter coreNormalDamageParam;
        PRCoreGadgetDamageParameter coreGadgetDamageParam;
        PRLaserWaveParameter laserWaveParam[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPowerReactorParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPowerReactorParameter* pInstance);
        static void Clean(ObjPowerReactorParameter* pInstance);
    };
}

namespace heur::rfl {
    struct RadioData {
        enum class CharaType : int8_t {
            CHARATYPE_NONE = -1,
            CHARATYPE_AMY = 0,
            CHARATYPE_CHARMY = 1,
            CHARATYPE_EGGMAN = 2,
            CHARATYPE_ESPIO = 3,
            CHARATYPE_KNUCKLES = 4,
            CHARATYPE_ROUGE = 5,
            CHARATYPE_SHADOW = 6,
            CHARATYPE_SILVER = 7,
            CHARATYPE_SONIC = 8,
            CHARATYPE_TAILS = 9,
            CHARATYPE_VECTOR = 10,
            CHARATYPE_SOLDIER = 11,
            CHARATYPE_NETWORK_SOLDIER = 12,
            CHARATYPE_CAPTAIN = 13,
            CHARATYPE_BUDDY = 14,
            CHARATYPE_CLASSIC_SONIC = 15,
            CHARATYPE_INFINITE = 16,
            CHARATYPE_OMEGA = 17,
            CHARATYPE_NUM = 18,
        };

        enum class FaceType : int8_t {
            FACETYPE_ANGRY = 0,
            FACETYPE_BASE = 1,
            FACETYPE_SAD = 2,
            FACETYPE_SMILE = 3,
            FACETYPE_SURPRISE = 4,
            FACETYPE_ANGRY_IDLE = 5,
            FACETYPE_BASE_IDLE = 6,
            FACETYPE_SAD_IDLE = 7,
            FACETYPE_SMILE_IDLE = 8,
            FACETYPE_SURPRISE_IDLE = 9,
            FACETYPE_NUM = 10,
        };

        enum class TalkType : int8_t {
            TALKTYPE_FIRST = 0,
            TALKTYPE_SECOND = 1,
            TALKTYPE_NUM = 2,
        };

        CharaType charaType;
        FaceType faceType;
        CharaType charaTypeSecond;
        FaceType faceTypeSecond;
        TalkType talkType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(RadioData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(RadioData* pInstance);
        static void Clean(RadioData* pInstance);
    };
}

namespace heur::rfl {
    struct Data {
        enum class Type : int8_t {
            TYPE_CAPTION = 0,
            TYPE_RADIO = 1,
            TYPE_SOUND = 2,
            TYPE_TUTORIAL = 3,
        };

        Type type;
        csl::ut::VariableString labelId;
        float waitTime;
        RadioData radioData;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Data* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Data* pInstance);
        static void Clean(Data* pInstance);
    };
}

namespace heur::rfl {
    struct Discussion {
        Data datas[20];
        bool isForcePlay;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Discussion* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Discussion* pInstance);
        static void Clean(Discussion* pInstance);
    };
}

namespace heur::rfl {
    struct CaptionParameter {
        Discussion discussions[10];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CaptionParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CaptionParameter* pInstance);
        static void Clean(CaptionParameter* pInstance);
    };
}

namespace heur::rfl {
    struct DressUpPreset {
        bool available;
        uint8_t pad[3];
        CustomizeData customizeData;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DressUpPreset* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DressUpPreset* pInstance);
        static void Clean(DressUpPreset* pInstance);
    };
}

namespace heur::rfl {
    struct AllDressUpPresets {
        DressUpPreset presetCommon[128];
        DressUpPreset presetMen[128];
        DressUpPreset presetWomen[128];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AllDressUpPresets* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AllDressUpPresets* pInstance);
        static void Clean(AllDressUpPresets* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamWire {
        float shootSpeed;
        float speed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamWire* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamWire* pInstance);
        static void Clean(PlayerParamWire* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamWireBoost {
        float shootSpeed;
        float speed;
        float maxSpeed;
        float bounceForce;
        float deceleSideForce;
        float waitTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamWireBoost* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamWireBoost* pInstance);
        static void Clean(PlayerParamWireBoost* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamWeaponBurst {
        int32_t numRotate;
        float rotateTime;
        float beginAngle;
        float endAngle;
        float damageRate;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamWeaponBurst* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamWeaponBurst* pInstance);
        static void Clean(PlayerParamWeaponBurst* pInstance);
    };
}

namespace heur::rfl {
    struct BuddyModePackage {
        PlayerParamWire wire;
        PlayerParamWireBoost wireboost;
        PlayerParamWeaponBurst weaponburst;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BuddyModePackage* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BuddyModePackage* pInstance);
        static void Clean(BuddyModePackage* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamWireDrift {
        float acceleForce;
        float deceleForce;
        float innerSideForce;
        float outerSideForce;
        float maxSideForce;
        float thresholdSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamWireDrift* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamWireDrift* pInstance);
        static void Clean(PlayerParamWireDrift* pInstance);
    };
}

namespace heur::rfl {
    struct ReduceDamage {
        int32_t numRestRings;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ReduceDamage* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ReduceDamage* pInstance);
        static void Clean(ReduceDamage* pInstance);
    };
}

namespace heur::rfl {
    struct RingInvincible {
        int32_t numRings;
        float time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(RingInvincible* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(RingInvincible* pInstance);
        static void Clean(RingInvincible* pInstance);
    };
}

namespace heur::rfl {
    struct RingBonus {
        int32_t numRings;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(RingBonus* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(RingBonus* pInstance);
        static void Clean(RingBonus* pInstance);
    };
}

namespace heur::rfl {
    struct RingCollector {
        float radius;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(RingCollector* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(RingCollector* pInstance);
        static void Clean(RingCollector* pInstance);
    };
}

namespace heur::rfl {
    struct PowerRestart {
        int32_t numRings;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PowerRestart* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PowerRestart* pInstance);
        static void Clean(PowerRestart* pInstance);
    };
}

namespace heur::rfl {
    struct LandingDash {
        float speedSV;
        float speedFV;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(LandingDash* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(LandingDash* pInstance);
        static void Clean(LandingDash* pInstance);
    };
}

namespace heur::rfl {
    struct CancelDash {
        float speedSV;
        float speedFV;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CancelDash* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CancelDash* pInstance);
        static void Clean(CancelDash* pInstance);
    };
}

namespace heur::rfl {
    struct Skimmer {
        float rate;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Skimmer* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Skimmer* pInstance);
        static void Clean(Skimmer* pInstance);
    };
}

namespace heur::rfl {
    struct RingUp {
        int32_t numRings;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(RingUp* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(RingUp* pInstance);
        static void Clean(RingUp* pInstance);
    };
}

namespace heur::rfl {
    struct HTurbo {
        float speed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(HTurbo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(HTurbo* pInstance);
        static void Clean(HTurbo* pInstance);
    };
}

namespace heur::rfl {
    struct ChainRing {
        float time;
        int32_t rateRing;
        int32_t rateSuperRing;
        int32_t rateDroppedRing;
        int32_t rateDroppedRingDamage;
        int32_t rateRedRing;
        int32_t rateBlueRing;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ChainRing* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ChainRing* pInstance);
        static void Clean(ChainRing* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyCombo {
        float time;
        int32_t rate;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyCombo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyCombo* pInstance);
        static void Clean(EnemyCombo* pInstance);
    };
}

namespace heur::rfl {
    struct DamageInvincible {
        float time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DamageInvincible* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DamageInvincible* pInstance);
        static void Clean(DamageInvincible* pInstance);
    };
}

namespace heur::rfl {
    struct HStability {
        float time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(HStability* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(HStability* pInstance);
        static void Clean(HStability* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamGadgetSkill {
        ReduceDamage reduceDamage;
        RingInvincible ringInvicible;
        RingBonus ringBonus;
        RingCollector ringCollector;
        PowerRestart powerRestart;
        LandingDash landingDash;
        CancelDash cancelDash;
        Skimmer skimmer;
        RingUp ringUp;
        HTurbo hTurbo;
        ChainRing chainRing;
        EnemyCombo enemyCombo;
        DamageInvincible damageInvincible;
        HStability hStability;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamGadgetSkill* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamGadgetSkill* pInstance);
        static void Clean(PlayerParamGadgetSkill* pInstance);
    };
}

namespace heur::rfl {
    struct BuddyPackage {
        PlayerParamWireDrift wiredrift;
        PlayerParamGadgetSkill skill;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BuddyPackage* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BuddyPackage* pInstance);
        static void Clean(BuddyPackage* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamCommon {
        float noDamageTime;
        float damagedInitialSpeed;
        float upstandMaxSlope;
        float landingMaxSlope;
        float landingMaxSlopeOnMovable;
        float movableMaxSlope;
        float onewayFloorThroughSpeed;
        float projSpeedThreshold;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamCommon* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamCommon* pInstance);
        static void Clean(PlayerParamCommon* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamSpeed {
        float maxSpeed;
        float maxSpeedDash;
        float maxSpeedOver;
        float maxSpeedAir;
        float maxRotateSpeed;
        float minRotateSpeed;
        float acceleForce;
        float dashAcceleForce;
        float autorunAcceleForce;
        float deceleForceLow;
        float dashDeceleForce;
        float deceleForceHigh;
        bool enabledTurnSlow;
        bool enabledSpeedSlow;
        float turnSlowTime;
        float turnSlowAngle;
        float turnSlowRatio;
        float slowTime;
        float acceleSlowTime;
        float maxFallSpeed;
        float landingDecele;
        float limitLandingDecele;
        float overSpeedDamperAir;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSpeed* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSpeed* pInstance);
        static void Clean(PlayerParamSpeed* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamRotation {
        float pitchRollSpeedMinDiff;
        float pitchRollSpeedMaxDiff;
        float pitchRollSpeedAirRate;
        float pitchRollSpeed;
        float toFrontRotation;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamRotation* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamRotation* pInstance);
        static void Clean(PlayerParamRotation* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamRunning {
        float speedMinJog;
        float speedMinRun;
        float speedMinJet;
        float animSpeedRate;
        float animSpeedMinJog;
        float followDelayTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamRunning* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamRunning* pInstance);
        static void Clean(PlayerParamRunning* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamBrake {
        float enableSpeed;
        float initialSpeedRatio;
        float maxSpeed;
        float forceLand;
        float forceAir;
        float forceRun;
        float endSpeed;
        float stopTime;
        float turnInitialSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamBrake* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamBrake* pInstance);
        static void Clean(PlayerParamBrake* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamJump {
        float shortReleaseTime;
        float longPressTime;
        float addForceTime;
        float force;
        float addForce;
        float forceMin;
        float gravitySize;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamJump* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamJump* pInstance);
        static void Clean(PlayerParamJump* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamJumpSpeed {
        float acceleForce;
        float deceleForce;
        float brakeForce;
        float minSpeed;
        float limitMin;
        float limitMax;
        float limitUpSpeed;
        float airdragSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamJumpSpeed* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamJumpSpeed* pInstance);
        static void Clean(PlayerParamJumpSpeed* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamDoubleJump {
        float initialSpeed;
        float limitSpeedMin;
        float limitSpeedMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDoubleJump* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDoubleJump* pInstance);
        static void Clean(PlayerParamDoubleJump* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamSliding {
        float minSpeed;
        float deceleForce;
        float thresholdLowSpeed;
        float rotationForceLow;
        float rotationVelocityForce;
        float rotationForceHigh;
        float rotationForceAutoRun;
        float movableMaxSlope;
        float gravitySize;
        float minContinueTime;
        float deceleRatioAutoRun;
        float maxAutoRunTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSliding* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSliding* pInstance);
        static void Clean(PlayerParamSliding* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamStomping {
        float initialSpeed;
        float airDrag;
        float thresholdSpeedAirDrag;
        float landingCancelTime;
        float runInitialSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamStomping* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamStomping* pInstance);
        static void Clean(PlayerParamStomping* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamWallJump {
        float gravitySize;
        float minTime;
        float maxTime;
        float stopTime;
        float maxDownSpeed;
        float fallGroundDistance;
        float frontForce;
        float upForce;
        float impulseTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamWallJump* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamWallJump* pInstance);
        static void Clean(PlayerParamWallJump* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamGrind {
        float acceleForce;
        float deceleForce;
        float limitSpeedMin;
        float jumpSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamGrind* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamGrind* pInstance);
        static void Clean(PlayerParamGrind* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamFallSlope {
        float maxAcceleForce;
        float acceleForce;
        float maxSpeed;
        float brakeForce;
        float gravitySize;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamFallSlope* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamFallSlope* pInstance);
        static void Clean(PlayerParamFallSlope* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamSpinAttack {
        float jumpForce;
        float jumpAddForce;
        float addTime;
        float acceleForce;
        float deceleForce;
        float brakeForce;
        float limitSpeedMin;
        float limitSpeedMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSpinAttack* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSpinAttack* pInstance);
        static void Clean(PlayerParamSpinAttack* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamHomingAttack {
        float speed;
        float bounceVertSpeed;
        float bounceHorzSpeed;
        float powerCurveSonic;
        float powerCurve;
        float powerEdge;
        float powerQuick;
        float fallHomingEnableUpSpeed;
        float attackDownTime;
        float enableHomingTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamHomingAttack* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamHomingAttack* pInstance);
        static void Clean(PlayerParamHomingAttack* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamQuickStep {
        float acceleForce;
        float acceleSideForce;
        float stepInitialSpeed;
        float avoidForce;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamQuickStep* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamQuickStep* pInstance);
        static void Clean(PlayerParamQuickStep* pInstance);
    };
}

namespace heur::rfl {
    struct SpeedParam {
        float maxVertSpeed;
        float acceleVertForce;
        float maxHorzSpeed;
        float acceleHorzForce;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SpeedParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SpeedParam* pInstance);
        static void Clean(SpeedParam* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamDiving {
        SpeedParam normal;
        SpeedParam fast;
        SpeedParam damaged;
        float deceleVertForce;
        float deceleHorzForce;
        float deceleNeutralForce;
        float damageTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDiving* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDiving* pInstance);
        static void Clean(PlayerParamDiving* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamBallMove {
        float maxSpeed;
        float slidePower;
        float brakeForce;
        float slidePowerSlalom;
        float brakeForceSlalom;
        float releaseSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamBallMove* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamBallMove* pInstance);
        static void Clean(PlayerParamBallMove* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamPinBall {
        float acceleForce;
        float deceleForce;
        float gravityRate;
        float releaseSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamPinBall* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamPinBall* pInstance);
        static void Clean(PlayerParamPinBall* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamSpinDash {
        float maxDistance;
        float baseSpeed;
        float addSpeed;
        int32_t maxNumCharges;
        float acceleForce;
        float acceleSideForce;
        float deceleForce;
        float keepTime;
        float homingAngle;
        float homingDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSpinDash* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSpinDash* pInstance);
        static void Clean(PlayerParamSpinDash* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamFan {
        float danperV;
        float danperH;
        float accelRate;
        float moveForce;
        float jumpCheckSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamFan* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamFan* pInstance);
        static void Clean(PlayerParamFan* pInstance);
    };
}

namespace heur::rfl {
    struct CommonModePackage {
        PlayerParamCommon common;
        PlayerParamSpeed speed;
        PlayerParamRotation rotation;
        PlayerParamRunning running;
        PlayerParamBrake brake;
        PlayerParamJump jump;
        PlayerParamJumpSpeed jumpSpeed;
        PlayerParamDoubleJump doubleJump;
        PlayerParamSliding sliding;
        PlayerParamStomping stomping;
        PlayerParamWallJump walljump;
        PlayerParamGrind grind;
        PlayerParamFallSlope fallSlope;
        PlayerParamSpinAttack spinAttack;
        PlayerParamHomingAttack homingAttack;
        PlayerParamQuickStep quickstep;
        PlayerParamDiving diving;
        PlayerParamBallMove ballmove;
        PlayerParamPinBall pinball;
        PlayerParamSpinDash spindash;
        PlayerParamFan fan;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CommonModePackage* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CommonModePackage* pInstance);
        static void Clean(CommonModePackage* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamInput {
        float preInputTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamInput* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamInput* pInstance);
        static void Clean(PlayerParamInput* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamAutorun {
        float initialSideSpeed;
        float acceleSideForce;
        float deceleSideForce;
        float maxSideSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamAutorun* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamAutorun* pInstance);
        static void Clean(PlayerParamAutorun* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamSlider {
        float frontAccel;
        float frontBrake;
        float sideBrake;
        float damageBrake;
        float damageSpeedReduceRate;
        float defaultRotateSpeed;
        float rotateSpeed;
        float rotateSpeedAir;
        float gravity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSlider* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSlider* pInstance);
        static void Clean(PlayerParamSlider* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamSideStep {
        float speed;
        float stepSpeed;
        float maxStepDistance;
        float minStepDistance;
        float maxStepSpeed;
        float minStepSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSideStep* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSideStep* pInstance);
        static void Clean(PlayerParamSideStep* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamWaterAct {
        float resistRate;
        float breatheBrake;
        float breatheTime;
        float breatheGravity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamWaterAct* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamWaterAct* pInstance);
        static void Clean(PlayerParamWaterAct* pInstance);
    };
}

namespace heur::rfl {
    struct CommonPackage {
        PlayerParamInput input;
        PlayerParamAutorun autorun;
        PlayerParamSlider slider;
        PlayerParamSideStep sidestep;
        PlayerParamWaterAct wateract;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CommonPackage* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CommonPackage* pInstance);
        static void Clean(CommonPackage* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamDoubleBoost {
        float speed;
        float acceleForce;
        float acceleSideForce;
        float deceleSideForce;
        float maxSideSpeed;
        float jumpHeight;
        float jumpSpeed;
        float jumpTime;
        float jumpAcceleSideForce;
        float jumpDeceleSideForce;
        float jumpMaxSideSpeed;
        float spinTime;
        int32_t numSpin;
        float decreaseRate;
        float decreaseRateDamage;
        float increaseRateRing;
        float increaseRateRingWeak;
        float damageTime;
        float inletRadius;
        float weakSpeedRatio;
        float slowRate;
        float inputRangeBegin;
        float inputSuccessBegin;
        float inputSuccessEnd;
        float failedStumbleTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDoubleBoost* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDoubleBoost* pInstance);
        static void Clean(PlayerParamDoubleBoost* pInstance);
    };
}

namespace heur::rfl {
    struct CommonParameterPackage {
        PlayerParamAutorun autorun;
        PlayerParamDoubleBoost doubleboost;
        PlayerParamSlider slider;
        PlayerParamWireDrift wiredrift;
        PlayerParamWaterAct wateract;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CommonParameterPackage* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CommonParameterPackage* pInstance);
        static void Clean(CommonParameterPackage* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetAsteroidFV {
        float radius;
        float height;
        float rotateSpeed;
        float shotSpeed;
        float shotMoveTime;
        float shotReloadTime;
        float shotReloadRadius;
        float inletRadius;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetAsteroidFV* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetAsteroidFV* pInstance);
        static void Clean(GadgetAsteroidFV* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetAsteroidSV {
        float radius;
        float height;
        float rotateSpeed;
        float shotSpeed;
        float shotMoveTime;
        float shotReloadTime;
        float shotReloadRadius;
        float inletRadius;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetAsteroidSV* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetAsteroidSV* pInstance);
        static void Clean(GadgetAsteroidSV* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetBaseParameter {
        float activeTime;
        float decreaseTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetBaseParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetBaseParameter* pInstance);
        static void Clean(GadgetBaseParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetAsteroidParameter : GadgetBaseParameter {
        float maxFallSpeed;
        float hoverTime;
        float shotSpeedToBoss;
        float stopTraceSpeed;
        float stopTraceTime;
        GadgetAsteroidFV fv;
        GadgetAsteroidSV sv;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetAsteroidParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetAsteroidParameter* pInstance);
        static void Clean(GadgetAsteroidParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetBurstNormal {
        float continueTime;
        float speedFV;
        float distanceFV;
        float intervalFV;
        float speedSV;
        float distanceSV;
        float intervalSV;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetBurstNormal* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetBurstNormal* pInstance);
        static void Clean(GadgetBurstNormal* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetBurstSpecial {
        float decreaseTime;
        float outOfControlTime;
        float thresholdInput;
        float initialSpeedFV;
        float launchAngleFV;
        float initialSpeedSV;
        float launchAngleSV;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetBurstSpecial* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetBurstSpecial* pInstance);
        static void Clean(GadgetBurstSpecial* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetBurstParameter : GadgetBaseParameter {
        GadgetBurstNormal normal;
        GadgetBurstSpecial special;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetBurstParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetBurstParameter* pInstance);
        static void Clean(GadgetBurstParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetCommonParameter {
        int32_t startType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetCommonParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetCommonParameter* pInstance);
        static void Clean(GadgetCommonParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetCubeAir {
        float airDamageRadiusFV;
        float airDamageRadiusSV;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetCubeAir* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetCubeAir* pInstance);
        static void Clean(GadgetCubeAir* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetCubeNormal {
        float decreaseTime;
        float startBurstRadiusFV;
        float startBurstRadiusSV;
        float maxBurstRadiusFV;
        float maxBurstRadiusSV;
        float burstSpeedFV;
        float burstSpeedSV;
        float motionSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetCubeNormal* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetCubeNormal* pInstance);
        static void Clean(GadgetCubeNormal* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetCubeSpecial {
        float decreaseTime;
        float createCubeSizeFV;
        float createCubeSizeSV;
        float createCubeLimitFV;
        float createCubeLimitSV;
        float spAttackFlameFV;
        float spAttackFlameSV;
        float spChargeFlame1FV;
        float spChargeFlame1SV;
        float spChargeFlame2FV;
        float spChargeFlame2SV;
        int32_t spCubeNum0FV;
        int32_t spCubeNum0SV;
        int32_t spCubeNum1FV;
        int32_t spCubeNum1SV;
        int32_t spCubeNum2FV;
        int32_t spCubeNum2SV;
        float motionSpeed;
        float cameraInSpeed;
        float cameraOutSpeed;
        float cameraStartWait;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetCubeSpecial* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetCubeSpecial* pInstance);
        static void Clean(GadgetCubeSpecial* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetCubeParameter : GadgetBaseParameter {
        float attackDamageRadiusFV;
        float attackDamageRadiusSV;
        GadgetCubeNormal normal;
        GadgetCubeSpecial special;
        GadgetCubeAir air;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetCubeParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetCubeParameter* pInstance);
        static void Clean(GadgetCubeParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetDrillBoostFV {
        float speed;
        float accel;
        float brake;
        float startBrake;
        float startDanperBrakeRate;
        float wallSpeed;
        float wallAccel;
        float wallBrake;
        float edgeMoveTime;
        float rotateSpeed;
        float jumpSpeed;
        float hitCollisionRadius;
        float hitCollisionOffsetX;
        float hitCollisionOffsetY;
        float hitCollisionOffsetZ;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetDrillBoostFV* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetDrillBoostFV* pInstance);
        static void Clean(GadgetDrillBoostFV* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetDrillBoostSV {
        float speed;
        float accel;
        float brake;
        float startBrake;
        float startDanperBrakeRate;
        float wallSpeed;
        float wallAccel;
        float wallBrake;
        float edgeMoveTime;
        float jumpSpeed;
        float hitCollisionRadius;
        float hitCollisionOffsetX;
        float hitCollisionOffsetY;
        float hitCollisionOffsetZ;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetDrillBoostSV* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetDrillBoostSV* pInstance);
        static void Clean(GadgetDrillBoostSV* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetDrillDash {
        float chargeKeepTime;
        float shiftDownTime;
        float dashHoldTime;
        bool enableChargeInvincible;
        bool enableChargeAttack;
        bool enableDashInvincible;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetDrillDash* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetDrillDash* pInstance);
        static void Clean(GadgetDrillDash* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetDrillDashFV {
        float speed1;
        float speed2;
        float speed3;
        float speed4;
        float endSpeed1;
        float endSpeed2;
        float endSpeed3;
        float endSpeed4;
        float brake;
        float keepSpeedTime1;
        float keepSpeedTime2;
        float keepSpeedTime3;
        float keepSpeedTime4;
        float gravity;
        float noGravityTime;
        float chargeRotateSpeed;
        float rotateSpeed;
        float hitCollisionRadius1;
        float hitCollisionRadius2;
        float hitCollisionRadius3;
        float hitCollisionRadius4;
        float hitCollisionHeight1;
        float hitCollisionHeight2;
        float hitCollisionHeight3;
        float hitCollisionHeight4;
        float hitCollisionOffset1_X;
        float hitCollisionOffset1_Y;
        float hitCollisionOffset1_Z;
        float hitCollisionOffset2_X;
        float hitCollisionOffset2_Y;
        float hitCollisionOffset2_Z;
        float hitCollisionOffset3_X;
        float hitCollisionOffset3_Y;
        float hitCollisionOffset3_Z;
        float hitCollisionOffset4_X;
        float hitCollisionOffset4_Y;
        float hitCollisionOffset4_Z;
        float mapHitOffset1;
        float mapHitOffset2;
        float mapHitOffset3;
        float mapHitOffset4;
        float chargeBrake;
        float chargeDanperBrakeRate;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetDrillDashFV* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetDrillDashFV* pInstance);
        static void Clean(GadgetDrillDashFV* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetDrillDashSV {
        float speed1;
        float speed2;
        float speed3;
        float speed4;
        float endSpeed1;
        float endSpeed2;
        float endSpeed3;
        float endSpeed4;
        float brake;
        float keepSpeedTime1;
        float keepSpeedTime2;
        float keepSpeedTime3;
        float keepSpeedTime4;
        float gravity;
        float noGravityTime;
        float hitCollisionRadius1;
        float hitCollisionRadius2;
        float hitCollisionRadius3;
        float hitCollisionRadius4;
        float hitCollisionHeight1;
        float hitCollisionHeight2;
        float hitCollisionHeight3;
        float hitCollisionHeight4;
        float hitCollisionOffset1_X;
        float hitCollisionOffset1_Y;
        float hitCollisionOffset1_Z;
        float hitCollisionOffset2_X;
        float hitCollisionOffset2_Y;
        float hitCollisionOffset2_Z;
        float hitCollisionOffset3_X;
        float hitCollisionOffset3_Y;
        float hitCollisionOffset3_Z;
        float hitCollisionOffset4_X;
        float hitCollisionOffset4_Y;
        float hitCollisionOffset4_Z;
        float mapHitOffset1;
        float mapHitOffset2;
        float mapHitOffset3;
        float mapHitOffset4;
        float chargeBrake;
        float chargeDanperBrakeRate;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetDrillDashSV* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetDrillDashSV* pInstance);
        static void Clean(GadgetDrillDashSV* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetDrillParameter : GadgetBaseParameter {
        GadgetDrillDash dash;
        GadgetDrillDashFV dashFV;
        GadgetDrillDashSV dashSV;
        GadgetDrillBoostFV boostFV;
        GadgetDrillBoostSV boostSV;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetDrillParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetDrillParameter* pInstance);
        static void Clean(GadgetDrillParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetFloatingBaseParameter {
        float gravitySizeFV;
        float absoluteTimeFV;
        float addUpForceFV;
        float maxUpSpeedFV;
        float minUpSpeedFV;
        float maxSpeedFV;
        float acceleForceFV;
        float deceleForceFV;
        float maxDistansFV;
        float gravitySizeSV;
        float absoluteTimeSV;
        float addUpForceSV;
        float maxUpSpeedSV;
        float minUpSpeedSV;
        float maxSpeedSV;
        float acceleForceSV;
        float deceleForceSV;
        float maxDistansSV;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetFloatingBaseParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetFloatingBaseParameter* pInstance);
        static void Clean(GadgetFloatingBaseParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetHoverAttackFV {
        float radius;
        float offsetHeight;
        float bulletSpeed;
        float activeTime;
        float enemyBulletSpeed;
        float bulletCollisionOffsetY;
        float bulletActiveTime;
        float targetSearchDistance;
        float searchRengeAngle;
        float searchInterval;
        float interpolationTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetHoverAttackFV* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetHoverAttackFV* pInstance);
        static void Clean(GadgetHoverAttackFV* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetHoverAttackSV {
        float radius;
        float offsetHeight;
        float bulletSpeed;
        float activeTime;
        float enemyBulletSpeed;
        float bulletCollisionOffsetY;
        float bulletActiveTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetHoverAttackSV* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetHoverAttackSV* pInstance);
        static void Clean(GadgetHoverAttackSV* pInstance);
    };
}

namespace heur::rfl {
    struct GagetHoverJump : GadgetFloatingBaseParameter {
        float initialSpeedFV;
        float floatingTimeFV;
        float launchAngleFV;
        float initialSpeedSV;
        float floatingTimeSV;
        float launchAngleSV;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GagetHoverJump* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GagetHoverJump* pInstance);
        static void Clean(GagetHoverJump* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetHoverRescue {
        float initialSpeed;
        float acceleForce;
        float maxSpeed;
        float jumpOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetHoverRescue* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetHoverRescue* pInstance);
        static void Clean(GadgetHoverRescue* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetHoverParameter : GadgetBaseParameter {
        float attackDecreaseTime;
        float shootingInterval;
        float firstJumpDecreaseTime;
        float jumpDecreaseTime;
        GadgetHoverAttackFV attackFV;
        GadgetHoverAttackSV attackSV;
        GagetHoverJump jump;
        GadgetHoverRescue rescue;
        GagetHoverJump rescueJump;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetHoverParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetHoverParameter* pInstance);
        static void Clean(GadgetHoverParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetLightningCharge {
        float decreaseTime;
        float chargeTime;
        float searchRadiusFV;
        float searchRadiusSV;
        float searchRadPlayerFV;
        float searchRadPlayerSV;
        float searchRadiusEnemyFV;
        float searchRadiusEnemySV;
        float searchRadiusItemFV;
        float searchRadiusItemSV;
        float electroSpeed;
        float moveSpeedFV;
        float moveSpeedSV;
        float launchSpeedFV;
        float launchSpeedSV;
        float launchTimeFV;
        float launchTimeSV;
        float adjustDistanceFV;
        float adjustDistanceSV;
        float chainAngleEnemyFV;
        float chainAngleEnemySV;
        float chainAngleFV;
        float chainAngleSV;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetLightningCharge* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetLightningCharge* pInstance);
        static void Clean(GadgetLightningCharge* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetLightningNormal {
        float decreaseTime;
        float moveTimeFV;
        float moveTimeSV;
        float initialSpeedFV;
        float initialSpeedSV;
        int32_t maxChains;
        int32_t maxChainsAir;
        float motionSpeedRatio;
        float edgeStopTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetLightningNormal* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetLightningNormal* pInstance);
        static void Clean(GadgetLightningNormal* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetLightningParameter : GadgetBaseParameter {
        GadgetLightningNormal normal;
        GadgetLightningCharge charge;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetLightningParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetLightningParameter* pInstance);
        static void Clean(GadgetLightningParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetVoidNormal {
        float decreaseTime;
        float ballRadiusFV;
        float ballRadiusSV;
        float ballRadSpeedFV;
        float ballRadSpeedSV;
        float gravityRadiusFV;
        float gravityRadiusSV;
        float gravityRadSpeedFV;
        float gravityRadSpeedSV;
        float moveSpeedFV;
        float moveSpeedSV;
        float activeTimeFV;
        float activeTimeSV;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetVoidNormal* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetVoidNormal* pInstance);
        static void Clean(GadgetVoidNormal* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetVoidSpecial {
        float decreaseTime;
        float moveLengthFV;
        float moveLengthSV;
        float moveLengthUpFV;
        float moveLengthUpSV;
        float moveTimeFV;
        float moveTimeSV;
        float moveAttackRadFV;
        float moveAttackRadSV;
        float lastAttackRadFV;
        float lastAttackRadSV;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetVoidSpecial* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetVoidSpecial* pInstance);
        static void Clean(GadgetVoidSpecial* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetVoidRescueFloat : GadgetFloatingBaseParameter {
        float activeTimeFV;
        float activeTimeSV;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetVoidRescueFloat* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetVoidRescueFloat* pInstance);
        static void Clean(GadgetVoidRescueFloat* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetVoidParameter : GadgetBaseParameter {
        GadgetVoidNormal normal;
        GadgetVoidSpecial special;
        GadgetVoidRescueFloat floating;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetVoidParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetVoidParameter* pInstance);
        static void Clean(GadgetVoidParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GadgetParameters {
        GadgetCommonParameter common;
        GadgetBurstParameter burst;
        GadgetLightningParameter lightning;
        GadgetCubeParameter cube;
        GadgetDrillParameter drill;
        GadgetAsteroidParameter asteroid;
        GadgetHoverParameter hover;
        GadgetVoidParameter gadget_void;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GadgetParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GadgetParameters* pInstance);
        static void Clean(GadgetParameters* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamWallRun {
        float speed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamWallRun* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamWallRun* pInstance);
        static void Clean(PlayerParamWallRun* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamClimbWall {
        float hangApproachSpeed;
        float hangApproachMinTime;
        float speed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamClimbWall* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamClimbWall* pInstance);
        static void Clean(PlayerParamClimbWall* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamCancelStep {
        float initialFrontSpeed;
        float initialUpSpeed;
        float initialDashSpeed;
        float initialDashBrake;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamCancelStep* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamCancelStep* pInstance);
        static void Clean(PlayerParamCancelStep* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamBoost {
        float decreaseFirst;
        float decreaseRate;
        float initialSpeed;
        float maxSpeed;
        float maxSpeedAir;
        float acceleForce;
        float acceleSideForce;
        float rotationForce;
        float maxUpAngle;
        float time;
        float continueTime;
        float cancelSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamBoost* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamBoost* pInstance);
        static void Clean(PlayerParamBoost* pInstance);
    };
}

namespace heur::rfl {
    struct ParameterPackage {
        PlayerParamCommon common;
        PlayerParamSpeed speed;
        PlayerParamRotation rotation;
        PlayerParamRunning running;
        PlayerParamBrake brake;
        PlayerParamJump jump;
        PlayerParamJumpSpeed jumpSpeed;
        PlayerParamDoubleJump doubleJump;
        PlayerParamSliding sliding;
        PlayerParamStomping stomping;
        PlayerParamWallJump walljump;
        PlayerParamGrind grind;
        PlayerParamFallSlope fallSlope;
        PlayerParamWallRun wallRun;
        PlayerParamClimbWall climbWall;
        PlayerParamCancelStep cancelStep;
        PlayerParamSpinAttack spinAttack;
        PlayerParamHomingAttack homingAttack;
        PlayerParamBoost boost;
        PlayerParamQuickStep quickstep;
        PlayerParamDiving diving;
        PlayerParamWire wire;
        PlayerParamWireBoost wireboost;
        PlayerParamWeaponBurst weaponburst;
        PlayerParamBallMove ballmove;
        PlayerParamPinBall pinball;
        PlayerParamSpinDash spindash;
        PlayerParamFan fan;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ParameterPackage* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ParameterPackage* pInstance);
        static void Clean(ParameterPackage* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerBuddyParameters {
        BuddyPackage common;
        BuddyModePackage forwardView;
        BuddyModePackage sideView;
        BuddyModePackage forwardViewWater;
        BuddyModePackage sideViewWater;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerBuddyParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerBuddyParameters* pInstance);
        static void Clean(PlayerBuddyParameters* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerCommonParameters {
        CommonPackage common;
        CommonModePackage forwardView;
        CommonModePackage sideView;
        CommonModePackage forwardViewWater;
        CommonModePackage sideViewWater;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerCommonParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerCommonParameters* pInstance);
        static void Clean(PlayerCommonParameters* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParameters {
        CommonParameterPackage common;
        ParameterPackage forwardView;
        ParameterPackage sideView;
        ParameterPackage forwardViewWater;
        ParameterPackage sideViewWater;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParameters* pInstance);
        static void Clean(PlayerParameters* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerParamSuperSonic {
        float speedRatio;
        float speedRatioBoost;
        int32_t numRings;
        float decreaseSec;
        float inletRadius;
        float moveSoundSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSuperSonic* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSuperSonic* pInstance);
        static void Clean(PlayerParamSuperSonic* pInstance);
    };
}

namespace heur::rfl {
    struct SonicClassicPackage {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SonicClassicPackage* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SonicClassicPackage* pInstance);
        static void Clean(SonicClassicPackage* pInstance);
    };
}

namespace heur::rfl {
    struct SonicClassicParamBase {
        float brakeForce;
        float startForce;
        float stopSpeed;
        float brake;
        float slipBrakeForce;
        float slipBrake;
        float slipSpeed;
        float slipTime;
        float standableSlopeAngle;
        float maxSpeedUpRate;
        float accelUpRate;
        float brakeUpRate;
        float walkSpeed;
        float stumbleSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SonicClassicParamBase* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SonicClassicParamBase* pInstance);
        static void Clean(SonicClassicParamBase* pInstance);
    };
}

namespace heur::rfl {
    struct SonicClassicParamBrake {
        float maxLowBrakeSpeed;
        float initialSpeedRatio;
        float maxSpeed;
        float forceBrake;
        float forceTurn;
        float endSpeed;
        float maxTurnSpeed;
        float turnSpeed;
        float turnStartFrame;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SonicClassicParamBrake* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SonicClassicParamBrake* pInstance);
        static void Clean(SonicClassicParamBrake* pInstance);
    };
}

namespace heur::rfl {
    struct SonicClassicParamSpinDash {
        float chargeTime0;
        float chargeTime1;
        float chargeTime2;
        float dashSpeed0;
        float dashSpeed1;
        float dashSpeed2;
        float dashSpeedWater;
        float maxSpeedAir;
        float brake;
        float chargeBrake;
        float chargeDamperBrakeRate;
        float checkGroundDist;
        float minChangeSpeed;
        float maxRunningSpeed;
        float dropChargeTime0;
        float dropChargeTime1;
        float dropChargeTime2;
        float dropDashSpeed0;
        float dropDashSpeed1;
        float dropDashSpeed2;
        float dropDashSpeedWater;
        float controlSpeed;
        float airAccel;
        float maxControlSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SonicClassicParamSpinDash* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SonicClassicParamSpinDash* pInstance);
        static void Clean(SonicClassicParamSpinDash* pInstance);
    };
}

namespace heur::rfl {
    struct SonicClassicParamPinBall {
        float maxSpeedAir;
        float brake;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SonicClassicParamPinBall* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SonicClassicParamPinBall* pInstance);
        static void Clean(SonicClassicParamPinBall* pInstance);
    };
}

namespace heur::rfl {
    struct SonicClassicParamBarrier {
        float effectOffsetNormal_X;
        float effectOffsetNormal_Y;
        float effectOffsetNormal_Z;
        float effectOffsetBall_X;
        float effectOffsetBall_Y;
        float effectOffsetBall_Z;
        float effectOffsetSleep_X;
        float effectOffsetSleep_Y;
        float effectOffsetSleep_Z;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SonicClassicParamBarrier* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SonicClassicParamBarrier* pInstance);
        static void Clean(SonicClassicParamBarrier* pInstance);
    };
}

namespace heur::rfl {
    struct SonicClassicModePackage {
        SonicClassicParamBase base;
        SonicClassicParamBrake brake;
        SonicClassicParamSpinDash spindash;
        SonicClassicParamPinBall pinball;
        SonicClassicParamBarrier barrier;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SonicClassicModePackage* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SonicClassicModePackage* pInstance);
        static void Clean(SonicClassicModePackage* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerSonicClassicParameters {
        SonicClassicPackage common;
        SonicClassicModePackage forwardView;
        SonicClassicModePackage sideView;
        SonicClassicModePackage forwardViewWater;
        SonicClassicModePackage sideViewWater;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerSonicClassicParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerSonicClassicParameters* pInstance);
        static void Clean(PlayerSonicClassicParameters* pInstance);
    };
}

namespace heur::rfl {
    struct SonicPackage {
        PlayerParamDoubleBoost doubleboost;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SonicPackage* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SonicPackage* pInstance);
        static void Clean(SonicPackage* pInstance);
    };
}

namespace heur::rfl {
    struct SonicModePackage {
        PlayerParamBoost boost;
        PlayerParamWallRun wallRun;
        PlayerParamClimbWall climbWall;
        PlayerParamCancelStep cancelStep;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SonicModePackage* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SonicModePackage* pInstance);
        static void Clean(SonicModePackage* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerSonicParameters {
        SonicPackage common;
        SonicModePackage forwardView;
        SonicModePackage sideView;
        SonicModePackage forwardViewWater;
        SonicModePackage sideViewWater;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerSonicParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerSonicParameters* pInstance);
        static void Clean(PlayerSonicParameters* pInstance);
    };
}

namespace heur::rfl {
    struct SuperSonicPackage {
        PlayerParamSuperSonic superSonic;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SuperSonicPackage* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SuperSonicPackage* pInstance);
        static void Clean(SuperSonicPackage* pInstance);
    };
}

namespace heur::rfl {
    struct PlayerSuperSonicParameters {
        SuperSonicPackage common;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerSuperSonicParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerSuperSonicParameters* pInstance);
        static void Clean(PlayerSuperSonicParameters* pInstance);
    };
}

namespace heur::rfl {
    struct CapsuleParam {
        enum class NodeType : int8_t {
            Head = 0,
            Hips = 1,
            UpperArm_L = 2,
            UpperArm_R = 3,
            ForeArm_L = 4,
            ForeArm_R = 5,
            Hand_L = 6,
            Hand_R = 7,
            Thigh_L = 8,
            Thigh_R = 9,
            Calf_L = 10,
            Calf_R = 11,
            Foot_L = 12,
            Foot_R = 13,
            Spin = 14,
            NumNodes = 15,
            None = 16,
        };

        enum class LODLevel : int8_t {
            LOD_HIGH = 0,
            LOD_MIDDLE = 1,
            LOD_LOW = 2,
        };

        NodeType type;
        csl::math::Vector3 translation;
        csl::math::Vector3 rotation;
        csl::math::Vector3 scale;
        LODLevel lod;
        bool enabledAmbientOcclusion;
        bool enabledShadow;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CapsuleParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CapsuleParam* pInstance);
        static void Clean(CapsuleParam* pInstance);
    };
}

namespace heur::rfl {
    struct OcclusionCapsuleParameter {
        CapsuleParam capsules[16];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(OcclusionCapsuleParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(OcclusionCapsuleParameter* pInstance);
        static void Clean(OcclusionCapsuleParameter* pInstance);
    };
}

namespace heur::rfl {
    struct SosParameter {
        uint32_t generateMinute;
        uint32_t fluctuation;
        bool isTimeCountMainMenu;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SosParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SosParameter* pInstance);
        static void Clean(SosParameter* pInstance);
    };
}

namespace heur::rfl {
    struct BGMTransitionInfo {
        float fadeOutTime;
        float playDelayTime;
        float fadeInTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BGMTransitionInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BGMTransitionInfo* pInstance);
        static void Clean(BGMTransitionInfo* pInstance);
    };
}

namespace heur::rfl {
    struct EventBGMInfo {
        BGMTransitionInfo begin;
        BGMTransitionInfo end;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EventBGMInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EventBGMInfo* pInstance);
        static void Clean(EventBGMInfo* pInstance);
    };
}

namespace heur::rfl {
    struct StageSoundParameter {
        BGMTransitionInfo pauseMenuIn;
        BGMTransitionInfo pauseMenuOut;
        BGMTransitionInfo stageClear;
        BGMTransitionInfo resultEnd;
        BGMTransitionInfo boostBegin;
        BGMTransitionInfo boostEnd;
        BGMTransitionInfo doubleBoostBegin;
        BGMTransitionInfo doubleBoostEnd;
        BGMTransitionInfo speedUp;
        BGMTransitionInfo invincibleBegin;
        BGMTransitionInfo invincibleEnd;
        BGMTransitionInfo drownBegin;
        BGMTransitionInfo drownEnd;
        EventBGMInfo qte[4];
        EventBGMInfo midboss[2];
        float waterDepthBottom;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageSoundParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageSoundParameter* pInstance);
        static void Clean(StageSoundParameter* pInstance);
    };
}

namespace heur::rfl {
    struct QTEParameter {
        enum class InterpolateType : int8_t {
            LINEAR = 0,
            CUBIC_EASEIN = 1,
            CUBIC_EASEOUT = 2,
        };

        float qteTimeSpan;
        float firstLine;
        float successLine;
        float minLine;
        float decreasePerInput;
        float minDecreasePerInput;
        float goBackSpeed;
        float allowNoInputTime;
        float inputInnerMinSpeed;
        float inputInnerMaxSpeed;
        InterpolateType innerInterpolate;
        float noinputOuterMinAccele;
        float noinputOuterMaxAccele;
        InterpolateType outerInterpolate;
        float innerSpeedMax;
        float outerSpeedMax;
        float safetime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(QTEParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(QTEParameter* pInstance);
        static void Clean(QTEParameter* pInstance);
    };
}

namespace heur::rfl {
    struct UIGameCockpitParameter {
        QTEParameter doubleBoostQte;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(UIGameCockpitParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(UIGameCockpitParameter* pInstance);
        static void Clean(UIGameCockpitParameter* pInstance);
    };
}

namespace heur::rfl {
    struct CharaMakeParameter {
        float cameraMinDistance;
        float cameraMaxDistance;
        float cameraDollySpeed;
        float cameraRotationSpeed;
        float cameraDollyThreshold;
        float cameraRotationThreshold;
        float cameraPositionInterpolateRate;
        csl::math::Vector3 lightDir;
        csl::math::Vector3 lightColor;
        float lightFieldValue;
        csl::math::Vector3 defaultCameraPosition;
        csl::math::Vector3 defaultCameraTarget;
        csl::math::Vector3 regionCameraPositions[5];
        csl::math::Vector3 regionCameraTargets[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CharaMakeParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CharaMakeParameter* pInstance);
        static void Clean(CharaMakeParameter* pInstance);
    };
}

namespace heur::rfl {
    struct MyBuddyCameraParam {
        csl::math::Vector3 position;
        csl::math::Vector3 target;
        float roll;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MyBuddyCameraParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MyBuddyCameraParam* pInstance);
        static void Clean(MyBuddyCameraParam* pInstance);
    };
}

namespace heur::rfl {
    struct DiscussData {
        csl::ut::VariableString memo;
        csl::ut::VariableString openingId;
        csl::ut::VariableString clearedId;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DiscussData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DiscussData* pInstance);
        static void Clean(DiscussData* pInstance);
    };
}

namespace heur::rfl {
    struct CameraData {
        float cameraPosX;
        float cameraPosY;
        float cameraPosZ;
        float targetPosX;
        float targetPosY;
        float targetPosZ;
        float fovY;
        float betweenRatio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CameraData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CameraData* pInstance);
        static void Clean(CameraData* pInstance);
    };
}

namespace heur::rfl {
    struct CameraTargetData {
        float x;
        float y;
        float z;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CameraTargetData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CameraTargetData* pInstance);
        static void Clean(CameraTargetData* pInstance);
    };
}

namespace heur::rfl {
    struct LightParam {
        float lightDirX;
        float lightDirY;
        float lightDirZ;
        float lightColorR;
        float lightColorG;
        float lightColorB;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(LightParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(LightParam* pInstance);
        static void Clean(LightParam* pInstance);
    };
}

namespace heur::rfl {
    struct MiscData {
        float prisonRotateRatio;
        float toDeathEggScreenPosX;
        float toDeathEggScreenPosY;
        float toEarthScreenPosX;
        float toEarthScreenPosY;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MiscData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MiscData* pInstance);
        static void Clean(MiscData* pInstance);
    };
}

namespace heur::rfl {
    struct PositionParam {
        float posX;
        float posY;
        float posZ;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PositionParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PositionParam* pInstance);
        static void Clean(PositionParam* pInstance);
    };
}

namespace heur::rfl {
    struct PlanetCursorParam {
        float ratioX;
        float ratioY;
        float rotateSpeed;
        float cursorSpeedOutSide;
        float absorbDistance;
        float absorbSpeed;
        float absorbSpeedOutSide;
        PositionParam minCursorPos;
        PositionParam maxCursorPos;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlanetCursorParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlanetCursorParam* pInstance);
        static void Clean(PlanetCursorParam* pInstance);
    };
}

namespace heur::rfl {
    struct PlanetRotateParam {
        float m_rotateXMin;
        float m_rotateXMax;
        float m_rotateYMin;
        float m_rotateYMax;
        float m_builtInRotateX;
        float m_builtInRotateY;
        float m_builtInRotateZ;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlanetRotateParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlanetRotateParam* pInstance);
        static void Clean(PlanetRotateParam* pInstance);
    };
}

namespace heur::rfl {
    struct WorldMapCameraParameter {
        PositionParam m_earthPos;
        CameraData m_earthCameraParam;
        PositionParam m_deathEggPos;
        CameraData m_deathEggCameraParam;
        PositionParam m_prisonPos;
        CameraTargetData m_prisonCameraTarget;
        PlanetRotateParam m_EarthRotateParam;
        PlanetRotateParam m_DeathEggRotateParam;
        LightParam m_lightParam;
        PlanetCursorParam m_cursorEarth;
        PlanetCursorParam m_cursorDeathEgg;
        MiscData m_miscData;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WorldMapCameraParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WorldMapCameraParameter* pInstance);
        static void Clean(WorldMapCameraParameter* pInstance);
    };
}

namespace heur::rfl {
    struct StageDetailBuddyCameraParameter {
        MyBuddyCameraParam mainCamera;
        MyBuddyCameraParam halfToneCamera;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageDetailBuddyCameraParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageDetailBuddyCameraParameter* pInstance);
        static void Clean(StageDetailBuddyCameraParameter* pInstance);
    };
}

namespace heur::rfl {
    struct StageDetailSosEvent {
        float effectTime;
        float addValue1;
        float addValue2;
        uint8_t numEffects;
        uint8_t pad2[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageDetailSosEvent* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageDetailSosEvent* pInstance);
        static void Clean(StageDetailSosEvent* pInstance);
    };
}

namespace heur::rfl {
    struct StageDetailParameter {
        bool skipTransceiverEffectWhenFriendExists;
        uint8_t pad[3];
        float friendBuddyEffectTime;
        StageDetailSosEvent sosEvent;
        StageDetailBuddyCameraParameter buddyCamera[2];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageDetailParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageDetailParameter* pInstance);
        static void Clean(StageDetailParameter* pInstance);
    };
}

namespace heur::rfl {
    struct WorldMapDiscussParameter {
        DiscussData discussDatas[50];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WorldMapDiscussParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WorldMapDiscussParameter* pInstance);
        static void Clean(WorldMapDiscussParameter* pInstance);
    };
}

namespace heur::rfl {
    struct WorldMapTutorialParameter {
        float naviButtonScale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WorldMapTutorialParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WorldMapTutorialParameter* pInstance);
        static void Clean(WorldMapTutorialParameter* pInstance);
    };
}

namespace heur::rfl {
    struct UIRadioParameter {
        float cameraPosX;
        float cameraPosY;
        float cameraPosZ;
        float targetPosX;
        float targetPosY;
        float targetPosZ;
        float fovY;
        float lightDirX;
        float lightDirY;
        float lightDirZ;
        float lightColorR;
        float lightColorG;
        float lightColorB;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(UIRadioParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(UIRadioParameter* pInstance);
        static void Clean(UIRadioParameter* pInstance);
    };
}

namespace heur::rfl {
    struct UIResultSingleModelPosition {
        csl::math::Vector3 cameraPosition;
        csl::math::Vector3 cameraTarget;
        csl::math::Vector3 modelPosition;
        float modelRotY;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(UIResultSingleModelPosition* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(UIResultSingleModelPosition* pInstance);
        static void Clean(UIResultSingleModelPosition* pInstance);
    };
}

namespace heur::rfl {
    struct UIResultTagModelPosition {
        csl::math::Vector3 cameraPosition;
        csl::math::Vector3 cameraTarget;
        csl::math::Vector3 sonicPosition;
        csl::math::Vector3 buddyPosition;
        float sonicRotY;
        float buddyRotY;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(UIResultTagModelPosition* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(UIResultTagModelPosition* pInstance);
        static void Clean(UIResultTagModelPosition* pInstance);
    };
}

namespace heur::rfl {
    struct UIResultTrioModelPosition {
        csl::math::Vector3 cameraPosition;
        csl::math::Vector3 cameraTarget;
        csl::math::Vector3 sonicPosition;
        csl::math::Vector3 buddyPosition;
        csl::math::Vector3 claSonicPosition;
        float sonicRotY;
        float buddyRotY;
        float claSoniRotY;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(UIResultTrioModelPosition* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(UIResultTrioModelPosition* pInstance);
        static void Clean(UIResultTrioModelPosition* pInstance);
    };
}

namespace heur::rfl {
    struct UIResultMenuParameter {
        float cameraMinDistance;
        float cameraMaxDistance;
        csl::math::Vector3 lightDir;
        csl::math::Vector3 lightColor;
        float lightFieldValue;
        float waitDisplayTime;
        float scoreScrollTotalTime;
        float bonusIntervalTime;
        float bonusScrollMax;
        float bonusScrollMin;
        float expBonusIntervalTime;
        float expScrollTimeS;
        float expScrollTimeA;
        float expScrollTimeB;
        float expScrollTimeC;
        UIResultSingleModelPosition sonicPosition;
        UIResultSingleModelPosition buddyPosition;
        UIResultSingleModelPosition classicPosition;
        UIResultTagModelPosition tagPosition[14];
        UIResultTrioModelPosition trioPosition[14];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(UIResultMenuParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(UIResultMenuParameter* pInstance);
        static void Clean(UIResultMenuParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ExtraStageUnlockData {
        int32_t stageNo;
        int32_t missionID;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ExtraStageUnlockData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ExtraStageUnlockData* pInstance);
        static void Clean(ExtraStageUnlockData* pInstance);
    };
}

namespace heur::rfl {
    struct StageStats {
        enum class RankType : int8_t {
            RANK_S = 0,
            RANK_A = 1,
            RANK_B = 2,
            RANK_C = 3,
            RANK_NONE = 4,
            RANK_DEBUG = 5,
            NUM_RANKS = 6,
        };

        csl::ut::VariableString stagecode;
        int32_t totalPlays;
        int32_t totalClears;
        int32_t totalMisses;
        int32_t totalWBoost;
        int32_t totalWBoostSuccess;
        RankType highRank;
        int32_t highTime;
        int32_t highScore;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageStats* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageStats* pInstance);
        static void Clean(StageStats* pInstance);
    };
}

namespace heur::rfl {
    struct Summary : StageStats {
        csl::ut::VariableString name;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Summary* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Summary* pInstance);
        static void Clean(Summary* pInstance);
    };
}

namespace heur::rfl {
    struct UserSummary : StageStats {
        csl::ut::MoveArray<Summary> summary;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(UserSummary* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(UserSummary* pInstance);
        static void Clean(UserSummary* pInstance);
    };
}

namespace heur::rfl {
    struct AllSummary {
        csl::ut::MoveArray<UserSummary> userSummary;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AllSummary* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AllSummary* pInstance);
        static void Clean(AllSummary* pInstance);
    };
}

namespace heur::rfl {
    struct PlayLog {
        enum class PlayType : int8_t {
            PLAY_NONE = 0,
            START = 1,
            RETRY = 2,
            RESTART = 3,
            PASS_MARKER = 4,
            DEAD = 5,
            CLEAR = 6,
            DEBUG = 7,
            PAUSE_RESTART = 8,
            PAUSE_GIVEUP = 9,
        };

        csl::ut::VariableString user;
        csl::ut::VariableString stagecode;
        PlayType play;
        csl::ut::VariableString option;
        csl::math::Vector3 position;
        int32_t time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayLog* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayLog* pInstance);
        static void Clean(PlayLog* pInstance);
    };
}

namespace heur::rfl {
    struct StageStatsAll {
        csl::ut::MoveArray<StageStats> stageStats;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageStatsAll* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageStatsAll* pInstance);
        static void Clean(StageStatsAll* pInstance);
    };
}

namespace heur::rfl {
    struct StagePlayData {
        enum class GadgetType : int8_t {
            GADGET_NONE = -1,
            GADGET_ASTEROID = 0,
            GADGET_LIGHTNING = 1,
            GADGET_CUBE = 2,
            GADGET_DRILL = 3,
            GADGET_BURST = 4,
            GADGET_VOID = 5,
            GADGET_HOVER = 6,
            NUM_GADGETS = 7,
        };

        enum class GadgetSkillType : int8_t {
            SKILL_NONE = 0,
            ACCELE_GRIND = 1,
            ACCELE_RING = 2,
            REDUCE_DAMAGE = 3,
            RESTORE_RING = 4,
            HIGH_GRIP = 5,
            TAKE_BARRIER = 6,
            DROP_RING = 7,
            RING_INVINCIBLE = 8,
            RING_BONUS = 9,
            INLET_RING = 10,
            POWER_RESTART = 11,
            LANDING_DASH = 12,
            BALANCE = 13,
            CANCEL_DASH = 14,
            SKIMMER = 15,
            RING_UP = 16,
            HA_TURBO = 17,
            BRAKE_GUARD = 18,
            HOMING_BLOW = 19,
            CHAIN_RING = 20,
            COMBO_ENEMY = 21,
            DAMAGED_INVINCIBLE = 22,
            DOUBLE_JUMP = 23,
            HA_STABILITY = 24,
            HUNDRED_BONUS = 25,
            NUM_GADGET_SKILLS = 26,
        };

        enum class RankType : int8_t {
            RANK_S = 0,
            RANK_A = 1,
            RANK_B = 2,
            RANK_C = 3,
            RANK_NONE = 4,
            RANK_DEBUG = 5,
            NUM_RANKS = 6,
        };

        csl::ut::VariableString user;
        csl::ut::VariableString stagecode;
        GadgetType gadgetType;
        GadgetSkillType skill0;
        GadgetSkillType skill1;
        GadgetSkillType skill2;
        RankType rank;
        int32_t time;
        int32_t score;
        int32_t getRings;
        int32_t takeRings;
        int32_t enemies;
        int32_t damages;
        int32_t misses;
        int32_t retry;
        int32_t restart;
        int32_t passMarkers;
        int32_t jump;
        int32_t jumpDouble;
        int32_t homing;
        int32_t boost;
        int32_t quickstep;
        int32_t grindstep;
        int32_t stomping;
        int32_t sliding;
        int32_t gadget;
        int32_t gadgetSpOn;
        int32_t gadgetSp;
        int32_t gadgetSpY;
        int32_t gadgetSpAuto;
        int32_t wboost;
        int32_t wboostSuccess;
        csl::ut::MoveArray<PlayLog> logs;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StagePlayData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StagePlayData* pInstance);
        static void Clean(StagePlayData* pInstance);
    };
}

namespace heur::rfl {
    struct PlayStats {
        StageStatsAll stageStatsAll;
        csl::ut::MoveArray<StagePlayData> stagePlays;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayStats* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayStats* pInstance);
        static void Clean(PlayStats* pInstance);
    };
}

namespace heur::rfl {
    struct ActStageData {
        int8_t rank;
        uint8_t correct;
        uint16_t flags;
        uint32_t score;
        uint32_t allTime;
        NetBuddyData myBuddy;
        NetBuddyData rentalBuddy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ActStageData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ActStageData* pInstance);
        static void Clean(ActStageData* pInstance);
    };
}

namespace heur::rfl {
    struct BuddyData {
        CustomizeData customize;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BuddyData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BuddyData* pInstance);
        static void Clean(BuddyData* pInstance);
    };
}

namespace heur::rfl {
    struct ClosetData {
        bool registered;
        CustomizeData customize;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ClosetData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ClosetData* pInstance);
        static void Clean(ClosetData* pInstance);
    };
}

namespace heur::rfl {
    struct RaceData {
        uint8_t level;
        uint32_t experiencePoint;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(RaceData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(RaceData* pInstance);
        static void Clean(RaceData* pInstance);
    };
}

namespace heur::rfl {
    struct AllBuddyData {
        BuddyData buddy[15];
        ClosetData closet[15];
        RaceData race[7];
        uint32_t activeBuddyIndex;
        uint32_t entryBuddyCount;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AllBuddyData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AllBuddyData* pInstance);
        static void Clean(AllBuddyData* pInstance);
    };
}

namespace heur::rfl {
    struct AllFriendData {
        FriendData selectedFriend;
        FriendData stockedFriends[31];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AllFriendData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AllFriendData* pInstance);
        static void Clean(AllFriendData* pInstance);
    };
}

namespace heur::rfl {
    struct AllStageData {
        ActStageData actStages[70];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AllStageData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AllStageData* pInstance);
        static void Clean(AllStageData* pInstance);
    };
}

namespace heur::rfl {
    struct AudioSettingsData {
        enum class AudioOutput : int8_t {
            Mono = 0,
            Stereo = 1,
            FivePOne = 2,
            SevenPOne = 3,
            NrOutputs = 4,
        };

        float m_masterVolume;
        float m_movieVolume;
        float m_voiceVolume;
        float m_musicVolume;
        float m_sfxVolume;
        AudioOutput m_outputChannels;
        uint32_t m_outputAdapterIndex;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AudioSettingsData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AudioSettingsData* pInstance);
        static void Clean(AudioSettingsData* pInstance);
    };
}

namespace heur::rfl {
    struct ChallengeMissionData {
        uint16_t sosMissionClearCount;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ChallengeMissionData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ChallengeMissionData* pInstance);
        static void Clean(ChallengeMissionData* pInstance);
    };
}

namespace heur::rfl {
    struct KeybindingInfo {
        int32_t m_simpleInputID;
        int32_t m_eKeysButtonIDs[2];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(KeybindingInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(KeybindingInfo* pInstance);
        static void Clean(KeybindingInfo* pInstance);
    };
}

namespace heur::rfl {
    struct KeybindingData {
        KeybindingInfo m_keybindings[12];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(KeybindingData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(KeybindingData* pInstance);
        static void Clean(KeybindingData* pInstance);
    };
}

namespace heur::rfl {
    struct ConfigInfoData {
        enum class VoiceLanguageType : int8_t {
            VOICE_LANGUAGE_ENGLISH = 0,
            VOICE_LANGUAGE_FRENCH = 1,
            VOICE_LANGUAGE_ITALIAN = 2,
            VOICE_LANGUAGE_GERMAN = 3,
            VOICE_LANGUAGE_SPANISH = 4,
            VOICE_LANGUAGE_JAPANESE = 5,
            NUM_VOICE_LANGUAGES = 6,
        };

        enum class LanguageType : int8_t {
            LANGUAGE_ENGLISH = 0,
            LANGUAGE_FRENCH = 1,
            LANGUAGE_ITALIAN = 2,
            LANGUAGE_GERMAN = 3,
            LANGUAGE_SPANISH = 4,
            LANGUAGE_POLISH = 5,
            LANGUAGE_RUSSIAN = 6,
            LANGUAGE_JAPANESE = 7,
            LANGUAGE_ZHONGWEN = 8,
            LANGUAGE_KOREAN = 9,
            LANGUAGE_ZHONGWEN_S = 10,
            NUM_LANGUAGES = 11,
        };

        enum class DifficultyType : int8_t {
            DIFFICULTY_NORMAL = 0,
            DIFFICULTY_EASY = 1,
            NUM_DIFFICULTIES = 2,
        };

        VoiceLanguageType speech;
        LanguageType text;
        DifficultyType difficulty;
        int8_t m_vibrationIndex;
        DifficultyType difficultyDLC;
        uint32_t flags;
        KeybindingData m_keybindings;
        AudioSettingsData m_audio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ConfigInfoData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ConfigInfoData* pInstance);
        static void Clean(ConfigInfoData* pInstance);
    };
}

namespace heur::rfl {
    struct CustomizeFlagSetData {
        uint32_t bitFlags[256];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CustomizeFlagSetData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CustomizeFlagSetData* pInstance);
        static void Clean(CustomizeFlagSetData* pInstance);
    };
}

namespace heur::rfl {
    struct DailyMissionData {
        int32_t missionID[3];
        bool cleared[3];
        bool watchedCrearWindow[3];
        uint32_t bonusIndex[3];
        uint32_t missionStartTime;
        uint32_t bonusStartTime;
        bool bonusStarted;
        float bonusValue;
        bool watchedNew[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DailyMissionData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DailyMissionData* pInstance);
        static void Clean(DailyMissionData* pInstance);
    };
}

namespace heur::rfl {
    struct FlagSetData {
        uint8_t byteFlags[16];
        uint32_t bitFlags[64];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FlagSetData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FlagSetData* pInstance);
        static void Clean(FlagSetData* pInstance);
    };
}

namespace heur::rfl {
    struct GameInfoData {
        uint32_t totalTime;
        uint8_t lastPlayStageNo;
        uint8_t lastPlayStageNoShadowDLC;
        uint8_t padding[2];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameInfoData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameInfoData* pInstance);
        static void Clean(GameInfoData* pInstance);
    };
}

namespace heur::rfl {
    struct MissionFlagSetData {
        uint32_t bitFlags[128];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MissionFlagSetData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MissionFlagSetData* pInstance);
        static void Clean(MissionFlagSetData* pInstance);
    };
}

namespace heur::rfl {
    struct StatValue {
        int32_t value;
        bool assigned;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StatValue* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StatValue* pInstance);
        static void Clean(StatValue* pInstance);
    };
}

namespace heur::rfl {
    struct StatsContainerData {
        StatValue stats[3393];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StatsContainerData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StatsContainerData* pInstance);
        static void Clean(StatsContainerData* pInstance);
    };
}

namespace heur::rfl {
    struct GameData {
        GameInfoData info;
        FlagSetData flagSet;
        CustomizeFlagSetData customizeFlagSet;
        MissionFlagSetData missionFlagSet;
        ChallengeMissionData chalengeMission;
        DailyMissionData dailyMission;
        AllStageData stages;
        AllBuddyData buddies;
        AllFriendData friends;
        StatsContainerData statsContainer;
        ConfigInfoData configInfo;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameData* pInstance);
        static void Clean(GameData* pInstance);
    };
}

namespace heur::rfl {
    struct SystemData {
        enum class StatusType : int8_t {
            STATUS_ZERO_FILL = 0,
            STATUS_INITIALIZED = 1,
            STATUS_NEWGAME = 2,
            STATUS_CONTINUE = 3,
        };

        uint8_t version;
        StatusType status;
        StatusType statusDLC;
        uint8_t padding[1];
        uint32_t reserve;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SystemData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SystemData* pInstance);
        static void Clean(SystemData* pInstance);
    };
}

namespace heur::rfl {
    struct SaveDataType {
        SystemData system;
        GameData game;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SaveDataType* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SaveDataType* pInstance);
        static void Clean(SaveDataType* pInstance);
    };
}

