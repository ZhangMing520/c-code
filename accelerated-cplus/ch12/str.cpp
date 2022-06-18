#include "str.h"

using std::istream;
using std::ostream;

istream &operator>>(istream &is, Str &s)
{
    s.data.clear();

    char c;
    // 忽略空白字符
    while (is.get(c) && isspace(c))
        ;
    if (is)
    {
        do
            s.data.push_back(c);
        while (is.get(c) && !isspace(c));
    }
    return is;
}

ostream &operator<<(ostream &os, Str &s)
{
    for (Str::size_type i = 0; i != s.size(); i++)
    {
        os << s[i];
    }
    return os;
}

Str operator+(const Str &s, const Str &t)
{
    Str r = s;
    r += t;
    return r;
}