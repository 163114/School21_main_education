// Copyright 2022 elviaatt

#include "s21_to_upper.h"
#include "s21_strlen.h"
#include <stdlib.h>

void *s21_to_upper(const char *str)
{
    int len = s21_strlen(str);
    char *str_ = (char*) malloc(len + 1);
    if (str_){
        for (int i = 0; i < len; i++)
        {
            int c = str[i];
            if (c > 96 && c < 127) str_[i] = (char) (c - 32);
            else str_[i] = (char) c;
        }
    }
    str_[len] = '\0';
    return str_;
}
