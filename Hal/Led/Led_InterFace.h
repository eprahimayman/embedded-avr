/*
 * Led_InterFace.h
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_
#include"../../Mcal/Dio/Dio_Private.h"
#include"../../Mcal/Dio/Dio_InterFace.h"
#include"../../Common/StdTypes.h"
#include <stdint.h>
#include "Led_Private.h"
void Led_Init(uint8_t LedGroup, uint8_t LedPin);
void Led_On(uint8_t LedGroup, uint8_t LedPin,uint8_t ConnectionType);
void Led_Off(uint8_t LedGroup, uint8_t LedPin,uint8_t ConnectionType);
void Led_Toggle(uint8_t LedGroup, uint8_t LedPin);
#endif /* HAL_LED_LED_INTERFACE_H_ */
