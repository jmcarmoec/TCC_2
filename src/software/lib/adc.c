#include "adc.h"

void init_ADC(){    
    LPC_SYSCON->PDRUNCFG        &= ~(1<<4);
    LPC_SYSCON->SYSAHBCLKCTRL   |= (1<<13);
}