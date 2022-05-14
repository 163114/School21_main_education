/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "s21_sprintf_test.check" instead.
 */

#include <check.h>

#line 1 "s21_sprintf_test.check"
#include <string.h>
#include <stdio.h>
#include "../s21_string.h"

START_TEST(s21_sprintf_test1)
{
#line 6
    const int input = 15;
    const char *format = "%d";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input);
    const int result = sprintf(buffer, format, input);
    
    ck_assert_int_eq(s21_result, result);
    ck_assert_mem_eq(s21_buffer, buffer, 100);


}
END_TEST

START_TEST(s21_sprintf_test2)
{
#line 22
    const float input = 15.55;
    const char *format = "%f";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input);
    const int result = sprintf(buffer, format, input);
    
    ck_assert_int_eq(s21_result, result);
    ck_assert_mem_eq(s21_buffer, buffer, 100);
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

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}