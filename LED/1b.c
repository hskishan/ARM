#include<lpc17xx.h>
int main()
{
	LPC_GPIO1->FIODIR |= (1<<19) | (1<<20) | (1<<22) | (1<<24);
	LPC_GPIO1->FIOSET |= (1<<19) | (1<<20) | (1<<22) | (1<<24);
	while(1);
}
