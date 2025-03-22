#include<lpc17xx.h>
void delay(unsigned int count)
{
	unsigned int i,j;
	for(i=0; i<1275;j++)
		for(j=0;j<1275;j++);
}

int main()
	
{		
	LPC_GPIO1->FIODIR =  0x07F80000;
	while(1)

	LPC_GPIO1->FIOSET =  0x05500000;
	LPC_GPIO1->FIOCLR =  0x0AA00000;
	delay(1000);
	LPC_GPIO1->FIOCLR =  0x05500000;
	LPC_GPIO1->FIOSET =  0x0AA00000;
	delay(1000);

}