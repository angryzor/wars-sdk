#pragma once

namespace csl::fnd {
    class PoolHeapBase : public HeapBase {
        size_t bufferStart;
        size_t bufferEnd;
        uint64_t unk103;
        size_t blockSize;
        uint32_t unk105;
        unsigned int liveAllocations;
        uint32_t unk106;
        unsigned int callAllocateTime;
        unsigned int unk108;
        uint64_t unk109;

    public:
        PoolHeapBase(const char* name);

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
        virtual bool GetMemorySnapshot(MemorySnapshot& memorySnapshot) const override;
        virtual uint64_t UnkFunc1();

        void Initialize(void* unkParam1, void* unkParam2, size_t unkParam3);
    };

    template<typename TLock>
    class alignas(8) PoolHeapTemplate : public PoolHeapBase {
        TLock m_Lock;
    
    public:
        PoolHeapTemplate(const char* name) : PoolHeapBase{ name } {}

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void* Alloc(size_t in_size, size_t in_alignment) override;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) override;
        virtual void Free(void* in_pMemory) override;
    };
}
