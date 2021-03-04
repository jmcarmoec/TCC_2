#include "system_functions.h"

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
    start_ADC(PIN_LDR_WEST);
    start_ADC(PIN_LDR_EAST);
}