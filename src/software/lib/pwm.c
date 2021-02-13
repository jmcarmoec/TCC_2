#include "pwm.h"
void init_PWM(){    
    LPC_SYSCON->SYSAHBCLKCTRL   |= (1<<7);
    LPC_SYSCON->SYSAHBCLKCTRL   |= (1<<8);    

    //LPC_SYSCON->SYSAHBCLKDIV = 0x1;

    LPC_IOCON->PIO0_8           |= 0x2;
    LPC_IOCON->PIO0_9           |= 0x2;

    LPC_TMR16B0->PR = 3-1; //1 us
    LPC_TMR16B0->MR3 = 20*1000;//20 ms 
    LPC_TMR16B0->MR0 = 10*1000; // 10 ms   

    /*
    //LPC_TMR16B0->MCR |= (1<<9);
    LPC_TMR16B0->MCR |= (1<<10);
    //LPC_TMR16B0->MCR |= (1<<11);

    LPC_TMR16B0->PWMC |= 1<<0;
    
    LPC_TMR16B0->TCR = 0x2;
    LPC_TMR16B0->TCR = 0x1;*/


    //LPC_TMR16B1->TCR |= 1<<1;
    //LPC_TMR16B1->TCR &= ~(1<<0);


}

