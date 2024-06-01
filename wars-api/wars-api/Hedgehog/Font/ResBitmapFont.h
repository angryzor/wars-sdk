#pragma once

namespace hh::font {
    struct BFNT_CHUNK {
    };
    struct BFNT_ROOT {
        char magic[4];
        uint32_t unk1;
        char count;
        uint64_t unk2;
        BFNT_CHUNK** chunkPointerss;
    };
    class ResBitmapFont : public fnd::ManagedResource {
        BFNT_ROOT* binaryData;
    public:
        virtual void Load(void* data, size_t size);
        virtual void Unload();
        virtual void Resolve(fnd::ResourceResolver& resolver);
        virtual void Reload(void* data, size_t size) {}

        MANAGED_RESOURCE_CLASS_DECLARATION(ResBitmapFont)
    };
}
