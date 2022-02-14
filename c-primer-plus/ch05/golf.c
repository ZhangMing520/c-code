/**
 * @file golf.c
 * @author your name (you@domain.com)
 * @brief 三重赋值；赋值是从右到左进行的
 * @version 0.1
 * @date 2022-02-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
    int jane, tarzan, cheeta;

    // 首先是jane得到值68，然后tarzan得到值68，最后cheeta得到值68
    cheeta = tarzan = jane = 68;
    printf("                  cheeta    tarzan  jane\n");
    printf("First round score %4d %8d %8d\n", cheeta, tarzan, jane);
}