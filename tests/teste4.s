# as output.s -o output.o
# ld -dynamic-linker /lib/ld-linux.so.2 -o output -lc output.o
# ./output


.section .data					# MEM
	filo:	.space 7956			# allocates space for STACK based on TAC
	temp:	.space 140			# allocates space for HEAP based on TAC.

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

	_004:	MOVL  (%ECX) , %EAX
		ADDL  4(%ECX) , %EAX
		MOVL  %EAX ,(%EDX)

	_005:	MOVL  (%EDX) , %EAX
		SUBL  8(%ECX) , %EAX
		MOVL  %EAX ,4(%EDX)

	_006:	LEAL 12(%ECX) , %EAX
		PUSHL  %EAX
		MOVL 4(%EDX) , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_007:	MOVL  $0 , %EAX
		IMULL $10 , %EAX
		MOVL  %EAX ,8(%EDX)

	_008:	MOVL  8(%EDX) , %EAX
		ADDL  $4 , %EAX
		MOVL  %EAX ,12(%EDX)

	_009:	MOVL  12(%EDX) , %EAX
		IMULL $6 , %EAX
		MOVL  %EAX ,16(%EDX)

	_010:	MOVL  16(%EDX) , %EAX
		ADDL  $8 , %EAX
		MOVL  %EAX ,20(%EDX)

	_011:	MOVL  20(%EDX) , %EAX
		IMULL $3 , %EAX
		MOVL  %EAX ,24(%EDX)

	_012:	MOVL  24(%EDX) , %EAX
		ADDL  $7 , %EAX
		MOVL  %EAX ,28(%EDX)

	_013:	MOVL  28(%EDX) , %EAX
		IMULL $4 , %EAX
		MOVL  %EAX ,32(%EDX)

	_014:	MOVL  32(%EDX) , %EAX
		ADDL  $-252 , %EAX
		MOVL  %EAX ,36(%EDX)

	_015:	MOVL  $5 , %EAX
		IMULL $9 , %EAX
		MOVL  %EAX ,40(%EDX)

	_016:	MOVL  40(%EDX) , %EAX
		ADDL  $8 , %EAX
		MOVL  %EAX ,44(%EDX)

	_017:	MOVL 36(%EDX) , %EAX
		LEAL 36(%ECX) , %EBX
		ADDL %EBX , %EAX
		PUSHL  %EAX
		MOVL 44(%EDX) , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_018:	MOVL  $0 , %EAX
		IMULL $10 , %EAX
		MOVL  %EAX ,48(%EDX)

	_019:	MOVL  48(%EDX) , %EAX
		ADDL  $4 , %EAX
		MOVL  %EAX ,52(%EDX)

	_020:	MOVL  52(%EDX) , %EAX
		IMULL $6 , %EAX
		MOVL  %EAX ,56(%EDX)

	_021:	MOVL  56(%EDX) , %EAX
		ADDL  $8 , %EAX
		MOVL  %EAX ,60(%EDX)

	_022:	MOVL  60(%EDX) , %EAX
		IMULL $3 , %EAX
		MOVL  %EAX ,64(%EDX)

	_023:	MOVL  64(%EDX) , %EAX
		ADDL  $7 , %EAX
		MOVL  %EAX ,68(%EDX)

	_024:	MOVL  68(%EDX) , %EAX
		IMULL $4 , %EAX
		MOVL  %EAX ,72(%EDX)

	_025:	MOVL  72(%EDX) , %EAX
		ADDL  $-252 , %EAX
		MOVL  %EAX ,76(%EDX)

	_026:	LEAL 80(%EDX) , %EAX
		PUSHL  %EAX
		MOVL 76(%EDX) , %EAX
		LEAL 36(%ECX) , %EBX
		ADDL %EBX , %EAX
		POPL  %EBX
		MOVL (%EAX) , %EAX
		MOVL %EAX , (%EBX)

	_027:	LEAL (%ECX) , %EAX
		PUSHL  %EAX
		MOVL 80(%EDX) , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_028:	PUSHL  %ECX
		PUSHL  %EDX
		PUSHL  (%ECX)
		PUSHL  $intf
		CALL printf
		POPL  %EAX
		POPL  %EAX
		POPL  %EDX
		POPL  %ECX

	_029:	LEAL (%ECX) , %EAX
		PUSHL  %EAX
		MOVL $0 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_030:	MOVL  $45 , %EAX
		SUBL  (%ECX) , %EAX
		MOVL  %EAX ,84(%EDX)

	_031:	MOVL  $2 , %EAX
		ADDL  $3 , %EAX
		MOVL  %EAX ,88(%EDX)

	_032:	MOVL  88(%EDX) , %EAX
		IMULL 16(%ECX) , %EAX
		MOVL  %EAX ,92(%EDX)

	_033:	MOVL   92(%EDX) , %EAX
		MOVL   4(%ECX) , %EBX
		PUSHL %EDX
		XORL   %EDX , %EDX
		IDIVL  %EBX
		MOVL   %EDX, %EBX
		POPL   %EDX
		MOVL   %EAX , 96(%EDX)

	_034:	MOVL  84(%EDX) , %EAX
		ADDL  96(%EDX) , %EAX
		MOVL  %EAX ,100(%EDX)

	_035:	LEAL 16(%ECX) , %EAX
		PUSHL  %EAX
		MOVL 100(%EDX) , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_036:	MOVL (%ECX) , %EAX
		MOVL 4(%ECX) , %EBX
		CMPL %EAX , %EBX
		JL _044

	_037:	JMP  _038

	_038:	LEAL 8(%ECX) , %EAX
		PUSHL  %EAX
		MOVL $2 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_039:	LEAL 12(%ECX) , %EAX
		PUSHL  %EAX
		MOVL $1 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_040:	MOVL  8(%ECX) , %EAX
		ADDL  12(%ECX) , %EAX
		MOVL  %EAX ,104(%EDX)

	_041:	MOVL  104(%EDX) , %EAX
		ADDL  $5 , %EAX
		MOVL  %EAX ,108(%EDX)

	_042:	LEAL (%ECX) , %EAX
		PUSHL  %EAX
		MOVL 108(%EDX) , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_043:	JMP  _049

	_044:	LEAL 8(%ECX) , %EAX
		PUSHL  %EAX
		MOVL $1 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_045:	LEAL 12(%ECX) , %EAX
		PUSHL  %EAX
		MOVL $0 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_046:	MOVL  8(%ECX) , %EAX
		ADDL  12(%ECX) , %EAX
		MOVL  %EAX ,112(%EDX)

	_047:	MOVL  112(%EDX) , %EAX
		ADDL  $5 , %EAX
		MOVL  %EAX ,116(%EDX)

	_048:	LEAL (%ECX) , %EAX
		PUSHL  %EAX
		MOVL 116(%EDX) , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_049:	LEAL 120(%EDX) , %EAX
		PUSHL  %EAX
		MOVL $0 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_050:	PUSHL  %ECX
		PUSHL  %EDX
		PUSHL  (%ECX)
		PUSHL  $intf
		CALL printf
		POPL  %EAX
		POPL  %EAX
		POPL  %EDX
		POPL  %ECX

	_051:	LEAL 4(%ECX) , %EAX
		PUSHL  %EAX
		MOVL $5 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_052:	LEAL (%ECX) , %EAX
		PUSHL  %EAX
		MOVL $0 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_053:	MOVL 12(%ECX) , %EAX
		MOVL $5 , %EBX
		CMPL %EAX , %EBX
		JG _055

	_054:	JMP  _063

	_055:	MOVL  (%ECX) , %EAX
		ADDL  $1 , %EAX
		MOVL  %EAX ,124(%EDX)

	_056:	LEAL (%ECX) , %EAX
		PUSHL  %EAX
		MOVL 124(%EDX) , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_057:	MOVL (%ECX) , %EAX
		MOVL 4(%ECX) , %EBX
		CMPL %EAX , %EBX
		JL _059

	_058:	JMP  _061

	_059:	MOVL  12(%ECX) , %EAX
		ADDL  $1 , %EAX
		MOVL  %EAX ,128(%EDX)

	_060:	LEAL 12(%ECX) , %EAX
		PUSHL  %EAX
		MOVL 128(%EDX) , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_061:	LEAL 132(%EDX) , %EAX
		PUSHL  %EAX
		MOVL $0 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_062:	JMP  _053

	_063:	LEAL 136(%EDX) , %EAX
		PUSHL  %EAX
		MOVL $0 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_064:	PUSHL  %ECX
		PUSHL  %EDX
		PUSHL  12(%ECX)
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
