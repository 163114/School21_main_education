#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h> // !!!!!!!!!!!!!!!!!!!!!!!!!!

int choose_return_type(char *buffer, int index, const char *format, va_list argp)
{
    char *pt = strtok(buffer, " "), cl = 'q';
    for (int i = 1; i <= index; i++)
        if (pt != NULL)
            pt = strtok(NULL, " ");
        // else error  specifires < date
        else return 1; // error

    if (*format == 'h' || *format == 'l' || *format == 'L')
    {
        cl = *format;
        format++;
    }
    else if (*format == 'c')
        *va_arg(argp, char*) = *pt;
    else if (*format == 'd' || *format == 'i')
        printf("if"); // call преобразование в int, write in argp
    else if (*format == 'e')
        printf("if");
    else if (*format == 'E')
        printf("if");
    else if (*format == 'f') {
        *(va_arg(argp, long double*)) = atof(pt);
    } else if (*format == 'g')
        printf("if");
    else if (*format == 'G')
        printf("if");
    else if (*format == 'o')
        printf("if");
    else if (*format == 's')
        strcpy(va_arg(argp, char*), pt);
    else if (*format == 'u')
        *va_arg(argp, unsigned int*) = atoi(pt);
        //*va_arg(argp, unsigned int*) = atoi(pt);
    else if (*format == 'x')
        printf("if");
    else if (*format == 'X')
        printf("if");
    else if (*format == 'p')
        printf("if"); // *va_arg(argp, void**) = (void *) *pt;
    else if (*format == 'n')
        printf("if");
    else return 1;
    return 0;
}

int s21_sscanf(const char *str, const char *format, ...)
{
    va_list argp;
    va_start(argp, format);
    int number_of_specifires = 0;
    char *buffer = strcpy(buffer, str);
    while (*format != '\0')
    {
        if (*format == '%')
        {
            ++number_of_specifires;
            format++;
            choose_return_type(buffer, number_of_specifires, format, argp);
            ++format;
        }
    }
    va_end(argp);
}


int main()
{
    
    char a[] = "0x37 dcc -18.56 years old!", c;
    char b[80];
    void *p;
    int d = 56;
    float f;
    sscanf(a, "%p%f", &p, &d);
    //scanf("%s%d", b, &d);
    /*
    char a[] = "+-18 years old!";
    int d;
    //sscanf(a, "%s%d", b, &d);
    d = atoi(a);
    */
    char sp[] = "0x38";
    void *pss = (void*) sp;
    
    //pss = (void *) 0x38;
    // printf("%p %d\n%d", d, d, pss);
    return 0;
}
