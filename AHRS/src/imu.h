/******************************************************************************
* File Name: imu.h
* Version: 1.01.1
* Description: Header file per imu.c
*******************************************************************************/
/*******************************************************************************
* Author: Omar Cocchairella
*******************************************************************************/
/*******************************************************************************
* History
* 			DD.MM.YYYY     Version     Description
			22.01.2018     1.01        Revisione della versione di Sebastian Giles
* 										da parte di Omar Cocchairella.
			10.01.2019     1.01.1      Martin Breccia commento della versione
* 										di Omar Cocchairella.
*******************************************************************************/

#ifndef SRC_IMU_H_
#define SRC_IMU_H_

#include "stddef.h"
#include "eMPL/inv_mpu.h" //libreria Invensense adattata per renesas rx  // Invensense library adapted for renesas rx
#include "i2c.h"

typedef struct {
	float accRoll;
	float accPitch;
	float accYaw;
	float gyrRoll;
	float gyrPitch;
	float gyrYaw;
} IMU_raw;

typedef struct {
	uint16_t acc_sens;
	float gyr_sens;
} IMU_sens;

typedef struct {
	float accRoll;
	float accPitch;
	float accYaw;
	float gyrRoll;
	float gyrPitch;
	float gyrYaw;
} IMU_temp;

typedef struct{
	float Roll_Rad_Ref;
	float Pitch_Rad_Ref;
	float Yaw_Rad_Ref;
} IMU_rif;
//data reading method
// Metodo di lettura dei dati
int imu_read(IMU_raw*, IMU_sens*, IMU_temp*);

 /*******************************************************************************
 * Function name: imu_init
 * Description  : Inizializzazione del sistema IMU.
 * 				  IMU system initialitation.
 * Arguments    : (IMU_sens*) -imu_sens puntatore alla struttura IMU_sens
 * 				  (IMU_sens*) -imu_sens pointer to IMU_sens struct
 * Return value : hex - 0x0 se tutto ok
 * 				  hex - 0x0 if all right
 *
 * 				  hex - 0x1 errore inizializzazione i2c.
 * 				  hex - 0x1 i2c error initialitation.
 *
 * 				  hex - 0x2 errore inizializzazione mpu_6050.
 * 				  hex - 0x2 mpu_6050 error inizialitation.
 *
 * 				  hex - 0x3 errore nel settaggio dei sensori dell'mpu.
 * 				  hex - 0x3 mpu sensors setting error.
 *
 * 				  hex - 0x4 errore nel settaggio della frequenza di campionamnto.
 * 							 del mpu_6050.
 * 				  hex - 0x4 mpu_6050 sampling frequency setting error
 *******************************************************************************/
int imu_init();

 /*******************************************************************************
 * Function name: imu_read
 * Description  : Metodo di lettura dei dati.
 * 				  Data reading method.
 * Arguments    : (IMU_raw*, IMU_sens*, IMU_temp*)
 * 					-imu_raw puntatore alla struttura IMU_raw che contiene dati 
 * 						grezzi del imu.
 * 					-imu_sens puntatore alla struttura IMU_sens che contiene dati
 * 						sensore imu.
 * 					-imu_temp puntatore alla struttura IMU_temp
 * 						contiene dati rielaborati.
 *
 * 					(IMU_raw*, IMU_sens*, IMU_temp*)
 * 						-imu_raw pointer to IMU_raw struct that contains IMU raw data.
 * 						-imu_sens pointer to IMU_sens struct that contains IMU data.
 * 						-imu_temp pointer to IMU_temp struct that contains reworked data.
 *
 * Return value : int - 0 se tutto ok.
 * 				  int - 0 if all right.
 *******************************************************************************/
int imu_read(IMU_raw*, IMU_sens*, IMU_temp*);




#endif /* SRC_IMU_H_ */
