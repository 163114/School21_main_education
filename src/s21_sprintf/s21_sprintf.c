// Copyright 2022 finchren
/*
Task - Implement the sprintf function from the stdio.h library
What to return - number of characters written to buffer 
(not counting the terminating null character), or a negative value if an encoding error (for string and character conversion specifiers) occurred
+ 1. Write the results to a character string buffer
2. Formatting support:
    a. Specifiers: 
+       c, 
            To finish testing of %c I need to finish %d for. Want to test how works %c as %d and the other way around
        d,
+           Itoa function
+           Put the argp number in the array of chars
+           Find the lenght of that array - Probably don't need to do this. I can just go until \0
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

char* s21_itoa(int number, char *buffer, int base) {
    int current = 0;  
    if (number == 0) {  
        buffer[current++] = '0';  
        buffer[current] = '\0';  
        return buffer;  
    }  
    int num_digits = 0;  
    if (number < 0) {  
        if (base == 10) {  
        ++num_digits;  
        buffer[current] = '-';  
        ++current;  
        number *= -1;  
    } else { 
        return NULL;
        }  
    }  
    num_digits += (int)floor(log(number) / log(base)) + 1;  
    while (current < num_digits) {  
        int base_val = (int) pow(base, num_digits -1 -current);  
        int num_val = number / base_val;  
        char value = num_val + '0';  
        buffer[current] = value;  
        ++current;  
        number -= base_val * num_val;  
    }  
    buffer[current] = '\0';  
    return buffer;  
}

int main() {
    char buffer[100];
    // char exclamation_point = '!';
    int number = 2147483640;
    // s21_sprintf(buffer, "Hello world%c!%c\n", exclamation_point, exclamation_point);
    s21_sprintf(buffer, "Hello world%d!%d\n", number, number);
    puts(buffer);
    return 0;
}

int s21_sprintf(char *buffer, const char *format, ...) {
    // va_list is effictively a pointer to an arguments in the varargs array
    va_list argp;
    // After calling va_start argp points at the first vararg argument
    va_start(argp, format);
    int index = 0, number_of_specifires = 0;
    while (*format != '\0') {
        if (*format == '%') {
            ++number_of_specifires;    
            ++format;
            // Here we can call another function to which we can pass variable arguments by passing a single va_list pointer
            choose_return_type(buffer, format, &index, argp);
            ++format;
            // ++index; Moved index to separate funcitons because like in case with int a parameter may consist of multiple indexes
        } else {
            buffer[index] = *format;
            ++index;
            ++format;
        }
    }
    // We call va_end to stop consuming the vararg arguments
    va_end(argp);
    return index;
}

void choose_return_type(char *buffer, const char *format, int *index, va_list argp) {
    if ('c' == *format) {
        c_specifier(buffer, index, argp);
    }
    if ('d' == *format) {
        d_specifier(buffer, index, argp);
    }
}

void c_specifier(char *buffer, int *index, va_list argp) {
    buffer[*index] = va_arg(argp, int);
    ++*index;
}

void d_specifier(char *buffer, int *index, va_list argp) {
    char array_for_int[10];
    int int_array_index = 0;
    s21_itoa(va_arg(argp, int), array_for_int, 10);
    while (array_for_int[int_array_index] != '\0') {
        // printf("array_for_int[int_array_index] in while looop - %c\n", array_for_int[int_array_index]);
        buffer[*index] = array_for_int[int_array_index];
        ++int_array_index;
        ++*index;
    }
}
