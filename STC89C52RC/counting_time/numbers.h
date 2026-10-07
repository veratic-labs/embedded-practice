#ifndef NUMBERS_H
#define NUMBERS_H

unsigned char code num[] = {
    0x3F,  // 0
    0x06,  // 1
    0x5B,  // 2
    0x4F,  // 3
    0x66,  // 4
    0x6D,  // 5
    0x7D,  // 6
    0x07,  // 7
    0x7F,  // 8
    0x6F   // 9
};

unsigned char code select[] = {
    0x00,  // 000 << 2
    0x04,  // 001 << 2
    0x08,  // 010 << 2
    0x0C,  // 011 << 2
    0x10,  // 100 << 2
    0x14,  // 101 << 2
    0x18,  // 110 << 2
    0x1C   // 111 << 2
};

unsigned int display[8];

volatile unsigned char tick = 0;
sbit KEY1 = P3^1;
sbit KEY2 = P3^0;

unsigned char running = 0;
unsigned char reset = 0;

unsigned int ms10 = 0;
unsigned int sec = 0;
unsigned int min = 0;
unsigned int hour = 0;

void timer0_init(void);
void update_display(void);
void display_number(void);
void detect_key1(void);
void detect_key2(void);

#endif