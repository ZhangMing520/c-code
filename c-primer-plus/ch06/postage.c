/**
 * @file postage.c
 * @author your name (you@domain.com)
 * @brief 逗号运算符
 * @version 0.1
 * @date 2022-02-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
    const int FIRST_OZ = 37;
    const int NEXT_OZ = 37;
    int ounces, cost;

    printf(" ounces cost\n");
    for (ounces = 1, cost = FIRST_OZ; ounces < 16; ounces++, cost += NEXT_OZ)
        printf("%5d $%4.2f\n", ounces, cost / 100.0);

    return 0;
}