/*
 * LDR_Prog.c
 *
 *  Created on: Jul 4, 2024
 *      Author: samar ibrahim
 */

#include "../../LIB/stdTypes.h"
#include "../../LIB/Error_States.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/ADC/ADC_Config.h"
#include "../../MCAL/ADC/ADC_int.h"
#include "../../MCAL/GIE/GIE_int.h"
#include "LDR_config.h"
#include "LDR_priv.h"
#include "../LCD/LCD_int.h"
#include <util/delay.h>

#define REFERENCE_VOLTAGE   5000UL  // 5V reference voltage in millivolts
#define FIXED_RESISTOR      10000UL // Fixed resistor value in ohms

static volatile u16 ADCValue = 0;






ES_t LDR_enuInit(LDR_t* Copy_PstrLDRconfig) {
    ES_t Local_enuErrorState = ES_OK; // Assume success unless an error is found

    // Initialize the ADC
    ADC_enuInit() ;

    // Iterate through each LDR configuration
    for (u8 Local_u8Iterator = 0; Local_u8Iterator < LDRNUM; Local_u8Iterator++) {
        if (Copy_PstrLDRconfig[Local_u8Iterator].LDR_Channel != NOTCONNECTED) {
            // Set pin direction and select ADC channel
            DIO_enuSetPinDirection(DIO_u8PORTA, Copy_PstrLDRconfig[Local_u8Iterator].LDR_Channel, DIO_u8INPUT);
            ADC_enuSelectChannel(Copy_PstrLDRconfig[Local_u8Iterator].LDR_Channel);
        }
    }

    return Local_enuErrorState;
}

void LDR_GetValue(u8* Copy_u8Value) {
    u16 ADC_Value;

    // Start ADC conversion
    ADC_enuStartConversion();
    // Wait for ADC conversion to complete
    ADC_enuPollingSystem();
    // Read ADC value
    ADC_enuReadADCValue(&ADC_Value);

    // Convert ADC value (0-1023) to a range of 0-100
    *Copy_u8Value = (ADC_Value * 100) / 1023;
}


