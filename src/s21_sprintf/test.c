// Testing file for small functions
#include <stdio.h>
// #include <limits.h>
// #include <math.h>

// %i takes integer value as integer value with decimal, hexadecimal or octal type.
// To enter a value in hexadecimal format – value should be provided by preceding “0x” and value in octal format – value should be provided by preceding “0”.

int flip_to_array(int number_to_flip, char *pointer_to_array);
void print_out(char *pointer_to_array, int size_of_array);

// IT WORKS?
// int main() {
//     // int hexadecimal_num = 0x7FFFFFFF;
//     int octal_num = 017777777777;
//     // int zerox_num = 0x1;
//     // int regular_num = 7575757;
//     int size_of_array = 0;
//     char flipped_array[12];
//     char *pointer_to_flipped_array = flipped_array;
//     size_of_array = flip_to_array(octal_num, pointer_to_flipped_array);
//     print_out(pointer_to_flipped_array, size_of_array);
//     return 0;
// }

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

// void print_out(char *pointer_to_array, int size_of_array) {
//     for (int i = 0; i < size_of_array; ++i) {
//         printf("%d", pointer_to_array[i]);
//     }
// }