#ifndef GUARD_str_h
#define GUARD_str_h

#include "vec.h"
#include <algorithm>
// 不能使用 string, 不包含 strlen
#include <cstring>
#include <iterator>
#include <iostream>

class Str
{
    friend std::istream &operator>>(std::istream &, Str &);

public:
    typedef Vec<char>::size_type size_type;
    Str() {}
    Str(size_type n, char c) : data(n, c) {}
    Str(const char *cp)
    {
        std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
    }
    template <class In>
    Str(In b, In e)
    {
        std::copy(b, e, std::back_inserter(data));
    }

    size_type size() const { return data.size(); }

    char &operator[](size_type i) { return data[i]; }
    const char &operator[](size_type i) const { return data[i]; }

private:
    Vec<char> data;
};

std::ostream &operator<<(std::ostream &, Str &);
Str operator+(const Str &, const Str &);
Str operator+=(const Str &, const Str &);

#endif