/*
* FONTE: https://www.digikey.com/eewiki/display/microcontroller/Getting+Started+with+NXP%27s+LPC11XX+Cortex-M0+ARM+Microcontrollers#GettingStartedwithNXP'sLPC11XXCortex-M0ARMMicrocontrollers-CodeExample0:ToggleaGPIOPin
*/
#ifndef PWM
#define PWM
    #include <LPC11xx.h>
    #include "timer.h"

    #define MOTOR_0     (0)
    #define MOTOR_1     (1)

    void init_PWM();

    
#endif