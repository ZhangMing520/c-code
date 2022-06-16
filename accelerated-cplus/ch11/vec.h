#ifndef GUARD_vec_h
#define GUARD_vec_h

#include <memory>
#include <algorithm>

template <class T>
class Vec
{
public:
    // 使用指针作为内部的迭代器类型
    typedef T *iterator;
    typedef const T *const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    ~Vec() { uncreate(); }
    Vec() { create(); }
    explicit Vec(size_type n, const T &val = T()) { create(n, val); }

    Vec(const Vec &v) { create(v.begin(), v.end()); }

    T &operator[](size_type i) { return data[i]; }
    const T &operator[](size_type i) const { return data[i]; }

    Vec &operator=(const Vec &);

    size_type size() const { return avail - data; }
    // 返回迭代器
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return avail; }
    const_iterator end() const { return avail; }

    void push_back(const T &val)
    {
        if (avail == limit)
            grow();

        unchecked_append(val);
    }

private:
    // 首元素
    iterator data;
    // 指向最后一个可获得元素后面的一个元素
    iterator limit;
    // 指向构造匀速末元素后面的一个元素
    iterator avail;

    // 内存分配工具
    // 控制内存分配的对象
    std::allocator<T> alloc;

    void create();
    void create(size_type, const T &);
    void create(const_iterator, const_iterator);

    void uncreate();

    void grow();
    void unchecked_append(const T &);
};

template <class T>
Vec<T> &Vec<T>::operator=(const Vec &rhs)
{
    // 判断是否进行自我赋值
    if (rhs != this)
    {
        // 删除运算符左侧的数组
        uncreate();
        // 从右侧赋值元素到左侧
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template <class T>
void Vec<T>::create()
{
    data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T &val)
{
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
    data = alloc.allocate(j - i);
    avail = limit = std::uninitialized_copy(data, limit, data);
}

template <class T>
void Vec<T>::uncreate()
{
    if (data)
    {
        iterator it = avail;
        while (it != data)
        {
            // 调用析构函数，删除对象中的元素
            alloc.destroy(--it);
        }
        // deallocate 需要一个非零指针作为参数
        // 释放元素内存空间
        alloc.deallocate(data, limit - data);
    }
    // 重置指针
    data = limit = avail = 0;
}

template <class T>
void Vec<T>::grow()
{
    // 为对象分配实际使用的两倍大小的内存空间
    // max 参数必须为同一类型
    size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);
    // 释放原来的空间
    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

template <class T>
void Vec<T>::unchecked_append(const T &val)
{
    alloc.construct(avail++, val);
}

#endif