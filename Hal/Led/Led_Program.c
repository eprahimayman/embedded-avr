/*
 * Led_Program.c
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */



#include "Led_InterFace.h"
#include "Led_Private.h"
#include"../../Mcal/Dio/Dio_Private.h"
#include"../../Mcal/Dio/Dio_InterFace.h"
#include <stdint.h>

void Led_Init(uint8_t LedGroup, uint8_t LedPin){
	 Dio_DirectionSetForPin(LedGroup,LedPin,Dio_OutPut);
}
void Led_On(uint8_t LedGroup, uint8_t LedPin,uint8_t ConnectionType){
	if(ConnectionType==Source){
		Dio_WriteValueForPin(LedGroup,LedPin,Dio_OutPutHigh);
	}else if(ConnectionType==Sink){
		Dio_WriteValueForPin(LedGroup,LedPin,Dio_OutPutLow);
	}
}
void Led_Off(uint8_t LedGroup, uint8_t LedPin,uint8_t ConnectionType){
	if(ConnectionType==Source){
		Dio_WriteValueForPin(LedGroup,LedPin,Dio_OutPutLow);
	}else if(ConnectionType==Sink){
		Dio_WriteValueForPin(LedGroup,LedPin,Dio_OutPutHigh);
	}
}

void Led_Toggle(uint8_t LedGroup, uint8_t LedPin){
	DIO_TogglePin(LedGroup,LedPin);
}


















