#include "s21_strncat.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n)
{
    s21_size_t len1 = s21_strlen(dest);
    char *s = (char*) malloc((len1 + s21_strlen(src)) * sizeof(char));
    for (s21_size_t i = 0; i < n + len1; i++)
        s[i] = i < len1? dest[i]: src[i - len1];
    dest = s;
    return dest;
}

