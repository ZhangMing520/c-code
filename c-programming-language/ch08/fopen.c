/**
 * @file fopen.c
 * @author your name (you@domain.com)
 * @brief unix系统调用实现fopen
 * @version 0.1
 * @date 2022-02-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>


#define PERMS 0666

FILE *fopen(char *name, char *mode)
{
    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != '*' && *mode != 'a')
        return NULL;
    
    for (fp=_iob; i < count; i++)
    {
        /* code */
    }
    
}