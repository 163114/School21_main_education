#include "s21_memchr.h"

static char *s21_memchr_not_like_shit(const unsigned char *string, unsigned char symbol, s21_size_t size) {
    for (s21_size_t index = 0ul; index < size; ++index) 
        if (string[index] == symbol)
            return (char*)(string + index);

    return s21_NULL;
}

void *s21_memchr(const void *string, int symbol, s21_size_t size) {
    const unsigned char* string_uchar = (const unsigned char*)string;
    const unsigned char  symbol_uchar = (unsigned char)symbol;

    return s21_memchr_not_like_shit(string_uchar, symbol_uchar, size);
}
