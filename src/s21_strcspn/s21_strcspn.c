#include "s21_strcspn.h"
#include "../s21_common/s21_filter_from_beginning/s21_filter_from_beginning.h"
#include "../s21_common/s21_is_found/s21_is_found.h"

s21_size_t s21_strcspn(const char *string, const char *symbols) {
    return __s21_filter_from_beginning(string, symbols, is_not_found);
}