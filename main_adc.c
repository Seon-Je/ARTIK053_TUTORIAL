#include <stdio.h>
#include "adc.h"

#define ADC_PIN0 0

void main(void)
{
	int32_t val;

	while (1)
	{
		val = read_adc(ADC_PIN0);
		printf("ADC%d value : %d \n", ADC_PIN0, val);
		up_mdelay(1000);
	}
}


