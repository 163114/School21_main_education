// Copyright 2022 elviaatt

#include "s21_trim.h"
#include "s21_strlen.h"

static int searc(char c, const char *trim_chars) {
    int lentr = s21_strlen(trim_chars);
    for (int i = 0; i < lentr; i++)
        if (c == trim_chars[i]) return 1;
    return 0;
}

void *s21_trim(const char *src, const char *trim_chars) {
    int len = s21_strlen(src), begin = 0, end = len - 1;

    for (; begin < len; begin++)
        if (!searc(src[begin], trim_chars)) break;
    for (; end > begin; end--)
        if (!searc(src[end], trim_chars)) break;
    const int lenst = len - begin - (len - end) + 2;
    char *str_ = (char *)malloc((lenst+1) * sizeof(char));
    if (str_) {
        for (int i = 0; i < lenst - 1 && begin <= end; i++, begin++)
            str_[i] = src[begin];
    }
    str_[lenst - 1] = '\0';
    return str_;
}


// static int __is_found(const char *source, int length, char symbol) {
//     for (int index = 0; index < length; ++index)
//         if (source[index] == symbol)
//             return 1;
//     return 0;
// }

// void *s21_trim(const char *source, const char *symbols_to_delete) {
//     const int source_length = s21_strlen(source);
//     const int symbols_length = s21_strlen(symbols_to_delete);

//     int new_source_length = 0;

//     for (int index = 0; index < source_length; ++index) {

//     }
// }
