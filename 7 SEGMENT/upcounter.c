#include <lpc17xx.h>

void delay(unsigned int count)
{
	unsigned int i, j;
	for (i=0; i<count; i++)
		for(j=0; j<1275; j++);
}
int main(void)
{
	unsigned long int sevensegcodes[] =
	{
		0x00000100, 0x000001E1, 0x00000090,
		0x000000C0, 0x00000061, 0x00000042,
		0x00000002, 0x000001E0, 0x00000000,
		0x00000040, 0x00000020, 0x00000003,
		0x00000112, 0x00000081, 0x00000012,
		0x00000032
	};
	
	unsigned char i =0;
	
	LPC_GPIO0->FIODIR |= 0x000001F7;
	
	while(1)
	{
		for(i=0;i<16;i++)
		{
			LPC_GPIO0->FIOPIN = sevensegcodes[i];
			
			LPC_GPIO0->FIOSET |= (1<<2);
			
			delay(5000);
		}
	}
	
}
