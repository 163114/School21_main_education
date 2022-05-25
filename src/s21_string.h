#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include "s21_string_types.h"

#include <stdio.h>


#include "s21_memchr/s21_memchr.h"     //  1
#include "s21_memcmp/s21_memcmp.h"     //  2
#include "s21_memcpy/s21_memcpy.h"     //  3
#include "s21_memmove/s21_memmove.h"   //  4
#include "s21_memset/s21_memset.h"     //  5
#include "s21_strcat/s21_strcat.h"     //  6
#include "s21_strncat/s21_strncat.h"   //  7
#include "s21_strchr/s21_strchr.h"     //  8
#include "s21_strcmp/s21_strcmp.h"     //  9
#include "s21_strncmp/s21_strncmp.h"   // 10
#include "s21_strcpy/s21_strcpy.h"     // 11
#include "s21_strncpy/s21_strncpy.h"   // 12
#include "s21_strcspn/s21_strcspn.h"   // 13
#include "s21_strerror/s21_strerror.h" // 14
#include "s21_strlen/s21_strlen.h"     // 15
#include "s21_strpbrk/s21_strpbrk.h"   // 16
#include "s21_strrchr/s21_strrchr.h"   // 17
#include "s21_strspn/s21_strspn.h"     // 18
#include "s21_strstr/s21_strstr.h"     // 19
#include "s21_strtok/s21_strtok.h"     // 20


#endif  //  SRC_S21_STRING_H_
/*
#include "s21_sprintf/s21_sprintf.h"

#endif  //  SRC_S21_STRING_H_
typedef long unsigned s21_size_t;
#define s21_NULL ((void *)0)


void	*s21_memchr(const void *__s, int __c, s21_size_t __n);
int	 s21_memcmp(const void *__s1, const void *__s2, s21_size_t __n);
void	*s21_memcpy(void *__dst, const void *__src, s21_size_t __n);
void	*s21_memmove(void *__dst, const void *__src, s21_size_t __len);
void	*s21_memset(void *__b, int __c, s21_size_t __len);

char	*s21_strcat(char *__s1, const char *__s2);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char	*s21_strchr(const char *__s, int __c);
int	 s21_strcmp(const char *__s1, const char *__s2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

s21_size_t	 s21_strcspn(const char *__s, const char *__charset);
char	*s21_strerror(int __errnum);
s21_size_t	 s21_strlen(const char *__s);
char	*s21_strncat(char *__s1, const char *__s2, s21_size_t __n);
int	 s21_strncmp(const char *__s1, const char *__s2, s21_size_t __n);
char	*s21_strncpy(char *__dst, const char *__src, s21_size_t __n);
char	*s21_strpbrk(const char *__s, const char *__charset);
char	*s21_strrchr(const char *__s, int __c);
s21_size_t	 s21_strspn(const char *__s, const char *__charset);
char	*s21_strstr(const char *__big, const char *__little);
char	*s21_strtok(char *__str, const char *__sep);
s21_size_t	 s21_strxfrm(char *__s1, const char *__s2, s21_size_t __n);
*/