#include "_config.h"
#ifdef CFG_ENABLE_SHIFT
#include "shift.h"

void shift_bits_init(void) {
	CFG_SHIFT_DDR |= _BV(CFG_SHIFT_RCLK)
		| _BV(CFG_SHIFT_SRCLK)
		| _BV(CFG_SHIFT_SER);
}

void shift_bits_out(bits_type b, size_t len) {
	CFG_SHIFT_PORT &= ~_BV(CFG_SHIFT_RCLK);
	for (size_t i = 0; i < CFG_SHIFT_REGISTER_PIN_COUNT; i++) {
		CFG_SHIFT_PORT &= ~_BV(CFG_SHIFT_SRCLK);
		if (i < len && (b & ((bits_type)1 << i)))
			CFG_SHIFT_PORT |= _BV(CFG_SHIFT_SER);
		CFG_SHIFT_PORT |= _BV(CFG_SHIFT_SRCLK);
		CFG_SHIFT_PORT &= ~_BV(CFG_SHIFT_SER);
	}
	CFG_SHIFT_PORT |= _BV(CFG_SHIFT_RCLK);
}


#endif
