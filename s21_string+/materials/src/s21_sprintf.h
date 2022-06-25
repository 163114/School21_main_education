// Copyright 2022 elviaatt & finchren

#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#include "s21_itoa.h"
#include "s21_atoi.h"


#define UNUSED_SHIT(fucking_unused_shit) do { (void)(fucking_unused_shit); } while (0)

int s21_sprintf(char *buffer, const char *format, ...);


#endif  // SRC_S21_SPRINTF_H_
