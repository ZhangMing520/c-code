/**
 * @file showf_pt.c
 * @author your name (you@domain.com)
 * @brief 打印浮点数  e/E
 * @version 0.1
 * @date 2022-02-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
    float aboat = 32000.0;
    double abet = 2.14e9;
    long double dip = 5.32e-5;

//     32000.000000 can be written 3.200000e+04
// 2140000000.000000 can be written 2.140000e+09
// 0.000000 can be written 5.320000e-05
    printf("%f can be written %e\n", aboat, aboat);
    printf("%f can be written %e\n", abet, abet);
    // 源代码中的e在本机器中不适合 应该是Le
    printf("%f can be written %Le\n", dip, dip);
    return 0;
}