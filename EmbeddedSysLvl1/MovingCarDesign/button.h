#ifndef BUTTON_H_
#define BUTTON_H_

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define BUTTON_0_PORT	PORT_B
#define BUTTON_0_Pin	0
#define BUTTON_1_PORT	PORT_B
#define BUTTON_1_Pin	1

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum{
	E_OK,
	BUTTON_INIT_ERROR,
	BUTTON_READ_ERROR
}EN_buttonError_t;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

EN_buttonError_t BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);

EN_buttonError_t BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *buttonState);


#endif /* BUTTON_H_ */