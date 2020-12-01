#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*	
	INFO INPUT:
	Voc: Open Circuito Voltage 	[V]
	Isc: Short circuit current	[A]
	Vmpp: Voltage at maximum power point	[V]
	Impp: Current at maximum power point	[A]
	a: Ideality Factor	[-]	
	
	INFO OUTPUT:	
	Rs: Series Resistance
	Rsh: Shunt Resistance
	Iph: Light-generated current
	I0: Diode saturation current
	
*/

#define CELSIUS (25*pow(10,-3)
#define KELVIN (273.15)
#define C_2_K	(KELVIN+CELSIUS)

// Input Values
float Voc=5.04;
float Isc=0.2;
float Vmpp=4.0;
float Impp=0.178;
float a=1.2;

//Output Values

float Rs;
float Rsh;
float Iph;
float I0;

double LambertW(const double z);
const int dbgW=0;

//Functions

//Calculate Rs
float calculate_A();
float calculate_B();
float calculate_C();
float calculate_D();
float calculate_RS(float A,float B,float C,float D);

//Calculate Rsh
float calculate_Rsh();

//Calculate Iph
float calculate_Iph();

//Calculate I0
float calculate_I0();

int main(int argc, char *argv[]) {	
	printf("%f\n",calculate_A());	
	printf("%f\n",calculate_B());	
	printf("%f\n",calculate_C());	
	printf("%f\n",calculate_D());
	printf("%f\n",calculate_RS(calculate_A(),calculate_B(),calculate_C(),calculate_D()));
	printf("%f\n",LambertW(5));
/*	
	printf("Voc:");
	scanf("%f",&Voc);
	
	printf("Isc:");
	scanf("%f",&Isc);
	
	printf("Vmpp:");
	scanf("%f",&Vmpp);
	
	printf("Impp:");
	scanf("%f",&Impp);
	
	printf("a:");
	scanf("%f",&a);
	*/
	
	return 0;
}
//Calculate Rs
float calculate_A(){
	return (a*CELSIUS/Impp);	
}
float calculate_B(){
	return 0;
}
float calculate_C(){
	return 0;
}
float calculate_D(){
	return 0;
}
float calculate_RS(float A,float B,float C,float D){
	return (A*(LambertW(B*pow(M_E,C))-(D+C)));
}

//Calculate Rsh
float calculate_Rsh(){
	
}

//Calculate Iph
float calculate_Iph(){
	
}

//Calculate I0
float calculate_I0(){
	
}

double LambertW(const double z) {
  int i; 
  const double eps=4.0e-16, em1=0.3678794411714423215955237701614608; 
  double p,e,t,w;
  if (dbgW) fprintf(stderr,"LambertW: z=%g\n",z);
  if (z<-em1 || isinf(z) || isnan(z)) { 
    fprintf(stderr,"LambertW: bad argument %g, exiting.\n",z); exit(1); 
  }
  if (0.0==z) return 0.0;
  if (z<-em1+1e-4) { // series near -em1 in sqrt(q)
    double q=z+em1,r=sqrt(q),q2=q*q,q3=q2*q;
    return 
     -1.0
     +2.331643981597124203363536062168*r
     -1.812187885639363490240191647568*q
     +1.936631114492359755363277457668*r*q
     -2.353551201881614516821543561516*q2
     +3.066858901050631912893148922704*r*q2
     -4.175335600258177138854984177460*q3
     +5.858023729874774148815053846119*r*q3
     -8.401032217523977370984161688514*q3*q;  // error approx 1e-16
  }
  /* initial approx for iteration... */
  if (z<1.0) { /* series near 0 */
    p=sqrt(2.0*(2.7182818284590452353602874713526625*z+1.0));
    w=-1.0+p*(1.0+p*(-0.333333333333333333333+p*0.152777777777777777777777)); 
  } else 
    w=log(z); /* asymptotic */
  if (z>3.0) w-=log(w); /* useful? */
  for (i=0; i<10; i++) { /* Halley iteration */
    e=exp(w); 
    t=w*e-z;
    p=w+1.0;
    t/=e*p-0.5*(p+1.0)*t/p; 
    w-=t;
    if (fabs(t)<eps*(1.0+fabs(w))) return w; /* rel-abs error */
  }
  /* should never get here */
  fprintf(stderr,"LambertW: No convergence at z=%g, exiting.\n",z); 
  exit(1);
}
