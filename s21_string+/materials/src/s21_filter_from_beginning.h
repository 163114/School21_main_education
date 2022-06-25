// Copyright 2022 elviaatt

#ifndef SRC_S21_FILTER_FROM_BEGINNING_H_
#define SRC_S21_FILTER_FROM_BEGINNING_H_

#include "s21_string_types.h"

s21_size_t __s21_filter_from_beginning(const char *string, const char *symbols,
    int (*is_suitable)(const char *, char, s21_size_t));

#endif  // SRC_S21_FILTER_FROM_BEGINNING_H_
