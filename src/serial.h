#ifndef		SERIAL_H
#define		SERIAL_H
#include <stdint.h>
#include "defines.h"
#include "_config.h"

#ifndef	CFG_USART_SET_BIT_MSG
#define	CFG_USART_SET_BIT_MSG	"1"
#endif

#ifndef	CFG_USART_CLR_BIT_MSG
#define	CFG_USART_CLR_BIT_MSG	"0"
#endif


/*
 * Calulate the USART Baud Rate Register (UBBR) value for Asynchronous
 * Normal mode.
 */
#define UBRR_ASYNC_NORMAL(br) ((F_CPU / (br * 16UL)) - 1)


/*
 * Setup the baudrate and pins for serial data.
 */
void serial_init(uint64_t baudrate);


/*
 * Output the character c on TX.
 */
void serial_write(char c);


/*
 * Output the first len bits of a bits_type value
 */
void serial_write_bits(bits_type b, size_t len);

/*
 * Output a string over serial
 */
void serial_write_str(char *s);

#endif
