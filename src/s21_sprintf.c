// Copyright 2022 finchren
/*
Task - Implement the sprintf function from the stdio.h library
+ 1. Write the results to a character string buffer
2. Formatting support:
    a. Specifiers: c, d, i, f, s, u, %
        + 1. Choose return type funciton
        2. Pass to the choose return type function pointer to int which is going to point to data type. Write a function that calls 
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
// Include the the char array of specifiers
#include "s21_specifiers.h"

int s21_sprintf(char *str, const char *format, ...);
int choose_return_type(const char *format, int *specifier_index);

enum is_true{
    FALSE,
    TRUE
};

int main() {
    char *pointer_str_array;
    pointer_str_array = (char*)malloc(1*sizeof(char));
    if (pointer_str_array == NULL) {
        printf("Memory could not be allocated");
    } else {
        char exclamation_point = '!';
        s21_sprintf(pointer_str_array, "Hello world%c!%c\n", exclamation_point, exclamation_point);
        puts(pointer_str_array);
        
        free(pointer_str_array);
        pointer_str_array = NULL;
        char *pointer_str_array;
        pointer_str_array = (char*)malloc(1*sizeof(char));
        char hello[5] = {'H', 'e', 'l', 'l', 'o'};
        s21_sprintf(pointer_str_array, "%s world%c!%c\n", hello, exclamation_point, exclamation_point);
        puts(pointer_str_array);
    }
    free(pointer_str_array);
    pointer_str_array = NULL;
    return 0;
}

int choose_return_type(const char *format, int *specifier_index) {
    int amount_of_specifiers = 15, is_true = FALSE;
    for (int i = 0; i < amount_of_specifiers; ++i) {
        if (specifiers[i] == *format) {
            is_true = TRUE;
            printf("i = %d", i);
            *specifier_index = i;
        }
    }
    return is_true;
}

int s21_sprintf(char *str, const char *format, ...) {
    // va_list is effictively a pointer to an arguments in the varargs array
    va_list argp;
    // After calling va_start argp ooints at the first vararg argument
    va_start(argp, format);
    int realloc_counter = 2, index = 0, specifier_index = -1;
        while (*format != '\0') {
            if (*format == '%') {
                ++format;
                if (choose_return_type(format, &specifier_index)) {
                    char char_to_print = '\0';
                    if (specifier_index == CHARACTER_C ||
                        specifier_index == SIGNED_DECIMAL_INTEGER_D ||
                        specifier_index == SIGNED_INTEGER_I ||
                        specifier_index == UNSINGNED_OCTAL_O) {
                        // va_arg takes the pointer and a type, 
                        // increments the pointer by that size and returns it as a char
                        char_to_print = va_arg(argp, int); 
                        // should be char for CHARACTER_C but for whatever reason it doesn't allow to set datatype to char
                    } else if (specifier_index == DECIMAL_FLOATING_POINT_E ||
                            specifier_index == DECIMAL_FLOATING_POINT_E_CAPITAL ||
                            specifier_index == DECIMAL_FLOATING_POINT_F ||
                            specifier_index == DECIMAL_FLOATING_POINT_G ||
                            specifier_index == DECIMAL_FLOATING_POINT_G_CAPTIAL) {
                        char_to_print = va_arg(argp, double); // float
                    } else if (specifier_index == STRING_S) {
                        char_to_print = va_arg(argp, int);
                    } 
                    str[index] = char_to_print;
                    ++index;
                    continue;
                }
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
