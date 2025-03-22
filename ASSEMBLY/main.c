#include<LPC17xx.h>

extern void OddEvenSum(void);

int main(void)
{
	SystemInit();
	OddEvenSum();
	while(1);
}
