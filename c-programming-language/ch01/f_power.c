#include <stdio.h>

int power(int m, int n);

/**
 * @brief c语言中的函数，实现 pow
 * 
 * 返回值类型   函数名(可能有的参数说明)
 * {
 *      声明序列
 *      语句序列
 * }
 *
 */
main()
{
    int i;

    for (i = 0; i < 10; i++)
    {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }
}

/**
 * @brief 求base的n次幂，只能适用于小数，非实用
 * @param base
 * @param n
 * @return int
 */
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 0; i < n; i++)
    {
        p = p * base;
    }
    return p;
}