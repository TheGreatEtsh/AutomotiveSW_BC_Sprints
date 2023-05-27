/*
 * bcm_cfg.c
 *
 * Created: 5/23/2023 9:21:40 PM
 *  Author: Ahmed Hesham
 */ 

#include "bcm_interface.h"
#include "bcm_cfg.h"


const str_BCM_config_t cst_str_BCM_config [BCM_NUMBER_OF_CHANNELS] =
{
    /*DATA_TYPE		BUS_ID*/  
	{ BCM_EXCHANGE, BCM_UART},
	{ BCM_DISPLAY,	BCM_SPI},
	{ BCM_STORE,	BCM_I2C}
};
