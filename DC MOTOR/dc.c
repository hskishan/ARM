#include<lpc17xx.h>
#define PWM_PIN 2
#define DutyCycle 40
#define Period 100

int main(void)
{
	unsigned int i;
	unsigned int ON_TIME;
	unsigned int OFF_TIME;
	
	LPC_GPIO2->FIODIR |=(1<<PWM_PIN);
	ON_TIME = (Period * DutyCycle)/100;
	OFF_TIME = Period - ON_TIME;
	
	while(1)
	{
		LPC_GPIO2->FIOSET = (1<<PWM_PIN);
		for (i=0; i<ON_TIME;i++);
		
		LPC_GPIO2->FIOCLR =(1<<PWM_PIN);
		for (i=0;i<OFF_TIME;i++);
	}
}
