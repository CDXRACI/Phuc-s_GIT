/*****************************************************************************
 * 
 * @author  : CD.P
 * @version : 0.1
 * @date    : 28/11/2022
 * 
 * ---------------------------------------------------------------------------
 * 
 * @file    : AT_COMMAND_TESTING_COMMAND_CN.h
 * @brief   : This file is declaration for AT_COMMAND_TESTING_COMMAND_CN.c
 * @bug     : No BUG
 * 
 ****************************************************************************/

#ifndef __AT_COMMAND_TESTING_CN_H
#define __AT_COMMAND_TESTING_CN_H

#include "stm32f4xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef enum __STATE_OF_LOGIC
{
            LOGIC_LOW           = 0,
            LOGIC_HIGH          = 1,
            LOGIC_UNK           = 2


}STATE_OF_LOGIC;



typedef struct __MODULE_SIM7020C_TESTING
{

            char *AT;
            char *ATI;
            char *ATCGMI;


}MODULE_SIM7020C_TESTING;

extern MODULE_SIM7020C_TESTING __MODULE_SIM7020C_TESTING_FW;

void AT_SEND_COMMAND(void);

void USART1_CONFIG(void);

void SEND_STRING(char *str);


#ifdef __cplusplus
}
#endif
#endif

