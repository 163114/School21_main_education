// Copyright 2022 elviaatt

#include "s21_strstr.h"
#include "s21_strlen.h"

static int are_strings_equal(const char *string1, const char* string2, s21_size_t length) {
    for (s21_size_t index = 0ul; index < length; ++index)
        if (string1[index] != string2[index])
            return 0;
    return 1;
}

char *s21_strstr(const char *string, const char* substring) {
    const s21_size_t string_length = s21_strlen(string);
    const s21_size_t substring_length = s21_strlen(substring);

    if (string_length < substring_length)
        return s21_NULL;

    if (string_length == 0ul || substring_length == 0ul)
         return (char*)(string);

    for (s21_size_t index = 0ul; index < string_length - substring_length; ++index)
        if (are_strings_equal(string + index, substring, substring_length))
            return (char*)(string + index);

    return s21_NULL;
}
