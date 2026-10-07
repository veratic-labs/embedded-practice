#include <reg52.h>
#include "sound.h"

void main(void)
{
    timer0_init();

    while (1)
    {
    }
}

void timer0_init(void)
{
    TMOD &= 0xF0;
    TMOD |= 0x01;

    TH0 = 0xFF;
    TL0 = 0x9C;

    ET0 = 1;
    EA = 1;
    TR0 = 1;
}

void timer0_isr(void) interrupt 1
{
    TH0 = 0xFF;
    TL0 = 0x9C;

    period_tick = note_period[note];
    
    if (tone_tick >= period_tick)
    {
        tone_tick = 0;
        BEEP = !BEEP;
    }

    if (note_tick >= 10000)
    {
        note_tick = 0;
        note++;

        if (note > 6)
        {
            note = 0;
        }
    }

    tone_tick++;
    note_tick++;

}