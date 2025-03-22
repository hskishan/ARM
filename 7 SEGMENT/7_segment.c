#include<lpc17xx.h>
int main(void)
{
	LPC_GPIO0->FIODIR |= 0x00001F7;

	LPC_GPIO4->FIODIR |=(1<<28);

	LPC_GPIO0->FIOPIN = 0x00000000;
	
	LPC_GPIO4->FIOSET |= (1<<28);
	LPC_GPIO0->FIOSET |= (1<<2);

	while(1);
	
}
