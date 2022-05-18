#include "s21_strchr.h"

char	*s21_strchr(const char *__s, int __c)
{
    int len = s21_strlen(__s);
    for (int i = 0; i < len; i++)
        if ((int) __s[i] == __c) return (char *) (__s + i);
    return s21_NULL;
}
