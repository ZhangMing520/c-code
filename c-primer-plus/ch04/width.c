/**
 * @file width.c
 * @author your name (you@domain.com)
 * @brief printf 宽度修饰符     printf "%.2d\n" 1 -> 01  printf "%.2s\n" "hello" -> he
 * @version 0.1
 * @date 2022-02-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

#define PAGES 931

int main(void)
{

// *931*
// *931*
// *       931*
// *931       *

    printf("*%d*\n", PAGES);
    printf("*%2d*\n", PAGES);
    // %010d 前面是0而不是空格
    printf("*%10d*\n", PAGES);
    printf("*%-10d*\n", PAGES);

    return 0;
}