#include <REG52.H>
#include "numbers.h"

void main(void)
{
    timer0_init();

    while (1)
    {
        detect_key1();
        detect_key2();
    }
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

void timer0_isr(void) interrupt 1
{
    TH0 = 0xFC;
    TL0 = 0x18;

    tick++;

    display_number();

    if (tick >= 10 && running)
    {
        tick = 0;
        ms10++;

        if (ms10 >= 100)
        {
            sec++;
            ms10 = 0;
        }

        if (sec >= 60)
        {
            min++;
            sec = 0;
        }

        if (min >= 60)
        {
            hour++;
            min = 0;
        }

        //prevent large number
        if (hour >= 100)
        {
            hour = 0;
        }

        update_display();
    }

    if (reset)
    {
        tick = 0;
        ms10 = 0;
        sec = 0;
        min = 0;
        hour = 0;

        update_display();
        running = 0;
        reset = 0;
    }
}

void update_display(void)
{
    display[0] = ms10 % 10;
    display[1] = ms10 / 10;
    display[2] = sec % 10;
    display[3] = sec / 10;
    display[4] = min % 10;
    display[5] = min / 10;
    display[6] = hour % 10;
    display[7] = hour / 10;
}

void display_number(void)
{
    static unsigned char i = 0;

    P0 = 0x00;
    P2 = select[i];
    P0 = num[display[i]];

    if (i % 2 == 0)
    {
        P0 = P0 | 0x80;
    }

    i++;

    if (i >= 8)
        i = 0;
}

void detect_key1(void)
{
    if (KEY1 == 0)
    {
        running = !running;
        while (KEY1 == 0);
    }
}

void detect_key2(void)
{
    if (KEY2 == 0)
    {
        reset = 1;
        while (KEY2 == 0);
    }
}