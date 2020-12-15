#include "gpio.h"

void init_GPIO(){
    LPC_SYSCON->SYSAHBCLKCTRL   |= (1<<6);
}
void set_DIR(u_int8_t N,u_int8_t DIR){    
    if(DIR==OUTPUT){
        GET_MACRO_GPIO(N)->DIR |= (1<<(GET_PIN(N)));
    }else{
        GET_MACRO_GPIO(N)->DIR &= ~(1<<(GET_PIN(N)));
    }
}
void write_digital_gpio(u_int8_t N,u_int8_t VALUE){    
    if(VALUE==HIGH){
        GET_MACRO_GPIO(N)->DATA |= (1<<(GET_PIN(N)));
    }else{
        GET_MACRO_GPIO(N)->DATA &= ~(1<<(GET_PIN(N)));
    }
}

u_int8_t read_digital_gpio(u_int8_t N){
    return (GET_MACRO_GPIO(N)->DATA & (1<<(GET_PIN(N))))?(HIGH):(LOW);
}