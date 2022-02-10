

/**
 * @brief 指针t指向的字符串复制到指针s指向的位置，数组下表版本
 *
 * @param s
 * @param t
 */
void strcpy(char *s, char *t)
{
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

/**
 * @brief 指针t指向的字符串复制到指针s指向的位置，指针方法版本
 *
 * @param s
 * @param t
 */
void strcpy2(char *s, char *t)
{
    while ((*s = *t) != '\0')
    {
        s++;
        t++;
    }
}

/**
 * @brief 指针t指向的字符串复制到指针s指向的位置，最终版本
 *
 * @param s
 * @param t
 */
void strcpy3(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}