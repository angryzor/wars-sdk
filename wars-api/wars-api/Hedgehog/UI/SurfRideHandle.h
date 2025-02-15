#pragma once

namespace hh::ui {
    class GOCSpriteListener {
    public:
        uint64_t delegate1[3];
        uint64_t delegate2[3];
        void* unk1;

        GOCSpriteListener(void* unkParam1);
        virtual ~GOCSpriteListener();

        virtual void PreReload(SurfRide::Project* project);
        virtual void PostReload(SurfRide::Project* project);
    };

    class SurfRideHandleBase : public fnd::RefByHandleObject {
    protected:
        void* surfRideObject;
    public:
        typedef fnd::HandleManager<SurfRideHandleBase> HandleManager;
        SurfRideHandleBase(void* surfRideObject);
    };

    template<typename T>
    class SurfRideHandle : public SurfRideHandleBase, public GOCSpriteListener {
    public:
        SurfRideHandle(csl::fnd::IAllocator* pAllocator, T* obj);

        inline T* Get() const { return surfRideObject == nullptr ? nullptr : reinterpret_cast<T*>(reinterpret_cast<size_t>(surfRideObject) - 8); }
        inline void Set(T* obj) { surfRideObject = obj == nullptr ? nullptr : reinterpret_cast<void*>(reinterpret_cast<size_t>(obj) + 8); }
    };

    class SurfRideLayerHandle : public SurfRideHandle<SurfRide::Layer> {
    public:
        csl::ut::String key;

        SurfRideLayerHandle(csl::fnd::IAllocator* pAllocator, SurfRide::Layer* layer);

        virtual void PreReload(SurfRide::Project* project) override;
        virtual void PostReload(SurfRide::Project* project) override;
    };

    class GOCSprite;
    class SurfRideCastHandle : public SurfRideHandle<SurfRide::Cast> {
    public:
        GOCSprite* gocSprite;
        csl::ut::String key;

        SurfRideCastHandle(csl::fnd::IAllocator* pAllocator, GOCSprite* gocSprite, SurfRide::Cast* cast);

        virtual void PreReload(SurfRide::Project* project) override;
        virtual void PostReload(SurfRide::Project* project) override;
    };
}
