/**
 * @file praise2.c
 * @author your name (you@domain.com)
 * @brief string.h
 * @version 0.1
 * @date 2022-02-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <string.h>

#define PRAISE "What a super marvelous name! "

int main(void)
{
    char name[40];

    printf("What's your name?\n");
    scanf("%s", name);
    printf("Hello,%s. %s\n", name, PRAISE);

// Hello,Morgan. What a super marvelous name! 
// Your name of 6 letters occupies 40 memory cells.
// The phrase of praise has 29 letters and occupies 30 memory cells.
    printf("Your name of %ld letters occupies %d memory cells.\n", strlen(name), sizeof name);
    printf("The phrase of praise has %d letters", strlen(PRAISE));
    printf(" and occupies %ld memory cells.\n", sizeof PRAISE);

    return 0;
}