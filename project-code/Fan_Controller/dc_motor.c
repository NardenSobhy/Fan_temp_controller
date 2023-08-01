/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dc_motor.c
 *
 * Description: Source file for the DC Motor driver
 *
 * Author: Narden Sobhy Shaker
 *
 *******************************************************************************/

#include "dc_motor.h"
#include "gpio.h"
#include "pwm.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void DcMotor_Init(void){


	/* Configure the direction for pin0 & pin1 in PORTB as output pin */
	GPIO_setupPinDirection(DC_MOTOR_OUTPUT_PORT_ID ,DC_MOTOR_OUTPUT_1_PIN_ID ,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_OUTPUT_PORT_ID ,DC_MOTOR_OUTPUT_2_PIN_ID ,PIN_OUTPUT);

	/*Stop at the DC-Motor at the beginning*/
	GPIO_writePin(DC_MOTOR_OUTPUT_PORT_ID ,DC_MOTOR_OUTPUT_1_PIN_ID ,LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_OUTPUT_PORT_ID ,DC_MOTOR_OUTPUT_2_PIN_ID ,LOGIC_LOW);

}

void DcMotor_Rotate(DcMotor_State state,uint8 speed){


	Timer0_PWM_Init(speed);

	DC_MOTOR_OUTPUT_PORT &=0xFC;
	DC_MOTOR_OUTPUT_PORT |=state;
}
