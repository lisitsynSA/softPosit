	.text
	.file	"test.c"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movq	$0, -16(%rbp)
	movq	$0, -24(%rbp)
	movabsq	$.L.str, %rdi
	leaq	-16(%rbp), %rsi
	leaq	-24(%rbp), %rdx
	movb	$0, %al
	callq	__isoc99_scanf
	movq	-16(%rbp), %rcx
	movl	%eax, -28(%rbp)         # 4-byte Spill
	movq	%rcx, %rax
	xorl	%r8d, %r8d
	movl	%r8d, %edx
	divq	-24(%rbp)
	movabsq	$.L.str.1, %rdi
	movq	%rax, %rsi
	movb	$0, %al
	callq	printf
	xorl	%r8d, %r8d
	movl	%eax, -32(%rbp)         # 4-byte Spill
	movl	%r8d, %eax
	addq	$32, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"%lld %lld"
	.size	.L.str, 10

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"64 bit division is %lld\n"
	.size	.L.str.1, 25


	.ident	"clang version 9.0.1 (https://github.com/lisitsynSA/softPosit.git 7a72c404b3e14d91abb26afba0c1da5efdcb6f1d)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym __isoc99_scanf
	.addrsig_sym printf
