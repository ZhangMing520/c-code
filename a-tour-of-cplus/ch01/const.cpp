#include <iostream>
#include <vector>

using std::vector;

// const sum不会更改参数的值
double sum(const vector<double> &);

int main()
{
    vector<double> v{1.2, 3.4, 5.6};
    // 正确：sum(v)在运行时求值
    const double s1 = sum(v);
    // 错误：sum(v)不是常量表达式
    constexpr double s2 = sum(v);
    return 0;
}

/**
 * @brief   constexpr 函数必须非常简单、无副作用且仅使用通过参数传递的信息。
 *      特别是，函数不能更改非局部变量，但可以包含循环以及使用自己的局部变量。
 *
 * @param x
 * @param n
 * @return constexpr double
 */
constexpr double nth(double x, int n)
{
    double res = 1;
    int i = 0;
    while (i < n)
    {
        res *= x;
        ++i;
    }
    return res;
}