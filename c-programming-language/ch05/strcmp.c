
/**
 * @brief 字符串比较，数组下标版本
 *
 * @param s
 * @param t
 * @return int
 */
int strcmp(char *s, char *t)
{
    int i;

    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;

    return s[i] - t[i];
}

/**
 * @brief 字符串比较，指针版本
 *
 * @param s
 * @param t
 * @return int
 */
int strcmp2(char *s, char *t)
{

    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
            
    return *s - *t;
}