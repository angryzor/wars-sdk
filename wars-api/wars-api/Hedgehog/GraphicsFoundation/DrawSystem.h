#pragma once

namespace hh::gfnd {
    class DrawSystem {
    public:
        static DrawContext* (*CreateDrawContext)(csl::fnd::IAllocator* allocator);
        static GraphicsGeometry* (*CreateGraphicsGeometry)(void* unused, csl::fnd::IAllocator* allocator);
    };
}
