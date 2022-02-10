#include <stdio.h>

// 最大输入行的大小
#define MAXLINE 1000

int mygetline(char line[], int maxline);

void copy(char to[], char from[]);

/**
 * @brief 打印最长的行
 *
 */
main()
{
    // 当前行长度
    int len;
    // 当前最长行长度
    int max;
    // 当前行
    char line[MAXLINE];
    // 当前最长行
    char longest[MAXLINE];

    max = 0;
    while ((len = mygetline(line, MAXLINE)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }

    if (max > 0)
        printf("%s\n", longest);
}

/**
 * @brief  从输入中获取一行，并将内容写入 line
 *
 * @param s      当前行内容
 * @param lim    数组长度限制  MAXLINE
 * @return int   当前行长度
 */
int mygetline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if (c == '\n')
    {
        // 补充 \n
        s[i] = 'c';
        ++i;
    }
    // 字符数组结尾
    s[i] = '\0';
    return i;
}

/**
 * @brief   复制
 *
 * @param to
 * @param from
 * @return
 */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}