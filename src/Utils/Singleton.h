#ifndef SINGLETON_H
#define SINGLETON_H

#include <string>

template <typename T, typename D = T>
class Singleton
{
    friend D;
    /// TODO: Fix this
    //static_assert(std::is_base_of_v<T, D>, "T should be a base type for D");

public:
    static T& instance()
    {
        static D inst;
        return inst;
    }

private:
    Singleton() = default;;
    ~Singleton() = default;
    Singleton( const Singleton& ) = delete;
    Singleton& operator=( const Singleton& ) = delete;
protected:
    virtual void OnContructorCalled() {};
};

#endif // SINGLETON_H
