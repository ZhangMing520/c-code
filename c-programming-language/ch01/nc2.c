#include <stdio.h>

/**
 * @brief 统计字符个数 for
 *
 * 单个分号叫做空语句
 */
main()
{
    double nc;
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}