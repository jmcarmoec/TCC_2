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
     set_DIR(3,INPUT);        
     while(1){
          if(read_digital_gpio(3)==HIGH){
               printf_string("Ta funcionando nessa merda");           
               printf_float(1586.458);
          }
          
     }
      return 0 ;
}
