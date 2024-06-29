#pragma once

namespace csl::fnd {
    class ExternalHeapBase : public HeapBase {
        uint64_t unk101;
        size_t bufferStart;
        size_t bufferEnd;
        uint32_t liveAllocations;
        uint32_t unk104;
        uint32_t callAllocateTime;
        uint64_t unk106;
        bool initialized;
        char* unk107;

    public:
        ExternalHeapBase(const char* name);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void* Alloc(size_t in_size, size_t in_alignment) override;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) override;
        virtual void Free(void* in_pMemory) override;
        virtual bool IsIn(void* ptr) const override;
        virtual size_t GetBlockSize(void* ptr) const override;
        virtual void CollectHeapInformation(HeapInformation& heapInformation) const override;
        virtual size_t GetBufferTop() const override;
        virtual size_t GetBufferEnd() const override;
        virtual unsigned int GetCurrentAllocateCount() const override;
        virtual unsigned int GetCallAllocateTime() const override;
        virtual bool GetMemorySnapshot(MemorySnapshot& memorySnapshot) const override { return false; }
        virtual void UnkFunc1() {}
        virtual void UnkFunc2() {}
        virtual unsigned int UnkFunc3() { return 0; }
        virtual bool UnkFunc4() { return false; }
        virtual uint64_t UnkFunc5() = 0;
        virtual uint64_t UnkFunc6() = 0;
        virtual uint64_t UnkFunc7() = 0;
        virtual uint64_t UnkFunc8() = 0;

        void Initialize(void* unkParam1, void* unkParam2, size_t unkParam3);
    };

    template<typename TLock>
    class alignas(8) ExternalHeapTemplate : public ExternalHeapBase {
        TLock m_Lock;
    
    public:
        ExternalHeapTemplate(const char* name) : ExternalHeapBase{ name } {}

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void* Alloc(size_t in_size, size_t in_alignment) override;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) override;
        virtual void Free(void* in_pMemory) override;
        virtual void UnkFunc1() override;
        virtual void UnkFunc2() override;
    };
}
