	.file	"const.c"
	.comm	globalConstX,4,4
	.globl	globalConstY_0
	.section	.rodata
	.align 4
	.type	globalConstY_0, @object
	.size	globalConstY_0, 4
globalConstY_0:
	.zero	4
	.globl	globalConstZ_1000
	.align 4
	.type	globalConstZ_1000, @object
	.size	globalConstZ_1000, 4
globalConstZ_1000:
	.long	1000
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
	movl	$0, -12(%ebp)
	movl	$64, -8(%ebp)
	movl	globalConstX, %edx
	movl	$0, %eax
	addl	%eax, %edx
	movl	$1000, %eax
	addl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-4(%ebp), %eax
	addl	%eax, %edx
	movl	-12(%ebp), %eax
	addl	%eax, %edx
	movl	-8(%ebp), %eax
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
