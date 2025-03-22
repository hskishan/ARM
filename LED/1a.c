#include<lpc17xx.h>
int main()
{
	//Configure P1.19 as Output
	LPC_GPIO1->FIODIR=0x01000000;
	
	//Switch on LED
	LPC_GPIO1->FIOSET=0x01000000;
	while(1);
	
}
