#ifndef GUARD_handle_h
#define GUARD_handle_h
/**
 * @file handle.h
 * @author your name (you@domain.com)
 * @brief 第一版本总是对底层对象进行复制
 * @version 0.1
 * @date 2022-06-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdexcept>

template <class T>
class Handle
{
public:
    Handle() : p(0);
    Handle(const Handle &h) : p(0)
    {
        if (h.p)
            p = h.p->clone();
    }
    Handle &operator=(const Handle &);
    ~Handle() { delete p; }
    Handle(T *t) : p(t) {}

    operator bool() const { return p; }
    T *operator->() const;
    T &operator*() const;

private:
    T *p;
};

template <class T>
Handle<T> &Handle<T>::operator=(const Handle &rhs)
{
    if (&rhs != this)
    {
        delete p;
        p = rhs.p ? rhs.p->clone() : 0;
    }
    return *this;
}

template <class T>
T &Handle<T>::operator*() const
{
    if (p)
        return *p;

    throw std::runtime_error("unbound Handle");
}

template <class T>
T *Handle<T>::operator->() const
{
    if (p)
        return p;

    throw std::runtime_error("unbound Handle");
}

template <class T>
bool compare_core_handles(const Handle<T>& h1, const Handle<T>& h2)
{
    return h1->name() < h2->name()
}

#endif