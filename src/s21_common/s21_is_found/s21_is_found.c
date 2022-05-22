#include "s21_is_found.h"
#include "../s21_memchr/s21_memchr.h"

int __is_found(const char *string, char symbol, s21_size_t length) {
    return s21_memchr(string, symbol, length);
}
int __is_not_found(const char *string, char symbol, s21_size_t length) {
    return !__is_found(string, symbol, length);
}