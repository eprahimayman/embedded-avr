/*
 * Lcd_Config.h
 *
 *  Created on: Sep 8, 2026
 *      Author: eprah
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_
#include"../../Mcal/Dio/Dio_InterFace.h"
#include"../../Mcal/Dio/Dio_Private.h"
#include"Lcd_Private.h"
#define Lcd_Mode Lcd_8BitMode

#define Lcd_RSPin Dio_Pin0
#define Lcd_RSGroup Dio_GroupA

#define Lcd_RWPin Dio_Pin1
#define Lcd_RWGroup Dio_GroupA

#define Lcd_EnablePin Dio_Pin2
#define Lcd_EnableGroup Dio_GroupA

#if Lcd_Mode==Lcd_8BitMode
#define Lcd_DataGroup Dio_GroupC
#elif
#define Lcd_D4Pin Dio_Pin4
#define Lcd_DataGroup Dio_GroupC
#define Lcd_D5Pin Dio_Pin5
#define Lcd_DataGroup Dio_GroupC
#define Lcd_D6Pin Dio_Pin6
#define Lcd_DataGroup Dio_GroupC
#define Lcd_D7Pin Dio_Pin7
#define Lcd_DataGroup Dio_GroupC
#else
#error"Invalid Lcd Mode "
#endif

#define Lcd_DisplayOnOff Lcd_CursorBlinking
#define Lcd_FunctionSet  Lcd_8bit2Line5X11
#define Lcd_EntryModeSet Lcd_RightNoShift

#endif /* HAL_LCD_LCD_CONFIG_H_ */
