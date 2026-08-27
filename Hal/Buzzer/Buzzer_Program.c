/*
 * Buzzer_Program.c
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */
#include"Buzzer_InterFace.h"
#include"Buzzer_Config.h"
#include"Buzzer_Private.h"
#include <stdint.h>
void Buzzer_Init(uint8_t GroupName, uint8_t PinNo)
{
    Dio_DirectionSetForPin(GroupName, PinNo, Dio_OutPut);
    Buzzer_State(GroupName, PinNo, Buzzer_Off);
}

void Buzzer_State(uint8_t GroupName, uint8_t PinNo, uint8_t State)
{
    if(Connection_ == Source_Connection)
    {
        if(State == Buzzer_On)
        {
            Dio_WriteValueForPin(GroupName, PinNo, Dio_OutPutHigh);
        }
        else
        {
            Dio_WriteValueForPin(GroupName, PinNo, Dio_OutPutLow);
        }
    }
    else if(Connection_ == Sink_Connection)
    {
        if(State == Buzzer_On)
        {
            Dio_WriteValueForPin(GroupName, PinNo, Dio_OutPutLow);
        }
        else
        {
            Dio_WriteValueForPin(GroupName, PinNo, Dio_OutPutHigh);
        }
    }
}

void Buzzer_Toggle(uint8_t GroupName, uint8_t PinNo)
{
    DIO_TogglePin(GroupName, PinNo);
}
