/*
 * stm32l4gpio.h
 *
 *  Created on: May 13, 2025
 *      Author: Arun
 */

#ifndef STM32L4GPIO_H_
#define STM32L4GPIO_H_

#include<stdio.h>
#include<stdint.h>
#include "stm32l476xx.h"
/*
 * GPIO REGISTERS
 */


typedef struct{
	uint8_t GPIO_MODE;
	uint16_t GPIO_PIN;
	uint8_t GPIO_SPEED;
	uint8_t GPIO_OUTTYPE;
	uint8_t GPIO_PUPDM;
	uint8_t GPIO_ALT_MODE;
}GPIO_Config;



typedef struct{
	GPIO_Reg_Def *pGPIOx;
	GPIO_Config pGPIOM;
}GPIO_Handle_T;

/*
 * DIFFERENT MODES OF GPIO PERIPHERAL
 */
#define INPUT_MODE        0
#define OUTPUT_MODE       1
#define ALTERNATE_MODE    2
#define ANALOG_MODE       3
#define INTERRUPT_FT      4
#define INTERRUPT_RT      5
#define INTERRUPT_RFT     6


/*
 * GPIO OUTPUT TYPE REGISTER
 */
#define OUTPUT_PUSHPULL      0
#define OUTPUT_OPENDRAIN     1

/*
 * GPIO SPEED REGISTER
 */
#define SPEED_LS               0
#define SPEED_MS               1
#define SPEED_HS               2
#define SPEED_VHS              3

/*
 * PUSH PULL DOWN REGISTER
 */
#define PUSHPULL_NOPUPD          0
#define PUSHPULL_PU              1
#define PUSHPULL_PD              2

/*
 * GPIO PIN Numbers
 */
#define GPIO_PIN_NUM0                      0
#define GPIO_PIN_NUM1                      1
#define GPIO_PIN_NUM2                      2
#define GPIO_PIN_NUM3                      3
#define GPIO_PIN_NUM4                      4
#define GPIO_PIN_NUM5                      5
#define GPIO_PIN_NUM6                      6
#define GPIO_PIN_NUM7                      7
#define GPIO_PIN_NUM8                      8
#define GPIO_PIN_NUM9                      9
#define GPIO_PIN_NUM10                     10
#define GPIO_PIN_NUM11                     11
#define GPIO_PIN_NUM12                     12
#define GPIO_PIN_NUM13                     13
#define GPIO_PIN_NUM14                     14
#define GPIO_PIN_NUM15                     15


/*
 * Alternate functions
 */

#define ALT_FUN0                            0
#define ALT_FUN1                            1
#define ALT_FUN2                            2
#define ALT_FUN3                            3
#define ALT_FUN4                            4
#define ALT_FUN5                            5
#define ALT_FUN6                            6
#define ALT_FUN7                            7
#define ALT_FUN8                            8
#define ALT_FUN9                            9
#define ALT_FUN10                           10
#define ALT_FUN11                           11
#define ALT_FUN12                           12
#define ALT_FUN13                           13
#define ALT_FUN14                           14
#define ALT_FUN15                           15

void GPIO_PERI_CLK(GPIO_Reg_Def *pGPIOx,uint8_t ENorDI);
uint8_t GPIO_READ_PIN(GPIO_Reg_Def *pGPIOx,uint16_t PINNUMBER);
uint16_t GPIO_READ_PORT(GPIO_Reg_Def *pGPIOx);
void GPIO_WRITE_PIN(GPIO_Reg_Def *pGPIOx,uint16_t PINNUMBER,uint8_t value);
void GPIO_WRITE_PORT(GPIO_Reg_Def *pGPIOx,uint16_t value);
void GPIO_INIT(GPIO_Handle_T *gpio_init);
void GPIO_PIN_TOGGLE(GPIO_Reg_Def *pGPIOx,uint16_t PINNUMBER);
void finding(GPIO_Reg_Def *pGPIOx);
void IRQInterruptEnable(uint32_t IRQNumber,uint8_t EnorDi);
void IRQPrioritySet(uint32_t IRQNumber,uint32_t Priority);
void IRQHandling(uint16_t PINNUMBER);
#endif /* STM32L4GPIO_H_ */
