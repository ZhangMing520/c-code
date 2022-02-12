/**
 * @file toobig.c
 * @author your name (you@domain.com)
 * @brief 整数太大，超出了整数类型的范围    %u显示unsigned int
 * @version 0.1
 * @date 2022-02-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
    int i = 2147483647;
    unsigned int j = 4294967295;

    // 整数溢出
    // 2147483647 -2147483648 -2147483647
    printf("%d %d %d\n", i, i + 1, i + 2);
    // 4294967295 0 1
    printf("%u %u %u\n", j, j + 1, j + 2);
    return 0;
}
