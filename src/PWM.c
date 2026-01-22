#include "stm32f10x.h"                  // Device header


void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIOA_Structure;
	GPIOA_Structure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIOA_Structure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIOA_Structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIOA_Structure);
	
	TIM_InternalClockConfig(TIM2);
	
	TIM_TimeBaseInitTypeDef TIM_InitStructure;
	TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_InitStructure.TIM_Period = 100 -1; //ARR
	TIM_InitStructure.TIM_Prescaler = 720 - 1; //PSC
	TIM_InitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_InitStructure);
	
	TIM_OCInitTypeDef PWM_InitStructure;
	TIM_OCStructInit(&PWM_InitStructure);
	PWM_InitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	PWM_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	PWM_InitStructure.TIM_OutputState = TIM_OutputState_Enable;
	PWM_InitStructure.TIM_Pulse = 0; //CRR
	TIM_OC1Init(TIM2, &PWM_InitStructure);
	TIM_OC2Init(TIM2, &PWM_InitStructure);
	
	TIM_Cmd(TIM2, ENABLE);
	
}

void PWM_SetCompare1(uint16_t Compare)
{
	TIM_SetCompare1(TIM2, Compare);
}

void PWM_SetCompare2(uint16_t Compare)
{
	TIM_SetCompare2(TIM2, Compare);
}

