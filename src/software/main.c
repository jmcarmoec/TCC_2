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
  set_DIR(3,OUTPUT);

  init_UART();

  init_ADC();
  start_ADC(AD0);
  select_ADC_channel(AD0);

  init_TIMER_0();

  init_PWM();
  set_period(20);
  set_duty_cycle(PWM_MR0,1.86);
  set_duty_cycle(PWM_MR1,1.25);

  while(1){
    send_UART('|');
    printf_float(get_duty_cycle(PWM_MR0));
    delay_MS(1000);
  }
  return 0 ;
}
