#include "timer.h"
void init_TIMER_0(){
    /*Assuming CCLK (System Clock) = 48Mhz (set by startup code)*/
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<9); //Enable 32Bit Timer0 Clock
	LPC_TMR32B0->CTCR = 0x0;
	LPC_TMR32B0->PR = PRESCALE; //Increment LPC_TMR32B0->TC at every 47999+1 clock cycles        
	//48000 clock cycles @48Mhz = 1 mS
	LPC_TMR32B0->TCR = 0x02; //Reset Timer
}
void delay_MS(unsigned int milliseconds){  

    LPC_TMR32B0->TCR = 0x02; //Reset Timer
	LPC_TMR32B0->TCR = 0x01; //Enable timer

	while(LPC_TMR32B0->TC < milliseconds); //wait until timer counter reaches the desired delay

	LPC_TMR32B0->TCR = 0x00; //Disable timer
}