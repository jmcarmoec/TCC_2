#include "system_sensors.h"

float get_lux_LDR(u_int8_t PIN_LDR){
    float value=-1;    
    switch(PIN_LDR){
        case (PIN_LDR_NORTH):
            select_ADC_channel(PIN_LDR_NORTH);
            value=V_AD(read_ADC(PIN_LDR_NORTH));
        break;
        case (PIN_LDR_SOUTH):
            select_ADC_channel(PIN_LDR_SOUTH);
            value=V_AD(read_ADC(PIN_LDR_SOUTH));
        break;
        case (PIN_LDR_WEST):
            select_ADC_channel(PIN_LDR_WEST);
            value=V_AD(read_ADC(PIN_LDR_WEST));
        break;
        case (PIN_LDR_EAST):
            select_ADC_channel(PIN_LDR_EAST);
            value=V_AD(read_ADC(PIN_LDR_EAST));
        break;
    }    
    value = p(value)-e(value);
    return (value)<0?0.1:value;
}
float p(float x){
    return 118.6914204*expoente(x,2) - 187.4369988*x + 68.8980274;
}
float e(float x){
    return ((-37.72388518*x*x*x)+(207.09982962*x*x)-(304.99913932*x)+(71.50709816));
}