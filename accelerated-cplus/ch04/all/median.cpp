#include <stdexcept>
#include <algorithm>
#include "median.h"

using std::domain_error;
using std::vector;

/**
 * @brief 计算一个 vector<double> 类型的变量的中值
 *
 * @param vec   整个 vector 参数都会被复制
 * @return double
 */
double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;

    return size % 2 == 0 ? (vec[mid] + vec[mid + 1]) / 2 : vec[mid];
}
