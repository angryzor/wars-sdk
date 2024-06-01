#pragma once

namespace hh::game
{
    class ObjInfoRegistry : fnd::ReferencedObject {
        static ObjInfoClass* staticObjInfoClasses[249];
    public:
        csl::ut::MoveArray<ObjInfoClass*> objInfos;
        csl::ut::StringMap<ObjInfoClass*> objInfosByName;
        static ObjInfoRegistry* instance;
        DEFAULT_CREATE_FUNC(ObjInfoRegistry);
    };
}
