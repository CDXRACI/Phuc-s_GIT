#include "GPIO_Config.h"

void SETTING_ON_GPIO_PIN_PA5(void)
{

RCC_AHB1ENR_RE |= (1<<0);
RCC_APB1ENR_RE |= (1<<28);
RCC_APB2ENR_RE |= (1<<14);

};

void GPIO_PIN_SET_LOGIC_PA5(void)
{


GPIOA_MODE         |= ((0<<11) | (1<<10));
GPIOA_TYPER        &= ~(1<<5);
GPIOA_OSPEEDR      |= ((1<<11)  |(1<<10));
HAL_Delay(1000);
GPIO_BITSET_RESET  |= (1<<5);

};


void GPIO_PIN_LOW_LOGIC_PA5(void)
{


GPIOA_MODE         |= ((0<<11) | (1<<10));
GPIOA_TYPER        &= ~(1<<5);
GPIOA_OSPEEDR      |= ((1<<11)  |(1<<10));
HAL_Delay(1000);
GPIO_BITSET_RESET  |= (1<<21);

};

