#pragma once

namespace app::level {
	class StageInfo : public hh::game::GameService
	{
	public:
		csl::ut::MoveArray<StageData> stages;
		csl::ut::MoveArray<void*> unk1;
		csl::ut::MoveArray<void*> unk2;

		StageData* GetStageData(const char* stageName);

        GAMESERVICE_CLASS_DECLARATION_INLINE_GETCLASS(StageInfo)
	};
}
