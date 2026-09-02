/*
 * Button_Program.c
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */

#include"../../Mcal/Dio/Dio_InterFace.h"
#include"../../Mcal/Dio/Dio_Private.h"
#include"Button_Private.h"
#include"Button_InterFace.h"
#include"../../Common/BitMath.h"
#include"../../Mcal/atmega32Register.h"
#include <stdint.h>
void Button_Init(uint8_t GroupName, uint8_t PinNumber,uint8_t ButtonConnection){
	if(PinNumber<=Dio_Pin7){
		if(ButtonConnection==InternalPullUp)
			Dio_InterNalPullUpForPin( GroupName,PinNumber,DIO_High);
		else if(ButtonConnection==ExternalPullUp||ButtonConnection==PullDown)
			Dio_InterNalPullUpForPin( GroupName,PinNumber,DIO_Low);
	}
}
State_t BUTTON_GetState(uint8_t GroupName,uint8_t PinNumber,uint8_t ButtonConnection){
	uint8_t ButtonValue=0;
	State_t ButtonState=ButtonNotPressed;
	if(PinNumber<=Dio_Pin7){
		ButtonValue = Dio_ReadValueForPin(GroupName, PinNumber);
		if(ButtonConnection==InternalPullUp||ButtonConnection==ExternalPullUp){
			if(ButtonValue==0)ButtonState=ButtonPressed;
			else ButtonState=ButtonNotPressed;
		}else if(ButtonConnection==PullDown){
			if(ButtonValue==0)ButtonState=ButtonNotPressed;
			else ButtonState=ButtonPressed;
		}
	}
	return ButtonState;
}
