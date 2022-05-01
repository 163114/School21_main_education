#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <stdio.h>
#include <stdlib.h>
// The function is used in vararg arguments in the s21_printf function
#include <stdarg.h>

int s21_sprintf(char *str, const char *format, ...);
int choose_return_type(const char *format, int *specifier_index);

enum is_true{
    FALSE,
    TRUE
};

#endif