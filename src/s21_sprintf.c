// Copyright 2022 finchren
/*
Task - Implement the sprintf function from the stdio.h library
+ 1. Write the results to a character string buffer
2. Formatting support:
    a. Specifiers: c, d, i, f, s, u, %
    b. Flags: -, +, (space)
    c. Width description: (number)
    d. Precision description: .(number)
    e. Length description: h, l
3. Memory test
4. Test
5. Cpplint test
6. Implement the function in the s21_string.h library
*/

#include <stdio.h>
#include <stdlib.h>
// The function is used in vararg arguments in the s21_printf function
#include <stdarg.h>

int s21_sprintf(char *str, const char *format, ...);

int main() {
    char *pointer_str_array;
    pointer_str_array = (char*)malloc(1*sizeof(char));
    if (pointer_str_array == NULL) {
        printf("Memory could not be allocated");
    } else {
        char exclamation_point = '!';
        sprintf(pointer_str_array, "Hello world%c", exclamation_point);
        puts(pointer_str_array);
    }
    free(pointer_str_array);
    pointer_str_array = NULL;
    return 0;
}

int s21_sprintf(char *str, const char *format, ...) {
    // va_list is effictively a pointer to an arguments in the varargs array
    va_list argp;
    // After calling va_start argp ooints at the first vararg argument
    va_start(argp, format);
    int realloc_counter = 2, specifier_counter = 0, index = 0;
        while (*format != '\0') {
            if (*format == '%') {
                ++specifier_counter;
                continue;
            } else if (*format == 'c') {
                char char_to_print = va_arg(argp, int);
                str[index] = char_to_print;;
                ++index;
                continue;
            } else {
                str[index] = *format;
                str = (char*)realloc(str, (realloc_counter)*sizeof(char));
                ++realloc_counter;
                ++index;
            }
            ++format;
        }
    // We call va_end to stop consuming the vararg arguments
    va_end(argp);
    return 0;
}
