#pragma once

namespace app::level {
    class StageData : hh::fnd::ReferencedObject {
    public:
        enum class ChunkType : uint8_t {
            INITIAL = 0,
            AFTER = 1,
        };

        enum class AttributeFlag : unsigned short
        {
            BOSS = 1,
            EXTRA = 2,
            SPECIAL = 3,
            DLC = 4,
            CREDIT = 5,
            CHARA_CHANGE = 6,
            SHIFTBP = 7,
            TOP_VIEW = 8,
            APP_GFX_PARAM = 9,
            NUMBER_RING = 10,
            YELLOW_MOON_RING_OR_TITLE = 12,
            USE_SOS = 13,
        };

        template<typename T, size_t Len>
        struct List {
            unsigned int count;
            T items[Len];
        };

        char name[16];
        char dir[16];
        char bgm[32];
        char amb[32];
        float bgmRetryStart;
        float bgmRetryFade;
		int stageNumber;
        int categoryNumber;
		int sequenceNumber;
        csl::ut::Bitset<AttributeFlag> attributeFlags;
        player::CharacterId characterId;
        List<unsigned char, 100> staticSectors;
        List<unsigned char, 100> dynamicSectors;
        List<char[16], 4> openingEvents;
        List<char[16], 4> clearedEvents;
        ChunkType chunkType;
    
        static StageData* Create(csl::fnd::IAllocator* allocator);
        StageData(csl::fnd::IAllocator* allocator);

        const char* GetName() const {
            return name;
        }

        // returns value of `stage` if cyber stage, `name` if other stage
        const char* GetStageName() const;
    };
}
