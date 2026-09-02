/*
 * SevenSeg_InterFace.h
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */

#ifndef HAL_SEVENSEG_SEVENSEG_INTERFACE_H_
#define HAL_SEVENSEG_SEVENSEG_INTERFACE_H_
#include"stdint.h"
#include"../../Mcal/Dio/Dio_InterFace.h"
void SEVEN_SEGMENT_Init(uint8_t GroupName);
void SEVEN_SEGMENT_DisplayNumber(unsigned char Number,uint8_t GroupName);

#endif /* HAL_SEVENSEG_SEVENSEG_INTERFACE_H_ */
