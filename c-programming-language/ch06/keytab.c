/**
 * @file keytab.c
 * @author zhangming
 * @brief 统计一个输入流中C语言关键词
 * @version 0.1
 * @date 2022-02-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

// 关键词字符
#define MAXWORD 100

struct key
{
    char *word;
    int count;
} keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"unsigned", 0},
    {"void", 0},
    {"volatile", 0},
    {"while", 0},
};

// 关键词数组长度
#define NKEYS (sizeof keytab / sizeof(struct key))

int getword(char *, int);
int binsearch(char *, struct key *, int);

main()
{
    int n;
    char word[MAXWORD];

    // TODO getword
    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;

        for (n = 0; n < NKEYS; n++)
        {
            if (keytab[n].count > 0)
                printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }
    }
}

/**
 * @brief 从tab找出word所在的索引
 *
 * @param word 待查找关键词
 * @param tab
 * @param n 数组长度
 * @return int word所在数组索引
 */
int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
        {
            high = mid - 1;
        }
        else if (cond > 0)
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int getword(char *word, int lim)
{
}