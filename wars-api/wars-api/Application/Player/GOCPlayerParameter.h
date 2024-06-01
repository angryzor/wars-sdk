#pragma once

namespace app::player {
    class GOCPlayerParameter : public hh::game::GOComponent {
    public:
        enum class Mode : uint32_t {
            FORWARD_VIEW,
            SIDE_VIEW,
            FORWARD_VIEW_WATER,
            SIDE_VIEW_WATER,
        };

        enum class SuperState : uint32_t {
            NORMAL_SONIC,
            SUPER_SONIC,
        };


        heur::rfl::PlayerCommonParameters* playerCommonParameters;
        heur::rfl::PlayerSonicParameters* playerSonicParameters;
        heur::rfl::PlayerBuddyParameters* playerBuddyParameters;
        heur::rfl::PlayerSonicClassicParameters* playerSonicClassicParameters;
        heur::rfl::PlayerSuperSonicParameters* playerSuperSonicParameters;
        heur::rfl::GadgetParameters* gadgetParameters;
        heur::rfl::CommonModePackage* commonModePackage[4];
        heur::rfl::SonicModePackage* sonicModePackage[4];
        heur::rfl::BuddyModePackage* buddyModePackage[4];
        heur::rfl::SonicClassicModePackage* sonicClassicModePackage[4];
        Mode mode;
        uint16_t loadedPackages;

    private:
        // void* GetPlayerParameter(const hh::fnd::RflClass& rflClass);

    public:

        void SetMode(Mode mode);

        // template<typename T>
        // T* GetPlayerParameter() {
        //     return reinterpret_cast<T*>(GetPlayerParameter(RESOLVE_STATIC_VARIABLE(T::rflClass)));
        // }

        // template<typename T>
        // T* GetPlayerParameter(const hh::fnd::RflClass& rflClass) {
        //     return reinterpret_cast<T*>(GetPlayerParameter(rflClass));
        // }

        virtual void* GetRuntimeTypeInfo() const override;
        virtual const char* GetCategory() const override;
		virtual void OnGOCEvent(hh::game::GOComponent::GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        GOCOMPONENT_CLASS_DECLARATION_INLINE_GETCLASS(GOCPlayerParameter)
    };
}
