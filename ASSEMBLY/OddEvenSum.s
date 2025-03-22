 AREA myDATA, DATA, READWRITE		;	
NUM		DCB 1,2,3,4,5,6				;
EVENSUM DCB 0						;
ODDSUM	DCB 0						;

 AREA myCODE, CODE, READONLY		;
 EXPORT OddEvenSum					;
ENTRY								;
OddEvenSum
 LDR R0, =NUM	;
 MOV R1, #0		;
 MOV R2, #0		;
 MOV R3, #6		;
 
LOOP
  LDRB R4, [R0], #1 ;
  LSRS R5, R4, #1	;
  BCS ODD			;
  
  ADD R1, R1, R4	;
  B DEC				;
  
  ADD R1, R1, R4	;
  B DEC				;
  
ODD				
  ADD R2, R2, R4	;
  
DEC
 SUBS R3, R3, #1	;
 BNE LOOP			;
 
 LDR R0, =EVENSUM	;
 STRB R1, [R0]		;
 
 LDR R0, =ODDSUM	;
 STRB R2, [R0]		;
 
 BX LR 				;
 END				;