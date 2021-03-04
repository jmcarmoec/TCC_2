/* 
 * Created:   qua dez 9 2020
 * Processor: LPC1114FN28/102
 * Compiler:  GCC for ARM
 */
#include "system/system_functions.h"
#include "system/system_actuators.h"
#include "system/system_sensors.h"

int main(void) {
  /*
  init_GPIO();  

  set_DIR(1,OUTPUT);
  set_DIR(2,OUTPUT);
  set_DIR(3,OUTPUT);
  set_DIR(4,OUTPUT);
  set_DIR(5,OUTPUT);

  write_digital_gpio(5,HIGH);
  

  init_UART();

  init_ADC();
  start_ADC(AD0);
  select_ADC_channel(AD0);

  init_TIMER_0();

  init_PWM();
  set_period(20);  
  set_duty_cycle(PWM_MR0,1);
  delay_MS(10000);
  set_duty_cycle(PWM_MR0,2);
  set_duty_cycle(PWM_MR1,1.25);
  */
  init_system();

  while(1){
    send_UART('|');
    printf_float(get_lux_LDR(PIN_LDR_NORTH));
    delay_MS(1000);
  }
  return 0 ;
}
