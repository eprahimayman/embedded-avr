/*
 * BitMath.h
 *
 *  Created on: Aug 27, 2026
 *      Author: eprah
 */

#ifndef COMMON_BITMATH_H_
#define COMMON_BITMATH_H_
#define SetBit(Reg,BitNo)     Reg|=(1<<BitNo)
#define ClearBit(Reg,BitNo)   Reg&=~(1<<BitNo)
#define ToggleBit(Reg,BitNo)  Reg^=(1<<BitNo)
/* not shift the 1 becouse if do anding with 1 <<no will produce 1 in bit ex(2,3) will produce number >1
we will do rightshifting to number and with 00000001
*/
#define GetBit(reg,no) ((reg>>no)&1)


#endif /* COMMON_BITMATH_H_ */
