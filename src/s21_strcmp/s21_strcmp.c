#include "s21_strcmp.h"

int	 s21_strcmp(const char *__s1, const char *__s2)
{
    s21_size_t len1 = s21_strlen(__s1), len2 = s21_strlen(__s2);
    return s21_strncmp(__s1, __s2, len1 < len2? len2: len1);
}
