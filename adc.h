/***********************************************************************************************************
 * Module :ADC
 *
 *File Name : ADC.H
 *
 * Description : Header file for the ADC driver
 *
 * Author: Doha Eid
 **********************************************************************************************************/

#ifndef ADC_H_
#define ADC_H_
#include"std_types.h"

/***********************************************************************************************************
 *                                         Definitions                                                    *
 **********************************************************************************************************/
#define ADC_MAXIMUM_VALUE                 1023
#define ADC_REF_VOLT_VALUE                2.56



/***********************************************************************************************************
 *                                     Type Deceleration                                                   *
 **********************************************************************************************************/
typedef enum
{
	AREF,AVCC,Reserved,INTERNAL
}ADC_RefrenceVoltage;
typedef enum
{
	No_prescaler,F_CPU_2,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;
typedef struct
{
	ADC_RefrenceVoltage ref_volt;
	ADC_Prescaler       Prescaler;
}ADC_ConfigType;

/***********************************************************************************************************
 *                                     Function prototypes                                                *
 **********************************************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr);


uint16 ADC_readChannel(uint8 channel_num);





#endif /* ADC_H_ */
