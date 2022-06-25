// Copyright 2022 elviaatt

#include "s21_memcmp.h"

static int __s21_memcmp_not_like_shit(const unsigned char *string1,
const unsigned char *string2, s21_size_t size) {
    for (s21_size_t index = 0ul; index < size; ++index) {
        if (string1[index] != string2[index])
            return string1[index] - string2[index];
    }
    return 0;
}

int s21_memcmp(const void *string1, const void *string2, s21_size_t size) {
    const unsigned char* string_uchar1 = (const unsigned char*)string1;
    const unsigned char* string_uchar2 = (const unsigned char*)string2;

    return __s21_memcmp_not_like_shit(string_uchar1, string_uchar2, size);
}
