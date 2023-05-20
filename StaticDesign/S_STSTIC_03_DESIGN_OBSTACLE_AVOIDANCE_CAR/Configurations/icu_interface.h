/*
 * icu_interface.h
 *
 * Created: 8:50 PM Saturday, May 20, 2023 PM
 *  Author: Ahmed Hesham
 */

#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_


/** OPTIONS **/


typedef struct{
    u8 capturePort;
    u8 capturePin;
    u8 interruptNo;
}st_ICU_capturePin_t;

typedef enum{
    ICU_OK,
    ICU_ERROR
}en_ICU_error_t;

/**
 |
 | Syntax          : ICU_init (void)
 | Description     : Initializes ICU  
 | Sync\Async      : Synchronous
 | Reentrancy      : Reentrant
 | Parameters (in) : None
 | Parameters (out): None
 | Return value:   : en_ICU_error_t		ICU_OK = 0
 |						ICU_NOK = 1
 |*/
en_ICU_error_t ICU_init (void);

/**
 |
 | Syntax          : ICU_getElapsedTime (u32 *u32_a_elapsedTime)
 | Description     : gets the value of the elapsed time from the start to end of signal   
 | Sync\Async      : Synchronous
 | Reentrancy      : Reentrant
 | Parameters (in) : None
 | Parameters (out): u32*				u32_a_elapsedTime
 | Return value:   : en_ICU_error_t		ICU_OK = 0
 |							ICU_NOK = 1
 |*/
en_ICU_error_t ICU_getElapsedTime (u32 *u32_a_elapsedTime);

/**
 |
 | Syntax          : ICU_task (void)
 | Description     : ICU task sent to interrupt callback function  
 | Sync\Async      : Synchronous
 | Reentrancy      : Reentrant
 | Parameters (in) : None
 | Parameters (out): None	
 | Return value:   : None	
 |*/

void ICU_task (void);

#endif /* ICU_INTERFACE_H_ */