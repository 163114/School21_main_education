// Copyright 2022 elviaatt

#ifndef S21_COMMON_S21_FILTER_FROM_BEGINNING_S21_FILTER_FROM_BEGINNING_H
#define S21_COMMON_S21_FILTER_FROM_BEGINNING_S21_FILTER_FROM_BEGINNING_H

#include "s21_string_types.h"

s21_size_t __s21_filter_from_beginning(const char *string, const char *symbols,
    int (*is_suitable)(const char *, char, s21_size_t));

#endif  //  S21_COMMON_S21_FILTER_FROM_BEGINNING_S21_FILTER_FROM_BEGINNING_H
