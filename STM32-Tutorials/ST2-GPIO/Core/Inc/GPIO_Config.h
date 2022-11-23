/******************************************************
 *  @file : GPIO-Config.h
 *  @brief: This is declaration for GPIO-Config.c
 * ****************************************************
 *  
 *  @date :    23/10/2022
 *  @version : 0.1
 *  @author  : Cd.X
 **/


#ifndef __GPIO_CONFIG_H__
#define __GPIO_CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif    


#include "stm32f4xx_hal.h"

#ifndef STM32F411RE

#define STM32F411RE
#define RCC_REGISTER_RE         (*((uint32_t *)0x40023800))
#define RCC_CR_RE               (*((uint32_t *)0x40023800))
#define RCC_AHB1ENR_RE          (*((uint32_t *)0x40023830))
#define RCC_AHB2ENR_RE          (*((uint32_t *)0x40023834))
#define RCC_APB1ENR_RE          (*((uint32_t *)0x40023840))
#define RCC_APB2ENR_RE          (*((uint32_t *)0x40023844))



#define GPIOA_MODE              (*((uint32_t *)0x40020000))
#define GPIOA_TYPER             (*((uint32_t *)0x40020004))
#define GPIOA_OSPEEDR           (*((uint32_t *)0x40020008))
#define GPIO_BITSET_RESET       (*((uint32_t *)0x40020018))


#endif

typedef enum STATE_OF_LOGIC
{
LOW_lOGIC  = 0,
HIGH_LOGIC = 1,
UK_LOGIC   = 2


}__STATE_OF_LOGIC;

void SETTING_ON_GPIO_PIN_PA5(void);

void GPIO_PIN_SET_LOGIC_PA5(void);

void GPIO_PIN_LOW_LOGIC_PA5(void);

typedef struct GPIO_CONFIG
{





};

#ifdef __cplusplus
}
#endif


#endif
