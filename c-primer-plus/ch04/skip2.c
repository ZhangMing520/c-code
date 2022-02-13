/**
 * @file skip2.c
 * @author your name (you@domain.com)
 * @brief scanf * 跳过相应的输入项目  *放在%和说明符字母之间
 *          如果程序需要读取一个文件中某个特定的列
 * @version 0.1
 * @date 2022-02-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
    int n;
    char line[100];

// Please enter three integers:
// 2 3 2
// The last integer was 2
    // printf("Please enter three integers:\n");
    // scanf("%*d %*d %d", &n);
    // printf("The last integer was %d\n", n);

////////////// 读取文件中第几行，第一个参数是文件名
// ./skip2 < skip2.c
// The 2th line was @file
    scanf("%*s\n%*s\n%s", line);
    printf("The 2th line was %s\n", line);

    return 0;
}