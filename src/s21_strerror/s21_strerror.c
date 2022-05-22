#include "s21_strerror.h"
#include "../s21_strncpy/s21_strncpy.h"
#include "../s21_strlen/s21_strlen.h"

static int __get_number_of_digits(int number) {
    int number_of_digits = 0;
    while (number) {
        number /= 10;
        ++number_of_digits;
    }
    return number_of_digits;
}

static void __int_to_string_with_terminator(char *destination, int number) {
    int number_of_digits = __get_number_of_digits(number);
    if (number < 0) {
        ++number_of_digits;
        destination[0] = '-';
        number *= -1;
    }

    static const int base = 10;
    destination[number_of_digits] = '\0';
    while (number) {
        const int digit = number % base;
        destination[number_of_digits - 1] = digit + '0';
        number /= base;
        --number_of_digits;
    }
}

char *s21_strerror(int error_number) {
    if (error_number < 0 || error_number > NUMBER_OF_ERRORS) {
        const s21_size_t length = s21_strlen(UNKNOWN_ERROR);
        static char unknown_error_with_code[100];
        s21_strncpy(unknown_error_with_code, UNKNOWN_ERROR, length);
        __int_to_string_with_terminator(unknown_error_with_code + length, error_number);

        return unknown_error_with_code;
    }

    static const char *errors[] = {ERROR};
    return (char*)errors[error_number];
}