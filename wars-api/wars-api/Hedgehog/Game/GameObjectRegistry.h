#pragma once

namespace hh::game
{
    class GameObjectRegistry : fnd::ReferencedObject {
        csl::ut::MoveArray<const GameObjectClass*> gameObjectClasses;
        csl::ut::StringMap<const GameObjectClass*> gameObjectClassesByName;

        static GameObjectClass* staticGameObjectClasses[538];
    public:
        DEFAULT_CREATE_FUNC(GameObjectRegistry);
        void AddObject(const GameObjectClass** gameObjectClass);
        const GameObjectClass* GetGameObjectClassByName(const char* name);
        inline const csl::ut::MoveArray<const GameObjectClass*>& GetGameObjectClasses() {
            return gameObjectClasses;
        }
    };
}
