/**
 * @file escape.c
 * @author your name (you@domain.com)
 * @brief 使用转义字符
 * @version 0.1
 * @date 2022-02-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
    float salary;
    printf("\aEnter you desired monthly salary:");
    printf("$________\b\b\b\b\b\b\b");
    scanf("%f", &salary);
    printf("\n\t$%.f a month is $%.2f a year.", salary, salary * 12.0);
    // \r 使光标移动到当前行起始位置
    printf("\rGee!\n");

    return 0;
}