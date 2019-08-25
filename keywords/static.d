
static.o:     file format elf64-x86-64
static.o
architecture: i386:x86-64, flags 0x00000011:
HAS_RELOC, HAS_SYMS
start address 0x0000000000000000

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         00000075  0000000000000000  0000000000000000  00000040  2**0
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  1 .data         00000008  0000000000000000  0000000000000000  000000b8  2**2
                  CONTENTS, ALLOC, LOAD, DATA
  2 .bss          00000010  0000000000000000  0000000000000000  000000c0  2**2
                  ALLOC
  3 .comment      0000002c  0000000000000000  0000000000000000  000000c0  2**0
                  CONTENTS, READONLY
  4 .note.GNU-stack 00000000  0000000000000000  0000000000000000  000000ec  2**0
                  CONTENTS, READONLY
  5 .eh_frame     00000058  0000000000000000  0000000000000000  000000f0  2**3
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, DATA
SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 static.c
0000000000000000 l    d  .text	0000000000000000 .text
0000000000000000 l    d  .data	0000000000000000 .data
0000000000000000 l    d  .bss	0000000000000000 .bss
0000000000000000 l     O .bss	0000000000000004 globalStaticX
0000000000000004 l     O .bss	0000000000000004 globalStaticY_0
0000000000000000 l     O .data	0000000000000004 globalStaticZ_256
0000000000000004 l     O .data	0000000000000004 localStaticD_32.1729
0000000000000008 l     O .bss	0000000000000004 localStaticB.1727
000000000000000c l     O .bss	0000000000000004 localStaticC_0.1728
0000000000000000 l    d  .note.GNU-stack	0000000000000000 .note.GNU-stack
0000000000000000 l    d  .eh_frame	0000000000000000 .eh_frame
0000000000000000 l    d  .comment	0000000000000000 .comment
0000000000000000 g     F .text	000000000000005a func
000000000000005a g     F .text	000000000000001b main



Disassembly of section .text:

0000000000000000 <func>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	89 7d fc             	mov    %edi,-0x4(%rbp)
   7:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # d <func+0xd>
			9: R_X86_64_PC32	.data-0x4
   d:	83 e8 01             	sub    $0x1,%eax
  10:	89 05 00 00 00 00    	mov    %eax,0x0(%rip)        # 16 <func+0x16>
			12: R_X86_64_PC32	.data-0x4
  16:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 1c <func+0x1c>
			18: R_X86_64_PC32	.data
  1c:	83 e8 01             	sub    $0x1,%eax
  1f:	89 05 00 00 00 00    	mov    %eax,0x0(%rip)        # 25 <func+0x25>
			21: R_X86_64_PC32	.data
  25:	8b 15 00 00 00 00    	mov    0x0(%rip),%edx        # 2b <func+0x2b>
			27: R_X86_64_PC32	.bss-0x4
  2b:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 31 <func+0x31>
			2d: R_X86_64_PC32	.bss
  31:	01 c2                	add    %eax,%edx
  33:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 39 <func+0x39>
			35: R_X86_64_PC32	.data-0x4
  39:	01 c2                	add    %eax,%edx
  3b:	8b 45 fc             	mov    -0x4(%rbp),%eax
  3e:	01 c2                	add    %eax,%edx
  40:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 46 <func+0x46>
			42: R_X86_64_PC32	.bss+0x4
  46:	01 c2                	add    %eax,%edx
  48:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 4e <func+0x4e>
			4a: R_X86_64_PC32	.bss+0x8
  4e:	01 c2                	add    %eax,%edx
  50:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 56 <func+0x56>
			52: R_X86_64_PC32	.data
  56:	01 d0                	add    %edx,%eax
  58:	5d                   	pop    %rbp
  59:	c3                   	retq   

000000000000005a <main>:
  5a:	55                   	push   %rbp
  5b:	48 89 e5             	mov    %rsp,%rbp
  5e:	48 83 ec 10          	sub    $0x10,%rsp
  62:	c7 45 fc ff ff ff ff 	movl   $0xffffffff,-0x4(%rbp)
  69:	8b 45 fc             	mov    -0x4(%rbp),%eax
  6c:	89 c7                	mov    %eax,%edi
  6e:	e8 00 00 00 00       	callq  73 <main+0x19>
			6f: R_X86_64_PC32	func-0x4
  73:	c9                   	leaveq 
  74:	c3                   	retq   
