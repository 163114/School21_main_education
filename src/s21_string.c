#include "s21_string.h"
#include <stdio.h>

#include <stdlib.h>

int main()
{
    char s1[] = "hi my frends", s2[] = "hi frends";
    printf("%s\t%s\n", s1, s2);
    printf("%d\n", s21_strcmp(s1, s2));
    return 0;
}

s21_size_t s21_strlen(const char *string) {
    s21_size_t length = 0ul;
    while (string[length])
        ++length;

    return length;
}

char	*s21_strcat(char *__s1, const char *__s2)
{
    return s21_strncat(__s1, __s2, s21_strlen(__s2));
}

char *s21_strncat(char *dest, const char *src, s21_size_t n)
{
    s21_size_t len1 = s21_strlen(dest);
    char *s = (char*) malloc((len1 + s21_strlen(src)) * sizeof(char));
    for (s21_size_t i = 0; i < n + len1; i++)
        s[i] = i < len1? dest[i]: src[i - len1];
    dest = s;
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
    s21_size_t len1 = s21_strlen(__s1), len2 = s21_strlen(__s2);
    return s21_strncmp(__s1, __s2, len1 < len2? len2: len1);
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n)
{
    for (s21_size_t l = 0; l < (n - 1) && *str1 && *str2 && *str1 == *str2; l++, str1++, str2++) {}
    return *str1 - *str2;
}
