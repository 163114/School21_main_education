#include "s21_memcpy.h"

static char *s21_memcpy_uchar(unsigned char *destination, const unsigned char*source, s21_size_t size) {
    for (s21_size_t index = 0ul; index < size; ++index)
        destination[index] = source[index];

    return destination;
}

void *s21_memcpy(void *destination, const void *source, s21_size_t size) {
    unsigned char *destination_uchar = (unsigned char*)destination;
    const unsigned char *source_uchar = (const unsigned char*)source;

    return s21_memcpy_uchar(destination_uchar, source_uchar, size);
}