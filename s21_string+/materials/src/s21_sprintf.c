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
-            If a precision is given, no null character needs be present; if the precision is not specified, or is greater than the size of the array, 
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
+ 3. Memory test
+ 4. Test
+ 5. Cpplint test
+ 6. Add and push
*/

#include "s21_sprintf.h"
#include <assert.h>
#include "s21_string.h"

#include <stdio.h>

enum is_true_or_false{
    FALSE = 0,
    TRUE = 1
};

typedef struct Specifiers {
    char c;
    char d;
    char i;
    char e;
    char E;
    char f;
    char g;
    char G;
    char o;
    char s;
    char u;
    char x;
    char X;
    char p;
    char n;
    char percent;
    char plus;
    char minus;
    char space;

    char hashtag;
    char zero;

    int width;
    int precision;
    char is_precision_default;

    char star;

    char h;
    char l;
    char ll;
    char L;
} Specifiers;


typedef struct Argument {
    char data[100];
    char *string_pointer;
    wchar_t *wstring_pointer;
    int length;
    char is_empty;
    char is_negative;
} Argument;


static void pick_minus_plus_or_space(const char **format, Specifiers* specifiers) {
    while (**format == '+' || **format == '-' || **format == ' ') {
        if (**format == '+') {
            specifiers->plus = TRUE;
            ++(*format);
        }
        if (**format == '-') {
            specifiers->minus = TRUE;
            ++(*format);
        }
        if (**format == ' ') {
            specifiers->space = TRUE;
            ++(*format);
        }
    }
}

static void pick_width(const char **format, Specifiers* specifiers) {
    specifiers->width = s21_atoi(format);
}

static void pick_precision(const char **format, Specifiers* specifiers) {
    while (**format == '.') {
        ++(*format);
        specifiers->precision = s21_atoi(format);
        specifiers->is_precision_default = FALSE;
    }

    if (specifiers->precision < 0) {
        specifiers->precision = 0;
    }
}

static void pick_length_modifier(const char **format, Specifiers* specifiers) {
    if (**format == 'h') {
        specifiers->h = TRUE;
        ++(*format);
        return;
    }
    if (**format == 'l') {
        specifiers->l = TRUE;
        ++(*format);
        if (**format == 'l') {
            specifiers->ll = TRUE;
            specifiers->l = FALSE;
            ++(*format);
        }
        return;
    }
    if (**format == 'L') {
        specifiers->L = TRUE;
        ++(*format);
        return;
    }
}

static void __s21_wmemmove(char* destination, const wchar_t *source, int size) {
    for (int index = 0; index < size; ++index)
        destination[index] = source[index];
}

static void write_wide_char_to_buffer(char *buffer, int* index,
const Specifiers* specifiers, const Argument* argument) {
    if (specifiers->width > 1) {
        if (specifiers->minus) {
            // left-justify
            __s21_wmemmove(buffer, (wchar_t*)(argument->data), argument->length);
            s21_memset(buffer + argument->length, ' ', specifiers->width - argument->length);
            *index += specifiers->width;
        } else {
            // right-justify
            s21_memset(buffer, ' ', specifiers->width - argument->length);
            __s21_wmemmove(buffer+ specifiers->width - argument->length,
            (wchar_t*)(argument->data), argument->length);
            *index += specifiers->width;
        }
    } else {
        __s21_wmemmove(buffer, (wchar_t*)(argument->data), argument->length);
        *index += argument->length;
    }
}


static void write_char_to_buffer(char *buffer, int* index,
const Specifiers* specifiers, const Argument* argument) {
    if (specifiers->width > 1) {
        if (specifiers->minus) {
            // left-justify
            s21_memcpy(buffer, argument->data, argument->length);
            s21_memset(buffer + argument->length, ' ', specifiers->width - argument->length);
            *index += specifiers->width;  //  rearrange
        } else {
            // right-justify
            s21_memset(buffer, ' ', specifiers->width - argument->length);
            s21_memcpy(buffer + specifiers->width - argument->length, argument->data, argument->length);
            *index += specifiers->width;  //  rearrange
        }
    } else {
        s21_memcpy(buffer, argument->data, argument->length);
        *index += argument->length;
    }
}

static void __write_no_precision_no_width(char *buffer, int* index,
const Specifiers* specifiers, const Argument* argument) {
    // if ((specifiers->d || specifiers->i || specifiers->u) &&
    // (argument->data[0] == '0' || argument->data[1] == '0') && specifiers->precision < 1) {
    //    if (argument->data[0] == '0')
    //        ((char *)(argument->data))[0] = ' ';
    //    if (argument->data[1] == '0') {
    //        ((char *)(argument->data))[1] = ' ';
    //    }
    // }
    UNUSED_SHIT(specifiers);
    s21_memcpy(buffer, argument->data, argument->length);
    *index += argument->length;
}

static void __write_no_precision_with_width(char *buffer,
int* index, const Specifiers* specifiers, const Argument* argument) {
    if ((specifiers->d || specifiers->i || (specifiers->u && !specifiers->l)) &&
    (argument->data[0] == '0' ||
    ((argument->data[0] == '+' || argument->data[0] == '-') && argument->data[1] == '0'))
    && specifiers->precision < 1) {
        ((Argument*)(argument))->length -= 1;
    }

    const int length_for_spaces = specifiers->width - argument->length;
    assert(length_for_spaces >= 0);

    if (specifiers->minus) {
       // assert(0 && "here");
        s21_memcpy(buffer, argument->data, argument->length);
        *index += argument->length;
        s21_memset(buffer + argument->length, ' ', length_for_spaces);
        *index += length_for_spaces;
    } else {
        s21_memset(buffer, ' ', length_for_spaces);
        *index += length_for_spaces;

        s21_memcpy(buffer + length_for_spaces, argument->data, argument->length);
        *index += argument->length;
    }
}

static int __write_with_precision_no_width(char *buffer, int* index,
const Specifiers* specifiers, const Argument* argument) {
    int symbols_assigned = 0;
    if ((argument->is_negative || specifiers->plus) && !(specifiers->u)) {
        static const int length_for_sign = 1;
        const char plus_or_minus = argument->is_negative ? '-' : '+';
        s21_memset(buffer, plus_or_minus, length_for_sign);

        const int length_for_zeros = specifiers->precision - argument->length + length_for_sign;
        assert(length_for_zeros >= 0);
        s21_memset(buffer + length_for_sign, '0', length_for_zeros);
        *index += length_for_zeros;
        symbols_assigned += length_for_zeros;

        s21_memcpy(buffer + length_for_zeros + length_for_sign,
        argument->data + length_for_sign, argument->length - length_for_sign);
        *index += argument->length;
        symbols_assigned += argument->length;
    } else {  // no additional minus sign
        const int length_for_zeros = specifiers->precision - argument->length;

        assert(length_for_zeros >= 0);
        s21_memset(buffer, '0', length_for_zeros);
        *index += length_for_zeros;
        symbols_assigned += length_for_zeros;

        s21_memcpy(buffer + length_for_zeros, argument->data, argument->length);
        *index += argument->length;
        symbols_assigned += argument->length;
    }
    return symbols_assigned;
}

static void __write_with_precision_with_width(char *buffer,
int* index, const Specifiers* specifiers, const Argument* argument) {
    assert(specifiers->width >= argument->length);
    assert(specifiers->precision >= argument->length);
    assert(specifiers->width >= specifiers->precision);


    const int length_for_spaces = specifiers->width - specifiers->precision -
    (((argument->is_negative || specifiers->plus) && !(specifiers->u)) ? 1 : 0);

    if (specifiers->minus) {
        const int shift = __write_with_precision_no_width(buffer, index, specifiers, argument);
        assert(length_for_spaces >= 0);
        s21_memset(buffer + shift, ' ', length_for_spaces);
        *index += length_for_spaces;

    } else {
        s21_memset(buffer, ' ', length_for_spaces);
        *index += length_for_spaces;

        __write_with_precision_no_width(buffer + length_for_spaces, index, specifiers, argument);
    }
}


static void write_number_to_buffer(char *buffer, int* index,
const Specifiers* specifiers, const Argument* argument) {
    assert(argument->length >= 0);

    if (specifiers->precision < argument->length) {   //  ignoring precision
        if (specifiers->width < argument->length) {  //  ignoring width and ignoring precision
            __write_no_precision_no_width(buffer, index, specifiers, argument);
        } else {  //  considering width
            __write_no_precision_with_width(buffer, index, specifiers, argument);
        }
    } else {  //  considering precision
        if (specifiers->width <= argument->length) {
            __write_with_precision_no_width(buffer, index, specifiers, argument);
        } else {  //  considering both width and precision
            assert(specifiers->width > argument->length);
            assert(specifiers->precision >= argument->length);

            if (specifiers->precision > specifiers->width) {
                __write_with_precision_no_width(buffer, index, specifiers, argument);
            } else {
                __write_with_precision_with_width(buffer, index, specifiers, argument);
            }
        }
    }
}

static void set_default_precision_if_needed(Specifiers* specifiers) {
    if (specifiers->is_precision_default && specifiers->f)
        specifiers->precision = 6;
}

static void write_string_to_buffer(char *buffer, int* index,
const Specifiers* specifiers, const Argument* argument) {
    int length_to_copy = argument->length;
    if (!(specifiers->is_precision_default) && specifiers->precision < argument->length)
        length_to_copy = specifiers->precision;

    if (specifiers->width > length_to_copy) {
        const int length_for_spaces = specifiers->width - length_to_copy;
        assert(length_to_copy >= 0);

        if (specifiers->minus) {
            s21_memmove(buffer, argument->string_pointer, length_to_copy);
            s21_memset(buffer + length_to_copy, ' ', length_for_spaces);
        } else {
            s21_memset(buffer, ' ', length_for_spaces);
            s21_memmove(buffer + length_for_spaces, argument->string_pointer, length_to_copy);
        }

        *index += length_for_spaces;
    } else {  //  ignoring width
        s21_memmove(buffer, argument->string_pointer, length_to_copy);
    }

    *index += length_to_copy;
}

static void write_wide_string_to_buffer(char *buffer, int* index,
const Specifiers* specifiers, const Argument* argument) {
    int length_to_copy = argument->length;
    if (!(specifiers->is_precision_default) && specifiers->precision < argument->length)
        length_to_copy = specifiers->precision;

    if (specifiers->width > length_to_copy) {
        const int length_for_spaces = specifiers->width - length_to_copy;
        assert(length_to_copy >= 0);

        if (specifiers->minus) {
            __s21_wmemmove(buffer, argument->wstring_pointer, length_to_copy);
            s21_memset(buffer + length_to_copy, ' ', length_for_spaces);
        } else {
            s21_memset(buffer, ' ', length_for_spaces);
            __s21_wmemmove(buffer + length_for_spaces, (argument->wstring_pointer), length_to_copy);
        }

        *index += length_for_spaces;
    } else {  //  ignoring width
        __s21_wmemmove(buffer, argument->wstring_pointer, length_to_copy);
    }

    *index += (length_to_copy);
}

static void write_argument_to_buffer(char* buffer, int* index,
const Specifiers* specifiers, const Argument* argument) {
    assert(argument->length >= 0 && "Length should not be negative!");
    if (specifiers->c) {
        if (specifiers->l)
            write_wide_char_to_buffer(buffer, index, specifiers, argument);
        else
            write_char_to_buffer(buffer, index, specifiers, argument);
    }
    if (specifiers->d || specifiers->i)
        write_number_to_buffer(buffer, index, specifiers, argument);
    if (specifiers->f)
        write_number_to_buffer(buffer, index, specifiers, argument);
    if (specifiers->s) {
        if (specifiers->l)
            write_wide_string_to_buffer(buffer, index, specifiers, argument);
        else
            write_string_to_buffer(buffer, index, specifiers, argument);
    }
    if (specifiers->u)
        write_number_to_buffer(buffer, index, specifiers, argument);
}

static int __get_distance_to_next_percent(const char* format) {
    int length = 0;
    while (format[length] && format[length] != '%')
        ++length;
    return length;
}

static int __is_not_end(const char *format) {
    return *(format) != '\0';
}

static int __get_length_for_spaces_precent(const char** format,
const Specifiers* specifiers, int length_for_content) {
    int length_for_spaces = ((specifiers->width - length_for_content) >
    0 && __is_not_end(*format)) ? (specifiers->width - length_for_content) : 0;
    return length_for_spaces;
}

static void write_percent_to_buffer(char* buffer, const char** format,
int* index, const Specifiers* specifiers) {
    if (!specifiers->percent)
        return;

    const int length_for_content = __get_distance_to_next_percent(*format);
    const int length_for_spaces = __get_length_for_spaces_precent(format, specifiers, length_for_content);

    assert(length_for_content >= 0);
    assert(length_for_spaces >= 0);

    if (length_for_content == 0 && __is_not_end(*format)) {  //  printing '%', also considering width
        const int length_for_percent = 1;
        const int length_for_spaces_percent =
        length_for_spaces - length_for_percent > 0 ?
        length_for_spaces - length_for_percent : 0;

        assert(length_for_spaces_percent >= 0);
        if (specifiers->minus) {
            s21_memset(buffer, '%', length_for_percent);
            s21_memset(buffer + length_for_percent, ' ', length_for_spaces_percent);
        } else {
            s21_memset(buffer, ' ', length_for_spaces_percent);
            s21_memset(buffer + length_for_spaces_percent, '%', length_for_percent);
        }
        *index += length_for_percent;
        *index += length_for_spaces_percent;
        *format += length_for_percent;

    } else {  //  printing content up to the next '%', not including '%', considering width
        if (specifiers->minus) {
            s21_memmove(buffer, *format, length_for_content);
            s21_memset(buffer + length_for_content, ' ', length_for_spaces);
        } else {
            s21_memset(buffer, ' ', length_for_spaces);
            s21_memmove(buffer + length_for_spaces, *format, length_for_content);
        }
        *index += length_for_content;
        *index += length_for_spaces;

        *format += length_for_content;
    }
}


static void initialize_specifiers(Specifiers *specifiers) {
    specifiers->c = FALSE;
    specifiers->d = FALSE;
    specifiers->i = FALSE;
    specifiers->e = FALSE;
    specifiers->E = FALSE;
    specifiers->f = FALSE;
    specifiers->g = FALSE;
    specifiers->G = FALSE;
    specifiers->o = FALSE;
    specifiers->s = FALSE;
    specifiers->u = FALSE;
    specifiers->x = FALSE;
    specifiers->X = FALSE;
    specifiers->p = FALSE;
    specifiers->n = FALSE;
    specifiers->percent = FALSE;

    specifiers->plus = FALSE;
    specifiers->minus = FALSE;
    specifiers->space = FALSE;

    specifiers->hashtag = FALSE;
    specifiers->zero = FALSE;

    specifiers->width = 0;
    specifiers->precision = 0;
    specifiers->is_precision_default = TRUE;

    specifiers->star = FALSE;

    specifiers->h = FALSE;
    specifiers->l = FALSE;
    specifiers->ll = FALSE;
    specifiers->L = FALSE;
}

static void initialize_argument(Argument* argument) {
    s21_memset(argument->data, '\0', 100ul);

    argument->string_pointer = s21_NULL;
    argument->wstring_pointer = s21_NULL;
    argument->length = 0;
    argument->is_empty = TRUE;
    argument->is_negative = FALSE;
}


static void write_space_to_buffer_and_decrease_width(char *buffer,
int *index, Specifiers* specifiers, const Argument* argument) {
    if (specifiers->space && (!specifiers->plus) &&
    !(argument->is_negative) &&
    (specifiers->d || specifiers->i || specifiers->f)) {
        s21_memset(buffer, ' ', 1);
        ++(*index);

        if (specifiers->width > 0)
            specifiers->width -= 1;
    }
}

static void char_from_varg_to_argument(va_list argp, Argument* argument) {
    argument->data[0] = va_arg(argp, int);
    argument->is_empty = FALSE;
    argument->length = 1;
}

static long long int __get_signed_from_va_arg(va_list argp) {
    return va_arg(argp, long long int);
}
static long long int __get_unsigned_from_va_arg(va_list argp) {
    return va_arg(argp, unsigned long long int);
}

static void __write_signed_to_argument(long long int number, char plus, Argument* argument) {
    if (number < 0)
        argument->is_negative = TRUE;

    int length_for_plus = 0;
    if (plus && !(argument->is_negative)) {
        length_for_plus = 1;
        s21_memset(argument->data, '+', length_for_plus);
    }

    static const int base = 10;
    s21_itoa(number, argument->data + length_for_plus, base, &(argument->length));
    argument->is_empty = FALSE;
    argument->length += length_for_plus;
}

static void int_from_varg_to_argument(va_list argp, char plus, Argument* argument) {
    const int number = __get_signed_from_va_arg(argp);
    __write_signed_to_argument(number, plus, argument);
}
static void short_int_from_varg_to_argument(va_list argp, char plus, Argument* argument) {
    const short int number = __get_signed_from_va_arg(argp);
    __write_signed_to_argument(number, plus, argument);
}
static void long_int_from_varg_to_argument(va_list argp, char plus, Argument* argument) {
    const long int number = __get_signed_from_va_arg(argp);
    __write_signed_to_argument(number, plus, argument);
}
static void long_long_int_from_varg_to_argument(va_list argp, char plus, Argument* argument) {
    const long long int number = __get_signed_from_va_arg(argp);
    __write_signed_to_argument(number, plus, argument);
}



static void __write_unsigned_to_argument(unsigned long long int number, Argument* argument) {
    static const int base = 10;
    s21_itoa(number, argument->data, base, &(argument->length));
    argument->is_empty = FALSE;
}

static void unsigned_from_varg_to_argument(va_list argp, Argument* argument) {
    const unsigned int number = __get_unsigned_from_va_arg(argp);
    __write_unsigned_to_argument(number, argument);
}

static void short_unsigned_from_varg_to_argument(va_list argp, Argument* argument) {
    const unsigned short int number = __get_unsigned_from_va_arg(argp);
    __write_unsigned_to_argument(number, argument);
}

static void long_unsigned_from_varg_to_argument(va_list argp, Argument* argument) {
    const unsigned long int number = __get_unsigned_from_va_arg(argp);
    __write_unsigned_to_argument(number, argument);
}

static void long_long_unsigned_from_varg_to_argument(va_list argp, Argument* argument) {
    const unsigned long long int number = __get_unsigned_from_va_arg(argp);
    __write_unsigned_to_argument(number, argument);
}

static void string_from_varg_to_argument(va_list argp, Argument* argument) {
    argument->is_empty = FALSE;
    argument->string_pointer = va_arg(argp, char*);
    argument->length = s21_strlen(argument->string_pointer);
}

static int __s21_wstrlen(const wchar_t* string) {
    int length = 0;
    while (string[length])
        ++length;
    return length;
}

static void wide_string_from_varg_to_argument(va_list argp, Argument* argument) {
    argument->is_empty = FALSE;
    argument->wstring_pointer = va_arg(argp, wchar_t*);
    argument->length = __s21_wstrlen(argument->wstring_pointer);
}

static int __count_zeros(double* number, int* precision) {
    static const int base = 10;
    unsigned long long int digit = (unsigned long long int)(*number);

    int zeros = 0;
    while (digit == 0 && *precision >= 0) {
        digit = (unsigned long long int)((*number) * base);
        (*number) *= base;
        --*precision;
        ++zeros;
    }

    return zeros;
}

static void ___round(unsigned long long int* number) {
    static const int base = 10;
    const int remainder = *number % base;

    static const int threshold = 5;
    if (remainder >= threshold)
        *number += base;
}


static void __double_to_array_of_chars(char *pointer_array_for_double,
double temp_arpg_variable, const Specifiers* specifiers) {
    static const int base = 10;

    int precision = specifiers->precision + 1;

    const int zeros = __count_zeros(&temp_arpg_variable, &precision);


    // const double multiplier = pow(base, precision);
    const unsigned long long multiplier = pow(base, precision);

    char is_negative = FALSE;
    if (temp_arpg_variable < 0) {
        temp_arpg_variable *= -1;
        is_negative = TRUE;
    }

    unsigned long long int double_without_floating_point
    = temp_arpg_variable * multiplier;  // TODO(elviaatt): get rid of overflow!

    ___round(&double_without_floating_point);

    int index = 0, flip_index = 0;
    char temp_array_for_double[49] = {'\0'};

    while (double_without_floating_point > 0) {
        temp_array_for_double[index] = (char)((double_without_floating_point % base) + '0');
        double_without_floating_point /= base;
        ++index;
    }

    if (specifiers->plus && !is_negative) {
        pointer_array_for_double[flip_index] = '+';
        ++flip_index;
    }
    if (is_negative) {
        pointer_array_for_double[flip_index] = '-';
        ++flip_index;
    }

    for (int i = 0; i < zeros; ++i)
        pointer_array_for_double[i + flip_index] = '0';

    // For loop to flip the temp array
    for (int i = index - 1; i >= 0; --i) {
        pointer_array_for_double[flip_index + zeros] = temp_array_for_double[i];
        ++flip_index;
    }
}






static int __find_dot_index(double number, const Specifiers* specifiers) {
    int index = 0;
    char is_negative = FALSE;
    if (number < 0) {
        number *= -1;
        is_negative = TRUE;
        ++index;
    }

    if (number < 1) {
        if (is_negative || specifiers->plus)  //  012345
            index = 2;                        //  -0.987
        else                                  //  012345
            index = 1;                        //  0.987
    } else {
        double remainder = number;
        while (remainder >= 1) {
            remainder /= 10;
            ++index;
        }

        if (specifiers->plus && !is_negative) {
            ++index;
        }
    }
    return index;
}


static void float_from_varg_to_argument(va_list argp, const Specifiers* specifiers, Argument* argument) {
    char array_for_double[49] = {'\0'};

    char *pointer_array_for_double = array_for_double;
    const double temp_arpg_variable = va_arg(argp, double);

    int dot_index = __find_dot_index(temp_arpg_variable, specifiers);
    int array_for_double_index = 0;


    const int max_amount_of_precision = specifiers->precision;

    __double_to_array_of_chars(pointer_array_for_double, temp_arpg_variable, specifiers);

    while (array_for_double_index != dot_index) {
        argument->data[array_for_double_index] = array_for_double[array_for_double_index];
        ++array_for_double_index;
    }

    static const char dot = '.';
    if (specifiers->precision != 0) {
        argument->data[array_for_double_index] = dot;
        ++array_for_double_index;
    }

    for (int i = 0; i < max_amount_of_precision; ++i) {
        argument->data[array_for_double_index] = array_for_double[array_for_double_index - 1];
        ++array_for_double_index;
    }
    argument->length = array_for_double_index;
}

// static void percent_to_buffer(char *buffer, int *index, const char format) {
//     buffer[*index] = format;
//     ++*index;
// }

static void pick_type(const char **format, Specifiers* specifiers) {
    if ('c' == **format) {
        specifiers->c = TRUE;
    } else if ('d' == **format || 'i' == **format) {
        specifiers->d = TRUE;
        specifiers->i = TRUE;
    } else if ('f' == **format) {
        specifiers->f = TRUE;
    } else if ('s' == **format) {
        specifiers->s = TRUE;
    } else if ('u' == **format) {
        specifiers->u = TRUE;
    } else {
        specifiers->percent = TRUE;
    }

    if (!specifiers->percent)
        ++*format;
}

static void any_type_from_varg_to_argument(va_list argp,
const Specifiers* specifiers, Argument* argument) {  //  pick type in separated function
    if (specifiers->c) {
        char_from_varg_to_argument(argp, argument);
    } else if (specifiers->d || specifiers->i) {
        if (specifiers->h)       //  %hd  %hi
            short_int_from_varg_to_argument(argp, specifiers->plus, argument);
        else if (specifiers->l)  //  %ld  %li
            long_int_from_varg_to_argument(argp, specifiers->plus, argument);
        else if (specifiers->ll)  //  %lld %lli
            long_long_int_from_varg_to_argument(argp, specifiers->plus, argument);
        else                     //  %d   %i
            int_from_varg_to_argument(argp, specifiers->plus,  argument);
    } else if (specifiers->f) {  //  %f
        float_from_varg_to_argument(argp, specifiers, argument);
    } else if (specifiers->s) {
        if (specifiers->l)       //  %ls
            wide_string_from_varg_to_argument(argp, argument);
        else                     //  %s
            string_from_varg_to_argument(argp, argument);
    } else if (specifiers->u) {
        if (specifiers->h)       //  %hu
            short_unsigned_from_varg_to_argument(argp, argument);
        else if (specifiers->l)  //  %lu
            long_unsigned_from_varg_to_argument(argp, argument);
        else if (specifiers->ll)  //  %llu
            long_long_unsigned_from_varg_to_argument(argp, argument);
        else                     //  %u
            unsigned_from_varg_to_argument(argp, argument);
    }
}





int s21_sprintf(char *buffer, const char *format, ...) {
    // va_list is effictively a pointer to an arguments in the varargs array
    va_list argp;
    // After calling va_start argp points at the first vararg argument
    va_start(argp, format);
    int index = 0;
    while (*format != '\0') {
        if (*format == '%') {
            Specifiers specifiers;
            initialize_specifiers(&specifiers);

            Argument argument;
            initialize_argument(&argument);
            ++format;  // to move from percent

            pick_minus_plus_or_space(&format, &specifiers);
            pick_width(&format, &specifiers);
            pick_minus_plus_or_space(&format, &specifiers);
            pick_precision(&format, &specifiers);
            pick_minus_plus_or_space(&format, &specifiers);
            pick_length_modifier(&format, &specifiers);
            pick_type(&format, &specifiers);


            set_default_precision_if_needed(&specifiers);

            any_type_from_varg_to_argument(argp, &specifiers, &argument);

            write_space_to_buffer_and_decrease_width(buffer + index, &index, &specifiers, &argument);
            write_percent_to_buffer(buffer + index, &format, &index, &specifiers);
            write_argument_to_buffer(buffer + index, &index, &specifiers, &argument);

            // ++format;
        } else {
            buffer[index] = *format;
            ++index;
            ++format;
        }
    }
    // We call va_end to stop consuming the vararg arguments
    va_end(argp);
    buffer[index] = '\0';
    // Upon successful return, the function returns the number of
    // characters printed (excluding the null byte used to end output to strings).
    return index;
}
