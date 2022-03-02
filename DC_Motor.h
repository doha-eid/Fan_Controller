/*
 * Module:DC_Motor
 *
 *File Name : DC_Motor.h
 *
 * Description:Header file for DC Motor driver
 *      Author: Doha Eid
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include"std_types.h"
/***********************************************************************************************************
 *                                          Definitions                                                    *
 **********************************************************************************************************/
#define DC_MOTOR_PORT               PORTB_ID
#define DC_MOTOR_FIRST_PIN          PIN0_ID
#define DC_MOTOR_SECOND_PIN         PIN1_ID

/***********************************************************************************************************
 *                                        Type Deceleration                                               *
 **********************************************************************************************************/
typedef enum
{
	Stop,Clock_Wise,Anti_Clock_Wise
}DcMotor_state;

/***********************************************************************************************************
 *                                     Function Prototypes                                                *
 **********************************************************************************************************/
/*
 * Description :
 * Function responsible for initiate the DC Motor
 */
void DcMotor_Init(void );
/*
 * Description :
 * Function responsible for rotate the Dc Motor CW, ACW , Stop
 */
void DcMotor_Rotate(DcMotor_state state , uint8 speed);
#endif /* DC_MOTOR_H_ */
