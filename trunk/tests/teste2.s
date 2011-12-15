# as output.s -o output.o
# ld -dynamic-linker /lib/ld-linux.so.2 -o output -lc output.o
# ./output


.section .data					# MEM
	filo:	.space 16			# allocates space for STACK based on TAC
	temp:	.space 8			# allocates space for HEAP based on TAC.

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
		MOVL $2 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_003:	LEAL 8(%ECX) , %EAX
		PUSHL  %EAX
		MOVL $3 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_004:	LEAL 12(%ECX) , %EAX
		PUSHL  %EAX
		MOVL $4 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_005:	MOVL (%ECX) , %EAX
		MOVL 4(%ECX) , %EBX
		CMPL %EAX , %EBX
		JG _009

	_006:	JMP  _007

	_007:	MOVL 8(%ECX) , %EAX
		MOVL 12(%ECX) , %EBX
		CMPL %EAX , %EBX
		JL _009

	_008:	JMP  _013

	_009:	MOVL 8(%ECX) , %EAX
		MOVL 12(%ECX) , %EBX
		CMPL %EAX , %EBX
		JL _013

	_010:	JMP  _011

	_011:	LEAL (%ECX) , %EAX
		PUSHL  %EAX
		MOVL $1 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_012:	JMP  _014

	_013:	LEAL (%ECX) , %EAX
		PUSHL  %EAX
		MOVL $0 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_014:	LEAL (%EDX) , %EAX
		PUSHL  %EAX
		MOVL $0 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_015:	PUSHL  %ECX
		PUSHL  %EDX
		PUSHL  (%ECX)
		PUSHL  $intf
		CALL printf
		POPL  %EAX
		POPL  %EAX
		POPL  %EDX
		POPL  %ECX

	_016:	MOVL 8(%ECX) , %EAX
		MOVL 12(%ECX) , %EBX
		CMPL %EAX , %EBX
		JL _020

	_017:	JMP  _018

	_018:	MOVL (%ECX) , %EAX
		MOVL 4(%ECX) , %EBX
		CMPL %EAX , %EBX
		JG _020

	_019:	JMP  _024

	_020:	MOVL 8(%ECX) , %EAX
		MOVL 12(%ECX) , %EBX
		CMPL %EAX , %EBX
		JG _024

	_021:	JMP  _022

	_022:	LEAL (%ECX) , %EAX
		PUSHL  %EAX
		MOVL $1 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_023:	JMP  _025

	_024:	LEAL (%ECX) , %EAX
		PUSHL  %EAX
		MOVL $0 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_025:	LEAL 4(%EDX) , %EAX
		PUSHL  %EAX
		MOVL $0 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_026:	PUSHL  %ECX
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
