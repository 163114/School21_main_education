// Copyright 2022 finchren
/*
Task - Implement the sprintf function from the stdio.h library
What to return - number of characters written to buffer 
(not counting the terminating null character), or a negative value if an encoding error (for string and character conversion specifiers) occurred
+ 1. Write the results to a character string buffer
2. Formatting support:
    a. Specifiers: 
+        c, 
+            To finish testing of %c I need to finish %d for. Want to test how works %c as %d and the other way around
+        d,
+            Itoa function
+            Put the argp in the array of chars and append to the buffer
+        i, 
+            Find out the difference between the %d and %i: 
+            %d takes integer value as signed decimal integer i.e. it takes negative values along with positive values but values should be in decimal
+            otherwise it will print garbage value.( Note: if input is in octal format like:012 then %d will ignore 0 and take input as 12).
+            %i takes integer value as integer value with decimal, hexadecimal or octal type.
+            To enter a value in hexadecimal format – value should be provided by preceding “0x” and value in octal format – value should be provided by preceding “0”.
        f, 
            Find out what %f does:
            %f converts floating-point number to the decimal notation in the style [-]ddd.ddd.
            Value range of %f: -340282346638528859811704183484516925440.000000 to 340282346638528859811704183484516925440.000000, precision - 6 decimal places
            If value is bigger or less than the range, then "inf" or "-inf" is displayed
            Precision specifies the exact number of digits to appear after the decimal point character. The default precision is 6.
            if the precision is explicitly zero, no decimal-point character appears. If a decimal point appears, at least one digit appears before it.
            To implement %f I need to divide the double value of vararg by to 10 to the power of the number of digits. Ex: 
            12345.12345
            10 to the power of -6 (6 numbers before the point and 6 after)
            !!! if (double varg % pow(10, -1) != 0) - condition for floating point numbers
            Or I can print out the numbers and at specific point print out the dot. For that I would need to store the index of the number with a whle case "while (remainder > 0)". If false, then I remember the index

            1. Write a function to find the lenght of the double number
            2. Find the index of the dot
            3. Think about the 
        s, 
        u, 
+        %
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
//     // char buffer[100];
//     // char exclamation_point = '!';
//     int number = 2147483647;
//     char *buffer = NULL;
//     // s21_sprintf(buffer, "Hello world%c!%c\n", exclamation_point, exclamation_point);
//     s21_sprintf(buffer, "%d Hello world %d ! %d\n", number, number, number);
//     // puts(buffer);
//     return 0;
// }

int s21_sprintf(char *buffer, const char *format, ...) {
    // assert(buffer && "BUFFER SHOULD NOT BE NULL!!!!");
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
    // Upon successful return, the function returns the number of characters printed (excluding the null byte used to end output to strings).
    return index;
}

void choose_return_type(char *buffer, const char *format, int *index, va_list argp) {
    if ('c' == *format) {
        c_specifier(buffer, index, argp);
    }
    // Improved d_i_specifier function to work with %i too
    if ('d' == *format || 'i' == *format) {
        d_i_specifier(buffer, index, argp);
    }
    if ('f' == *format) {
        f_specifier(buffer, index, argp);
    }
}

void c_specifier(char *buffer, int *index, va_list argp) {
    buffer[*index] = va_arg(argp, int);
    ++*index;
}

void d_i_specifier(char *buffer, int *index, va_list argp) {
    char array_for_int[12];
    int int_array_index = 0;
    s21_itoa(va_arg(argp, int), array_for_int, 10);
    while (array_for_int[int_array_index] != '\0') {
        buffer[*index] = array_for_int[int_array_index];
        ++int_array_index;
        ++*index;
    }
}

// !!! Redundant function below. I immproved d_i_specifier function to work with %i
// void i_specifier(char *buffer, int *index, va_list argp) {
//     char array_for_int[12];
//     int int_array_index = 0;
//     // Use const variable that is equal to va_arg(argp, int). I need to check the cases in the notebook and then use that const value to pass to itoa with a needed base
//     const int va_arg_const = va_arg(argp, int); 
//     // int size_of_array = 0;
//     char flipped_array[12];
//     char *pointer_to_flipped_array = flipped_array;
//     flip_to_array(va_arg_const, pointer_to_flipped_array);
//     d_specifier(buffer, index, flipped_array);
//     // s21_itoa(va_arg_const, array_for_int, 10);
//     // while (array_for_int[int_array_index] != '\0') {
//     //     buffer[*index] = array_for_int[int_array_index];
//     //     ++int_array_index;
//     //     ++*index;
//     // }
// }

void f_specifier(char *buffer, int *index, va_list argp) {
    char array_for_float[48];
    int float_array_index = 0;
    s21_itoa(va_arg(argp, double), array_for_float, 10);
    while (array_for_float[float_array_index] != '\0') {
        buffer[*index] = array_for_float[float_array_index];
        ++float_array_index;
        ++*index;
    }
}

// // 1. Flip the va_arg_const. I need to do this so I could access '0x'-like values in the begging of the va_arg number
// // 2. Implement choose_base function after I flip the va_arg_const to an array of chars
// // Here I should choose the base on itoa based on the last chars of the flipped array of chars
// // int choose_base(int va_arg_const, ) {
// //     int base = 10;

// //     return base;
// // }

// int flip_to_array(int number_to_flip, char *pointer_to_array) {
//     int temp_num = number_to_flip, temp_single_num = 0, index = 0;
//     while (temp_num > 0) {
//         temp_single_num = temp_num % 10;
//         if (index == 0) {
//             pointer_to_array[index] = (char)temp_single_num;
//             temp_num /= 10;
//             index += 1;
//         } else {
//             pointer_to_array[index] = (char)temp_single_num;
//             temp_num /= 10;
//             index += 1;
//         }
//     }
//     return index;
// }
