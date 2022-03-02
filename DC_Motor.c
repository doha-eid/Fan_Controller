/***********************************************************************************************************
 * Module :DC_Motor
 *
 *File Name :DC_Motor.c
 *
 *  Description :Source File for DC Motor driver
 *
 *      Author: Doha Eid
 **********************************************************************************************************/
#include"common_macros.h"
#include"DC_Motor.h"
#include"gpio.h"
#include"pwm.h"

/*
 * Description :
 * Function responsible for initiate the DC Motor
 */
void DcMotor_Init(void )
{
/*
 * Set the 2-pins of motor as output pins
 */
	GPIO_setupPinDirection(DC_MOTOR_PORT,DC_MOTOR_FIRST_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT,DC_MOTOR_SECOND_PIN,PIN_OUTPUT);
	/*Stop the motor at the beginning */
	GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_FIRST_PIN,LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_SECOND_PIN,LOGIC_LOW);


}

/*
 * Description :
 * Function responsible for rotate the Dc Motor CW, ACW , Stop
 */
void DcMotor_Rotate(DcMotor_state state , uint8 speed)
{
Timer0_PWM_Init(speed);
 if (state==Clock_Wise)
{
	GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_FIRST_PIN,LOGIC_HIGH);
	GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_SECOND_PIN,LOGIC_LOW);
}
else if (state==Anti_Clock_Wise)
{
	GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_FIRST_PIN,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_SECOND_PIN,LOGIC_HIGH);
}else{
	GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_FIRST_PIN,LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_SECOND_PIN,LOGIC_LOW);
}
}
