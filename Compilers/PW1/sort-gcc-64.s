	.file	"sort.c"
	.text
	.globl	sort
	.type	sort, @function
sort:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp								# save rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp							# save rsp to rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$0, -12(%rbp)						# i = 0
	jmp	.L2
.L6:
	movl	$0, -8(%rbp)						# j = 0
	jmp	.L3
.L5:
	movl	-8(%rbp), %eax						# load j
	cltq										# rax extend
	leaq	0(,%rax,4), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx						# load num[j]
	movl	-8(%rbp), %eax
	cltq
	addq	$1, %rax							# j + 1
	leaq	0(,%rax,4), %rcx	
	movq	-32(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax						# load num[j+1]
	cmpl	%eax, %edx							# compare num[j] with num[j+1]
	jle	.L4
	movl	-8(%rbp), %eax						# load j to eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax						# load num[j]
	movl	%eax, -4(%rbp)						# temp = num[j]
	movl	-8(%rbp), %eax						# load j to eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax							# addr of num[j+1]
	movl	-8(%rbp), %edx						# j
	movslq	%edx, %rdx						
	leaq	0(,%rdx,4), %rcx					# offset	
	movq	-32(%rbp), %rdx						
	addq	%rcx, %rdx							# addr of num[j]
	movl	(%rax), %eax						# load num[j+1]
	movl	%eax, (%rdx)						# num[j] = num[j+1]
	movl	-8(%rbp), %eax
	cltq
	addq	$1, %rax							
	leaq	0(,%rax,4), %rdx
	movq	-32(%rbp), %rax
	addq	%rax, %rdx							# addr of num[j]
	movl	-4(%rbp), %eax
	movl	%eax, (%rdx)						# num[j+1] = temp
.L4:
	addl	$1, -8(%rbp)						# j = j + 1
.L3:
	movl	-20(%rbp), %eax
	subl	-12(%rbp), %eax
	subl	$1, %eax							# n - i - 1
	cmpl	%eax, -8(%rbp)						# compare j and n - i -1
	jl	.L5
	addl	$1, -12(%rbp)
.L2:
	movl	-12(%rbp), %eax
	cmpl	-20(%rbp), %eax						# compare i with n
	jl	.L6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	sort, .-sort
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"%d "
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	-36864(%rsp), %r11
.LPSRL0:										# scanf n
	subq	$4096, %rsp
	orq	$0, (%rsp)
	cmpq	%r11, %rsp
	jne	.LPSRL0
	subq	$3168, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-40028(%rbp), %rax
	movq	%rax, %rsi							# save &n for scanf
	leaq	.LC0(%rip), %rax				
	movq	%rax, %rdi							# save %d for scanf	
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	$0, -40024(%rbp)
	jmp	.L9
.L10:											# scanf num
	movl	-40024(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	-40016(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, %rsi							# save num + i for scanf
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi							# save %d for scanf
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	addl	$1, -40024(%rbp)
.L9:
	movl	-40028(%rbp), %eax
	cmpl	%eax, -40024(%rbp)
	jl	.L10
	movl	-40028(%rbp), %eax
	leaq	-40016(%rbp), %rdx
	movq	%rdx, %rsi							# save *num for sort
	movl	%eax, %edi							# save n for sort
	call	sort
	movl	$0, -40020(%rbp)
	jmp	.L11
.L12:
	movl	-40020(%rbp), %eax
	cltq
	movl	-40016(%rbp,%rax,4), %eax
	movl	%eax, %esi							# save num[i] for printf
	leaq	.LC1(%rip), %rax					# save %d for printf
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -40020(%rbp)
.L11:
	movl	-40028(%rbp), %eax
	cmpl	%eax, -40020(%rbp)
	jl	.L12
	movl	$10, %edi
	call	putchar@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L14
	call	__stack_chk_fail@PLT
.L14:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.2.0-19ubuntu1) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
