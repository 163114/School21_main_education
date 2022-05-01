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

/*
#define function1(type,argp) \
{ \
if (type == 'd') \
    return va_arg(argp, int); \
if (type == 'c') \
    return va_arg(argp, char); \
}
*/

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
        s21_sprintf(pointer_str_array, "Hello world%c!%c", exclamation_point, exclamation_point);
        puts(pointer_str_array);
        
        // Want to see how other types work besides char and int
        free(pointer_str_array);
        pointer_str_array = NULL;
        char *pointer_str_array;
        pointer_str_array = (char*)malloc(1*sizeof(char));
        int c = 28;
        s21_sprintf(pointer_str_array, "Unsigned hexadecimal integer - %x\n", c);
        puts(pointer_str_array);
        // End of test for %x. Delete that later
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
    // Delete that later
    // printf("specifier index in return choose = %d\n", *specifier_index);
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
                // Replace that if with a function to keep specifier easy, short and simple
                // Add pointer to index of char specifier and call that index using an enum
                // where each one is specific type of data
                    if (choose_return_type(format, &specifier_index)) {
                    char char_to_print = va_arg(argp, int);
                    str[index] = char_to_print;
                    // printf("%d\n", specifier_index);
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
