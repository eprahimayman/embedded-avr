/*
 * Buzzer_InterFace.h
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */

#ifndef HAL_BUZZER_BUZZER_INTERFACE_H_
#define HAL_BUZZER_BUZZER_INTERFACE_H_

#include"../../Mcal/Dio/Dio_Private.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include"../../Common/StdTypes.h"
#include <stdint.h>
/*
void Buzzer_Init(uint8_t  GroupName, uint8_t  PinNo);
void  Buzzer_State(uint8_t GroupName, uint8_t PinNo, uint8_t State);
void Buzzer_Toggle(uint8_t GroupName,uint8_t PinNo);
*/
void Buzzer_Init(uint8_t  GroupName, uint8_t  PinNo);
void Buzzer_On(uint8_t GroupName, uint8_t PinNo,uint8_t ConnectionType);
void Buzzer_Off(uint8_t GroupName, uint8_t PinNo,uint8_t ConnectionType);
void Buzzer_Toggle(uint8_t GroupName,uint8_t PinNo);
#endif /* HAL_BUZZER_BUZZER_INTERFACE_H_ */
