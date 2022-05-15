#include "s21_memcpy_forward_backward.h"

char *__s21_memcpy_forward_uchar(unsigned char *destination, const unsigned char*source, s21_size_t size) {
    for (s21_size_t index = 0ul; index < size; ++index)
        destination[index] = source[index];

    return destination;
}

char *__s21_memcpy_backward_uchar(unsigned char *destination, const unsigned char*source, s21_size_t size) {
    for (s21_size_t index = size; index > 0ul; --index)  //  index >= 0ul causes endless cycle
        destination[index - 1ul] = source[index - 1ul];

    return destination;
}