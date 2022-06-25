// Copyright 2022 elviaatt

#include "s21_memset.h"

char *s21_memset_uchar(unsigned char *string,
unsigned char symbol, s21_size_t size) {
    for (s21_size_t index = 0ul; index < size; ++index)
        string[index] = symbol;
    return (char*)string;
}

void *s21_memset(void *string, int symbol, s21_size_t size) {
    unsigned char *string_uchar = (unsigned char*)string;
    unsigned char symbol_uchar = (unsigned char)symbol;
    char *result = s21_memset_uchar(string_uchar, symbol_uchar, size);
    return result;
}
