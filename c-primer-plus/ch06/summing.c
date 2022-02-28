/**
 * @file summing.c
 * @author your name (you@domain.com)
 * @brief while 对用户输入的整数求和
 * @version 0.1
 * @date 2022-02-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
    long num;
    long sum = 0L;
    int status;

    printf("Please enter an integer to be summed.");
    printf("q to quit):");
    status = scanf("%ld", &num);
    // status 为什么等于1呢？因为scanf返回的是成功读入的项目的个数
    while (status == 1)
    {
        sum = sum + num;
        printf("Please enter next integer q to quit):");
        status = scanf("%ld", &num);
    }
    printf("Those integers sum to %ld.\n", sum);
    return 0;
}