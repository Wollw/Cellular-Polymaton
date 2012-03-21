#include <stdlib.h>
#include "interrupt.h"
#include "defines.h"

/* Keeps track of number of interrupts since last update of the
 * cells states.  Resets to 0 when the cells are updated to a new state. */
volatile size_t update_counter;

/* flags.update is set to true when we're interrupted CFG_WAIT_COUNT
 * number of times.  This is done so we can configure the length of
 * the delay between updates.  This interrupt routine just serves to
 * signal to the main loop that it is time to update.	*/
#ifdef	__AVR_ATmega328P__
ISR(TIMER1_OVF_vect) {
#elif	__AVR_ATtiny85__
ISR(TIM0_OVF_vect) {
#endif
	if (++update_counter >= CFG_WAIT_COUNT) {
		flags.update = true;
		update_counter = 0;
	} 
}

void interrupt_init(void) {
#ifdef	__AVR_ATmega328P__
	//TCCR1B |= _BV(CS10) | _BV(CS12);
	TCCR1B |= _BV(CS12);
	TIMSK1 |= _BV(TOIE1);
#elif	__AVR_ATtiny85__
	TCCR0B |= _BV(CS00) | _BV(CS02);
	TIMSK  |= _BV(TOIE0);
#endif
	// We want to display something to start with.
	flags.update = true;
	update_counter = 0;
}
