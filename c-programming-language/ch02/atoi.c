/**
 * @file atoi.c
 * @author your name (you@domain.com)
 * @brief 将字符串s转换成整数
 * @version 0.1
 * @date 2022-02-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int atoi(char s[]);

int main(void)
{
    char s[10];

    scanf("%s", s);
    printf("%d\n", atoi(s));
}

int atoi(char s[])
{
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
        n = 10 * n + (s[i] - '0');

    return n;
}

/**
 * @brief 转换成小写字母
 *
 * @param c
 * @return int  整数
 */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
