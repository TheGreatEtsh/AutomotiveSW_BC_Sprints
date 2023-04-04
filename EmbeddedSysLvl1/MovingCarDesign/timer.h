#ifndef TIMER_H_
#define TIMER_H_

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
// PORTS NUMBERS
#define TIMER0			0
#define TIMER1			1
#define TIMER2			2

// TIMER WAVEFORM
#define OV_PWM			0
#define CTC_PWM 		1

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum{
	E_OK,
	WRONG_TIMER_NUMBER,
	WRONG_DESIRED_TIME
}EN_timerError_t;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

EN_timerError_t TIMER_init				(uint8_t timerUsed);
EN_timerError_t TIMER_setTime			(uint8_t timerUsed, uint32_t desiredTime);
EN_timerError_t TIMER_start				(uint8_t timerUsed);							
EN_timerError_t TIMER_stop				(uint8_t timerUsed);
void 			TIMER_setCallBack		(void (*funPtr) (void));



#endif /* TIMER_H_ */