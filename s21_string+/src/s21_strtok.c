// Copyright 2022 elviaatt

#include "s21_strtok.h"
#include "s21_is_found.h"
#include "s21_strlen.h"

static int __is_delimiter(const char* delimiters, char symbol, s21_size_t length) {
    return __is_found((const char *)delimiters, symbol, length);
}

char *s21_strtok(char *string, const char *delimiters) {
    static char *string_to_remember = s21_NULL;
    static s21_size_t length_string = 0ul;
    static s21_size_t index = 0ul;

    if (string) {
        string_to_remember = string;
        length_string = s21_strlen(string);
        index = 0ul;
    }

    const s21_size_t length_delimiters = s21_strlen(delimiters);
    s21_size_t length_token = 0ul;
    s21_size_t start_index = index;

    int is_previous_delimiter = 1;
    char *result_token = s21_NULL;
    int go_on = 1;
    while (index < length_string && go_on) {
        if (__is_delimiter(delimiters, string_to_remember[index], length_delimiters)) {
            
            if (!is_previous_delimiter)
                string_to_remember[index] = '\0';
            is_previous_delimiter = 1;
            
            if (length_token > 0ul) {
                result_token = string_to_remember + start_index;
                
                start_index = index;
                go_on = 0;
                length_token = 0ul;
            }
        } else {
            ++length_token;

            if (is_previous_delimiter)
                start_index = index;

            is_previous_delimiter = 0;
        }

        ++index;
    }

    if (length_token > 0ul)
        result_token = string_to_remember + start_index;

    return result_token;
}
