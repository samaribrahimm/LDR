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



ES_t LDR_enuInit(LDR_t* Copy_PstrLDRconfig) {
    ES_t Local_enuErrorState = ES_OK; // Assume success unless an error is found

    // Iterate through each LDR configuration
    for (u8 Local_u8Iterator = 0; Local_u8Iterator < LDRNUM; Local_u8Iterator++) {
        if (Copy_PstrLDRconfig[Local_u8Iterator].LDR_Channel != NOTCONNECTED) {
            // Set pin direction and select ADC channel
            DIO_enuSetPinDirection(DIO_u8PORTA, Copy_PstrLDRconfig[Local_u8Iterator].LDR_Channel, DIO_u8INPUT);

        }
    }

    return Local_enuErrorState;
}

void LDR_GetValue(u8 Copy_u8ChannelID,u16* Copy_u8Value) {

ADC_enuEnable();
ADC_enuInit();
ADC_enuDisableTrigger();
ADC_enuSelectChannel(Copy_u8ChannelID);
ADC_enuStartConversion();
ADC_enuDisableInterrupt();
ADC_enuPollingSystem();
ADC_enuReadADCValue(Copy_u8Value);
ADC_enuDisable();


}


