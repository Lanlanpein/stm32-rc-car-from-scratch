#include "stm32f10x.h"
#include "PWM.h"

void Motor_Init(void)
{
	PWM_Init();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef L298N_structure;
	L298N_structure.GPIO_Mode = GPIO_Mode_Out_PP;
	L298N_structure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	L298N_structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &L298N_structure);
	
	GPIO_InitTypeDef L298N_structure2;
	L298N_structure2.GPIO_Mode = GPIO_Mode_Out_PP;
	L298N_structure2.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	L298N_structure2.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &L298N_structure2);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_6);
	GPIO_ResetBits(GPIOB, GPIO_Pin_7);
	
	GPIO_SetBits(GPIOA, GPIO_Pin_6);
	GPIO_ResetBits(GPIOA, GPIO_Pin_7);
}


//Õý×ª
void Motor_Forward(void)
{
    GPIO_SetBits(GPIOA, GPIO_Pin_6);  // AIN1=1
    GPIO_ResetBits(GPIOA, GPIO_Pin_7); // AIN2=0
	GPIO_ResetBits(GPIOB, GPIO_Pin_7); // AIN1=0
    GPIO_SetBits(GPIOB, GPIO_Pin_6);   // AIN2=1
}

//·´×ª
void Motor_Backward(void)
{
    GPIO_SetBits(GPIOA, GPIO_Pin_7);  // AIN1=1
    GPIO_ResetBits(GPIOA, GPIO_Pin_6); // AIN2=0
	GPIO_ResetBits(GPIOB, GPIO_Pin_6); // AIN1=0
    GPIO_SetBits(GPIOB, GPIO_Pin_7);   // AIN2=1
}

int16_t Limit(int16_t speed)
{
	if (speed > 0)
	{
		Motor_Forward();
	} 
	else if (speed < 0)
	{
		Motor_Backward();
	} 
	
//	if (speed > 1 && speed < 30)
//	{
//		speed = 30;
//	} 
//	else if (speed > -30 && speed < -1)
//	{
//		speed = -30;
//	} 
	
	if (speed > 100)
	{
		speed = 100;
	}
	else if (speed < -100)
	{
		speed = -100;
	} 	
	return speed;
}






