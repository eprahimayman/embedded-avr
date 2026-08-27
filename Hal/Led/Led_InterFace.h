/*
 * Led_InterFace.h
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_
#include"../../Mcal/Dio/Dio_Private.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include"../../Common/StdTypes.h"
#include <stdint.h>
void Led_Init(uint8_t GroupName,uint8_t PinNo);
void Led_State(uint8_t GroupName,uint8_t PinNo,uint8_t State);
void Led_Toggle(uint8_t GroupName,uint8_t PinNo);
#endif /* HAL_LED_LED_INTERFACE_H_ */
