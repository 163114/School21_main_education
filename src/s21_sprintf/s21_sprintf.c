#include "s21_sprintf.h"

void choose_return_type(char *buffer, const char *format, int index, va_list argp) {
    if ('c' == *format) {
        c_specifier(buffer, index, argp);
    }
    
}

void c_specifier(char *buffer, int index, va_list argp) {
    buffer[index] = va_arg(argp, int);
}
int s21_sprintf(char *buffer, const char *format, ...) {
    // va_list is effictively a pointer to an arguments in the varargs array
    va_list argp;
    // After calling va_start argp points at the first vararg argument
    va_start(argp, format);
    int index = 0;
    while (*format != '\0') {
        if (*format == '%') {
        ++format;
        // Here we can call another function to which we can pass variable arguments by passing a single va_list pointer
        choose_return_type(buffer, format, index, argp);
        ++format;
        ++index;
        } else {
            buffer[index] = *format;
            ++index;
            ++format;
        }
    }
    // We call va_end to stop consuming the vararg arguments
    va_end(argp);
    return 0;
}


