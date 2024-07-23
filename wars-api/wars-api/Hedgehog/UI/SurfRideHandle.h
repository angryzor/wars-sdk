#pragma once

namespace hh::ui {
    class SurfRideHandleBase : public fnd::RefByHandleObject {
    protected:
        void* surfRideObject;
    public:
        typedef fnd::HandleManager<SurfRideHandleBase> HandleManager;
        SurfRideHandleBase(void* surfRideObject);
    };

    class SurfRideLayerHandle : public SurfRideHandleBase {
    protected:
        csl::ut::String unk1;
    public:
        SurfRideLayerHandle(SurfRide::Layer* layer);
    };

    class GOCSprite;
    class SurfRideCastHandle : public SurfRideHandleBase {
    protected:
        GOCSprite* gocSprite;
        csl::ut::String unk1;
    public:
        SurfRideCastHandle(GOCSprite* gocSprite, SurfRide::Cast* cast);
    };
}
