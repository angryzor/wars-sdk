#pragma once

namespace hh::game {
    class ObjInfo;
    class ObjInfoContainer;

    class ObjInfoClass {
    public:
        const char *pName;
        ObjInfo* (*instantiator)(csl::fnd::IAllocator* pAllocator);
    };

    class ObjInfo : public fnd::ReferencedObject {
        enum class Flags : uint32_t {
            LOADED = 0,
            INITIALIZED = 1,
        };
        fnd::ResourceLoader* resourceLoader;
        csl::ut::Bitset<Flags> flags;
        GameManager* gameManager;
    public:
        ObjInfo();
        virtual void Load() {}
        virtual void Initialize(GameManager* gameManager) {}
        virtual void Finalize() {}
        virtual const char* GetInfoName() { return ""; }
        virtual void RegistCallback(ObjInfoContainer* container) {}
    };
}
