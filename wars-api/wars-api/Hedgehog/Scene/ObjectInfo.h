#pragma once

namespace hh::scene{
    class ObjectInfo{
    public:
        SceneNode* node;
        int64_t unk0;
        int64_t unk1;
        int64_t unk2;
        int unk3;
        int unk4;
    };

    class ObjectInfoImpl : public ObjectInfo {
    public:
        virtual SceneNode* GetNode();
        virtual int64_t UnkFunc0(int64_t a2, int64_t a3);
        virtual int64_t UnkFunc1(int64_t a2, int64_t a3);
        virtual int64_t SetUnk(int a2);
        virtual int GetUnk();
        virtual ~ObjectInfoImpl();
    };
}
