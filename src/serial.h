#ifndef		SERIAL_H
#define		SERIAL_H
#include <stdint.h>


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
 * Output the first len bits of a uint64_t pointer.
 */
void serial_write_bits(bits_t b, size_t len);

#endif
