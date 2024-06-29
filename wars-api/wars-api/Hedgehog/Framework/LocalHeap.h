#pragma once

namespace hh::fw::heap {
    struct SystemMemoryParam {
        size_t unk1;
        size_t systemHeapSize;
        size_t unk3;
        size_t unk4;
        size_t mainHeapSize;
        size_t criSystemHeapSize;
    };

    struct MemoryParam {
    };

    struct HeapDefinition {
        uint32_t id;
        const char* name;
        uint64_t unk2;
        uint64_t heapSize;
    };

    class LocalHeap {
    public:
        csl::ut::InplaceMoveArray<csl::ut::Pair<unsigned int, csl::fnd::HeapBase*>, 8> heaps1;
        csl::ut::InplaceMoveArray<csl::ut::Pair<unsigned int, csl::fnd::HeapBase*>, 8> heaps2;
        csl::ut::InplaceMoveArray<csl::fnd::IAllocator*, 8> debugAllocators;
        csl::fnd::FreeListHeapTemplate<csl::fnd::Mutex> baseHeap;
        fnd::MemoryRouter* memoryRouter;
        static HeapDefinition heapDefs[3];

        LocalHeap();
        void setup(const SystemMemoryParam* systemMemoryParam, const MemoryParam* memoryParam, size_t unkParam);
        fnd::MemoryRouter* GetMemoryRouter();
        static LocalHeap* instance;
    };

    fnd::MemoryRouter* localInitUtilRsdx(const SystemMemoryParam* systemMemoryParam, const MemoryParam* memoryParam, size_t unkParam);
}
