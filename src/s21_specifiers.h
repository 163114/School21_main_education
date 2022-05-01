#ifndef SPECIFIERS_H
#define SPECIFIERS_H

// Define the char array of specifiers to use in spritf and sscanf
char specifiers[15] = {'c', 'd', 'i', 'e', 'E', 'f', 'g', 'G', 'o', 's',
'u', 'x', 'X', 'p', 'n'};

// Define enum of specifiers for easy to read and use code
enum datatype{
    // Writes a single character
    CHARACTER_C = 0, // %c
    
    // Converts a signed integer into decimal representation [-]dddd
    SIGNED_DECIMAL_INTEGER_D = 1, // %d
    SIGNED_INTEGER_I = 3, // %i
    
    // Converts floating-point number to the decimal exponent notation
    // For the e conversion style [-]d.ddde±dd is used
    DECIMAL_FLOATING_POINT_E = 4, // %e
    DECIMAL_FLOATING_POINT_E_CAPITAL = 5, // %E
    
    // Converts floating-point number to the decimal notation in the style [-]ddd.ddd
    DECIMAL_FLOATING_POINT_F = 6, // %f
    
    // Converts floating-point number to decimal or decimal exponent notation depending on the value and the precision
    // For the g conversion style conversion with style e or f will be performed
    DECIMAL_FLOATING_POINT_G = 7, // %g
    // For the G conversion style conversion with style E or F will be performed
    DECIMAL_FLOATING_POINT_G_CAPTIAL = 8, // %G
    
    // Converts an unsigned integer into octal representation oooo
    UNSINGNED_OCTAL_O = 9, // %o
    
    // Writes a character string
    STRING_S = 10, // %s
    
    // Converts an unsigned integer into decimal representation dddd
    UNSIGNED_DECIMAL_INTEGER_U = 11, // %u
    
    // Converts an unsigned integer into hexadecimal representation hhhh
    // For the x conversion letters abcdef are used
    UNSIGNED_HEXADECIMAL_INTEGER_X = 12, // %x
    
    // For the X conversion letters ABCDEF are used
    UNSIGNED_HEXADECIMAL_INTEGER_X_CAPITAL = 13, // %X
    
    // Writes an implementation defined character sequence defining a pointer
    POINTER_ADDRESS_P = 14, // %p
    
    // Returns the number of characters written so far by this call to the function
    NUMBER_OF_CHARACTERS_N = 15 // %n
};

#endif