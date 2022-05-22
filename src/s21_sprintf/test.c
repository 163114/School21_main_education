// Testing file for small functions
// double lowest = -340 282 346 638 528 859 811 704 183 484 516 925 440.000000;
// double max = 340282346638528859811704183484516925440.000000;

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

int s21_sprintf(char *buffer, const char *format, ...);
void choose_return_type(char *buffer, const char *format, int *index, va_list argp);
void c_specifier(char *buffer, int *index, va_list argp);
void d_i_specifier(char *buffer, int *index, va_list argp);
void f_specifier(char *buffer, int *index, va_list argp);

int find_dot_index(double number);
void double_to_array_of_chars(char *pointer_array_for_double, double temp_arpg_variable);

int main() {
    char buffer[5000];
    double double_value = 34028234663815678.000000;
    s21_sprintf(buffer, "Hello, World %f", double_value, double_value, double_value, double_value, double_value, double_value);
    puts(buffer);
    return 0;
}

int s21_sprintf(char *buffer, const char *format, ...) {
    va_list argp;
    va_start(argp, format);
    int index = 0, number_of_specifires = 0;
    while (*format != '\0') {
        if (*format == '%') {
            ++number_of_specifires;    
            ++format;
            choose_return_type(buffer, format, &index, argp);
            ++format;
        } else {
            buffer[index] = *format;
            ++index;
            ++format;
        }
    }
    va_end(argp);
    return index;
}

void choose_return_type(char *buffer, const char *format, int *index, va_list argp) {
    if ('f' == *format) {
        f_specifier(buffer, index, argp);
    }
}

void f_specifier(char *buffer, int *index, va_list argp) {
    // char array_for_double[49] = {'\0'};
    char array_for_double[490] = {'\0'};
    char *pointer_array_for_double = array_for_double;
    const double temp_arpg_variable = va_arg(argp, double);
    int dot_index = find_dot_index(temp_arpg_variable);
    int array_for_double_index = 0;
    double_to_array_of_chars(pointer_array_for_double, temp_arpg_variable);
    while (array_for_double_index != dot_index) {
        buffer[*index] = array_for_double[array_for_double_index];
        ++array_for_double_index;
        ++*index;
    }
    char dot = '.';
    buffer[*index] = dot;
    ++*index;
    int max_amount_of_precision = 6;
    for (int i = 0; i < max_amount_of_precision; ++i) {
        buffer[*index] = array_for_double[array_for_double_index];
        ++array_for_double_index;
        ++*index;
    }
}

int find_dot_index(double number) {
    int index = 0;
    double remainder = number;
    while (remainder >= 1) {
        remainder /= 10;
        ++index;
    }
    return index;
}

void double_to_array_of_chars(char *pointer_array_for_double, double temp_arpg_variable) {
    // HERE I NEED TO ROUND THE NUMBER BEFORE THE DEVISION BY 10
    long long int double_without_floating_point = temp_arpg_variable * pow(10, 6); // Breaks here
    int index = 0, flip_index = 0;
    // char temp_array_for_double[49] = {'\0'};
    char temp_array_for_double[490] = {'\0'};
    while (double_without_floating_point > 0) {
        temp_array_for_double[index] = (char)((double_without_floating_point % 10) + 48);
        double_without_floating_point /= 10;
        ++index;
    }
    for (int i = index - 1; i >= 0; --i) {
        pointer_array_for_double[flip_index] = temp_array_for_double[i];
        ++flip_index;
    }
}
