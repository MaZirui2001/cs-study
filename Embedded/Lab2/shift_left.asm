	.arch armv8-a
	.file	"shift_left.c"
	.text
	.global	a
	.bss
	.align	3
	.type	a, %object
	.size	a, 40
a:
	.zero	40
	.text
	.align	2
	.global	gcd
	.type	gcd, %function
gcd:
.LFB0:
	.cfi_startproc
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	w0, [sp, 12]
	str	w1, [sp, 8]
	ldr	w0, [sp, 12]
	ldr	w1, [sp, 8]
	sdiv	w2, w0, w1
	ldr	w1, [sp, 8]
	mul	w1, w2, w1
	sub	w0, w0, w1
	str	w0, [sp, 28]
	b	.L2
.L3:
	ldr	w0, [sp, 8]
	str	w0, [sp, 12]
	ldr	w0, [sp, 28]
	str	w0, [sp, 8]
	ldr	w0, [sp, 12]
	ldr	w1, [sp, 8]
	sdiv	w2, w0, w1
	ldr	w1, [sp, 8]
	mul	w1, w2, w1
	sub	w0, w0, w1
	str	w0, [sp, 28]
.L2:
	ldr	w0, [sp, 28]
	cmp	w0, 0
	bne	.L3
	ldr	w0, [sp, 8]
	add	sp, sp, 32
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE0:
	.size	gcd, .-gcd
	.align	2
	.global	shift_left
	.type	shift_left, %function
shift_left:
.LFB1:
	.cfi_startproc
	stp	x29, x30, [sp, -64]!
	.cfi_def_cfa_offset 64
	.cfi_offset 29, -64
	.cfi_offset 30, -56
	mov	x29, sp
	str	w0, [sp, 28]
	str	w1, [sp, 24]
	ldr	w1, [sp, 28]
	ldr	w0, [sp, 24]
	bl	gcd
	str	w0, [sp, 48]
	str	wzr, [sp, 56]
	b	.L6
.L9:
	adrp	x0, a
	add	x0, x0, :lo12:a
	ldrsw	x1, [sp, 56]
	ldr	w0, [x0, x1, lsl 2]
	str	w0, [sp, 44]
	ldr	w0, [sp, 56]
	str	w0, [sp, 60]
	str	wzr, [sp, 52]
	b	.L7
.L8:
	ldr	w1, [sp, 60]
	ldr	w0, [sp, 28]
	add	w0, w1, w0
	ldr	w1, [sp, 24]
	sdiv	w2, w0, w1
	ldr	w1, [sp, 24]
	mul	w1, w2, w1
	sub	w1, w0, w1
	adrp	x0, a
	add	x0, x0, :lo12:a
	sxtw	x1, w1
	ldr	w2, [x0, x1, lsl 2]
	adrp	x0, a
	add	x0, x0, :lo12:a
	ldrsw	x1, [sp, 60]
	str	w2, [x0, x1, lsl 2]
	ldr	w1, [sp, 60]
	ldr	w0, [sp, 28]
	add	w0, w1, w0
	ldr	w1, [sp, 24]
	sdiv	w2, w0, w1
	ldr	w1, [sp, 24]
	mul	w1, w2, w1
	sub	w0, w0, w1
	str	w0, [sp, 60]
	ldr	w0, [sp, 52]
	add	w0, w0, 1
	str	w0, [sp, 52]
.L7:
	ldr	w1, [sp, 24]
	ldr	w0, [sp, 48]
	sdiv	w0, w1, w0
	sub	w0, w0, #1
	ldr	w1, [sp, 52]
	cmp	w1, w0
	blt	.L8
	adrp	x0, a
	add	x0, x0, :lo12:a
	ldrsw	x1, [sp, 60]
	ldr	w2, [sp, 44]
	str	w2, [x0, x1, lsl 2]
	ldr	w0, [sp, 56]
	add	w0, w0, 1
	str	w0, [sp, 56]
.L6:
	ldr	w1, [sp, 56]
	ldr	w0, [sp, 48]
	cmp	w1, w0
	blt	.L9
	nop
	nop
	ldp	x29, x30, [sp], 64
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1:
	.size	shift_left, .-shift_left
	.section	.rodata
	.align	3
.LC0:
	.string	"%d %d"
	.align	3
.LC1:
	.string	"%d"
	.align	3
.LC2:
	.string	"%d "
	.text
	.align	2
	.global	main
	.type	main, %function
main:
.LFB2:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	add	x1, sp, 20
	add	x0, sp, 24
	mov	x2, x1
	mov	x1, x0
	adrp	x0, .LC0
	add	x0, x0, :lo12:.LC0
	bl	__isoc99_scanf
	str	wzr, [sp, 28]
	b	.L11
.L12:
	ldrsw	x0, [sp, 28]
	lsl	x1, x0, 2
	adrp	x0, a
	add	x0, x0, :lo12:a
	add	x0, x1, x0
	mov	x1, x0
	adrp	x0, .LC1
	add	x0, x0, :lo12:.LC1
	bl	__isoc99_scanf
	ldr	w0, [sp, 28]
	add	w0, w0, 1
	str	w0, [sp, 28]
.L11:
	ldr	w0, [sp, 24]
	ldr	w1, [sp, 28]
	cmp	w1, w0
	blt	.L12
	ldr	w0, [sp, 20]
	ldr	w1, [sp, 24]
	bl	shift_left
	str	wzr, [sp, 28]
	b	.L13
.L14:
	adrp	x0, a
	add	x0, x0, :lo12:a
	ldrsw	x1, [sp, 28]
	ldr	w0, [x0, x1, lsl 2]
	mov	w1, w0
	adrp	x0, .LC2
	add	x0, x0, :lo12:.LC2
	bl	printf
	ldr	w0, [sp, 28]
	add	w0, w0, 1
	str	w0, [sp, 28]
.L13:
	ldr	w0, [sp, 24]
	ldr	w1, [sp, 28]
	cmp	w1, w0
	blt	.L14
	mov	w0, 10
	bl	putchar
	mov	w0, 0
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
