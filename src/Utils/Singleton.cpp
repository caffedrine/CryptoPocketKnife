#include "Singleton.h"

template <typename T, typename D>
T& Singleton<T, D>::instance()
{
    static D inst;
    return inst;
}
