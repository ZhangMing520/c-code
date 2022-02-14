/**
 * @file exercise02.c
 * @author your name (you@domain.com)
 * @brief printf 输出小练习，指定输出格式，填写输出说明符
 * @version 0.1
 * @date 2022-02-14
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

#define BOOK "War and Peace"

int main(void)
{
    float cost = 12.99;
    float percent = 80.0;

    printf("This copy of \"War and Peace\" sells fro $%.2f\n", cost);
    printf("That is %.0f%% of list.\n", percent);
    return 0;
}