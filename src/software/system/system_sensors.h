#ifndef SYS_SENS
#define SYS_SENS
    
    #include "system_functions.h"    

    #define ERROR_MAX   (55.21673164)
    #define ERROR_MIN   (0.5288358399)
    #define ERROR_MED   (24.37560262)
    
    #define LUX_MAX     (1000)
    #define LUX_MIN     (0.1)

    #define GET_LUX_MAX (931.864807)
    #define GET_LUX_MIN (0.1)

    float get_lux_LDR(u_int8_t PIN_LDR);    
    float p(float x);
    float e(float x);
#endif