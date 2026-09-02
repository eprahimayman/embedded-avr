/*
 * Button_Private.h
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */

#ifndef HAL_BUTTON_BUTTON_PRIVATE_H_
#define HAL_BUTTON_BUTTON_PRIVATE_H_
typedef enum{
	InternalPullUp,
	ExternalPullUp,
	PullDown,
}Button_Connection_t;

typedef enum {
	ButtonPressed = 0,
	ButtonNotPressed
} State_t;

#endif /* HAL_BUTTON_BUTTON_PRIVATE_H_ */
