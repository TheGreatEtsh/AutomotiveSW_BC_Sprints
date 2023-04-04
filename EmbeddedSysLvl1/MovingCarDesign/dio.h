#ifndef DIO_H_
#define DIO_H_

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
// PORTS NUMBERS
#define PORT_A			'A'
#define PORT_B			'B'
#define PORT_C			'C'
#define PORT_D			'D'

// DIRECTIONS
#define INPUT			0
#define OUTPUT			1

// VALUES
#define LOW				0
#define HIGH			1

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum{
	E_OK,
	WRONG_PORT_NUMBER,
	WRONG_PIN_NUMBER,
	WRONG_DIRECTION,
	WRONG_VALUE
}EN_dioError_t;


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

EN_dioError_t DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction);	// Initialize dio direction

EN_dioError_t DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value);		// Write data to dio

EN_dioError_t DIO_toggle(uint8_t portNumber, uint8_t pinNumber);						// Toggle dio 

EN_dioError_t DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value);		// Read dio

#endif /* DIO_H_ */