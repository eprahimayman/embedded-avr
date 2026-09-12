/*
 * LedAnimation_Program.c
 *
 *  Created on: Sep 11, 2026
 *      Author: eprah
 */
#include"../../Hal/Led/Led_Private.h"
#include"../../Hal/Led/Led_InterFace.h"
#include"../../Mcal/Dio/Dio_InterFace.h"
#include"../../Mcal/Dio/Dio_Private.h"
#include"../../Hal/KPD/KPD_InterFace.h"
#include"../../Hal/KPD/KPD_Private.h"
#include"LedAnimation_Config.h"
#include <stdint.h>
#include <util/delay.h>

void LedAnimation(uint8_t KeyValue){

	switch(KeyValue){

		/* Toggle LED 1 only */
		case '1':
			Led_Toggle(LedGroup, LedOne);
			break;

		/* Shift right pattern through all 8 LEDs */
		case '2':
			Led_On(LedGroup, LedOne, Source);   _delay_ms(80); Led_Off(LedGroup, LedOne, Source);
			Led_On(LedGroup, LedTwo, Source);   _delay_ms(80); Led_Off(LedGroup, LedTwo, Source);
			Led_On(LedGroup, LedThree, Source); _delay_ms(80); Led_Off(LedGroup, LedThree, Source);
			Led_On(LedGroup, LedFour, Source);  _delay_ms(80); Led_Off(LedGroup, LedFour, Source);
			Led_On(LedGroup, LedFive, Source);  _delay_ms(80); Led_Off(LedGroup, LedFive, Source);
			Led_On(LedGroup, LedSix, Source);   _delay_ms(80); Led_Off(LedGroup, LedSix, Source);
			Led_On(LedGroup, LedSeven, Source); _delay_ms(80); Led_Off(LedGroup, LedSeven, Source);
			Led_On(LedGroup, LedEight, Source); _delay_ms(80); Led_Off(LedGroup, LedEight, Source);
			break;

		/* Shift left pattern through all 8 LEDs */
		case '3':
			Led_On(LedGroup, LedEight, Source); _delay_ms(80); Led_Off(LedGroup, LedEight, Source);
			Led_On(LedGroup, LedSeven, Source); _delay_ms(80); Led_Off(LedGroup, LedSeven, Source);
			Led_On(LedGroup, LedSix, Source);   _delay_ms(80); Led_Off(LedGroup, LedSix, Source);
			Led_On(LedGroup, LedFive, Source);  _delay_ms(80); Led_Off(LedGroup, LedFive, Source);
			Led_On(LedGroup, LedFour, Source);  _delay_ms(80); Led_Off(LedGroup, LedFour, Source);
			Led_On(LedGroup, LedThree, Source); _delay_ms(80); Led_Off(LedGroup, LedThree, Source);
			Led_On(LedGroup, LedTwo, Source);   _delay_ms(80); Led_Off(LedGroup, LedTwo, Source);
			Led_On(LedGroup, LedOne, Source);   _delay_ms(80); Led_Off(LedGroup, LedOne, Source);
			break;

		/* Ping Pong animation through all 8 LEDs */
		case '4':
			Led_On(LedGroup, LedOne, Source);   _delay_ms(60); Led_Off(LedGroup, LedOne, Source);
			Led_On(LedGroup, LedTwo, Source);   _delay_ms(60); Led_Off(LedGroup, LedTwo, Source);
			Led_On(LedGroup, LedThree, Source); _delay_ms(60); Led_Off(LedGroup, LedThree, Source);
			Led_On(LedGroup, LedFour, Source);  _delay_ms(60); Led_Off(LedGroup, LedFour, Source);
			Led_On(LedGroup, LedFive, Source);  _delay_ms(60); Led_Off(LedGroup, LedFive, Source);
			Led_On(LedGroup, LedSix, Source);   _delay_ms(60); Led_Off(LedGroup, LedSix, Source);
			Led_On(LedGroup, LedSeven, Source); _delay_ms(60); Led_Off(LedGroup, LedSeven, Source);
			Led_On(LedGroup, LedEight, Source); _delay_ms(60); Led_Off(LedGroup, LedEight, Source);
			Led_On(LedGroup, LedSeven, Source); _delay_ms(60); Led_Off(LedGroup, LedSeven, Source);
			Led_On(LedGroup, LedSix, Source);   _delay_ms(60); Led_Off(LedGroup, LedSix, Source);
			Led_On(LedGroup, LedFive, Source);  _delay_ms(60); Led_Off(LedGroup, LedFive, Source);
			Led_On(LedGroup, LedFour, Source);  _delay_ms(60); Led_Off(LedGroup, LedFour, Source);
			Led_On(LedGroup, LedThree, Source); _delay_ms(60); Led_Off(LedGroup, LedThree, Source);
			Led_On(LedGroup, LedTwo, Source);   _delay_ms(60); Led_Off(LedGroup, LedTwo, Source);
			Led_On(LedGroup, LedOne, Source);   _delay_ms(60); Led_Off(LedGroup, LedOne, Source);
			break;

		/* Flashing pattern with all 8 LEDs */
		case '5':
			Led_On(LedGroup, LedOne, Source);
			Led_On(LedGroup, LedTwo, Source);
			Led_On(LedGroup, LedThree, Source);
			Led_On(LedGroup, LedFour, Source);
			Led_On(LedGroup, LedFive, Source);
			Led_On(LedGroup, LedSix, Source);
			Led_On(LedGroup, LedSeven, Source);
			Led_On(LedGroup, LedEight, Source);
			_delay_ms(200);
			Led_Off(LedGroup, LedOne, Source);
			Led_Off(LedGroup, LedTwo, Source);
			Led_Off(LedGroup, LedThree, Source);
			Led_Off(LedGroup, LedFour, Source);
			Led_Off(LedGroup, LedFive, Source);
			Led_Off(LedGroup, LedSix, Source);
			Led_Off(LedGroup, LedSeven, Source);
			Led_Off(LedGroup, LedEight, Source);
			break;

		/* In to out animation across 8 LEDs */
		case '6':
			Led_On(LedGroup, LedFour, Source);  Led_On(LedGroup, LedFive, Source);  _delay_ms(100);
			Led_Off(LedGroup, LedFour, Source); Led_Off(LedGroup, LedFive, Source);
			Led_On(LedGroup, LedThree, Source); Led_On(LedGroup, LedSix, Source);   _delay_ms(100);
			Led_Off(LedGroup, LedThree, Source);Led_Off(LedGroup, LedSix, Source);
			Led_On(LedGroup, LedTwo, Source);   Led_On(LedGroup, LedSeven, Source); _delay_ms(100);
			Led_Off(LedGroup, LedTwo, Source);  Led_Off(LedGroup, LedSeven, Source);
			Led_On(LedGroup, LedOne, Source);   Led_On(LedGroup, LedEight, Source); _delay_ms(100);
			Led_Off(LedGroup, LedOne, Source);  Led_Off(LedGroup, LedEight, Source);
			break;

		/* Out to in animation across 8 LEDs */
		case '7':
			Led_On(LedGroup, LedOne, Source);   Led_On(LedGroup, LedEight, Source); _delay_ms(100);
			Led_Off(LedGroup, LedOne, Source);  Led_Off(LedGroup, LedEight, Source);
			Led_On(LedGroup, LedTwo, Source);   Led_On(LedGroup, LedSeven, Source); _delay_ms(100);
			Led_Off(LedGroup, LedTwo, Source);  Led_Off(LedGroup, LedSeven, Source);
			Led_On(LedGroup, LedThree, Source); Led_On(LedGroup, LedSix, Source);   _delay_ms(100);
			Led_Off(LedGroup, LedThree, Source);Led_Off(LedGroup, LedSix, Source);
			Led_On(LedGroup, LedFour, Source);  Led_On(LedGroup, LedFive, Source);  _delay_ms(100);
			Led_Off(LedGroup, LedFour, Source); Led_Off(LedGroup, LedFive, Source);
			break;

		/* Snake filling animation all 8 LEDs */
		case '8':
			Led_On(LedGroup, LedOne, Source);   _delay_ms(80);
			Led_On(LedGroup, LedTwo, Source);   _delay_ms(80);
			Led_On(LedGroup, LedThree, Source); _delay_ms(80);
			Led_On(LedGroup, LedFour, Source);  _delay_ms(80);
			Led_On(LedGroup, LedFive, Source);  _delay_ms(80);
			Led_On(LedGroup, LedSix, Source);   _delay_ms(80);
			Led_On(LedGroup, LedSeven, Source); _delay_ms(80);
			Led_On(LedGroup, LedEight, Source); _delay_ms(80);
			break;

		/* Turn off all LEDs */
		case '9':
			Led_Off(LedGroup, LedOne, Source);
			Led_Off(LedGroup, LedTwo, Source);
			Led_Off(LedGroup, LedThree, Source);
			Led_Off(LedGroup, LedFour, Source);
			Led_Off(LedGroup, LedFive, Source);
			Led_Off(LedGroup, LedSix, Source);
			Led_Off(LedGroup, LedSeven, Source);
			Led_Off(LedGroup, LedEight, Source);
			break;

		default:
			break;
	}
}

