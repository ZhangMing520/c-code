/**
 * @file cp.c
 * @author your name (you@domain.com)
 * @brief unix 系统调用，使用creat实现cp
 *      函数unlink(char *name)用于将文件name从文件系统中删除掉，对应于标准库函数remove
 *      一个程序同时打开的文件数目不能超过一个极限（通常为20）。如果一个程序需要同事处理多个文件，那么它必须重用文件描述符。
 *      close(int fd)用来断开文件描述符和已打开文件间的联结
 * @version 0.1
 * @date 2022-02-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

// 所有者 所有者组 其他 可读可写
#define PERMS 0666

void error(char *, ...);

int main(int argc, char *argv[])
{
    int f1, f2, n;
    char buf[BUFSIZ];

    if (argc != 3)
        error("Usage: cp from to ");

    // 成功返回int类型的文件描述符，否则返回-1
    if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
        error("cp: can't open %s", argv[1]);

    // creat成功创建了文件，返回一个文件描述符，否则返回-1 
    if ((f2 = creat(argv[2], PERMS)) == -1)
        error("cp: can't create %s, mode %03o", PERMS);

    while ((n = read(f1, buf, BUFSIZ)) > 0)
        if (write(f2, buf, n) != n)
            error("cp: write error on file %s", argv[2]);

    return 0;
}

/**
 * @brief 打印错误
 *
 * @param fmt
 * @param ...
 */
void error(char *fmt, ...)
{
    // 初始化
    va_list args;
    va_start(args, fmt);
    // fprintf 向文件中输出
    fprintf(stderr, "error:");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}