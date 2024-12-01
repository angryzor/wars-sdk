#pragma once
#ifndef EXPORTING_TYPES
#include <span>
#endif

namespace hh::game
{
    struct GOCActivatorSpawner {
        float m_range;
        float m_distance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClassMember rflClassMembers[2];
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GOCActivatorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GOCActivatorSpawner* pInstance);
        static void Clean(GOCActivatorSpawner* pInstance);
    };

    inline const hh::fnd::RflTypeInfo GOCActivatorSpawner::typeInfo{
        "GOCActivatorSpawner",
        "GOCActivatorSpawner",
        [](void* instance, csl::fnd::IAllocator* allocator) {
            auto* inst = static_cast<GOCActivatorSpawner*>(instance);
            inst->m_range = 0.0f;
            inst->m_distance = 0.0f;
            return instance;
        },
        [](void* instance) {},
        [](void* instance) {},
        sizeof(GOCActivatorSpawner),
    };
    inline const hh::fnd::RflClassMember GOCActivatorSpawner::rflClassMembers[2]{
        { "m_range", nullptr, nullptr, hh::fnd::RflClassMember::Type::FLOAT, hh::fnd::RflClassMember::Type::VOID, 0, 0, offsetof(GOCActivatorSpawner, m_range), nullptr },
        { "m_distance", nullptr, nullptr, hh::fnd::RflClassMember::Type::FLOAT, hh::fnd::RflClassMember::Type::VOID, 0, 0, offsetof(GOCActivatorSpawner, m_distance), nullptr },
    };
    inline const hh::fnd::RflClass GOCActivatorSpawner::rflClass{ "GOCActivatorSpawner", nullptr, sizeof(GOCActivatorSpawner), nullptr, 0, GOCActivatorSpawner::rflClassMembers, 2, nullptr };

    // This is an emulation. This feature doesn't exist yet in Forces.
    class GOComponentRegistry : fnd::BaseObject {
    public:
        class GOComponentRegistryItem {
            const char* name;
            const GOComponentClass* componentClass;
            const fnd::RflClass* rflClass;

        public:
            inline GOComponentRegistryItem(const char* name, const GOComponentClass* componentClass, const fnd::RflClass* rflClass) : name{ name }, componentClass{ componentClass }, rflClass{ rflClass } {}
            inline const char* GetName() const { return name; }
            inline const GOComponentClass* GetComponentClass() const { return componentClass; }
            inline const fnd::RflClass* GetSpawnerDataClass() const { return rflClass; }
        };

    private:
        inline static GOComponentRegistryItem rangeSpawning{ "RangeSpawning", nullptr, &GOCActivatorSpawner::rflClass };
        inline static GOComponentRegistryItem* components[]{ &rangeSpawning };

    public:
        const GOComponentRegistryItem* GetComponentInformationByName(const char* name) {
            if (!strcmp(name, "RangeSpawning")) return &rangeSpawning;
            return nullptr;
        }

#ifndef EXPORTING_TYPES
        inline std::span<GOComponentRegistryItem*> GetComponents() const {
            return { components, 1 };
        }
#endif
    };
}
