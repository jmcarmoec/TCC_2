#include "system_actuators.h"

float set_motor_inc(int PIN_MOTOR, float INC_RAD_MOTOR,int TYPE_VALUE){
    float value = INC_RAD_MOTOR;
    float add = 0;
    if(TYPE_VALUE==MATH_VALUE){
        add = MS_TO_RAD(get_duty_cycle(PIN_MOTOR));        
    }
    value+=add;
    switch(PIN_MOTOR){
        case PIN_PWM_MOTOR_NORTH_SOUTH:
            set_duty_cycle(PIN_PWM_MOTOR_NORTH_SOUTH,RAD_TO_MS(value));
        break;
        case PIN_PWM_MOTOR_EAST_WEST:
            set_duty_cycle(PIN_PWM_MOTOR_EAST_WEST,RAD_TO_MS(value));
        break;
    }

    return 0;
}