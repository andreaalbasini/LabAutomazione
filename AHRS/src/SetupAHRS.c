/******************************************************************************
 * File Name: SetupAHRS.c
* Version: 1.0
* Description: Routine di setup e lettura per A.H.R.S.
*******************************************************************************/
/*******************************************************************************
* Author: Ragaini Davide
 *******************************************************************************/
/***********************************************************************************************
* History
* 			DD.MM.YYYY     Version     Description
*			13.04.2019     1.0         First Release.
*			16.01.2020     1.01.01.1   Revisione da parte di Raiola Corrado, Costea Marian Ioan,
* 			                           Cafaro Adolfo Damiano, Albasini Andrea
************************************************************************************************/



#include "SetupAHRS.h"
#include "platform.h"

//setup IMU


void Setup_MARG(AHRS_out* ahrs)
{
	char msg[12];

	lcd_initialize();
	lcd_clear();
	lcd_display(LCD_LINE1,"************");
	lcd_display(LCD_LINE2," PRESS SW1  ");
	lcd_display(LCD_LINE3,"  FOR NEW   ");
	lcd_display(LCD_LINE4,"CALIBRATION ");
	lcd_display(LCD_LINE6," PRESS SW2  ");
	lcd_display(LCD_LINE7,"FOR DEFAULT ");
	lcd_display(LCD_LINE8,"  PARAMS    ");




	// Timer,imu and magnetometer initialization
	CMT_init();
	imu_init(&ahrs->sens);
	mag_init(&ahrs->mag);



	 // it asks to push sw1 or sw2 based on user choise according to wanted parameters displayed
	while( PORT4.PIDR.BIT.B0 && PORT4.PIDR.BIT.B1){

		//both registers are at 1, so it stays inside cycle until user press one
		//of the sw, when it happens the programme gets out from the cycle and the right condition is choose.


	}


//if sw1 is pushed it will start a new calibration
	if(!(PORT4.PIDR.BIT.B0)){

		lcd_initialize();
			lcd_clear();


		lcd_display(LCD_LINE1," IMU SETUP ");
		lcd_display(LCD_LINE2," IN CORSO ");

		lcd_display(LCD_LINE4,"Calibrazione");
		lcd_display(LCD_LINE5,"Magnetometro");

		calibrationYPR(msg, &ahrs->mag);// new calibration

	}
	else if (!(PORT4.PIDR.BIT.B1))        //if sw2 is pushed  default parameters will be selected
		calibrationYPR1(msg, &ahrs->mag);


	else calibrationYPR1(msg, &ahrs->mag); // if there are some errors, default parameters
										   //are select

}

// Reading function of the filtered MARG data

void Read_MARG(AHRS_out* ahrs)
{
	imu_read(&ahrs->raw, &ahrs->sens, &ahrs->temp);
	mag_read(&ahrs->mag);
	getYPR(&ahrs->mag, &ahrs->temp, &ahrs->ahrs_data);
}

