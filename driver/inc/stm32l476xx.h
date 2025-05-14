/*
 * stm32l476xx.h
 *
 *  Created on: May 12, 2025
 *      Author: Arun
 */

#ifndef STM32L476XX_H_
#define STM32L476XX_H_
#include<stdio.h>
#include<stdint.h>
#include<stddef.h>
#include "stm32l4gpio.h"
/*  AHB AND APB BUS ADDRESSES
 */
#define AHB1_BASE_ADDR            0x40020000U
#define AHB2_BASE_ADDR            0x48000000U
#define APB1_BASE_ADDR            0x40000000U
#define APB2_BASE_ADDR            0x40010000U
#define EXTI_BASE_ADDR            0x40010400U
#define SYSCGG_BASE_ADDR          0x40010000U
#define NVIC_ISER0_BASE_ADDR      0xE000E100U
#define NVIC_ICER0_BASE_ADDR      0XE000E180U
#define NVIC_IPR0_BASE_ADDR       0xE000E400U

/*
 * GPIO BASE ADDRESSES
 */

#define GPIOA_BASE_ADDR           (AHB2_BASE_ADDR+0x0000)
#define GPIOB_BASE_ADDR           (AHB2_BASE_ADDR+0x0400)
#define GPIOC_BASE_ADDR           (AHB2_BASE_ADDR+0x0800)
#define GPIOD_BASE_ADDR           (AHB2_BASE_ADDR+0x0C00)
#define RCC_BASE_ADDR             (AHB1_BASE_ADDR+0x1000)


/*
 * RCC REGISTERS
 */
typedef struct{
	uint32_t CR;
	uint32_t ICSCR;
	uint32_t CFGR;
	uint32_t PLLCFGR;
	uint32_t PLLSAI1CFGR;
	uint32_t PLLSAI2CFGR;
	uint32_t CIER;
	uint32_t CIFR;
	uint32_t CICR;
	uint32_t AHB1RSTR;
	uint32_t AHB2RSTR;
	uint32_t AHB3RSTR;
	uint32_t APB1RSTR1;
	uint32_t APB1RSTR2;
	uint32_t APB2RSTR;
	uint32_t AHB1ENR;
	uint32_t AHB2ENR;
	uint32_t AHB3ENR;
	uint32_t APB1ENR1;
	uint32_t APB1ENR2;
	uint32_t APB2ENR;
	uint32_t AHB1SMENR;
	uint32_t AHB2SMENR;
	uint32_t AHB3SMENR;
	uint32_t APB1SMENR1;
	uint32_t APB1SMENR2;
	uint32_t APB2SMENR;
	uint32_t CCIPR;
	uint32_t BDCR;
	uint32_t CSR;
	uint32_t CRRCR;
	uint32_t CCIPR2;
}RCC_RegDef_t;


typedef struct{
	uint32_t MODER;
	uint32_t OTYPER;
	uint32_t OSPEEDR;
	uint32_t PUPDR;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t LCKR;
	uint32_t AF[2];
	uint32_t BRR;
	uint32_t ASCR;
}GPIO_Reg_Def;

/*
 * EXTI registers
 */

typedef struct{
	uint32_t IMR1;
	uint32_t EMR1;
	uint32_t RTSR1;
	uint32_t FTSR1;
	uint32_t SWIER1;
	uint32_t PR1;
	uint32_t IMR2;
	uint32_t EMR2;
	uint32_t RTSR2;
	uint32_t FTSR2;
	uint32_t SWIER2;
	uint32_t PR2;
}EXTI_Reg_Def;

/*
 * SYSCFG Registers
 */
typedef struct{
	uint32_t MEMRMP;
	uint32_t CFGR1;
	uint32_t EXTICR[4];
	uint32_t SCSR;
	uint32_t CFGR2;
	uint32_t SWPR;
	uint32_t SKR;
	uint32_t SWPR2;
}SYSCFG_Reg_Def;


#define GPIOA             ((GPIO_Reg_Def*)GPIOA_BASE_ADDR)
#define GPIOB             ((GPIO_Reg_Def*)GPIOB_BASE_ADDR)
#define GPIOC             ((GPIO_Reg_Def*)GPIOC_BASE_ADDR)
#define GPIOD             ((GPIO_Reg_Def*)GPIOD_BASE_ADDR)
#define RCC               ((RCC_RegDef_t*)RCC_BASE_ADDR)
#define EXTI              ((EXTI_Reg_Def*)EXTI_BASE_ADDR)
#define SYSCFG            ((SYSCFG_Reg_Def*)SYSCGG_BASE_ADDR)



#define GPIOA_CLK_EN()               ((RCC->AHB2ENR) |=(1<<0))
#define GPIOB_CLK_EN()               ((RCC->AHB2ENR)|=(1<<1))
#define GPIOC_CLK_EN()               ((RCC->AHB2ENR)|=(1<<2))
#define GPIOD_CLK_EN()               ((RCC->AHB2ENR)|=(1<<3))
#define GPIOE_CLK_EN()               ((RCC->AHB2ENR)|=(1<<4))
#define GPIOF_CLK_EN()               ((RCC->AHB2ENR)|=(1<<5))


/*
 * GPIO PERIPHERAL CLOCK DISABLE
 */

#define GPIOA_CLK_DI()               ((RCC->AHB2ENR) &=~(1<<0))
#define GPIOB_CLK_DI()               ((RCC->AHB2ENR)&=~(1<<1))
#define GPIOC_CLK_DI()              ((RCC->AHB2ENR)&=~(1<<2))
#define GPIOD_CLK_DI()               ((RCC->AHB2ENR)&=~(1<<3))
#define GPIOE_CLK_DI()               ((RCC->AHB2ENR)&=~(1<<4))
#define GPIOF_CLK_DI()               ((RCC->AHB2ENR)&=~(1<<5))


/*
 * enable or disable
 */

#define ENABLE               1
#define DISABLE              0

/*
 * IRQ number corresponding to EXTI lines
 */
#define EXTI0                                               6
#define EXTI1                                               7
#define EXTI2                                               8
#define EXTI3                                               9
#define EXTI4                                               10
#define EXTI9_5                                             23
#define EXTI15_10                                           40

#endif /* STM32L476XX_H_ */
