/***************************************************************************
* Implementation of Madgwick's IMU and AHRS algorithms.
* See: http://www.x-io.co.uk/node/8#open_source_ahrs_and_imu_algorithms
*
* Date			Author          Notes
* 29/09/2011	SOH Madgwick    Initial release
* 02/10/2011	SOH Madgwick	Optimized for reduced CPU load
* 19/02/2012	SOH Madgwick	Magnetometer measurement is normalized
**************************************************************************/
/*******************************************************************************
* History
* 			DD.MM.YYYY     Version     Description
*			22.01.2018     1.01        Revisione della versione di Sebastian Giles
* 										da parte di Omar Cocchairella.
*			10.01.2019     1.01.1      Ragaini Davide commento della versione
* 										di Omar Cocchairella.
* 			16.01.2020     1.01.01.1   Revisione da parte di Raiola Corrado, Costea Marian Ioan,
* 			                           Cafaro Adolfo Damiano, Albasini Andrea
*******************************************************************************/



#ifndef AHRS_h
#define AHRS_h

#include <imu.h>
#include <math.h>
#include <mathf.h>
#include <stdio.h>
#include "platform.h"
#include "mag.h"

/********************
 * Struttura dati contenente i dati filtrati degli angoli di Tait-Bryan e delle velocità angolari, sia in gradi che in radianti.
	Data struct whitch contains filtered data of Tait-Bryan angles and angular speeds, in degrees and in radians


 ********************/

typedef struct{
	float RollRad;        // Corrisponde all'uscita in radianti dell'asse x di AHRS
						  // Variable in radiants of the AHRS x axis(Angle)
	float PitchRad;       // Corrisponde all'uscita in radianti dell'asse y di AHRS
						  //Variable in radiants of the AHRS y axis(Angle)
	float YawRad;         // Corrisponde all'uscita in radianti dell'asse z di AHRS
	                      //Variable in radiants of the AHRS z axis(Angle)
	float RollDeg;        // Corrisponde all'uscita in gradi dell'asse x di AHRS
	                      //Variable in degrees of the AHRS x axis(Angle)
	float PitchDeg;       // Corrisponde all'uscita in gradi dell'asse y di AHRS
	                      //Variable in degrees of the AHRS y axis(Angle)
	float YawDeg;         // Corrisponde all'uscita in gradi dell'asse z di AHRS
	                      //Variable in degrees of the AHRS z axis(Angle)
	float omegaRollRad;        // Corrisponde all'uscita in radianti dell'asse x di AHRS (velocità angolare)
	                           //Variable in radiants of the AHRS x axis(angular speed)
	float omegaPitchRad;       // Corrisponde all'uscita in radianti dell'asse y di AHRS (velocità angolare)
	                           //Variable in radiants of the AHRS y axis(angular speed)
	float omegaYawRad;         // Corrisponde all'uscita in radianti dell'asse z di AHRS (velocità angolare)
	                           //Variable in radiants of the AHRS z axis(angular speed)
	float omegaRollDeg;        // Corrisponde all'uscita in gradi dell'asse x di AHRS (velocità angolare)
	                           //Variable in degrees of the AHRS x axis(angular speed)
	float omegaPitchDeg;       // Corrisponde all'uscita in gradi dell'asse y di AHRS (velocità angolare)
	                           //Variable in degrees of the AHRS y axis(angular speed)
	float omegaYawDeg;         // Corrisponde all'uscita in gradi dell'asse z di AHRS (velocità angolare)
	                           //Variable in degrees of the AHRS z axis(angular speed)
}AHRS_data;

/***************************************************************************************
 * Function name: setAHRSFrequency
 * Description: Il filtro ha bisogno di sapere la frequenza con cui sarà chiamata la funzione
				madgwickFilterUpdate(). Prima di tutto va impostato questo valore.
				Filter needs to know the call's frequency of the madgwickFilterUpdate() function.
				First thing to do is to set this value.
 **************************************************************************************/
void setAHRSFrequency(float f);

/***************************************************************************************
 * Function name: madgwickFilterUpdate
 * Description: Questa funzione ricalcola l'assetto facendo uso di nuovi dati forniti dall'IMU.
				Per avere una buona stima dell'assetto è ideale chiamare questa funzione con la
				frequenza più alta possibile, dalla funzione setAHRSFrequency.
 * 				This function ricalculates setup with new IMU's data. If we want
 * 				a good setup estimate is recommended to call this function with the highest
 * 				possible frequency, from setAHRSFrequency function.
 * Return value:None.
 **************************************************************************************/
void madgwickFilterUpdate(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz);

/***************************************************************************************
 * Function name: getAHRS
 * Description: Questa funzione ricava gli angoli di Tait-Bryan.
				I valori vengono scritti nelle variabili passate per riferimento.
				Questa funzione può essere chiamata con una frequenza più bassa di quella con
				cui viene aggiornato il filtro, per esempio alla frequenza dell'algoritmo di
				controllo.
				This function gets Tait-Bryan's angles.
				it writes the values in the variables, passed by reference.
				This function can be called with a lower frequency than filter update frequency,
				for example we can use control algorithm frequency



 * Arguments    : Puntatori a float pitch, yaw e roll.
 * 				  Float pitch, yaw and roll pointers.
 * Return value : None.
 **************************************************************************************/
void getAHRS(float* pitch, float* yaw, float* roll);

/***************************************************************************************
 * Function name: getQuat
 * Description  : Assegnamento dei quaternioni.
 * 				  Quaternions assignment
 * Return value : None
 **************************************************************************************/
void getQuat(float* qa, float* qb, float* qc, float* qd);

/***************************************************************************************
 * Function name: getYPR
 * Description  : Trasforma le misurazioni del MARG in quaternioni e ne restituisce i dati
 * 				  in gradi e in radianti nella struttura dati AHRS_data.
 * 				  It transforms MARG measurments from quaternions to degrees and radiants data
 * 				  in the AHRS_data data struct.
 * Arguments    : Puntatori a struttura dati MAG_data, IMU_temp e AHRS_data
 * 				  MAG_data, IMU_temp and AHRS_data data struct pointers.
 * Return value : None.
 **************************************************************************************/
void getYPR(MAG_data*, IMU_temp*, AHRS_data*);


/***************************************************************************************
 * Function name: calibrationYPR

 * Description  : Funzione di calibrazione del magnetometro e stampa su schermo dei parametri;
 * 				  al suo termine si prema SW1 per continuare.
 * 				  Magnetometer calibration function. It prints parameters on the display;
 * 				  in the end press sw1 to continue.
 * Arguments    : Ammette puntatore a char e puntatore a struttura dati AHRS.
 * 				  Allows char pointer and AHRS data struct pointer
 * Return value : Restituisce su schermo i dati della calibrazione.
 * 				  Returns on display the calibration data.

 **************************************************************************************/
void calibrationYPR(char*, MAG_data*);



void calibrationYPR(char*, MAG_data*);
/***************************************************************************************

 * Function name: calibrationYPR1
 * Description  : Funzione di calibrazione del magnetometro e stampa su schermo dei parametri;
 * 				  al suo termine si prema SW1 per continuare.
 * 				  Magnetometer calibration function. It prints parameters on display;
 * 				  in the end press sw1 to continue
 * Arguments    : Ammette puntatore a char e puntatore a struttura dati AHRS.
 *                Allows char pointer and AHRS data struct pointer
 * Return value : Restituisce su schermo i dati della calibrazione di default.
 *				  Returns on display the default calibration data.
 *
 ***************************************************************************************/
void calibrationYPR1(char*, MAG_data*);


#endif
