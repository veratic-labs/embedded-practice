#ifndef SOUND_H
#define SOUND_H

sbit BEEP = P2^5;
volatile unsigned char tone_tick = 0;
volatile unsigned int note_tick = 0;
unsigned char period_tick;
unsigned char note = 0;

unsigned char note_period[] =
{
    19,    // DO
    17,    // RE
    15,    // MI
    14,    // FA
    13,    // SOL
    11,    // LA
    10     // SI
};

void timer0_init(void);

#endif