#ifndef AUTOMATON_H
#define AUTOMATON_H
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "defines.h"
#include "config.h"

/* Used to keep track of the automaton's state.  *rules is made to point
 * to the user defined rules struct and *cells is made to point to the 
 * user defined cells struct.  The state member is used to store which
 * cells are alive and dead. */
typedef struct {
	struct rules const *rules;
	struct cells const *cells;
	bits_t state :CFG_CELL_COUNT;
} automaton_t;

/* Setup an automaton_t struct's members to point to the configured
 * rules and cells. */
void initialize_automaton(automaton_t *a);

/* Update an automaton_t struct based on the rules it uses. */
void update_automaton(automaton_t *a);

#endif
