#include "s21_strtok.h"
#include "../s21_common/s21_is_found/s21_is_found.h"
#include "../s21_strlen/s21_strlen.h"
/*
char *s21_strtok(char *string, const char *delimiters) {
    static char *string_to_remember = s21_NULL;
    static s21_size_t size_string_to_remember = 0ul;
    static s21_size_t index = 0ul;

    if (string) {
        string_to_remember = string;
        size_string_to_remember = s21_strlen(string_to_remember);
        index = 0ul;
    }   
    //  0 1 2 3 4 5 6 7 8 9 1011
    // "H e y   y o   b i t c h"

    const s21_size_t size_delimiters = s21_strlen(delimiters); 
    const s21_size_t start_index = index;

    printf("start: %zu\n", start_index); //
    while (is_not_found(delimiters, string_to_remember[index], size_delimiters) && index < size_string_to_remember) {
        ++index;
    }

    string_to_remember[index] = '\0';
    ++index;

    printf("%s\n", string_to_remember + start_index); //
    printf("index: %zu\n", index); //
    return string_to_remember + start_index;
}
*/

char *s21_strtok(char *string, const char *delimiters) {
    static char *string_to_remember = s21_NULL;
    static s21_size_t size_string_to_remember = 0ul;
    static s21_size_t index = 0ul;
    static s21_size_t start_index = 0ul;

    if (string) {
        string_to_remember = string;
        size_string_to_remember = s21_strlen(string_to_remember);
        index = 0ul;
        start_index = 0ul;
        printf("length: %zu\n", size_string_to_remember); //
    }   
    if (index == size_string_to_remember)
        return s21_NULL;
    //  0 1 2 3 4 5 6 7 8 9 1011
    // "H e y   y o   b i t c h"

    const s21_size_t size_delimiters = s21_strlen(delimiters); 

    if (is_not_found(delimiters, string_to_remember[index], size_delimiters))
        start_index = index;

    printf("start: %zu\n", start_index); //
    while (is_not_found(delimiters, string_to_remember[index], size_delimiters) && index < size_string_to_remember) {
        ++index;
    }
    
    if (index < size_string_to_remember) {
        string_to_remember[index] = '\0';
        ++index;
    }


    printf("%s\n", string_to_remember + start_index); //
    printf("index: %zu\n", index); //


    return string_to_remember + start_index;
}
