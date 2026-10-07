#include <stdio.h>

void ask(void)
{
    static int times;
    times += 1;

    printf("This is your %dth question", times);
}