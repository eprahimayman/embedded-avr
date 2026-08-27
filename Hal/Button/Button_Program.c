/*
 * Button_Program.c
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Private.h"

#include "Button_Interface.h"
#include "Button_Private.h"
#include "Button_Config.h"

void BUTTON_Init(uint8_t GroupName, uint8_t PinNumber)
{
	Dio_DirectionSetForPin(GroupName, PinNumber, Dio_InPut);

	if(BUTTON_CONNECTION == BUTTON_ACTIVE_LOW)
	{
		Dio_InterNalPullUpForPin(GroupName, PinNumber, DIO_High);
	}
}

uint8_t BUTTON_GetState(uint8_t GroupName, uint8_t PinNumber)
{
	uint8_t State = BUTTON_RELEASED;
	unsigned char PinValue = Dio_ReadValueForPin(GroupName, PinNumber);

	if(BUTTON_CONNECTION == BUTTON_ACTIVE_LOW)
	{
		if(PinValue == DIO_Low)
			State = BUTTON_PRESSED;
		else
			State = BUTTON_RELEASED;
	}
	else /* BUTTON_ACTIVE_HIGH */
	{
		if(PinValue == DIO_High)
			State = BUTTON_PRESSED;
		else
			State = BUTTON_RELEASED;
	}

	return State;
}

