#include "s21_strcat.h"
#include "../s21_strncat/s21_strncat.h"
#include "../s21_strlen/s21_strlen.h"

char *s21_strcat(char *destination, const char *source) {
    return s21_strncat(destination, source, s21_strlen(source));
}
