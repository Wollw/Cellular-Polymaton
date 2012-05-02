;;  vim: expandtab
;;  Multicolor LED Controller
;;
;;  This is firmware for an attiny4/5/9/10 for causing a multicolor LED
;;  to change between two colors.  PB0 is connected to one pin of the LED
;;  and PB2 to the other.  PB0 is used as a PWM output which is controlled
;;  by the state of PB1.  When PB1 goes low the LED's color attached to
;;  PB0 fades out.  When PB1 goes high again the color fades back in.
.NOLIST
.INCLUDE "defs.inc"
.LIST

.EQU    PWM_MIN	=	0x02
.EQU    PWM_MAX	=	0xf0

.ORG    0x0000
    rjmp    RESET
.ORG    0x0004
    rjmp    TIM0_OVF
.ORG    0x0040

RESET:
    ;; Clock prescaler of 256 to save power (?)
    ldi     TEMP0,      0xD8
    ldi     TEMP1,      0b1000
    out     CCP,        TEMP0
    out     CLKPSR,     TEMP1

    ;; Setup pins
    ldi     TEMP0,      0b1010
    out     PUEB,       TEMP0
    ldi     TEMP0,      0b0101
    out     DDRB,       TEMP0
    ldi     TEMP0,      0b0100
    out     PORTB,      TEMP0

    ;; 8-bit Fast PWM on OC0A so we can fade 
    ldi     TEMP1,      0b10000001
    ldi     TEMP0,      0b00001001
    out     TCCR0A,     TEMP1
    out     TCCR0B,     TEMP0

    ;; interrupt on timer overflow
    ;; which is when we update the PWM reference
    ldi     TEMP0,      0b001
    out     TIMSK0,     TEMP0

    ;; Start Fast PWM with a low reference
    ;; meaning it starts out close to off
    ldi     TEMP1,      0x00
    ldi     TEMP0,      PWM_MIN
    out     OCR0AH,     TEMP1
    out     OCR0AL,     TEMP0
    ldi     OCRVAL,     0x40

    ;; Disable ADC to save power
    ldi     TEMP0,      0b10
    out     PRR,        TEMP0

    sei
    rjmp    LOOP

;; Loop forever and sleep a lot
LOOP:
    ldi     TEMP0,      0b1
    out     SMCR,       TEMP0
    sleep
    ldi     TEMP0,      0b0
    out     SMCR,       TEMP0
    rjmp    LOOP


;; When timer overflows increment or decrement based on state of PB1.
;; We don't increment if we're at PWM_HIGH and don't decrement if 
;; we're at PWM_LOW.  If PB1 is high we try to increment, otherwise we
;; try to decrement.
TIM0_OVF:
    cli
    ldi     TEMP0,      0x00
    sbic    PINB,       1
    rjmp    INC_OCRVAL
    rjmp    DEC_OCRVAL
TIM0_OVF_EXIT:
    out     OCR0AH,    TEMP0
    out     OCR0AL,    OCRVAL
    sei
    reti

;; Increment the reference if we aren't at PWM_MAX already
INC_OCRVAL:
    cpi     OCRVAL,     PWM_MAX
    brsh    TIM0_OVF_EXIT
    inc     OCRVAL
    rjmp    TIM0_OVF_EXIT

;; Decrement the reference if we aren't at PWM_MIN already
DEC_OCRVAL:
    cpi     OCRVAL,     PWM_MIN
    brlo    TIM0_OVF_EXIT
    dec     OCRVAL
    rjmp    TIM0_OVF_EXIT
