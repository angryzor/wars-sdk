#pragma once

namespace csl::fnd {
    class LinkHeapBase : public HeapBase {
        HeapBase* heaps[12];

    public:
        LinkHeapBase(const char* name);

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
        virtual bool CanHaveChild() override { return false; }
        virtual void ForEachAllocatedBlock(MemoryBlockFunction& func) override;
        virtual void PrintDebugInformation() override;
        virtual bool GetMemorySnapshot(MemorySnapshot& memorySnapshot) const override;
        virtual void SetDebugFillOnAlloc(bool enabled) override;
        virtual void SetDebugFillOnFree(bool enabled) override;
        virtual void SetDebugUnk(bool enabled) override;
        virtual uint64_t UnkFunc1();

        void Initialize(void* unkParam1, void* unkParam2, size_t unkParam3);
    };

    template<typename TLock>
    class alignas(8) LinkHeapTemplate : public LinkHeapBase {
        TLock m_Lock;
    
    public:
        LinkHeapTemplate(const char* name) : LinkHeapBase{ name } {}

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void* Alloc(size_t in_size, size_t in_alignment) override;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) override;
        virtual void Free(void* in_pMemory) override;
    };
}
