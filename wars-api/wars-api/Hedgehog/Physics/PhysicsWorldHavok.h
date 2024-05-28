#pragma once

namespace hh::physics {
    class PhysicsWorldHavok : public PhysicsWorld {
    public:
        GAMESERVICE_CLASS_DECLARATION(PhysicsWorldHavok)
    };

    const hh::game::GameServiceClass* PhysicsWorld::GetClass() {
        return PhysicsWorldHavok::GetClass();
    }
}
