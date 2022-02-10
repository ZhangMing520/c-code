#include <stdio.h>

/**
 * @brief 替换多个空格为一个空格
 *
 * 空格和TAB是不一样的
 */
main()
{

    int c;
    // 1 表示有空格
    char flag = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            flag = 1;
        }
        else
        {
            // 前面有空格，在不是空格字符之前输出一个空格
            if (flag == 1)
            {
                putchar(' ');
                flag = 0;
            }
            putchar(c);
        }
    }
}