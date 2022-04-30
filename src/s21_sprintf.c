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

int s21_sprintf(char *str, const char *format, ...);

enum is_true {
    FALSE,
    TRUE
};

int main() {
    char *pointer_str_array;
    pointer_str_array = (char*)malloc(1*sizeof(char));
    if (pointer_str_array == NULL) {
        printf("Memory could not be allocated");
    } else {
        sprintf_mine(pointer_str_array, "Hello world");
        puts(pointer_str_array);
    }
    free(pointer_str_array);
    pointer_str_array = NULL;
    return 0;
}

int s21_sprintf_mine(char *str, const char *format, ...) {
    int realloc_counter = 2, specifier_counter = 0, is_true = TRUE;
    // Endless for loop to iterate over the string and add it to the buffer
    // It's not the most beautiful solution. Should replace it later
    for (int i = 0; i > -1; ++i) {
        while (is_true) {
            if (format[i] != '\0') {
                is_true = FALSE;
            } else if (format[i] == '%') {
                ++specifier_counter;
                continue;
            } else {
                str[i] = format[i];
                str = (char*)realloc(str, (realloc_counter)*sizeof(char));
                ++realloc_counter;
            }
        }
    }
    return 0;
}
