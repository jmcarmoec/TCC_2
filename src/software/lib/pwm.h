  
/*
* FONTE: https://www.digikey.com/eewiki/display/microcontroller/Getting+Started+with+NXP%27s+LPC11XX+Cortex-M0+ARM+Microcontrollers#GettingStartedwithNXP'sLPC11XXCortex-M0ARMMicrocontrollers-CodeExample0:ToggleaGPIOPin
*/
#ifndef PWM
#define PWM
    #include <LPC11xx.h>
    #include "timer.h"

    #define CLOCK_SYS   (48) // MHz

    #define PERIOD_SERVO_MOTOR    (20) // ms
    #define DEFAULT_DUTY_CYCLE_SERVO_MOTOR_0 (1.7) // ms
    #define DEFAULT_DUTY_CYCLE_SERVO_MOTOR_1 (10) // ms

    
    #define MOTOR_0     (0)
    #define MOTOR_1     (1)

    void init_PWM();

    
#endif