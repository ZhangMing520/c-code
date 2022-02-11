

struct point
{
    int x;
    int y;
};

/**
 * @brief  创建二维空间的点
 *
 * @param x
 * @param y
 * @return struct point
 */
struct point makepoint(int x, int y)
{
    struct point temp;
    // 参数和结构体成员同名也不会冲突
    temp.x = x;
    temp.y = y;
    return temp;
};

/**
 * @brief   点相加
 *
 * @param p1 值传递，拷贝了一份，不影响实参
 * @param p2
 * @return struct point
 */
struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
};
