	.file	"hw13.cpp"
	.text
	.globl	_Z1fsf
	.type	_Z1fsf, @function
_Z1fsf:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp				// 保存栈基指针
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp			// 更改栈基指针，用以分配本函数的栈空间
	.cfi_def_cfa_register 6
	movl	%edi, %eax			// 将参数a的值迁移至eax
	movss	%xmm0, -8(%rbp)		// 将参数f的值迁移至栈中
	movw	%ax, -4(%rbp)		// 将a的值存入栈中
	cmpw	$2, -4(%rbp)		// 比较a和2的大小
	jne	.L2						// 若a不等于2，则进入L2
	movss	-8(%rbp), %xmm0		// 若a等于2， 则将f存入xmm0寄存器
	cvttss2sil	%xmm0, %eax     // 将f转换为一个整数存入eax，准备作为返回值返回
	jmp	.L3						// 前往返回调用者的代码段
.L2:
	movzwl	-4(%rbp), %eax		// 将a存入eax，准备作为返回值返回
.L3:
	popq	%rbp				// 恢复栈空间
	.cfi_def_cfa 7, 8
	ret							// 返回调用者
	.cfi_endproc
.LFE0:
	.size	_Z1fsf, .-_Z1fsf
	.ident	"GCC: (Ubuntu 12.2.0-3ubuntu1) 12.2.0"
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
