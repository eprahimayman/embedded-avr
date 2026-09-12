/*
 * Lcd_sinusoidalform.c
 *
 *  Created on: Sep 10, 2026
 *      Author: eprah
 */
#include "../../Hal/Lcd/Lcd_InterFace.h"
#include "../../Hal/Lcd/Lcd_Private.h"
#include "../../Hal/Lcd/Lcd_Config.h"
#include <math.h>
#include <util/delay.h>

void App_Lcd_SinWave(uint8_t *string){
    Lcd_SendInstruction(Lcd_ClearDisplay);
    _delay_ms(2);
    for (uint8_t x = 0; string[x] != '\0'; x++)
    {
        uint8_t y = (x % 2 == 0) ? 1 : 0;
        Lcd_Moveto(y, x);
        Lcd_WriteCharacter(string[x]);
        _delay_ms(200);
    }
}
/*
void App_Lcd_SinWave(uint8_t *string)
{
    static float phase = 0.0;

    Lcd_SendInstruction(Lcd_ClearDisplay);
    _delay_ms(2);

    for (uint8_t x = 0; string[x] != '\0'; x++)
    {
        float angle = (x * 0.5) + phase;
        uint8_t y = (sin(angle) >= 0) ? 0 : 1;

        Lcd_Moveto(y, x);
        Lcd_WriteCharacter(string[x]);
    }

    phase += 0.3;
    if (phase >= 6.28)
    {
        phase = 0.0;
    }

    _delay_ms(200);
}
*/
