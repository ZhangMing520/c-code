/**
 * @file guess.c
 * @author your name (you@domain.com)
 * @brief   用户可能输入各种各样的内容，告诉用于哪里出现了错误
 * @version 0.1
 * @date 2022-02-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
    int guess = 1;
    printf("Pick an integer from 1 to 100. I will try to guess.");
    printf("it.\nRespond with a y if my guess is right and with");
    printf("\nan n if it is wrong.\n");
    printf("Uh... is your number %d?\n", guess);

    while (getchar() != 'y')
    {
        printf("Well, then, is it %d?\n", ++guess);
        while (getchar()!='\n')
        //  只获取第一个，后面的跳过一直到回车
            continue;        
    }
    printf("I knew I could do it!\n");
    return 0;
}