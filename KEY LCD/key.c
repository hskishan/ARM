#include <LPC17xx.h>

void SetRowToZero(unsigned char);
unsigned char ReadColumnNumber(void);


char keyCodes[4][4]=
{
	{'1','2','3','4'},
	{'5','6','7','8'},
	{'9','0','A','B'},
	{'C','D','E','F'}
};

void KeyPadInitialize(void)
{
	LPC_GPIO1->FIODIR |= (1<<9)|(1<<10)|(1<<14)|(1<<15);
	
	LPC_GPIO1->FIODIR &= ~((1<<0)|(1<<1)|(1<<4)|(1<<8));
}
void SetRowToZero(unsigned char rowNumber)
{
	LPC_GPIO1->FIOSET |= (1<<9)|(1<<10)|(1<<14)|(1<<15);
	
	switch(rowNumber)
	{
		case 0: LPC_GPIO1->FIOCLR |=(1<<9);
				break;
		case 1: LPC_GPIO1->FIOCLR |=(1<<10);
				break;
		case 2: LPC_GPIO1->FIOCLR |=(1<<14);
				break;
		case 3: LPC_GPIO1->FIOCLR |=(1<<15);
				break;
	}
}
unsigned char ReadColumnNumber(void)
{
	unsigned long int temp = LPC_GPIO1->FIOPIN;
	
	if((temp & (1<<0))==0)
		return 0;
	
	else if((temp & (1<<1))==0)
		return 1;
	
	else if((temp & (1<<4))==0)
		return 2;
	
	else if((temp & (1<<8))==0)
		return 3;
	else
		return 4;
}
unsigned char GetKeyPressed(void)
{
	unsigned char rowNumber,colNumber;
	
	while(1)
	{
		for(rowNumber =0; rowNumber<4; rowNumber++)
		{
			SetRowToZero(rowNumber);
			colNumber = ReadColumnNumber();
			
			if(colNumber<4)
				return keyCodes[rowNumber][colNumber];
		}
	}
}
void delay(int count)
{
	unsigned int i,j;
	
	for(i=0; i<count;i++)
		for(j=0;j<1275;j++);
}

		
	
