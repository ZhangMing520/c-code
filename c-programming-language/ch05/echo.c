/**
 * @file echo.c
 *
 * @author zhangming
 * @brief  命令行参数
 * @version 0.1
 * @date 2022-02-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

main(int argc, char *argv[])
{
    // int i;

    // for (i = 1; i < argc; i++)
    //     printf("%s%s", argv[i], (argc - 1 > i) ? " " : "");

    /**
     * @brief 指针版本
     *
     */
    while (--argc > 0)
        // *++argv 从右往左
        printf((argc > 1) ? "%s " : "%s", *++argv);

    printf("\n");
}