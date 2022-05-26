/**
 * @file echo.c
 * @author your name (you@domain.com)
 * @brief getchar putchar 回显
 * @version 0.1
 * @date 2022-02-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
    int ch;
    while ((ch = getchar()) != EOF)
        putchar(ch);

    return 0;
}