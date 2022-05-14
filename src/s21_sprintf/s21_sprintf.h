#ifndef S21_SPRINTF_NEW_H
#define S21_SPRINTF_NEW_H

#include <stdio.h>
#include <stdlib.h>
// The function is used in vararg arguments in the s21_printf function
#include <stdarg.h>

int s21_sprintf(char *buffer, const char *format, ...);
void choose_return_type(char *buffer, const char *format, int index, int *number_of_arguments, va_list argp);
void c_specifier(char *buffer, int index, int *number_of_arguments, va_list argp);

enum is_true{
    FALSE,
    TRUE
};

#endif
