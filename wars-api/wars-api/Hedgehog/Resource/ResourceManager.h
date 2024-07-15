#pragma once

namespace hh::fnd {
    class ResourceManager : public fnd::ReferencedObject, public csl::fnd::Singleton<ResourceManager> {
    public:
        class Listener {
        public:
            virtual ~Listener() = default;
            virtual void ResourceAddedCallback(ManagedResource* resource) {}
            virtual void ResourceRemovedCallback(ManagedResource* resource) {}
            virtual void ResourceRemovedAllCallback() {}
        };

    private:
        csl::ut::MoveArray<DynamicResourceContainer*> resourceContainers;
        csl::ut::MoveArray<void*> unk4; // probably managedResources
        csl::ut::PointerMap<const ResourceTypeInfo*, uint32_t> resourceContainerIndexByTypeInfo;
        csl::ut::MoveArray<Listener*> listeners;
        uint64_t unk7;
        uint64_t unk8;

    public:
        void AddResource(hh::fnd::ManagedResource* resource);
        void RemoveResource(hh::fnd::ManagedResource* resource);
        void FireResourceAdded(hh::fnd::ManagedResource* resource);
        void FireResourceRemoved(hh::fnd::ManagedResource* resource);
        ManagedResource* GetResource(const char* name, const hh::fnd::ResourceTypeInfo* resourceTypeInfo);
        ResourceManager();
        void Setup();
        void AddListener(Listener* listener);
        void RemoveListener(Listener* listener);

        const csl::ut::MoveArray<ManagedResource*>& GetResourcesByTypeInfo(const ResourceTypeInfo* typeInfo);
        csl::ut::MoveArray<DynamicResourceContainer*>& GetResourceContainers() {
            return resourceContainers;
        }

        template<typename T>
        inline T* GetResource(const char* name) {
            return static_cast<T*>(GetResource(name, T::GetTypeInfo()));
        }
    };
}
