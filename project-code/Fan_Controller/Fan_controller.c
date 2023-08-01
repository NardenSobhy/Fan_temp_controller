/*
 ================================================================================================
 Name        : Fan_controller.c
 Author      : Narden Sobhy Shaker
 Description : Control a fan which is automatically turned ON or OFF according to the temperature.
 Date        : 8/10/2022
 ================================================================================================
*/


#include "lcd.h"
#include "lm35_sensor.h"
#include "dc_motor.h"
#include <avr/io.h>
#include "adc.h"



int main(){

	uint8 temp;
	ADC_ConfigType ADC_Config={AREF,PRESCALER_8};
	SREG  |= (1<<7);
	DcMotor_Init();
	LCD_init();
	ADC_init(& ADC_Config);
	LCD_displayString("Fan is OFF");
	LCD_displayStringRowColumn(1, 0, "Temp =    C");

	while(1){
		temp = LM35_getTemperature();


		 if(temp>=120){

			DcMotor_Rotate(CW,100);
			LCD_displayStringRowColumn(0, 7, "ON ");

		}else if(temp>=90){

			DcMotor_Rotate(CW,75);
			LCD_displayStringRowColumn(0, 7, "ON ");

		}else if(temp>=60){

			DcMotor_Rotate(CW,50);
			LCD_displayStringRowColumn(0, 7, "ON ");

		}else if(temp>=30){

			DcMotor_Rotate(CW,25);
			LCD_displayStringRowColumn(0, 7, "ON ");

		}else{

			DcMotor_Rotate(STOP,0);
			LCD_displayStringRowColumn(0, 7, "OFF ");

		}

		LCD_moveCursor(1,7);
			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				/* In case the digital value is two or one digits print space in the next digit place */
				LCD_displayCharacter(' ');
			}

	}
}

