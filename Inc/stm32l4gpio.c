/*
 * stm32l4gpio.c
 *
 *  Created on: May 13, 2025
 *      Author: Arun
 */

#include "stm32l4gpio.h"
#include<stdio.h>
#include<stdint.h>


void GPIO_PERI_CLK(GPIO_Reg_Def *pGPIOx,uint8_t EN)
{
	if(EN==ENABLE)
	{
		if(pGPIOx==GPIOA)
		{
			GPIOA_CLK_EN();
		}
		else if(pGPIOx==GPIOB)
		{
			GPIOB_CLK_EN();
		}
		else if(pGPIOx==GPIOC)
		{
			GPIOC_CLK_EN();
		}
		else if(pGPIOx==GPIOD)
		{
			GPIOD_CLK_EN();
		}
	}
	else
	{
		  if(pGPIOx==GPIOA)
			{
				GPIOA_CLK_DI();
			}
			else if(pGPIOx==GPIOB)
			{
				GPIOB_CLK_DI();
			}
			else if(pGPIOx==GPIOC)
			{
				GPIOC_CLK_DI();
			}
			else if(pGPIOx==GPIOD)
			{
				GPIOD_CLK_DI();
			}
	}
}

uint8_t GPIO_READ_PIN(GPIO_Reg_Def *pGPIOx,uint16_t PINNUMBER)
{
	uint8_t value;
	value=(uint8_t)((pGPIOx->IDR)>>PINNUMBER)&(0x00000001);
	return value;
}
uint16_t GPIO_READ_PORT(GPIO_Reg_Def *pGPIOx)
{
	uint16_t value;
	value=(uint16_t)pGPIOx->IDR;
	return value;
}
void GPIO_WRITE_PIN(GPIO_Reg_Def *pGPIOx,uint16_t PINNUMBER,uint8_t value)
{
	if(value==1)
	{
		pGPIOx->ODR|=(1<<PINNUMBER);
	}
	else
	{
		pGPIOx->ODR&=~(1<<PINNUMBER);
	}

}
void GPIO_WRITE_PORT(GPIO_Reg_Def *pGPIOx,uint16_t value)
{
	pGPIOx->ODR=value;
}
void GPIO_INIT(GPIO_Handle_T *gpio_init)
{
	uint32_t temp=0;

	//Setting mode of the pin

     if((gpio_init->pGPIOM.GPIO_MODE)<=3)
     {
    	 temp=(gpio_init->pGPIOM.GPIO_MODE)<<(2*gpio_init->pGPIOM.GPIO_PIN);
    	 gpio_init->pGPIOx->MODER|=temp;
     }
     else
     {
        if(gpio_init->pGPIOM.GPIO_MODE==INTERRUPT_FT)
        {
           EXTI->FTSR1|=(1<<gpio_init->pGPIOM.GPIO_PIN);

           EXTI->RTSR1&=~(1<<gpio_init->pGPIOM.GPIO_PIN);
        }
        else if(gpio_init->pGPIOM.GPIO_MODE==INTERRUPT_RT)
        {
        	EXTI->FTSR1&=~(1<<gpio_init->pGPIOM.GPIO_PIN);

        	 EXTI->RTSR1|=(1<<gpio_init->pGPIOM.GPIO_PIN);
        }
        else
        {
        	EXTI->FTSR1|=(1<<gpio_init->pGPIOM.GPIO_PIN);

            EXTI->RTSR1|=(1<<gpio_init->pGPIOM.GPIO_PIN);
        }

       //Selecting the port for interrupt
        uint8_t temp1=(gpio_init->pGPIOM.GPIO_PIN)/4;
        uint8_t temp2=(gpio_init->pGPIOM.GPIO_PIN)%4;
        uint8_t portcode=finding(gpio_init->pGPIOx);
        SYSCFG->EXTICR[temp1]|=(portcode<<(4*temp2));

        //setting imr register which determine the generation of interrupt

        EXTI->IMR1|=(1<<gpio_init->pGPIOM.GPIO_PIN);
     }
     temp=0;
     //setting speed of pin i.e how quickly the rise and fall happening at a particular pin

     temp=(gpio_init->pGPIOM.GPIO_SPEED)<<(2*gpio_init->pGPIOM.GPIO_PIN);
     gpio_init->pGPIOx->OSPEEDR|=temp;

     //setting output type of pin

     temp=(gpio_init->pGPIOM.GPIO_OUTTYPE)<<(gpio_init->pGPIOM.GPIO_PIN);
     gpio_init->pGPIOx->OTYPER|=temp;

   //setting push pull down mode

     temp=(gpio_init->pGPIOM.GPIO_PUPDM)<<(2*gpio_init->pGPIOM.GPIO_PIN);
     gpio_init->pGPIOx->PUPDR|=temp;

  //setting alternate function mode

     if(gpio_init->pGPIOM.GPIO_MODE==ALTERNATE_MODE)
     {
    	 uint8_t temp1=(gpio_init->pGPIOM.GPIO_PIN)/8;
    	 uint8_t temp2=(gpio_init->pGPIOM.GPIO_PIN)%8;
    	 gpio_init->pGPIOx->AF[temp1]|=(gpio_init->pGPIOM.GPIO_ALT_MODE)<<(4*temp2);
     }

}
void GPIO_PIN_TOGGLE(GPIO_Reg_Def *pGPIOx,uint16_t PINNUMBER)
{
   pGPIOx->ODR^=(1<<PINNUMBER);
}
uint8_t finding(GPIO_Reg_Def *pGPIOx)
{
	if(pGPIOx==GPIOA)
	{
		return 0;
	}
	else if(pGPIOx==GPIOB)
	{
		return 1;
	}
	else if(pGPIOx==GPIOC)
	{
		return 2;
	}
	else if(pGPIOx==GPIOD)
	{
		return 3;
	}
	else if(pGPIOx==GPIOE)
	{
		return 4;
	}

}
void IRQInterruptEnable(uint32_t IRQNumber,uint8_t EnorDi)
{
  if(EnorDi==1)
  {
	  if(IRQNumber>=0 && IRQNumber<=31)
	  	{
	  		*(NVIC_ISER0_BASE_ADDR)|=(1<<IRQNumber);
	  	}
	  	else if(IRQNumber>31 && IRQNumber<=64)
	  	{
	  		*(NVIC_ISER0_BASE_ADDR+0x04)|=(1<<(IRQNumber)%32);
	  	}
	  	else if(IRQNumber>64 && IRQNumbe<96)
	  	{
	  		*(NVIC_ISER0_BASE_ADDR+0x08)|=(1<<(IRQNumber)%64);
	  	}
  }
  else
  {
	  if(IRQNumber>=0 && IRQNumber<=31)
	  	  	{
	  	  		*(NVIC_ICER0_BASE_ADDR)|=(1<<IRQNumber);
	  	  	}
	  	  	else if(IRQNumber>31 && IRQNumber<=64)
	  	  	{
	  	  		*(NVIC_ICER0_BASE_ADDR+0x04)|=(1<<(IRQNumber)%32);
	  	  	}
	  	  	else if(IRQNumber>64 && IRQNumbe<96)
	  	  	{
	  	  		*(NVIC_ICER0_BASE_ADDR+0x08)|=(1<<(IRQNumber)%64);
	  	  	}
  }

}
void IRQPrioritySet(uint32_t IRQNumber,uint32_t Priority)
{
	uint16_t ipr=(IRQNumber)/4;
	uint16_t ipr_section=(IRQNumber)%4;
	*(NVIC_IPR0_BASE_ADDR+ipr) |=(Priority<<(8*ipr_section));
}
void IRQHandling(uint16_t PINNUMBER)
{
	if(EXTI->PR1 &(1<<PINNUMBER))
	{
		EXTI->PR1 |=(1<<PINNUMBER);
	}
}
