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
    return value;
}