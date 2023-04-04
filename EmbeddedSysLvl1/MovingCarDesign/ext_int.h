#ifndef EXT_INT_H_
#define EXT_INT_H_

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
// PORTS NUMBERS
#define INT0						0
#define INT1						1
#define INT2						2

// INTERRUPT ACCURENCE
#define LOW_LEVEL					1
#define ANY_CHANGE					2
#define FALLING_EDGE				3
#define RISING_EDGE					4

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum{
	E_OK,
	WRONG_INTERRUPT_NUMBER
}EN_intError_t;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

EN_intError_t EXT_INT_init 		(uint8_t intNumber);
void EXT_INT_setCallBackInt0 	(void (*funPtr) (void));
void EXT_INT_setCallBackInt1 	(void (*funPtr) (void));
void EXT_INT_setCallBackInt2 	(void (*funPtr) (void));

#endif /* EXT_INT_H_ */