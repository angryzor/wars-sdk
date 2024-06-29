#pragma once

namespace csl::fnd {
    class OptimizedFreeListHeapBase : public HeapBase {
    public:
        class LargeBlock : public FreeListHeapBase {
        public:
            virtual void* GetRuntimeTypeInfo() const override;
        };

    private:

        struct Unk1{
            uint64_t unk1;
            uint64_t unk2;
            uint64_t unk3;
            uint64_t unk4;
            uint64_t unk5;
            uint64_t unk6;
            ut::ListT<Unk1>::Node linkListNode;
        };

        struct Unk2 {
            uint64_t unk1;
            uint64_t unk2;
            uint64_t unk3;
            uint64_t unk4;
            uint64_t unk5;
            ut::ListT<Unk1> list1;
            ut::ListT<Unk1> list2;

            Unk2();
        };

        LargeBlock rootBlock;
        Unk2 blocks[8];
        uint64_t unk1;
        bool initialized;

    public:
        OptimizedFreeListHeapBase(const char* name);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void* Alloc(size_t in_size, size_t in_alignment) override;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) override;
        virtual void Free(void* in_pMemory) override;
        virtual size_t GetBlockSize(void* ptr) const override;
        virtual void CollectHeapInformation(HeapInformation& heapInformation) const override;
        virtual size_t GetBufferTop() const override;
        virtual size_t GetBufferEnd() const override;
        virtual unsigned int GetCurrentAllocateCount() const override;
        virtual unsigned int GetCallAllocateTime() const override;
        virtual bool GetMemorySnapshot(MemorySnapshot& memorySnapshot) const override { return false; }
    };

    template<typename TLock>
    class alignas(8) OptimizedFreeListHeapTemplate : public OptimizedFreeListHeapBase {
        TLock m_Lock;
    
    public:
        OptimizedFreeListHeapTemplate(const char* name) : OptimizedFreeListHeapBase{ name } {}

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void* Alloc(size_t in_size, size_t in_alignment) override;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) override;
        virtual void Free(void* in_pMemory) override;
    };
}
