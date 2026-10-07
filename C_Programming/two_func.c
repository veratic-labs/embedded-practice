#include <stdio.h>

void age(void);

int main(void)
{
    printf("I will introduce my age:\n");
    age();

    return 0;
}

void age(void)
{
    int age;
    age = 20;

    printf("My age is %d\n", age);
}