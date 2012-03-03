#ifndef CONFIG_H
#define CONFIG_H
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include "defines.h"


/* Comment this out of you don't want to use the shift registers. */
#define	CFG_ENABLE_SHIFT
/* The ports and pins used for shifting bits out to the shift registers. */
#define	CFG_SHIFT_REGISTER_PIN_COUNT	24
#define CFG_SHIFT_DDR					DDRB
#define	CFG_SHIFT_PORT					PORTB
#define	CFG_SHIFT_RCLK					PIN0
#define	CFG_SHIFT_SER					PIN1
#define	CFG_SHIFT_SRCLK					PIN2

/* Comment this out of you don't want to use the serial port. */
#define CFG_ENABLE_USART
/* The baudrate for serial transfer. */
#define CFG_USART_BAUDRATE		9600
/* What to output for set and cleared bits */
#define	CFG_USART_SET_BIT_MSG	"x"
#define	CFG_USART_CLR_BIT_MSG	"o"

/* The number of cells in the automaton */
#define CFG_CELL_COUNT		19
/* The most neighbors a cell has */
#define CFG_MOST_NEIGHBORS	7
/* The rules used for cells that are alive and cells that are dead.
 * See README.md for a detailed description of how these work.*/
struct rules {
	bits_t live :CFG_MOST_NEIGHBORS+1;
	bits_t dead :CFG_MOST_NEIGHBORS+1;
} cfg_rules = {
	0b11000010,
	0b01111010
};
/* The configurations for each cell in the automaton.
 * See README.md for a detailed description of how this works.*/
struct cells {
	bits_t neighbors :CFG_CELL_COUNT;
	bool initial_state :1;
} cfg_cells[] = {
	{ 0b0000000000001111110, LIVE },
	{ 0b0000000001111000101, LIVE },
	{ 0b0000000101001011011, DEAD },
	{ 0b0000011100000010101, LIVE },
	{ 0b0001010000001101101, DEAD },
	{ 0b0111000000001010001, LIVE },
	{ 0b0100000000010110111, DEAD },
	{ 0b0000000011101000010, LIVE },
	{ 0b0000000011010000010, DEAD },
	{ 0b0000000010110000110, DEAD },
	{ 0b0000000001110000000, DEAD },
	{ 0b0000111000000001100, LIVE },
	{ 0b0000110100000001000, DEAD },
	{ 0b0000101100000011000, DEAD },
	{ 0b0000011100000000000, DEAD },
	{ 0b1110000000000110000, LIVE },
	{ 0b1101000000000100000, DEAD },
	{ 0b1011000000001100000, DEAD },
	{ 0b0111000000000000000, DEAD }
};

#endif
