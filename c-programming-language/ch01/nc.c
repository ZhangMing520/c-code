#include <stdio.h>

/**
 * @brief 统计字符个数 while
 *
 */
main()
{
    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;

    printf("%ld\n", nc);
}