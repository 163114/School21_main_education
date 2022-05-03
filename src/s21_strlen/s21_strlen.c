#include "s21_strlen.h"

s21_size_t s21_strlen(const char *string) {
    s21_size_t length = 0ul;
    while (string[length])
        ++length;

    return length;
}