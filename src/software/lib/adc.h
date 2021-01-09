/*
* FONTE: https://www.digikey.com/eewiki/display/microcontroller/Getting+Started+with+NXP%27s+LPC11XX+Cortex-M0+ARM+Microcontrollers#GettingStartedwithNXP'sLPC11XXCortex-M0ARMMicrocontrollers-CodeExample0:ToggleaGPIOPin
*/
#ifndef ADC
#define ADC
    #include <LPC11xx.h>     

    #define AD0 0 // NOT CONFIGURED
    #define AD1 1
    #define AD2 2
    #define AD3 3
    #define AD4 4
    #define AD5 5 // NOT CONFIGURED

    void init_ADC();
    void start_adc(int AD);
    
#endif