/**
 * @brief alloc 函数对一个大字符数组allocbuf中的空间进行分配。该数组是alloc和free的私有数组
 * 
 */


// 可用空间大小
#define ALLOCSIZE 10000

// alloc 使用的存储区
static char allocbuf[ALLOCSIZE];
// 下一个空闲位置
static char *allocp = allocbuf;

/**
 * @brief  返回指向n个字符的指针
 *
 * @param n
 * @return char*
 */
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        // 分配前的指针
        return allocp - n;
    }
    else
        // 空间不够
        return 0;
}

/**
 * @brief   释放p指向的存储区
 *
 * @param p
 */
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    // 这种释放只适合于allocbuf单个人使用
    // alloc与afree以栈式进行存储空间的管理
        allocp = p;
}