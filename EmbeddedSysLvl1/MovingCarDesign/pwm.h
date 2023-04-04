#ifndef PWM_H_
#define PWM_H_

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
// PORTS NUMBERS
#define PWM_0_PORT
#define PWM_1_PORT
#define PWM_2_PORT

// PIN NUMBERS
#define PWM_0_PIN
#define PWM_1_PIN
#define PWM_2_PIN

// PWM WAVEFORM
#define FAST_PWM			0
#define PHASE_CORRECT_PWM 	1


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum{
	E_OK,
	WRONG_PORT_NUMBER,
	WRONG_PIN_NUMBER,
	WRONG_DUTY_CYCLE
}EN_pwmError_t;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

EN_pwmError_t PWM_init				(uint8_t pwmPort, uint8_t pwmPin);
EN_pwmError_t PWM_setDutyCycle		(uint8_t pwmPort, uint8_t pwmPin, uint8_t desiredDutyCycle);
EN_pwmError_t PWM_start				(uint8_t pwmPort, uint8_t pwmPin);   
EN_pwmError_t PWM_stop				(uint8_t pwmPort, uint8_t pwmPin);


#endif /* PWM_H_ */