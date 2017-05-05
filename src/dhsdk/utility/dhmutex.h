#ifndef DHMUTEX_H
#define DHMUTEX_H

#ifdef WIN32
#include <windows.h>

class CCSLock
{
public:
	CCSLock(CRITICAL_SECTION& cs):m_cs(cs)
	{
		EnterCriticalSection(&m_cs);
	}

	~CCSLock()
	{
		LeaveCriticalSection(&m_cs);
	}
private:
	CRITICAL_SECTION& m_cs;
};

#else

#include <pthread.h>

#endif

class DHMutex
{
public:
	DHMutex();
	~DHMutex();

	int	Lock();
	int	UnLock();

private:

#ifdef WIN32
	CRITICAL_SECTION m_critclSection;
#else
	pthread_mutex_t m_mutex;
#endif
};

#endif

