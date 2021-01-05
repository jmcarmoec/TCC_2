/*
* FONTE: https://www.digikey.com/eewiki/display/microcontroller/Getting+Started+with+NXP%27s+LPC11XX+Cortex-M0+ARM+Microcontrollers#GettingStartedwithNXP'sLPC11XXCortex-M0ARMMicrocontrollers-CodeExample0:ToggleaGPIOPin
*/
#ifndef UART
#define UART
    #include <LPC11xx.h>     
    #include <math.h>

     #define FLOAT_PRECISION 6

    /*
        function: enable TX,RX and UART clock
        parameters(0): -
        return: - 
    */
   void init_UART();

   /*
        function: send data through RX
        parameters(1): sequence of characters
        return: -
   */
  void send_UART(char data);

   /*
        function: recive data through TX
        parameters(1): -
        return: sequence of characters
   */
  unsigned int recv_UART(); //NOT READY

  void printf_int(int value);
  void printf_string(char* string);
  void printf_float(float value);

#endif