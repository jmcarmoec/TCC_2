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
      init_TIMER_0();
      //init_PWM();
      set_DIR(3,OUTPUT);      
      LPC_SYSCON->SYSAHBCLKCTRL   |= (1<<7);
      LPC_SYSCON->SYSAHBCLKCTRL   |= (1<<8);          

      LPC_IOCON->PIO0_8           |= 0x2;
      LPC_IOCON->PIO0_9           |= 0x2;

      LPC_SYSCON->SYSAHBCLKDIV = 0x1;

      LPC_TMR16B0->PR = 48-1; //1 us
      LPC_TMR16B0->MR3 = 20*1000;//20 ms 
      LPC_TMR16B0->MR0 = 20*1000-1.7*1000; // 1.7 ms       
            
      LPC_TMR16B0->MCR |= 1<<10;

      //LPC_TMR16B0->MCR |= 1<<9;

      //LPC_TMR16B0->EMR |= 1<<4;
      //LPC_TMR16B0->EMR |= 1<<5;

      LPC_TMR16B0->CTCR = 0x0;

      LPC_TMR16B0->PWMC = 0x1;

      LPC_TMR16B0->TCR = 0x2;
      LPC_TMR16B0->TCR = 0x1;      

      char a = 0;          
      while(1){ 
            printf_string("|");
            printf_int(LPC_TMR16B0->MCR);            
            if(a){
                 write_digital_gpio(3,HIGH);
                 a=0;
            }else{
                 write_digital_gpio(3,LOW);
                 a=1;
            }
            delay_MS(500);
      }
      return 0 ;
}
