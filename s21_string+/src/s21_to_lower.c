// Copyright 2022 elviaatt

#include "s21_to_lower.h"
#include "s21_strlen.h"

#include "stdlib.h"

void *s21_to_lower(const char *str) {
    int len = s21_strlen(str);
    char *str_ = (char*) malloc(len + 1);  //  for c++ compilers
    if (str_){
        for (int i = 0; i < len; i++)
        {
            int c = str[i];
            if (c > 64 && c < 91) str_[i] = (char) (c + 32);
            else str_[i] = (char) c;
        }
    }
    str_[len] = '\0';
    return str_;
}
/*
void *s21_to_lower(const char *string) {
    const s21_size_t length = s21_strlen(string);
    char *lower_string = malloc(sizeof(char) * (length + 1ul));

    if (!lower_string)
        return lower_string;

    for (s21_size_t index = 0ul; index < length; ++index) {
        if ('A' <= string[index] && string[index] <= 'Z') {
            lower_string[index] = string[index] - ('A' - 'a');
        } else {
            lower_string[index] = string[index];
        }
    }
    lower_string[length] = '\0';

    return lower_string;
}
*/
