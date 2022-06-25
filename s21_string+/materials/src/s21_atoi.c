// Copyright 2022 elviaatt & finchren

#include "s21_atoi.h"

// Main used for testing
// int main() {
//     char test_number_array[] = {'0', '0', '3', '0', '3', '0', '3', '\0'};
//     char *pointer = test_number_array;
//     int resulting_number = s21_itoa(pointer);
//     printf("Resulting number = %d", resulting_number);
//     return 0;
// }

static int __get_sign(const char **format) {
    int sign = 1;
    if ('-' == **format) {
        sign = -1;
        ++(*format);
    }
    return sign;
}

int s21_atoi(const char **format) {
    int result = 0, index = 0;
    char temp_array_of_numbers[13] = {'\0'};
    // We write to the temp array each number in the sequence

    const int sign = __get_sign(format);
    while (**format <= '9' && **format >= '0') {
        temp_array_of_numbers[index] = **format;
        ++index;
        ++*format;
    }
    // Here we sum all the numbers in the array and return the sum
    int temp_index = index, char_int_step = 48;
    for (int i = 0; i < index; ++i) {
        result += (temp_array_of_numbers[i] - char_int_step) * pow(10, temp_index - 1);
        --temp_index;
    }
    return result * sign;
}
