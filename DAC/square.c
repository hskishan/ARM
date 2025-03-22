#include <lpc17xx.h>
#define AMPLITUDE 3.3

void delay(unsigned int ms)
{
	unsigned int i,j;
	for(i=0;i<ms;i++)
		for(j=0;j<1275;j++);
}
int main(void)
{
	unsigned long int dacrValue = 0;
	unsigned long int dac_value = 0;
	
	SystemInit();
	
	LPC_PINCON->PINSEL1 |= (1<<21);
	LPC_PINCON->PINSEL1 &= ~(1<<20);
	
	LPC_DAC->DACR |= (1<<16);
	
	dac_value = AMPLITUDE * 1023 /3.3;
	
	while(1)
	{
		dacrValue &= ~(0x3FF<<6);
		dacrValue |= (dac_value<<6);
		LPC_DAC->DACR = dacrValue;
		delay(100);
		
		dacrValue &= ~(0x3FF<<6);
		LPC_DAC->DACR = dacrValue;
		delay(100);
}
	}