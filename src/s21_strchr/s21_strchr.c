#include "s21_strchr.h"

char	*s21_strchr(const char *__s, int __c)
{
    char *p = s21_NULL;
    for (; *__s; __s++)
        if ((int) *__s == __c) p = __s;
    return p;
}
