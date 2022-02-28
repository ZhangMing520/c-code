/**
 * @file cmpflt.c
 * @author your name (you@domain.com)
 * @brief 比较浮点数，浮点数比较中只能使用> <
 * @version 0.1
 * @date 2022-02-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <math.h>
#include <stdio.h>

int main(void)
{
    const double ANSWER = 3.14159;
    double response;

    printf("What is the value of pi?\n");
    scanf("%lf", &response);
    // fabs 一个浮点值的绝对值
    while (fabs(response - ANSWER) > 0.0001)
    {
        printf("Try again!\n");
        scanf("%lf", &response);
    }
    printf("Close enough!\n");
    return 0;
}