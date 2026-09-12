/*
 * main.c
 *
 *  Created on: Sep 2, 2026
 *      Author: eprah
 */
#include"../Hal/Button/Button_InterFace.h"
#include"../Hal/Led/Led_InterFace.h"
#include"../Hal/Buzzer/Buzzer_InterFace.h"
#include"../Hal/SevenSeg/SevenSeg_InterFace.h"
#include"../Mcal/Dio/Dio_InterFace.h"
#include"../Mcal/Dio/Dio_Private.h"
#include"../Hal/Button/Button_Private.h"
#include"../Hal/Lcd/Lcd_InterFace.h"
#include"../Hal/Lcd/Lcd_Private.h"
#include"../Hal/KPD/KPD_InterFace.h"
#include"../Hal/KPD/KPD_Private.h"
#include"Lcdsinusoidalform/Lcd_sinusoidal form_Interface.h"
#include"TrafficLightApp/TrafficLightApp_InterFace.h"
#include"LedAnimation/LedAnimation_InterFace.h"
#include"LedAnimation/LedAnimation_Config.h"
#include <util/delay.h>

int main(void){
	uint8_t KeyValue = Kpd_BtnValueNotPressed;
	    KPD_Init();

	    while(1)
	    {
	        KPD_GetKPDValue(&KeyValue);

	        if(KeyValue != Kpd_BtnValueNotPressed)
	        {
	            LedAnimation(KeyValue);
	        }
	    }

}

