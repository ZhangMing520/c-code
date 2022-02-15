/**
 * @file zeno.c
 * @author your name (you@domain.com)
 * @brief 希腊哲学家Zeno曾经辩论说一支箭永远不能达到它的目标。首先箭要到达目标距离的一半，然后又必须到达剩余距离的一半
 *      采取一种定量的方法，嘉定箭用1秒的时间走完前一半距离，然后用1/2秒的时间走完剩下的距离的一半，
 *      用1/4秒的时间走完剩下的距离的一半以此类推
 * @version 0.1
 * @date 2022-02-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
    int t_ct;
    double time, x;
    int limit;

    printf("Enter the number of terms you want:");
    scanf("%d", &limit);
    // 总的时间是无限接近2秒
    for (time = 0, x = 1, t_ct = 1; t_ct <= limit; t_ct++, x *= 2.0)
    {
        time += 1.0 / x;
        printf("time = %f where terms = %d.\n", time, t_ct);
    }
    return 0;
}