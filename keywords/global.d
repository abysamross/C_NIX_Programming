
global.o:     file format elf64-x86-64
global.o
architecture: i386:x86-64, flags 0x00000011:
HAS_RELOC, HAS_SYMS
start address 0x0000000000000000

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         0000006f  0000000000000000  0000000000000000  00000040  2**0
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  1 .data         00000004  0000000000000000  0000000000000000  000000b0  2**2
                  CONTENTS, ALLOC, LOAD, DATA
  2 .bss          00000004  0000000000000000  0000000000000000  000000b4  2**2
                  ALLOC
  3 .comment      0000002c  0000000000000000  0000000000000000  000000b4  2**0
                  CONTENTS, READONLY
  4 .note.GNU-stack 00000000  0000000000000000  0000000000000000  000000e0  2**0
                  CONTENTS, READONLY
  5 .eh_frame     00000058  0000000000000000  0000000000000000  000000e0  2**3
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, DATA
SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 global.c
0000000000000000 l    d  .text	0000000000000000 .text
0000000000000000 l    d  .data	0000000000000000 .data
0000000000000000 l    d  .bss	0000000000000000 .bss
0000000000000000 l    d  .note.GNU-stack	0000000000000000 .note.GNU-stack
0000000000000000 l    d  .eh_frame	0000000000000000 .eh_frame
0000000000000000 l    d  .comment	0000000000000000 .comment
0000000000000004       O *COM*	0000000000000004 globalX
0000000000000000 g     O .bss	0000000000000004 globalY_0
0000000000000000 g     O .data	0000000000000004 globalZ_256
0000000000000000 g     F .text	0000000000000054 func
0000000000000054 g     F .text	000000000000001b main



Disassembly of section .text:

0000000000000000 <func>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	89 7d ec             	mov    %edi,-0x14(%rbp)
   7:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
   e:	c7 45 f8 80 00 00 00 	movl   $0x80,-0x8(%rbp)
  15:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 1b <func+0x1b>
			17: R_X86_64_PC32	globalZ_256-0x4
  1b:	83 e8 01             	sub    $0x1,%eax
  1e:	89 05 00 00 00 00    	mov    %eax,0x0(%rip)        # 24 <func+0x24>
			20: R_X86_64_PC32	globalZ_256-0x4
  24:	83 6d f8 01          	subl   $0x1,-0x8(%rbp)
  28:	8b 15 00 00 00 00    	mov    0x0(%rip),%edx        # 2e <func+0x2e>
			2a: R_X86_64_PC32	globalX-0x4
  2e:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 34 <func+0x34>
			30: R_X86_64_PC32	globalY_0-0x4
  34:	01 c2                	add    %eax,%edx
  36:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 3c <func+0x3c>
			38: R_X86_64_PC32	globalZ_256-0x4
  3c:	01 c2                	add    %eax,%edx
  3e:	8b 45 ec             	mov    -0x14(%rbp),%eax
  41:	01 c2                	add    %eax,%edx
  43:	8b 45 fc             	mov    -0x4(%rbp),%eax
  46:	01 c2                	add    %eax,%edx
  48:	8b 45 f4             	mov    -0xc(%rbp),%eax
  4b:	01 c2                	add    %eax,%edx
  4d:	8b 45 f8             	mov    -0x8(%rbp),%eax
  50:	01 d0                	add    %edx,%eax
  52:	5d                   	pop    %rbp
  53:	c3                   	retq   

0000000000000054 <main>:
  54:	55                   	push   %rbp
  55:	48 89 e5             	mov    %rsp,%rbp
  58:	48 83 ec 10          	sub    $0x10,%rsp
  5c:	c7 45 fc ff ff ff ff 	movl   $0xffffffff,-0x4(%rbp)
  63:	8b 45 fc             	mov    -0x4(%rbp),%eax
  66:	89 c7                	mov    %eax,%edi
  68:	e8 00 00 00 00       	callq  6d <main+0x19>
			69: R_X86_64_PC32	func-0x4
  6d:	c9                   	leaveq 
  6e:	c3                   	retq   
