	.text
	.file	"test.c"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$44, %esp
	movl	$0, -16(%ebp)
	movl	$0, -20(%ebp)
	movl	$0, -24(%ebp)
	movl	$0, -28(%ebp)
	movl	$0, -32(%ebp)
	movl	%esp, %eax
	leal	-32(%ebp), %ecx
	movl	%ecx, 8(%eax)
	leal	-24(%ebp), %ecx
	movl	%ecx, 4(%eax)
	movl	$.L.str, (%eax)
	calll	__isoc99_scanf
	movl	-24(%ebp), %ecx
	movl	-20(%ebp), %edx
	movl	-32(%ebp), %esi
	movl	-28(%ebp), %edi
	movl	%esp, %ebx
	movl	%edi, 12(%ebx)
	movl	%esi, 8(%ebx)
	movl	%edx, 4(%ebx)
	movl	%ecx, (%ebx)
	movl	%eax, -36(%ebp)         # 4-byte Spill
	calll	__udivdi3
	movl	%esp, %ecx
	movl	%edx, 8(%ecx)
	movl	%eax, 4(%ecx)
	movl	$.L.str.1, (%ecx)
	calll	printf
	xorl	%ecx, %ecx
	movl	%eax, -40(%ebp)         # 4-byte Spill
	movl	%ecx, %eax
	addl	$44, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
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
