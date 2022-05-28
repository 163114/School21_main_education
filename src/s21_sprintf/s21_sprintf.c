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
+-        f, 
+            Find out what %f does:
+            %f converts floating-point number to the decimal notation in the style [-]ddd.ddd.
+-           Value range of %f: -340282346638528859811704183484516925440.000000 to 340282346638528859811704183484516925440.000000, precision - 6 decimal places
-            Precision specifies the exact number of digits to appear after the decimal point character. The default precision is 6.
-            if the precision is explicitly zero, no decimal-point character appears. If a decimal point appears, at least one digit appears before it.
+-        s,
+            Find out what %s does: 
+            Writes a character string
-            The argument must be a pointer to the initial element of an array of characters. Precision specifies the maximum number of bytes to be written. 
-            If Precision is not specified, writes every byte up to and not including the first null terminator. 
-            If a precision is given, no null character need be present; if the precision is not specified, or is greater than the size of the array, 
+            the array must contain a terminating NUL character.
+        u, 
+            Find out what %u does:
+            Unsigned decimal integer. 
+                What is unsigned? 
+                Unsigned int can hold only integers without a sign (minus). Only positive values and zero can be stored
+                Signed int can store postive and negative values
+                Maximum value for a variable of type unsigned int - 4 294 967 295
+                If I enter a negative value for the %u specifierm, it will go the opposite way. Ex = %u -3 == 4 294 967 293
+                (^In that case variable is repeatedly converted by adding or subtracting one or more than a maximum value until the value is in the range of the new type)
+                The floating point value gets cut off. 3.3 == 3
+                Value bigger than the max value that the unsigned int can store again goes through the range of 0 to 4 294 967 295
+                For example: 4 294 967 296 -> 0, 4 294 967 297 -> 1, 4 294 967 298 ->3, 8 589 934 590 -> 4 294 967 294
+        %
+            To print a percent sign character, use %%.
+            If a percent sign (%) is followed by a character that has no meaning as a format field, the character is simply copied to the buffer
    b. Flags:
+        Find out what the flags do.
            I need an atoi function to convert an array of chars to an int to implement the flags;
        -, 
            Left-justify the result within the field width.
            By default the result if right-justified
        +,
            Prefix the output value with a sign (+ or -) if the output value is of a signed type.
            By default sign appears only for negative signed values (-).
        (space)
            Prefix the output value with a blank if the output value is signed and positive.
            The + flag overrides the blank flag if both appear, and a positive signed value will be output with a sign.
    c. Width description: (number)
    d. Precision description: .(number)
    e. Length description: h, l
3. Memory testß
4. Test
5. Cpplint test
6. Add and push
*/

#include "s21_sprintf.h"

// // !!! THE COMMENTED CODE IS FOR TROUBLESHOOTING. DELETE THAT LATER
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

// char *s21_memset_uchar(char *string, unsigned char symbol, s21_size_t size) {
//     for (s21_size_t index = 0ul; index < size; ++index)
//         string[index] = symbol;
 
//     return string;

// }


// void *s21_memset(void *string, int symbol, s21_size_t size) {
//     unsigned char *string_uchar = (unsigned char*)string;
//     unsigned char symbol_uchar = (unsigned char)symbol;

//     char * result = s21_memset_uchar(string_uchar, symbol_uchar, size);
//     return result;
// }

// int main() {
//     char buffer[100];
//     // char exclamation_point = '!';
//     // int number = 2147483647;
//     // char *buffer = NULL;
//     // s21_sprintf(buffer, "Hello world%c!%c\n", exclamation_point, exclamation_point);
//     // s21_sprintf(buffer, "%d Hello world %d ! %d\n", number, number, number);
//     // double double_value = 112345.789;
//     double max = 340282346638528859811704183484516925440.000000;
//     s21_sprintf(buffer, "Hello world! %f", max);
//     puts(buffer);

//     return 0;
// }

int s21_sprintf(char *buffer, const char *format, ...) {
    // assert(buffer && "BUFFER SHOULD NOT BE NULL!!!!");
    // va_list is effictively a pointer to an arguments in the varargs array
    va_list argp;
    // After calling va_start argp points at the first vararg argument
    va_start(argp, format);
    int index = 0;
    while (*format != '\0') {
        if (*format == '%') {
            ++format;
            // The variable number_of_spaces is used to store the number of spaces the are going to be left or right justified later
            // int number_of_spaces = 0;
            int are_there_flags = FALSE;
            if ((are_there_flags = check_if_there_are_any_flags(&index, *format)) == TRUE) {
                
                // Probably the best way to do this would be to call this inside the function of a flag
                // number_of_spaces = s21_atoi(format);
            } else {
                // Here we can call another function to which we can pass variable arguments by passing a single va_list pointer
                choose_return_type(buffer, format, &index, argp);
                ++format;
            }
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

void choose_flag_type(char *buffer, const char *format, int *index) {
    
    if ('-' == *format) {
        left_justify_flag(buffer, format, index);
    }
}

void choose_return_type(char *buffer, const char *format, int *index, va_list argp) {
    // Maybe I can specify flags here. It may be easier
    if ('c' == *format) {
        c_specifier(buffer, index, argp);
    } else if ('d' == *format || 'i' == *format) {
        d_i_specifier(buffer, index, argp);
    } else if ('f' == *format) {
        f_specifier(buffer, index, argp);
    } else if ('s' == *format) {
        s_specifier(buffer, index, argp);
    } else if ('u' == *format) {
        u_specifier(buffer, index, argp);
    } else {
        percent_specifier(buffer, index, *format);
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

void f_specifier(char *buffer, int *index, va_list argp) {
    // Here I can implement the precision for the number. Just check the format with if else
    char array_for_double[49] = {'\0'};
    char *pointer_array_for_double = array_for_double;
    // Ask Misha what's wrong here - didn't build the file with the s21_memset library + Misha didn't compile the file with gcc flags. Going to use '\0' for now
    // s21_memset(array_for_double, 0, 49);
    // !!! Can be replaced with long double to work with bigger numbers. After that you should rework the data type in all nesting functions
    const double temp_arpg_variable = va_arg(argp, double);
    int dot_index = find_dot_index(temp_arpg_variable);
    // Write to the buffer the array_for_double. When you meet dot_index, insert dot char and continue to write chars until 6 decimal places of precision
    int array_for_double_index = 0;
    double_to_array_of_chars(pointer_array_for_double, temp_arpg_variable);
    // Append to the buffer the values before the dot. Ex: 12345.
    while (array_for_double_index != dot_index) {
        buffer[*index] = array_for_double[array_for_double_index];
        ++array_for_double_index;
        ++*index;
    }
    // Append dot to the buffer
    char dot = '.';
    buffer[*index] = dot;
    ++*index;
    // Append to the buffer the values after the dot. Maximum precision is 6. Ex: .123456
    int max_amount_of_precision = 6;
    for (int i = 0; i < max_amount_of_precision; ++i) {
        buffer[*index] = array_for_double[array_for_double_index];
        ++array_for_double_index;
        ++*index;
    }
}

int find_dot_index(double number) {
    int index = 0;
    double remainder = number;
    while (remainder >= 1) {
        remainder /= 10;
        ++index;
    }
    return index;
}

void double_to_array_of_chars(char *pointer_array_for_double, double temp_arpg_variable) {
    long long int double_without_floating_point = temp_arpg_variable * pow(10, 6);
    int index = 0, flip_index = 0;
    char temp_array_for_double[49] = {'\0'};
    // Write each number to the temp array. I'll need to flip temp later
    while (double_without_floating_point > 0) {
        temp_array_for_double[index] = (char)((double_without_floating_point % 10) + 48); // REPLACE 48 WITH '0'
        double_without_floating_point /= 10;
        ++index;
    }
    // For loop to flip the temp array
    for (int i = index - 1; i >= 0; --i) {
        pointer_array_for_double[flip_index] = temp_array_for_double[i];
        ++flip_index;
    }
}

void s_specifier(char *buffer, int *index, va_list argp) {
    int temp_argp_array_index = 0;
    char *pointer_temp_argp_array = va_arg(argp, char*);
    while (pointer_temp_argp_array[temp_argp_array_index] != '\0') {
        buffer[*index] = pointer_temp_argp_array[temp_argp_array_index];
        ++*index;
        ++temp_argp_array_index;
    }
}

void u_specifier(char *buffer, int *index, va_list argp) {
    char array_for_unsigned_int[12];
    int unsigned_int_array_index = 0;
    s21_itoa_unsigned(va_arg(argp, unsigned int), array_for_unsigned_int, 10);
    while (array_for_unsigned_int[unsigned_int_array_index] != '\0') {
        buffer[*index] = array_for_unsigned_int[unsigned_int_array_index];
        ++unsigned_int_array_index;
        ++*index;
    }
}

void percent_specifier(char *buffer, int *index, const char format) {
    buffer[*index] = format;
    ++*index;
}

int check_if_there_are_any_flags(char format, int *index) {
    int are_there_flags = FALSE;
    if ('-' == format || '+' == format || ' ' == format) {
        are_there_flags = TRUE;
        ++*index;
    }
    return are_there_flags;
}

void left_justify_flag(char *buffer, const char *format, int *index) {
    int number_of_spaces = 0;
    number_of_spaces = s21_atoi(format);

}