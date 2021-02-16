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
      init_PWM();
      set_DIR(3,OUTPUT);     
      char a = 0;          
      while(1){
            
            printf_string("|");
            printf_int(LPC_TMR16B0->MR0);            
            
            if(a){
                 write_digital_gpio(3,HIGH);
                 a=0;
            }else{
                 write_digital_gpio(3,LOW);
                 a=1;
            }
            delay_MS(1000);
      }
      return 0 ;
}
