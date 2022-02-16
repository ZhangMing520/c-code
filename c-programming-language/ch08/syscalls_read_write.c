/**
 * @file syscalls_read_write.c
 * @author your name (you@domain.com)
 * @brief unix系统调用  read write  0 1 2 标准输入、标准输出、标准错误输出
 * @version 0.1
 * @date 2022-02-15
 *
 * @copyright Copyright (c) 2022
 *
 */

// syscalls.h: No such file or directory
// #include "syscalls.h"

// grep BUFSIZ /usr/include/*  BUFSIZ在stdio.h
// man read         read在unistd.h
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    char buf[BUFSIZ];
    int n;

    while ((n = read(0, buf, BUFSIZ)) > 0)
        write(2, buf, n);

    return 0;
}