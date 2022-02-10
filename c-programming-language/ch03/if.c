#include <stdio.h>

/**
 * @brief 歧义性：else部分与嵌套里面的if匹配，每一个else与最近还无else匹配的if匹配
 * 
 * 
 */
main()
{
    /**
     * @brief  编译执行下列代码不是缩进结构所表示的那样
     * 
     * 在if语句嵌套的情况下尽可能使用花括号
     */
    // int n, i;

    // n = 1;
    // if (n > 0)
    //     for (i = 0; i < n; i++)
    //         if (n > 0)
    //         {
    //             printf("...");
    //         }
    // else
    //     printf("error n is negative\n") ;
}