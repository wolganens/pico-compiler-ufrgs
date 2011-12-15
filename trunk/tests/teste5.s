# as output.s -o output.o
# ld -dynamic-linker /lib/ld-linux.so.2 -o output -lc output.o
# ./output


.section .data					# MEM
	filo:	.space 16			# allocates space for STACK based on TAC
	temp:	.space 20			# allocates space for HEAP based on TAC.

	intf:	.string "%d\n"			# integer format for printing.
	
		.equ LINUX_SYSCALL , 0x80	# alias for invoking a system call through INT.

#------------------------------------------------------------------------------

.section .text					# CODE
	.extern printf
	.global _start				# enables linker (ld) to see it.
	.align 4				# ensures word (4 bytes, 32 bits) align of instructions.
	
	_start:	MOVL  $filo , %ECX		# register %ECX gets SP reference.
		MOVL  $temp , %EDX		# register %EDX gets Rx reference.

	_001:	LEAL (%ECX) , %EAX
		PUSHL  %EAX
		MOVL $1 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_002:	LEAL 4(%ECX) , %EAX
		PUSHL  %EAX
		MOVL $5 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_003:	LEAL 8(%ECX) , %EAX
		PUSHL  %EAX
		MOVL $1 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_004:	LEAL 12(%ECX) , %EAX
		PUSHL  %EAX
		MOVL $3 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_005:	MOVL (%ECX) , %EAX
		MOVL 4(%ECX) , %EBX
		CMPL %EAX , %EBX
		JG _007

	_006:	JMP  _023

	_007:	LEAL 8(%ECX) , %EAX
		PUSHL  %EAX
		MOVL $0 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_008:	MOVL 8(%ECX) , %EAX
		MOVL 12(%ECX) , %EBX
		CMPL %EAX , %EBX
		JG _010

	_009:	JMP  _021

	_010:	MOVL  8(%ECX) , %EAX
		ADDL  $1 , %EAX
		MOVL  %EAX ,(%EDX)

	_011:	LEAL 8(%ECX) , %EAX
		PUSHL  %EAX
		MOVL (%EDX) , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_012:	MOVL (%ECX) , %EAX
		MOVL 4(%ECX) , %EBX
		CMPL %EAX , %EBX
		JL _017

	_013:	JMP  _014

	_014:	JMP  _015

	_015:	LEAL 4(%ECX) , %EAX
		PUSHL  %EAX
		MOVL (%ECX) , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_016:	JMP  _019

	_017:	MOVL  4(%ECX) , %EAX
		SUBL  $1 , %EAX
		MOVL  %EAX ,4(%EDX)

	_018:	LEAL 4(%ECX) , %EAX
		PUSHL  %EAX
		MOVL 4(%EDX) , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_019:	LEAL 8(%EDX) , %EAX
		PUSHL  %EAX
		MOVL $0 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_020:	JMP  _008

	_021:	LEAL 12(%EDX) , %EAX
		PUSHL  %EAX
		MOVL $0 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_022:	JMP  _005

	_023:	LEAL 16(%EDX) , %EAX
		PUSHL  %EAX
		MOVL $0 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_024:	PUSHL  %ECX
		PUSHL  %EDX
		PUSHL  (%ECX)
		PUSHL  $intf
		CALL printf
		POPL  %EAX
		POPL  %EAX
		POPL  %EDX
		POPL  %ECX

	_exit:	MOVL $1 , %EAX 
		MOVL $0 , %EBX 
		INT $LINUX_SYSCALL
.end
