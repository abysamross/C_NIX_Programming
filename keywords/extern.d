
extern.o:     file format elf64-x86-64
extern.o
architecture: i386:x86-64, flags 0x00000011:
HAS_RELOC, HAS_SYMS
start address 0x0000000000000000

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         00000014  0000000000000000  0000000000000000  00000040  2**0
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  1 .data         00000000  0000000000000000  0000000000000000  00000054  2**0
                  CONTENTS, ALLOC, LOAD, DATA
  2 .bss          00000000  0000000000000000  0000000000000000  00000054  2**0
                  ALLOC
  3 .comment      0000002c  0000000000000000  0000000000000000  00000054  2**0
                  CONTENTS, READONLY
  4 .note.GNU-stack 00000000  0000000000000000  0000000000000000  00000080  2**0
                  CONTENTS, READONLY
  5 .eh_frame     00000038  0000000000000000  0000000000000000  00000080  2**3
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, DATA
SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 extern.c
0000000000000000 l    d  .text	0000000000000000 .text
0000000000000000 l    d  .data	0000000000000000 .data
0000000000000000 l    d  .bss	0000000000000000 .bss
0000000000000000 l    d  .note.GNU-stack	0000000000000000 .note.GNU-stack
0000000000000000 l    d  .eh_frame	0000000000000000 .eh_frame
0000000000000000 l    d  .comment	0000000000000000 .comment
0000000000000000 g     F .text	0000000000000014 func
0000000000000000         *UND*	0000000000000000 globalExternIntE1
0000000000000000         *UND*	0000000000000000 globalExternIntE2



Disassembly of section .text:

0000000000000000 <func>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	8b 15 00 00 00 00    	mov    0x0(%rip),%edx        # a <func+0xa>
			6: R_X86_64_PC32	globalExternIntE1-0x4
   a:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 10 <func+0x10>
			c: R_X86_64_PC32	globalExternIntE2-0x4
  10:	01 d0                	add    %edx,%eax
  12:	5d                   	pop    %rbp
  13:	c3                   	retq   
