#include "s21_atoi.h"

// Main used for testing
// int main() {
//     char test_number_array[] = {'0', '0', '3', '0', '3', '0', '3', '\0'};
//     char *pointer = test_number_array;
//     int resulting_number = s21_itoa(pointer);
//     printf("Resulting number = %d", resulting_number);
//     return 0;
// }

int s21_atoi(char *format) {
    // Note for later - Do I need to use index from sprintf here or not? The index of buffer doesn't move if while I parse the number from string
    // So probably I don't need it. Need to look into it after a while. Now too sleepy.
    int result = 0, index = 0;
    char temp_array_of_numbers[12] = {'\0'};
    // We write to the temp array each number in the sequence
    while (*format <= '9' && *format >= '0') {
        temp_array_of_numbers[index] = *format;
        ++index;
        ++format;
    }
    // Here we sum all the numbers in the array and return the sum
    int temp_index = index, char_int_step = 48;
    for (int i = 0; i < index; ++i) {
        result += (temp_array_of_numbers[i] - char_int_step) * pow(10, temp_index - 1);
        --temp_index;
    }
    return result;
}
