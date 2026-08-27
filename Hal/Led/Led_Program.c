/*
 * Led_Program.c
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */

#include"Led_InterFace.h"
#include"Led_Config.h"
#include"Led_Private.h"
#include <stdint.h>

void Led_Init(uint8_t GroupName,uint8_t PinNo){
	Dio_DirectionSetForPin(GroupName,PinNo,Dio_OutPut);
	Led_State(GroupName,PinNo,Led_Off);
}
void Led_State(uint8_t GroupName,uint8_t PinNo,uint8_t State){
	if(Connection==Source_Connection){
		if(State==Led_On){
			Dio_WriteValueForPin(GroupName,PinNo,Dio_OutPutHigh);
		}else Dio_WriteValueForPin(GroupName, PinNo, Dio_OutPutLow);
	}else if(Connection==Sink_Connection){
		if(State==Led_On){
			Dio_WriteValueForPin(GroupName,PinNo,Dio_OutPutLow);
		}else Dio_WriteValueForPin(GroupName, PinNo, Dio_OutPutHigh);
	}
}

void Led_Toggle(uint8_t GroupName,uint8_t PinNo){
	DIO_TogglePin(GroupName,PinNo);
}
