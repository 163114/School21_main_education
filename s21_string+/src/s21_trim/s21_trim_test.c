/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "s21_trim_test.check" instead.
 */

#include <check.h>

#line 1 "s21_trim_test.check"
#include <string.h>
#include <stdlib.h>
#include "../s21_string.h"

START_TEST(s21_to_trim_test1)
{
#line 6
    const char *string = "----URGH DA FUCK!+++++";
    const char *symbols_to_remove = "+-";
    const char *expected = "URGH DA FUCK!";
    
    char *actual = s21_trim(string, symbols_to_remove);
    ck_assert_pstr_eq(actual, expected);

    free(actual);

}
END_TEST

START_TEST(s21_to_trim_test2)
{
#line 16
    const char *string = "--/.. --URGH DA FUCK!+++++/... ";
    const char *symbols_to_remove = "/+.- ";
    const char *expected = "URGH DA FUCK!";
    
    char *actual = s21_trim(string, symbols_to_remove);
    ck_assert_pstr_eq(actual, expected);

    free(actual);

}
END_TEST

START_TEST(s21_to_trim_test3)
{
#line 26
    const char *string = "--/.. --URGH../ DA../+- FUCK!+++++/... ";
    const char *symbols_to_remove = "/+.- ";
    const char *expected = "URGH../ DA../+- FUCK!";
    
    char *actual = s21_trim(string, symbols_to_remove);
    ck_assert_pstr_eq(actual, expected);

    free(actual);

}
END_TEST

START_TEST(s21_to_trim_test4)
{
#line 36
    const char *string = "--/.. &*--URGH../ DA../+- FUCK!+++&*++/... ";
    const char *symbols_to_remove = "/+.- *&";
    const char *expected = "URGH../ DA../+- FUCK!";
    
    char *actual = s21_trim(string, symbols_to_remove);
    ck_assert_pstr_eq(actual, expected);

    free(actual);

}
END_TEST

START_TEST(s21_to_trim_test5)
{
#line 46
    const char *string = "1-2-3/4.5.6 7&8*9-0-URGH../ DA1234567890./+- FUCK!+++&*++/... 123456789";
    const char *symbols_to_remove = "67890/+.- *&12345";
    const char *expected = "URGH../ DA1234567890./+- FUCK!";
    
    char *actual = s21_trim(string, symbols_to_remove);
    ck_assert_pstr_eq(actual, expected);

    free(actual);

}
END_TEST

START_TEST(s21_to_trim_test6)
{
#line 56
    const char *string = "1-2-3/4.5.6 7&8*9-0-URGH../ DA1234567890./+- FUCK!+++&*++/... 123456789";
    const char *symbols_to_remove = "";
    const char *expected = "1-2-3/4.5.6 7&8*9-0-URGH../ DA1234567890./+- FUCK!+++&*++/... 123456789";
    
    char *actual = s21_trim(string, symbols_to_remove);
    ck_assert_pstr_eq(actual, expected);

    free(actual);

}
END_TEST

START_TEST(s21_to_trim_test7)
{
#line 66
    const char *string = "";
    const char *symbols_to_remove = "+- ";
    const char *expected = "";
    
    char *actual = s21_trim(string, symbols_to_remove);
    ck_assert_pstr_eq(actual, expected);

    free(actual);

}
END_TEST

START_TEST(s21_to_trim_test8)
{
#line 76
    const char *string = "";
    const char *symbols_to_remove = "";
    const char *expected = "";
    
    char *actual = s21_trim(string, symbols_to_remove);
    ck_assert_pstr_eq(actual, expected);

    free(actual);

}
END_TEST

START_TEST(s21_to_trim_test9)
{
#line 86
    const char *string = "0000102030405060708090000";
    const char *symbols_to_remove = "0";
    const char *expected = "10203040506070809";
    
    char *actual = s21_trim(string, symbols_to_remove);
    ck_assert_pstr_eq(actual, expected);

    free(actual);

}
END_TEST

START_TEST(s21_to_trim_test10)
{
#line 96
    const char *string = "000 0102030405060708090 000";
    const char *symbols_to_remove = "0";
    const char *expected = " 0102030405060708090 ";
    
    char *actual = s21_trim(string, symbols_to_remove);
    ck_assert_pstr_eq(actual, expected);

    free(actual);

}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, s21_to_trim_test1);
    tcase_add_test(tc1_1, s21_to_trim_test2);
    tcase_add_test(tc1_1, s21_to_trim_test3);
    tcase_add_test(tc1_1, s21_to_trim_test4);
    tcase_add_test(tc1_1, s21_to_trim_test5);
    tcase_add_test(tc1_1, s21_to_trim_test6);
    tcase_add_test(tc1_1, s21_to_trim_test7);
    tcase_add_test(tc1_1, s21_to_trim_test8);
    tcase_add_test(tc1_1, s21_to_trim_test9);
    tcase_add_test(tc1_1, s21_to_trim_test10);

    srunner_set_fork_status(sr, CK_NOFORK); srunner_set_fork_status(sr, CK_NOFORK); srunner_set_fork_status(sr, CK_NOFORK); srunner_set_fork_status(sr, CK_NOFORK); srunner_set_fork_status(sr, CK_NOFORK); srunner_set_fork_status(sr, CK_NOFORK); srunner_set_fork_status(sr, CK_NOFORK); srunner_set_fork_status(sr, CK_NOFORK); srunner_set_fork_status(sr, CK_NOFORK); srunner_set_fork_status(sr, CK_NOFORK); srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
