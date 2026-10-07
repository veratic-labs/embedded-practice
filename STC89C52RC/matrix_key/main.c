#include <REG52.H>
#include "numbers.h"

int row = 1;
int col = 1;
int n;
int display[2] = {0, 0};
  
void scan_key(void);
void convert_number(void);
void timer0_init(void);
void display_numbers(void);

void main(void)
{
    timer0_init();
    
    while (1)
    {
        scan_key();
    }
}

void scan_key(void)
{
    char row_n;
    char col_n;
    int i, j;
    
    P1 = 0xF0;
    row_n = P1 & 0xF0;
    row_n = row_n >> 4;

    P1 = 0x0F; 
    col_n = P1 & 0x0F;

    for (i = 0; i < 4; i++)
    {
        if ((row_n & (1 << i)) == 0x00)
            row = 4 - i;
    }

    for (j = 0; j < 4; j++)
    {
        if ((col_n & (1 << j)) == 0x00)
            col = 4 - j;
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
    TL0 = 0x01;

    display_numbers();
}

void display_numbers(void)
{
    static int x = 0;
    
    n = 4 * (row - 1) + col;
    display[0] = n % 10;
    display[1] = n / 10;

    P0 = 0x00;
    P2 = select[x];
    P0 = num[display[x]];

    x++;

    if (x > 1)
        x = 0;
}