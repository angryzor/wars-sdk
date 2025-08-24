#pragma once

namespace hh::scene{
    class SceneBuilder{
    public:
        class ResourceNameResolver : public hh::fnd::ResourceNameResolver{
        public:
            csl::fnd::IAllocator* allocator;
            csl::ut::StringMap<int64_t> unk1;
            csl::ut::MoveArray<int64_t> unk2;

            virtual const char* RNR_UnkFunc1(const char* name) override;
            ResourceNameResolver();
        };
    };
}
