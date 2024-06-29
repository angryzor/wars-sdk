#pragma once

namespace hh::fnd
{
	class PooledAllocatorBase : public csl::fnd::IAllocator
	{
	private:
		csl::fnd::IAllocator* pAllocator;
		void* pBuffer;
		csl::fnd::LinkHeapBase* pHeap;
        csl::fnd::FreeListHeapTemplate<csl::fnd::DummyLock> freeListHeap;
		csl::fnd::PoolHeapTemplate<csl::fnd::DummyLock>* poolHeaps;
		uint32_t numPoolHeaps;
		csl::fnd::HeapBase** unkHeap;

	public:
		PooledAllocatorBase(csl::fnd::LinkHeapBase* heap);
	};

	class ThreadSafePooledAllocator : public PooledAllocatorBase
	{
		void SetupInternal(csl::fnd::IAllocator* memoryRouterAllocator, size_t memorySize, void* unkParam1, unsigned int numPoolHeaps, bool unkParam3, unsigned int unkParam4);
	public:
        csl::fnd::LinkHeapTemplate<csl::fnd::Mutex> heap;

		ThreadSafePooledAllocator(const char* name) : PooledAllocatorBase{ &heap }, heap{ name } { }
		void Setup(csl::fnd::IAllocator* memoryRouterAllocator, size_t memorySize, void* unkParam1, unsigned int numPoolHeaps, bool unkParam3);
		void SetName(const char* name);
		virtual void* Alloc(size_t in_size, size_t in_alignment) override;
		virtual void Free(void* in_pMemory) override;
	};
}
