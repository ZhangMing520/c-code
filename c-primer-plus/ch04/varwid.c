/**
 * @file varwid.c
 * @author your name (you@domain.com)
 * @brief printf f* 使用可变宽度输出字段；宽度不是直接指定，而是通过传递参数
 * @version 0.1
 * @date 2022-02-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
    unsigned width, precision;
    int number = 256;
    double weight = 242.5;

// What field width?
// 6
// The number is:    256
// Now enter a width and a pricision:
// 8 3 
// Weight =  242.500

    printf("What field width?\n");
    scanf("%d", &width);
    // width 替代 * 指定字宽
    printf("The number is: %*d\n", width, number);

    printf("Now enter a width and a pricision:\n");
    scanf("%d %d", &width, &precision);
    printf("Weight = %*.*f\n", width, precision, weight);

    return 0;
}