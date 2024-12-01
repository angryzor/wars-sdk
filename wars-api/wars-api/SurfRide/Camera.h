#pragma once

namespace SurfRide
{
    struct SrCamera {
		SRS_CAMERA cameraData;

		SrCamera(const SRS_CAMERA& cameraData);
    };

    struct SrScreenResolution {
        unsigned int width;
        unsigned int height;
    };

	class Camera
	{
	public:
		SrCamera camera;
		csl::math::Matrix34 viewMatrix;

		Camera(const SrCamera& camera);
		void SetCamera(const SrCamera& camera);

		inline SRS_CAMERA& GetCameraData() { return camera.cameraData; }
	};

	SrScreenResolution GetScreenResolution();
}
