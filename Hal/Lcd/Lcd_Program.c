/*
 * Lcd_Program.c
 *
 *  Created on: Sep 8, 2026
 *      Author: eprah
 */
#include"Lcd_InterFace.h"
#include"Lcd_Config.h"
#include"../../Mcal/Dio/Dio_InterFace.h"
#include"../../Mcal/Dio/Dio_Private.h"
#include <util/delay.h>
#include <math.h>

void Lcd_Init(){
#if Lcd_Mode==Lcd_8BitMode
	Dio_DirectionSetForPin(Lcd_RSGroup,Lcd_RSPin,Dio_OutPut);
	Dio_DirectionSetForPin(Lcd_RWGroup,Lcd_RWPin,Dio_OutPut);
	Dio_DirectionSetForPin(Lcd_EnableGroup,Lcd_EnablePin,Dio_OutPut);
	Dio_DirectionSetForGroup(Lcd_DataGroup,Dio_OutPut);
	_delay_ms(35);
	Lcd_SendInstruction(Lcd_FunctionSet);
	_delay_ms(1);
	Lcd_SendInstruction(Lcd_DisplayOnOff);
	_delay_ms(1);
	Lcd_SendInstruction(Lcd_ClearDisplay);
	_delay_ms(1.9);
	Lcd_SendInstruction(Lcd_EntryModeSet);
#elif

#else
#error"Invalid Lcd Mode "
#endif

}
void Lcd_SendInstruction(uint8_t instruction){
#if Lcd_Mode==Lcd_8BitMode
	Dio_WriteValueForPin(Lcd_RSGroup,Lcd_RSPin,Dio_OutPutLow);
	Dio_WriteValueForPin(Lcd_RWGroup,Lcd_RWPin,Dio_OutPutLow);
	Dio_WriteValueForGroup(Lcd_DataGroup,instruction);
	Dio_WriteValueForPin(Lcd_EnableGroup,Lcd_EnablePin,Dio_OutPutHigh);
	_delay_ms(1);
	Dio_WriteValueForPin(Lcd_EnableGroup,Lcd_EnablePin,Dio_OutPutLow);
#elif

#else
#error"Invalid Lcd Mode "
#endif
}
void Lcd_WriteCharacter(uint8_t Character){
#if Lcd_Mode==Lcd_8BitMode
	Dio_WriteValueForPin(Lcd_RSGroup,Lcd_RSPin,Dio_OutPutHigh);
	Dio_WriteValueForPin(Lcd_RWGroup,Lcd_RWPin,Dio_OutPutLow);
	Dio_WriteValueForGroup(Lcd_DataGroup,Character);
	Dio_WriteValueForPin(Lcd_EnableGroup,Lcd_EnablePin,Dio_OutPutHigh);
	_delay_us(10);
	Dio_WriteValueForPin(Lcd_EnableGroup,Lcd_EnablePin,Dio_OutPutLow);
	_delay_ms(1);
#elif

#else
#error"Invalid Lcd Mode "
#endif
}
void Lcd_WriteString(uint8_t * string){
	uint8_t i=0;
	while(*(string+i)!='\0'){
		Lcd_WriteCharacter(string[i]);
		i++;
	}
}

void Lcd_Moveto(uint8_t LineNo,uint8_t DigitNo){
	uint8_t DDRAMAdress=0;
	switch(LineNo){
	case 0:DDRAMAdress=0x00+DigitNo   ;break;
	case 1:DDRAMAdress=0x40+DigitNo	  ;break;
	}
	Lcd_SendInstruction(Lcd_SetDDRAMCommand|DDRAMAdress);
}
void Lcd_specialCharacter(uint8_t *string,uint8_t location){
	uint8_t CGRAMAddres=8*location;
	Lcd_SendInstruction(Lcd_SetCGRAMCommand|CGRAMAddres);
	for(uint8_t index=0;index<8;index++){
		Lcd_WriteCharacter(string[index]);
	}
}
