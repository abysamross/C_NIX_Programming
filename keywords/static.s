	.file	"static.c"
	.local	globalStaticX
	.comm	globalStaticX,4,4
	.local	globalStaticY_0
	.comm	globalStaticY_0,4,4
	.data
	.align 4
	.type	globalStaticZ_256, @object
	.size	globalStaticZ_256, 4
globalStaticZ_256:
	.long	256
	.text
	.globl	func
	.type	func, @function
func:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	globalStaticZ_256(%rip), %eax
	subl	$1, %eax
	movl	%eax, globalStaticZ_256(%rip)
	movl	localStaticD_32.1729(%rip), %eax
	subl	$1, %eax
	movl	%eax, localStaticD_32.1729(%rip)
	movl	globalStaticX(%rip), %edx
	movl	globalStaticY_0(%rip), %eax
	addl	%eax, %edx
	movl	globalStaticZ_256(%rip), %eax
	addl	%eax, %edx
	movl	-4(%rbp), %eax
	addl	%eax, %edx
	movl	localStaticB.1727(%rip), %eax
	addl	%eax, %edx
	movl	localStaticC_0.1728(%rip), %eax
	addl	%eax, %edx
	movl	localStaticD_32.1729(%rip), %eax
	addl	%edx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	func, .-func
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$-1, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	func
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.data
	.align 4
	.type	localStaticD_32.1729, @object
	.size	localStaticD_32.1729, 4
localStaticD_32.1729:
	.long	32
	.local	localStaticB.1727
	.comm	localStaticB.1727,4,4
	.local	localStaticC_0.1728
	.comm	localStaticC_0.1728,4,4
	.ident	"GCC: (Ubuntu 4.8.5-2ubuntu1~14.04.1) 4.8.5"
	.section	.note.GNU-stack,"",@progbits
