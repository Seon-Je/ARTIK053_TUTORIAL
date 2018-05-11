#include <stdio.h>
#include "gpio.h"

//GPIO 13(42) 0/1 : switch on/off
//GPIO 16(45) 0/1 : RED off/on
//GPIO 15(44) 0/1 : switch on/off
//GPIO 20(49) 0/1 : BLUE off/on

#define LED_RED 45
#define LED_BLUE 49
#define SW_RED 42
#define SW_BLUE 44

void main(void)
{
	int sw_red_val = 0;
	int sw_blue_val = 0;

	while(1)
	{

		sw_red_val = gpio_read(SW_RED);
		sw_blue_val = gpio_read(SW_BLUE);

		printf("Read GPIO [RED SW(%d) : %d, BLUE SW(%d) : %d]\n", SW_RED,sw_red_val,SW_BLUE,sw_blue_val);

		if (sw_red_val == 0)
		{
			gpio_write(LED_RED,HIGH);
			printf("LED state [RED  ON, ");
		}
		else
		{
			gpio_write(LED_RED,LOW);
			printf("LED state [RED OFF, ");
		}

		if (sw_blue_val == 0)
		{
			gpio_write(LED_BLUE,HIGH);
			printf("BLUE  ON]\n\n");
		}
		else
		{
			gpio_write(LED_BLUE,LOW);
			printf("BLUE OFF]\n\n");
		}

		up_mdelay(1000);
	}
}
