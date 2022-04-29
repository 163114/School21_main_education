/**
 * @file s21_string_unit.c
 * @author arrynpal
 * 
 * @brief Case unit-test for s21_string.h
 * 
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * @warning metods from 3 to 5 return tupes is void. I don't know how function will be working.
 */
#ifndef S21_STRING_UNIT
#define S21_STRING_UNIT
#include <check.h>
// #include <stdlib.h>
#include <string.h>

#include "../code-samples/s21_strlen.c"

char str[] = "School 21 - it is cool!";
char str_[] = "";       //    !!! ====================== where it is !!!

char str1_1[] = "1942, late evening, Bletchley Park, Alan Turing's desk.";
char str2_1[] = "1942, late evening(...). For almost a year, a group of smartest mathematicians...";
char str1_2[] = "The group often had to come up with different algorithms, ";
char str2_2[] = "and they even developed a special set of keywords and their syntax...";
char s1 = 'h', s2 = 'o', s3 = 'j', s4 = '\0';  /* using memchr_test */

size_t n = 5;

s21_size_t s21_n = 5;   /* using: memchr_test */

/* ------------ memchr ------------ 1 -- */
START_TEST(memchr_test_1)
{
    ch_assert_ptr_eq(s21_memchr(str, (int) s1, s21_n), memchr(str, (int) s1, n));
} END_TEST

START_TEST(memchr_test_2)
{
    ch_assert_ptr_eq(s21_memchr(str, (int) s3, s21_n), memchr(str, (int) s3, n));
} END_TEST

START_TEST(memchr_test_3)
{
    ch_assert_ptr_eq(s21_memchr(str_, (int) s3, s21_n), memchr(str_, (int) s3, n));
} END_TEST

/* ------------ memcmp ------------ 2 -- */
START_TEST(memcmp_test_1)
{
    ch_assert_int_eq(s21_memcmp(str1_1, str2_1, s21_n), memcmp(str1_1, str2_1, n));
} END_TEST

START_TEST(memcmp_test_2)
{
    ch_assert_int_eq(s21_memcmp(str1_2, str2_2, s21_n), memcmp(str1_2, str2_2, n));
} END_TEST

START_TEST(memcmp_test_3)
{
    ch_assert_int_eq(s21_memcmp(str1_2, str_, s21_n), memcmp(str1_2, str_, n));
} END_TEST

/* ------------ memcpy ------------ 3 -- */
START_TEST(memcpy_test_1)
{
    char b_str1[] = str1_1, b_str2[] = str1_1;
    ch_assert_str_eq(s21_memcpy(b_str1, str2_2, s21_n), memcpy(b_str2, str2_2, n));
} END_TEST

START_TEST(memcpy_test_2)
{
    char b_str1[] = str1_1, b_str2[] = str1_1;
    ch_assert_str_eq(s21_memcpy(b_str1, str_, s21_n), memcpy(b_str2, str_, n));
} END_TEST

START_TEST(memcpy_test_3)
{
    char b_str1[] = str_, b_str2[] = str_;
    ch_assert_str_eq(s21_memcpy(b_str1, str2_2, s21_n), memcpy(b_str2, str2_2, n));
} END_TEST

/* ------------ memmove ------------ 4 -- */
START_TEST(memcmp_test_1)
{
    /* ======= code ======= */
} END_TEST

/* ------------ memset ------------ 5 -- */
START_TEST(memset_test_1)
{
    char b_str1[] = str1_1, b_str2[] = str1_1;
    ch_assert_str_eq(s21_memset(b_str1, (int) s1, s21_n), memset(b_str2, (int) s1, n));
} END_TEST

START_TEST(memset_test_2)
{
    char b_str1[] = str_, b_str2[] = str_;
    ch_assert_str_eq(s21_memset(b_str1, (int) s1, s21_n), memset(b_str2, (int) s1, n));
} END_TEST

START_TEST(memset_test_3)
{
     char b_str1[] = str1_1, b_str2[] = str1_1;
    ch_assert_str_eq(s21_memset(b_str1, (int) s4, s21_n), memset(b_str2, (int) s4, n));
} END_TEST

START_TEST(memset_test_4)
{
     char b_str1[] = str_, b_str2[] = str_;
    ch_assert_str_eq(s21_memset(b_str1, (int) s4, s21_n), memset(b_str2, (int) s4, n));
} END_TEST

/* ------------ strcat ------------ 6 -- */
START_TEST(strcat_test_1)
{
    char b_str1[] = str1_1, b_str2[] = str1_1;
    ch_assert_str_eq(s21_strcat(b_str1, str2_1), strcat(b_str2, str2_1));
} END_TEST

START_TEST(strcat_test_2)
{
    char b_str1[] = str_, b_str2[] = str_;
    ch_assert_str_eq(s21_strcat(b_str1, str2_1), strcat(b_str2, str2_1));
} END_TEST

START_TEST(strcat_test_3)
{
    char b_str1[] = str1_1, b_str2[] = str1_1;
    ch_assert_str_eq(s21_strcat(b_str1, str_), strcat(b_str2, str_));
} END_TEST

/* ------------ strncat ------------ 7 -- */
START_TEST(strncat_test_1)
{
    char b_str1[] = str1_1, b_str2[] = str1_1;
    ch_assert_str_eq(s21_strncat(b_str1, str2_1, s21_n), strncat(b_str2, str2_1, n));
} END_TEST

START_TEST(strncat_test_2)
{
    char b_str1[] = str_, b_str2[] = str_;
    ch_assert_str_eq(s21_strncat(b_str1, str2_1, s21_n), strncat(b_str2, str2_1, n));
} END_TEST

START_TEST(strncat_test_3)
{
    char b_str1[] = str1_1, b_str2[] = str1_1;
    ch_assert_str_eq(s21_strncat(b_str1, str_, s21_n), strncat(b_str2, str_, n));
} END_TEST

/* ------------ strchr ------------ 8 -- */
START_TEST(strchr_test_1)
{
    ch_assert_str_eq(s21_strchr(b_str1, str2_1, s21_n), strchr(b_str2, str2_1, n));
} END_TEST


#endif /* S21_STRING_UNIT */

