// Copyright 2022 finchren
/*
Task - Implement the sprintf function from the stdio.h library
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

#include "s21_sprintf_new.h"

int main() {
    char *buffer;
    buffer = (char*)malloc(1*sizeof(char));
    if (buffer == NULL) {
        printf("Memory could not be allocated");
    } else {

        char exclamation_point = '!';
        // int number = 15;
        s21_sprintf(buffer, "Hello world%c!%c\n", exclamation_point, exclamation_point);
        // puts(buffer);
        printf("buffer = %s\n", buffer);

    }
    free(buffer);
    buffer = NULL;
    return 0;
}

int s21_sprintf(char *buffer, const char *format, ...) {
    // va_list is effictively a pointer to an arguments in the varargs array
    va_list argp;
    // After calling va_start argp points at the first vararg argument
    va_start(argp, format);
    int realloc_counter = 2, index = 0;
    while (*format != '\0') {
        if (*format == '%') {
        ++format;
        // Here we can call another function to which we can pass variable arguments by passing a single va_list pointer
        choose_return_type(buffer, format, index, argp);
        // int for_testing = va_arg(argp, int);
        // printf("inside the while loop = %c, run number = %d\n", for_testing, index);
        } else {
            buffer[index] = *format;
            buffer = (char*)realloc(buffer, (realloc_counter)*sizeof(char));
            ++index;
            ++format;
        }
    }
    // We call va_end to stop consuming the vararg arguments
    va_end(argp);
    return 0;
}

void choose_return_type(char *buffer, const char *format, int index, va_list argp) {
    // int for_testing = va_arg(argp, int);
    // printf("inside the choose return type = %c, run number = %d\n", for_testing, index);
    if ('c' == *format) {
        c_specifier(buffer, index, argp);
    }
    
}

void c_specifier(char *buffer, int index, va_list argp) {
    // int for_testing = va_arg(argp, int);
    // printf("inside the c specifier = %c, run number = %d\n", for_testing, index);
    // int char_to_append = va_arg(argp, int);
    // buffer[index] = va_arg(argp, int);
    buffer[index] = va_arg(argp, int);
    printf("buffer[index] = %d  %c\n", buffer[index], buffer[index]);
}