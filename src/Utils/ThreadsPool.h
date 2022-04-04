#ifndef _THREADSPOOL_H_
#define _THREADSPOOL_H_

#include "QThreadPoolExtended.h"

class ThreadsPool
{
public:
    ThreadsPool(int max_threads_count = 5);
    ~ThreadsPool() = default;
    QThreadPoolExtended *ThreadsPoolPtr();
protected:

private:
    QThreadPoolExtended threadsPool;
};

#endif // _THREADSPOOL_H_