	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	pushq	%r14
	pushq	%rbx
Ltmp6:
	.cfi_offset %rbx, -32
Ltmp7:
	.cfi_offset %r14, -24
	movl	$2520, %ebx             ## imm = 0x9D8
	leaq	L_.str(%rip), %r14
	jmp	LBB0_1
	.align	4, 0x90
LBB0_5:                                 ## %.loopexit
                                        ##   in Loop: Header=BB0_1 Depth=1
	incl	%ebx
LBB0_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_2 Depth 2
	movl	$1, %ecx
	.align	4, 0x90
LBB0_2:                                 ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpl	$19, %ecx
	jg	LBB0_4
## BB#3:                                ##   in Loop: Header=BB0_2 Depth=2
	movl	%ebx, %eax
	cltd
	idivl	%ecx
	incl	%ecx
	testl	%edx, %edx
	je	LBB0_2
	jmp	LBB0_5
	.align	4, 0x90
LBB0_4:                                 ## %.critedge
                                        ##   in Loop: Header=BB0_1 Depth=1
	movq	%r14, %rdi
	movl	%ebx, %esi
	xorb	%al, %al
	callq	_printf
	jmp	LBB0_5
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	 "%d"


.subsections_via_symbols
