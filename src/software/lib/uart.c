#include "uart.h"
void init_UART(){
    LPC_IOCON->PIO1_6                |= 0x01;      //configure UART RXD pin (sec 7.4.40)
    LPC_IOCON->PIO1_7               |= 0x01;      //configure UART TXD pin (sec 7.4.41)
    LPC_SYSCON->SYSAHBCLKCTRL       |= (1<<12);   //enable clock to UART (sec 3.5.14)
    LPC_SYSCON->UARTCLKDIV          |= 0x9B;      //set clk divider to 4e (sec 3.5.16)
    LPC_UART->FCR                   |= 0x01;      //enable FIFO (sec 13.5.6)
    LPC_UART->LCR                   |= 0x03;      //set for 8 bit data width, 1 stop bit, no parity (sec 13.5.7)
    LPC_UART->TER                   |= 0x80;      //enable transmission (sec 13.5.16)    
}
void send_UART(char data){    
    LPC_UART->THR &= 0x00;
    LPC_UART->THR |= data;  
    for(int i=0;i<0xFF1;i++);  
}
unsigned int recv_UART(){
    char data;
    while(LPC_UART->LSR & 0x01){}       //wait for transmitted byte to loop back and be received                                       
    data = LPC_UART->RBR;               //store received data (sec 13.5.1)
    return data;
}

void printf_int(int value){
    int top=-1;
    int array_values[30];   
    int aux = value;
    int charSend;
    while(aux!=0){        
        ++top;
        charSend=aux%10;        
        array_values[top]=charSend;
        aux/=10;
        
    }
    while (top>=0){
        send_UART(array_values[top]+'0');
        top--;
    }
}

void printf_string(char* string){
    for(int i=0;string[i]!=0;i++){
        send_UART(string[i]);
    }
}

void printf_float(float value){
    int p_i = (int)value;
    float p_d = value-p_i;
    p_d*=pow(10,FLOAT_PRECISION);
    printf_int(p_i);
    send_UART('.');
    printf_int(p_d);
}