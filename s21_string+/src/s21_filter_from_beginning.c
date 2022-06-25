// Copyright 2022 elviaatt

#include "s21_filter_from_beginning.h"
#include "s21_strlen.h"

s21_size_t __s21_filter_from_beginning(const char *string, const char *symbols,
        int (*is_suitable)(const char *, char, s21_size_t)) {
    s21_size_t result = 0ul;
    const s21_size_t size_string = s21_strlen(string);
    const s21_size_t size_symbols = s21_strlen(symbols);

    for (s21_size_t index = 0ul; index < size_string; ++index) {
        if (!is_suitable(symbols, string[index], size_symbols))
            return result;
        ++result;
    }
    return result;
}
