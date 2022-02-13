/**
 * @file strings.c
 * @author your name (you@domain.com)
 * @brief print %s 精度使用
 * @version 0.1
 * @date 2022-02-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

#define BLURB "Authentic imitation! "

int main(void)
{
// /Authentic imitation! /
// /   Authentic imitation! /
// /                   Authe/
// /Authe                   /
    printf("/%2s/\n", BLURB);
    printf("/%24s/\n", BLURB);
    printf("/%24.5s/\n", BLURB);
    printf("/%-24.5s/\n", BLURB);

    return 0;
}