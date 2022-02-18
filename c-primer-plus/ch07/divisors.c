/**
 * @file divisors.c
 * @author your name (you@domain.com)
 * @brief 素数
 * @version 0.1
 * @date 2022-02-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    unsigned long num; // 要检查的数
    unsigned long div; // 可能的约数
    bool is_prime;     // 素数的标志

    printf("Please enter an integer for analysis:");
    printf("Enter q to quit.\n");

    while (scanf("%lu", &num) == 1)
    {
        for (div = 2, is_prime = true; (div * div) <= num; div++)
        {
            if (num % div == 0)
            {
                if ((div * div) != num)
                    printf("%lu is divisible by %lu and %lu.\n", num, div, num / div);
                else
                    printf("%lu is divisible by %lu.\n", num, div);
                is_prime = false;   // 不是素数
            }
        }
        if (is_prime)
            printf("%lu is Prime.\n", num);
        printf("Please enter another integer for analysis:");
        printf("Enter q to quit.\n");
    }
    return 0;
}