
volatile.o:     file format elf64-x86-64
volatile.o
architecture: i386:x86-64, flags 0x00000011:
HAS_RELOC, HAS_SYMS
start address 0x0000000000000000

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         00000074  0000000000000000  0000000000000000  00000040  2**0
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  1 .data         00000004  0000000000000000  0000000000000000  000000b4  2**2
                  CONTENTS, ALLOC, LOAD, DATA
  2 .bss          00000004  0000000000000000  0000000000000000  000000b8  2**2
                  ALLOC
  3 .comment      0000002c  0000000000000000  0000000000000000  000000b8  2**0
                  CONTENTS, READONLY
  4 .note.GNU-stack 00000000  0000000000000000  0000000000000000  000000e4  2**0
                  CONTENTS, READONLY
  5 .eh_frame     00000058  0000000000000000  0000000000000000  000000e8  2**3
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, DATA
SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 volatile.c
0000000000000000 l    d  .text	0000000000000000 .text
0000000000000000 l    d  .data	0000000000000000 .data
0000000000000000 l    d  .bss	0000000000000000 .bss
0000000000000000 l    d  .note.GNU-stack	0000000000000000 .note.GNU-stack
0000000000000000 l    d  .eh_frame	0000000000000000 .eh_frame
0000000000000000 l    d  .comment	0000000000000000 .comment
0000000000000004       O *COM*	0000000000000004 globalVolatileX
0000000000000000 g     O .bss	0000000000000004 globalVolatileY_0
0000000000000000 g     O .data	0000000000000004 globalVolatileZ_512
0000000000000000 g     F .text	0000000000000059 func
0000000000000059 g     F .text	000000000000001b main



Disassembly of section .text:

0000000000000000 <func>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	89 7d ec             	mov    %edi,-0x14(%rbp)
   7:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%rbp)
   e:	c7 45 fc 10 00 00 00 	movl   $0x10,-0x4(%rbp)
  15:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 1b <func+0x1b>
			17: R_X86_64_PC32	globalVolatileZ_512-0x4
  1b:	83 c0 01             	add    $0x1,%eax
  1e:	89 05 00 00 00 00    	mov    %eax,0x0(%rip)        # 24 <func+0x24>
			20: R_X86_64_PC32	globalVolatileZ_512-0x4
  24:	8b 45 fc             	mov    -0x4(%rbp),%eax
  27:	83 e8 01             	sub    $0x1,%eax
  2a:	89 45 fc             	mov    %eax,-0x4(%rbp)
  2d:	8b 15 00 00 00 00    	mov    0x0(%rip),%edx        # 33 <func+0x33>
			2f: R_X86_64_PC32	globalVolatileX-0x4
  33:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 39 <func+0x39>
			35: R_X86_64_PC32	globalVolatileY_0-0x4
  39:	01 c2                	add    %eax,%edx
  3b:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 41 <func+0x41>
			3d: R_X86_64_PC32	globalVolatileZ_512-0x4
  41:	01 c2                	add    %eax,%edx
  43:	8b 45 ec             	mov    -0x14(%rbp),%eax
  46:	01 c2                	add    %eax,%edx
  48:	8b 45 f4             	mov    -0xc(%rbp),%eax
  4b:	01 c2                	add    %eax,%edx
  4d:	8b 45 f8             	mov    -0x8(%rbp),%eax
  50:	01 c2                	add    %eax,%edx
  52:	8b 45 fc             	mov    -0x4(%rbp),%eax
  55:	01 d0                	add    %edx,%eax
  57:	5d                   	pop    %rbp
  58:	c3                   	retq   

0000000000000059 <main>:
  59:	55                   	push   %rbp
  5a:	48 89 e5             	mov    %rsp,%rbp
  5d:	48 83 ec 10          	sub    $0x10,%rsp
  61:	c7 45 fc ff ff ff ff 	movl   $0xffffffff,-0x4(%rbp)
  68:	8b 45 fc             	mov    -0x4(%rbp),%eax
  6b:	89 c7                	mov    %eax,%edi
  6d:	e8 00 00 00 00       	callq  72 <main+0x19>
			6e: R_X86_64_PC32	func-0x4
  72:	c9                   	leaveq 
  73:	c3                   	retq   
