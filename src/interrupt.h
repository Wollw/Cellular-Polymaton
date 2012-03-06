#ifndef	INTERRUPT_H
#define	INTERRUPT_H
#include <avr/interrupt.h>
#include <util/atomic.h>
#include <stdbool.h>
#include "config.h"

/* default number of cycles to wait for should be 1 */
#ifndef	CFG_WAIT_COUNT
#define	CFG_WAIT_COUNT	1
#endif

/* Setup the timer interrupt */
void interrupt_init(void);

#endif
