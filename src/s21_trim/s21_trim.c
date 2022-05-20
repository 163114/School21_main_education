#include "s21_trim.h"

int searc(char c, const char *trim_chars)
{
    int lentr = s21_strlen(trim_chars);
    for (int i = 0; i < lentr; i++)
        if (c == trim_chars[i]) return 1;
    return 0;
}

void *s21_trim(const char *src, const char *trim_chars)
{
    int len = s21_strlen(src), begin = 0, end = len - 1, lenst = len;

    for (; begin < len; begin++)
        if (!searc(src[begin], trim_chars)) break;
    for (; end > begin; end--)
        if (!searc(src[end], trim_chars)) break;
    lenst = len - begin - (len - end) + 1;
    char *str_ = (char *)malloc(lenst * sizeof(char));
    if (str_)
    {
        for (int i = 0; i < lenst && begin <= end; i++, begin++)
            str_[i] = src[begin];
    }
    return str_;
}
