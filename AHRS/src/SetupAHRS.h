/******************************************************************************
* File Name: SetupAHRS.h
* Version: 1.0
* Description: Routine di setup e lettura per A.H.R.S.
*******************************************************************************/
/*******************************************************************************
 * Author: Ragaini Davide
 *******************************************************************************/
/*******************************************************************************
* History
* 			DD.MM.YYYY     Version     Description
*			13.04.2019     1.0         First Release.
*******************************************************************************/



#ifndef SRC_SETUPAHRS_H_
#define SRC_SETUPAHRS_H_

/******************************************************************************
Includes   <System Includes> , "Project Includes"
*******************************************************************************/
#include <stdio.h>
#include "platform.h"
#include "imu.h"
#include "mag.h"
#include "AHRS.h"


/********************************************************************************
 * typedef struct AHRS_out
 * Al fine di facilitare le inizializzazioni e le chiamate a funzioni, abbiamo
 * creato la struttura dati AHRS_out.
 * Dichiarando un istanza di questa struttura, si dichiarano automaticamente
 *  anche le strutture dati necessarie all'algoritmo AHRS.
 * Basta diciarare una istanza di questa struttura nel main e passarla come
 * riferimeno alle funzioni.
 *
 * We created AHRS_out data struct for simplified function initialitations and calls.
 * With istance declaration of this structure, we also automatically declare
 * data struct necessary to AHRS algorithm.
 * Need only to declare struct istance in the main and pass her as reference to functions.
 *
 * IMPORTANTE!
 * Da non confondere con AHRS_data che contiene i dati relativi all'orientamento.
 * ATTENTION!
 * Not to confuse with AHRS_data which has orientation data.
 ********************************************************************************/
typedef struct{
	MAG_data mag;
	IMU_sens sens;
	IMU_raw raw;
	IMU_temp temp;
	AHRS_data ahrs_data;
}AHRS_out;


/***************************************************************************************
 * Function name: Setup_MARG
 * Description  : Esegue l'inizializzazione dello schermo, CMT, accelerometro, giroscopio
 * 				  e magneometro; infine esegue la calibrazione del magnetometro.
 * 				  Run display, CMT, accelerometer, gyroscope and magnetometer initialitation;
 * 				  in the end run magnetometer calibration.
 * Arguments    : Puntatore alla struttura dati AHRS_out.
 * 				  AHRS_out data struct pointer.
 * Return Value : Non restituisce nulla, ma stampa i parametri della calibrazione su schermo.
 * 				  Return nothing, it only prints calibration on the display.
 **************************************************************************************/
void Setup_MARG(AHRS_out* ahrs);


/***************************************************************************************
 * Function name: Read_MARG
 * Description  : Questa funzione legge i dati dall'IMU, magnetometro, li filtra e aggiorna
 * 				  la struttura dati AHRS_data.
 * 				  This function reads IMU, magnetometer data, filters them and updates AHRS_data
 * 				  data struct.
 * Arguments    : Puntatore alla struttura dati AHRS_out.
 * 				  AHRS_out data struct pointer.
 * Return value : Non restituisce niente ma aggiorna i dati della struttura dati AHRS_data.
 * 				  Return nothing but it updates AHRS_outs data struct data.
 **************************************************************************************/
void Read_MARG(AHRS_out* ahrs);


#endif /* SRC_SETUPAHRS_H_ */
