#pragma once

namespace hh::fnd {
    class ResourceManager : public fnd::ReferencedObject, public csl::fnd::Singleton<ResourceManager> {
        csl::ut::MoveArray<DynamicResourceContainer*> resourceContainers;
        csl::ut::MoveArray<void*> unk4; // probably managedResources
        csl::ut::PointerMap<const ResourceTypeInfo*, uint32_t> resourceContainerIndexByTypeInfo;
        csl::ut::MoveArray<void*> unk5; // probably managedResources
        uint64_t unk7;
        uint64_t unk8;

    public:
        ManagedResource* GetResource(const char* name, const hh::fnd::ResourceTypeInfo* resourceTypeInfo);
        ResourceManager();
        void Setup();

        const csl::ut::MoveArray<ManagedResource*>& GetResourcesByTypeInfo(const ResourceTypeInfo* typeInfo);
        csl::ut::MoveArray<DynamicResourceContainer*>& GetResourceContainers() {
            return resourceContainers;
        }

        template<typename T>
        inline T* GetResource(const char* name) {
            return static_cast<T*>(GetResource(name, T::GetTypeInfo()));
        }

        class ResourceListener {
        public:
            virtual ~ResourceListener();
            virtual void ResourceLoadedCallback(ManagedResource* resource) {}
            virtual void ResourceUnloadedCallback(ManagedResource* resource) {}
        };
    };
}
