/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "s21_sprintf_test.check" instead.
 */

#include <check.h>

#line 1 "s21_sprintf_test.check"
#include <string.h>
#include <stdio.h>
#include "../s21_string.h"

// CHAR Regular value test
START_TEST(s21_sprintf_test1)
{
#line 7
    const char input = '!';
    const char *format = "Hello, World%c!%c";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input, input);
    const int result = sprintf(buffer, format, input, input);
    
    ck_assert_str_eq(s21_buffer, buffer);
 
// CHAR Test with a few of char variables
}
END_TEST

START_TEST(s21_sprintf_test2)
{
#line 22
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

// CHAR Try to print out %c as a %d value
}
END_TEST

START_TEST(s21_sprintf_test3)
{
#line 38
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

// CHAR DECIMAL Try to print both %c and %d
}
END_TEST

START_TEST(s21_sprintf_test4)
{
#line 54
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

// DECIMAL Minimum value test
}
END_TEST

START_TEST(s21_sprintf_test5)
{
#line 71
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

// DECIMAL Maximum range of int test
}
END_TEST

START_TEST(s21_sprintf_test6)
{
#line 87
    const int input_int = 2147483648;
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
#line 103
    const int input_int = -2147483648;
    const char *format = "%d%d Hello, World %d%d";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int);
    
    ck_assert_str_eq(s21_buffer, buffer);
    ck_assert_int_eq(s21_result, result);

// DECIMAL Normal value test
}
END_TEST

START_TEST(s21_sprintf_test8)
{
#line 119
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
#line 135
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

// DECIMAL Normal value test - a lot of variables
}
END_TEST

START_TEST(s21_sprintf_test10)
{
#line 151
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
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
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

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
