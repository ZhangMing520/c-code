/**
 * @file for_geo.c
 * @author your name (you@domain.com)
 * @brief for 循环
 * @version 0.1
 * @date 2022-02-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
    double debt;
    for (debt = 100.0; debt < 150.0; debt = debt * 1.1)
        printf("You debt is now $%.2f.\n", debt);

    return 0;
}