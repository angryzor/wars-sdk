#pragma once

namespace app::camera {
    class CameraService
        : public hh::game::GameService
        , public hh::game::GameManagerListener
    {
    public:
        uint64_t unk201;
        hh::fnd::Handle<app_cmn::camera::CameraFrame, hh::fnd::HandleManager<hh::game::GameObject>> cameras[2];
        uint32_t unk202;
        uint32_t unk203[1];
        uint32_t unk204[1];


		virtual void* GetRuntimeTypeInfo() override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void GameServiceAddedCallback(hh::game::GameService* gameService) override;
		virtual void GameServiceRemovedCallback(hh::game::GameService* gameService) override;
		virtual void Update(const hh::fnd::SUpdateInfo& updateInfo) override;

        app_cmn::camera::CameraFrame* CreateDefaultCameraFrame(int componentId, int viewportId, int priority, float nearClip, float farClip, float fov);
        hh::fnd::Handle<app_cmn::camera::CameraFrame, hh::fnd::HandleManager<hh::game::GameObject>> GetCameraFrame(int index);
        static hh::fnd::Handle<app_cmn::camera::CameraFrame, hh::fnd::HandleManager<hh::game::GameObject>> GetCameraFrame(hh::game::GameManager gameManager, int index);

        GAMESERVICE_CLASS_DECLARATION(CameraService)
    };
}
