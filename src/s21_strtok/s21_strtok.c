#include "s21_strtok.h"
#include "../s21_common/s21_is_found/s21_is_found.h"
#include "../s21_strlen/s21_strlen.h"

static int is_delimiter(const unsigned char* delimiters, unsigned char symbol, s21_size_t length) {
    return is_found(delimiters, symbol, length);
}

char *s21_strtok(char *string, const char *delimiters) {
    static char *string_to_remember = s21_NULL;
    static s21_size_t length_string = 0ul;
    static s21_size_t index = 0ul;

    if (string) {
        // printf("new string\n");
        string_to_remember = string;
        length_string = s21_strlen(string);
        index = 0ul;
    }

    const s21_size_t length_delimiters = s21_strlen(delimiters);
    s21_size_t length_token = 0ul;
    s21_size_t start_index = index;

//     012345678901234
//    "URGH DA FUCK!"
    int is_previous_delimiter = 1;
    char *result_token = s21_NULL;
    int go_on = 1;
    while (index < length_string && go_on) {
        if (is_delimiter(delimiters, string_to_remember[index], length_delimiters)) {
            
            if (!is_previous_delimiter)
                string_to_remember[index] = '\0';
            is_previous_delimiter = 1;
            ++index; //

            
            if (length_token > 0ul) {
                const s21_size_t old_start_index = start_index;
                start_index = index - 1;
                
                //printf("index-1 = %zu\told_start_index = %zu\tlength_token = %zu\n", index-1, old_start_index, length_token);
                length_token = 0ul;
                result_token = string_to_remember + old_start_index;
                go_on = 0;
            }
        } else {
            ++index; // 
            ++length_token;
            if (is_previous_delimiter)
                start_index = index - 1;
            is_previous_delimiter = 0;
        }
    }

    if (length_token > 0ul) {
        //printf("index-1 = %zu\tstart_index\t= %zu\tlength_token = %zu\n", index-1, start_index, length_token);
        result_token = string_to_remember + start_index;
    }

    return result_token;
}
