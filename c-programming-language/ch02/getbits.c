/**
 * @file getbits.c
 * @author your name (you@domain.com)
 * @brief 获取
 * @version 0.1
 * @date 2022-02-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main(void)
{
    unsigned x;
    int p, n;

    x = 8;
    p = 0, n = 2;
    printf("%d\n", getbits(x, p, n));
}

/**
 * @brief 用于返回x从p位置开始（右对齐的）n位的值
 *
 * @param x
 * @param p
 * @param n
 * @return unsigned
 */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & (~0 << n);
}