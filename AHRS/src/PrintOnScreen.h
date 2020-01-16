/******************************************************************************
* File Name: PrintOnScreen.h
* Version: 1.0
* Description: Stampa su schermo integrato al microcontrollore dei dati.
*				Non è necessaria al fine del sistema di orientamento.
*				Da utilizzare in caso di test del codice sistema di orientamento.
*******************************************************************************/
/*******************************************************************************
 * Author: Ragaini Davide
 *******************************************************************************/
/*******************************************************************************
* History
*			DD.MM.YYYY     Version     Description
*			13.03.2019     1.0         First Release.
*******************************************************************************/



#ifndef SRC_PRINTONSCREEN_H_
#define SRC_PRINTONSCREEN_H_

/******************************************************************************
Includes   <System Includes> , "Project Includes"
*******************************************************************************/
//#include "platform.h"
#include "mag.h"
#include "AHRS.h"
#include "SetupAHRS.h"


/***************************************************************************************
 * Function name: Print_ABS
 * Description: Stampa su schermo integrato il parametro ABS (si rimanda alla teoria AHRS).
 * 				Fornisce un indicazione della validità della precisione del magnetometro.
 * 				Valore ottimo è il più vicino possibile a 1.
 * 				Prints parameter abs on display (ahrs theory).
 * 				gives magnetometer precision validity indication.
 * 				The value nearest to 1 is the optimal value.
 * Arguments: Puntatore alla struttura MAG_data
 * 			  MAG-data struct pointer
 * Return value: Stampa sulla prima riga.
 * 				 Prints first line
 **************************************************************************************/
void Print_ABS(AHRS_out*);


/***************************************************************************************
 * Function name: Print_Angoli
 * Description: Stampa su schermo integrato gli angoli in gradi.
 * 				Prints angles in degrees on display
 * Arguments: Puntatore alla struttura AHRS_data.
 * 			  AHRS_data struct pointer
 * Return value: Stampa su righe 3, 4 e 5.
 * 				 Prints third, forth and fifth line
 **************************************************************************************/
void Print_Angoli(AHRS_out*);


/***************************************************************************************
 * Function name: Print_VelAng
 * Description: Stampa su schermo integrato le velocità angolari in gradi.
 * 				Prints angular speed in degrees on display
 * Arguments: Puntatore alla struttura AHRS_data.
 * 			  AHRS_data struct pointer.
 * Return value: Stampa su righe 6, 7 e 8.
 * 				 Prints sixth, seventh and eighth line.
 **************************************************************************************/
void Print_VelAng(AHRS_out*);

/***************************************************************************************
 * Function name: RealTimeChart
 * Description  : Aggiorna le variabili dichiarate globalmente, per la funzionalità di debug RealTime-Chart.
 * 				  Debug RealTime-Chart function updates globals variables
 * Arguments    : Puntatore alla struttura AHRS_data.
 *                AHRS_data struct pointer.
 * Return value : None.
 **************************************************************************************/
void RealTimeChart(AHRS_out*);

/***************************************************************************************
 * Print_Temp
 * Description  : Stampa su schermo integrato le velocità angolari della struttura dati imu_temp.
 * 				  Prints imu_temp data struct angular speed on display.
 * Arguments    : Puntatore alla struttura AHRS_data.
 * 				  AHRS_data struct pointer.
 * Return value : Stampa su righe 6,7 e 8.
 *                Prints sixth, seventh and eighth line
 **************************************************************************************/
void Print_Temp(AHRS_out*);

#endif /* SRC_PRINTONSCREEN_H_ */
