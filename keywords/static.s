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
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	globalStaticZ_256, %eax
	subl	$1, %eax
	movl	%eax, globalStaticZ_256
	movl	localStaticD_32.1376, %eax
	subl	$1, %eax
	movl	%eax, localStaticD_32.1376
	movl	globalStaticX, %edx
	movl	globalStaticY_0, %eax
	addl	%eax, %edx
	movl	globalStaticZ_256, %eax
	addl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	localStaticB.1374, %eax
	addl	%eax, %edx
	movl	localStaticC_0.1375, %eax
	addl	%eax, %edx
	movl	localStaticD_32.1376, %eax
	addl	%edx, %eax
	popl	%ebp
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
	.data
	.align 4
	.type	localStaticD_32.1376, @object
	.size	localStaticD_32.1376, 4
localStaticD_32.1376:
	.long	32
	.local	localStaticB.1374
	.comm	localStaticB.1374,4,4
	.local	localStaticC_0.1375
	.comm	localStaticC_0.1375,4,4
	.ident	"GCC: (Ubuntu 4.8.5-2ubuntu1~14.04.1) 4.8.5"
	.section	.note.GNU-stack,"",@progbits
