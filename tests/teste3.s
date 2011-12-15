# as output.s -o output.o
# ld -dynamic-linker /lib/ld-linux.so.2 -o output -lc output.o
# ./output


.section .data					# MEM
	filo:	.space 16			# allocates space for STACK based on TAC
	temp:	.space 16			# allocates space for HEAP based on TAC.

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
		MOVL $2 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_002:	LEAL 4(%ECX) , %EAX
		PUSHL  %EAX
		MOVL $1 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_003:	LEAL 8(%ECX) , %EAX
		PUSHL  %EAX
		MOVL $1 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_004:	LEAL 12(%ECX) , %EAX
		PUSHL  %EAX
		MOVL $1 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_005:	MOVL 8(%ECX) , %EAX
		MOVL $5 , %EBX
		CMPL %EAX , %EBX
		JG _007

	_006:	JMP  _018

	_007:	MOVL (%ECX) , %EAX
		MOVL 4(%ECX) , %EBX
		CMPL %EAX , %EBX
		JL _010

	_008:	JMP  _009

	_009:	JMP  _010

	_010:	JMP  _011

	_011:	MOVL  8(%ECX) , %EAX
		ADDL  $1 , %EAX
		MOVL  %EAX ,(%EDX)

	_012:	LEAL 8(%ECX) , %EAX
		PUSHL  %EAX
		MOVL (%EDX) , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_013:	JMP  _016

	_014:	MOVL  12(%ECX) , %EAX
		SUBL  $1 , %EAX
		MOVL  %EAX ,4(%EDX)

	_015:	LEAL 12(%ECX) , %EAX
		PUSHL  %EAX
		MOVL 4(%EDX) , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_016:	LEAL 8(%EDX) , %EAX
		PUSHL  %EAX
		MOVL $0 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_017:	JMP  _005

	_018:	LEAL 12(%EDX) , %EAX
		PUSHL  %EAX
		MOVL $0 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_019:	PUSHL  %ECX
		PUSHL  %EDX
		PUSHL  8(%ECX)
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
