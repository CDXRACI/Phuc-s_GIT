#include "GPIO_Config.h"

void SETTING_ON_GPIO_PIN_PA(void)
{

RCC_AHB1ENR_RE |= (1<<0);
RCC_AHB1ENR_RE |= (1<<2);
RCC_APB1ENR_RE |= (1<<28);
RCC_APB2ENR_RE |= (1<<14);

};

void GPIO_PIN_SET_LOGIC_PA5(void)
{

__STATE_OF_LOGIC STATE_LOGIC;
STATE_LOGIC = LOW_lOGIC;
// GPIOA_MODE         |= ((0<<11) | (1<<10));
// GPIOA_TYPER        &= ~(1<<5);
// GPIOA_OSPEEDR      |= ((1<<11)  |(1<<10));
// HAL_Delay(1000);
// GPIO_BITSET_RESET  |= (1<<5);

switch (STATE_LOGIC)
{
case LOW_lOGIC:

GPIOA_RE->GPIO_MODE_RE     |=((0<<11) | (1<<10));
GPIOA_RE->GPIO_TYPER_RE    &= ~(1<<5);
GPIOA_RE->GPIO_OSPEEDR_RE  |=((1<<11)  |(1<<10));
STATE_LOGIC = HIGH_LOGIC;

case HIGH_LOGIC:
GPIOA_RE->GPIO_BITSET_BITRESET |= (1<<5);
HAL_Delay(1000);
GPIOA_RE->GPIO_BITSET_BITRESET |= (1<<21);
HAL_Delay(1000);
STATE_LOGIC = UK_LOGIC;
break;

default:
    break;
}

};


void GPIO_PIN_LOW_LOGIC_PA5(void)
{


GPIOA_MODE         |= ((0<<11) | (1<<10));
GPIOA_TYPER        &= ~(1<<5);
GPIOA_OSPEEDR      |= ((1<<11)  |(1<<10));
HAL_Delay(1000);
GPIO_BITSET_RESET  |= (1<<21);

};

void GPIO_PIN_INPUT_PC13(void)
{

GPIOC_RE->GPIO_MODE_RE     |=((0<<27) | (0<<26));
// GPIOA_RE->GPIO_TYPER_RE    &= ~(1<<5);
// GPIOA_RE->GPIO_OSPEEDR_RE  |=((1<<11)  |(1<<10));
GPIOC_RE->GPIO_PULLR_RE    |= ((0<<27) | ( 1<<26));

if((GPIOC_RE->GPIO_IDR_RE&(1<<13)) == 0)
{

GPIOA_RE->GPIO_MODE_RE     |=((0<<11) | (1<<10));
GPIOA_RE->GPIO_TYPER_RE    &= ~(1<<5);
GPIOA_RE->GPIO_OSPEEDR_RE  |=((1<<11)  |(1<<10));
GPIOA_RE->GPIO_BITSET_BITRESET |= (1<<5);
HAL_Delay(1000);
GPIOA_RE->GPIO_BITSET_BITRESET |= (1<<21);
HAL_Delay(1000);


}




};