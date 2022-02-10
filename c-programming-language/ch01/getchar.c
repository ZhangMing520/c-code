#include <stdio.h>

/**
 * @brief getchar() 获取一个字符
 *
 * 文本的输入输出都是作为字符流处理的，不管它从何处输入，从何处输出
 *
 * 文本流是由一行行字符组成的字符序列，而每一行字符则由0个或者多个字符组成，并后跟一个换行符
 * 
 * ./getchar < EOF.c
 */
main()
{
    int c;
    // 程序运行来看，输入nihao，输出nihao
    // 看着getchar好像一次获取了多个字符，主要是while循环依次读取一个字符，直到\n结束，putchar也没有换行导致
    while ((c = getchar()) != EOF)
    {
        putchar(c);
        // %c 中文会乱码，ASCII还是不能显示所有字符
        // printf("%c\n", c);
    }
}