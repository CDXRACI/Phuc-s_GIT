#include "ST_CLOCKCONNFIG.h"

#ifndef HSE_VALUE 
#define HSE_VALUE (8000000)U
#endif

void SYS_CONFIG_CLOCK(void)
{
RCC->APB1ENR |= (1 << 28);
RCC->CR |= 1<<16;  

while (!(RCC->CR & (1<<17)));


RCC->CFGR &= ~(1<<4);
	

RCC->CFGR |= (4<<10);
	

RCC->CFGR &= ~(1<<13);
#define PLL_M 	4
#define PLL_N 	100
#define PLL_P 	2  

RCC->PLLCFGR = (PLL_M <<0) | (PLL_N << 6) | (PLL_P <<16) | (1<<22);
RCC->CR |= (1<<24);
while (!(RCC->CR & (1<<25)));
RCC->CFGR |= (2<<0);
while (!(RCC->CFGR & (2<<2)));
RCC->APB2ENR |= (1<<14);


}

void INIT_INTERRUPT(void)
{

RCC->APB2ENR |= (1<<14);  // Enable SYSCNFG
RCC->APB2ENR |= (1<<0);  // Enable AFIO CLOCK


};