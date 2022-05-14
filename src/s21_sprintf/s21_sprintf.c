// Copyright 2022 finchren
/*
Task - Implement the sprintf function from the stdio.h library
+ 1. Write the results to a character string buffer
2. Formatting support:
    + a. Specifiers: c, d, i, f, s, u, %
        + 1. Choose return type funciton
        + 2. Pass to the choose function return type function pointer to int which is going to point to data type in enum. Write an if-else
    b. Flags: -, +, (space)
    c. Width description: (number)
    d. Precision description: .(number)
    e. Length description: h, l
3. Memory test
4. Test
5. Cpplint test
6. Implement the function in the s21_string.h library
*/

#include "s21_sprintf.h"
// Include the the char array of specifiers
#include "s21_specifiers.h"

int main() {
    char *pointer_str_array;
    pointer_str_array = (char*)malloc(1*sizeof(char));
    if (pointer_str_array == NULL) {
        printf("Memory could not be allocated");
    } else {
    
        // %c
        char exclamation_point = '!';
        // s21_sprintf(pointer_str_array, "Hello world%c!%c\n", exclamation_point, exclamation_point);
        // puts(pointer_str_array);

        // %d
        // ASCII table int 6 == char 54; I think I should do the following - if int -> value + 48 to convert to char for ASCII
        int number_six = 15;
        s21_sprintf(pointer_str_array, "Hello world%d!%c\n", number_six, exclamation_point);
        puts(pointer_str_array);

        // %s        
        // char hello[] = "Hello";
        // s21_sprintf(pointer_str_array, "%s world%c!%c\n", hello, exclamation_point, exclamation_point);
        // puts(pointer_str_array);
    }
    free(pointer_str_array);
    pointer_str_array = NULL;
    return 0;
}

int choose_return_type(const char *buffer, int *specifier_index) {
    int amount_of_specifiers = 15, is_true = FALSE;
    for (int i = 0; i < amount_of_specifiers; ++i) {
        if (specifiers[i] == *buffer) {
            is_true = TRUE;
            printf("i = %d\n", i);
            *specifier_index = i;
        }
    }
    return is_true;
}

int s21_sprintf(char *buffer, const char *format, ...) {
    // va_list is effictively a pointer to an arguments in the varargs array
    va_list argp;
    // After calling va_start argp ooints at the first vararg argument
    va_start(argp, format);
    int realloc_counter = 2, index = 0, specifier_index = -1;
        while (*format != '\0') {
            if (*format == '%') {
                ++format;
                if (choose_return_type(format, &specifier_index)) {
                    // Variable for char for string function
                    char char_to_print = '\0';
                    // Variable for int
                    int int_type_to_print = 0;
                    // Pointer for strings and address
                    const char *pointer_char_to_print = &char_to_print;
                    if (specifier_index == CHARACTER_C) {
                        // va_arg takes the pointer and a type, 
                        // increments the pointer by that size and returns it as a char
                        int_type_to_print = va_arg(argp, int); 
                    } else if (specifier_index == SIGNED_DECIMAL_INTEGER_D ||
                        specifier_index == SIGNED_INTEGER_I) {
                        int_type_to_print = va_arg(argp, int);
                        int_type_to_print += 48;
                    } else if (specifier_index == DECIMAL_FLOATING_POINT_E ||
                        specifier_index == DECIMAL_FLOATING_POINT_E_CAPITAL ||
                        specifier_index == DECIMAL_FLOATING_POINT_F ||
                        specifier_index == DECIMAL_FLOATING_POINT_G ||
                        specifier_index == DECIMAL_FLOATING_POINT_G_CAPTIAL) {
                        char_to_print = va_arg(argp, double);
                    } else if (specifier_index == UNSINGNED_OCTAL_O ||
                        specifier_index == UNSIGNED_DECIMAL_INTEGER_U ||
                        specifier_index == UNSIGNED_HEXADECIMAL_INTEGER_X ||
                        specifier_index == UNSIGNED_HEXADECIMAL_INTEGER_X_CAPITAL) {
                        char_to_print = va_arg(argp, unsigned int);
                    } else if (specifier_index == STRING_S) {
                        pointer_char_to_print = va_arg(argp, char*);
                        char_to_print = *pointer_char_to_print;
                    } else if (specifier_index == POINTER_ADDRESS_P) {
                         pointer_char_to_print = va_arg(argp, void*);
                         char_to_print = *pointer_char_to_print;
                    } 
                    printf("Inside the while loop - %d\n", int_type_to_print);
                    buffer[index] = ((char)int_type_to_print);
                    ++index;
                    ++format;
                    continue;
                }
            } else {
                buffer[index] = *format;
                buffer = (char*)realloc(buffer, (realloc_counter)*sizeof(char));
                ++realloc_counter;
                ++index;
            }
            ++format;
        }
    // We call va_end to stop consuming the vararg arguments
    va_end(argp);
    return 0;
}
