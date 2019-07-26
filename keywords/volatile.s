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
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -8(%ebp)
	movl	$16, -4(%ebp)
	movl	globalVolatileZ_512, %eax
	addl	$1, %eax
	movl	%eax, globalVolatileZ_512
	movl	-4(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -4(%ebp)
	movl	globalVolatileX, %edx
	movl	globalVolatileY_0, %eax
	addl	%eax, %edx
	movl	globalVolatileZ_512, %eax
	addl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-12(%ebp), %eax
	addl	%eax, %edx
	movl	-8(%ebp), %eax
	addl	%eax, %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	func, .-func
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	$-1, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	func
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.5-2ubuntu1~14.04.1) 4.8.5"
	.section	.note.GNU-stack,"",@progbits
