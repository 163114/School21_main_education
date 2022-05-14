// Copyright 2022 finchren
/*
Task - Implement the sprintf function from the stdio.h library
What to return - number of characters written to buffer 
(not counting the terminating null character), or a negative value if an encoding error (for string and character conversion specifiers) occurred
1. Write the results to a character string buffer
2. Formatting support:
    a. Specifiers: 
        c, 
        d, 
        i, 
        f, 
        s, 
        u, 
        %
    b. Flags: 
        -, 
        +, 
        (space)
    c. Width description: (number)
    d. Precision description: .(number)
    e. Length description: h, l
3. Memory test
4. Test
5. Cpplint test
6. Implement the function in the s21_string.h library
*/

#include "s21_sprintf.h"

// int main() {
//     char buffer[100];
//     char exclamation_point = '!';
//     // int number = 15;
//     s21_sprintf(buffer, "Hello world%c!%c\n", exclamation_point, exclamation_point);
//     puts(buffer);
//     return 0;
// }

int s21_sprintf(char *buffer, const char *format, ...) {
    // va_list is effictively a pointer to an arguments in the varargs array
    va_list argp;
    // After calling va_start argp points at the first vararg argument
    va_start(argp, format);
    int index = 0, number_of_specifires = 0, number_of_arguments = 0;
    while (*format != '\0') {
        if (*format == '%') {
            ++number_of_specifires;    
            ++format;
            // Here we can call another function to which we can pass variable arguments by passing a single va_list pointer
            choose_return_type(buffer, format, index, &number_of_arguments, argp);
            ++format;
            ++index;
        } else {
            buffer[index] = *format;
            ++index;
            ++format;
        }
    }
    if (number_of_arguments != number_of_arguments) {
        index = -1;
    }
    // We call va_end to stop consuming the vararg arguments
    va_end(argp);
    return index;
}

void choose_return_type(char *buffer, const char *format, int index, int *number_of_arguments, va_list argp) {
    if ('c' == *format) {
        c_specifier(buffer, index, number_of_arguments, argp);
    }
}

void c_specifier(char *buffer, int index, int *number_of_arguments, va_list argp) {
    buffer[index] = va_arg(argp, int);
    ++number_of_arguments;
}