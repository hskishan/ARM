#include <lpc17xx.h>
#include <math.h>

#define PI			3.14159265
#define SAMPLES		1024

int main(void)
{
	short int i=0;
	unsigned long int dacrValue = 0;
	float angle = 0;
	
	SystemInit();
	
	LPC_PINCON->PINSEL1 |= (1<<21);
	LPC_PINCON->PINSEL1 &= ~(1<<20);
	
	LPC_DAC->DACR |= (1<<16);
	
	while(1)
	{
		for(i=0;i<SAMPLES;i++)
		{
			angle = (2 * PI * i)/SAMPLES;
			
			dacrValue = (unsigned long int)((sin(angle) +1)*511.5);
			
			LPC_DAC->DACR = (dacrValue<<6);
		}
	}
}
	