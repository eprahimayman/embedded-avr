/*
 * Button_Private.h
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */

#ifndef HAL_BUTTON_BUTTON_PRIVATE_H_
#define HAL_BUTTON_BUTTON_PRIVATE_H_
typedef enum
{
	BUTTON_PRESSED,
	BUTTON_RELEASED
}Button_State_t;

typedef enum
{
	BUTTON_ACTIVE_LOW,
	BUTTON_ACTIVE_HIGH
}Button_Connection_t;


#endif /* HAL_BUTTON_BUTTON_PRIVATE_H_ */
