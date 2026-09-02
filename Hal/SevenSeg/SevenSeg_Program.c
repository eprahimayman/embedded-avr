/*
 * SevenSeg_Program.c
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */


#include "SevenSeg_Interface.h"
#include "SevenSeg_Private.h"
#include "SevenSeg_Config.h"
#include"../../Mcal/Dio/Dio_InterFace.h"
void SEVEN_SEGMENT_Init(uint8_t GroupName)
{
	Dio_DirectionSetForGroup(GroupName, Dio_OutPut);
}
void SEVEN_SEGMENT_DisplayNumber(unsigned char Number,uint8_t GroupName)
{
	unsigned char Pattern;

	if(Number <= 9)
	{
		Pattern = SevenSegment_Patterns[Number];

		if(SEVEN_SEGMENT_TYPE == SEVEN_SEGMENT_COMMON_CATHODE)
		{
			Pattern = ~Pattern;
		}

		Dio_WriteValueForGroup(GroupName, Pattern);
	}
}
