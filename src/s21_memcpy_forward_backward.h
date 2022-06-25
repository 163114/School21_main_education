// Copyright 2022 elviaatt

#ifndef SRC_S21_MEMCPY_FORWARD_BACKWARD_S21_MEMCPY_FORWARD_BACKWARD_H
#define SRC_S21_MEMCPY_FORWARD_BACKWARD_S21_MEMCPY_FORWARD_BACKWARD_H

#include "s21_string_types.h"

char *__s21_memcpy_forward_uchar(unsigned char *destination,
    const unsigned char*source, s21_size_t size);
char *__s21_memcpy_backward_uchar(unsigned char *destination,
    const unsigned char*source, s21_size_t size);

#endif  //  SRC_S21_MEMCPY_FORWARD_BACKWARD_S21_MEMCPY_FORWARD_BACKWARD_H
