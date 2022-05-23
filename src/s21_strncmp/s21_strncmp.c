#include "s21_strncmp.h"

int s21_strncmp(const char *string1, const char *string2, s21_size_t size) {
    for (s21_size_t index = 0ul; index < size; ++index)
        if (string1[index] != string2[index])
            return string1[index] - string2[index];

    return 0;
}