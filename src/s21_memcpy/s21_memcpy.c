#include "s21_memcpy.h"
#include "../s21_common/s21_memcpy_forward_backward.h"

void *s21_memcpy(void *destination, const void *source, s21_size_t size) {
    unsigned char *destination_uchar = (unsigned char*)destination;
    const unsigned char *source_uchar = (const unsigned char*)source;

    return __s21_memcpy_forward_uchar(destination_uchar, source_uchar, size);
}