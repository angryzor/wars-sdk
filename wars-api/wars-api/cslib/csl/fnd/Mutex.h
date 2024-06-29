#pragma once

#ifndef EXPORTING_TYPES
#include "synchapi.h"
#endif

namespace csl::fnd
{	
	class Mutex
	{
		CRITICAL_SECTION m_CriticalSection;

	public:
		Mutex()
		{
			InitializeCriticalSection(&m_CriticalSection);
		}

		~Mutex()
		{
			DeleteCriticalSection(&m_CriticalSection);
		}
		
		void Lock()
		{
			EnterCriticalSection(&m_CriticalSection);
		}

		void Unlock()
		{
			LeaveCriticalSection(&m_CriticalSection);
		}
	};

	class MutexGuard
	{
		Mutex* m_pMutex;

	public:
		MutexGuard(Mutex& rMutex) : m_pMutex(&rMutex)
		{
			m_pMutex->Lock();
		}

		~MutexGuard()
		{
			m_pMutex->Unlock();
		}
	};

	class DummyLock {
	public:
		DummyLock()
		{
		}

		~DummyLock()
		{
		}
		
		void Lock()
		{
		}

		void Unlock()
		{
		}
	};
}
