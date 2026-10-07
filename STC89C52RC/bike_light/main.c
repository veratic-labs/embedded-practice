#include <REG52.H>
#include "bike.h"

unsigned int t;

void main(void)
{
    timer0_init();

    while (1)
    {
        if (KEY == 0)
        {
            //initialise
            P2 = 0x00;

            if (mode == FLICKER)
                mode = ALL_OFF;
            else
                mode += 1;

            while (KEY == 0);
        }

        //control led
        if (mode == ALL_OFF)
            all_off();

        else if (mode == ALL_ON)
            all_on();

        if (t > 100)
        {
            t = 0;
            
            if (mode == FLOW)
                flow();

            else if (mode == FLICKER)
                flicker();
        }
    }
}

void all_off(void)
{
    P2 = 0xFF;
}

void all_on(void)
{
    P2 = 0x00;
}

void flow(void)
{
    P2 = P2 << 1;

    if (P2 == 0x00)
        P2 = 0x01;
}

void flicker(void)
{
    P2 = ~P2;
}

void timer0_isr(void) interrupt 1
{
    TH0 = 0xFC;
    TL0 = 0x18;
    t++;
}

void timer0_init(void)
{
    TMOD &= 0xF0;
    TMOD |= 0x01;

    TH0 = 0xFC;
    TL0 = 0x18;

    ET0 = 1;
    EA = 1;

    TR0 = 1;
}