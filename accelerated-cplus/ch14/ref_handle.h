#ifndef GUARD_ref_handle_h
#define GUARD_ref_handle_h
/**
 * @file ref_handle.h
 * @author your name (you@domain.com)
 * @brief 第二版本从来不会真正地复制底层对象。
 * @version 0.1
 * @date 2022-06-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdexcept>

template <class T>
class Ref_handle
{
public:
    // 因为是指针，所以用 new
    Ref_handle() : reptr(new size_t(1)), p(0) {}
    Ref_handle(T *t) : reptr(new size_t(1)), p(t) {}
    Ref_handle(const Ref_handle &h) : refptr(h.refptr), p(h.p)
    {
        ++*refptr;
    }
    Ref_handle &operator=(const Ref_handle &);
    ~Ref_handle();

    operator bool() const { return p; }
    T &operator* const
    {
        if (p)
            return *p;
        throw std::runtime_error("unbound Ref_handle")
    }
    T *operator->const
    {
        if (p)
            return p;
        throw std::runtime_error("unbound Ref_handle")
    }

private:
    // 指针才能共享
    T *p;
    sizt_t *refptr;
};

template <class T>
Ref_handle<T> &Ref_handle<T>::operator=(const Ref_handle &rhs)
{
    ++*rhs.refptr;
    // 释放左边操作数对象，如果必要的话删除指针
    if (--*refptr == 0)
    {
        delete refptr;
        delete p;
    }
    refptr = rhs.refptr;
    p = rhs.p;
    return *this;
}

template <class T>
Ref_handle<T>::~Ref_handle()
{
    if (--*refptr == 0)
    {
        delete refptr;
        delete p;
    }
}

#endif