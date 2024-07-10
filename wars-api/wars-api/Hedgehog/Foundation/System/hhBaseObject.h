#pragma once

#define DEFAULT_CREATE_FUNC(ClassName) public:\
		ClassName();\
		static ClassName* Create(csl::fnd::IAllocator* allocator);

#define CREATE_FUNC(ClassName, ...) public:\
		ClassName(__VA_ARGS__);\
		static ClassName* Create(csl::fnd::IAllocator* allocator, __VA_ARGS__);

namespace hh::fnd
{
	class alignas(8) BaseObject
	{
	public:
		BaseObject() {}
		virtual ~BaseObject() = default;
	};
}
