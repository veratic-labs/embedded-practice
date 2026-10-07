#include <REG52.H>
#include "button.h"
#include "led.h"

void main(void)
{
    while (1)
    {
        if (KEY1 == 0)
            LED1 = 0;
        else
            LED1 = 1;

        if (KEY2 == 0)
            LED2 = 0;
        else
            LED2 = 1;

        if (KEY3 == 0)
            LED3 = 0;
        else
            LED3 = 1;

        if (KEY4 == 0)
            LED4 = 0;
        else
            LED4 = 1;
    }
}