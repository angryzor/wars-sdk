#pragma once

namespace app::player {
    class PlayerParameterService : public hh::game::GameService {
    public:
        csl::ut::MoveArray<hh::fnd::Reference<hh::fnd::ResReflection<void*>>> parameters;

        GAMESERVICE_CLASS_DECLARATION(PlayerParameterService)
    };
}