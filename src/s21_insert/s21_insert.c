#include "s21_insert.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index)
{
    int len1 = s21_strlen(src), len2 = s21_strlen(str), len = len1 + len2, i = 0, j = 0, k = 0;
    char *str_ = (char*) malloc(len1 + len2 * sizeof(char));
    for (; i < len; i++)
    {
        if (i >= start_index && k < len2)
        {
            str_[i] = str[k];
            k++;
        } else {
            str_[i] = src[j];
            j++;
        }
    }
    return str_;
}