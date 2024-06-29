#pragma once

namespace csl::fnd {
    struct HeapBlock {

    };

    struct MemorySnapshot {
        IAllocator* allocator;
        void* unk1;
        void* unk2;
        uint32_t unk3;

        MemorySnapshot(csl::fnd::IAllocator* allocator);
        virtual ~MemorySnapshot();
    };

    struct HeapInformation {
        struct FreeSizeInformation {
            size_t totalFreeSize;
            size_t maxFreeSize;
        };

        unsigned int liveAllocations;
        FreeSizeInformation freeSize;
        size_t bufferSize;
    };

    struct HeapStatistics {
        size_t bufferSize;
        size_t used;
        size_t allocated;
        unsigned int liveAllocations;
        unsigned int totalAllocations;
    };

    class MemoryBlockFunction {
    public:
        virtual void operator()(void* ptr, size_t size) = 0;
    };

    class alignas(8) HeapBase {
        void* unk0;
        char name[10];
        HeapBase* parent;
        csl::ut::ListT<HeapBase> children;
        uint64_t unk8;
        uint64_t unk9;
        bool initialized;
        uint32_t unk11;
        uint16_t unk12;
        bool debugFillOnAlloc;
        bool debugFillOnFree;
        bool debugUnk;
    public:
        HeapBase(const char* name);
        virtual void* GetRuntimeTypeInfo() const;
        virtual ~HeapBase() = default;
        virtual void* Alloc(size_t in_size, size_t in_alignment) = 0;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) = 0;
        virtual void Free(void* in_pMemory) = 0;
        virtual bool IsIn(void* ptr) const = 0;
        virtual size_t GetBlockSize(void* ptr) const = 0;
        virtual void CollectHeapInformation(HeapInformation& heapInformation) const = 0;
        virtual size_t GetBufferTop() const = 0;
        virtual size_t GetBufferEnd() const = 0;
        virtual unsigned int GetCurrentAllocateCount() const = 0;
        virtual unsigned int GetCallAllocateTime() const = 0;
        virtual bool CanHaveChild() { return true; }
        virtual void ForEachAllocatedBlock(MemoryBlockFunction& func) {}
        virtual void PrintDebugInformation() {}
        virtual bool GetMemorySnapshot(MemorySnapshot& memorySnapshot) const = 0;
        virtual void SetDebugFillOnAlloc(bool enabled);
        virtual void SetDebugFillOnFree(bool enabled);
        virtual void SetDebugUnk(bool enabled);
        virtual bool CorrectSnapshotFromDebugInformation(MemorySnapshot& memorySnapshot, unsigned int unkParam) const { return false; }

        void SetName(const char* name);
        inline const char* GetName() {
            return name;
        }
        inline HeapBase* GetParent() {
            return parent;
        }

        inline const csl::ut::ListT<HeapBase>& GetChildren() {
            return children;
        }
    };
}
