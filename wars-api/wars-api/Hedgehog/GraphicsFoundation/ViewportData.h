#pragma once

namespace hh::gfnd {
    struct ViewportDimensions {
        float x;
        float y;
        float width;
        float height;
    };

    struct alignas(16) ViewportData {
        csl::math::Matrix44 viewMatrix;
        ViewportDimensions viewportDimensions;
        csl::math::Matrix44 projMatrix;
        uint32_t unk1;
        csl::math::Vector3 lookAtPos;
        float fov;
        float aspectRatio;
        float nearClip;
        float farClip;
        uint64_t unk8;

        ViewportData();
        ViewportData& operator=(const ViewportData& other);
        void SetDimensions(const ViewportDimensions& other);
        void SetPerspectiveProjectionMatrix(float fov, float aspectRatio, float nearClip, float farClip);
        inline csl::math::Matrix44 GetInverseViewMatrix() {
            return { viewMatrix.inverse() };
        }
    };
}
