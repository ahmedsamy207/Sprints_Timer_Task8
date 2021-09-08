/*
 * LED_Interrupt.h
 *
 * Created: 9/2/2021 8:22:26 PM
 *  Author: Ahmed SemSem
 */ 
#include "../HAL/Header/LED_driver_ECU.h"
#include "../MCAL/Header/Timer.h"


#ifndef LED_INTERRUPT_H_
#define LED_INTERRUPT_H_


/* Prototype of the Call Back Function */
void LED_voidInterrupt (void);


#endif /* LED_INTERRUPT_H_ */