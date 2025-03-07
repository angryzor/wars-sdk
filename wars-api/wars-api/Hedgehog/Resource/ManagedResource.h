#pragma once

#define MANAGED_RESOURCE_CLASS_DECLARATION(ClassName) private:\
		static const hh::fnd::ResourceTypeInfo typeInfo;\
		ClassName();\
		static ClassName* Create(csl::fnd::IAllocator* allocator, csl::fnd::IAllocator* resourceAllocator, size_t size);\
	public:\
		static const hh::fnd::ResourceTypeInfo* GetTypeInfo();

#define MANAGED_RESOURCE_CLASS_DECLARATION_INLINE_GETTYPEINFO(ClassName) private:\
		static const hh::fnd::ResourceTypeInfo typeInfo;\
		ClassName();\
		static ClassName* Create(csl::fnd::IAllocator* allocator, csl::fnd::IAllocator* resourceAllocator, size_t size);\
	public:\
		inline static const hh::fnd::ResourceTypeInfo* GetTypeInfo() { return &RESOLVE_STATIC_VARIABLE(typeInfo); }

namespace hh::fnd {
    class ManagedResource;

    struct ResourceTypeInfo {
        const char *pName;
        const char *pScopedName;
        uint32_t objectSize;
        bool isInBinaContainer;
        ManagedResource* (*instantiator)(csl::fnd::IAllocator* pAllocator);
    };

    class ResourceResolver;
    class StaticResourceContainer;
    class ManagedResource : public ReferencedObject, private csl::ut::NonCopyable {
    public:
        csl::ut::VariableString name;
        csl::ut::VariableString unkStrPrefix; // before hyphen
        csl::ut::VariableString unkStrPostfix; // after hyphen
        const ResourceTypeInfo* resourceTypeInfo;
        csl::fnd::IAllocator* resourceAllocator;
        void* originalBinaryData;
        void* unpackedBinaryData;
        size_t size;

        DEFAULT_CREATE_FUNC(ManagedResource);

        inline const char* GetName() const {
            return name.c_str();
        }

        inline const ResourceTypeInfo& GetClass() const {
            return *resourceTypeInfo;
        }

        inline size_t GetSize() const {
            return size;
        }

        inline csl::fnd::IAllocator* GetResourceAllocator() {
            return resourceAllocator;
        }

        // static ManagedResource* Create(File* file, const char* name, ResourceTypeInfo* resourceTypeInfo);
        static ManagedResource* Create(csl::fnd::IAllocator* resourceAllocator, const char* unkStrParam, const char* name, void* data, size_t size, ResourceTypeInfo* resourceTypeInfo);

        // This is only guessed from a similar function in rio, but there this and the following function are swapped.
        // I haven't actually seen this be overridden anywhere.
        virtual void LoadFromStaticResourceContainer(void* data, size_t size, StaticResourceContainer* container);
        virtual void Load(void* data, size_t size) = 0;
        virtual void Unload() = 0;
        virtual void Resolve(ResourceResolver& resolver) {}
        virtual void Reload(void* data, size_t size) = 0;
    };
}
