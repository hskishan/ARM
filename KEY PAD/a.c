#include <LPC17xx.h>

void SetRowToZero(unsigned char);
unsigned char ReadColumnNumber(void);
void KeyPadInitialize(void);
unsigned char GetKeyPressed(void);
void delay(int count);

char keyCodes[4][4]=
{
	{0x1,0x2,0x3,0x4},
	{0x5,0x6,0x7,0x8},
	{0x9,0x0,0xA,0xB},
	{0xC,0xD,0xE,0xF}
};
int main(void)
{
	unsigned char key;
	
	LPC_GPIO1->FIODIR = 0x07F80000;
	
	KeyPadInitialize();
	
	while(1)
	{
		key=GetKeyPressed();
		delay(20);
		
		if(key!=0xFF)
			LPC_GPIO1->FIOPIN=(key<<19);
		else
			LPC_GPIO1->FIOCLR = 0x07F80000;
	}
}
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
