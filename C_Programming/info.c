#include <stdio.h>

void printb(unsigned char n);

int main(void)
{
    unsigned char status = 0b00101101;

    if (status & (1<<1))
        printf("wifi is on");
    else
        printf("wifi is off");

    status = status | (1 << 3);
    
    status = status & ~ (1 << 2);

    status = status ^ (1 << 4);

    printb(status);
}

void printb(unsigned char n)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (n & (1 << i)) >> i);
    }
}