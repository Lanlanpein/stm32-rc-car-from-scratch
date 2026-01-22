#include "stm32f10x.h" // Device header
#include "Motor.h"
#include "Delay.h"
#include "Key.h"
#include "PWM.h"
#include "WiFi.h"

uint16_t i;
uint16_t Key_num;
int16_t speed_l = 0;
int16_t speed_r = 0;
uint16_t rxbuf;
uint16_t mode_flag = 'L';

int main(void)
{
	Key_Init();
	Motor_Init();
	WiFi_Init();
	
	while (1)
	{
		
		while(USART_GetFlagStatus(USART2, USART_FLAG_RXNE) == RESET);
		rxbuf = USART_ReceiveData(USART2);
		if ((rxbuf == 'L')||(rxbuf == 'H')||(rxbuf == 'C'))
		{
			mode_flag = rxbuf;
		}			
		if (mode_flag == 'L')
		{
		switch (rxbuf)
			{
			case 'W':
				speed_l += 5;
				speed_r += 5;
				speed_l = Limit(speed_l);
				speed_r = Limit(speed_r);
				break;
			case 'S':
				speed_l -= 5;
				speed_r -= 5;
				speed_l = Limit(speed_l);
				speed_r = Limit(speed_r);
				break;
			case 'A':
				speed_l -= 5;
				speed_r += 5;
				speed_l = Limit(speed_l);
				speed_r = Limit(speed_r);
				break;
			case 'D':
				speed_l += 5;
				speed_r -= 5;
				speed_l = Limit(speed_l);
				speed_r = Limit(speed_r);
				break;
			case 'F':
				speed_l = 0;
				speed_r = 0;
				break;
			}
		}
		else if (mode_flag == 'H')
		{
		speed_l = 0;
		speed_r = 0;			
		switch (rxbuf)
			{
			case 'W':
				speed_l += 50;
				speed_r += 50;
				speed_l = Limit(speed_l);
				speed_r = Limit(speed_r);
				break;
			case 'S':
				speed_l -= 5;
				speed_r -= 5;
				speed_l = Limit(speed_l);
				speed_r = Limit(speed_r);
				break;
			case 'A':
				speed_l -= 5;
				speed_r += 5;
				speed_l = Limit(speed_l);
				speed_r = Limit(speed_r);
				break;
			case 'D':
				speed_l += 5;
				speed_r -= 5;
				speed_l = Limit(speed_l);
				speed_r = Limit(speed_r);
				break;
			case 'F':
				speed_l = 0;
				speed_r = 0;
				break;
			}
		}
		else if (mode_flag == 'C')
		{
	
		switch (rxbuf)
			{
			case 'W':
				speed_l = 50;
				speed_r = 50;
				speed_l = Limit(speed_l);
				speed_r = Limit(speed_r);
				break;
			case 'S':
				speed_l = -50;
				speed_r = -50;
				speed_l = Limit(speed_l);
				speed_r = Limit(speed_r);
				break;
			case 'A':
				speed_l = 40;
				speed_r = 60;
				speed_l = Limit(speed_l);
				speed_r = Limit(speed_r);
				break;
			case 'D':
				speed_l = 60;
				speed_r = 40;
				speed_l = Limit(speed_l);
				speed_r = Limit(speed_r);
				break;
			case 'F':
				speed_l = 0;
				speed_r = 0;
				break;
			case 'N':
				speed_l = 0;
				speed_r = 0;
				break;
			}
		}
		
		
		PWM_SetCompare1(speed_l);
		PWM_SetCompare2(speed_r);
		
		
//		if (Get_Keynum() == 1)
//		{
//			speed += 10;
//			if (speed >100)
//			{
//				speed = 30;
//			}
//		}
//		PWM_SetCompare1(0);
//		PWM_SetCompare2(0);
//		for (i = 30; i<=100; i++)
//		{
//			PWM_SetCompare1(i);
//			PWM_SetCompare2(i);
//			Delay_ms(100);
//		}
//		for (i = 100; i>=30; i--)
//		{
//			PWM_SetCompare1(i);
//			PWM_SetCompare2(i);
//			Delay_ms(100);
//		}
	}
}
