#include "config.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include <stdbool.h>
#include "automaton.h"
#include "serial.h"

volatile bool update_cells;

ISR(TIMER1_OVF_vect) {
	ATOMIC_BLOCK(ATOMIC_FORCEON) {
		update_cells = true;
	}
}

int main(void) {
	serial_init(9600);

	automaton_t a;
	initialize_automaton(&a);
	update_cells = 0;

	for (size_t i = 0; i < 9; i++)
		serial_write_bits(a.cells[i].neighbors, 9);

	// Turn on 16 Bit Timer, Interrupt on Overflow
	//TCCR1B |= _BV(CS10) | _BV(CS12);
	TCCR1B |= _BV(CS12);
	TIMSK1 |= _BV(TOIE1);
	sei();

	for (;;) {
		if (update_cells) {
			ATOMIC_BLOCK(ATOMIC_FORCEON) {
				update_cells = false;
				serial_write('-');
				serial_write('\r');
				serial_write('\n');
				serial_write_bits(a.state, CFG_CELL_COUNT);
				update_automaton(&a);
			}
		}
	}
}
