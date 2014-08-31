	.file	"hello.c"
	.globl	s
	.data
	.type	s, @object
	.size	s, 13
s:
	.string	"Hello World!"
	.local	i
	.comm	i,4,4
	.globl	lol
	.section	.rodata
	.align 4
	.type	lol, @object
	.size	lol, 4
lol:
	.long	14
.LC0:
	.string	"Hello, world!"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC0, %edi
	call	puts
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	multiply
	.type	multiply, @function
multiply:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movss	%xmm0, -4(%rbp)
	movss	%xmm1, -8(%rbp)
	movss	-4(%rbp), %xmm0
	mulss	-8(%rbp), %xmm0
	movss	%xmm0, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, -12(%rbp)
	movss	-12(%rbp), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	multiply, .-multiply
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
