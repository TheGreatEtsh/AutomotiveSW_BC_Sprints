/*
 * timer.h
 *
 * Created: 4/5/2023 12:38:41 AM
 *  Author: Ahmed Hesham
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../registers.h"
#include "../../Service/BitMath.h"
#include "../interrupts.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
// TIMER NUMBERS
#define TIMER_0									0
#define TIMER_1									1
#define TIMER_2									2



// TIMER WAVEFORM TYPES
#define OV_TIMER								0
#define CTC_TIMER								1

// PRESCALER OPTIONS
#define NO_CLK									0
#define PRESCLNG_1								1
#define PRESCLNG_8								8
#define PRESCLNG_64								64
#define PRESCLNG_256							256
#define PRESCLNG_1024							1024
#define XCK_FLNG_EDGE							10
#define XCK_RSNG_EDGE							15

/******************************************_CONFIGURATIONS_***************************************/
/*****************************************_TIMER_MODE_USED_***************************************/

#define TIMER_0_MODE							CTC_TIMER
#define TIMER_1_MODE
#define TIMER_2_MODE							CTC_TIMER
/*****************************************_PRESCALER_USED_***************************************/
#define TIMER_0_PRESCALER						PRESCLNG_256
#define TIMER_1_PRESCALER						PRESCLNG_256
#define TIMER_2_PRESCALER						PRESCLNG_256

/**************************************_CLOCK_FREQUENCY_USED_************************************/
#define XTAL_FREQ								16

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum timerError{
	TIMER_OK,
	WRONG_TIMER_USED,
	WRONG_DESIRED_TIME
	}EN_timerError_t;


EN_timerError_t TIMER_init(uint8_t timerUsed);
EN_timerError_t TIMER_setTime(uint8_t timerUsed, uint32_t desiredTime);
EN_timerError_t TIMER_start(uint8_t timerUsed);
EN_timerError_t TIMER_stop(uint8_t timerUsed);
void			TIMER_setCallBack(uint8_t timerUsed, void (*funPtr)(void));



#endif /* TIMER_H_ */