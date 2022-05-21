#include "s21_strcpy.h"
#include "../s21_strncpy/s21_strncpy.h"
#include "../s21_strlen/s21_strlen.h"

char *s21_strcpy(char *destination, const char *source) {
    const s21_size_t size = s21_strlen(source);
    
    char *result = s21_strncpy(destination, source, size);
    result[size] = '\0';

    return result;
}