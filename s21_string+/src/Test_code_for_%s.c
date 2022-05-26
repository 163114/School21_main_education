#include "s21_sprintf.h"

int main() {
    char test_string[100] = "world!";
    char buffer[1024];
    s21_sprintf(buffer, "Hello %s", test_string);
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
    if ('s' == *format) {
        s_specifier(buffer, index, argp);
    }
}

void s_specifier(char *buffer, int *index, va_list argp) {
    char temp_argp_array[1024] = "\0";
    char *pointer_temp_argp_array = temp_argp_array;
    pointer_temp_argp_array = va_arg(argp, char*);
    int temp_argp_array_index = 0;
    while (*pointer_temp_argp_array != '\0') {
        buffer[*index] = temp_argp_array[temp_argp_array_index];
        ++*index;
        ++temp_argp_array_index;
        ++pointer_temp_argp_array;
    }
}