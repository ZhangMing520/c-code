/**
 * @file typesize.c
 * @author your name (you@domain.com)
 * @brief 输出类型的大小
 * @version 0.1
 * @date 2022-02-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
    printf("Type int has a size of %lu bytes.\n", sizeof(int));
    printf("Type char has a size of %lu bytes.\n", sizeof(char));
    printf("Type long has a size of %lu bytes.\n", sizeof(long));
    printf("Type double has a size of %lu bytes.\n", sizeof(double));

    return 0;
}