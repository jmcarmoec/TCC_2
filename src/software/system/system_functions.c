#include "system_functions.h"
#include "system_sensors.h"

void init_system(){
    init_GPIO();
    init_TIMER_0();
    #if DEBUG_FLAG
        init_UART();
    #endif
    init_PWM();
    init_ADC();
    
    start_ADC(PIN_LDR_NORTH);
    start_ADC(PIN_LDR_SOUTH);
    start_ADC(PIN_LDR_EAST);
    start_ADC(PIN_LDR_WEST);    

}

float tracking_sun_position(float value_lux_sensor_A,float value_lux_sensor_B){
    if(value_lux_sensor_A>value_lux_sensor_B){
        return (PI*value_lux_sensor_A)/(2*(GET_LUX_MAX));
    }else if(value_lux_sensor_B>value_lux_sensor_A){
        return (-PI*value_lux_sensor_B)/(2*(GET_LUX_MAX))+PI;
    }
    return PI/2;
}