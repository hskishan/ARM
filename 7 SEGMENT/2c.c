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
	
	unsigned char number,digit,i =0;
	
	LPC_GPIO0->FIODIR |= 0x000001F7;
	
	LPC_GPIO4->FIODIR |= (1<<28);
	
	while(1)
	{
		for(number = 0xFF; number >=0x00; number--)
		{
			for(i=0;i<50;i++)
			{
				digit = (number & 0xF0)>>4;
				LPC_GPIO0->FIOPIN = sevensegcodes[digit];
				LPC_GPIO0->FIOSET |= (1<<2);
				LPC_GPIO4->FIOCLR |= (1<<28);
				delay(50);
				
				digit = (number & 0x0F);
				LPC_GPIO0->FIOPIN = sevensegcodes[digit];
				LPC_GPIO0->FIOCLR |= (1<<2);
				LPC_GPIO4->FIOSET |= (1<<28);
				delay(50);
			}
		}
	}
}



	