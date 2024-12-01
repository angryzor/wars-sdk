#pragma once

namespace hh::gfx {
    class GOCVisualDebugDraw : public GOCVisualTransformed {
    public:
        struct SetupInfo {
            void* unk1;
            uint16_t unk2;
            fnd::Geometry* geometry;
            csl::ut::Color8 color;
        };

        void* unk201;
        uint32_t unk202;

    public:
        inline GOCVisualDebugDraw();
        void Setup(const SetupInfo& setupInfo);

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void OnGOCVisualEvent(GOCVisualEvent unkParam1, unsigned int unkParam2, void* unkParam3) override;
        
        GOCOMPONENT_CLASS_DECLARATION(GOCVisualDebugDraw)
    };
}
