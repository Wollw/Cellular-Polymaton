#ifndef DEFINES_H
#define DEFINES_H

/* Convenience definitions. bits_t must be defined
 * as some sort of unsigned integer.*/
#define DEAD false
#define LIVE true
typedef bool cell_state_t;
typedef uint64_t bits_t;

typedef volatile struct {
	bool update :1;
} flags_t;

extern flags_t flags;

#endif
