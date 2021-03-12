#include "system_actuators.h"

float set_motor(int motor, float INC_RAD_MOTOR){

    switch(motor){
        case PIN_PWM_MOTOR_NORTH_SOUTH:
            set_duty_cycle(PIN_PWM_MOTOR_NORTH_SOUTH,RAD_TO_MS(INC_RAD_MOTOR));
        break;

        case PIN_PWM_MOTOR_EAST_WEST:
            set_duty_cycle(PIN_PWM_MOTOR_EAST_WEST,RAD_TO_MS(INC_RAD_MOTOR));
        break;
    }

    return 0;
}