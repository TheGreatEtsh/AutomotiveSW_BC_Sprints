#ifndef MOTOR_H_
#define MOTOR_H_

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
//PINS 
#define MOTOR_0_PORT	PWM_0_PORT
#define MOTOR_0_Pin		PWM_0_PIN
#define MOTOR_1_PORT	PWM_1_PORT
#define MOTOR_1_Pin		PWM_1_PIN

//DIRECTIONS
#define ACW				1
#define CW				0

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum{
	E_OK,
	INIT_ERROR,
	WRONG_DIRECTION,
	WRONG_SPEED,
	STARTING_ERROR,
	STOPPING_ERROR
	
}EN_motorError_t;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
EN_motorError_t MOTOR_init				(void);
EN_motorError_t MOTOR_setDirection		(uint8_t direction);
EN_motorError_t MOTOR_speed				(uint8_t setSpeed);
EN_motorError_t MOTOR_start				(void);
EN_motorError_t MOTOR_stop				(void);



#endif /* MOTOR_H_ */