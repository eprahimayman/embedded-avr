/*
 * TrafficLightApp_Program.c
 *
 *  Created on: Sep 2, 2026
 *      Author: eprah
 */
#include"../../Mcal/Dio/Dio_InterFace.h"
#include"../../Mcal/Dio/Dio_Private.h"
#include"../../Hal/Button/Button_InterFace.h"
#include"../../Hal/Button/Button_Private.h"
#include"../../Hal/Led/Led_Private.h"
#include"../../Hal/Led/Led_InterFace.h"
#include"../../Hal/SevenSeg/SevenSeg_Private.h"
#include"../../Hal/SevenSeg/SevenSeg_InterFace.h"
#include"TrafficLightApp_Private.h"
#include"TrafficLightApp_InterFace.h"
#include"TrafficLightApp_ConFig.h"
#include"../../Hal/SevenSeg/SevenSeg_InterFace.h"
#include"../../Hal/SevenSeg/SevenSeg_Private.h"
#include <stdint.h>
#include <util/delay.h>

void TrafficLightApp_Init(){
Button_Init( ButtonGroup, Button,InternalPullUp);
Led_Init(LedGroup, LedGreen);//green
Led_Init(LedGroup, LedYello);//yello
Led_Init(LedGroup, LedRed);//red
SEVEN_SEGMENT_Init(SevenSeg_Units);
SEVEN_SEGMENT_Init(SevenSeg_Tens);
}
void DivideNumber(uint8_t Number,uint8_t * Number_Units,uint8_t * Number_Tens){
	*(Number_Units)=Number%10;
	*(Number_Tens)=Number/10;
}
void TrafficLightApp_Run(){

	uint8_t x=0;
	uint8_t y=0;
	uint8_t * Number_Units=&x;
	uint8_t * Number_Tens=&y;
	Led_On(LedGroup,LedGreen,Source);
	Led_Off(LedGroup,LedYello,Source);
	Led_Off(LedGroup,LedRed,Source);
	uint8_t flag=0;
	for(int i=99;i>0;i--){
		DivideNumber(i,Number_Units,Number_Tens);
		SEVEN_SEGMENT_DisplayNumber(x,SevenSeg_Units);
		SEVEN_SEGMENT_DisplayNumber(y,SevenSeg_Tens);
		if(BUTTON_GetState(ButtonGroup,Button,InternalPullUp)==ButtonPressed){
			_delay_ms(5);
			if(BUTTON_GetState(ButtonGroup,Button,InternalPullUp)==ButtonPressed){
				flag=1;
				break;
			}
		}
		_delay_ms(1000);
		if(flag==1)break;
		if(i==0)break;
	}

	Led_Off(LedGroup,LedGreen,Source);
	Led_On(LedGroup,LedYello,Source);
	Led_Off(LedGroup,LedRed,Source);
	for(int i=10;i>0;i--){
		DivideNumber(i,Number_Units,Number_Tens);
		SEVEN_SEGMENT_DisplayNumber(x,SevenSeg_Units);
		SEVEN_SEGMENT_DisplayNumber(y,SevenSeg_Tens);
		_delay_ms(1000);
		if(i==0)break;
	}

	Led_Off(LedGroup,LedGreen,Source);
	Led_Off(LedGroup,LedYello,Source);
	Led_On(LedGroup,LedRed,Source);
	for(int i=30;i>0;i--){
		DivideNumber(i,Number_Units,Number_Tens);
		SEVEN_SEGMENT_DisplayNumber(x,SevenSeg_Units);
		SEVEN_SEGMENT_DisplayNumber(y,SevenSeg_Tens);
		_delay_ms(1000);
		if(i==0)break;
	}
}
