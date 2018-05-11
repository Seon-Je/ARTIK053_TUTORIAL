#include <stdio.h>
#include "pwm.h"

#define PWM_PIN 0
#define PERIOD 1000

void main(void)
{
	int i;
	int fd;

	fd=pwm_open(PWM_PIN);
	while(1)
	{
		for (i=0 ; i< 1000 ; i=i+10)
		{
			printf("PORT : %d | PERIOD : %d | Duty_Cycle : %d\n", PWM_PIN, PERIOD, i/10);
			pwm_write(fd, PERIOD, i);
			up_mdelay(100);
		}

		for (i=990 ; i>0 ; i=i-10)
		{
			printf("PORT : %d | PERIOD : %d | Duty_Cycle : %d \n", PWM_PIN, PERIOD, i/10);
			pwm_write(fd, PERIOD, i);
			up_mdelay(100);
		}
	}
	pwm_close(fd);
}
