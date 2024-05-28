#pragma once

namespace hh::fnd
{
	class HandleBase
	{
	protected:
		uint32_t handle;

		void Set(const RefByHandleObject* pObj);
		RefByHandleObject* Get(HandleManagerBase* handleManager) const;
		
	public:
		HandleBase()
		{
			
		}
		
		HandleBase(const RefByHandleObject* pObj)
		{
			Set(pObj);
		}

		bool operator==(const RefByHandleObject* pObj)
		{
			return handle == pObj->handle;
		}

		bool operator!=(const RefByHandleObject* pObj)
		{
			return !operator==(pObj);
		}

		HandleBase& operator=(const RefByHandleObject* pObj)
		{
			Set(pObj);
			return *this;
		}

		HandleBase& operator=(const HandleBase& hObj)
		{
			handle = hObj.handle;
			return *this;
		}
	};

    //hh::fnd::Handle<hh::fnd::Messenger,hh::fnd::HandleManager<hh::fnd::Messenger>>
	template<typename T, typename M = HandleManager<T>>
	class Handle : public HandleBase
	{
	public:
		Handle()
		{
			
		}

		Handle(const T* pObj) : HandleBase(pObj)
		{
			
		}


		Handle<T, M>& operator=(T* pObj)
		{
			Set(pObj);
			return *this;
		}

		Handle<T, M>& operator=(const Handle<T, M>& hObj)
		{
			handle = hObj.handle;
			return *this;
		}

		T* operator*() const
		{
			return reinterpret_cast<T*>(HandleBase::Get(RESOLVE_STATIC_VARIABLE(HandleManager<T>::instance)));
		}

		operator T*() const
		{
			return operator*();
		}

		T* operator->() const
		{
			return operator*();
		}
	};
}
