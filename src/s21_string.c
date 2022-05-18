#include "s21_string.h"


char	*s21_strcat(char *__s1, const char *__s2)
{
    s21_size_t len1 = s21_strlen(__s1), len2 = s21_strlen(__s2);
    char s[len1 + len2];
    for (s21_size_t i = 0; i < len1 + len2; i++)
        s[i] = i < len1? __s1[i]: __s2[i - len1];
    __s1 = &s;
    return __s1;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n)
{
    s21_size_t len = s21_strlen(src);
    char s[n];
    if (n < len)
    {
        for (s21_size_t i = 0; i < n; i++) s[i] = src[i];
        s21_strcat(dest, s);
    } else {
        s21_strcat(dest, src);
    }
    return dest;
}

char	*s21_strchr(const char *__s, int __c)
{
    char *p = s21_NULL;
    for (; *__s; __s++)
        if ((int) *__s == __c) p = __s;
    return p;
}

int	 s21_strcmp(const char *__s1, const char *__s2)
{
    for (; *__s1 && *__s2 && *__s1 == *__s2; __s1++, __s2++) {}
    return *__s1 - *__s2;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n)
{
    for (s21_size_t l = 0; l < n && *str1 && *str2 && *str1 == *str2; l++, str1++, str2++) {}
    return *str1 - *str2;
}

