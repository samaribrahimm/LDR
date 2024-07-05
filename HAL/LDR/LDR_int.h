/*
 * LDR_int.h
 *
 *  Created on: Jul 4, 2024
 *      Author: user
 */

#ifndef HAL_LDR_LDR_INT_H_
#define HAL_LDR_LDR_INT_H_

#include"../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"
#include "LDR_Config.h"
// Function prototypes

ES_t LDR_enuInit(LDR_t* Copy_PstrLDRconfig);

//void LDR_SychGetResistanceValue(u16*Copy_u16value);

//void LDR_SychVoltageValue(u16 *Copy_u16value);
//ES_t LDR_enuGetValue(u8 Copy_u8_LDR_ID, u16 *Copy_u8Value)
ES_t LDR_enuGetValue(u8 Copy_u8_LDR_ID, u8 *Copy_u8Value);
#endif /* HAL_LDR_LDR_INT_H_ */
