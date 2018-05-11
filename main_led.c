#include <stdio.h>
#include "gpio.h"

#define LED_RED 45
#define LED_BLUE 49

void main(void)
{
	while(1)
	{
		printf("LED TEST - | RED  : ON  | BLUE : OFF | \n");
		gpio_write(LED_RED,HIGH);
		gpio_write(LED_BLUE,LOW);
		up_mdelay(1000);

		printf("LED TEST - | RED  : OFF | BLUE : ON  | \n");
		gpio_write(LED_RED,LOW);
		gpio_write(LED_BLUE,HIGH);
		up_mdelay(1000);
	}
}
