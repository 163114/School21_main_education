#include "s21_strncmp.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n)
{
    for (s21_size_t l = 0; l < (n - 1) && *str1 && *str2 && *str1 == *str2; l++, str1++, str2++) {}
    return *str1 - *str2;
}
