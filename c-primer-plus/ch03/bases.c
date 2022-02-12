/**
 * @file bases.c
 * @author your name (you@domain.com)
 * @brief 打印整数的8进制，16进制   %#o %#x %#X 分别生成 0 0x 0X 前缀
 * @version 0.1
 * @date 2022-02-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

int main(void)
{
    int x=100 ; 
    // dec = 100; octal = 144; hex = 64
    printf("dec = %d; octal = %o; hex = %x\n" ,x,x,x);
    // dec = 100; octal = 0144; hex = 0x64
    printf("dec = %d; octal = %#o; hex = %#x\n" ,x,x,x);
    return 0 ;
}