#pragma once

namespace app_cmn::fnd {
    class ResRflParameter : public hh::fnd::ReferencedObject {
    public:
        hh::fnd::ResReflection* resReflection;
        hh::fnd::Packfile* packfile;
        hh::fnd::RflClass* rflClass;
        uint64_t unk4;
        csl::ut::MoveArray32<void*> unk5;
        csl::ut::MoveArray32<void*> unk6;

        CREATE_FUNC(ResRflParameter)
    };
}
