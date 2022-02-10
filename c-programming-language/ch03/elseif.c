#include <stdio.h>

int binsearch(int x, int v[], int n);

/**
 * @brief if .. else if .. else
 *
 */
main()
{
    int x, ret;
    int v[] = {1, 3, 5, 7, 9};

    x = 3;
    ret = binsearch(x, v, 5);
    printf("%d\n", ret);
}

/**
 * @brief   二分查找x
 *
 * @param x     待查找元素
 * @param v     数组，已排序
 * @param n     数组大小
 * @return int
 */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid;
        else if (x > v[mid])
            low = mid;
        else
            return mid;
    }
    return -1;
}