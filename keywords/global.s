	.file	"global.c"
	.comm	globalX,4,4
	.globl	globalY_0
	.bss
	.align 4
	.type	globalY_0, @object
	.size	globalY_0, 4
globalY_0:
	.zero	4
	.globl	globalZ_256
	.data
	.align 4
	.type	globalZ_256, @object
	.size	globalZ_256, 4
globalZ_256:
	.long	256
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
	movl	$128, -8(%ebp)
	movl	globalZ_256, %eax
	subl	$1, %eax
	movl	%eax, globalZ_256
	subl	$1, -8(%ebp)
	movl	globalX, %edx
	movl	globalY_0, %eax
	addl	%eax, %edx
	movl	globalZ_256, %eax
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
