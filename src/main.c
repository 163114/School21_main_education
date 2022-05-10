#include <string.h>
#include <stdio.h>

int main(){
    char s1[] = "hi my frends", s2[] = "hi frends";
    char *s = strcat(s1, s2);
    printf("%s", s);
    return 0;
}
