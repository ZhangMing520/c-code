#include <vector>
#include <stdexcept>
#include <algorithm>

using std::domain_error;
using std::vector;

/**
 * @brief 求中值
 *
 * @param v
 * @return template <class T>
 */
// T 类型参数
template <class T>
T median(vector<T> v)
{
    typedef typename vector<T>::size_type vec_sz;

    vec_sz size = v.size();
    if (size == 0)
        throw domain_error("median of an empty error");

    sort(v.begin(), v.end())

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
        ++beigin;
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
        /* code */
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