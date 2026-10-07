#include <REG52.H>
#include <intrins.h>
#include "lcd_drive.h"

sbit RW = P2^5;
sbit RS = P2^6;
sbit EN = P2^7;

void lcd_write_command(unsigned char command)
{
    RS = 0;
    RW = 0;

    P0 = command;

    EN = 1;
    _nop_();
    _nop_();
    EN = 0;

    if (command == 0x01 || command == 0x02)
        lcd_delay_ms(2);
    else
        lcd_delay_ms(1);
}

void lcd_delay_ms(unsigned int ms)
{
    unsigned int i, j;

    for (i = 0; i < ms; i++)
        for (j = 0; j < 120; j++);
}

void lcd_init(void)
{
    lcd_delay_ms(20);

    lcd_write_command(0x38);
    lcd_write_command(0x0C);
    lcd_write_command(0x06);
    lcd_write_command(0x01);
}

void lcd_write_char(unsigned char character)
{
    RS = 1;
    RW = 0;

    P0 = character;

    EN = 1;
    _nop_();
    _nop_();
    EN = 0;

    lcd_delay_ms(50);
}