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
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	$0, -12(%rbp)
	movl	$128, -8(%rbp)
	movl	globalZ_256(%rip), %eax
	subl	$1, %eax
	movl	%eax, globalZ_256(%rip)
	subl	$1, -8(%rbp)
	movl	globalX(%rip), %edx
	movl	globalY_0(%rip), %eax
	addl	%eax, %edx
	movl	globalZ_256(%rip), %eax
	addl	%eax, %edx
	movl	-20(%rbp), %eax
	addl	%eax, %edx
	movl	-4(%rbp), %eax
	addl	%eax, %edx
	movl	-12(%rbp), %eax
	addl	%eax, %edx
	movl	-8(%rbp), %eax
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
