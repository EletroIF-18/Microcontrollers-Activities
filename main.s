/*
 * AssemblerApplication1.asm
 *
 *  Created: 12/04/2022 16:59:05
 *   Author: Aluno
 */

	ldi R16, 0b00111111
	out DDRB, R16


main:
	on:
		sbi PORTB, PB5
		RCALL delay
		sbi PORTB, PB4
		RCALL delay
		sbi PORTB, PB3
		RCALL delay
		sbi PORTB, PB2
		RCALL delay
		sbi PORTB, PB1
		RCALL delay
		sbi PORTB, PB0
		RCALL delay

	off:
		cbi PORTB, PB5
		cbi PORTB, PB4
		cbi PORTB, PB3
		cbi PORTB, PB2
		cbi PORTB, PB1
		cbi PORTB, PB0

		RCALL delay
		rjmp main

delay:
	ldi R18, 41
	ldi R19, 150
	ldi R20, 128
	loop:
    DEC R20
    BRNE loop
    DEC R19
    BRNE loop
    DEC R18
    BRNE loop
    RET