#pragma once

namespace csl::fnd {
    class StackHeapBase : public HeapBase {
        size_t bufferStart;
        size_t bufferEnd;
        uint64_t unk103;
        uint64_t unk104;
        unsigned int liveAllocations;
        uint32_t unk105;
        uint64_t unk106;
        uint64_t unk107;
        unsigned int callAllocateTime;

    public:
        StackHeapBase(const char* name);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void* Alloc(size_t in_size, size_t in_alignment) override;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) override;
        virtual void Free(void* in_pMemory) override {}
        virtual bool IsIn(void* ptr) const override;
        virtual size_t GetBlockSize(void* ptr) const override { return 0; }
        virtual void CollectHeapInformation(HeapInformation& heapInformation) const override;
        virtual size_t GetBufferTop() const override;
        virtual size_t GetBufferEnd() const override;
        virtual unsigned int GetCurrentAllocateCount() const override;
        virtual unsigned int GetCallAllocateTime() const override;
        virtual bool GetMemorySnapshot(MemorySnapshot& memorySnapshot) const override { return false; }
        virtual uint64_t UnkFunc1();
        virtual uint64_t UnkFunc2();
        virtual uint64_t UnkFunc3();

        void Initialize(void* unkParam1, void* unkParam2, size_t unkParam3);
    };

    template<typename TLock>
    class alignas(8) StackHeapTemplate : public StackHeapBase {
        TLock m_Lock;
    
    public:
        StackHeapTemplate(const char* name) : StackHeapBase{ name } {}

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void* Alloc(size_t in_size, size_t in_alignment) override;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) override;
        virtual void Free(void* in_pMemory) override;
    };
}
