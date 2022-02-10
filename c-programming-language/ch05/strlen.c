

/**
 * @brief   返回字符串的长度，指针参数
 *
 * @param s
 * @return int
 */
int strlen(char *s)
{
    int n;
    for (n = 0; *s != '\0'; s++)
        ++n;
    return n;
}

/**
 * @brief   返回字符串的长度，利用指针运算
 * 
 * @param s 
 * @return int 
 */
int strlen2(char *s)
{
    char *p = s;
    while (*p != '\0')
    {
        p++;
    }
    return p - s;
}