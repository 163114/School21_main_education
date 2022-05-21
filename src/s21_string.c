#include "s21_string.h"
#include <stdio.h>

#include <stdlib.h>

int main()
{
    char s1[] = "hi my frends", s2[] = "hi frends", s3[] = "qwertyuiop[]\';lkjhgfdsa`zxcvbnm,./1234567890-";
    // printf("%s\t%s\n", s1, s2);
    printf("%s\n", s21_trim(s3, ".*qwer1234567890ty-uiop"));
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
    char *str_ = (char *)malloc(len1 + len2 * sizeof(char));
    if (str_){
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
    }
    return str_;
}

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





int choose_return_type(char *buffer, int index, const char *format, va_list argp)
{
    char *pt = strtok(buffer, " "), cl = 'q';
    for (int i = 1; i <= index; i++)
        if (pt != NULL)
            pt = strtok(NULL, " ");
        // else error  specifires < date
        else return 1; // error

    if (*format == 'h' || *format == 'l' || *format == 'L')
    {
        cl = *format;
        format++;
        c = *format;
    }
    else if (*format == 'c')
        *va_arg(argp, char*) = *pt;
    else if (*format == 'd' || *format == 'i') {
        if (cl == 'h') printf("ho");
        else if (cl == 'l') printf("lo");
        else printf("else o");
    } else if (*format == 'e') {
        if (cl == 'L') printf("e");
        else printf("else e");
    } else if (*format == 'E') {
        if (cl == 'L') printf("E");
        else printf("else E");
    } else if (*format == 'f') {
        if (cl == 'L') *(va_arg(argp, long double*)) = atof(pt);
        else *(va_arg(argp, float*)) = atof(pt);
    } else if (*format == 'g') {
        if (cl == 'L') printf("g");
        else printf("else g");
    } else if (*format == 'G') {
        if (cl == 'L') printf("G");
        else printf("else G");
    } else if (*format == 'o') {
        if (cl == 'h') printf("ho");
        else if (cl == 'l') printf("lo");
        else printf("else o");
    } else if (*format == 's')
        strcpy(va_arg(argp, char*), pt);
    else if (*format == 'u') {
        if (cl == 'h') *va_arg(argp, short unsigned int*) = atof(pt);
        else if (cl == 'l') *va_arg(argp, long unsigned int*) = atof(pt);
        else *va_arg(argp, unsigned int*) = atof(pt);
    } else if (*format == 'x') {
        if (cl == 'h') printf("hx");
        else if (cl == 'l') printf("lx");
        else printf("else x");
    } else if (*format == 'X') {
        if (cl == 'h') printf("hX");
        else if (cl == 'l') printf("lX");
        else printf("else X");
    } else if (*format == 'p')
        printf("p"); // *va_arg(argp, void**) = (void *) *pt;
    else if (*format == 'n')
        printf("n");
    else return 1;
    return 0;
}
