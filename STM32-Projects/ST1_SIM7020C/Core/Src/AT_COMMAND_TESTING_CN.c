#include "AT_COMMAND_TESTING_CN.h"


void SEND_STRING(char *str)
{

while(*str != '\0' )
{
USART1->DR = (*str++);
	while (!(USART1->SR & (1<<6)));  
}
}

void USART1_CONFIG(void)
{

  RCC->AHB1ENR |= 0x0001;
  RCC->APB2ENR |= 0x0010;
  GPIOA->MODER |= (2<<18);
  GPIOA->MODER |= (2<<20);


  GPIOA->AFR[1] |= (7<<8);
  GPIOA->AFR[1] |= (7<<4);

  USART1->CR1  =   0x00;   // Clear ALL
  USART1->CR1 |=   (1<<13);   // UE = 1... Enable USART

  USART1->CR1 &=  ~(1<<12); // M= 0 -> LENGTH = 8BITS. CONSISTS 1 BIT START 8 BIT DATA AND 1 BIT STOP
  USART1->CR2 &=  ~(3<<12); //STOP = 00 -> STOP BITS = 1
  USART1->CR3 &=  ~(1<<7); // DMA TRANSMIT DISABLE
  USART1->BRR |=  0x364;


  USART1->CR1 |= (1<<2); // RE=1.. Enable the Receiver
  USART1->CR1 |= (1<<3);  // TE=1.. Enable Transmitter


}
void AT_SEND_COMMAND(void)
{
  MODULE_SIM7020C_TESTING __MODULE_SIM7020C_TESTING_FW;




  __MODULE_SIM7020C_TESTING_FW.AT        = "AT\r\n";
  __MODULE_SIM7020C_TESTING_FW.ATI       = "ATI\r\n";


 SEND_STRING(__MODULE_SIM7020C_TESTING_FW.AT);
 HAL_Delay(1000);
//  SEND_STRING(__MODULE_SIM7020C_TESTING_FW.ATI);
//  HAL_Delay(1000);



};

