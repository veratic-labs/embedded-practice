#include <REG52.H>

sbit INPUT  = P3^4;   // 74HC595 SER
sbit MOVE   = P3^6;   // 74HC595 SRCLK
sbit OUTPUT = P3^5;   // 74HC595 RCLK

void save_dat(unsigned char dat);

void main(void)
{
    // 初始化
    INPUT  = 0;
    MOVE   = 0;
    OUTPUT = 0;

    // LED点阵的一侧全部设为低电平
    P0 = 0x00;

    // 595只让一个输出为高电平
    save_dat(0x01);

    while (1)
    {
    }
}

void save_dat(unsigned char dat)
{
    unsigned char i;

    for (i = 0; i < 8; i++)
    {
        // 发送最高位
        INPUT = dat & 0x80;

        // SRCLK产生上升沿，移入1 bit
        MOVE = 0;
        MOVE = 1;

        // 下一位移动到最高位
        dat <<= 1;
    }

    // RCLK产生上升沿，把8 bit送到输出端
    OUTPUT = 0;
    OUTPUT = 1;
}