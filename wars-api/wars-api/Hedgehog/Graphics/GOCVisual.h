#pragma once

namespace hh::gfx {
    class GOCVisual : public game::GOComponent {
    public:
        enum class Flag : uint8_t {
            VISIBLE,
        };

        enum class GOCVisualEvent : uint32_t {
            VISIBILITY_UPDATED = 0, // unkParam2 = 0, unkParam = 0
            WORLD_MATRIX_UPDATED = 1,
            MODEL_SPACE_AABB_UPDATED = 2, // unkParam2 = 0, unkParam3 = csl::geom::Aabb*
        };
    public:
        csl::ut::Bitset<Flag> visualFlags;
        uint8_t unk102;
        CREATE_FUNC(GOCVisual, uint8_t unk102Param);
		virtual void* GetRuntimeTypeInfo() const override;
		virtual const char* GetCategory() const override;
        virtual void OnGOCVisualEvent(GOCVisualEvent event, unsigned int unkParam2, void* unkParam3) = 0;
        void SetVisible(bool visible);
        bool IsVisible() const;

        GOCOMPONENT_CLASS_DECLARATION(GOCVisual)
    };
}
