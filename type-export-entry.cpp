#include <stdint.h>
#include <d3d11.h>

#define EXPORTING_TYPES
#define RESOLVE_STATIC_VARIABLE(x) x

namespace std {
	typedef size_t align_val_t;
}

namespace csl::geom {
	class Aabb;
}

namespace csl::math 
{
	class Vector2 { public: float x; float y; };
	class alignas(16) Vector3 { public: float x; float y; float z; };
	class alignas(16) Vector4 { public: float x; float y; float z; float w; };
	class Angle3 : Vector3 {};
	class alignas(16) Quaternion  {
	public:
		float x; float y; float z; float w;
		void SetRotationBetweenVectors(const Vector4& a, const Vector4& b, const Vector4& fallback);
		static Vector4 RotateVector(const Quaternion& quaternion, const Vector4& vector);
	};
	class alignas(16) Matrix44 {
		Vector4 t; Vector4 u; Vector4 v; Vector4 w;
	public:
		static Matrix44 CreateViewMatrix(Vector3 position, Vector3 up, Vector3 target);
		static Matrix44 CreateOrthogonalProjectionMatrix(float top, float bottom, float left, float right, float nearClip, float farClip);
		static Matrix44 CreatePerspectiveProjectionMatrix(float fov, float aspectRatio, float nearClip, float farClip);
	};
	class alignas(16) Matrix34 {
		Vector4 t; Vector4 u; Vector4 v; Vector4 w;
	public:
		Vector3 GetTransVector() const;
		void SetTransVector(const Vector3& vec);
	};

	class Position { public: float x; float y; float z; };

	Matrix34 Matrix34Multiply(const Matrix34& x, const Matrix34& y);
	Matrix34 Matrix34AffineTransformation(const Vector3& position, const Quaternion& rotation);
	void Matrix34Scale(const Matrix34& mat, const Vector3& scale, Matrix34* result);

	class Segment3
	{
	public:
		Vector3 m_Start{};
		Vector3 m_End{};
	};

	class Capsule
	{
	public:
		Segment3 m_Segment{};
		float m_Radius{};
	};

	class Transform
	{
	public:
		Vector3 position;
		Quaternion rotation;
		Vector3 scale;

		Transform(const Transform& parent, const Transform& child);
	};

	class CalculatedTransform
	{
	public:
		Matrix34 m_Mtx;
		Vector3 m_Scale;
		size_t m_Flags;
	};

	template<typename T>
	inline static const T& Clamp(const T& value, const T& min, const T& max)
	{
		if (value < min)
			return min;
		
		if (value > max)
			return max;
		
		return value;
	}

	template<typename T>
	inline static const T& Max(const T& value, const T& max)
	{
		if (value > max)
			return value;

		return max;
	}

	template<typename T>
	inline static const T& Min(const T& value, const T& min)
	{
		if (value < min)
			return value;

		return min;
	}

	bool Intersection(const Vector3& point, geom::Aabb aabb);

	class Constants
	{
	public:
		inline static const Vector2 Vector2Zero{ 0, 0 };
		inline static const Vector3 Vector3Zero{ 0, 0, 0 };
		inline static const Quaternion QuaternionIdentity{ 0, 0, 0, 1 };
	};
}

namespace csl::geom {
	class Aabb
	{
	public:
		math::Vector3 m_Min{};
		math::Vector3 m_Max{};
		static Aabb Transform(const math::Matrix34& matrix, const Aabb& aabb);
		math::Vector3 Center() const;
		bool Intersect(const Aabb& aabb) const;
	};
}

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