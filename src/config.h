#ifndef CONFIG_H
#define CONFIG_H
#include <stdint.h>
#include <stdbool.h>
#include "defines.h"

/* Comment this out of you don't want to use the serial port. */
#define CFG_ENABLE_USART

/* The number of cells in the automaton */
#define CFG_CELL_COUNT 9

/* The most neighbors a cell has */
#define CFG_MOST_NEIGHBORS 8

/* The rules used for cells that are alive and cells that are dead.
 * See README.md for a detailed description of how these work.*/
struct rules {
	bits_t live :CFG_MOST_NEIGHBORS+1;
	bits_t dead :CFG_MOST_NEIGHBORS+1;
} cfg_rules = {
	0b00001100,
	0b00001000
};

/* The configurations for each cell in the automaton.
 * See README.md for a detailed description of how this works.*/
struct cells {
	bits_t neighbors :CFG_CELL_COUNT;
	bool initial_state :1;
} cfg_cells[] = {
	{ 0b000011010, DEAD },
	{ 0b000111101, DEAD },
	{ 0b000110010, DEAD },
	{ 0b011010011, LIVE },
	{ 0b111101111, LIVE },
	{ 0b110010110, LIVE },
	{ 0b010011000, DEAD },
	{ 0b101111000, DEAD },
	{ 0b010110000, DEAD }
};

#endif
