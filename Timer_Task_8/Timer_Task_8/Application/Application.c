/*
 * Application.c
 *
 * Created: 03/09/2021 11:19:26 م
 *  Author: Ahmed SemSem
 */ 
#include "../HAL/Header/LED_driver_ECU.h"
#include "../MCAL/Header/Timer.h"
#include "LED_Interrupt.h"
/* define CPU Clock Cycle To 2 MHZ */
#define F_CPU 2000000UL

int main(void)
{
	LED_vinitialize('A',0);
	LED_vTurnoff('A',0);
	/* CAll Timer Initialization With 
	* Timer 1 
	* 64 Prescaler
	* Overflow Interrupt
	* Normal Mode */
	TMR_voidInit();
	/* Enable GIE Interrupt */
	TMR_voidEnableGIE();
	/* Set TCNT as 500 ms Delay */
	TMR_s8SetTCNT(49911);/*(2^16(timer resolution))-(.5Sec/(64(Prescaler)/2000000Hz)) = 49911*/
	/* Set CAll Back Function */
	TMR_voidSetCallBack(LED_voidInterrupt);
	while(1)
    {
	}
}