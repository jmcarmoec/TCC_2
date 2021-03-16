/* 
 * Created:   qua dez 9 2020
 * Processor: LPC1114FN28/102
 * Compiler:  GCC for ARM
 */

#include "system/system_functions.h"
#include "system/system_actuators.h"
#include "system/system_sensors.h"

/*INFORMAÇÕES DO AMBIENTE DE INSTALAÇÃO DO PROTÓTIPO*/
// QUIXADÁ-CE
// Brasil
// COORD: (-4.9781706, -39.0318527) - FONTE: https://www.google.com.br/maps/place/Quixad%C3%A1,+CE,+63900-000/@-4.9781706,-39.0318527,14z/data=!3m1!4b1!4m5!3m4!1s0x7be9fc4afc3f5e3:0x4920f6ec47296ab2!8m2!3d-4.9684385!4d-39.0161259

#define SLEEP_TIME_DAY    (5000) //ms
#define SLEEP_TIME_NIGHT  (10000) //ms

#define DAY   (1)
#define NIGHT (0)

#define STATE_EAST_WEST             (0)
#define STATE_NORTH_SOUTH           (1)
#define STATE_ACTUATORS_EAST_WEST   (2)
#define STATE_ACTUATORS_NORTH_SOUTH (3)
#define STATE_SLEEP                 (4)
#define STATE_NIGHT                 (5)

#define LUX_NIGHT (80)

#define ANGLE_NIGHT (PI/2)

uint8_t time;

float lux_north;
float lux_south;
float lux_east;
float lux_west;

float radians_east_west;
float radians_north_south;

uint8_t state;

int main(void) {  

  init_system();
  state = STATE_EAST_WEST;
  
  while(1){        
    switch (state){
    case (STATE_EAST_WEST):
      lux_east = get_lux_LDR(PIN_LDR_EAST);
      lux_west = get_lux_LDR(PIN_LDR_WEST);
      radians_east_west = tracking_sun_position(lux_east,lux_west);      

      state = STATE_NORTH_SOUTH;
      break;
    case (STATE_NORTH_SOUTH):
      lux_north = get_lux_LDR(PIN_LDR_NORTH);
      lux_south = get_lux_LDR(PIN_LDR_SOUTH);
      radians_north_south = tracking_sun_position(lux_north,lux_south);      

      if(!((lux_east<=LUX_NIGHT)&&(lux_west<=LUX_NIGHT)&&(lux_north<=LUX_NIGHT)&&(lux_south<=LUX_NIGHT))){                
        time  = DAY;
        write_digital_gpio(PIN_DAY_STATUS,HIGH);        
      }else{        
        time  = NIGHT;        
        write_digital_gpio(PIN_DAY_STATUS,LOW);
      }
      
      state = STATE_ACTUATORS_EAST_WEST;
      break;
    case (STATE_ACTUATORS_EAST_WEST):
      write_digital_gpio(PIN_ACTUATOR_L_W_STATUS,HIGH);
      control_motor(PIN_PWM_MOTOR_EAST_WEST,(time==DAY)?radians_east_west:ANGLE_NIGHT);
      write_digital_gpio(PIN_ACTUATOR_L_W_STATUS,LOW);

      state = STATE_ACTUATORS_NORTH_SOUTH;      
      break;
    case (STATE_ACTUATORS_NORTH_SOUTH):
      write_digital_gpio(PIN_ACTUATOR_N_S_STATUS,HIGH);
      control_motor(PIN_PWM_MOTOR_NORTH_SOUTH,(time==DAY)?radians_north_south:ANGLE_NIGHT);
      write_digital_gpio(PIN_ACTUATOR_N_S_STATUS,LOW);

      state = STATE_SLEEP;
      break;    
    case (STATE_SLEEP):
      if(time==DAY){
        delay_MS(SLEEP_TIME_DAY);
      }else{                        
        delay_MS(SLEEP_TIME_NIGHT);        
      }
      
      state = STATE_EAST_WEST;
      break;         
    default:

      break;
    }
  }
  write_digital_gpio(PIN_LED_STATUS_SYSTEM,LOW);
  return 0 ;
}