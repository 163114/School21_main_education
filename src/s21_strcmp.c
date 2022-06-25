// Copyright 2022 elviaatt

#include "s21_strcmp.h"
#include "s21_strncmp.h"
#include "s21_strlen.h"


int s21_strcmp(const char *__s1, const char *__s2) {
    s21_size_t len1 = s21_strlen(__s1), len2 = s21_strlen(__s2);
    return s21_strncmp(__s1, __s2, len1 < len2? len2: len1);
}




// This code also works
/*
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
*/
