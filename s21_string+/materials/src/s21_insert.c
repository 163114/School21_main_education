// Copyright 2022 elviaatt

#include "s21_insert.h"
#include "s21_strlen.h"
/*
void *s21_insert(const char *src, const char *str, s21_size_t start_index)
{
    int len1 = s21_strlen(src), len2 = s21_strlen(str), len = len1 + len2, i = 0, j = 0, k = 0;
    char *str_ = malloc(len1 + len2 * sizeof(char));
    if (str_){
        for (; i < len; i++)
        {
            if (i >= (signed)start_index && k < len2)
            {
                str_[i] = str[k];
                k++;
            } else {
                str_[i] = src[j];
                j++;
            }
        }
    }
    return str_;
}
*/
// TODO(elviaatt):
// decide behaviour when source is NULL or string_to_insert is NULL
void *s21_insert(const char *source,
const char *string_to_insert, s21_size_t start_index) {
    if (source == s21_NULL || string_to_insert == s21_NULL)
        return s21_NULL;

    const s21_size_t source_length = s21_strlen(source);
    const s21_size_t string_to_insert_length = s21_strlen(string_to_insert);

    if (start_index > source_length)
        return s21_NULL;

    char *extended_string = malloc(sizeof(char) *
    (source_length + string_to_insert_length + 1ul));

    for (s21_size_t index = 0ul; index < start_index; ++index)
        extended_string[index] = source[index];

    for (s21_size_t index = 0ul; index < string_to_insert_length; ++index)
        extended_string[index + start_index] = string_to_insert[index];

    for (s21_size_t index = 0ul; index < source_length - start_index; ++index)
        extended_string[index + start_index +
        string_to_insert_length] = source[index + start_index];

    extended_string[source_length + string_to_insert_length] = '\0';

    return extended_string;
}
