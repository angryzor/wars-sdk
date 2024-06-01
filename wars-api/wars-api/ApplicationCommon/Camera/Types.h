#pragma once

namespace app_cmn::camera {
    struct FrustumParameter {
        float nearClip;
        float farClip;
        float fov;
        FrustumParameter();
    };

    struct CameraParameter {
        struct Target {
            csl::math::Vector4 unk1;
            csl::math::Vector4 unk2;
            csl::math::Vector4 unk3;
        };
        struct Orientation {
            csl::math::Vector4 unk9;
            uint32_t unk8b;  
        };
        Target target;
        Orientation orientation;
        FrustumParameter unk10;
        CameraParameter();
    };

    struct CameraPose {
        csl::math::Vector4 unk1;
        csl::math::Vector4 unk2;
        csl::math::Vector4 unk3;
        CameraPose();
    };

}
