	.text
	.file	"test.c"
	.globl	sum                     # -- Begin function sum
	.p2align	4, 0x90
	.type	sum,@function
sum:                                    # @sum
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%eax
	movss	12(%ebp), %xmm0         # xmm0 = mem[0],zero,zero,zero
	movss	8(%ebp), %xmm1          # xmm1 = mem[0],zero,zero,zero
	movss	8(%ebp), %xmm2          # xmm2 = mem[0],zero,zero,zero
	movss	12(%ebp), %xmm3         # xmm3 = mem[0],zero,zero,zero
	addss	%xmm3, %xmm2
	movss	%xmm2, -4(%ebp)
	flds	-4(%ebp)
	addl	$4, %esp
	popl	%ebp
	retl
.Lfunc_end0:
	.size	sum, .Lfunc_end0-sum
                                        # -- End function

	.ident	"clang version 9.0.1 (https://github.com/lisitsynSA/softPosit.git 2a42b492b2fbc01ebc12c466e6ade530d7c0ff7e)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
