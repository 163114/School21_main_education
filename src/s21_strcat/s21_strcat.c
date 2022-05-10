#include "s21_strcat.h"

char	*s21_strcat(char *__s1, const char *__s2)
{
    s21_size_t len1 = s21_strlen(__s1), len2 = s21_strlen(__s2);
    char s[len1 + len2];
    for (s21_size_t i = 0; i < len1 + len2; i++)
        s[i] = i < len1? __s1[i]: __s2[i - len1];
    __s1 = &s;
    return __s1;
}
