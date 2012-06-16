#include "_config.h"
#include "automaton.h"


static cell_state_type cell_state_next(size_t i, const automaton_type *a);
static uint8_t cell_live_neighbors(size_t i, const automaton_type *a);


void initialize_automaton(automaton_type *a) {
	a->rules = &cfg_rules;
	a->cells = cfg_cells;
	for (size_t i = 0; i < CFG_CELL_COUNT; i++)
		if (cfg_cells[i].initial_state == LIVE)
			a->state |= (bits_type)1 << i;
		else
			a->state &= ~((bits_type)1 << i);
}


void update_automaton(automaton_type *a) {
	bits_type state_next = 0;
	for (size_t i = 0; i < CFG_CELL_COUNT; i++) {
		if (cell_state_next(i, a) == LIVE)
			state_next |=   (bits_type)1 << i;
		else
			state_next &= ~((bits_type)1 << i);
	}
	a->state = state_next;
}


static cell_state_type cell_state_next(size_t i, const automaton_type *a) {
	bits_type r = (a->state & ((bits_type)1 << i)) ? a->rules->live : a->rules->dead;
	return r & ((bits_type)1 << cell_live_neighbors(i, a)) ? LIVE : DEAD;
}


static uint8_t cell_live_neighbors(size_t i, const automaton_type *a) {
	uint8_t nc = 0;
	for (size_t j = 0; j < CFG_CELL_COUNT; j++)
		if ((a->cells[i].neighbors & ((bits_type)1 << j)) && (a->state & ((bits_type)1 << j)))
			nc++;
	return nc;
}
