#pragma once

namespace csl::ut
{
	template<typename TKey>
	class PointerMapOperation
	{
	public:
		inline static size_t hash(TKey key)
		{
			return 0x9E3779B1 * (size_t)key;
		}

		inline static bool compare(const TKey& key, const TKey& other)
		{
			return key == other;
		}
	};

	template<typename TKey, typename TValue>
	class PointerMap : public HashMap<TKey, TValue, PointerMapOperation<TKey>> {};
}
