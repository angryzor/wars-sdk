#pragma once

namespace hh::fnd
{
	template<typename T>
	class Reference {
		T* ptr{ nullptr };
	public:
		Reference() {
		}

		Reference(Reference& other) {
			*this = other;
		}

		Reference(Reference&& other) {
			ptr = other.ptr;
			other.ptr = nullptr;
		}

		Reference(T* rawPtr) {
			if (rawPtr != nullptr)
				rawPtr->Acquire();

			ptr = rawPtr;
		}

		~Reference() {
			if (ptr != nullptr)
				ptr->Release();
		}

		inline Reference<T>& operator=(T* const other) {
			T* old = ptr;

			if (other != nullptr)
				other->Acquire();

			ptr = other;

			if (old != nullptr)
				old->Release();

			return *this;
		}

		inline Reference<T>& operator=(const Reference<T>& other) {
			*this = other.ptr;
			return *this;
		}

		inline Reference<T>& operator=(Reference<T>&& other) {
			T* old = ptr;

			ptr = other.ptr;
			other.ptr = nullptr;

			if (old != nullptr)
				old->Release();

			return *this;
		}

		inline T& operator*() const {
			return *ptr;
		}

		inline T* operator->() const {
			return ptr;
		}

		inline operator T&() const {
			return *ptr;
		}

		inline operator T*() const {
			return ptr;
		}

		inline bool operator==(const Reference<T>& other) const {
			return ptr == other.ptr;
		}

		inline bool operator==(T* const other) const {
			return ptr == other;
		}
	};

	class alignas(8) ReferencedObject : public BaseObject
	{
		uint32_t sizeAndInitialized;
		volatile long RefCount{};

	private:
		static ReferencedObject* Allocate(size_t size, csl::fnd::IAllocator* allocator);
		void Free();
	
	protected:
		csl::fnd::IAllocator* pAllocator;
		
	public:
		ReferencedObject();

		inline void Acquire() {
			if (sizeAndInitialized >= 2) {
				InterlockedExchangeAdd(&RefCount, 1);
			}
		}

		inline void Release();

		csl::fnd::IAllocator* GetAllocator() const
		{
			return pAllocator;
		}


		static void* operator new(size_t count, void* ptr) {
			return ptr;
		}

		static void operator delete(void* ptr, void* place) noexcept {
		}

		static void* operator new(size_t count, csl::fnd::IAllocator* pAllocator) {
			return Allocate(count, pAllocator);
		}

		static void operator delete(void* ptr, csl::fnd::IAllocator* pAllocator) noexcept {
			pAllocator->Free(ptr);
		}

		static void* operator new(size_t count, std::align_val_t al, csl::fnd::IAllocator* pAllocator) {
			return Allocate(count, pAllocator);
		}

		static void operator delete(void* ptr, std::align_val_t al, csl::fnd::IAllocator* pAllocator) noexcept {
			pAllocator->Free(ptr);
		}

		static void operator delete(void* ptr, size_t size) noexcept {
			static_cast<hh::fnd::ReferencedObject*>(ptr)->Free();
		}
	};
}
