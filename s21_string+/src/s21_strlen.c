// Copyright 2022 elviaatt

#include "s21_strlen.h"
// 'h' 'e' '\0'
s21_size_t s21_strlen(const char *string) {
    s21_size_t length = 0ul;

    while (string[length])  //  '\0' is implicitly converted to false
        ++length;

    return length;
}
