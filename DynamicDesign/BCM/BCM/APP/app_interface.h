/*
 * app_interface.h
 *
 * Created: 5/25/2023 3:17:16 AM
 *  Author: Ahmed Hesham
 */ 


#ifndef APP_INTERFACE_H_
#define APP_INTERFACE_H_

#include "../ECUAL/led/led_interface.h"
#include "../SERV/bcm/bcm_interface.h"
#include "../LIB/std.h"

#define SIZE_OF_FIRST_INSTANCE		300


/**
 * \Syntax          : APP_init(void)
 * \Description     : Initializes Application
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 */
void APP_init(void);

/**
 * \Syntax          : APP_superLoop(void)
 * \Description     : Application's superloop where is dispatcher called
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 */
void APP_superLoop(void);

/**
 * \Syntax          : APP_saveReceivedTask(void)
 * \Description     : Task will be called when data is received
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 */
void APP_saveReceivedTask(void);

/**
 * \Syntax          : APP_dataSentTask(void)
 * \Description     : Task will be called when data is sent
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 */
void APP_dataSentTask(void);


#endif /* APP_INTERFACE_H_ */