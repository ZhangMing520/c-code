#include <stdio.h>
// 在单词内
#define IN 1
// 在单词外
#define OUT 0

/**
 * @brief 每行一个单词的形式打印
 *
 */
main()
{
    int c, state;
    state = OUT;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (state == IN)
            {
                putchar('\n');
            }
            state = OUT;
        }
        else
        {
            state = IN;
            putchar(c);
        }
    }
}