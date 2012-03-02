#ifndef CONFIG_H
#define CONFIG_H
#include <stdint.h>
#include <stdbool.h>

#define CFG_ENABLE_USART
#define CFG_CELL_COUNT 9
#define CFG_MOST_NEIGHBORS 8

#define dead false
#define live true

typedef uint64_t bits_t;

struct rules {
	uint64_t r_live :CFG_MOST_NEIGHBORS+1;
	uint64_t r_dead :CFG_MOST_NEIGHBORS+1;
} cfg_rules = {
	0b00001100,
	0b00001000
};

struct cells {
	uint64_t neighbors :CFG_CELL_COUNT;
	bool initial_state :1;
} cfg_cells[] = {
	{ 0b000011010, dead },
	{ 0b000111101, dead },
	{ 0b000110010, dead },
	{ 0b011010011, live },
	{ 0b111101111, live },
	{ 0b110010110, live },
	{ 0b010011000, dead },
	{ 0b101111000, dead },
	{ 0b010110000, dead }
};

#endif
