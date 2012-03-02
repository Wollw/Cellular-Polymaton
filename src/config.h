#ifndef CONFIG_H
#define CONFIG_H
#include <stdint.h>
#include <stdbool.h>

#define CFG_ENABLE_USART
#define CFG_CELL_COUNT 9
#define CFG_MOST_NEIGHBORS 8

#define DEAD false
#define LIVE true

typedef uint64_t bits_t;

struct rules {
	bits_t live :CFG_MOST_NEIGHBORS+1;
	bits_t dead :CFG_MOST_NEIGHBORS+1;
} cfg_rules = {
	0b00001100,
	0b00001000
};

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
