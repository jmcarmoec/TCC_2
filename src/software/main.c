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
      LPC_IOCON->JTAG_TDI_PIO0_11    &= 0xFFFFFF78;
      LPC_IOCON->JTAG_TDI_PIO0_11    |= (1<<2);
      LPC_ADC->CR                    = 0x0001;      
     while(1){     
      //printf_string("start");      
      LPC_ADC->CR     |= (1<<24);                            
      while((LPC_ADC->DR[0] < 0x7FFFFFFF)); 
      int value = ( LPC_ADC->DR[0] & 0xFFC0) >> 8;
      printf_int(LPC_ADC->DR[0]);      
      for (int i = 0; i < 2*0xFFFF; i++);       
      //break;
      //printf_string("done");      
      //break;
     }
      return 0 ;
}
