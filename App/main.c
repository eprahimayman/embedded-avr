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
#include"TrafficLightApp/TrafficLightApp_InterFace.h"
#include <util/delay.h>

int main(void){
	TrafficLightApp_Init();
	while(1){
		TrafficLightApp_Run();
	}
}

