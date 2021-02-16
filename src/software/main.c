/* 
 * Created:   qua dez 9 2020
 * Processor: LPC1114FN28/102
 * Compiler:  GCC for ARM
 */

#include <LPC11xx.h>

#define DEBUG_FLAG 1

#include "lib/adc.h"
#include "lib/gpio.h"
#include "lib/pwm.h"
#include "lib/timer.h"

#if DEBUG_FLAG
#include "lib/uart.h"
#endif

int main(void) { 

      //init_GPIO();                        
      init_UART();
      init_TIMER_0();
      //init_PWM();
      //set_DIR(3,OUTPUT);      
      
      LPC_SYSCON->SYSAHBCLKCTRL     |= (1<<7); // Habilita clock do Timer 0 de 16 bits (Pag. 30)
      //PC_SYSCON->SYSAHBCLKCTRL     |= (1<<8);          

      LPC_IOCON->PIO0_8             |= 0x2; // Selecina a o canal do pino 0_8 como saída do timer 0 de 16 bits (pag. 85)
      //LPC_IOCON->PIO0_9             |= 0x2;

      LPC_SYSCON->SYSAHBCLKDIV = 0x1; // Dividir o clock por 1 (pag. 29)

      /*
            Olhar a página 341, para saber o que cada registrador abaixo faz.
      */

      LPC_TMR16B0->PR = 48-1; // Define o prescale que é usado como granularidade do pwm, ou seja, 1 us de precisão no pulso (pag. 344)
      LPC_TMR16B0->MR3 = 20*1000;//Define o período de 20 ms (pag. 345)
      LPC_TMR16B0->MR0 = 1.7*1000; // Define o duty cycle de 1.7 ms (pag. 345)   
      
      LPC_TMR16B0->CTCR = 0x0; // Define o timer como contador, para cada borda de subida irá contar um valor. (pag. 349)

      LPC_TMR16B0->MCR |= 1<<10; // Reseta o Contador (Reg. TC) quando o contador chegar no valor definino como período (MR3) (pag. 345)

      LPC_TMR16B0->PWMC = 0x1; //Define PWM para o registrador MR0. (pag. 350)

      LPC_TMR16B0->TCR = 0x2; //Reseta a contagem (pag. 343)
      LPC_TMR16B0->TCR = 0x1; //Inicia contagem (pag. 343)

      

      //char a = 0;          
      while(1){
            
            printf_string("|");
            printf_int(LPC_TMR16B0->MR0);            
            /*
            if(a){
                 write_digital_gpio(3,HIGH);
                 a=0;
            }else{
                 write_digital_gpio(3,LOW);
                 a=1;
            }*/
            delay_MS(1000);
      }
      return 0 ;
}
