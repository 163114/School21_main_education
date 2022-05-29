/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "s21_sprintf_test.check" instead.
 */

#include <check.h>

#line 1 "s21_sprintf_test.check"
#include <string.h>
#include <stdio.h>
#include "../s21_string.h"

// Used here to remove the following warning - "warning: implicit declaration of function s21_sprintf"
int s21_sprintf(char *buffer, const char *format, ...);

// %% Single percent sign test
START_TEST(s21_sprintf_test00)
{
#line 10
    const char percent = '%';
    const char *format = "%%c";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, percent);
    const int result = sprintf(buffer, format, percent);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %% Multiple percent sign test
}
END_TEST

START_TEST(s21_sprintf_test01)
{
#line 26
    const char percent = '%';
    const char *format = "%%c%%%c%%%%c%%%%%c%%%%%%c";

    char s21_buffer[200];
    memset(s21_buffer, 0, 200);
    char buffer[200];
    memset(buffer, 0, 200);

    const int s21_result = s21_sprintf(s21_buffer, format, percent, percent, percent, percent, percent);
    const int result = sprintf(buffer, format, percent, percent, percent, percent, percent);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %% Multiple percent sign test with string inbetween
}
END_TEST

START_TEST(s21_sprintf_test02)
{
#line 42
    const char percent = '%';
    const char *format = "%%c%%%c%%%%c%%%%%c%%%%%%c Hello world %%c%%%c%%%%c%%%%%c%%%%%%c Hello world %%c%%%c%%%%c%%%%%c%%%%%%c";

    char s21_buffer[300];
    memset(s21_buffer, 0, 300);
    char buffer[300];
    memset(buffer, 0, 300);

    const int s21_result = s21_sprintf(s21_buffer, format, percent, percent, percent, percent, percent, percent, percent, percent, percent, percent, percent, percent, percent, percent, percent);
    const int result = sprintf(buffer, format, percent, percent, percent, percent, percent, percent, percent, percent, percent, percent, percent, percent, percent, percent, percent);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// % Invalid chars after the percent
// If a percent sign (%) is followed by a character that has no meaning as a format field, the character is simply copied to the buffer
}
END_TEST

START_TEST(s21_sprintf_test03)
{
#line 59
    const char misc_char = '@';
    const char *format = "%%c";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, misc_char);
    const int result = sprintf(buffer, format, misc_char);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// % Invalid chars after the percent
// If a percent sign (%) is followed by a character that has no meaning as a format field, the character is simply copied to the buffer
}
END_TEST

START_TEST(s21_sprintf_test04)
{
#line 76
    const char *format = "%@!%(%)%{%}%%==";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format);
    const int result = sprintf(buffer, format);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// % More invalid chars after the percent
// If a percent sign (%) is followed by a character that has no meaning as a format field, the character is simply copied to the buffer
}
END_TEST

START_TEST(s21_sprintf_test05)
{
#line 92
    const char *format = "%^%$%^&$#%@%!1234566543%{dfghjdf%±";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format);
    const int result = sprintf(buffer, format);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// % More invalid chars after the percent
// If a percent sign (%) is followed by a character that has no meaning as a format field, the character is simply copied to the buffer
}
END_TEST

START_TEST(s21_sprintf_test06)
{
#line 108
    const char *format = "%%%@!12345665()[]{}{{***43dfghjdf";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format);
    const int result = sprintf(buffer, format);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// % More invalid chars after the percent
// If a percent sign (%) is followed by a character that has no meaning as a format field, the character is simply copied to the buffer
}
END_TEST

START_TEST(s21_sprintf_test07)
{
#line 124
    const char *format = "р%%о%л%д%%@%!%%2345665()[вавава]{привет мир}{{***43вававаdfghjdf";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format);
    const int result = sprintf(buffer, format);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %c Regular value test
}
END_TEST

START_TEST(s21_sprintf_test1)
{
#line 139
    const char input = '!';
    const char *format = "Hello, World%c!%c";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input, input);
    const int result = sprintf(buffer, format, input, input);
    
    ck_assert_str_eq(s21_buffer, buffer);
 
// %c Test with a few of char variables
}
END_TEST

START_TEST(s21_sprintf_test2)
{
#line 154
    const char first_input = '!';
    const char second_input = '?';
    const char *format = "%c%c%cHello, World%c!%c%c";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, first_input, first_input, first_input, second_input, second_input, second_input);
    const int result = sprintf(buffer, format, first_input, first_input, first_input, second_input, second_input, second_input);
    
    ck_assert_str_eq(s21_buffer, buffer);

// %c Try to print out %c as a %d value
}
END_TEST

START_TEST(s21_sprintf_test3)
{
#line 170
    const char input = '!';
    const char *format = "Hello, World%d%d%d";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input, input, input);
    const int result = sprintf(buffer, format, input, input, input);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %c %d Try to print both %c and %d
}
END_TEST

START_TEST(s21_sprintf_test4)
{
#line 186
    const char input_char = '!';
    const int input_int = 15;
    const char *format = "Hello, World%c%c%c %d%d%d";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_char, input_char, input_char, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_char, input_char, input_char, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %d Minimum value test
}
END_TEST

START_TEST(s21_sprintf_test5)
{
#line 203
    const int input_int = 0;
    const char *format = "%d%d Hello, World %d%d";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %d Maximum range of int test
}
END_TEST

START_TEST(s21_sprintf_test6)
{
#line 219
    const int input_int = 2147483647;
    const char *format = "%d%d Hello, World %d%d";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// DECIMAL Maximum negative value test
}
END_TEST

START_TEST(s21_sprintf_test7)
{
#line 235
    const int input_int = -2147483647;
    const char *format = "%d%d Hello, World %d%d";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %d Normal value test
}
END_TEST

START_TEST(s21_sprintf_test8)
{
#line 251
    const int input_int = 47483648;
    const char *format = "%d%d Hello, World %d%d";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// DECIMAL Normal negative value test
}
END_TEST

START_TEST(s21_sprintf_test9)
{
#line 267
    const int input_int = -47483648;
    const char *format = "%d%d Hello, World %d%d";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %d Normal value test - a lot of variables
}
END_TEST

START_TEST(s21_sprintf_test10)
{
#line 283
    const int input_int = 947483648;
    const char *format = "%d%d%d%d Hello, World %d%d%d%d";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %d Abnormal value - zero in the begging of the number
}
END_TEST

START_TEST(s21_sprintf_test11)
{
#line 299
    const int input_int = 012;
    const char *format = "%d%d%d%d Hello, World %d%d%d%d";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %i Maximum value of hexadecimal int
}
END_TEST

START_TEST(s21_sprintf_test12)
{
#line 315
    const int input_int = 0x7FFFFFFF;
    const char *format = "%i%i%i Hello, World %i%i%i";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %i Normal value of hexadecimal int
}
END_TEST

START_TEST(s21_sprintf_test13)
{
#line 331
    const int input_int = 0x723100;
    const char *format = "%i%i%i Hello, World %i%i%i";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %i Minimum value of hexadecimal int
}
END_TEST

START_TEST(s21_sprintf_test14)
{
#line 347
    const int input_int = -0x7FFFFFFF;
    const char *format = "%i%i%i Hello, World %i%i%i";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %i Maximum value of octal int
}
END_TEST

START_TEST(s21_sprintf_test15)
{
#line 363
    const int input_int = 017777777777;
    const char *format = "%i%i%i Hello, World %i%i%i";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %i Normal value of octal int
}
END_TEST

START_TEST(s21_sprintf_test16)
{
#line 379
    const int input_int = 034430377;
    const char *format = "%i%i%i Hello, World %i%i%i";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %i Minimum value of octal int
}
END_TEST

START_TEST(s21_sprintf_test17)
{
#line 395
    const int input_int = -017777777777;
    const char *format = "%i%i%i Hello, World %i%i%i";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %i Maximum int test
}
END_TEST

START_TEST(s21_sprintf_test18)
{
#line 411
    const int input_int = 2147483647;
    const char *format = "%i%i%i Hello, World %i%i%i";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %i Minimum int test
}
END_TEST

START_TEST(s21_sprintf_test19)
{
#line 427
    const int input_int = -2147483647;
    const char *format = "%i%i%i Hello, World %i%i%i";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %i Regular int test
}
END_TEST

START_TEST(s21_sprintf_test20)
{
#line 443
    const int input_int = 7483647;
    const char *format = "%i%i%i Hello, World %i%i%i";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %f Regular double test - all 6 decimal places
}
END_TEST

START_TEST(s21_sprintf_test21)
{
#line 459
    const double input_int = 748364.123456;
    const char *format = " Hello, World %f";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int);
    const int result = sprintf(buffer, format, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %f Regular double test - 3 decimal places
}
END_TEST

START_TEST(s21_sprintf_test22)
{
#line 475
    const double input_int = 748364.123;
    const char *format = " Hello, World %f";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int);
    const int result = sprintf(buffer, format, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %f Regular double test - 0 decimal places
}
END_TEST

START_TEST(s21_sprintf_test23)
{
#line 491
    const double input_int = 748364;
    const char *format = " Hello, World %f";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int);
    const int result = sprintf(buffer, format, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %f Regular double test - multiple values in the begging and at the end of the string
}
END_TEST

START_TEST(s21_sprintf_test24)
{
#line 507
    const double input_int = 748364.123;
    const char *format = "test %f %f %f Hello, World %f %f %f test";

    char s21_buffer[200];
    memset(s21_buffer, 0, 200);
    char buffer[200];
    memset(buffer, 0, 200);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %f Regular double test - multiple values in the begging and at the end of the string with string in between
}
END_TEST

START_TEST(s21_sprintf_test25)
{
#line 523
    const double input_int = 748364.123;
    const char *format = "test %f test %f test %f Hello, World %f test %f test %f test";

    char s21_buffer[200];
    memset(s21_buffer, 0, 200);
    char buffer[200];
    memset(buffer, 0, 200);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %f Regular double test - multiple values in the row
}
END_TEST

START_TEST(s21_sprintf_test26)
{
#line 539
    const double input_int = 748364.123;
    const char *format = "test %f%f%f Hello, World %f%f%f test";

    char s21_buffer[200];
    memset(s21_buffer, 0, 200);
    char buffer[200];
    memset(buffer, 0, 200);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %s Regular value test
}
END_TEST

START_TEST(s21_sprintf_test27)
{
#line 555
    char test_string[100] = "hello world";
    char *pointer = test_string;
    const char *format = "%s";

    char s21_buffer[500];
    memset(s21_buffer, 0, 500);
    char buffer[500];
    memset(buffer, 0, 500);

    const int s21_result = s21_sprintf(s21_buffer, format, test_string);
    const int result = sprintf(buffer, format, test_string);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %s Regular value test - duplicate in a row
}
END_TEST

START_TEST(s21_sprintf_test28)
{
#line 572
    char test_string[100] = "hello world";
    char *pointer = test_string;
    const char *format = "%s %s %s hello %s %s %s world %s %s %s";

    char s21_buffer[500];
    memset(s21_buffer, 0, 500);
    char buffer[500];
    memset(buffer, 0, 500);

    const int s21_result = s21_sprintf(s21_buffer, format, test_string, test_string, test_string, test_string, test_string, test_string, test_string, test_string, test_string);
    const int result = sprintf(buffer, format, test_string, test_string, test_string, test_string, test_string, test_string, test_string, test_string, test_string);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %s Regular value test - duplicate in a row
}
END_TEST

START_TEST(s21_sprintf_test29)
{
#line 589
    char test_string[100] = "hello world";
    char *pointer = test_string;
    const char *format = "%s %s %s hello %s %s %s world %s %s %s";

    char s21_buffer[500];
    memset(s21_buffer, 0, 500);
    char buffer[500];
    memset(buffer, 0, 500);

    const int s21_result = s21_sprintf(s21_buffer, format, test_string, test_string, test_string, test_string, test_string, test_string, test_string, test_string, test_string);
    const int result = sprintf(buffer, format, test_string, test_string, test_string, test_string, test_string, test_string, test_string, test_string, test_string);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %s Empty string test
}
END_TEST

START_TEST(s21_sprintf_test30)
{
#line 606
    char test_string[100] = "\0";
    char *pointer = test_string;
    const char *format = "%s %s %s hello %s %s %s world %s %s %s";

    char s21_buffer[500];
    memset(s21_buffer, 0, 500);
    char buffer[500];
    memset(buffer, 0, 500);

    const int s21_result = s21_sprintf(s21_buffer, format, test_string, test_string, test_string, test_string, test_string, test_string, test_string, test_string, test_string);
    const int result = sprintf(buffer, format, test_string, test_string, test_string, test_string, test_string, test_string, test_string, test_string, test_string);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %u Regular value test
}
END_TEST

START_TEST(s21_sprintf_test31)
{
#line 623
    const unsigned int input_int = 748364;
    const char *format = " Hello, World %u";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int);
    const int result = sprintf(buffer, format, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %u Regular value test - multiple u_specifiers in a row
}
END_TEST

START_TEST(s21_sprintf_test32)
{
#line 639
    const unsigned int input_int = 748364;
    const char *format = "%u %u %u Hello, World %u%u%u Hello, World %u %u %u";

    char s21_buffer[200];
    memset(s21_buffer, 0, 200);
    char buffer[200];
    memset(buffer, 0, 200);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int, input_int, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int, input_int, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %u Regular value test - multiple u_specifiers in a row with different values
}
END_TEST

START_TEST(s21_sprintf_test33)
{
#line 655
    const unsigned int input_unsigned_int_first = 748364;
    const unsigned int input_unsigned_int_second = 12345;
    const char *format = "%u %u %u Hello, World %u%u%u Hello, World %u %u %u";

    char s21_buffer[200];
    memset(s21_buffer, 0, 200);
    char buffer[200];
    memset(buffer, 0, 200);

    const int s21_result = s21_sprintf(s21_buffer, format, input_unsigned_int_first, input_unsigned_int_second, input_unsigned_int_first, input_unsigned_int_second, input_unsigned_int_first, input_unsigned_int_second, input_unsigned_int_first, input_unsigned_int_second, input_unsigned_int_first);
    const int result = sprintf(buffer, format, input_unsigned_int_first, input_unsigned_int_second, input_unsigned_int_first, input_unsigned_int_second, input_unsigned_int_first, input_unsigned_int_second, input_unsigned_int_first, input_unsigned_int_second, input_unsigned_int_first);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %u Regular value test - tripple u_specifiers in a row with different values
}
END_TEST

START_TEST(s21_sprintf_test34)
{
#line 672
    const unsigned int input_unsigned_int_first = 748364;
    const unsigned int input_unsigned_int_second = 12345;
    const unsigned int input_unsigned_int_third = 1337;
    const char *format = "%u %u %u Hello, World %u%u%u Hello, World %u %u %u";

    char s21_buffer[200];
    memset(s21_buffer, 0, 200);
    char buffer[200];
    memset(buffer, 0, 200);

    const int s21_result = s21_sprintf(s21_buffer, format, input_unsigned_int_first, input_unsigned_int_second, input_unsigned_int_third, input_unsigned_int_second, input_unsigned_int_first, input_unsigned_int_second, input_unsigned_int_third, input_unsigned_int_second, input_unsigned_int_first);
    const int result = sprintf(buffer, format, input_unsigned_int_first, input_unsigned_int_second, input_unsigned_int_third, input_unsigned_int_second, input_unsigned_int_first, input_unsigned_int_second, input_unsigned_int_third, input_unsigned_int_second, input_unsigned_int_first);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %u Minimum value test
}
END_TEST

START_TEST(s21_sprintf_test35)
{
#line 690
    const unsigned int input_unsigned_int = 0;
    const char *format = "Hello, World %u";

    char s21_buffer[200];
    memset(s21_buffer, 0, 200);
    char buffer[200];
    memset(buffer, 0, 200);

    const int s21_result = s21_sprintf(s21_buffer, format, input_unsigned_int);
    const int result = sprintf(buffer, format, input_unsigned_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %u Minimum value test - multiple values
}
END_TEST

START_TEST(s21_sprintf_test36)
{
#line 706
    const unsigned int input_unsigned_int = 0;
    const char *format = "%u %u %u Hello, World %u%u%u Hello, World %u %u %u";

    char s21_buffer[200];
    memset(s21_buffer, 0, 200);
    char buffer[200];
    memset(buffer, 0, 200);

    const int s21_result = s21_sprintf(s21_buffer, format, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int);
    const int result = sprintf(buffer, format, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %u Maximum value test
}
END_TEST

START_TEST(s21_sprintf_test37)
{
#line 722
    const unsigned int input_unsigned_int = 4294967295;
    const char *format = "Hello, World %u";

    char s21_buffer[200];
    memset(s21_buffer, 0, 200);
    char buffer[200];
    memset(buffer, 0, 200);

    const int s21_result = s21_sprintf(s21_buffer, format, input_unsigned_int);
    const int result = sprintf(buffer, format, input_unsigned_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %u Maximum value test - multiple values
}
END_TEST

START_TEST(s21_sprintf_test38)
{
#line 738
    const unsigned int input_unsigned_int = 4294967295;
    const char *format = "%u %u %u Hello, World %u%u%u Hello, World %u %u %u";

    char s21_buffer[200];
    memset(s21_buffer, 0, 200);
    char buffer[200];
    memset(buffer, 0, 200);

    const int s21_result = s21_sprintf(s21_buffer, format, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int);
    const int result = sprintf(buffer, format, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %u Abnormal value - negative value
}
END_TEST

START_TEST(s21_sprintf_test39)
{
#line 754
    const unsigned int input_unsigned_int = -3;
    const char *format = "%u %u %u Hello, World %u%u%u Hello, World %u %u %u";

    char s21_buffer[200];
    memset(s21_buffer, 0, 200);
    char buffer[200];
    memset(buffer, 0, 200);

    const int s21_result = s21_sprintf(s21_buffer, format, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int);
    const int result = sprintf(buffer, format, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %u Abnormal value - bigger than max range value
}
END_TEST

START_TEST(s21_sprintf_test40)
{
#line 770
    const long int input_unsigned_int = 8589934590;
    const char *format = "%u %u %u Hello, World %u%u%u Hello, World %u %u %u";

    char s21_buffer[200];
    memset(s21_buffer, 0, 200);
    char buffer[200];
    memset(buffer, 0, 200);

    const int s21_result = s21_sprintf(s21_buffer, format, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int);
    const int result = sprintf(buffer, format, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int, input_unsigned_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %6 - Right-justify flag
}
END_TEST

START_TEST(s21_sprintf_test41)
{
#line 786
    const char *format = "%6 Hello, %6 World";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format);
    const int result = sprintf(buffer, format);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %42 - Right-justify flag
}
END_TEST

START_TEST(s21_sprintf_test43)
{
#line 801
    const char *format = "%42 Hello, %42 World %42";

    char s21_buffer[300];
    memset(s21_buffer, 0, 300);
    char buffer[300];
    memset(buffer, 0, 300);

    const int s21_result = s21_sprintf(s21_buffer, format);
    const int result = sprintf(buffer, format);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %42 - Right-justify flag with %d variable
}
END_TEST

START_TEST(s21_sprintf_test44)
{
#line 816
    const int input_int = 42;
    const char *format = "%42d Hello, %42d World %42d";

    char s21_buffer[300];
    memset(s21_buffer, 0, 300);
    char buffer[300];
    memset(buffer, 0, 300);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %42 - Right-justify flag with %d and %c variable
}
END_TEST

START_TEST(s21_sprintf_test45)
{
#line 832
    const int input_int = 42;
    const char input_char = 's';
    const char *format = "%42d Hello, %42c World %42d";

    char s21_buffer[300];
    memset(s21_buffer, 0, 300);
    char buffer[300];
    memset(buffer, 0, 300);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_char, input_int);
    const int result = sprintf(buffer, format, input_int, input_char, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %42 - Right-justify flag with %d and %c variable. Minimum value
}
END_TEST

START_TEST(s21_sprintf_test46)
{
#line 849
    const int input_int = 42;
    const char input_char = 's';
    const char *format = "%1d Hello, %1c World %1d";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_char, input_int);
    const int result = sprintf(buffer, format, input_int, input_char, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// %42 - Right-justify flag with %d and %c variable. Big value
}
END_TEST

START_TEST(s21_sprintf_test47)
{
#line 866
    const int input_int = 42;
    const char input_char = 's';
    const char *format = "%100d Hello, %100c World %100d";

    char s21_buffer[500];
    memset(s21_buffer, 0, 500);
    char buffer[500];
    memset(buffer, 0, 500);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_char, input_int);
    const int result = sprintf(buffer, format, input_int, input_char, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, s21_sprintf_test00);
    tcase_add_test(tc1_1, s21_sprintf_test01);
    tcase_add_test(tc1_1, s21_sprintf_test02);
    tcase_add_test(tc1_1, s21_sprintf_test03);
    tcase_add_test(tc1_1, s21_sprintf_test04);
    tcase_add_test(tc1_1, s21_sprintf_test05);
    tcase_add_test(tc1_1, s21_sprintf_test06);
    tcase_add_test(tc1_1, s21_sprintf_test07);
    tcase_add_test(tc1_1, s21_sprintf_test1);
    tcase_add_test(tc1_1, s21_sprintf_test2);
    tcase_add_test(tc1_1, s21_sprintf_test3);
    tcase_add_test(tc1_1, s21_sprintf_test4);
    tcase_add_test(tc1_1, s21_sprintf_test5);
    tcase_add_test(tc1_1, s21_sprintf_test6);
    tcase_add_test(tc1_1, s21_sprintf_test7);
    tcase_add_test(tc1_1, s21_sprintf_test8);
    tcase_add_test(tc1_1, s21_sprintf_test9);
    tcase_add_test(tc1_1, s21_sprintf_test10);
    tcase_add_test(tc1_1, s21_sprintf_test11);
    tcase_add_test(tc1_1, s21_sprintf_test12);
    tcase_add_test(tc1_1, s21_sprintf_test13);
    tcase_add_test(tc1_1, s21_sprintf_test14);
    tcase_add_test(tc1_1, s21_sprintf_test15);
    tcase_add_test(tc1_1, s21_sprintf_test16);
    tcase_add_test(tc1_1, s21_sprintf_test17);
    tcase_add_test(tc1_1, s21_sprintf_test18);
    tcase_add_test(tc1_1, s21_sprintf_test19);
    tcase_add_test(tc1_1, s21_sprintf_test20);
    tcase_add_test(tc1_1, s21_sprintf_test21);
    tcase_add_test(tc1_1, s21_sprintf_test22);
    tcase_add_test(tc1_1, s21_sprintf_test23);
    tcase_add_test(tc1_1, s21_sprintf_test24);
    tcase_add_test(tc1_1, s21_sprintf_test25);
    tcase_add_test(tc1_1, s21_sprintf_test26);
    tcase_add_test(tc1_1, s21_sprintf_test27);
    tcase_add_test(tc1_1, s21_sprintf_test28);
    tcase_add_test(tc1_1, s21_sprintf_test29);
    tcase_add_test(tc1_1, s21_sprintf_test30);
    tcase_add_test(tc1_1, s21_sprintf_test31);
    tcase_add_test(tc1_1, s21_sprintf_test32);
    tcase_add_test(tc1_1, s21_sprintf_test33);
    tcase_add_test(tc1_1, s21_sprintf_test34);
    tcase_add_test(tc1_1, s21_sprintf_test35);
    tcase_add_test(tc1_1, s21_sprintf_test36);
    tcase_add_test(tc1_1, s21_sprintf_test37);
    tcase_add_test(tc1_1, s21_sprintf_test38);
    tcase_add_test(tc1_1, s21_sprintf_test39);
    tcase_add_test(tc1_1, s21_sprintf_test40);
    tcase_add_test(tc1_1, s21_sprintf_test41);
    tcase_add_test(tc1_1, s21_sprintf_test43);
    tcase_add_test(tc1_1, s21_sprintf_test44);
    tcase_add_test(tc1_1, s21_sprintf_test45);
    tcase_add_test(tc1_1, s21_sprintf_test46);
    tcase_add_test(tc1_1, s21_sprintf_test47);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}