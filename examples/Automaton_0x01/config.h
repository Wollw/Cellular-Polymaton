#ifndef CONFIG_H
#define CONFIG_H
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include "defines.h"

/* The number of overflows before the world should be updated
 * defaults to 1 */
#define CFG_WAIT_COUNT	4

/* Comment this out of you don't want to use the shift registers. */
#define	CFG_ENABLE_SHIFT
/* The ports and pins used for shifting bits out to the shift registers. */
#define	CFG_SHIFT_REGISTER_PIN_COUNT	32
#define CFG_SHIFT_DDR					DDRB
#define	CFG_SHIFT_PORT					PORTB
#define	CFG_SHIFT_RCLK					PIN0
#define	CFG_SHIFT_SER					PIN1
#define	CFG_SHIFT_SRCLK					PIN2

/* Comment this out of you don't want to use the serial port. */
//#define CFG_ENABLE_USART
/* The baudrate for serial transfer. */
#define CFG_USART_BAUDRATE		9600
/* What to output for set and cleared bits */
#define	CFG_USART_SET_BIT_MSG	"[46m [49m"
#define	CFG_USART_CLR_BIT_MSG	"[44m [49m"

/* The number of cells in the automaton */
#define CFG_CELL_COUNT		31
/* The most neighbors a cell has */
#define CFG_MOST_NEIGHBORS	12
/* The rules used for cells that are alive and cells that are dead.
 * See README.md for a detailed description of how these work.*/
struct rules {
	bits_t live :CFG_MOST_NEIGHBORS+1;
	bits_t dead :CFG_MOST_NEIGHBORS+1;
} const cfg_rules = {
	0b0000000010010,
	0b0000001010110
};
/* The configurations for each cell in the automaton.
 * See README.md for a detailed description of how this works.*/
struct cells {
	bits_t neighbors :CFG_CELL_COUNT;
	bool initial_state :1;
} const cfg_cells[] = {
	{ 0b0000000000000000001111111111110,	LIVE },
	{ 0b0000001100000001100000110000001,	LIVE },
	{ 0b0001100000000011000001100000001,	LIVE },
	{ 0b0011000000000110000011000000001,	LIVE },
	{ 0b1100000000001100000110000000001,	LIVE },
	{ 0b0000000000111000011100000000001,	LIVE },
	{ 0b0000000011000000111000010000001,	LIVE },
	{ 0b0000000110000000101000101000011,	DEAD },
	{ 0b0000011000000001000001010000111,	DEAD },
	{ 0b0001100000000010000010100001101,	DEAD },
	{ 0b0110000000000100000101000011001,	DEAD },
	{ 0b1000000000011000001010000110001,	DEAD },
	{ 0b0000000001100000010100011100001,	DEAD },
	{ 0b0000000001100000001000001100000,	DEAD },
	{ 0b0000000110000000000000011000010,	DEAD },
	{ 0b0000011000000000000000100000110,	DEAD },
	{ 0b0001100000000000000001000001100,	DEAD },
	{ 0b0110000000000000000010000011000,	DEAD },
	{ 0b1000000000010000000100000110000,	DEAD },
	{ 0b1000000000101000000100000100000,	DEAD },
	{ 0b0000000001010000011000000100000,	DEAD },
	{ 0b0000000010100000011000001000000,	DEAD },
	{ 0b0000000101000000100000011000000,	DEAD },
	{ 0b0000001010000000100000010000010,	DEAD },
	{ 0b0000010100000001000000100000010,	DEAD },
	{ 0b0000101000000001000000100000100,	DEAD },
	{ 0b0001010000000010000001000000100,	DEAD },
	{ 0b0010100000000010000001000001000,	DEAD },
	{ 0b0101000000000100000010000001000,	DEAD },
	{ 0b1010000000000100000010000010000,	DEAD },
	{ 0b0100000000011000000100000010000,	DEAD },
};

#endif
