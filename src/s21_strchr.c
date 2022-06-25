// Copyright 2022 elviaatt

#include "s21_strchr.h"
#include "s21_strlen.h"

char *s21_strchr(const char *string, int symbol) {
    const int length = s21_strlen(string);

    for (int index = 0; index < length; index++)
        if ((int) string[index] == symbol)
            return (char *) (string + index);

    return s21_NULL;
}
