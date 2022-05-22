// /**
//  * @file s21_string_unit.c
//  * @author arrynpal
//  * 
//  * @brief Case unit-test for s21_string.h
//  * 
//  * @version 0.1
//  * @date 2022-04-29
//  * @copyright Copyright (c) 2022
//  * 
//  * @warning metods from 3 to 5 return tupes is void. I don't know how function will be working.
//  * @warning strspn -- 13 - 15 - 18 -- ck_assert(...)
//  * @warning strerror() wath equal ptr or str?
//  * 
//  * @todo function 19 - 20, sprintf, sscanf, test suite (function), main.
//  * @todo include library s21_string.h, delet ../code-samples/s21_strlen.c
//  * @todo delet all comenters
//  */
// #ifndef S21_STRING_UNIT
// #define S21_STRING_UNIT
// #include <check.h>
// // #include <stdlib.h>
// #include <string.h>

// // #include "../code-samples/s21_strlen.c"
// #include "s21_string.h"

// char str[] = "School 21 - it is cool!";
// char str_[] = "";       //    !!! ====================== where it is !!!

// char str1_1[] = "1942, late evening, Bletchley Park, Alan Turing's desk.";
// char str2_1[] = "1942, late evening(...). For almost a year, a group of smartest mathematicians...";
// char str1_2[] = "The group often had to come up with different algorithms, ";
// char str2_2[] = "and they even developed a special set of keywords and their syntax...";
// char s1 = 'h', s2 = 'o', s3 = 'j', s4 = '\0';  /* using memchr_test */

// /* ===!!! Atantion !!!=== s21_n and n will be equal */
// size_t n = 5;
// s21_size_t s21_n = 5;

// /* ------------ memchr ------------ 1 -- */
// START_TEST(memchr_test_1)
// {
//     ck_assert_ptr_eq(s21_memchr(str, (int) s1, s21_n), memchr(str, (int) s1, n));
// } END_TEST

// START_TEST(memchr_test_2)
// {
//     ck_assert_ptr_eq(s21_memchr(str, (int) s3, s21_n), memchr(str, (int) s3, n));
// } END_TEST

// START_TEST(memchr_test_3)
// {
//     ck_assert_ptr_eq(s21_memchr(str_, (int) s3, s21_n), memchr(str_, (int) s3, n));
// } END_TEST

// /* ------------ memcmp ------------ 2 -- */
// START_TEST(memcmp_test_1)
// {
//     ck_assert_int_eq(s21_memcmp(str1_1, str2_1, s21_n), memcmp(str1_1, str2_1, n));
// } END_TEST

// START_TEST(memcmp_test_2)
// {
//     ck_assert_int_eq(s21_memcmp(str1_2, str2_2, s21_n), memcmp(str1_2, str2_2, n));
// } END_TEST

// START_TEST(memcmp_test_3)
// {
//     ck_assert_int_eq(s21_memcmp(str1_2, str_, s21_n), memcmp(str1_2, str_, n));
// } END_TEST

// /* ------------ memcpy ------------ 3 -- */
// START_TEST(memcpy_test_1)
// {
//     char b_str1[] = "", b_str2[] = "";
//     strcpy(b_str1, str1_1);
//     strcpy(b_str2, str1_1);
//     ck_assert_str_eq(s21_memcpy(b_str1, str2_2, s21_n), memcpy(b_str2, str2_2, n));
// } END_TEST

// START_TEST(memcpy_test_2)
// {
//     char b_str1[] = "", b_str2[] = "";
//     strcpy(b_str1, str1_1);
//     strcpy(b_str2, str1_1);
//     ck_assert_str_eq(s21_memcpy(b_str1, str_, s21_n), memcpy(b_str2, str_, n));
// } END_TEST

// START_TEST(memcpy_test_3)
// {
//     char b_str1[] = "", b_str2[] = "";
//     strcpy(b_str1, str_);
//     strcpy(b_str2, str_);
//     ck_assert_str_eq(s21_memcpy(b_str1, str2_2, s21_n), memcpy(b_str2, str2_2, n));
// } END_TEST

// // /* ------------ memmove ------------ 4 -- */
// // START_TEST(memcmp_test_1)
// // {
// //     /* ======= code ======= */
// // } END_TEST

// /* ------------ memset ------------ 5 -- */
// START_TEST(memset_test_1)
// {
//     char b_str1[] = "", b_str2[] = "";
//     strcpy(b_str1, str1_1);
//     strcpy(b_str2, str1_1);
//     ck_assert_str_eq(s21_memset(b_str1, (int) s1, s21_n), memset(b_str2, (int) s1, n));
// } END_TEST

// START_TEST(memset_test_2)
// {
//     char b_str1[] = "", b_str2[] = "";
//     strcpy(b_str1, str_);
//     strcpy(b_str2, str_);
//     ck_assert_str_eq(s21_memset(b_str1, (int) s1, s21_n), memset(b_str2, (int) s1, n));
// } END_TEST

// START_TEST(memset_test_3)
// {
//     char b_str1[] = "", b_str2[] = "";
//     strcpy(b_str1, str1_1);
//     strcpy(b_str2, str1_1);
//     ck_assert_str_eq(s21_memset(b_str1, (int) s4, s21_n), memset(b_str2, (int) s4, n));
// } END_TEST

// START_TEST(memset_test_4)
// {
//     char b_str1[] = "", b_str2[] = "";
//     strcpy(b_str1, str_);
//     strcpy(b_str2, str_);
//     ck_assert_str_eq(s21_memset(b_str1, (int) s4, s21_n), memset(b_str2, (int) s4, n));
// } END_TEST

// /* ------------ strcat ------------ 6 -- */
// START_TEST(strcat_test_1)
// {
//     char b_str1[] = "", b_str2[] = "";
//     strcpy(b_str1, str1_1);
//     strcpy(b_str2, str1_1);
//     ck_assert_str_eq(s21_strcat(b_str1, str2_1), strcat(b_str2, str2_1));
// } END_TEST

// START_TEST(strcat_test_2)
// {
//     char b_str1[] = "", b_str2[] = "";
//     strcpy(b_str1, str_);
//     strcpy(b_str2, str_);
//     ck_assert_str_eq(s21_strcat(b_str1, str2_1), strcat(b_str2, str2_1));
// } END_TEST

// START_TEST(strcat_test_3)
// {
//     char b_str1[] = "", b_str2[] = "";
//     strcpy(b_str1, str1_1);
//     strcpy(b_str2, str1_1);
//     ck_assert_str_eq(s21_strcat(b_str1, str_), strcat(b_str2, str_));
// } END_TEST

// /* ------------ strncat ------------ 7 -- */
// START_TEST(strncat_test_1)
// {
//     char b_str1[] = "", b_str2[] = "";
//     strcpy(b_str1, str1_1);
//     strcpy(b_str2, str1_1);
//     ck_assert_str_eq(s21_strncat(b_str1, str2_1, s21_n), strncat(b_str2, str2_1, n));
// } END_TEST

// START_TEST(strncat_test_2)
// {
//     char b_str1[] = "", b_str2[] = "";
//     strcpy(b_str1, str_);
//     strcpy(b_str2, str_);
//     ck_assert_str_eq(s21_strncat(b_str1, str2_1, s21_n), strncat(b_str2, str2_1, n));
// } END_TEST

// START_TEST(strncat_test_3)
// {
//     char b_str1[] = "", b_str2[] = "";
//     strcpy(b_str1, str1_1);
//     strcpy(b_str2, str1_1);
//     ck_assert_str_eq(s21_strncat(b_str1, str_, s21_n), strncat(b_str2, str_, n));
// } END_TEST

// /* ------------ strchr ------------ 8 -- */
// START_TEST(strchr_test_1)
// {
//     ck_assert_str_eq(s21_strchr(str, (int) s1), strchr(str, (int) s1));
// } END_TEST

// START_TEST(strchr_test_2)
// {
//     ck_assert_str_eq(s21_strchr(str, (int) s3), strchr(str, (int) s3));
// } END_TEST

// START_TEST(strchr_test_3)
// {
//     ck_assert_str_eq(s21_strchr(str, (int) s4), strchr(str, (int) s4));
// } END_TEST

// START_TEST(strchr_test_4)
// {
//     ck_assert_str_eq(s21_strchr(str_, (int) s1), strchr(str_, (int) s1));
// } END_TEST

// START_TEST(strchr_test_5)
// {
//     ck_assert_str_eq(s21_strchr(str_, (int) s4), strchr(str_, (int) s4));
// } END_TEST

// /* ------------ strcmp ------------ 9 -- */
// START_TEST(strcmp_test_1)
// {
//     ck_assert_int_eq(s21_strcmp(str1_1, str1_2), strcmp(str1_1, str1_2));
// } END_TEST

// START_TEST(strcmp_test_2)
// {
//     ck_assert_int_eq(s21_strcmp(str2_1, str2_2), strcmp(str2_1, str2_2));
// } END_TEST

// START_TEST(strcmp_test_3)
// {
//     ck_assert_int_eq(s21_strcmp(str, str_), strcmp(str, str_));
// } END_TEST

// START_TEST(strcmp_test_4)
// {
//     ck_assert_int_eq(s21_strcmp(str_, str), strcmp(str_, str));
// } END_TEST

// /* ------------ strncmp ------------ 10 -- */
// START_TEST(strncmp_test_1)
// {
//     ck_assert_int_eq(s21_strncmp(str1_1, str1_2, s21_n), strncmp(str1_1, str1_2, n));
// } END_TEST

// START_TEST(strncmp_test_2)
// {
//     ck_assert_int_eq(s21_strncmp(str2_1, str2_2, s21_n), strncmp(str2_1, str2_2, n));
// } END_TEST

// START_TEST(strncmp_test_3)
// {
//     ck_assert_int_eq(s21_strncmp(str, str_, s21_n), strncmp(str, str_, n));
// } END_TEST

// /* ------------ strcpy ------------ 11 -- */
// START_TEST(strcpy_test_1)
// {
//     char b_str1[] = "", b_str2[] = "";
//     strcpy(b_str1, str1_1);
//     strcpy(b_str2, str1_1);
//     ck_assert_str_eq(s21_strcpy(b_str1, str2_1), strcpy(b_str2, str2_1));
// } END_TEST

// START_TEST(strcpy_test_2)
// {
//     char b_str1[] = "", b_str2[] = "";
//     strcpy(b_str1, str_);
//     strcpy(b_str2, str_);
//     ck_assert_str_eq(s21_strcpy(b_str1, str2_1), strcpy(b_str2, str2_1));
// } END_TEST

// START_TEST(strcpy_test_3)
// {
//     char b_str1[] = "", b_str2[] = "";
//     strcpy(b_str1, str1_1);
//     strcpy(b_str2, str1_1);
//     ck_assert_str_eq(s21_strcpy(b_str1, str_), strcpy(b_str2, str_));
// } END_TEST

// /* ------------ strncpy ------------ 12 -- */
// START_TEST(strncpy_test_1)
// {
//     char b_str1[] = "", b_str2[] = "";
//     strcpy(b_str1, str1_1);
//     strcpy(b_str2, str1_1);
//     ck_assert_str_eq(s21_strncpy(b_str1, str2_1, s21_n), strncpy(b_str2, str2_1, n));
// } END_TEST

// START_TEST(strncpy_test_2)
// {
//     char b_str1[] = "", b_str2[] = "";
//     strcpy(b_str1, str_);
//     strcpy(b_str2, str_);
//     ck_assert_str_eq(s21_strncpy(b_str1, str2_1, s21_n), strncpy(b_str2, str2_1, n));
// } END_TEST

// START_TEST(strncpy_test_3)
// {
//     char b_str1[] = "", b_str2[] = "";
//     strcpy(b_str1, str1_1);
//     strcpy(b_str2, str1_1);
//     ck_assert_str_eq(s21_strncpy(b_str1, str_, s21_n), strncpy(b_str2, str_, n));
// } END_TEST

// /* ------------ strсspn ------------ 13 -- */
// START_TEST(strсspn_test_1)
// {
//     ck_assert(s21_strсspn(str1_1, str1_2) & strсspn(str1_1, str1_2));
// } END_TEST

// START_TEST(strсspn_test_2)
// {
//     ck_assert(s21_strсspn(str, str_) & strсspn(str, str_));
// } END_TEST

// START_TEST(strсspn_test_3)
// {
//     ck_assert(s21_strсspn(str_, str) & strсspn(str_, str));
// } END_TEST

// START_TEST(strсspn_test_4)
// {
//     ck_assert(s21_strсspn(str, str) & strсspn(str, str));
// } END_TEST

// START_TEST(strсspn_test_5)
// {
//     ck_assert(s21_strсspn(str_, str_) & strсspn(str_, str_));
// } END_TEST

// START_TEST(strсspn_test_6)
// {
//     ck_assert(s21_strсspn(str2_1, str2_2) & strсspn(str2_1, str2_2));
// } END_TEST

// START_TEST(strсspn_test_7)
// {
//     ck_assert(s21_strсspn(str2_1, str_) & strсspn(str2_1, str_));
// } END_TEST

// /* ------------ strerror ------------ 14 -- */
// START_TEST(strerror_test_1)
// {
//     ck_assert_str_eq(s21_strerror(99), strerror(99));
// } END_TEST

// START_TEST(strerror_test_2)
// {
//     ck_assert_str_eq(s21_strerror(5), strerror(5));
// } END_TEST

// START_TEST(strerror_test_3)
// {
//     ck_assert_str_eq(s21_strerror(88), strerror(88));
// } END_TEST

// START_TEST(strerror_test_4)
// {
//     ck_assert_str_eq(s21_strerror(56), strerror(56));
// } END_TEST

// /* ------------ strlen ------------ 15 -- */
// START_TEST(strlen_test_1)
// {
//     ck_assert(s21_strlen(str1_1) & strlen(str1_1));
// } END_TEST

// START_TEST(strlen_test_2)
// {
//     ck_assert(s21_strlen(str) & strlen(str));
// } END_TEST

// START_TEST(strlen_test_3)
// {
//     ck_assert(s21_strlen(str_) & strlen(str_));
// } END_TEST

// /* ------------ strpbrk ------------ 16 -- */
// START_TEST(strpbrk_test_1)
// {
//     ck_assert_str_eq(s21_strpbrk(str1_1, str1_2), strpbrk(str1_1, str1_2));
// } END_TEST

// START_TEST(strpbrk_test_2)
// {
//     ck_assert_str_eq(s21_strpbrk(str2_1, str2_2), strpbrk(str2_1, str2_2));
// } END_TEST

// START_TEST(strpbrk_test_3)
// {
//     ck_assert_str_eq(s21_strpbrk(str, str), strpbrk(str, str));
// } END_TEST

// START_TEST(strpbrk_test_4)
// {
//     ck_assert_str_eq(s21_strpbrk(str, str_), strpbrk(str, str_));
// } END_TEST

// START_TEST(strpbrk_test_5)
// {
//     ck_assert_str_eq(s21_strpbrk(str_, str), strpbrk(str_, str));
// } END_TEST

// /* ------------ strrchr ------------ 17 -- */
// START_TEST(strrchr_test_1)
// {
//     ck_assert_str_eq(s21_strrchr(str, (int) s1), strrchr(str, (int) s1));
// } END_TEST

// START_TEST(strrchr_test_2)
// {
//     ck_assert_str_eq(s21_strrchr(str, (int) s3), strrchr(str, (int) s3));
// } END_TEST

// START_TEST(strrchr_test_3)
// {
//     ck_assert_str_eq(s21_strrchr(str, (int) s4), strrchr(str, (int) s4));
// } END_TEST

// /* ------------ strspn ------------ 18 -- */
// START_TEST(strspn_test_1)
// {
//     ck_assert(s21_strspn(str1_1, str1_2) & strspn(str1_1, str1_2));
// } END_TEST

// START_TEST(strspn_test_2)
// {
//     ck_assert(s21_strspn(str, str_) & strspn(str, str_));
// } END_TEST

// START_TEST(strspn_test_3)
// {
//     ck_assert(s21_strspn(str_, str) & strspn(str_, str));
// } END_TEST

// START_TEST(strspn_test_4)
// {
//     ck_assert(s21_strspn(str, str) & strspn(str, str));
// } END_TEST

// START_TEST(strspn_test_5)
// {
//     ck_assert(s21_strspn(str_, str_) & strspn(str_, str_));
// } END_TEST

// START_TEST(strspn_test_6)
// {
//     ck_assert(s21_strspn(str2_1, str2_2) & strspn(str2_1, str2_2));
// } END_TEST


// #endif /* S21_STRING_UNIT */

