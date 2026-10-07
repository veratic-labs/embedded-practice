#include <REG52.H>

void send_dat(unsigned char dat);
void timer0_init(void);

const unsigned char display[8] = {
    0x81,
    0x42,
    0x24,
    0x18,
    0x18,
    0x24,
    0x42,
    0x81
};

sbit INPUT = P3^4;
sbit MOVE = P3^6;
sbit OUTPUT = P3^5;

void main(void)
{
    timer0_init();
    
    while (1)
    {
    }
}

void send_dat(unsigned char dat)
{
    unsigned char i;

    for (i = 0; i < 8; i++)
    {
        INPUT = dat >> 7;

        MOVE = 0;
        MOVE = 1;

        dat <<= 1;
    }

    OUTPUT = 0;
    OUTPUT = 1;
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
    static unsigned char i = 0;
    
    TH0 = 0xFC;
    TL0 = 0x18;

    P0 = 0xFF;
    
    send_dat(display[i]);
    P0 = ~(1 << i);

    i++;

    if (i > 7)
        i = 0;
}