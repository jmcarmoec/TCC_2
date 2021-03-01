  
/*
* FONTE: https://www.digikey.com/eewiki/display/microcontroller/Getting+Started+with+NXP%27s+LPC11XX+Cortex-M0+ARM+Microcontrollers#GettingStartedwithNXP'sLPC11XXCortex-M0ARMMicrocontrollers-CodeExample0:ToggleaGPIOPin
*/
#ifndef PWM
#define PWM
    #include <LPC11xx.h>
    #include "timer.h"

    #define CLOCK_SYS   (48) // MHz

    #define PWM_PERIOD_DEFAULT    (20) // ms
    #define PWM_DEFAULT_DUTY_CYCLE (1.5) // ms    

    
    #define PWM_MR0     (0)
    #define PWM_MR1     (1)

    void init_PWM();
    void start_PWM();
    void stop_PWM();

    void set_duty_cycle(int PWM_MRx,float milisecValue);
    void set_period(float milisecValue);

    float get_duty_cycle(int PWM_MRx);
    float get_period();
#endif