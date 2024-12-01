#pragma once

#define GAMESERVICE_CLASS_DECLARATION(ClassName) private:\
		static const hh::game::GameServiceClass gameServiceClass;\
		ClassName();\
		static hh::game::GameService* Create(csl::fnd::IAllocator* allocator);\
	public:\
		static const hh::game::GameServiceClass* GetClass();

#define GAMESERVICE_CLASS_DECLARATION_INLINE_GETCLASS(ClassName) private:\
		static const hh::game::GameServiceClass gameServiceClass;\
		ClassName();\
		static hh::game::GameService* Create(csl::fnd::IAllocator* allocator);\
	public:\
		inline static const hh::game::GameServiceClass* GetClass() {\
			return &RESOLVE_STATIC_VARIABLE(gameServiceClass);\
		}

namespace hh::game
{
	class GameManager;
	class GameService;

	class alignas(8) GameServiceClass
	{
	public:
		typedef GameService* CreateFunction(csl::fnd::IAllocator* allocator);

		const char* name;
		CreateFunction* instantiator;
		void* unk2{};

		GameServiceClass(const char* name, CreateFunction* instantiator, void* unk2) : name{ name }, instantiator{ instantiator }, unk2{ unk2 } {}
	};
	
	class alignas(8) GameService : public hh::fnd::ReferencedObject, public hh::fnd::Messenger
	{
	public:
		GameManager* gameManager;
		GameServiceClass* staticClass;
		uint64_t unk001;
		uint64_t unk002;
		uint32_t unk003;
		uint64_t unk004;

		GameService();

		virtual void* GetRuntimeTypeInfo();
		virtual void OnAddedToGame() {}
		virtual void OnRemovedFromGame() {}
		virtual void Update(const fnd::SUpdateInfo& updateInfo) {}
	};
}
