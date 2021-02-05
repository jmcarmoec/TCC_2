#include "adc.h"

void init_ADC(){    
    LPC_SYSCON->PDRUNCFG        &= ~(1<<4); 
    LPC_SYSCON->SYSAHBCLKCTRL   |= (1<<13);       
}

void start_ADC(int AD){
    switch(AD){
        case (AD0):
            LPC_IOCON->R_PIO0_11          &= 0xFFFFFF78;
            LPC_IOCON->R_PIO0_11          |= (1<<1);                        
        break;
        case (AD1):
            LPC_IOCON->R_PIO1_0          &= 0xFFFFFF78;
            LPC_IOCON->R_PIO1_0          |= (1<<1);                        
        break;
        case (AD2):        
            LPC_IOCON->R_PIO1_1          &= 0xFFFFFF78;
            LPC_IOCON->R_PIO1_1          |= (1<<1);
        break;
        case (AD3):
            LPC_IOCON->R_PIO1_2          &= 0xFFFFFF78;
            LPC_IOCON->R_PIO1_2          |= (1<<1);
        break;
        case (AD4):
            LPC_IOCON->SWDIO_PIO1_3      &= 0xFFFFFF78;
            LPC_IOCON->SWDIO_PIO1_3      |= (1<<1);
        break;
    }
    LPC_ADC->CR                   = 0x0B00;
}
void select_ADC_channel(int AD){
    LPC_ADC->CR                   |= 1<<AD;
}
int read_ADC(int AD){
    LPC_ADC->CR     |= (1<<24);
    while((LPC_ADC->DR[AD] < 0x7FFFFFFF));     
    return ((LPC_ADC->DR[AD] & 0xFFC0) >> 8);
}