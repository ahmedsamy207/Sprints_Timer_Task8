/*
 * LED_Interrupt.c
 *
 * Created: 9/2/2021 8:22:51 PM
 *  Author: Ahmed SemSem
 */ 
#include "LED_Interrupt.h"

/* Global Variable define the State inside the ISR Function */
u8 LED_u8State = 0 ;
void LED_voidInterrupt (void)
{
	/* First State */
	if (LED_u8State == 0 )
	{
		/* After 500 ms LOW make Turn on the Led */
		LED_vTurnon('A',0);
		/* Make the Variable holds the value for the Next State */
		LED_u8State = 1 ;
		/* Make The TCNT Register holds the value for over flow after 300 ms */
		TMR_s8SetTCNT(56161);/*(2^16(timer resolution))-(.3Sec/(64(Prescaler)/2000000Hz)) = 56161*/
	}
	/* Next State */
	else if (LED_u8State==1)
	{
		/* Make The TCNT Register holds the value for over flow after 500 ms */
		TMR_s8SetTCNT(49911);/*(2^16(timer resolution))-(.5Sec/(64(Prescaler)/2000000Hz)) = 49911*/
		/* After 300 ms High make Turn Off the Led */
		LED_vTurnoff('A',0);
		/* Make the Variable holds the value for the Next State */
		LED_u8State = 0 ;
	}
	
}