#pragma once

namespace hh::gfnd {
    class GraphicsGeometryNeedle : public GraphicsGeometry {
        static GraphicsGeometryNeedle* MyCreate(void* unused, csl::fnd::IAllocator* allocator);
    public:
        GraphicsGeometryNeedle(csl::fnd::IAllocator* allocator);
        virtual bool Initialize(DrawContext* drawContext, const fnd::Geometry& geometry, const csl::math::Matrix34& transform) override;
        virtual bool InitializeEdge(DrawContext* drawContext, const fnd::Geometry& geometry, const csl::math::Matrix34& transform) override;
        virtual bool InitializeWire(DrawContext* drawContext, const fnd::WireGeometry& geometry, const csl::math::Matrix34& transform) override;
        virtual bool InitializeByCopying(DrawContext* drawContext, const GraphicsGeometry* geometry, const csl::math::Matrix34& transform) override;
        virtual void SetColor(const csl::ut::Color<uint8_t>& color) override;
        virtual void SetTransform(const csl::math::Matrix34& worldMatrix) override;
        virtual void Render(DrawContext* drawContext) override;
    };
}
