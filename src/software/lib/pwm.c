#include "pwm.h"

void init_PWM(){

    LPC_SYSCON->SYSAHBCLKCTRL   |= (1<<7);
    LPC_SYSCON->SYSAHBCLKCTRL   |= (1<<8);    
    LPC_IOCON->PIO0_8           |= 0x2;
    LPC_IOCON->PIO0_9           |= 0x2;
    
}
