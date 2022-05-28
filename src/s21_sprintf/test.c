#include "s21_sprintf.h"

#include <stdio.h>

int main() {
    const char *format = "signed first number = %+d, signed first char = %+c,\n"
                        "left-justify second number = %-5d, left-justify second char = %-c,\n"
                        "right-justify third number = %5d, right-justify third char = % c\n"
                        "blank number = %     d, blank char = %     c\n"
                        "blank number + override = %     +d, blank char + override = %     +c\n";
    const int number = 42;
    const char character = 'd';
    char s21_buffer[500];
    sprintf(s21_buffer, format, number, character, number, character, number, character, number, character, number, character);
    puts(s21_buffer);
    
    
//     char buffer[500];
//     int number = 42;
//     sprintf(buffer, "%300d", number);
//     puts(buffer);
//     return 0;
}
