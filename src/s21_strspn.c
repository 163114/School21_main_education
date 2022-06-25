// Copyright 2022 elviaatt

#include "s21_strspn.h"
#include "s21_memchr.h"
#include "s21_strlen.h"
#include "s21_filter_from_beginning.h"
#include "s21_is_found.h"

s21_size_t s21_strspn(const char *string, const char *symbols) {
    return __s21_filter_from_beginning(string, symbols, __is_found);
}
