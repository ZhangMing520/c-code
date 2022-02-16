/**
 * @file getchar.c
 * @author your name (you@domain.com)
 * @brief unix系统调用 read 构造C函数getchar
 * @version 0.1
 * @date 2022-02-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <unistd.h>
#include <stdio.h>

int getchar(void);
int getchar2(void);

int main(void)
{
    char c;

    while ((c = getchar2()) != EOF)
    {
        write(1, &c, 1);
    }

    return 0;
}

/**
 * @brief 无缓冲的单字符输入
 *
 * @return int
 */
int getchar(void)
{
    char c;

    return (read(0, &c, 1)) == 1 ? (unsigned char)c : EOF;
}

/**
 * @brief 带缓冲的版本
 *
 * @return int
 */
int getchar2(void)
{
    // static 保存函数执行上一次值
    static char buf[BUFSIZ];
    // 相当于指针的初始化
    static char *bufp = buf;
    static int n = 0;

    if (n == 0)
    {
        // 因为是char数组，所以可以直接使用 sizeof buf = sizeof buf / sizeof(char)=1
        n = read(0, buf, sizeof buf);
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char)*bufp++ : EOF;
}