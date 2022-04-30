all: clean test

test: s21_string.o s21_string_unit.o
	gcc s21_string.o s21_string_unit.o -lcheck -lm -lpthread -lrt -o check_s21_string_tests

s21_string.o:
	gcc s21_string.h -o s21_string.o

s21_string_unit.o:
	gcc s21_string_unit.c -o s21_string_unit.o

clean: 
	rm -rf *.o