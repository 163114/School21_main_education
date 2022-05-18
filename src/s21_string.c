#include "s21_string.h"
#include <stdio.h>

#include <stdlib.h>

int main()
{
    char s1[] = "hi my frends", s2[] = "hi frends", s3[] = "qwertyuiop[]\';lkjhgfdsa`zxcvbnm,./1234567890-";
    printf("%s\t%s\n", s1, s2);
    printf("%s\n", s21_trim("....fine***", ".*"));
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
    int len = s21_strlen(__s);
    for (int i = 0; i < len; i++)
        if ((int) __s[i] == __c) return (char *) (__s + i);
    return s21_NULL;
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

void *s21_to_upper(const char *str)
{
    int len = s21_strlen(str);
    char *str_ = (char*) malloc(len + 1);
    for (int i = 0; i < len; i++)
    {
        int c = str[i];
        if (c > 96 && c < 127) str_[i] = (char) (c - 32);
        else if (c > 159 && c < 176) str_[i] = (char) (c - 32);
        else if (c > 223 && c < 240) str_[i] = (char) (c - 80);
        else if (c == 241 || c == 243) str_[i] = (char) (c - 1);
        else str_[i] = (char) c;
    }
    return str_;
}

void *s21_to_lower(const char *str)
{
    int len = s21_strlen(str);
    char *str_ = (char*) malloc(len + 1);
    for (int i = 0; i < len; i++)
    {
        int c = str[i];
        if (c > 64 && c < 91) str_[i] = (char) (c + 32);
        else str_[i] = (char) c;
    }
    return str_;
}

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

// don't work
void *s21_trim(const char *src, const char *trim_chars)
{
    int len1 = s21_strlen(src), len2 = s21_strlen(trim_chars), start_n = 1, start = 0, end_n = 1, end = 0;
    for (int i = 0; i < len1; i++)
    {
        int t = 0;
        char c = src[i];
        if (start_n)
            for (int j = 0; j < len2; j++)
                if (c == trim_chars[j]) t = 1;
        if (!t) break;
        else start++;
    }
    for (int i = len1 - 1; i > -1; i++)
    {
        int t = 0;
        char c = src[i];
        if (end_n)
            for (int j = 0; j < len2; j++)
                if (c == trim_chars[j]) t = 1;
        if (!t) end_n = 0;
        else end++;
    }
    char *str_ = (char*) malloc(len1 - start - end + sizeof(char));
    for (int i = 0; i < s21_strlen(str_); i++)
        if (i >= start && i <= end) str_[i - start] = src[i];
    return str_;
}
