#define EXPORTING_TYPES
#define RESOLVE_STATIC_VARIABLE(x) x

#include "wars-api/wars-api/wars-api.h"

template class app::gfx::FxParamManager::Interpolator<hh::FxBloomParameter, 1>;
template class app::gfx::FxParamManager::Interpolator<hh::FxDOFParameter, 1>;
template class app::gfx::FxParamManager::Interpolator<hh::NeedleFxParameter::ToneMapType, 5>;
template class app::gfx::FxParamManager::Interpolator<hh::NeedleFxParameter::ExposureMode, 0>;
template class app::gfx::FxParamManager::Interpolator<hh::FxColorContrastParameter, 1>;
template class app::gfx::FxParamManager::Interpolator<hh::FxToneMapParameter, 5>;
template class app::gfx::FxParamManager::Interpolator<hh::FxExposureParameter, 0>;
template class app::gfx::FxParamManager::Interpolator<hh::FxShadowMapParameter, 1>;
template class app::gfx::FxParamManager::Interpolator<hh::FxScreenBlurParameter, 0>;
template class app::gfx::FxParamManager::Interpolator<hh::FxSSAOParameter, 0>;
template class app::gfx::FxParamManager::Interpolator<hh::FxLightFieldParameter, 0>;
template class app::gfx::FxParamManager::Interpolator<hh::FxSHLightFieldParameter, 0>;
template class app::gfx::FxParamManager::Interpolator<hh::FxLightScatteringParameter, 0>;
template class app::gfx::FxParamManager::Interpolator<hh::FxRLRParameter, 1>;
template class app::gfx::FxParamManager::Interpolator<hh::FxOcclusionCapsuleParameter, 0>;
template class app::gfx::FxParamManager::Interpolator<hh::FxGodrayParameter, 0>;
template class app::gfx::FxParamManager::Interpolator<hh::FxScreenSpaceGodrayParameter, 0>;
template class app::gfx::FxParamManager::Interpolator<hh::FxHeatHazeParameter, 0>;
template class app::gfx::FxParamManager::Interpolator<hh::FxSceneEnvironmentParameter, 0>;
template class app::gfx::FxParamManager::Interpolator<hh::FxRenderOption, 0>;
template class app::gfx::FxParamManager::Interpolator<hh::FxSGGIParameter, 0>;
template class app::gfx::FxParamManager::Interpolator<hh::FxTAAParameter, 0>;
template class app::gfx::FxParamManager::Interpolator<hh::FxEffectParameter, 0>;
template class csl::fnd::PoolHeapTemplate<csl::fnd::DummyLock>;
