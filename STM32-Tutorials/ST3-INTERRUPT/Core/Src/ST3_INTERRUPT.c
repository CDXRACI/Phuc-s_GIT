#include"ST3_INTERRUPT.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <string.h>


void RCC_CONFIG_SW( uint8_t  PWR_ON_OFF,uint8_t SYSCONFIG_RCC, char *GPIOX )
{

__STATE_OF_RCC_CONFIG_SW ST1 =      PWR_ON_OFF;
__STATE_OF_RCC_CONFIG_SW ST2 =      SYSCONFIG_RCC;
switch (ST1)
{
case RCC_CONFIG_PWR_OFF:
    printf("RCC_PWR_ON_IS_CLOSE");
    RCC_REGISTER_APB1ENR_RE &= ~(LOGIC_HIGH << 28);
    break;
case RCC_CONFIG_PWR_ON:
    printf("RCC_PWR_ON_IS_ENABLE");
    RCC_REGISTER_APB1ENR_RE |=  (LOGIC_HIGH << 28);
default:
    break;
}

switch (ST2)
{
case RCC_CONFIG_SW_OFF:
     printf("\r\nRCC_SYSCONFIG_IS_DISABLE");
     RCC_REGISTER_APB2ENR_RE  &= ~(LOGIC_HIGH << 14);
    break;
case RCC_CONFIG_SW_ON:
     printf("\r\nRCC_SYSCONFIG_IS_ENABLE");
     RCC_REGISTER_APB2ENR_RE  |=  (LOGIC_HIGH << 14);
default:
    break;
}

if(strstr(GPIOX,"GPIOA"))
{
RCC_REGISTER_AHB1ENR_RE |= (LOGIC_HIGH << 0);


}
else if(strstr(GPIOX,"GPIOB"))
{
RCC_REGISTER_AHB1ENR_RE |= (LOGIC_HIGH << 1);

}
else if(strstr(GPIOX,"GPIOC"))
{

RCC_REGISTER_AHB1ENR_RE |= (LOGIC_HIGH << 2);
}
else if(strstr(GPIOX,"GPIOD"))
{

RCC_REGISTER_AHB1ENR_RE |= (LOGIC_HIGH << 3);
}
else if(strstr(GPIOX,"GPIOE"))
{

RCC_REGISTER_AHB1ENR_RE |= (LOGIC_HIGH << 4);    
}
else if(strstr(GPIOX,"GPIOH"))
{

RCC_REGISTER_AHB1ENR_RE |= (LOGIC_HIGH << 7);
}
};

void INTERRUPT_SW_CONFIG(void)
{


  GPIOA->MODER &= ~(3<<2);
  GPIOA->OTYPER &= ~(1<<1);
  GPIOA->PUPDR |= (1<<1);
  GPIOA->OSPEEDR |= (1<<2);

  SYSCFG->EXTICR[1] &= ~(15<<4); //PA1 IS ENABLED.
  EXTI->RTSR &= ~(1<<1); // INTERRUPT RISING ENABLE 
  EXTI->FTSR |= (1<<1);
  EXTI->IMR |= (1<<1); // INTERRUPT MASKED ENABLE
 
  NVIC->IP[7] |= (1<<4); // RANGER IS 0 -> 255.
  NVIC->ISER[0] |= (1<<7); // ENABLE LINE 6
}
void SETTING_ON_GPIO_PIN_PA(void)
{

RCC_AHB1ENR_RE |= (1<<0);
RCC_AHB1ENR_RE |= (1<<2);
RCC_APB1ENR_RE |= (1<<28);
RCC_APB2ENR_RE |= (1<<14);

// __HAL_RCC_GPIOC_CLK_ENABLE();
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



GPIOC_RE->GPIO_MODE_RE     |=((0<<1) | (1<<0));
GPIOC_RE->GPIO_TYPER_RE    &= ~(1<<1);
GPIOC_RE->GPIO_OSPEEDR_RE  |=((1<<1)  |(1<<0));
//GPIOC_RE->GPIO_PULLR_RE    |= ((0<<27) | ( 1<<26));
STATE_LOGIC = HIGH_LOGIC;

case HIGH_LOGIC:
GPIOA_RE->GPIO_BITSET_BITRESET |= (1<<5);
HAL_Delay(1000);
GPIOA_RE->GPIO_BITSET_BITRESET |= (1<<21);
HAL_Delay(1000);
GPIOC_RE->GPIO_BITSET_BITRESET |= (1<<0);
HAL_Delay(1000);
GPIOC_RE->GPIO_BITSET_BITRESET |= (1<<16);
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


void GPIO_CONFIG_PA5_PA6(void)
{


GPIOA_MODE         |= ((0<<11) | (1<<10));
GPIOA_TYPER        &= ~(1<<5);
GPIOA_OSPEEDR      |= ((1<<11)  |(1<<10));

GPIOA_MODE         |= ((0<<13) | (1<<12));
GPIOA_TYPER        &= ~(1<<6);
GPIOA_OSPEEDR      |= ((1<<13)  |(1<<12));
};


void GPIO_PIN_INPUT_PC0(void)
{

GPIOC_RE->GPIO_MODE_RE     |=((0<<1) | (0<<0));
// GPIOA_RE->GPIO_TYPER_RE    &= ~(1<<5);
// GPIOA_RE->GPIO_OSPEEDR_RE  |=((1<<11)  |(1<<10));
GPIOC_RE->GPIO_PULLR_RE    |= ((0<<1) | ( 1<<0));

if((GPIOC_RE->GPIO_IDR_RE&(1<<0)) == 1)
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

