// Copyright 2022 elviaatt

#include "s21_memmove.h"
#include "s21_memcpy.h"
#include "s21_memcpy_forward_backward.h"

#include <stdlib.h>
#include <assert.h>

static int __is_destination_overlapping_from_left(
    const unsigned char *destination,
    const unsigned char *source,
    s21_size_t size) {
        return (0 < destination - source) &&
        (destination - source < (signed)size);
}

void *s21_memmove(void *destination, const void *source, s21_size_t size) {
    unsigned char *destination_uchar = (unsigned char*)destination;
    const unsigned char *source_uchar = (const unsigned char*)source;

    if (__is_destination_overlapping_from_left(destination_uchar,
    source_uchar, size))
        return __s21_memcpy_backward_uchar(destination_uchar,
        source_uchar, size);

    return __s21_memcpy_forward_uchar(destination_uchar, source_uchar, size);
}

// This also works, but the code is repeated
/*
void *s21_memmove(void *destination, const void *source, s21_size_t size) {
    unsigned char *destination_uchar = (unsigned char*)destination;
    const unsigned char *source_uchar = (const unsigned char*)source;

    for (s21_size_t index = 0ul; index < size; ++index)
        destination_uchar_copy[index] = source_uchar[index];

    for (s21_size_t index = 0ul; index < size; ++index)
        destination_uchar[index] = destination_uchar_copy[index];

    return destination_uchar_copy;
}
*/
