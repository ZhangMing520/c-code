/**
 * @file malloc.c
 * @author your name (you@domain.com)
 * @brief 当有申请请求时候，扫描空闲块列表以找到一个足够大的块。这个算法称为“最先匹配”；
 *      与之相对的算法是“最有匹配”，它寻找满足条件且最小的块。如果这个块刚好与请求的大小相符合，将它从链表中移走并返回给用户。
 *      如果这个块太大，那么将它分成两部分：大小合适的块返回给用户，剩下的部分留在空闲块列表中。如果找不到一个足够大的块，那么
 *
 *      释放过程也是首先搜索空闲块列表，以找到可以插入被释放块的合适位置。如果被释放块的任一端是一个空闲块，那么将这两个块合成一个更大的块，以确保不会有太多的碎片。
 *      空闲块列表是以地址的递增顺序链接在一起的，所以很容易判断相邻的块是否空闲
 *
 *      确保由malloc函数返回的存储空间与将要保存的对象能合适的对齐。每一个特定的机器上都有一个最受限类型，如果此类型可以存储在一个特定的地址中，那么所有其他的类型也可以存放在此地址中。
 *      某些机器上，最受限的类型是double类型；而在另一些机器上，最受限的类型是int或long类型
 * @version 0.1
 * @date 2022-02-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

// 以long类型的边界对齐
typedef long Align;

// 块的头部
union header
{
    struct
    {
        // 空闲块列表中的下一块
        union header *ptr;
        // 本块的大小
        unsigned size;
    };
    // 强制块的对齐
    // 所有块的大小都是头部大小的整数倍
    Align x;
};

typedef union header Header;

// 从空列表开始
static Header base;
// 空闲列表的开始指针
static Header *freep = NULL;

void *malloc(unsigned nbytes)
{
    Header *p, *prevp;
    Header *morecore(unsigned);
    unsigned nunits;

    nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
    if ((prevp = freep) == NULL)
    {
        // 没有空闲列表
        base.size
    }
}
