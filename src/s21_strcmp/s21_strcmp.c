#include "s21_strcmp.h"
#include "../s21_strlen/s21_strlen.h"

int s21_strcmp(const char* string1, const char* string2) {
    const s21_size_t length_string1 = s21_strlen(string1);
    const s21_size_t length_string2 = s21_strlen(string2);
    
    
    s21_size_t index1 = 0ul;
    s21_size_t index2 = 0ul;
    
    while (index1 < length_string1 && index2 < length_string2) {
        if (string1[index1] != string2[index2])
            return string1[index1] - string2[index2];
        ++index1;
        ++index2;
    }

    return string1[index1] - string2[index2];
}
