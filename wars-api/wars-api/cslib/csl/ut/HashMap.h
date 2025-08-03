#pragma once

namespace csl::ut
{
	template<typename TKey, typename TValue, typename TOp>
	class HashMap
	{
		inline static constexpr size_t INVALID_KEY = static_cast<size_t>(-1);
		
	protected:
		struct Elem
		{
			size_t m_Hash;
			TKey m_Key;
			TValue m_Value;
		};
		
		Elem* m_pElements{};
		size_t m_Length{};
		size_t m_Capacity{};
		size_t m_HashMask{};
		fnd::IAllocator* m_pAllocator{};
		size_t m_OpDummy{};
		
	protected:
		bool isUninitialized() const
		{
			return m_Capacity & csl::ut::SIGN_BIT;
		}

		size_t CalcResize(size_t capacity)
		{
			size_t result;
			for (result = 16; result < capacity; result *= 2);

			if (result < 16)
				result = 16;

			return result;
		}

		Elem* AllocateMemory(size_t count)
		{
			return static_cast<Elem*>(m_pAllocator->Alloc(sizeof(Elem) * count, alignof(Elem)));
		}

		void ReleaseMemory()
		{
			if (!isUninitialized() && m_pAllocator && m_pElements)
			{
				m_pAllocator->Free(m_pElements);
			}
		}
		
		size_t GetCapacity() const
		{
			return m_Capacity & ~csl::ut::SIGN_BIT;
		}

		size_t GetHashMask() const
		{
			return m_HashMask;
		}

		size_t GetHashCapacity() const
		{
			return GetHashMask() + 1;
		}

		void ResizeTbl(size_t capacity)
		{
			size_t oldCap = GetCapacity();
			Elem* oldElements = m_pElements;

			m_Capacity = capacity;
			m_HashMask = capacity - 1;
			m_Length = 0;

			m_pElements = AllocateMemory(capacity);
			memset(m_pElements, -1, sizeof(Elem) * capacity);

			if (oldElements)
			{
				for (size_t i = 0; i < oldCap; i++)
				{
					const Elem* pElem = &oldElements[i];

					if (pElem->m_Hash != INVALID_KEY)
					{
						Insert(pElem->m_Key, pElem->m_Value);
						pElem->m_Value.~TValue();
					}
				}

				if (!isUninitialized() && m_pAllocator)
					m_pAllocator->Free(oldElements);
			}
		}

		void Reserve(size_t capacity)
		{
			size_t cap = CalcResize(capacity);
			if (GetCapacity() < cap)
				ResizeTbl(cap);
		}
		
	public:
		HashMap(fnd::IAllocator* pAllocator) : m_Capacity{ csl::ut::SIGN_BIT }
		{
			m_pAllocator = pAllocator;
		}

		HashMap(const HashMap& other) : HashMap{ other.m_pAllocator }
		{
			if (!other.isUninitialized()) {
				reserve(other.m_Capacity);

				for (auto i = other.begin(); i != other.end(); i++)
					Insert(other.GetKey(i), other.GetValue(i));
			}
		}

		HashMap(HashMap&& other) : HashMap{ other.m_pAllocator }
		{
			m_pElements = other.m_pElements;
			m_Length = other.m_Length;
			m_Capacity = other.m_Capacity;
			m_HashMask = other.m_HashMask;
			other.m_pElements = nullptr;
			other.m_Length = 0;
			other.m_Capacity = csl::ut::SIGN_BIT;
			other.m_HashMask = 0;
		}

		void reserve(size_t capacity)
		{
			Reserve(capacity);
		}

		size_t size() {
			return m_Length;
		}

		~HashMap()
		{
			if (!isUninitialized())
			{
				for (size_t i = 0; i < GetHashCapacity(); i++)
				{
					const Elem& pElem = m_pElements[i];
					if (pElem.m_Hash != INVALID_KEY)
						pElem.m_Value.~TValue();
				}
			}

			ReleaseMemory();
			m_Length = 0;
			m_Capacity = 0;
			m_HashMask = 0;
			m_pElements = nullptr;
		}
		
	protected:
		size_t GetBegin() const
		{
			if (m_Length > 0) {
				for (size_t i = 0; i < GetHashCapacity(); i++)
				{
					if (m_pElements[i].m_Hash != INVALID_KEY)
						return i;
				}
			}
			
			return GetHashCapacity();
		}

		size_t GetNext(size_t idx) const
		{
			for (size_t i = idx + 1; i < GetHashCapacity(); i++)
			{
				if (m_pElements[i].m_Hash != INVALID_KEY)
					return i;
			}

			return GetHashCapacity();
		}
		
	public:
		struct iterator
		{
			const HashMap* m_pOwner;
			size_t m_CurIdx;

			friend bool operator==(const iterator& a, const iterator& b) { return a.m_CurIdx == b.m_CurIdx; }
			friend bool operator!=(const iterator& a, const iterator& b) { return a.m_CurIdx != b.m_CurIdx; }

			iterator& operator++() { m_CurIdx = m_pOwner->GetNext(m_CurIdx); return *this; }
			iterator operator++(int) { iterator tmp = *this; m_CurIdx = m_pOwner->GetNext(m_CurIdx); return tmp; }

			TKey& key() const
			{
				return m_pOwner->GetKey(*this);
			}

			TValue& operator*() const
			{
				return m_pOwner->GetValue(*this);
			}

			TValue* operator->() const
			{
				return &operator*();
			}

			operator TValue& ()
			{
				return operator*();
			}
		};

		iterator begin() const
		{
			return iterator{ this, GetBegin() };
		}

		iterator end() const
		{
			return iterator{ this, GetHashCapacity() };
		}

		void clear()
		{
			if (m_Length == 0)
				return;

			m_Length = 0;
			for (size_t i = 0; i < GetHashCapacity(); ++i)
			{
				auto& element = m_pElements[i];
				
				if (element.m_Hash != INVALID_KEY)
					element.m_Value.~TValue();

				element.m_Hash = INVALID_KEY;
			}
		}

		iterator InsertAndGet(TKey key, TValue value)
		{
			size_t hash = TOp::hash(key) & 0x7FFFFFFFFFFFFFFF;
			if (m_Length || GetCapacity())
			{
				if (2 * m_Length > GetHashMask())
				{
					ResizeTbl(2 * GetHashCapacity());
				}
			}
			else
			{
				ResizeTbl(CalcResize(GetHashCapacity()));
			}

			size_t idx = hash & GetHashMask();
			Elem* pElem = &m_pElements[idx];

			if (pElem->m_Hash == INVALID_KEY)
			{
				pElem->m_Hash = hash;
				pElem->m_Key = key;
				m_Length++;
			}
			else
			{
				while (pElem->m_Hash != hash || pElem->m_Key != key)
				{
					idx = (idx + 1) & GetHashMask();
					pElem = &m_pElements[idx];

					if (pElem->m_Hash == INVALID_KEY)
					{
						pElem->m_Hash = hash;
						pElem->m_Key = key;
						m_Length++;
						break;
					}
				}
			}

			new (&pElem->m_Value) TValue(value);

			return { this, idx };
		}

		void Insert(TKey key, TValue value)
		{
			InsertAndGet(key, value);
		}

		TValue& GetValueOrFallback(const TKey& key, TValue&& fallback) const {
			auto result = Find(key);

			if (result == end())
				return fallback;

			return GetValue(result);
		}

		iterator Find(const TKey& key) const
		{
			if (!m_pElements)
				return end();
			
			const size_t hash = TOp::hash(key) & 0x7FFFFFFFFFFFFFFF;
			size_t idx = hash & GetHashMask();
			const Elem* pElem = &m_pElements[idx];
			
			if (pElem->m_Hash == INVALID_KEY)
				return end();
			
			while (pElem->m_Hash != hash || !TOp::compare(key, pElem->m_Key))
			{
				idx = (idx + 1) & GetHashMask();
				pElem = &m_pElements[idx];

				if (pElem->m_Hash == INVALID_KEY)
					return end();
			}

			return iterator{ this, idx };
		}

		TKey& GetKey(const iterator& iter) const
		{
			return iter.m_pOwner->m_pElements[iter.m_CurIdx].m_Key;
		}
		
		TValue& GetValue(const iterator& iter) const
		{
			return iter.m_pOwner->m_pElements[iter.m_CurIdx].m_Value;
		}
		
		void Erase(const TKey& key)
		{
			Erase(Find(key));
		}

		void Erase(const iterator& iter)
		{
			if (iter == end())
				return;

			Elem* pElem = &m_pElements[iter.m_CurIdx];
			pElem->m_Hash = INVALID_KEY;
			m_Length--;

			pElem->m_Value.~TValue();

			size_t prev = iter.m_CurIdx;
			for (size_t i = (iter.m_CurIdx + 1) & GetHashMask(); m_pElements[i].m_Hash != INVALID_KEY; i = (i + 1) & GetHashMask()) {
				m_pElements[prev] = std::move(m_pElements[i]);
				m_pElements[i].m_Hash = INVALID_KEY;
				prev = i;
			}
		}
	};
}