/*
 * Lcd_Private.h
 *
 *  Created on: Sep 8, 2026
 *      Author: eprah
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

#define Lcd_4BitMode 1
#define Lcd_8BitMode 2

#define Lcd_ClearDisplay 0x01
#define Lcd_ReturnHome   0x02
#define Lcd_LeftNoShift  0x04 // cursor move left screen constant
#define Lcd_LeftShift    0x05 // cursor move left screen shifting
#define Lcd_RightNoShift 0x06
#define Lcd_RightShift   0x07

#define Lcd_DisplayOff     0x08
#define Lcd_DisplayOn      0x0C
#define Lcd_CursorOn       0x0E
#define Lcd_CursorBlinking 0x0F

#define Lcd_8bit2Line5X11  0x3C
#define Lcd_8bit2Line5X8   0x38
#define Lcd_8bit1Line5X11  0x34
#define Lcd_8bit1Line5X8   0x30

#define Lcd_4bit2Line5X11  0x2C
#define Lcd_4bit2Line5X8   0x28
#define Lcd_4bit1Line5X11  0x24
#define Lcd_4bit1Line5X8   0x20


#define Lcd_SetCGRAMCommand   0x40
#define Lcd_SetDDRAMCommand   0x80

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
