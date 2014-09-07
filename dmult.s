	.file	"dmult.c"
	.text
.globl multiply
	.type	multiply, @function
multiply:
.LFB0:
	.cfi_startproc
	mulsd	%xmm1, %xmm0
	ret
	.cfi_endproc
.LFE0:
	.size	multiply, .-multiply
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-4)"
	.section	.note.GNU-stack,"",@progbits
