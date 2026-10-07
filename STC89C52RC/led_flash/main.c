#include <REG52.H>

sbit LED1 = P2^0;

void delay_ms(unsigned int t);

void main(void)
{
    while (1)
    {
        LED1 = 0;

        delay_ms(1000);

        LED1 = 1;

        delay_ms(1000);
    }
}

void delay_ms(unsigned int t)
{
    unsigned int i, j;

    for (i = 0; i < t; i++)
        for (j = 0; j < 120; j++);
}