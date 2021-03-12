#ifndef SYS_ACT
#define SYS_ACT

#define DEBUG_FLAG 1

    #include "system_functions.h"    

    /*
        Como padrão irei usar medidas de ângulos em radianos
    */

    #define PI (3.14159265359)
    #define RADIANOS_TO_GRAUS(RAD)      ((180*RAD)/(2*PI))
    #define GRAUS_TO_RADIANOS(GRA)      ((2*PI*GRA)/(180))

    #define RAD_TO_MS(RAD)  (((1/(2*PI))*(RAD))+1)
    #define MS_TO_RAD(MS)   (2*PI*(MS-1))
    float set_motor(int motor, float INC_RAD_MOTOR);//Motor norte-sul ou leste-oeste | inclinação do motor em radianos | retorna inclinação antiga
#endif