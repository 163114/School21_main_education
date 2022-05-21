// Testing file for small functions
#include <stdio.h>
#include <math.h>

int main() {
    // // -3402823466385288598117041834845169254400.0000000000000000 Float lowest
    // //340282346638528859811704183484516925440.000000 Float max
    // double lowest = -340282346638528859811704183484516925440.000000;
    // // float max = 340282346638528859811704183484516925440.000000;
    // char first_array[1024];
    // // char second_array[58];
    // sprintf(first_array, "%f", lowest);
    // // sprintf(second_array, "%f", max);
    // puts(first_array);
    // // puts(second_array);
    // return 0;
    double number = 12345.12345;
    double power_of_ten = pow(10, -5);
    double result = number / power_of_ten;
    printf("%f", result);
}
