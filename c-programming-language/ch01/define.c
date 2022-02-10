#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/**
 * @brief 符号常量  #define 名字 替换文本
 * 
 * 所有在程序中出现在 #define 中定义的名字，该名字即没有用引号括起来，也不是其他名字的一部分，都用所对应的替换文本替换
 * 
 */
main()
{
    int fahr;
    for (fahr = 0; fahr < UPPER; fahr = fahr + STEP)
    {
        printf("%3d %6.1f\n", fahr, 5.0 / 9.0 * (fahr - 32));
    }
}