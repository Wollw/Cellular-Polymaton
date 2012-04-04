#ifndef AUTOMATON_H
#define AUTOMATON_H
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "defines.h"
#include "_config.h"

/* Used to keep track of the automaton's state.  *rules is made to point
 * to the user defined rules struct and *cells is made to point to the 
 * user defined cells struct.  The state member is used to store which
 * cells are alive and dead. */
typedef struct {
	struct rules const *rules;
	struct cells const *cells;
	bits_type state :CFG_CELL_COUNT;
} automaton_type;

/* Setup an automaton_type struct's members to point to the configured
 * rules and cells. This must be done to have the information defined
 * in the _config.h file be used. */
void initialize_automaton(automaton_type *a);

/* Update an automaton_type struct based on the rules it uses. */
void update_automaton(automaton_type *a);

#endif
