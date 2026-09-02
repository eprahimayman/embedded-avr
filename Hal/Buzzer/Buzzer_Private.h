/*
 * Buzzer_Private.h
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */
#include"Buzzer_Config.h"
#ifndef HAL_BUZZER_BUZZER_PRIVATE_H_
#define HAL_BUZZER_BUZZER_PRIVATE_H_
/*
typedef enum{
	Buzzer_On,
	Buzzer_Off
} StateOfBuzzer;

typedef enum
{
	Sink_Connection,
	Source_Connection
}Buzzer_Connection_t;
*/

typedef enum {
    Sink_Connections = 0,
    Source_Connections
} Buzzer_Connection_t;
#endif /* HAL_BUZZER_BUZZER_PRIVATE_H_ */
