#ifndef LCD_DRIVE_H
#define LCD_DRIVE_H

void lcd_write_command(unsigned char command);
void lcd_delay_ms(unsigned int ms);
void lcd_init(void);
void lcd_write_char(unsigned char character);

#endif