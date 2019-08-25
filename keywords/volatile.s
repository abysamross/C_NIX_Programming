	.file	"volatile.c"
	.comm	globalVolatileX,4,4
	.globl	globalVolatileY_0
	.bss
	.align 4
	.type	globalVolatileY_0, @object
	.size	globalVolatileY_0, 4
globalVolatileY_0:
	.zero	4
	.globl	globalVolatileZ_512
	.data
	.align 4
	.type	globalVolatileZ_512, @object
	.size	globalVolatileZ_512, 4
globalVolatileZ_512:
	.long	512
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
	movl	%edi, -20(%rbp)
	movl	$0, -8(%rbp)
	movl	$16, -4(%rbp)
	movl	globalVolatileZ_512(%rip), %eax
	addl	$1, %eax
	movl	%eax, globalVolatileZ_512(%rip)
	movl	-4(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -4(%rbp)
	movl	globalVolatileX(%rip), %edx
	movl	globalVolatileY_0(%rip), %eax
	addl	%eax, %edx
	movl	globalVolatileZ_512(%rip), %eax
	addl	%eax, %edx
	movl	-20(%rbp), %eax
	addl	%eax, %edx
	movl	-12(%rbp), %eax
	addl	%eax, %edx
	movl	-8(%rbp), %eax
	addl	%eax, %edx
	movl	-4(%rbp), %eax
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
	.ident	"GCC: (Ubuntu 4.8.5-2ubuntu1~14.04.1) 4.8.5"
	.section	.note.GNU-stack,"",@progbits
