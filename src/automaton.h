#ifndef AUTOMATON_H
#define AUTOMATON_H
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "config.h"

#ifndef LIVE
#define LIVE true
#endif

#ifndef DEAD
#define DEAD false
#endif

typedef struct rules ruleset_t;
typedef struct cells cell_t;
typedef bits_t       rules_t;
typedef bool         cell_state_t;
typedef bits_t       automaton_state_t;

typedef struct {
	ruleset_t *rules;
	cell_t *cells;
	automaton_state_t state :CFG_CELL_COUNT;
} automaton_t;

/* Setup an automaton_t struct's members to point to the configured
 * rules and cells
 */
void initialize_automaton(automaton_t *a);

/* Update an automaton_t struct based on the rules it uses.
 */
void update_automaton(automaton_t *a);

#endif
