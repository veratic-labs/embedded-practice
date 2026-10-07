#include <REG52.H>
#include "led.h"
#include "key.h"

void main(void)
{
    int status1 = 1;
    int status2 = 1;
    int status3 = 1;
    int status4 = 1;
    
    while (1)
    {
        //change status
        if (KEY1 == 0)
        {   
            status1 = !status1;
            while (KEY1 == 0);
        }

        if (KEY2 == 0)
        {
           status2 = !status2;
           while (KEY2 == 0);
        }

        if (KEY3 == 0)
        {
            status3 = !status3;
            while (KEY3 == 0);
        }

        if (KEY4 == 0)
        {
            status4 = !status4;
            while (KEY4 == 0);
        }

        //control on and off
        LED1 = status1;
        LED2 = status2; 
        LED3 = status3;
        LED4 = status4;
    }
}