#pragma once

namespace hh::scene{
    class SceneNode : public hh::fnd::ReferencedObject {
    public:
        hh::game::GameObject* gameObject;
        csl::ut::VariableString name;
        int unk0;
        int unk1;
        bool isDead;

        virtual void Destroy();
        virtual void UnkFunc1() {}
        virtual int64_t UnkFunc2();
        virtual char UnkFunc3();
        virtual hh::fnd::HFrame* GetHFrame();

        SceneNode(csl::fnd::IAllocator* allocator, csl::ut::VariableString& name, int a4, char a5);
    };
}
