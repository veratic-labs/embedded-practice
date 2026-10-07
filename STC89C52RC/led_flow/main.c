#include <REG52.H>

void delay_ms(unsigned int t);

void main(void)
{
    unsigned char led = 0xFE;

    while (1)
    {
        P2 = led;
        delay_ms(1000);

        led = (led << 1) | 0x01;

        if (led == 0xFF)
            led = 0xFE;
    }
}

void delay_ms(unsigned int t)
{
    unsigned int i, j;

    for (i = 0; i < t; i++)
        for (j = 0; j < 120; j++);
}