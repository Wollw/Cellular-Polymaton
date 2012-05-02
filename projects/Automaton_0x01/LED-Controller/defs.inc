.device ATtiny4

;;	Personal Definitions
.DEF    TEMP0	=	r16
.DEF    TEMP1	=	r17
.DEF    OCRVAL	=	r18
	
;;	MCU Definitions
.equ	SMCR	=	0x3a
.equ    CCP		=	0x3c
.equ    CLKPSR	=	0x36
.equ	PRR		=	0x35

.equ    TCCR0A	=	0x2e
.equ    TCCR0B	=	0x2d
.equ    TIMSK0	=	0x2b

.equ    OCR0AL	=	0x26
.equ    OCR0AH	=	0x27


.equ    PUEB	=	0x03
.equ    PORTB	=	0x02
.equ    DDRB    =	0x01
.equ    PINB    =	0x00
