// Copyright 2022 elviaatt

#include "s21_strncpy.h"
#include "s21_strlen.h"
#include "s21_memset.h"

char *s21_strncpy(char *destination, const char *source, s21_size_t size) {
    const s21_size_t source_size = s21_strlen(source);
    
    const s21_size_t size_to_copy = size < source_size ? size : source_size;
    for (s21_size_t index = 0ul; index < size_to_copy; ++index)
        destination[index] = source[index];

    const int size_for_terminators = (int)size - (int)source_size;
    if (size_for_terminators > 0)
        s21_memset(destination + source_size, '\0', size_for_terminators);

    return destination;   
}
