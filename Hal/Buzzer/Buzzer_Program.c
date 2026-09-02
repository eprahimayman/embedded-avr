/*
 * Buzzer_Program.c
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */
/*
 * Buzzer_Program.c
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */
#include"Buzzer_Interface.h"
#include"Buzzer_Config.h"
#include"Buzzer_Private.h"
#include"../../Mcal/Dio/Dio_InterFace.h"

#include <stdint.h>


void Buzzer_Init(uint8_t  GroupName, uint8_t  PinNo){
	Dio_DirectionSetForPin(GroupName,PinNo,Dio_OutPut);
}
void Buzzer_On(uint8_t GroupName, uint8_t PinNo,uint8_t ConnectionType){
	if(ConnectionType==Source_Connections){
		Dio_WriteValueForPin(GroupName,PinNo,Dio_OutPutHigh);
	}else if(ConnectionType==Sink_Connections){
		Dio_WriteValueForPin(GroupName,PinNo,Dio_OutPutLow);
	}
}
void Buzzer_Off(uint8_t GroupName, uint8_t PinNo,uint8_t ConnectionType){
	if(ConnectionType==Source_Connections){
		Dio_WriteValueForPin(GroupName,PinNo,Dio_OutPutLow);
	}else if(ConnectionType==Sink_Connections){
		Dio_WriteValueForPin(GroupName,PinNo,Dio_OutPutHigh);
	}
}
void Buzzer_Toggle(uint8_t GroupName,uint8_t PinNo){
	DIO_TogglePin(GroupName,PinNo);
}
