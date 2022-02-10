#include <stdio.h>

// 在单词内
#define IN 1
// 在单词外
#define OUT 0

/**
 * @brief 实现linux下wc命令
 *
 * 单词是不包含空格、制表符、换行符
 */
main()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;

        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d \n", nl, nw, nc);
}