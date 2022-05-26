/**
 * @file file_eof.c
 * @author your name (you@domain.com)
 * @brief fopen() 打开一个文件显示其内容
 * @version 0.1
 * @date 2022-02-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h> // 使用exit()

int main(void)
{
    int ch;
    FILE *fp;
    char fname[50]; // 用于存放文件名

    printf("Enter the name of the file:");
    scanf("%s", fname);
    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("Failed to open file.Bye\n");
        exit(1);
    }
    // getc(fp)从打开的文件中获取一个字符
    while ((ch = getc(fp)) != EOF)
        putchar(ch);
    fclose(fp);
    return 0;
}