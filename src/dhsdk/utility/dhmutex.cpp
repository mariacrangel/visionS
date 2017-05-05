#include "dhmutex.h"

/*DHMutex::DHMutex()
{
#ifndef WIN32
//	pthread_attr_init( &attr );
//	pthread_attr_destroy( &attr );

	pthread_mutexattr_t attr;
//	attr.__mutexkind = PTHREAD_MUTEX_RECURSIVE_NP;
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&m_mutex, &attr);
#else
	InitializeCriticalSection(&m_critclSection);
#endif
}*/

DHMutex::DHMutex()
{
#ifndef WIN32
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
#ifdef LINUX
//	attr.__mutexkind = PTHREAD_MUTEX_RECURSIVE_NP;
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
#endif
	int ret = pthread_mutex_init(&m_mutex, &attr);
//	printf("pthread_mutex_init=%d!\n", ret);
	pthread_mutexattr_destroy(&attr);
#else
	InitializeCriticalSection(&m_critclSection);
#endif
}


DHMutex::~DHMutex()
{
#ifndef WIN32
	pthread_mutex_destroy(&m_mutex);
#else
	DeleteCriticalSection(&m_critclSection);
#endif
}

int DHMutex::Lock()
{
#ifdef WIN32
	EnterCriticalSection(&m_critclSection);
	return 0;
#else
	return pthread_mutex_lock(&m_mutex);
#endif
}

int DHMutex::UnLock()
{
#ifdef WIN32
	LeaveCriticalSection(&m_critclSection);
	return 0;
#else
	return pthread_mutex_unlock(&m_mutex);
#endif
}

