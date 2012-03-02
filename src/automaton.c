#include "config.h"
#include "automaton.h"


cell_state_t _cell_state_next(size_t i, automaton_t *a);
uint8_t _cell_live_neighbors(size_t i, automaton_t *a);


void initialize_automaton(automaton_t *a) {
	a->rules = &cfg_rules;
	a->cells = cfg_cells;
	for (size_t i = 0; i < CFG_CELL_COUNT; i++)
		if (cfg_cells[i].initial_state == live)
			a->state |= (bits_t)1 << i;
		else
			a->state &= ~((bits_t)1 << i);
}

void update_automaton(automaton_t *a) {
	bits_t state_next = 0;
	for (size_t i = 0; i < CFG_CELL_COUNT; i++) {
		if (_cell_state_next(i, a) == live)
			state_next |=   (bits_t)1 << i;
		else
			state_next &= ~((bits_t)1 << i);
	}
	a->state = state_next;
}


cell_state_t _cell_state_next(size_t i, automaton_t *a) {
	rules_t r = (a->state & ((bits_t)1 << i)) ? a->rules->r_live : a->rules->r_dead;
	return r & ((bits_t)1 << _cell_live_neighbors(i, a)) ? live : dead;
}


uint8_t _cell_live_neighbors(size_t i, automaton_t *a) {
	uint8_t nc = 0;
	for (size_t j = 0; j < CFG_CELL_COUNT; j++)
		if ((a->cells[i].neighbors & ((bits_t)1 << j)) && (a->state & ((bits_t)1 << j)))
			nc++;
	return nc;
}
