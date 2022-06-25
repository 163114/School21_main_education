// Copyright 2022 elviaatt

#include "s21_strncat.h"
#include "s21_strlen.h"

char *s21_strncat(char *destination, const char *source, s21_size_t size) {
    const s21_size_t size_source = s21_strlen(source);
    const s21_size_t size_destination = s21_strlen(destination);

    const s21_size_t size_to_write = size < size_source ? size : size_source;
    for (s21_size_t index = size_destination; index <
    size_destination + size_to_write; ++index)
        destination[index] = source[index - size_destination];
    destination[size_destination + size_to_write] = '\0';

    return destination;
}
