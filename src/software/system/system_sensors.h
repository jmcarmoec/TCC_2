#ifndef SYS_SENS
#define SYS_SENS
    
    #include "system_functions.h"

    #define ERROR_MAX_LUX   (66.94231628)
    #define ERROR_MEDIO_LUX (8,34816797)

    float get_lux_LDR(u_int8_t PIN_LDR);
    float interpolation_function(float value);

#endif