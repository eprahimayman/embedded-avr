/*
 * KPD_InterFace.h
 *
 *  Created on: Sep 10, 2026
 *      Author: eprah
 */

#ifndef HAL_KPD_KPD_INTERFACE_H_
#define HAL_KPD_KPD_INTERFACE_H_
#include <stdint.h>
#include "../../Mcal/DIO/DIO_Interface.h"
#include "KPD_Private.h"
#include "KPD_Config.h"


void KPD_Init();
void KPD_GetKPDValue(uint8_t *KPD_Value);


#endif /* HAL_KPD_KPD_INTERFACE_H_ */
