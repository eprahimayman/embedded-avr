/*
 * Lcd_InterFace.h
 *
 *  Created on: Sep 8, 2026
 *      Author: eprah
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_
#include"../../Mcal/Dio/Dio_InterFace.h"
#include"../../Mcal/Dio/Dio_Private.h"
#include"Lcd_Private.h"
#include"Lcd_Config.h"
#include <stdint.h>
#include"../../Mcal/Dio/Dio_InterFace.h"
#include"../../Mcal/Dio/Dio_Private.h"
void Lcd_Init();
void Lcd_SendInstruction(uint8_t instruction);
void Lcd_WriteCharacter(uint8_t Character);
void Lcd_WriteString(uint8_t * string);
void Lcd_Moveto(uint8_t LineNo,uint8_t DigitNo);
void Lcd_specialCharacter(uint8_t *string,uint8_t location);
#endif /* HAL_LCD_LCD_INTERFACE_H_ */
