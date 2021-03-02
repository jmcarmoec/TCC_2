/*
* FONTE: https://www.digikey.com/eewiki/display/microcontroller/Getting+Started+with+NXP%27s+LPC11XX+Cortex-M0+ARM+Microcontrollers#GettingStartedwithNXP'sLPC11XXCortex-M0ARMMicrocontrollers-CodeExample0:ToggleaGPIOPin
*/
#ifndef ADC
#define ADC
    #include <LPC11xx.h>     

    #define VREF    3.6 // (V)

    #define RESOLUTION (VREF/255) //(V)
    //#define V_AD(ADC_READ_VALUE)  ((RESOLUTION)*(ADC_READ_VALUE))
    #define V_AD(ADC_READ_VALUE) ((3.6*ADC_READ_VALUE)/(255))
    #define AD0     0
    #define AD1     1
    #define AD2     2
    #define AD3     3
    #define AD4     4
    #define AD5     5

    void init_ADC();
    void start_ADC(int AD);
    void select_ADC_channel(int AD);
    int read_ADC(int AD);

#endif