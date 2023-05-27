/*
 * led.h
 *
 * Created: 4/3/2023 5:33:17 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/dio/dio_interface.h"
#include "led_cfg.h"
typedef enum ledErrors
{
	LED_OK = 0,
	LED_WRONG_LED_PORT,
	LED_WRONG_LED_PIN
}enu_LED_status_t;

typedef struct 
{
	uint8_t uint8_ledID;
	uint8_t uint8_ledPort;
	uint8_t uint8_ledPin;
}str_LED_config_t;

/**
 * \Syntax          : LED_init(void)
 * \Description     : Initializes LED pins’ direction as output
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : enu_LED_status_t	LED_OK= 0,
 *										LED_WRONG_LED_PORT
 *										LED_WRONG_LED_PIN
 */
enu_LED_status_t LED_init(void);

/**
 * \Syntax          : LED_on(uint8_t uint8_ledID)
 * \Description     : Turns on a specific LED
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : uint8_ledID
 * \Parameters (out): None
 * \Return value:   : enu_LED_status_t	LED_OK= 0,
 *										LED_WRONG_LED_PORT
 *										LED_WRONG_LED_PIN
 */
enu_LED_status_t LED_on(uint8_t uint8_ledID);

/**
 * \Syntax          : LED_off(uint8_t uint8_ledID)
 * \Description     : Turns off a specific LED
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : uint8_ledID
 * \Parameters (out): None
 * \Return value:   : enu_LED_status_t	LED_OK= 0,
 *										LED_WRONG_LED_PORT
 *										LED_WRONG_LED_PIN
 */
enu_LED_status_t LED_off(uint8_t uint8_ledID);

/**
 * \Syntax          : LED_toggle(uint8_t uint8_ledID)
 * \Description     : Toggles a specific LED
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : uint8_ledID
 * \Parameters (out): None
 * \Return value:   : enu_LED_status_t	LED_OK= 0,
 *										LED_WRONG_LED_PORT
 *										LED_WRONG_LED_PIN
 */
enu_LED_status_t LED_toggle(uint8_t uint8_ledID);


#endif /* LED_H_ */