#pragma once

namespace hh::ui {
    class LayerController;
    class UIManager;
    class GOCSprite : public game::GOComponent {
    public:
        enum class Flag : uint8_t{
            HAS_RENDERABLE_MAYBE,
            ENABLED,  
        };

        struct LoadedProject {
            csl::ut::VariableString name;
            bool unk1;
            hh::fnd::Reference<hh::ui::SurfRideProjectContext> projectContext;
        };

    private:
        class Renderable : public gfnd::Renderable {
            GOCSprite* gocSprite;
        public:
            Renderable();
            virtual void Render(const gfnd::RenderableParameter* renderableParameter) override;
        };

    public:
        void* hhUiCAppMemoryAlloc;
        csl::ut::MoveArray<SurfRide::Project*> projects;
        csl::ut::MoveArray<LoadedProject> projectContexts;
        csl::ut::MoveArray<LayerController*> layerControllers;
        // UIManager* uiManager;
        fnd::Reference<Renderable> renderable;
        csl::ut::Bitset<Flag> flags;
        hh::ui::ResSurfRideProject* projectResource;
        csl::ut::VariableString projectName;
        bool initialized;
        fnd::Reference<SurfRideProjectContext> projectContext;
        csl::ut::MoveArray<void*> field_138;
        csl::ut::MoveArray<void*> field_158;
        uint16_t nextId;
        ViewportDimensions viewportDimensions;
        uint64_t field_190;
        uint64_t field_198;
        uint64_t field_1A0;
        uint64_t field_1A8;
        csl::ut::MoveArray<SurfRideCastHandle> casts;
        csl::ut::PointerMap<SurfRide::Cast*, SurfRideCastHandle> castMap;
        csl::ut::MoveArray<SurfRideLayerHandle> layers;
        csl::ut::PointerMap<SurfRide::Layer*, SurfRideLayerHandle> layerMap;
        
        LayerController* GetLayerController(SurfRide::Layer* layer, uint16_t id);
        fnd::Handle<SurfRideCastHandle> GetCastHandle(SurfRide::Cast* cast);
        fnd::Handle<SurfRideLayerHandle> GetLayerHandle(SurfRide::Layer* layer);

        struct SetupInfo {
            hh::ui::ResSurfRideProject* resource{};
            const char* name{};
            unsigned int renderableContainer{ 7 };
            unsigned char renderPriority{ 10 };
            unsigned int renderableUnk5{ 2 };
            unsigned int layerControllerCount{};
            unsigned int updatePriority{ 2 };
            ViewportDimensions viewportDimensions{};
        };

        GOCSprite();

		virtual void* GetRuntimeTypeInfo() const override;
		virtual const char* GetCategory() const override;
		virtual void Update(fnd::UpdatingPhase phase, const fnd::SUpdateInfo& updateInfo) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;

        void Setup(const SetupInfo& config);
        LayerController* GetLayerController(const char* sceneName, const char* layerName, uint16_t id);
        LayerController* GetLayerControllerWithNextId(SurfRide::Layer* layer);
        SurfRide::Project* GetProject();

        void SetFlag(Flag flag, bool enabled);
        void EnableFlag(Flag flag);
        void DisableFlag(Flag flag);

        GOCOMPONENT_CLASS_DECLARATION(GOCSprite)
    };
}
