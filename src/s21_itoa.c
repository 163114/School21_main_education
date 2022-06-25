// Copyright 2022 elviaatt & finchren

#include "s21_itoa.h"

char* s21_itoa(long long int number, char *buffer, int base, int *number_of_digits_Out) {
    int current = 0;
    if (number == 0) {
        buffer[current++] = '0';
        buffer[current] = '\0';
        *number_of_digits_Out = 1;
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
        // Used for the case when to the function is passed a non-valid radix argument

            return NULL;
        }
    }
    num_digits += (int)floor(log(number) / log(base)) + 1;
    while (current < num_digits) {
        long long int base_val = (long long int) pow(base, num_digits -1 - current);
        long long int num_val = number / base_val;
        char value = num_val + '0';
        buffer[current] = value;
        ++current;
        number -= base_val * num_val;
    }
    buffer[current] = '\0';

    *number_of_digits_Out = num_digits;

    return buffer;
}

// char* s21_itoa_unsigned(unsigned long long int number, char *buffer, int base, int *number_of_digits_Out) {
//     unsigned int current = 0;
//     if (number == 0) {
//         buffer[current++] = '0';
//         buffer[current] = '\0';
//         *number_of_digits_Out = 1;
//         return buffer;
//     }
//     unsigned int num_digits = 0;

//     num_digits += (int)floor(log(number) / log(base)) + 1;
//     while (current < num_digits) {
//         long long int base_val = (long long int) pow(base, num_digits -1 -current);
//         unsigned long long int num_val = number / base_val;
//         char value = num_val + '0';
//         buffer[current] = value;
//         ++current;
//         number -= base_val * num_val;
//     }
//     buffer[current] = '\0';

//     *number_of_digits_Out = num_digits;

//     return buffer;
// }
