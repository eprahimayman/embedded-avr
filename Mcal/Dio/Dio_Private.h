/*
 * Dio_Private.h
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_
// GroupName
typedef enum
{
Dio_GroupA,
Dio_GroupB,
Dio_GroupC,
Dio_GroupD
}Dio_GroupName_t;
//pinNumber
typedef enum
{
Dio_Pin0,
Dio_Pin1,
Dio_Pin2,
Dio_Pin3,
Dio_Pin4,
Dio_Pin5,
Dio_Pin6,
Dio_Pin7
}Dio_PinNumber_t;
//DirectionState
typedef enum
{
Dio_InPut,
Dio_OutPut
}Dio_Direction_t;
// oytputvalue
typedef enum
{
Dio_OutPutLow,
Dio_OutPutHigh
}Dio_OutPut_t;

typedef enum
{
	DIO_Low = 0,
	DIO_High
}DIO_Value_t;
#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
