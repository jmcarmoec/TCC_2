#ifndef SYS_FUNC
#define SYS_FUNC

    #define DEBUG_FLAG 1

    #include <LPC11xx.h>    

    #include "../lib/adc.h"
    #include "../lib/gpio.h"
    #include "../lib/pwm.h"
    #include "../lib/timer.h"

    #if DEBUG_FLAG
        #include "../lib/uart.h"
    #endif

    #define PIN_LED_STATUS_SYSTEM       (5)//0_5

    #define PIN_MOTOR_0_CONTROL_ENABLE  (1)//0_1
    #define PIN_MOTOR_1_CONTROL_ENABLE  (2)//0_2
    #define PIN_MOTOR_0_CONTROL         (3)//0_3
    #define PIN_MOTOR_1_CONTROL         (4)//0_4
    #define PIN_PWM_MOTOR_NORTH_SOUTH               (PWM_MR1)
    #define PIN_PWM_MOTOR_EAST_WEST                 (PWM_MR0)
    #define PIN_MOTOR_0_1_SANS                      (AD4)

    #define PIN_LDR_NORTH       (AD0)
    #define PIN_LDR_SOUTH       (AD1)
    #define PIN_LDR_EAST        (AD2)
    #define PIN_LDR_WEST        (AD3)
    
    void init_system();
#endif