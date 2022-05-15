#include <stdio.h> 

int main() {
    int number = 0;
    char array[10] = {'1', '2', '3'};
    // for (int i = 0; i <= 2; ++i) {
    //     char one_char = array[i];
    // }
    while (array[number] != '\0') {
        printf("%c ", array[number]);
        ++number;
    }
    return 0;
}