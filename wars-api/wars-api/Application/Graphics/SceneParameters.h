#pragma once

namespace app::gfx {
    class SceneParameters : public hh::fnd::ReferencedObject {
    public:
        class Listener {
        public:
            virtual void SPL_UnkFunc1() {}
            virtual void SPL_UnkFunc2() {}
        };

        hh::NeedleFxSceneData* sceneData;
        csl::ut::MoveArray<SceneParameters::Listener*> listeners;
        csl::ut::MoveArray<void*> unk2;
        uint64_t unk3;
        csl::ut::VariableString unk4;
        uint8_t unk5;
        uint32_t sceneParamIndexOffset;
        SceneParameters(csl::fnd::IAllocator* allocator);
        hh::NeedleFxSceneData* GetSceneData();
    };
}
