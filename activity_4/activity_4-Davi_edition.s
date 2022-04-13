
 inicio:

 LDI R16, 0b11111111
 OUT DDRB, R16

 liga:
 SBI PORTB, PB0 
 SBI PORTB, PB1 
 SBI PORTB, PB2 
 SBI PORTB, PB3 
 SBI PORTB, PB4 
 SBI PORTB, PB5
 rjmp loop

 loop: 

 CBI PORTB, PB5 
 RCALL atraso
 SBI PORTB, PB5 
 CBI PORTB, PB4 
 RCALL atraso
 SBI PORTB, PB4 
 CBI PORTB, PB3 
 RCALL atraso
 SBI PORTB, PB3 
 CBI PORTB, PB2 
 RCALL atraso
 SBI PORTB, PB2  
 CBI PORTB, PB1 
 RCALL atraso
 SBI PORTB, PB1 
 CBI PORTB, PB0 
 RCALL atraso
 SBI PORTB, PB0 
 rjmp loop2 

 loop2:

 CBI PORTB, PB0 
 RCALL atraso
 SBI PORTB, PB0 
 CBI PORTB, PB1 
 RCALL atraso
 SBI PORTB, PB1 
 CBI PORTB, PB2 
 RCALL atraso
 SBI PORTB, PB2 
 CBI PORTB, PB3 
 RCALL atraso
 SBI PORTB, PB3  
 CBI PORTB, PB4 
 RCALL atraso
 SBI PORTB, PB4 
 CBI PORTB, PB5 
 RCALL atraso
 SBI PORTB, PB5
 rjmp liga  
 

 atraso:
 
 ldi r18, 41
 ldi r19, 150
 ldi r20, 128

 L1: dec r20
 
 brne L1
 dec r19
 brne L1
 dec r18
 brne L1
 ret



 
