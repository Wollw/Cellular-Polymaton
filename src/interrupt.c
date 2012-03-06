#include <stdlib.h>
#include "interrupt.h"
#include "defines.h"

volatile size_t update_counter;
#ifdef	__AVR_ATmega328P__
ISR(TIMER1_OVF_vect) {
#elif	__AVR_ATtiny85__
ISR(TIM0_OVF_vect) {
#endif
	ATOMIC_BLOCK(ATOMIC_FORCEON) {
		if (++update_counter >= CFG_WAIT_COUNT) {
			flags.update = true;
			update_counter = 0;
		} 
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
