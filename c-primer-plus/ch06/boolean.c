/**
 * @file boolean.c
 * @author your name (you@domain.com)
 * @brief _Bool 类型
 * @version 0.1
 * @date 2022-02-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    long num;
    long sum = 0L;
    bool input_is_good;

    printf("Please enter an integer to be summed.");
    printf("(q to quit): ");
    input_is_good = (scanf("%ld", &num) == 1);

    while (input_is_good)
    {
        sum += num;
        printf("Please enter next integer (q to quit):");
        input_is_good = (scanf("%ld", &num) == 1);
    }

    printf("Those integers sum to %ld.\n", sum);
    return 0;
}