/* 
 * Created:   qua dez 9 2020
 * Processor: LPC1114FN28/102
 * Compiler:  GCC for ARM
 */

#include <LPC11xx.h>

#define DEBUG_FLAG 1

#include "lib/adc.h"
#include "lib/gpio.h"
#include "lib/pwm.h"
#include "lib/timer.h"

#if DEBUG_FLAG
#include "lib/uart.h"
#endif

int main(void) {      
      init_GPIO();                        
      init_UART();      
      init_ADC();        
      //init_TIMER_0();
      LPC_IOCON->PIO0_8         = (LPC_IOCON->PIO0_8 & ~(0x3FF)) | 0x2;     //set up pin for PWM use (sec 7.4.23)
    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<7);                                  //enable clock signal to 16 bit timer0 (sec 3.5.14)
    LPC_TMR16B0->PR           = 10;                                      //set prescaler max value, not used here (sec 18.7.4)
    LPC_TMR16B0->MCR          = 0x10;                                     //set for reset on counter match (sec 18.7.6)
    LPC_TMR16B0->EMR          |= 0x20;                                    //set pin 27 to 1 on match (sec 18.7.10)
    LPC_TMR16B0->CCR          = 0;                                        //set to timer mode (sec 18.7.11)
    LPC_TMR16B0->PWMC         = 0x1;                                      //set channel zero to PWM mode (sec 18.7.12)
    LPC_TMR16B0->MR1          = 0x32;                                     //set value for period (sec 18.7.7)
    LPC_TMR16B0->MR0          = 50;                                      //set value for duty cycle (sec 18.7.7)
    LPC_TMR16B0->TCR          |= 0x3;                                     //enable and reset counter (sec 18.7.2)
    LPC_TMR16B0->TCR          &= ~(0x2);                                  //clear reset bit (sec 18.7.2)
     while(1){         
      printf_int(LPC_TMR16B0->TC);                                                            
     }
      return 0 ;
}
