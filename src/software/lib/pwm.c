#include "pwm.h"
void init_PWM(){    
    	LPC_SYSCON->SYSAHBCLKCTRL     |= (1<<7); // Habilita clock do Timer 0 de 16 bits (Pag. 30)
      	//PC_SYSCON->SYSAHBCLKCTRL     |= (1<<8);          

      	LPC_IOCON->PIO0_8             |= 0x2; // Selecina a o canal do pino 0_8 como saída do timer 0 de 16 bits (pag. 85)
      	LPC_IOCON->PIO0_9             |= 0x2;

      	LPC_SYSCON->SYSAHBCLKDIV = 0x1; // Dividir o clock por 1 (pag. 29)

      	/*
        	    Olhar a página 327, para saber o que cada registrador abaixo faz.
      	*/

      	LPC_TMR16B0->PR = CLOCK_SYS-1; // Define o prescale que é usado como granularidade do pwm, ou seja, 1 us de precisão no pulso (pag. 329)
      	LPC_TMR16B0->MR3 = PWM_PERIOD_DEFAULT*1000;//Define o período de 20 ms (pag. 331)
      	LPC_TMR16B0->MR0 = LPC_TMR16B0->MR3-PWM_DEFAULT_DUTY_CYCLE*1000; // Define o duty cycle de 1.7 ms (pag. 331)   		
		LPC_TMR16B0->MR1 = LPC_TMR16B0->MR3-PWM_DEFAULT_DUTY_CYCLE*1000;

      	LPC_TMR16B0->CTCR = 0x0; // Define o timer como contador, para cada borda de subida irá contar um valor. (pag. 334)

      	LPC_TMR16B0->MCR |= 1<<10; // Reseta o Contador (Reg. TC) quando o contador chegar no valor definino como período (MR3) (pag. 330)

      	LPC_TMR16B0->PWMC = (1<<3)|(1<<0)|(1<<1); //Define PWM para o registrador MR0. (pag. 335)

      	start_PWM();

      	/*
        	    PWM Rules: Correção páginas email = 336 e 337
      	*/
}
void set_duty_cycle(int PWM_MRx,float milisecValue){
	if(PWM_MRx==PWM_MR0){
		LPC_TMR16B0->MR0 = LPC_TMR16B0->MR3-milisecValue*1000;
	}else{
		LPC_TMR16B0->MR1 = LPC_TMR16B0->MR3-milisecValue*1000;
	}
}
void set_period(float milisecValue){
	LPC_TMR16B0->MR3=milisecValue*1000;
}

float 	get_duty_cycle(int PWM_MRx){
	float T;
	float Ton;
	float Toff;

	T= LPC_TMR16B0->MR3;

	if(PWM_MRx==PWM_MR0){		
		Toff = LPC_TMR16B0->MR0;		
	}else{
		Toff = LPC_TMR16B0->MR1;
	}
	Ton=T-Toff;
	return Ton/1000;
}
float get_period(){
	return LPC_TMR16B0->MR3/1000;
}
void start_PWM(){
	LPC_TMR16B0->TCR = 0x2; //Reseta a contagem (pag. 329)
	LPC_TMR16B0->TCR = 0x1; //Inicia contagem (pag. 329)
}
void stop_PWM(){	
	LPC_TMR16B0->TCR = 0x2; //Reseta a contagem (pag. 329)
    LPC_TMR16B0->TCR &= ~(1<<0); //Inicia contagem (pag. 329)		
}