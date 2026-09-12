/*
 * KPD_Program.c
 *
 *  Created on: Sep 10, 2026
 *      Author: eprah
 */
#include <util/delay.h>
#include "KPD_Interface.h"
#include "KPD_Private.h"
#include "../../Mcal/DIO/DIO_Interface.h"
#include "../../Mcal/DIO/DIO_Private.h"
#include "../../Mcal/DIO/DIO_Config.h"
#include "KPD_Config.h"
static uint8_t KPDValues[Kpd_RowNo][Kpd_ColNo]= Kpd_ValuesConfigured;
static uint8_t KPD_RGroups[Kpd_RowNo]= Kpd_RGroupConfigured;
static uint8_t KPD_RPins[Kpd_RowNo]= Kpd_RPinConfigured;
static uint8_t KPD_CGroups[Kpd_ColNo]= Kpd_CGroupConfigured;
static uint8_t KPD_CPins[Kpd_ColNo]= Kpd_CPinConfigured;
//void KPD_Init()
//{
//
//	for(uint8_t RIndex = 0 ;RIndex<Kpd_RowNo;RIndex++)
//	{
//		Dio_DirectionSetForPin(KPD_RGroups[RIndex],KPD_RPins[RIndex],Dio_InPut);
//		Dio_InterNalPullUpForPin(KPD_RGroups[RIndex],KPD_RPins[RIndex],DIO_High);
//	}
//	for(uint8_t CIndex = 0 ;CIndex<Kpd_ColNo;CIndex++)
//	{
//		Dio_WriteValueForPin(KPD_CGroups[CIndex], KPD_CPins[CIndex], Dio_OutPutHigh);
//	//	Dio_DirectionSetForPin(KPD_CGroups[CIndex],KPD_CPins[CIndex],Dio_OutPut);
//		Dio_WriteValueForPin(KPD_CGroups[CIndex],KPD_CGroups[CIndex],Dio_OutPutHigh);
//	}
//}
void KPD_Init(void)
{
    for(uint8_t RIndex = 0; RIndex < Kpd_RowNo; RIndex++)
    {
        Dio_DirectionSetForPin(KPD_RGroups[RIndex], KPD_RPins[RIndex], Dio_InPut);
        Dio_InterNalPullUpForPin(KPD_RGroups[RIndex], KPD_RPins[RIndex], DIO_High);
    }
    for(uint8_t CIndex = 0; CIndex < Kpd_ColNo; CIndex++)
    {
        Dio_DirectionSetForPin(KPD_CGroups[CIndex], KPD_CPins[CIndex], Dio_OutPut);
        Dio_WriteValueForPin(KPD_CGroups[CIndex], KPD_CPins[CIndex], Dio_OutPutHigh);
    }
}
void KPD_GetKPDValue(uint8_t *KPD_Value)
{

	*KPD_Value = Kpd_BtnValueNotPressed;
	uint8_t IsBtnPressed = Kpd_BtnStateNotPressed ;
	for (uint8_t C = 0 ; C<Kpd_ColNo;C++)
	{
		Dio_WriteValueForPin(KPD_CGroups[C],KPD_CPins[C],Dio_OutPutLow);
		for(uint8_t R=0;R<Kpd_RowNo;R++)
		{
			IsBtnPressed= Dio_ReadValueForPin(KPD_RGroups[R],KPD_RPins[R]);
			if(IsBtnPressed==Kpd_BtnStatePressed)
			{
				_delay_ms(100);
				IsBtnPressed= Dio_ReadValueForPin(KPD_RGroups[R],KPD_RPins[R]);
				if(IsBtnPressed==Kpd_BtnStatePressed)
				{
					*KPD_Value = KPDValues[R][C];
					Dio_WriteValueForPin(KPD_CGroups[C],KPD_CPins[C],Dio_OutPutHigh);
					return ;
				}

			}
		}
		Dio_WriteValueForPin(KPD_CGroups[C],KPD_CPins[C],Dio_OutPutHigh);
	}
}

