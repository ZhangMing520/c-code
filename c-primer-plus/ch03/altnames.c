/**
 * @file altnames.c
 * @author your name (you@domain.com)
 * @brief 可移植的整数类型名称  inttypes.h 文件头
 * @version 0.1
 * @date 2022-02-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    // 有符号16位
    int16_t me16;

    me16 = 4593;
    printf("First, assume int16_t is short:");
    printf("me16 = %hd\n", me16);
    printf("Next, let's not make any assumptions.\n");
    printf("Instead, use ad \"macro\" from inttypes.h:");
    printf("me16 = %" PRId16 "\n", me16);

    return 0;
}
