#include "s21_strrchr.h"

char *s21_strrchr(const char *string, int symbol) {
    const unsigned char symbol_uchar = (unsigned char)symbol;
    
    const char *result = s21_NULL;
    while (*string) {
        if (*string == symbol_uchar)
            result = string;
        ++string;
    }

    return (char*)result;
}