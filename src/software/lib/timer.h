/*
* FONTE: https://www.digikey.com/eewiki/display/microcontroller/Getting+Started+with+NXP%27s+LPC11XX+Cortex-M0+ARM+Microcontrollers#GettingStartedwithNXP'sLPC11XXCortex-M0ARMMicrocontrollers-CodeExample0:ToggleaGPIOPin
*/
#ifndef TIMER
#define TIMER
    #include <LPC11xx.h>

    #define PRESCALE (48000-1)

    void init_TIMER_0();
    void delay_MS(unsigned int milliseconds);
#endif