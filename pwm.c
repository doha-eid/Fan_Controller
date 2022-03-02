/***********************************************************************************************************
 * Module :pwm
 *
 * File Name:pwm.c
 *
 *  Description:Source file for the Pwm mode .
 *
 *      Author: Doha Eid
* *********************************************************************************************************/
#include"pwm.h"
#include"gpio.h"
#include<avr/io.h>

/*
 * Description :
 * Function to initiate the PWM mode in Timer0
 */
void Timer0_PWM_Init(unsigned char set_duty_cycle)
{


	/*Set the initial value of Timer0 to 0*/
	TCNT0=0;
	/*when the speed of the Motor 100% so set the duty cycle =255 instead of duty cycle =256 */
	if (set_duty_cycle==100)
		{
			set_duty_cycle=255;
		}
	/*Equation that its input the percentage of speed of DC Motor to make the output the values that turn on the DC Motor */
		else
		{

			set_duty_cycle =(set_duty_cycle*((float)(64)/25));
		}
   /*Set Compare value */
  OCR0=set_duty_cycle;
  /*Configure the PB3 as output pin */
  GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);
  /*
   * configure timer control register
   * Fast PWM mode --> FOC0=0
   * Fast PWM mode --> WGM01=1 & WGM00=1
   * Clear OC0 when matches occur (non-inverted mode)-->COM00=0 & COM01=1
   * clock F_CPU/8 -->CS00=0 CS01=1 CS02=0
   */
  TCCR0=(1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS01);

}
