#ifndef __MOTOR_H
#define __MOTOR_H

void Motor_Init(void);
void Motor_Forward(void);
void Motor_Backward(void);
int16_t Limit(int16_t speed);

#endif
