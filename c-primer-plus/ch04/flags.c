/**
 * @file flags.c
 * @author your name (you@domain.com)
 * @brief printf 格式标志
 * @version 0.1
 * @date 2022-02-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
//     1f 1F 0x1f
// *42** 42**-42*
// *    6**  006**00006**  006*
    printf("%x %X %#x\n", 31, 31, 31);
    printf("*%d**% d**% d*\n", 42, 42, -42);
    // 0 标志和精度说明符同时出现，那么0标志就会被忽略
    printf("*%5d**%5.3d**%05d**%05.3d*\n", 6, 6, 6, 6);

    return 0;
}