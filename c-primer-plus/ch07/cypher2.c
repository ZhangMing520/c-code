/**
 * @file cypher2.c
 * @author your name (you@domain.com)
 * @brief 改变输入，只保留非字母字符
 * @version 0.1
 * @date 2022-02-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;

    while ((ch = getchar()) != '\n')
    {
        if (isalpha(ch))
            // 改变它
            putchar(ch + 1);
        else
            // 原样打印
            putchar(ch);
    }
    putchar(ch);
    return 0;
}