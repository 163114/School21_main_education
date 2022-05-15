#include "s21_strpbrk.h"
#include "../s21_memchr/s21_memchr.h"
#include "../s21_strlen/s21_strlen.h"

//  this function may not be optimal in terms of time complexity
char *s21_strpbrk(const char *string, const char *symbols) {
    const s21_size_t string_length = s21_strlen(string);
    const s21_size_t symbols_length = s21_strlen(symbols);

    //  the last part possible of the string
    const char* first_result = string + string_length;  
    for (s21_size_t symbol_index = 0ul; symbol_index < symbols_length; ++symbol_index) {
        const char* const result = s21_memchr(string, symbols[symbol_index], string_length);
        
        //  the first occurrence is required, so we compare result with first_result,
        //  which is closer to the beginning of the string
        if (result && result < first_result)
            first_result = result;
    }

    //  if there was nothing found (first_result remained the same)
    if (first_result == string + string_length) 
        return s21_NULL;

    return (char*)first_result;
}
