/* 
 * Created:   qua dez 9 2020
 * Processor: LPC1114FN28/102
 * Compiler:  GCC for ARM
 */
#include "system/system_functions.h"
#include "system/system_actuators.h"
#include "system/system_sensors.h"

int main(void) {
  init_system();
  float lux_east=0;
  float lux_west=0;
  float lux_north=0;
  float lux_south=0;
  float rad_inc_E_W=0;
  float rad_inc_N_S=0;
  while(1){
    
    lux_west =  get_lux_LDR(PIN_LDR_WEST);
    lux_east =  get_lux_LDR(PIN_LDR_EAST);
    lux_north=  get_lux_LDR(PIN_LDR_NORTH);
    lux_south=  get_lux_LDR(PIN_LDR_SOUTH);

    rad_inc_E_W = tracking_sun_position(lux_east,lux_west);
    rad_inc_N_S = tracking_sun_position(lux_north,lux_south);

    set_motor_inc(PIN_PWM_MOTOR_EAST_WEST,rad_inc_E_W); 
    set_motor_inc(PIN_PWM_MOTOR_NORTH_SOUTH,rad_inc_N_S); 

    send_UART('>');
    printf_float(lux_north);
    delay_MS(1000);
    
  }
  return 0 ;
}
