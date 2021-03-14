#include "system_functions.h"
#include "system_sensors.h"
#include "system_actuators.h"

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
float get_radianos_motor(int PIN_MOTOR){
    float rad = 0.0;
    rad = get_duty_cycle(PIN_MOTOR);
    rad = MS_TO_RAD(rad);    
    return rad;
}
float control_motor(int PIN_MOTOR,float set_point){    
    float point = MS_TO_RAD(get_duty_cycle(PIN_MOTOR));
    float erro_faixa = GRAUS_TO_RADIANOS(1.5);
    float erro = 0;
    float Up = 0;
    float Ui = 0;
    float Ud = 0;
    float U  = 0;        
    for(float i=0;!((point>=set_point-erro_faixa)&&(point<=set_point+erro_faixa));i=i+(PI/300)){
        erro = set_point-point;
        Up = Kp*erro;
        Ui = Ki*erro*i;        
        Ud = Kd*erro/i;
        U = Up+Ui+Ud;
        //send_UART(' ');
        //printf_float(point);
        set_motor_inc(PIN_MOTOR,U,MATH_VALUE);

        point = MS_TO_RAD(get_duty_cycle(PIN_MOTOR));
    }
    return U;
}