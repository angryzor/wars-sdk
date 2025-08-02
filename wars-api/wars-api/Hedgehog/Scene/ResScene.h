#pragma once

namespace hh::scene{
    class ResScene : public hh::fnd::ManagedResource{
    public:
        csl::ut::MoveArray<int64_t> unk0;
        int unk1;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Resolve(hh::fnd::ResourceResolver& resolver) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResScene)
    };
}
