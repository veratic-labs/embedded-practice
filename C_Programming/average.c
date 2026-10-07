#include <stdio.h>
#include <stdarg.h>

#define COUNT 5

double average(int count, ...);

int main(void)
{
    double a = average(COUNT, 1, 24, 45, 29, 6);

    printf("%f\n", a);

    return 0;
}

double average(int count, ...)
{
    va_list args;

    va_start(args, count);

    int total = 0;

    for (int i = 0; i < count; i++)
        total += va_arg(args, int);

    va_end(args);

    double result = (double)total/count;

    return result;
}