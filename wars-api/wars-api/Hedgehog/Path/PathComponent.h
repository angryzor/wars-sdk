#pragma once

namespace hh::path {
    class PathManager;
    class PathComponent : public game::GOComponent, public fnd::HFrameListener {
    public:
        struct Description {
            ResPathObject* resource;
            fnd::HFrame* frame;
            bool unk1;
        };

        fnd::Reference<fnd::HFrame> frame;
        PathManager* pathManager;
        fnd::Reference<ResPathObject> resource;
        uint64_t qword90;
        bool isMoveable;
        hh::game::GOCTransform* gocTransform;
        csl::math::Matrix34 matrixB0;
        csl::math::Matrix34 matrixF0;

        PathComponent();

		virtual const char* GetCategory() const override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void HFrameUpdatedCallback(const fnd::HFrame* frame, bool unkParam) override;

        void Setup(const Description& description);
        const char* GetName() const;

        GOCOMPONENT_CLASS_DECLARATION(PathComponent);
    };
}
