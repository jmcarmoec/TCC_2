/*
* FONTE: https://www.digikey.com/eewiki/display/microcontroller/Getting+Started+with+NXP%27s+LPC11XX+Cortex-M0+ARM+Microcontrollers#GettingStartedwithNXP'sLPC11XXCortex-M0ARMMicrocontrollers-CodeExample0:ToggleaGPIOPin
*/
#ifndef GPIO
#define GPIO
    #include <stdio.h>  
    #include <LPC11xx.h>    

    #define INPUT   (0)
    #define OUTPUT  (1)

    #define HIGH    (1)
    #define LOW     (0)

    #define GET_PIN(N)  (N%12)
    #define GET_MOD(N)  ((N-(GET_PIN(N)))/12)    

    #define GET_MACRO_GPIO(N) ((GET_MOD(N)==0)?(LPC_GPIO0):(LPC_GPIO1))

    /*
        function: enable GPIO clock
        parameters(0): -
        return: -
    */
    void init_GPIO();

    /*
        function: set GPIO as INPUT or OUTPUT
        parameters(2):
            N-> 12*MODULE + PIN_NUMBER
            DIR -> INPUT or OUTPUT
        return: -
    */
    void set_DIR(u_int8_t N,u_int8_t DIR);

    /*
        function: set digital output value as HIGH or LOW
        parameters(2): 
             N-> 12*MODULE + PIN_NUMBER
             VALUE -> LOW or HIGH
        return: -

    */
   void write_digital_gpio(u_int8_t N,u_int8_t VALUE);

   /*
        function: get digital input value as HIGH or LOW
        parameters:
            N-> 12*MODULE + PIN_NUMBER
        return(u_int8_t): value in pin number N as HIGH(1) or LOW(0)

   */
  u_int8_t read_digital_gpio(u_int8_t N);
#endif