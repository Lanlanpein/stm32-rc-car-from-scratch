#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef KEY_InitStructure;
	KEY_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	KEY_InitStructure.GPIO_Pin = GPIO_Pin_15;
	KEY_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &KEY_InitStructure);
	
}

uint16_t Get_Keynum(void)
{
	uint16_t Keynum = 0;
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15) == 0);
		Delay_ms(20);
		Keynum = 1;
	}
	return Keynum;
}

