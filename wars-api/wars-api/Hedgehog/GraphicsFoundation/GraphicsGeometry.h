#pragma once

namespace hh::gfnd {
    class GraphicsGeometry : public fnd::ReferencedObject {
    public:
        enum class PrimitiveType : uint32_t {
            TRIANGLES,
            LINES,
        };
    private:
        csl::ut::MoveArray<csl::math::Vector4> vertices;
        csl::ut::MoveArray<unsigned short> indices;
        csl::ut::MoveArray<csl::math::Vector4> unk3;
        csl::math::Matrix34 transform;
        PrimitiveType primitiveType;
    public:
        virtual bool Initialize(DrawContext* drawContext, const fnd::Geometry& geometry, const csl::math::Matrix34& transform) = 0;
        virtual bool InitializeEdge(DrawContext* drawContext, const fnd::Geometry& geometry, const csl::math::Matrix34& transform) = 0;
        virtual bool InitializeWire(DrawContext* drawContext, const fnd::WireGeometry& geometry, const csl::math::Matrix34& transform) = 0;
        virtual bool InitializeByCopying(DrawContext* drawContext, const GraphicsGeometry* geometry, const csl::math::Matrix34& transform) = 0;
        virtual void SetColor(const csl::ut::Color8& color) = 0;
        virtual void SetTransform(const csl::math::Matrix34& transform) = 0;
        virtual void Render(DrawContext* drawContext) = 0;

        inline bool Initialize(DrawContext* drawContext, const fnd::Geometry& geometry) {
            return Initialize(drawContext, geometry, {});
        }

        inline bool InitializeEdge(DrawContext* drawContext, const fnd::Geometry& geometry) {
            return InitializeEdge(drawContext, geometry, {});
        }

        inline bool InitializeWire(DrawContext* drawContext, const fnd::WireGeometry& geometry) {
            return InitializeWire(drawContext, geometry, {});
        }

        inline bool InitializeByCopying(DrawContext* drawContext, const GraphicsGeometry* geometry) {
            return InitializeByCopying(drawContext, geometry, {});
        }

        inline void Render(DrawContext* drawContext, const csl::math::Matrix34& transform) {
            SetTransform(transform);
            Render(drawContext);
        }
    };
}
