/*
 * us_interface.h
 *
 *  Created: 8:50 PM Saturday, May 20, 2023 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef US_INTERFACE_H_
#define US_INTERFACE_H_


/** Typedefs **/
typedef struct{
    u8 portUsed;
    u8 triggerPinNumber;
    u8 echoPinNumber;
}st_US_config_t;

/** Functions' Prototypes **/
/**
 | Syntax          : US_init (void)
 | Description     : Initializes UltrasSonic  
 | Sync\Async      : Synchronous
 | Reentrancy      : Reentrant
 | Parameters (in) : None
 | Parameters (out): None
 | Return value:   : en_US_error_t		US_OK = 0
 |										US_NOK = 1
 |*/
en_US_error_t US_init (void);
/**
 |
 | Syntax          : US_getDistance (u16 *u16_a_distance)
 | Description     : gets the distance between the object and the obstacle  
 | Sync\Async      : Synchronous
 | Reentrancy      : Reentrant
 | Parameters (in) : None
 | Parameters (out): u16*			       	u16_a_distance
 | Return value:   : en_US_error_t		    US_OK = 0
 |											US_NOK = 1
 |*/
en_US_error_t US_getDistance (u16 *u16_a_distance);

#endif /* US_INTERFACE_H_ */