#pragma once

namespace hh::gfx {
    class GOCOcclusionCapsule : public game::GOComponent, public fnd::HFrameListener {
    public:
        uint8_t unk1;
        uint32_t unk2;
        fnd::HFrame* frame;
        hh::fnd::WorldPosition worldPos;
        csl::math::Vector3 scale;
        uint32_t unk4;

		virtual void* GetRuntimeTypeInfo() override;
		virtual const char* GetCategory() override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void HFrameUpdatedCallback(const fnd::HFrame* frame, bool unkParam) override;

        GOCOMPONENT_CLASS_DECLARATION(GOCOcclusionCapsule)
    };
}
