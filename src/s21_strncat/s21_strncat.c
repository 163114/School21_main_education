#include "s21_strncat.h"

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
