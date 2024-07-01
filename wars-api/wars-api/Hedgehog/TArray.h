#pragma once

namespace hh
{
	// Actually second param with allocator
	template<typename T>
	class TArray
	{
	protected:
		T* m_pBuffer{};
		size_t m_length{};
		int64_t m_capacity{};

		T* get(size_t i) const
		{
			if (!this->m_pBuffer)
				return nullptr;

			return &this->m_pBuffer[i];
		}

		bool isUninitialized()
		{
			return this->m_capacity & csl::ut::SIGN_BIT;
		}

	public:
		void reserve(size_t len)
		{
			// We already have enough reserved, return
			if (len <= this->capacity())
				return;

			// Allocate a new m_pBuffer with the appropriate reserved storage
			T* new_buffer = static_cast<T*>(hh::fnd::MemoryRouter::GetDebugAllocator()->Alloc(sizeof(T) * len, 16));

			if (this->m_pBuffer)
			{
				//memcpy(new_buffer, this->m_pBufferizeof(T) * this->m_length);
				for (size_t i = 0; i < this->m_length; i++) {
					new (&new_buffer[i]) T(std::move(this->m_pBuffer[i]));
					this->m_pBuffer[i].~T();
				}
			}

			// Free our old m_pBuffer
			if (!isUninitialized())
			{
				hh::fnd::MemoryRouter::GetDebugAllocator()->Free(this->m_pBuffer);
			}

			// Assign our new m_pBuffer and set the new m_capacity
			this->m_capacity = len;
			this->m_pBuffer = new_buffer;
		}

	public:
		TArray() : m_capacity{ csl::ut::SIGN_BIT }
		{
		}

		TArray(size_t in_capacity) : TArray{}
		{
			reserve(in_capacity);
		}

		TArray(const TArray<T>& other) : TArray<T>{ other.m_capacity } {
			for (T& x : other) {
				this->push_back(x);
			}
		}

		TArray(TArray<T>&& other) : TArray<T>{} {
			this->m_pBuffer = other.m_pBuffer;
			this->m_length = other.m_length;
			this->m_capacity = other.m_capacity;
			other.m_pBuffer = nullptr;
			other.m_length = 0;
			other.m_capacity = csl::ut::SIGN_BIT;
		}

		~TArray()
		{
			for (size_t i = 0; i < this->m_length; i++) {
				this->m_pBuffer[i].~T();
			}

			if (!isUninitialized())
				hh::fnd::MemoryRouter::GetDebugAllocator()->Free(this->m_pBuffer);
		}

		TArray<T>& operator=(TArray<T>&& other) {
			for (size_t i = 0; i < this->m_length; i++) {
				this->m_pBuffer[i].~T();
			}

			if (!isUninitialized())
				hh::fnd::MemoryRouter::GetDebugAllocator()->Free(this->m_pBuffer);

			this->m_pBuffer = other.m_pBuffer;
			this->m_length = other.m_length;
			this->m_capacity = other.m_capacity;
			other.m_pBuffer = nullptr;
			other.m_length = 0;
			other.m_capacity = csl::ut::SIGN_BIT;

			return *this;
		}

		void push_back(const T& item)
		{
			if (this->m_length + 1 > this->capacity())
			{
				reserve((this->m_length + 1) * 2);
			}

			this->m_length++;
			new (&this->m_pBuffer[this->m_length - 1]) T(item);
		}

		void push_back(T&& item)
		{
			if (this->m_length + 1 > this->capacity())
			{
				reserve((this->m_length + 1) * 2);
			}

			this->m_length++;
			new (&this->m_pBuffer[this->m_length - 1]) T(std::move(item));
		}

		void push_back_unchecked(const T& item)
		{
			this->m_length++;
			new (&this->m_pBuffer[this->m_length - 1]) T(item);
		}

		void push_back_unchecked(T&& item)
		{
			this->m_length++;
			new (&this->m_pBuffer[this->m_length - 1]) T(std::move(item));
		}

		void remove(size_t i)
		{
			if (i >= this->m_length)
				return;

			this->m_pBuffer[i].~T();

			for (size_t j = i + 1; j < this->m_length; j++)
				this->m_pBuffer[j - 1] = std::move(this->m_pBuffer[j]);

			this->m_length--;
		}

		bool empty()
		{
			return this->m_length == 0;
		}

		void clear()
		{
			if (!empty()) {
				for (size_t i = 0; i < this->m_length; i++) {
					this->m_pBuffer[i].~T();
				}
				this->m_length = 0;
			}
		}

		void swap(TArray<T>& rOldArray)
		{
			auto* tempBuffer = this->m_pBuffer;
			auto tempLen = this->m_length;
			auto tempCap = this->m_capacity;

			this->m_pBuffer = rOldArray.m_pBuffer;
			this->m_length = rOldArray.m_length;
			this->m_capacity = rOldArray.m_capacity;

			rOldArray.m_pBuffer = tempBuffer;
			rOldArray.m_length = tempLen;
			rOldArray.m_capacity = tempCap;
		}

		template<typename U>
		size_t find(const U& item) const
		{
			for (size_t i = 0; i < this->m_length; i++)
			{
				if (*this->get(i) == item)
					return i;
			}

			return -1;
		}

		const T& operator[] (size_t i) const
		{
			return *this->get(i);
		}

		T& operator[] (size_t i)
		{
			return *this->get(i);
		}
		
	public:
		[[nodiscard]] T* begin() const { return get(0); }

		[[nodiscard]] T* end() const { return get(this->m_length); }

		[[nodiscard]] T front() const { return *get(0); }

		[[nodiscard]] size_t size() const
		{
			return this->m_length;
		}

		[[nodiscard]] size_t capacity() const
		{
			return this->m_capacity & ~csl::ut::SIGN_BIT;
		}
	};
}
