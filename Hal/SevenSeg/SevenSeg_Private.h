/*
 * SevenSeg_Private.h
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */

#ifndef HAL_SEVENSEG_SEVENSEG_PRIVATE_H_
#define HAL_SEVENSEG_SEVENSEG_PRIVATE_H_

typedef enum
{
	SEVEN_SEGMENT_COMMON_CATHODE,
	SEVEN_SEGMENT_COMMON_ANODE
}SevenSegmentType_t;


static const unsigned char SevenSegment_Patterns[10] =
{
			0xC0, /* 0 */
		    0xF9, /* 1 */
		    0xA4, /* 2 */
		    0xB0, /* 3 */
		    0x99, /* 4 */
		    0x92, /* 5 */
		    0x82, /* 6 */
		    0xF8, /* 7 */
		    0x80, /* 8 */
		    0x90  /* 9 */
};

#endif /* HAL_SEVENSEG_SEVENSEG_PRIVATE_H_ */
