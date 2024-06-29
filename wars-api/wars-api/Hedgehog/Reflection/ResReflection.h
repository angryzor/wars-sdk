#pragma once

namespace hh::fnd {
    class ResReflection : public ManagedResource {
    public:
        void* reflectionData;

        inline void* GetData() {
            return reflectionData;
        }

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override {}

        MANAGED_RESOURCE_CLASS_DECLARATION(ResReflection)
    };

    template<typename T>
    class ResReflectionT : public ResReflection {
    public:
        T* GetData() {
            return static_cast<T*>(ResReflection::GetData());
        }

        inline static const ResourceTypeInfo* GetTypeInfo() {
            return ResReflection::GetTypeInfo();
        }
    };
}
