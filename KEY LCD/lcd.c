#include <LPC17xx.h>
#include "extern.h"

#define RS	9
#define RW	10
#define EN	11

void lcdinit(void)
{
	LPC_GPIO0->FIODIR |=(1<<22)|(1<<21)|(1<<20)|(1<<19);
	
	LPC_GPIO0->FIODIR |=(1<<11)|(1<<10)|(1<<9);
	
	lcdchar(0x33,'C');
	delay(100);
	
	lcdchar(0x32,'C');
	delay(100);
	
	lcdchar(0x28,'C');
	delay(100);
	
	lcdchar(0x0C,'C');
	delay(100);
	
	lcdchar(0x06,'C');
	delay(100);
	
	lcdchar(0x01,'C');
	delay(100);
}
void lcdstring(char *str)
{
	unsigned char i=0;
	 while(str[i] != '\0')
	 {
		 lcdchar(str[i],'D');
		 i++;
	 }
 }
void lcdchar(unsigned char data,unsigned char type)
{
	unsigned char lowerNibble = data & 0x0F;
	
	unsigned char upperNibble = (data & 0xF0)>>4;
	
	if(type=='C')
		LPC_GPIO0->FIOCLR = (1<<RS);
	else if(type=='D')
		LPC_GPIO0->FIOSET = (1<<RS);
	
	LPC_GPIO0->FIOSET |=(1<<EN);
	LPC_GPIO0->FIOCLR |=(0x0F<<19);
	LPC_GPIO0->FIOSET |=(upperNibble<<19);
	LPC_GPIO0->FIOCLR |=(1<<EN);
	delay(100);
	
	LPC_GPIO0->FIOSET |=(1<<EN);
	LPC_GPIO0->FIOCLR |=(0x0F<<19);
	LPC_GPIO0->FIOSET |=(lowerNibble<<19);
	LPC_GPIO0->FIOCLR |=(1<<EN);
	delay(100);
}

