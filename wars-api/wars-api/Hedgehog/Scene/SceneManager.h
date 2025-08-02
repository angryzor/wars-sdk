#pragma once

namespace hh::scene{
    class SceneManagerListener{
    public:
        virtual void SML_UnkFunc0() {}
        virtual void SML_UnkFunc1(int64_t a2, int64_t a3) {}
        virtual void SML_UnkFunc2() {}
        virtual void SML_UnkFunc3() {}
        virtual void SML_UnkFunc4() {}
        virtual void SML_UnkFunc5(int64_t a2) {}
        virtual void SML_UnkFunc6(int64_t a2) {}
        virtual void SML_UnkFunc7(int64_t a2) {}
        virtual void SML_UnkFunc8(int64_t a2) {}
        virtual void SML_UnkFunc9(int64_t a2) {}
        virtual void SML_UnkFunc10(int64_t a2) {}
        virtual void SML_UnkFunc11(int64_t a2) {}
        virtual void SML_UnkFunc12(int64_t a2) {}
        virtual void SML_UnkFunc13(int64_t a2) {}
        virtual void SML_UnkFunc14(int64_t a2) {}
        virtual void SML_UnkFunc15() {}
    };

    class SceneManager : public hh::game::GameService, public hh::game::GameStepListener{
    public:
        csl::ut::MoveArray<SceneControl*> sceneControls;
        csl::ut::MoveArray<SceneManagerListener*> listeners;

        virtual void* GetRuntimeTypeInfo() override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;

        virtual void PreStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        void AddListener(SceneManagerListener* listener);
        void RemoveListener(SceneManagerListener* listener);

        GAMESERVICE_CLASS_DECLARATION(SceneManager)
    };
}
