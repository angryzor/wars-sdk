
#pragma once

namespace hh::fnd {
    class ResourceTypeRegistry : public ReferencedObject, public csl::fnd::Singleton<ResourceTypeRegistry> {
        csl::ut::StringMap<const ResourceTypeInfo*> typeInfosByName;
        csl::ut::StringMap<const ResourceTypeInfo*> typeInfosByExtension;

        static const ResourceTypeInfo* typeInfos[55];
        static csl::ut::Pair<const char*, const ResourceTypeInfo*> typeInfoExtensionMap[28];
    public:
        ResourceTypeRegistry();
        static ResourceTypeRegistry* Create();
        csl::ut::MoveArray<const ResourceTypeInfo*> GetTypeInfos();
        const char* GetNameByTypeInfo(const ResourceTypeInfo* typeInfo);
        const ResourceTypeInfo* GetTypeInfoByName(const char* name);
        const char* GetExtensionByTypeInfo(const ResourceTypeInfo* typeInfo);
        const ResourceTypeInfo* GetTypeInfoByExtension(const char* extension);
    };
}
