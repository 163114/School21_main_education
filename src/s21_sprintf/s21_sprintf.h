#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <stdio.h>
#include <stdlib.h>
// The function is used in vararg arguments in the s21_printf function
#include <stdarg.h>
// Include the itoa to convert int to string 
#include "s21_itoa.h"

int s21_sprintf(char *buffer, const char *format, ...);
void choose_return_type(char *buffer, const char *format, int *index, va_list argp);
void c_specifier(char *buffer, int *index, va_list argp);
void d_specifier(char *buffer, int *index, va_list argp);
void i_specifier(char *buffer, int *index, va_list argp);

enum is_true{
    FALSE,
    TRUE
};

#endif
