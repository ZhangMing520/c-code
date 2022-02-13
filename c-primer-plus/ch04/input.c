/**
 * @file input.c
 * @author your name (you@domain.com)
 * @brief scanf 什么情况下使用&，基本类型使用& 数组不需要使用&
 * @version 0.1
 * @date 2022-02-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
    int age;
    float assets;
    char pet[30];
    char ch;

    printf("Enter you age, assets, and favorite pet.\n");
    // scanf("%d,%f", &age, &assets);    -> 29,  2222222 dog  格式字符串中逗号紧跟在%d后面，所以29必须紧跟一个逗号
    // 29 2222222 dog
    scanf("%d, %f", &age, &assets);
    scanf("%s", pet);
    printf("%d $%.2f %s\n", age, assets, pet);

    scanf(" %c", &ch);
    printf("*%c*\n", ch);
    // 下列最终读取了\n
    scanf("%c", &ch);
    printf("*%c*\n", ch);

    return 0;
}