
const.o:     file format elf64-x86-64
const.o
architecture: i386:x86-64, flags 0x00000011:
HAS_RELOC, HAS_SYMS
start address 0x0000000000000000

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         0000005a  0000000000000000  0000000000000000  00000040  2**0
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  1 .data         00000000  0000000000000000  0000000000000000  0000009a  2**0
                  CONTENTS, ALLOC, LOAD, DATA
  2 .bss          00000000  0000000000000000  0000000000000000  0000009a  2**0
                  ALLOC
  3 .rodata       00000008  0000000000000000  0000000000000000  0000009c  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  4 .comment      0000002c  0000000000000000  0000000000000000  000000a4  2**0
                  CONTENTS, READONLY
  5 .note.GNU-stack 00000000  0000000000000000  0000000000000000  000000d0  2**0
                  CONTENTS, READONLY
  6 .eh_frame     00000058  0000000000000000  0000000000000000  000000d0  2**3
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, DATA
SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 const.c
0000000000000000 l    d  .text	0000000000000000 .text
0000000000000000 l    d  .data	0000000000000000 .data
0000000000000000 l    d  .bss	0000000000000000 .bss
0000000000000000 l    d  .rodata	0000000000000000 .rodata
0000000000000000 l    d  .note.GNU-stack	0000000000000000 .note.GNU-stack
0000000000000000 l    d  .eh_frame	0000000000000000 .eh_frame
0000000000000000 l    d  .comment	0000000000000000 .comment
0000000000000004       O *COM*	0000000000000004 globalConstX
0000000000000000 g     O .rodata	0000000000000004 globalConstY_0
0000000000000004 g     O .rodata	0000000000000004 globalConstZ_1000
0000000000000000 g     F .text	000000000000003f func
000000000000003f g     F .text	000000000000001b main



Disassembly of section .text:

0000000000000000 <func>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	89 7d ec             	mov    %edi,-0x14(%rbp)
   7:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
   e:	c7 45 f8 40 00 00 00 	movl   $0x40,-0x8(%rbp)
  15:	8b 15 00 00 00 00    	mov    0x0(%rip),%edx        # 1b <func+0x1b>
			17: R_X86_64_PC32	globalConstX-0x4
  1b:	b8 00 00 00 00       	mov    $0x0,%eax
  20:	01 c2                	add    %eax,%edx
  22:	b8 e8 03 00 00       	mov    $0x3e8,%eax
  27:	01 c2                	add    %eax,%edx
  29:	8b 45 ec             	mov    -0x14(%rbp),%eax
  2c:	01 c2                	add    %eax,%edx
  2e:	8b 45 fc             	mov    -0x4(%rbp),%eax
  31:	01 c2                	add    %eax,%edx
  33:	8b 45 f4             	mov    -0xc(%rbp),%eax
  36:	01 c2                	add    %eax,%edx
  38:	8b 45 f8             	mov    -0x8(%rbp),%eax
  3b:	01 d0                	add    %edx,%eax
  3d:	5d                   	pop    %rbp
  3e:	c3                   	retq   

000000000000003f <main>:
  3f:	55                   	push   %rbp
  40:	48 89 e5             	mov    %rsp,%rbp
  43:	48 83 ec 10          	sub    $0x10,%rsp
  47:	c7 45 fc ff ff ff ff 	movl   $0xffffffff,-0x4(%rbp)
  4e:	8b 45 fc             	mov    -0x4(%rbp),%eax
  51:	89 c7                	mov    %eax,%edi
  53:	e8 00 00 00 00       	callq  58 <main+0x19>
			54: R_X86_64_PC32	func-0x4
  58:	c9                   	leaveq 
  59:	c3                   	retq   
