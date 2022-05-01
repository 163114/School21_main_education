#ifndef SPECIFIERS_H
#define SPECIFIERS_H

// Define the char array of specifiers to use in spritf and sscanf
char specifiers[15] = {'c', 'd', 'i', 'e', 'E', 'f', 'g', 'G', 'o', 's',
'u', 'x', 'X', 'p', 'n'};

// Define enum of specifiers for easy to read and use code
enum datatype{
    CHARACTER_C = 0, // %c
    SIGNED_DECIMAL_INTEGER_D = 1, // %d
    SIGNED_INTEGER_I = 3, // %i
    DECIMAL_FLOATING_POINT_E = 4, // %e
    DECIMAL_FLOATING_POINT_E_CAPITAL = 5, // %E
    DECIMAL_FLOATING_POINT_F = 6, // %f
    DECIMAL_FLOATING_POINT_G = 7, // %g
    DECIMAL_FLOATING_POINT_G_CAPTIAL = 8, // %G
    USINGNED_OCTAL_O = 9, // %o
    STRING_S = 10, // %s
    UNSIGNED_DECIMAL_INTEGER_U = 11, // %u
    UNSIGNED_HEXADECIMAL_INTEGER_X = 12, // %x
    UNSIGNED_HEXADECIMAL_INTEGER_X_CAPITAL = 13, // %X
    POINTER_ADDRESS_P = 14, // %p
    NUMBER_OF_CHARACTERS_N = 15 // %n
};

#endif