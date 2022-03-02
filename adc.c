/**********************************************************************************************************
 * Module :ADC
 *
 *File Name:ADC.C
 *
 * Description:Source file for the ADC driver
 *
 * Author:Doha Eid
 **********************************************************************************************************/
#include"common_macros.h"
#include"adc.h"
#include<avr/io.h>
/***********************************************************************************************************
 *                                    Function Definitions                                                 *
 **********************************************************************************************************/
/*
 * Description:
 * Function responsible for initialize ADC
 */
void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	ADMUX=(ADMUX &0x3F)|((Config_Ptr->ref_volt)<<6);/*choose the volt reference , internal voltage Vref=2.56  */
	SET_BIT(ADCSRA,ADEN);/*Enable ADC E=1*/
	ADCSRA = (ADCSRA & 0xF8) | ((Config_Ptr->Prescaler) );/*choose the Prescaler */
}
/*
 * Description:
 * Function to read analog data from ADC channel and data to digital
 */
uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &=0x07;
	ADMUX=(ADMUX & (0XE0));
	ADMUX = (ADMUX ) | channel_num ;
	SET_BIT(ADCSRA,ADSC);/*Start conversion write '1' to ADSC*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
		SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
		return ADC; /* Read the digital value from the data register */
}
