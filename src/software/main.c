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
      start_ADC(0);
      select_ADC_channel(0);  

     while(1){                 
            printf_float(V_AD(read_ADC(0)));             
            for(int i=0; i < 0xFFFFF; ++i);                 
            
     }
      return 0 ;
}
