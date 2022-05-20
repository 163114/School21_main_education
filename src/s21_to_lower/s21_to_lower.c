#include "s21_to_lower.h"

void *s21_to_lower(const char *str)
{
    int len = s21_strlen(str);
    char *str_ = (char*) malloc(len + 1);
    if (str_){
        for (int i = 0; i < len; i++)
        {
            int c = str[i];
            if (c > 64 && c < 91) str_[i] = (char) (c + 32);
            else str_[i] = (char) c;
        }
    }
    return str_;
}
