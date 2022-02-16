/**
 * @file lseek.c
 * @author your name (you@domain.com)
 * @brief unix 系统调用 lseek
 *        long lseek(int fd, long offset, int origin)
 *          offset 移动位置相对origin而定
 *          origin的值可以是0、1、2，分别用于指定offset从文件开始，从当前位置开始或从文件结束处开始算起
 *          返回值说明文件的新位置
 * @version 0.1
 * @date 2022-02-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <unistd.h>

int get(int fd, long pos, char *buf, int n);

int main(void)
{
    char buf[100];
    int n;

    // 从输入流中获取
    if ((n = get(0, 1, buf, 100)) > 0)
        write(2, buf, n);

    return 0;
}

/**
 * @brief 移动到位置pos处
 *
 * @param fd
 * @param pos
 * @param buf
 * @param n
 * @return int  真正读取的字节数
 */
int get(int fd, long pos, char *buf, int n)
{
    if (lseek(fd, pos, 0) > 0)
        return read(fd, buf, n);
    else
        return -1;
}