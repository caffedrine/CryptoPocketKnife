#ifndef _QTHREADPOOLEXTENDED_H_
#define _QTHREADPOOLEXTENDED_H_

#include <QThreadPool>

#if !defined(DLL_DECL_SPEC)
#define DLL_DECL_SPEC
#endif

class DLL_DECL_SPEC QThreadPoolExtended: public QThreadPool
{
public:
    QThreadPoolExtended(QObject *parent = nullptr);
    ~QThreadPoolExtended()=default;

    int AvailableThreads();
    int ActiveThreads();

protected:

private:
};

#endif // _QTHREADPOOLEXTENDED_H_