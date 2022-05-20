#include "s21_strncat.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n)
{
    s21_size_t len = s21_strlen(src);
    if (len > n){   // && s21_strlen(dest) + n....
        char *p = dest;
        while(*p) p++;
        for (s21_size_t i = 0; i < n; i++, p++)
            *p = src[i];
        *p = '\0';
    }
    return dest;
}

