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
    delay_MS(1);
}
unsigned int recv_UART(){
    char data;
    while(LPC_UART->LSR & 0x01){}       //wait for transmitted byte to loop back and be received                                       
    data = LPC_UART->RBR;               //store received data (sec 13.5.1)
    return data;
}

void printf_int(int value){
    if(value<0){
        send_UART('-');
        value*=-1;
    }
    if(value==0){
        send_UART('0');        
    }
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
        if(array_values[top]!=0){
            send_UART(array_values[top]+'0');
        }else{
            send_UART('0');
        }
        
        top--;
    }
}

void printf_string(char* string){
    for(int i=0;string[i]!=0;i++){
        send_UART(string[i]);
    }
}

void printf_float(float value){
    if(value!=0){
        int p_i = (int)value;
        float p_d = value-p_i;
        p_d*=expoente(10,FLOAT_PRECISION);
        printf_int(p_i);
        send_UART('.');
        if(p_d<0){
            p_d *=-1;
        }        
        for(int i=FLOAT_PRECISION;i>0;i--){
            printf_int(p_d/expoente(10,i-1));
            p_d = (int)p_d % (int)expoente(10,i-1);
        }        
    }else{
        printf_string("0.0");
    }
}

double expoente(double base,double expoente){
    float ac =1;
    for(int i=0;i<expoente;i++){
        ac*=base;
    }
    return ac;
}