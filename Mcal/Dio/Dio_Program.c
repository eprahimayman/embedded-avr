/*
 * Dio_Program.c

 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */
#include "../../Common/BitMath.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Config.h"
#include"atmega32Register"
#include"Dio_InterFace.h"

void Dio_DirectionSetForPin(unsigned char GroupName,unsigned char PinNo,unsigned char DirectionState){
	if(PinNo<=Dio_Pin7){
		if(DirectionState==Dio_InPut){
			switch(GroupName){
			case Dio_GroupA:ClearBit(DDRA_Reg,PinNo);break;
			case Dio_GroupB:ClearBit(DDRB_Reg,PinNo);break;
			case Dio_GroupC:ClearBit(DDRC_Reg,PinNo);break;
			case Dio_GroupD:ClearBit(DDRD_Reg,PinNo);break;
			default:break;
			}
		}
		else if(DirectionState==Dio_OutPut){
			switch(GroupName){
			case Dio_GroupA:SetBit(DDRA_Reg,PinNo);break;
			case Dio_GroupB:SetBit(DDRB_Reg,PinNo);break;
			case Dio_GroupC:SetBit(DDRC_Reg,PinNo);break;
			case Dio_GroupD:SetBit(DDRD_Reg,PinNo);break;
			default:break;
			}
		}
	}
}

void Dio_DirectionSetForGroup(unsigned char GroupName,unsigned char DirectionState){
	if(DirectionState==Dio_InPut){
		switch(GroupName){
		case Dio_GroupA:DDRA_Reg=0x00;break;
		case Dio_GroupB:DDRB_Reg=0x00;break;
		case Dio_GroupC:DDRC_Reg=0x00;break;
		case Dio_GroupD:DDRD_Reg=0x00;break;
		default:break;
		}
	}
	else if(DirectionState==Dio_OutPut){
		switch(GroupName){
		case Dio_GroupA:DDRA_Reg=0xFF;break;
		case Dio_GroupB:DDRB_Reg=0xFF;break;
		case Dio_GroupC:DDRC_Reg=0xFF;break;
		case Dio_GroupD:DDRD_Reg=0xFF;break;
		default:break;
		}
	}
}
void Dio_WriteValueForPin(unsigned char GroupName,unsigned char PinNo,unsigned char OutPutValue){
	if(PinNo<=Dio_Pin7){
		if(OutPutValue==Dio_OutPutLow){
			switch(GroupName){
			case Dio_GroupA:ClearBit(PORTA_Reg,PinNo);break;
			case Dio_GroupB:ClearBit(PORTB_Reg,PinNo);break;
			case Dio_GroupC:ClearBit(PORTC_Reg,PinNo);break;
			case Dio_GroupD:ClearBit(PORTD_Reg,PinNo);break;
			default:break;
			}
		}else if(OutPutValue==Dio_OutPutHigh){
			switch(GroupName){
			case Dio_GroupA:SetBit(PORTA_Reg,PinNo);break;
			case Dio_GroupB:SetBit(PORTB_Reg,PinNo);break;
			case Dio_GroupC:SetBit(PORTC_Reg,PinNo);break;
			case Dio_GroupD:SetBit(PORTD_Reg,PinNo);break;
			default:break;
			}

		}
	}
}
void Dio_WriteValueForGroup(unsigned char GroupName,unsigned char OutPutValue){
	if(OutPutValue==Dio_OutPutLow){
		switch(GroupName){
		case Dio_GroupA:PORTA_Reg=0x00;break;
		case Dio_GroupB:PORTB_Reg=0x00;break;
		case Dio_GroupC:PORTC_Reg=0x00;break;
		case Dio_GroupD:PORTD_Reg=0x00;break;
		default:break;
		}
	}else if(OutPutValue==Dio_OutPutHigh){
		switch(GroupName){
		case Dio_GroupA:PORTA_Reg=0xFF;break;
		case Dio_GroupB:PORTB_Reg=0xFF;break;
		case Dio_GroupC:PORTC_Reg=0xFF;break;
		case Dio_GroupD:PORTD_Reg=0xFF;break;
		default:break;
		}
	}
}
unsigned char Dio_ReadValueForPin(unsigned char GroupName,unsigned char PinNo){
	unsigned char PinValue=0x00;
	if(PinNo<=Dio_Pin7){
			switch(GroupName){
			case Dio_GroupA:PinValue=GetBit(PINA_Reg,PinNo);break;
			case Dio_GroupB:PinValue=GetBit(PINB_Reg,PinNo);break;
			case Dio_GroupC:PinValue=GetBit(PINC_Reg,PinNo);break;
			case Dio_GroupD:PinValue=GetBit(PIND_Reg,PinNo);break;
			default:break;
		}
	}
	return PinValue;
}

unsigned char Dio_ReadValueForGroup(unsigned char GroupName){
	unsigned char PinValue=0x00;
			switch(GroupName){
			case Dio_GroupA:PinValue=PINA_Reg;break;
			case Dio_GroupB:PinValue=PINB_Reg;break;
			case Dio_GroupC:PinValue=PINC_Reg;break;
			case Dio_GroupD:PinValue=PIND_Reg;break;
		    default:break;
}
return PinValue;
}

void Dio_InterNalPullUpForPin(unsigned char GroupName,unsigned char PinNo,unsigned char InterNalPullUpState){
	if(PinNo<=Dio_Pin7){
		if(InterNalPullUpState==DIO_High){
		switch(GroupName){
		case Dio_GroupA:SetBit(PORTA_Reg,PinNo);break;
		case Dio_GroupB:SetBit(PORTB_Reg,PinNo);break;
		case Dio_GroupC:SetBit(PORTC_Reg,PinNo);break;
		case Dio_GroupD:SetBit(PORTD_Reg,PinNo);break;
	    default:break;
}
		}else if(InterNalPullUpState==DIO_Low){
		case Dio_GroupA:ClearBit(PORTA_Reg,PinNo);break;
		case Dio_GroupB:ClearBit(PORTB_Reg,PinNo);break;
		case Dio_GroupC:ClearBit(PORTC_Reg,PinNo);break;
		case Dio_GroupD:ClearBit(PORTD_Reg,PinNo);break;
		default:break;
		}
	}
}
void Dio_InterNalPullUpForGroup(unsigned char GroupName,unsigned char InterNalPullUpState){

	if(InterNalPullUpState==DIO_Low){
		switch(GroupName){
		case Dio_GroupA:PORTA_Reg=0x00;break;
		case Dio_GroupB:PORTB_Reg=0x00;break;
		case Dio_GroupC:PORTC_Reg=0x00;break;
		case Dio_GroupD:PORTD_Reg=0x00;break;
		default:break;
		}
	}else if(InterNalPullUpState==DIO_High){
		switch(GroupName){
		case Dio_GroupA:PORTA_Reg=0xFF;break;
		case Dio_GroupB:PORTB_Reg=0xFF;break;
		case Dio_GroupC:PORTC_Reg=0xFF;break;
		case Dio_GroupD:PORTD_Reg=0xFF;break;
		default:break;
		}
	}
}
void DIO_TogglePin(unsigned char GroupName,unsigned char PinNo){
	if(PinNo<=Dio_Pin7)
	{
		switch(GroupName)
		{
		case Dio_GroupA: ToggleBit(PORTA_Reg,PinNo); break;
		case Dio_GroupB: ToggleBit(PORTB_Reg,PinNo); break;
		case Dio_GroupC: ToggleBit(PORTC_Reg,PinNo); break;
		case Dio_GroupD: ToggleBit(PORTD_Reg,PinNo); break;
		default: break;
		}
	}
}
void DIO_ToggleGroub(unsigned char GroupName){
	switch(GroupName)
	{
	case Dio_GroupA: PORTA_Reg=~PORTA_Reg; break;
	case Dio_GroupB: PORTB_Reg=~PORTB_Reg; break;
	case Dio_GroupC: PORTC_Reg=~PORTC_Reg; break;
	case Dio_GroupD: PORTD_Reg=~PORTD_Reg; break;
	default: break;
	}
}
