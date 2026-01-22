#include "stm32f10x.h"                  // Device header

void WiFi_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIOA_InitStructure;
	GPIOA_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIOA_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIOA_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIOA_InitStructure);
	GPIOA_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIOA_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_Init(GPIOA, &GPIOA_InitStructure);
	
	USART_InitTypeDef WIFI_InitStructure;
	WIFI_InitStructure.USART_BaudRate = 9600;
	WIFI_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	WIFI_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	WIFI_InitStructure.USART_Parity = USART_Parity_No;
	WIFI_InitStructure.USART_StopBits = USART_StopBits_1;
	WIFI_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART2, &WIFI_InitStructure);
	
	USART_Cmd(USART2, ENABLE);
}

uint16_t Get_WIFI(void)
{
	uint16_t Data = 0;
	if (USART_GetFlagStatus(USART2, USART_FLAG_RXNE) == 1)
	{
		Data = USART_ReceiveData(USART2);
	}
	return Data;
}

