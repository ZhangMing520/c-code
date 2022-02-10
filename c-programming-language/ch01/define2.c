#include <stdio.h>

#define LOWER 0
// 加上括号之后，被当做宏函数的参数，并且语法不对
// #define (LOWER) 0

// 多次定义，后面的覆盖前面的
#define LOWER 2

main()
{
    printf("%d\n", LOWER);
}