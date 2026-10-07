#ifndef BIKE_H
#define BIKE_H

//define modes
typedef enum
{
    ALL_OFF,
    ALL_ON,
    FLOW,
    FLICKER
} LedMode;

LedMode mode = ALL_OFF;

//key
sbit KEY = P3^1;

//control leds
void all_off(void);
void all_on(void);
void flow(void);
void flicker(void);

//timer function
void timer0_init(void);

#endif