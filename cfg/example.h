// Example Configuration.  See README.md for an explanation of option.
#pragma once
#ifndef CONFIGURED
#define CONFIGURED


/*
	Serial Settings
*/
//#define CONFIG_USE_SERIAL
//#define CONFIG_BAUD_RATE	9600

/*
	Rules and Initial State Settings
*/
//#define	CONFIG_USE_SWITCHES_FOR_SETTINGS
#define CONFIG_RULES_SURV	0b1100
#define CONFIG_RULES_BIRTH	0b1000
#define CONFIG_INITIAL_STATE	0b000111000


/*
	Delay Settings
*/
//#define	CONFIG_USE_ADC_FOR_DELAY_TIME
//#define CONFIG_DELAY_MIN		250
//#define	CONFIG_DELAY_MAX		5000
#define CONFIG_DELAY_MS 1000

/*
	Cell Neighbor Settings
*/
#define CONFIG_NEIGHBORS \
    {                \
        0b000011010, \
        0b000111101, \
        0b000110010, \
        0b011010011, \
        0b111101111, \
        0b110010110, \
        0b010011000, \
        0b101111000, \
        0b010110000, \
    }
#endif
