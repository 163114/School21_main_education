#include "s21_itoa.h"

// int main() {
//     int positive_number = 123456;  
//     char buffer[256];  
//     if (s21_itoa(positive_number, buffer, 10) != NULL) {  
//         printf("Input = %d, base = %d, buffer = %s\n", positive_number, 10, buffer);  
//     }  
//     int negative_number = -2310;  
//     if (s21_itoa(negative_number, buffer, 10) != NULL) {  
//         printf("Input = %d, base = %d, buffer = %s\n", negative_number, 10, buffer);  
//     }  
//     // Binary test
//     int number_for_binary = 10;  
//     if (s21_itoa(number_for_binary, buffer, 2) != NULL) {  
//         printf("Input = %d, base = %d, buffer = %s\n", number_for_binary, 2, buffer);  
//     }  
//     return 0;
// }

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
        } 
        // Used for the case when to the function is passed a non-valid radix argument
        else {
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
