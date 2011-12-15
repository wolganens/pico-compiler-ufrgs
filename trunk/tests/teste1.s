# as output.s -o output.o
# ld -dynamic-linker /lib/ld-linux.so.2 -o output -lc output.o
# ./output


.section .data					# MEM
	filo:	.space 224			# allocates space for STACK based on TAC
	temp:	.space 116			# allocates space for HEAP based on TAC.

	intf:	.string "%d\n"			# integer format for printing.
	
		.equ LINUX_SYSCALL , 0x80	# alias for invoking a system call through INT.

#------------------------------------------------------------------------------

.section .text					# CODE
	.extern printf
	.global _start				# enables linker (ld) to see it.
	.align 4				# ensures word (4 bytes, 32 bits) align of instructions.
	
	_start:	MOVL  $filo , %ECX		# register %ECX gets SP reference.
		MOVL  $temp , %EDX		# register %EDX gets Rx reference.

	_001:	LEAL 4(%ECX) , %EAX
		PUSHL  %EAX
		MOVL $1 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_002:	MOVL  $1 , %EAX
		IMULL $4 , %EAX
		MOVL  %EAX ,(%EDX)

	_003:	MOVL  (%EDX) , %EAX
		ADDL  $1 , %EAX
		MOVL  %EAX ,4(%EDX)

	_004:	MOVL  4(%EDX) , %EAX
		IMULL $3 , %EAX
		MOVL  %EAX ,8(%EDX)

	_005:	MOVL  8(%EDX) , %EAX
		ADDL  $3 , %EAX
		MOVL  %EAX ,12(%EDX)

	_006:	MOVL  12(%EDX) , %EAX
		IMULL $4 , %EAX
		MOVL  %EAX ,16(%EDX)

	_007:	MOVL  16(%EDX) , %EAX
		ADDL  $0 , %EAX
		MOVL  %EAX ,20(%EDX)

	_008:	MOVL  $5 , %EAX
		ADDL  4(%ECX) , %EAX
		MOVL  %EAX ,24(%EDX)

	_009:	MOVL 20(%EDX) , %EAX
		LEAL 8(%ECX) , %EBX
		ADDL %EBX , %EAX
		PUSHL  %EAX
		MOVL 24(%EDX) , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_010:	MOVL  $3 , %EAX
		IMULL $3 , %EAX
		MOVL  %EAX ,28(%EDX)

	_011:	MOVL  28(%EDX) , %EAX
		ADDL  $4 , %EAX
		MOVL  %EAX ,32(%EDX)

	_012:	MOVL  32(%EDX) , %EAX
		IMULL $2 , %EAX
		MOVL  %EAX ,36(%EDX)

	_013:	MOVL  36(%EDX) , %EAX
		ADDL  $7 , %EAX
		MOVL  %EAX ,40(%EDX)

	_014:	MOVL  40(%EDX) , %EAX
		IMULL $4 , %EAX
		MOVL  %EAX ,44(%EDX)

	_015:	MOVL  44(%EDX) , %EAX
		ADDL  $48 , %EAX
		MOVL  %EAX ,48(%EDX)

	_016:	MOVL  $5 , %EAX
		SUBL  4(%ECX) , %EAX
		MOVL  %EAX ,52(%EDX)

	_017:	MOVL 48(%EDX) , %EAX
		LEAL 152(%ECX) , %EBX
		ADDL %EBX , %EAX
		PUSHL  %EAX
		MOVL 52(%EDX) , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_018:	MOVL  $1 , %EAX
		IMULL $4 , %EAX
		MOVL  %EAX ,56(%EDX)

	_019:	MOVL  56(%EDX) , %EAX
		ADDL  $1 , %EAX
		MOVL  %EAX ,60(%EDX)

	_020:	MOVL  60(%EDX) , %EAX
		IMULL $3 , %EAX
		MOVL  %EAX ,64(%EDX)

	_021:	MOVL  64(%EDX) , %EAX
		ADDL  $3 , %EAX
		MOVL  %EAX ,68(%EDX)

	_022:	MOVL  68(%EDX) , %EAX
		IMULL $4 , %EAX
		MOVL  %EAX ,72(%EDX)

	_023:	MOVL  72(%EDX) , %EAX
		ADDL  $0 , %EAX
		MOVL  %EAX ,76(%EDX)

	_024:	LEAL 80(%EDX) , %EAX
		PUSHL  %EAX
		MOVL 76(%EDX) , %EAX
		LEAL 8(%ECX) , %EBX
		ADDL %EBX , %EAX
		POPL  %EBX
		MOVL (%EAX) , %EAX
		MOVL %EAX , (%EBX)

	_025:	MOVL  $3 , %EAX
		IMULL $3 , %EAX
		MOVL  %EAX ,84(%EDX)

	_026:	MOVL  84(%EDX) , %EAX
		ADDL  $4 , %EAX
		MOVL  %EAX ,88(%EDX)

	_027:	MOVL  88(%EDX) , %EAX
		IMULL $2 , %EAX
		MOVL  %EAX ,92(%EDX)

	_028:	MOVL  92(%EDX) , %EAX
		ADDL  $7 , %EAX
		MOVL  %EAX ,96(%EDX)

	_029:	MOVL  96(%EDX) , %EAX
		IMULL $4 , %EAX
		MOVL  %EAX ,100(%EDX)

	_030:	MOVL  100(%EDX) , %EAX
		ADDL  $48 , %EAX
		MOVL  %EAX ,104(%EDX)

	_031:	LEAL 108(%EDX) , %EAX
		PUSHL  %EAX
		MOVL 104(%EDX) , %EAX
		LEAL 152(%ECX) , %EBX
		ADDL %EBX , %EAX
		POPL  %EBX
		MOVL (%EAX) , %EAX
		MOVL %EAX , (%EBX)

	_032:	MOVL  80(%EDX) , %EAX
		ADDL  108(%EDX) , %EAX
		MOVL  %EAX ,112(%EDX)

	_033:	LEAL (%ECX) , %EAX
		PUSHL  %EAX
		MOVL 112(%EDX) , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_034:	PUSHL  %ECX
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
