/* Cellular Polymaton
 *
 * This is a framework for creating custom cellular automaton using
 * geometry other than square grids.  It takes a lot more effort to
 * make something this way than the simple 2D array but by defining
 * exactly which cells are considered neighbors to each cell you can
 * create any kind of automaton world you want.
 *
 * This program creates an automaton_type object and initializes it with
 * data defined in _config.h.  A timer is used to determine the time
 * between updates to the automaton.
 */
#include <avr/io.h>
#include <util/atomic.h>
#include <stdbool.h>

#include "defines.h"
#include "flags.h"
#include "_config.h"
#include "automaton.h"
#include "serial.h"
#include "shift.h"
#include "interrupt.h"

#ifdef CFG_ENABLE_USART
#include <stdio.h>
#endif

int main(void) {
	automaton_type a;
	initialize_automaton(&a);

#ifdef CFG_ENABLE_SHIFT
	shift_bits_init();
#endif

#ifdef CFG_ENABLE_USART
	/* Output the cell's neighbors sequentially from first
	 * cell to last.
	 */
	serial_init(9600);
	serial_write_str("-----------------------------\r\n");
	serial_write_str("CELL\tSTATE\tNEIGHBORS\r\n");
	char buffer[128];
	for (size_t i = 0; i < CFG_CELL_COUNT; i++) {
		sprintf(buffer, "%02d\t%s\t", i,
				a.cells[i].initial_state ? "LIVE" : "DEAD");
		serial_write_str(buffer);
		serial_write_bits(a.cells[i].neighbors, 9);
		serial_write_str("\r\n");
	}
	serial_write_str("------------------------------\r\n");
#endif

	// Turn on 16 Bit Timer, Interrupt on Overflow
	interrupt_init();

	sei();
	for (;;) {
		ATOMIC_BLOCK(ATOMIC_FORCEON) {
			if (flags.update) {
				flags.update = false;
#ifdef CFG_ENABLE_SHIFT
				shift_bits_out(a.state, CFG_CELL_COUNT);
#endif
#ifdef CFG_ENABLE_USART
				// Output the current state of the automaton.
				serial_write_bits(a.state, CFG_CELL_COUNT);
				serial_write_str("\r\n");
#endif
				update_automaton(&a);
			}
		}
	}
}
