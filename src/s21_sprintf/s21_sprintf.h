#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <stdio.h>
#include <stdlib.h>
// The function is used in vararg arguments in the s21_printf function
#include <stdarg.h>
#include <math.h>

// Include itoa function to convert int to string 
#include "s21_itoa.h"
// Include atoa function to convert string to int
#include "s21_atoi.h"
// Include s21_memset.h to fill the empty arrays with value to escape unnecessary errors
#include "../s21_memset/s21_memset.h"
//#include <assert.h>

int s21_sprintf(char *buffer, const char *format, ...);
void choose_return_type(char *buffer, const char *format, int *index, va_list argp);
void c_specifier(char *buffer, int *index, va_list argp);
void d_i_specifier(char *buffer, int *index, va_list argp);
void f_specifier(char *buffer, int *index, va_list argp);
int find_dot_index(double number);
void double_to_array_of_chars(char *pointer_array_for_double, double temp_arpg_variable);
void s_specifier(char *buffer, int *index, va_list argp);
void u_specifier(char *buffer, int *index, va_list argp);
void percent_specifier(char *buffer, int *index, const char format);
int check_if_there_are_any_flags(char format, int *index);
void choose_flag_type(char *buffer, const char *format, int *index);
void left_justify_flag(char *buffer, const char *format, int *index);

// Can be removed if not used in the code to fill the arrays with default values
void *s21_memset(void *string, int symbol, s21_size_t size);
char *s21_memset_uchar(char *string, unsigned char symbol, s21_size_t size);

enum is_true_or_false{
    FALSE,
    TRUE
};

#endif //  S21_SPRINTF_H
