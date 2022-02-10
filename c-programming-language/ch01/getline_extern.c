#include <stdio.h>

// 最大输入行的大小
#define MAXLINE 1000

// 当前最长行长度
int max;
// 当前行
char line[MAXLINE];
// 当前最长行
char longest[MAXLINE];

int mygetline(void);

void copy(void);

/**
 * @brief 打印最长的行，extern 使用外部变量（定义在函数外部），extern使变量的名字在该函数中可见
 *
 */
main()
{
    // 当前行长度
    int len;
    int max;
    extern char longest[];

    max = 0;
    while ((len = mygetline()) > 0)
        if (len > max)
        {
            max = len;
            copy();
        }

    if (max > 0)
        printf("%s\n", longest);
}

/**
 * @brief  从输入中获取一行，并将内容写入 line
 *
 * @return int   当前行长度
 */
int mygetline()
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    if (c == '\n')
    {
        // 补充 \n
        line[i] = 'c';
        ++i;
    }
    // 字符数组结尾
    line[i] = '\0';
    return i;
}

/**
 * @brief   复制
 *
 * @param to
 * @param from
 * @return
 */
void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}