	.file	"gcd.cpp"
	.text
	.section	.text._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt5ctypeIcE8do_widenEc
	.type	_ZNKSt5ctypeIcE8do_widenEc, @function
_ZNKSt5ctypeIcE8do_widenEc:
.LFB1535:
	.cfi_startproc
	movl	%esi, %eax
	ret
	.cfi_endproc
.LFE1535:
	.size	_ZNKSt5ctypeIcE8do_widenEc, .-_ZNKSt5ctypeIcE8do_widenEc
	.text
	.p2align 4
	.globl	_Z10bubblesortPii
	.type	_Z10bubblesortPii, @function
_Z10bubblesortPii:
.LFB1782:
	.cfi_startproc
	testl	%esi, %esi
	je	.L3
	leal	-1(%rsi), %r8d
	leaq	4(%rdi), %r9
	testl	%r8d, %r8d
	jle	.L18
	.p2align 4,,10
	.p2align 3
.L19:
	leal	-2(%rsi), %edx
	movq	%rdi, %rax
	leaq	(%r9,%rdx,4), %rsi
	.p2align 4,,10
	.p2align 3
.L8:
	movl	(%rax), %ecx
	movl	4(%rax), %edx
	cmpl	%edx, %ecx
	jle	.L7
	movl	%ecx, 4(%rax)
	movl	%edx, (%rax)
.L7:
	addq	$4, %rax
	cmpq	%rsi, %rax
	jne	.L8
.L9:
	movl	%r8d, %esi
	leal	-1(%rsi), %r8d
	testl	%r8d, %r8d
	jg	.L19
.L18:
	jne	.L9
.L3:
	ret
	.cfi_endproc
.LFE1782:
	.size	_Z10bubblesortPii, .-_Z10bubblesortPii
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB1783:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	movl	$6, %esi
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$40, %rsp
	.cfi_def_cfa_offset 80
	movdqa	.LC0(%rip), %xmm0
	movq	.LC1(%rip), %rax
	movq	%rsp, %rdi
	movq	%rsp, %rbp
	leaq	24(%rsp), %r13
	movq	%rax, 16(%rsp)
	movaps	%xmm0, (%rsp)
	call	_Z10bubblesortPii
	jmp	.L24
	.p2align 4,,10
	.p2align 3
.L31:
	movsbl	67(%r12), %esi
.L23:
	movq	%rbx, %rdi
	addq	$4, %rbp
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	cmpq	%rbp, %r13
	je	.L29
.L24:
	movl	0(%rbp), %esi
	movl	$_ZSt4cout, %edi
	call	_ZNSolsEi
	movq	%rax, %rbx
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbx,%rax), %r12
	testq	%r12, %r12
	je	.L30
	cmpb	$0, 56(%r12)
	jne	.L31
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r12), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L23
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L23
	.p2align 4,,10
	.p2align 3
.L29:
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
.L30:
	.cfi_restore_state
	call	_ZSt16__throw_bad_castv
	.cfi_endproc
.LFE1783:
	.size	main, .-main
	.p2align 4
	.type	_GLOBAL__sub_I__Z10bubblesortPii, @function
_GLOBAL__sub_I__Z10bubblesortPii:
.LFB2313:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit
	.cfi_endproc
.LFE2313:
	.size	_GLOBAL__sub_I__Z10bubblesortPii, .-_GLOBAL__sub_I__Z10bubblesortPii
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z10bubblesortPii
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	6
	.long	5
	.long	4
	.long	3
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	2
	.long	1
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
