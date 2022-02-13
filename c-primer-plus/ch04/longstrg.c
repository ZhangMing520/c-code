/**
 * @file longstrg.c
 * @author your name (you@domain.com)
 * @brief printf 打印跨行字符串     \   字符串连接（两者仅有空白字符分割）："a" "b"
 * @version 0.1
 * @date 2022-02-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
// Here's one way to print a long string.
// Here's another way to print a long string.
// Here's the newest way to print a long string.
    printf("Here's one way to print a ");
    printf("long string.\n");
    printf("Here's another way to print a \
long string.\n");
    printf("Here's the newest way to print a "
           "long string.\n");

    return 0;
}