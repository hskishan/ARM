#include<lpc17xx.h>
#define DEGREES 360
void delay(unsigned int ms)
{
	unsigned int i,j;
		for(i=0;i<ms;i++)
		for(j=0;j<1275;j++);	
}
int main()
{
	unsigned int steps = 200*DEGREES/360;
	unsigned int i = 0;
	unsigned int clock[] = {0x00008000,0x00010000,0x00020000,0x00040000};
	unsigned int anticlock[] = {0x00040000,0x0002000,0x00010000,0x00080000};
	
	LPC_GPIO0->FIODIR |=0x00078000;
	
	while(1)
	{
		for(i=0;i<steps;i++)
		{
			LPC_GPIO0->FIOCLR |= 0x00078000;
			LPC_GPIO0->FIOSET = clock[i%4];
			delay(200);
		}
		
		for (i=0;i<steps;i++)
		{
			LPC_GPIO0->FIOCLR |=0x00078000;
			LPC_GPIO0->FIOSET = anticlock[i%4];
			delay(200);
		}
	}
}
