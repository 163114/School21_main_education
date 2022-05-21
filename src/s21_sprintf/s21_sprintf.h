#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <stdio.h>
#include <stdlib.h>
// The function is used in vararg arguments in the s21_printf function
#include <stdarg.h>
#include <math.h>
// Include the itoa to convert int to string 
#include "s21_itoa.h"
#include <assert.h>

int s21_sprintf(char *buffer, const char *format, ...);
void choose_return_type(char *buffer, const char *format, int *index, va_list argp);
void c_specifier(char *buffer, int *index, va_list argp);
void d_i_specifier(char *buffer, int *index, va_list argp);
// void i_specifier(char *buffer, int *index, va_list argp); - Redundant. May need in the future. Going to save it for now just in case
// int flip_to_array(int number_to_flip, char *pointer_to_array); - Redundant. May need in the future. Going to save it for now just in case
void f_specifier(char *buffer, int *index, va_list argp);

// enum is_true{
//     FALSE,
//     TRUE
// };

#endif //  S21_SPRINTF_H
