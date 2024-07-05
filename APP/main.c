/*
 * main.c
 *
 *  Created on: Jul 4, 2024
 *      Author: samar
 */
#include "../HAL/LDR/LDR_int.h"
#include "../HAL/LDR/LDR_Config.h"  // This header file should include the LDR configuration structure
#include "../MCAL/DIO/DIO_int.h"   // Include Digital I/O functions
#include <util/delay.h>
extern  LDR_t LDR_Config[LDRNUM];

int main(void) {
    // Initialize the LCD
    LCD_enuInit();
    LCD_enuWriteString("LDR_Value = ",0,0);
    LDR_enuInit( &LDR_Config);

    // Main loop
    while (1) {
        u8 ldrValue =0,x;;
        LDR_GetValue(&ldrValue);// Get the value of the LDR at index 0

           // Display LDR value as an integer
LCD_vidClearScreen();
LCD_enuWriteString("LDR_Value = ",0,0);
LCD_enuDisplayNum((s32)ldrValue);

_delay_ms(1000);


    }

    return 0;
}
