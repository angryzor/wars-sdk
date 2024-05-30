#pragma once

namespace hh::gfnd {
    class DrawContextNeedle : public DrawContext {
    private:
        needle::PrimitiveRenderer* primitiveRenderer1;
        needle::RenderingDeviceContext* renderingDeviceContext;
        uint16_t unk3;
        needle::VertexShader* shaders[2];
        void* needleParameterValueObject[2];
        uint64_t pad[4];

        static DrawContextNeedle* MyCreate(csl::fnd::IAllocator* allocator);
    public:
        DrawContextNeedle();
        virtual void BeginScene(const RenderableParameter* renderableParameter) override;
        virtual void EndScene() override;
        virtual void BeginDraw(const BeginDrawInfo& beginDrawInfo) override;
        virtual void EndDraw() override;
        virtual void BeginDraw2d(const BeginDrawInfo& beginDrawInfo) override;
        virtual void EndDraw2d() override;
        virtual void UnkFunc8() override;
        virtual void DrawPrimitive(PrimitiveType primitiveType, const DrawVertex* vertices, const unsigned short* indices, unsigned int count) override;
        virtual void DrawSphere(const csl::math::Matrix34& transform, float radius, const csl::ut::Color8& color) override;
        virtual void DrawCapsule(const csl::math::Matrix34& transform, float height, float radius, const csl::ut::Color8& color) override;
        virtual void DrawAABB(const csl::math::Vector3& minPos, const csl::math::Vector3& maxPos, const csl::ut::Color8& color) override;
        virtual void DrawOBB(const csl::math::Matrix34& transform, const csl::math::Vector3& scale, const csl::ut::Color8& color) override;
        virtual void DrawCylinder(const csl::math::Matrix34& transform, float height, float radius, const csl::ut::Color8& color) override;
        virtual void DrawCircle(const csl::math::Matrix34& transform, float radius, const csl::ut::Color8& color) override;
        virtual void DrawPlane(const csl::math::Matrix34& transform, float width, float height, const csl::ut::Color8& color) override;
        virtual void SetWireframeMode() override;
        virtual void SetZTestEnable(bool enabled) override;
        virtual void SetZWriteEnable(bool enabled) override;
        virtual void SetCullingMode(unsigned int idx) override;
        virtual void SetUnk2(int a2, int a3, unsigned int* a4) override;
        void DrawOval(const csl::math::Matrix34& transform, float r1, float r2, const csl::ut::Color8& color);
        void NeedleDrawPrimitive(const csl::math::Matrix34& transform, const csl::ut::Color8& color, int primitiveType);
    };
}
