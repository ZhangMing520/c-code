/**
 * @file print2.c
 * @author your name (you@domain.com)
 * @brief   打印 short、long、long long、unsigned   %hd显示short整数
 * @version 0.1
 * @date 2022-02-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
    unsigned int un = 3000000000;
    short end = 200;
    long big = 65537;
    long long verybig = 12345678908642;

    //     un = 3000000000 and not -1294967296
    // end = 200 and  200
    // big = 65537 and not 1
    // verybig = 12345678908642 and not 12345678908642
    printf("un = %u and not %d\n", un, un);
    printf("end = %hd and  %d\n", end, end);
    printf("big = %ld and not %hd\n", big, big);
    // %ld显示long int，在本人电脑上是64位，效果没显示出来，换成%d即可
    printf("verybig = %lld and not %ld\n", verybig, verybig);
    return 0;
}