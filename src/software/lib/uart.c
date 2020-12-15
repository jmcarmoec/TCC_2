#include "uart.h"
void init_UART(){
   LPC_IOCON->PIO1_6             |= 0x01;      //configure UART RXD pin (sec 7.4.40)
    LPC_IOCON->PIO1_7             |= 0x01;      //configure UART TXD pin (sec 7.4.41)
    LPC_SYSCON->SYSAHBCLKCTRL     |= (1<<12);   //enable clock to UART (sec 3.5.14)
    //LPC_SYSCON->UARTCLKDIV        |= 0x00;      //set clk divider to 4e (sec 3.5.16)
    LPC_UART->FCR                 |= 0x01;      //enable FIFO (sec 13.5.6)
    LPC_UART->LCR                 |= 0x03;      //set for 8 bit data width, 1 stop bit, no parity (sec 13.5.7)
    LPC_UART->TER                 |= 0x80;      //enable transmission (sec 13.5.16)
}
void send_UART(char text){
    int data = 0x0d;
    LPC_UART->THR |= ++data & 0xFF;
}
char* recv_UART(){
    return 0;
}