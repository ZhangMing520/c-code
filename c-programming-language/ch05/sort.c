/**
 * @brief   TODO
 *
 * 1. 读取输入流中的所有文本行
 * 2. 对文本行进行排序
 * 3. 按照次序打印文本行
 *
 */
#include <stdio.h>
#include <string.h>

// 能够存储的最大文本行数
#define MAXLINES 5000
// 指向文本行的指针数组（数组中的元素是char * 指针）
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

main()
{
    // 行数
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
    }
    else
        printf("error: input too big to sort\n");
}


// 文本行的最大长度
#define MAXLEN 1000
