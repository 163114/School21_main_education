// Copyright 2022 finchren
/*
Task - Implement the sprintf function from the stdio.h library
What to return - number of characters written to buffer 
(not counting the terminating null character), or a negative value if an encoding error (for string and character conversion specifiers) occurred
+ 1. Write the results to a character string buffer
2. Formatting support:
    a. Specifiers: 
+       c, 
+            To finish testing of %c I need to finish %d for. Want to test how works %c as %d and the other way around
+        d,
+           Itoa function
+           Put the argp in the array of chars and append to the buffer
        i, 
            Find out the difference between the %d and %i: 
            %d takes integer value as signed decimal integer i.e. it takes negative values along with positive values but values should be in decimal
            otherwise it will print garbage value.( Note: if input is in octal format like:012 then %d will ignore 0 and take input as 12).
            %i takes integer value as integer value with decimal, hexadecimal or octal type.
            To enter a value in hexadecimal format – value should be provided by preceding “0x” and value in octal format – value should be provided by preceding “0”.
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

// !!! THE COMMENTED CODE IS FOR TROUBLESHOOTING. DELETE THAT LATER
// char* s21_itoa(int number, char *buffer, int base) {
//     int current = 0;
//     if (number == 0) {
//         buffer[current++] = '0';
//         buffer[current] = '\0';
//         return buffer;
//     }
//     int num_digits = 0;
//     if (number < 0) {
//         if (base == 10) {
//         ++num_digits;
//         buffer[current] = '-';
//         ++current;
//         number *= -1;
//     } else {
//         return NULL;
//         }
//     }
//     num_digits += (int)floor(log(number) / log(base)) + 1;
//     while (current < num_digits) {
//         int base_val = (int) pow(base, num_digits -1 -current);
//         int num_val = number / base_val;
//         char value = num_val + '0';
//         buffer[current] = value;
//         ++current;
//         number -= base_val * num_val;
//     }
//     buffer[current] = '\0';
//     return buffer;
// }

// int main() {
//     char buffer[100];
//     // char exclamation_point = '!';
//     int number = 2147483647;
//     // s21_sprintf(buffer, "Hello world%c!%c\n", exclamation_point, exclamation_point);
//     s21_sprintf(buffer, "%d Hello world %d ! %d\n", number, number, number);
//     puts(buffer);
//     return 0;
// }

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
    if ('i' == *format) {
        d_specifier(buffer, index, argp);
    }
}

void c_specifier(char *buffer, int *index, va_list argp) {
    buffer[*index] = va_arg(argp, int);
    ++*index;
}

void d_specifier(char *buffer, int *index, va_list argp) {
    char array_for_int[12];
    int int_array_index = 0;
    s21_itoa(va_arg(argp, int), array_for_int, 10);
    while (array_for_int[int_array_index] != '\0') {
        buffer[*index] = array_for_int[int_array_index];
        ++int_array_index;
        ++*index;
    }
}

void i_specifier(char *buffer, int *index, va_list argp) {
    char array_for_int[12];
    int int_array_index = 0;
    // Use const variable that is equal to va_arg(argp, int). I need to check the cases in the notebook and then use that const value to pass to itoa with a needed base
    const int va_arg_const = va_arg(argp, int); 
    s21_itoa(va_arg_const, array_for_int, 10);
    while (array_for_int[int_array_index] != '\0') {
        buffer[*index] = array_for_int[int_array_index];
        ++int_array_index;
        ++*index;
    }
}

int choose_base(int va_arg_const, ) {
    int base = 10;

    return base;
}