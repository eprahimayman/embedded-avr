/*
 * Dio_InterFace.h
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_
#include"../../Common/BitMath.h"
#include"../../Common/Definiation.h"
#include"Dio_Config.h"
#include"Dio_Private.h"
#include"Dio_Config.h"
// direction (input/output)
void Dio_DirectionSetForPin(unsigned char GroupName,unsigned char PinNo,unsigned char DirectionState);
void Dio_DirectionSetForGroup(unsigned char GroupName,unsigned char DirectionState);
//output Value for pin (input/output)
void Dio_WriteValueForPin(unsigned char GroupName,unsigned char PinNo,unsigned char OutPutValue);
void Dio_WriteValueForGroup(unsigned char GroupName,unsigned char OutPutValue);
// input for pin (high/low)
unsigned char Dio_ReadValueForPin(unsigned char GroupName,unsigned char PinNo);
unsigned char Dio_ReadValueForGroup(unsigned char GroupName);
// internal pullup enable/disable
void Dio_InterNalPullUpForPin(unsigned char GroupName,unsigned char PinNo,unsigned char InterNalPullUpState);
void Dio_InterNalPullUpForGroup(unsigned char GroupName,unsigned char InterNalPullUpState);
// toggel pin
void DIO_TogglePin(unsigned char GroupName,unsigned char PinNo);
void DIO_ToggleGroub(unsigned char GroupName);
#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
