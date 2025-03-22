#include<lpc17xx.h>
void delay(unsigned int count)
{
	unsigned int i,j;
	for(i=0;i<count;i++)
		for(j=0;j<1275;j++);
}
int main()
{
	while(1)
	{
		LPC_GPIO1->FIODIR = 0x07800000;
		LPC_GPIO1->FIOSET = 0x07800000;
		delay(2000);
		LPC_GPIO1->FIOCLR = 0x07800000;
		delay(2000);
	}
}