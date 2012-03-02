#include "config.h"
#ifdef CFG_ENABLE_USART
#include <stdlib.h>
#include <avr/io.h>
#include "serial.h"

void serial_init(uint64_t baudrate) {
	// Set Baudrate
	UBRR0H = (UBRR_ASYNC_NORMAL(baudrate) >> 8);
	UBRR0L = UBRR_ASYNC_NORMAL(baudrate);
	
	// Enable RX and TX
	UCSR0B |= _BV(RXEN0) | _BV(TXEN0);

	// Set 8N1 Framing
	UCSR0C |= _BV(UCSZ00) | _BV(UCSZ01);

}


void serial_write(char c) {
	// Wait for the USART Data Register to be empty and then send
	while( !(UCSR0A & (_BV(UDRE0))) );
	UDR0 = c;
}


void serial_write_str(char *s) {
	while (*s)
		serial_write(*s++);
}


void serial_write_bits(bits_t b, size_t len) {
	while (len--) {
		serial_write(b & ((bits_t)1 << len) ? '1' : '0');
	}
}
#endif
