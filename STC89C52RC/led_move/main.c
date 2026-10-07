#include <REG52.H>
#include "led.h"

void delay_ms(unsigned int t);

void main(void)
{
    while (1)
    {
        LED1 = 0;
        delay_ms(1000);

        LED1 = 1;
        LED2 = 0;
        delay_ms(1000);

        LED2 = 1;
        LED3 = 0;
        delay_ms(1000);

        LED3 = 1;
        LED4 = 0;
        delay_ms(1000);

        LED4 = 1;
        LED5 = 0;
        delay_ms(1000);

        LED5 = 1;
        LED6 = 0;
        delay_ms(1000);

        LED6 = 1;
        LED7 = 0;
        delay_ms(1000);

        LED7 = 1;
        LED8 = 0;
        delay_ms(1000);

        LED8 = 1;
    }
}

void delay_ms(unsigned int t)
{
    unsigned int i, j;

    for (i = 0; i < t; i++)
        for (j = 0; j < 120; j++);
}