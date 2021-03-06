// Copyright 2022 elviaatt & finchren

#ifndef SRC_S21_ITOA_H_
#define SRC_S21_ITOA_H_

#include <stdio.h>
#include <math.h>

char* s21_itoa(long long int number, char *buffer, int base, int *number_of_digits_Out);
char* s21_itoa_unsigned(unsigned long long int number, char *buffer, int base, int *number_of_digits_Out);

#endif  // SRC_S21_ITOA_H_
