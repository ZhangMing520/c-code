/**
 * @file floats.c
 * @author your name (you@domain.com)
 * @brief printf 格式化浮点数  %10.3f 格式化显示宽度是10，浮点数精度是3
 * @version 0.1
 * @date 2022-02-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

int main(void){

    const double RENT = 3852.99 ; 

// *3852.990000*
// *3.852990e+03*
// *3852.99*
// *3853.0*
// *  3852.990*
// * 3.853e+03*
// *+3852.99*
// *0003852.99*

    printf("*%f*\n" , RENT) ; 
    printf("*%e*\n" , RENT) ; 
    printf("*%4.2f*\n" , RENT) ; 
    printf("*%3.1f*\n" , RENT) ; 
    printf("*%10.3f*\n" , RENT) ; 
    printf("*%10.3e*\n" , RENT) ; 
    printf("*%+4.2f*\n" , RENT) ; 
    printf("*%010.2f*\n" , RENT) ; 

    return 0 ; 
}