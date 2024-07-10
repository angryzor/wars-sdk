#pragma once

namespace hh::gfnd {
    enum class PrimitiveType {
        POINT_LIST,
        LINE_LIST,
        TRIANGLE_LIST,
        TRIANGLE_STRIP,
    };

    struct DrawVertex {
        float x;
        float y;
        float z;
        uint32_t color;
    };

    class DrawContext : public fnd::ReferencedObject {
    public:
        struct BeginDrawInfo {
            uint32_t viewportId;
            float viewMatrix[16];
            float projMatrix[16];
        };

        virtual ~DrawContext();
        virtual void BeginScene(const RenderableParameter* renderableParameter);
        virtual void EndScene();
        virtual void BeginDraw(const BeginDrawInfo& beginDrawInfo);
        virtual void EndDraw();
        virtual void BeginDraw2d(const BeginDrawInfo& beginDrawInfo);
        virtual void EndDraw2d();
        virtual void UnkFunc8();
        virtual void DrawPrimitive(PrimitiveType primitiveType, const DrawVertex* vertices, const unsigned short* indices, unsigned int count);
        virtual void DrawSphere_(const csl::math::Matrix34& transform, float radius, const csl::ut::Color8& color);
        virtual void DrawCapsule(const csl::math::Matrix34& transform, float radius, float halfHeight, const csl::ut::Color8& color);
        virtual void DrawAABB(const csl::math::Vector3& minPos, const csl::math::Vector3& maxPos, const csl::ut::Color8& color);
        virtual void DrawOBB(const csl::math::Matrix34& transform, const csl::math::Vector3& halfExtents, const csl::ut::Color8& color);
        virtual void DrawCylinder(const csl::math::Matrix34& transform, float radius, float halfHeight, const csl::ut::Color8& color);
        virtual void DrawCircle(const csl::math::Matrix34& transform, float radius, const csl::ut::Color8& color);
        virtual void DrawPlane(const csl::math::Matrix34& transform, float width, float height, const csl::ut::Color8& color);
        virtual void SetWireframeMode();
        virtual void SetZTestEnable(bool enabled);
        virtual void SetZWriteEnable(bool enabled);
        virtual void SetCullingMode(unsigned int idx);
        virtual void SetUnk2(int a2, int a3, unsigned int* a4);

        // Fixed version because the real version is buggy
        inline void DrawSphere(const csl::math::Matrix34& transform, float radius, const csl::ut::Color8& color) {
            DrawCircle({ transform }, radius, color);
            DrawCircle({ transform * Eigen::AngleAxisf(1.5707964, Eigen::Vector3f::UnitZ()) }, radius, color);
            DrawCircle({ transform * Eigen::AngleAxisf(1.5707964, Eigen::Vector3f::UnitY()) * Eigen::AngleAxisf(1.5707964, Eigen::Vector3f::UnitZ()) }, radius, color);
        }
    };
}
