#pragma once

namespace hh::game {
    class GameApplication : public fw::Application {
        fnd::Reference<GameManager> gameManager;
        fnd::Reference<GameUpdater> gameUpdater;

    public:
        static GameApplication* instance;

        // inline static GameApplication* GetInstance() {
        //     return RESOLVE_STATIC_VARIABLE(instance);
        // }
        static GameApplication* GetInstance();

        CREATE_FUNC(GameApplication, fw::FrameworkEnvironment* frameworkEnvironment);
        
        inline GameUpdater& GetGameUpdater() const {
            return gameUpdater;
        }

        virtual uint64_t UnkFunc9() override;
        virtual void UnkFunc10() {}
    };
}
