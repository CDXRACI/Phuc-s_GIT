/***********************************************************************************
 * @author  : Cd.x
 * @version : 0.1
 * @date    : 24/10/2022
 * 
 * #################################################################################
 * 
 * @file    : ST3-INTERRUPT.h
 * @brief   : declaration for ST3-INTERRUPT.c 
 * 
 **/




#ifndef __ST3_INTERRUPT_H
#define __ST3_INTERRUPT_H

#include "stm32f4xx_hal.h"
#ifdef __cplusplus
extern "C"{
#endif

typedef enum __LOGICSTATES{

                            LOGIC_LOW  = 0,
                            LOGIC_HIGH = 1,
                            LOGIC_UK   = 2,

}LOGIC_STATE;


typedef enum STATE_OF_RCC_CONFIG_SW
{

                            RCC_CONFIG_SW_OFF       = 0,
                            RCC_CONFIG_SW_ON        = 1,
                            RCC_CONFIG_PWR_OFF      = 2,
                            RCC_CONFIG_PWR_ON       = 3,
                            RCC_UNKNOW_LOGIC        = 4

}__STATE_OF_RCC_CONFIG_SW;

extern  __STATE_OF_RCC_CONFIG_SW STATE_OF_RCC_CONFIG;

#define RCC_REGISTER_AHB1ENR_RE         (*((uint32_t *)0x40023830)) 
#define RCC_REGISTER_APB1ENR_RE         (*((uint32_t *)0x40023840)) 
#define RCC_REGISTER_APB2ENR_RE         (*((uint32_t *)0x40023844)) 

void RCC_CONFIG_SW(uint8_t  PWR_ON_OFF,uint8_t SW_RCC, char *GPIOX );
void INTERRUPT_SW_CONFIG(void);

void __INTERRUPT_LINEX(void);

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

void SETTING_ON_GPIO_PIN_PA(void);

void GPIO_PIN_SET_LOGIC_PA5(void);

void GPIO_PIN_LOW_LOGIC_PA5(void);

void GPIO_PIN_INPUT_PC0(void);
void GPIO_CONFIG_PA5_PA6(void);
typedef struct GPIO_CONFIG
{

volatile uint8_t GPIO_MODE_RE;             //0x00
volatile uint32_t GPIO_TYPER_RE;            //0x04
volatile uint32_t GPIO_OSPEEDR_RE;          //0x08
volatile uint32_t GPIO_PULLR_RE;            //0X0C
volatile uint32_t GPIO_IDR_RE;              //0X10
volatile uint32_t GPIO_ODR_RE;              //0x14
volatile uint32_t GPIO_BITSET_BITRESET;     //0x18
volatile uint32_t GPIO_LOCK_RE;             //0x1C
volatile uint32_t GPIO_ALTF_LOW_RE;         //0x20
volatile uint32_t GPIO_ALTF_HIGH_RE;        //0x24


}__GPIO_CONFIG;


#ifdef STM32F411RE
#define GPIOA_RE                ((__GPIO_CONFIG *)0x40020000)
#define GPIOB_RE                ((__GPIO_CONFIG *)0x40020400)
#define GPIOC_RE                ((__GPIO_CONFIG *)0x40020800) 
#define GPIOD_RE                ((__GPIO_CONFIG *)0x40020C00)
#endif




#ifdef __cplusplus
}
#endif
#endif