#ifndef GUARD_template_func_h
#define GUARD_template_func_h

#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

/**
 * @brief 求中值
 *
 * @param v
 * @return template <class T>
 */
// T 类型参数
template <class T>
T median(std::vector<T> v)
{
    typedef typename std::vector<T>::size_type vec_sz;

    vec_sz size = v.size();
    if (size == 0)
        throw std::domain_error("median of an empty error");

    sort(v.begin(), v.end());

    vec_sz mid = size / 2;

    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

/**
 * @brief 查找元素位置（顺序只读访问）
 *
 * @tparam In
 * @tparam X
 * @param begin 迭代器开始
 * @param end 迭代器结束
 * @param x 查找的元素
 * @return In
 */
template <class In, class X>
In find(In begin, In end, const X &x)
{
    while (begin != end && *begin != x)
    {
        ++begin;
    }
    return begin;
}

/**
 * @brief （顺序只写访问）
 *
 * @tparam In
 * @tparam Out
 * @param begin
 * @param end
 * @param dest
 * @return Out
 */
template <class In, class Out>
Out copy(In begin, In end, Out dest)
{
    while (begin != end)
    {
        *dest++ = *begin++;
    }
    return dest;
}

/**
 * @brief （顺序读-写访问），一旦我们处理了一个元素，就绝不会再次访问它
 *
 * @tparam For
 * @tparam X
 * @param begin
 * @param end
 * @param x
 * @param y
 */
template <class For, class X>
void replace(For begin, For end, const X &x, const X &y)
{
    while (begin != end)
    {
        if (*begin = x)
            *begin = y;
        ++begin;
    }
}

/**
 * @brief （可逆访问）双向迭代器
 *
 * @tparam Bi
 * @param begin
 * @param end
 */
template <class Bi>
void reverse(Bi begin, Bi end)
{
    while (begin != end)
    {
        --end;
        if (begin != end)
            swap(*begin++, *end);
    }
}

/**
 * @brief （随机访问）
 *
 * @tparam Ran
 * @tparam X
 * @param begin
 * @param end
 * @param x
 * @return true
 * @return false
 */
template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const X &x)
{
    while (begin < end)
    {
        Ran mid = begin + (end - begin) / 2;

        if (x < *mid)
            end = mid;
        else if (*mid < x)
            begin = mid + 1;
        else
            return true;
    }
    return false;
}

bool space(char);
bool not_space(char);

/**
 * @brief 重写后的函数有一个输出迭代器而不是返回一个值
 *
 * @tparam Out
 * @param str
 * @param os
 */
template <class Out>
void split(const std::string &str, Out os)
{
    typedef std::string::const_iterator iter;

    iter i = str.begin();
    while (i != str.end())
    {
        i = find_if(i, str.end(), not_space);

        iter j = find_if(i, str.end(), space);

        if (i != str.end())
            // *os 指示了 os 被连接到的容器的当前位置，因此，我们把值 string(i, j)赋给位于这个位置的元素
            *os++ = std::string(i, j);

        i = j;
    }
}

#endif