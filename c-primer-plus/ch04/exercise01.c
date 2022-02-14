/**
 * @file exercise01.c
 * @author your name (you@domain.com)
 * @brief 找错误小练习
 * @version 0.1
 * @date 2022-02-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

// 错误注意 字符串必须用双引号
#define B "booboo"
#define X 10

int main(void)
{
    int age, xp;
    char name[30];

    printf("Please enter your first name:");
    // 错误注意 name 必须声明成数组或者指针
    scanf("%s", name);
    printf("All right, %s, what's you age?\n", name);
    scanf("%d", &age);
    // 错误注意 必须先声明
    xp = age + X;
    printf("That's a %s! You must be at least %d.\n", B, xp);

    return 0;
}