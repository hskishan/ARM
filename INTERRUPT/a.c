#include<lpc17xx.h>

#define LED 19
#define BLINKLED 26
#define EX_INT 1
#define KEY_PIN 11

void led_init(void);
void interrupt_init(void);
void EINT1_IRQHandler(void);

int main(){
	volatile unsigned int blinkcounter = 0;
	led_init();
	interrupt_init();
	
	while(1)
	{
		if (LPC_GPIO2->FIOPIN & (1<<KEY_PIN))
				LPC_GPIO1->FIOCLR = (1<<LED);
		blinkcounter++;
		if (blinkcounter >= 1000000)
		{
			LPC_GPIO1->FIOPIN ^= (1<<BLINKLED);
			blinkcounter=0;
		}
	}
}
void led_init(void)
{
	LPC_GPIO1->FIODIR |=(1<<LED)|(1<<BLINKLED);
	LPC_GPIO2->FIODIR &= ~(1<<KEY_PIN);
	
}
void interrupt_init(void){
	LPC_SC->EXTINT=(1<<EX_INT);
	LPC_PINCON->PINSEL4 |= (1<<22);
	LPC_PINCON->PINSEL4 &= ~(1<<23);
	LPC_SC->EXTMODE |=(1<<EX_INT);
	LPC_SC->EXTPOLAR &= ~(1<<EX_INT);
	
	NVIC_EnableIRQ(EINT1_IRQn);
}

void EINT1_IEQHandler(void){
	LPC_SC->EXTINT=(1<<EX_INT);
	LPC_GPIO1->FIOSET=(1<<LED);
}

