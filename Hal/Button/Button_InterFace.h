/*
 * Button_InterFace.h
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */

#ifndef HAL_BUTTON_BUTTON_INTERFACE_H_
#define HAL_BUTTON_BUTTON_INTERFACE_H_
#include <stdint.h>
#include"Button_Private.h"
void Button_Init(uint8_t GroupName, uint8_t PinNumber,uint8_t ButtonConnection);
State_t BUTTON_GetState(uint8_t GroupName,uint8_t PinNumber,uint8_t ButtonConnection);
#endif /* HAL_BUTTON_BUTTON_INTERFACE_H_ */
