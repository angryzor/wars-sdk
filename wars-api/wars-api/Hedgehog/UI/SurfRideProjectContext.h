
#pragma once

namespace hh::ui {
    class SurfRideProjectContext : public fnd::ReferencedObject {
        csl::ut::VariableString sceneName;
        csl::ut::MoveArray<SurfRide::ReferencedObject*> unk2;
    public:
        SurfRideProjectContext();
        void Destroy(SurfRide::Project* project, csl::fnd::IAllocator* allocator);
    };
}
