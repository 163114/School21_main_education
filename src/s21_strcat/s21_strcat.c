#include "s21_strcat.h"

char	*s21_strcat(char *__s1, const char *__s2)
{
    return s21_strncat(__s1, __s2, s21_strlen(__s2));
}
