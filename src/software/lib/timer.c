#include "timer.h"
void init_TIMER_0(){
    LPC_SYSCON->SYSAHBCLKCTRL |= 1<<9;
    LPC_SYSCON->SYSAHBCLKCTRL |= 1<<10;
    LPC_SYSCON->SYSAHBCLKDIV =0x1;

    LPC_TMR32B0->PR = PRESCALE;

    LPC_TMR32B0->TCR |= 1<<1;
    LPC_TMR32B0->TCR &= ~(1<<0);      
}
void delay_MS(unsigned int milliseconds){  

    LPC_TMR32B0->TCR = 0x02; //Reset Timer
	LPC_TMR32B0->TCR = 0x01; //Enable timer

	while(LPC_TMR32B0->TC < milliseconds); //wait until timer counter reaches the desired delay

	LPC_TMR32B0->TCR = 0x00; //Disable timer
}