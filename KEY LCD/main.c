#include <lpc17xx.h>
#include "extern.h"
int main(void)
{
	unsigned char key;
	
	KeyPadInitialize();
	
	lcdinit();
	lcdstring("Key Pressed:");
	
	while(1)
	{
		key=GetKeyPressed();
		delay(20);
		lcdchar(0x8C,'C');
		delay(1);
		lcdchar(key,'D');
	}
}