#include <REG52.H>
#include "lcd_drive.h"

const char display[] = "Hello, world!";

void main(void)
{
    unsigned char i;
    
    lcd_init();

    for (i = 0; display[i] != '\0'; i++)
    {
        lcd_write_char(display[i]);
    }
    
    while (1)
    {
    }
}