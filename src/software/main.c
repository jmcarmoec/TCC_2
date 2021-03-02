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
  /*GPIO CONFIG SET*/ 
  init_GPIO();  

  set_DIR(1,OUTPUT);
  set_DIR(2,OUTPUT);
  set_DIR(3,OUTPUT);
  set_DIR(4,OUTPUT);
  set_DIR(5,OUTPUT);

  write_digital_gpio(1,LOW);
  write_digital_gpio(2,LOW);
  write_digital_gpio(3,LOW);
  write_digital_gpio(4,LOW);
  write_digital_gpio(5,HIGH);
  

  init_UART();

  init_ADC();
  start_ADC(AD4);
  select_ADC_channel(AD4);

  init_TIMER_0();

  init_PWM();
  set_period(20);  
  //set_duty_cycle(PWM_MR0,1.86);
  //set_duty_cycle(PWM_MR1,1.25);

  while(1){
    send_UART('|');
    printf_int(read_ADC(AD4));
    delay_MS(1000);
  }
  return 0 ;
}
