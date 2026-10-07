#include <stdio.h>

#define MODECODE 0b11100000
#define SPEEDCODE 0b00011100
#define FLAGCODE 0b00000011

void printb(unsigned char n);

int main(void)
{
    unsigned char data = 0b10111010;

    unsigned char mode = (data & MODECODE) >> 5;

    unsigned char speed = (data & SPEEDCODE) >> 2;

    unsigned char flag = (data & FLAGCODE);

    printf("mode:");
    printb(mode);

    printf("speed:");
    printb(speed);

    printf("flag:");
    printb(flag);
}

void printb(unsigned char n)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (n & (1 << i)) >> i);
    }

    printf("\n");
}