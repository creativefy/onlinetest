 ///
 /// @file    MutexLock.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-05 10:54:08
 ///
 
#include "MutexLock.h"

namespace wd
{

MutexLock::MutexLock()
: _isLocked(false)
{
	pthread_mutex_init(&_mutex, NULL);
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_mutex);
}


void MutexLock::lock()
{
	_isLocked = true;
	pthread_mutex_lock(&_mutex);
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
	_isLocked = false;
}

pthread_mutex_t * MutexLock::getMutexLockPtr()
{	return &_mutex;	}

}// end of namespace wd