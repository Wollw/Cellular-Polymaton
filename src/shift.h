#ifndef SHIFT_H
#define SHIFT_H
#include <stdlib.h>
#include "defines.h"
#include "_config.h"

/* Setup the pins needed for shifting bits.
 * The pins used can be configured in _config.h */
void shift_bits_init(void);

/* Shift len number of bits out on the configured pins. */
void shift_bits_out(bits_type b, size_t len);

#endif
