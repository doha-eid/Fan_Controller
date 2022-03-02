/***********************************************************************************************************
 * Module :main
 *
 *File Name :main.c
 *
 *Description : Source file for the application of fan controller
 *      Author: Doha Eid
 **********************************************************************************************************/
#include"std_types.h"
#include"common_macros.h"
#include"lcd.h"
#include"DC_Motor.h"
#include"lm35_sensor.h"
#include "adc.h"

int main (void )
{
uint8 Temp,speed;
/*Initialize the LCD */
LCD_init();
/*Initialize the DC motor*/
DcMotor_Init();

ADC_ConfigType ADC_ptr = {INTERNAL,F_CPU_8};

	ADC_init(&ADC_ptr);/*Initialize the ADC */


	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_moveCursor(1,0);
	LCD_displayString("Temp =    C");
	while (1)
	{
		/* Display the temperature value every time at same position */
		Temp=LM35_getTemperature();
				LCD_moveCursor(0,7);
	/*if the temperature less than 30 c so turn off the fan
	 * stop the DC Motor
	 *  Display the temperature on the LCD
     */
		if (Temp<30)
		{
			speed=0;
			DcMotor_Rotate(Stop,speed);
			LCD_moveCursor(0,1);
			LCD_displayString("Fan is off ");
			LCD_moveCursor(1,7);
			LCD_intgerToString(Temp);
			LCD_displayCharacter(' ');

		}
		/*
		 * if the temperature more than or equal 30c && less than 60c so turn on the fan
		 * and make the DC Motor rotate with 25% of its max speed clock-wise
		 * Display the temperature on the LCD
		 */
		else if ((Temp>=30)&&(Temp<60))
		{
		speed=25;
		DcMotor_Rotate(Clock_Wise,speed);
			LCD_moveCursor(0,1);
			LCD_displayString("Fan is ON ");
			LCD_moveCursor(1,7);
			LCD_intgerToString(Temp);
			LCD_displayCharacter(' ');

		}
		/*
		 * if the temperature more than or equal 60c && less than 90c so turn on the fan
		 * make the DC Motor rotate with 50% of its max speed clock-wise
		 * Display the temperature on the LCD
		 */
		else if ((Temp>=60)&&(Temp<90))
		{
			speed=50;
			DcMotor_Rotate(Clock_Wise,speed);
			LCD_moveCursor(0,1);
			LCD_displayString("Fan is ON ");
			LCD_moveCursor(1,7);
			LCD_intgerToString(Temp);
			LCD_displayCharacter(' ');

		}
		/*
		 * if the temperature more than or equal 90c && less than 120c so turn on the fan
		 * make the DC Motor rotate with 75% of its max speed clock-wise
		 * Display the temperature on the LCD
		 */
		else if ((Temp>=90)&&(Temp<120))
		{
			speed=75;
			 DcMotor_Rotate(Clock_Wise,speed);
			LCD_moveCursor(0,1);
			LCD_displayString("Fan is ON ");
			LCD_moveCursor(1,7);
			LCD_intgerToString(Temp);
			LCD_displayCharacter(' ');

		}
		/*
		 * if the temperature more than or equal 120c so turn on the fan
		 * make the DC Motor rotate with 100% of its max speed clock-wise
		 * Display the temperature on the LCD
		 */
		else if (Temp>=120)
		{
			speed=100;
			DcMotor_Rotate(Clock_Wise,speed);
			LCD_moveCursor(0,1);
			LCD_displayString("Fan is ON ");
			LCD_moveCursor(1,7);
			LCD_intgerToString(Temp);
			LCD_displayCharacter(' ');



		}

	}

}

