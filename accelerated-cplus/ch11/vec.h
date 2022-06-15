#ifndef GUARD_vec_h
#define GUARD_vec_h

template <class T>
class Vec
{
public:
    // 使用指针作为内部的迭代器类型
    typedef T *iterator;
    typedef const T *const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    Vec() { create(); }
    explicit Vec(size_type n, const T &val = T()) { create(n, val); }

    Vec(const Vec &v) { create(v.begin(), v.end()); }

    size_type size() const { return limit - data; }
    T &operator[](size_type i) { return data[i]; }
    const T &operator[](size_type i) const { return data[i]; }

    Vec &operator=(const Vec &);

    // 返回迭代器
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return data; }
    const_iterator end() const { return data; }

private:
    // 首元素
    iterator data;
    // 末元素
    iterator limit;
};


#endif