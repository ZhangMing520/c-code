#ifndef GUARD_ptr_h
#define GUARD_ptr_h
/**
 * @file ptr.h
 * @author your name (you@domain.com)
 * @brief 第三版本允许由程序来决定什么时候需要复制目标对象，而什么时候又不需要复制目标对象
 * @version 0.1
 * @date 2022-06-21
 *
 * @copyright Copyright (c) 2022
 *
 */

template <class T>
class Ptr
{
public:
    /**
     * @brief 在需要的时候有条件地赋值对象
     *
     */
    void make_unique()
    {
        if (*refptr != 1)
        {
            --*refptr;
            refptr = new size_t(1);
            p = p ? p->clone() : 0;
        }
    }

    Ptr() : reptr(new size_t(1)), p(0) {}
    Ptr(T *t) : reptr(new size_t(1)), p(t) {}
    Ptr(const Ptr &h) : refptr(h.refptr), p(h.p)
    {
        ++*refptr;
    }
    Ptr &operator=(const Ptr &);
    ~Ptr();

    operator bool() const { return p; }
    T &operator* const
    {
        if (p)
            return *p;
        throw std::runtime_error("unbound Ptr")
    }
    T *operator->const
    {
        if (p)
            return p;
        throw std::runtime_error("unbound Ptr")
    }

private:
    T *p;
    size_t *refptr;
};

#endif