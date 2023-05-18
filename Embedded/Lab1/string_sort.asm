	.arch armv8-a
	.file	"stringsort_io.c"
	.text
	.align	2
	.global	strcmp
	.type	strcmp, %function
strcmp:
.LFB6:
	.cfi_startproc
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	x0, [sp, 8]
	str	x1, [sp]
	str	wzr, [sp, 28]
	b	.L2
.L7:
	ldrsw	x0, [sp, 28]
	ldr	x1, [sp, 8]
	add	x0, x1, x0
	ldrb	w1, [x0]
	ldrsw	x0, [sp, 28]
	ldr	x2, [sp]
	add	x0, x2, x0
	ldrb	w0, [x0]
	cmp	w1, w0
	bcs	.L3
	mov	w0, -1
	b	.L4
.L3:
	ldrsw	x0, [sp, 28]
	ldr	x1, [sp, 8]
	add	x0, x1, x0
	ldrb	w1, [x0]
	ldrsw	x0, [sp, 28]
	ldr	x2, [sp]
	add	x0, x2, x0
	ldrb	w0, [x0]
	cmp	w1, w0
	bls	.L5
	mov	w0, 1
	b	.L4
.L5:
	ldr	w0, [sp, 28]
	add	w0, w0, 1
	str	w0, [sp, 28]
.L2:
	ldrsw	x0, [sp, 28]
	ldr	x1, [sp, 8]
	add	x0, x1, x0
	ldrb	w0, [x0]
	cmp	w0, 0
	beq	.L6
	ldrsw	x0, [sp, 28]
	ldr	x1, [sp]
	add	x0, x1, x0
	ldrb	w0, [x0]
	cmp	w0, 0
	bne	.L7
.L6:
	ldrsw	x0, [sp, 28]
	ldr	x1, [sp, 8]
	add	x0, x1, x0
	ldrb	w0, [x0]
	cmp	w0, 0
	beq	.L8
	mov	w0, 1
	b	.L4
.L8:
	ldrsw	x0, [sp, 28]
	ldr	x1, [sp]
	add	x0, x1, x0
	ldrb	w0, [x0]
	cmp	w0, 0
	beq	.L9
	mov	w0, -1
	b	.L4
.L9:
	mov	w0, 0
.L4:
	add	sp, sp, 32
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE6:
	.size	strcmp, .-strcmp
	.align	2
	.global	string_sort
	.type	string_sort, %function
string_sort:
.LFB7:
	.cfi_startproc
	stp	x29, x30, [sp, -64]!
	.cfi_def_cfa_offset 64
	.cfi_offset 29, -64
	.cfi_offset 30, -56
	mov	x29, sp
	str	x0, [sp, 24]
	str	w1, [sp, 20]
	str	wzr, [sp, 60]
	b	.L11
.L15:
	str	wzr, [sp, 56]
	b	.L12
.L14:
	ldrsw	x0, [sp, 56]
	lsl	x0, x0, 3
	ldr	x1, [sp, 24]
	add	x0, x1, x0
	ldr	x2, [x0]
	ldrsw	x0, [sp, 56]
	add	x0, x0, 1
	lsl	x0, x0, 3
	ldr	x1, [sp, 24]
	add	x0, x1, x0
	ldr	x0, [x0]
	mov	x1, x0
	mov	x0, x2
	bl	strcmp
	str	w0, [sp, 52]
	ldr	w0, [sp, 52]
	cmp	w0, 1
	bne	.L13
	ldrsw	x0, [sp, 56]
	lsl	x0, x0, 3
	ldr	x1, [sp, 24]
	add	x0, x1, x0
	ldr	x0, [x0]
	str	x0, [sp, 40]
	ldrsw	x0, [sp, 56]
	add	x0, x0, 1
	lsl	x0, x0, 3
	ldr	x1, [sp, 24]
	add	x1, x1, x0
	ldrsw	x0, [sp, 56]
	lsl	x0, x0, 3
	ldr	x2, [sp, 24]
	add	x0, x2, x0
	ldr	x1, [x1]
	str	x1, [x0]
	ldrsw	x0, [sp, 56]
	add	x0, x0, 1
	lsl	x0, x0, 3
	ldr	x1, [sp, 24]
	add	x0, x1, x0
	ldr	x1, [sp, 40]
	str	x1, [x0]
.L13:
	ldr	w0, [sp, 56]
	add	w0, w0, 1
	str	w0, [sp, 56]
.L12:
	ldr	w1, [sp, 20]
	ldr	w0, [sp, 60]
	sub	w0, w1, w0
	sub	w0, w0, #1
	ldr	w1, [sp, 56]
	cmp	w1, w0
	blt	.L14
	ldr	w0, [sp, 60]
	add	w0, w0, 1
	str	w0, [sp, 60]
.L11:
	ldr	w1, [sp, 60]
	ldr	w0, [sp, 20]
	cmp	w1, w0
	blt	.L15
	nop
	nop
	ldp	x29, x30, [sp], 64
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE7:
	.size	string_sort, .-string_sort
	.section	.rodata
	.align	3
.LC0:
	.string	"%d"
	.align	3
.LC1:
	.string	"%s"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
.LFB8:
	.cfi_startproc
	sub	sp, sp, #832
	.cfi_def_cfa_offset 832
	stp	x29, x30, [sp]
	.cfi_offset 29, -832
	.cfi_offset 30, -824
	mov	x29, sp
	add	x0, sp, 24
	mov	x1, 800
	mov	x2, x1
	mov	w1, 0
	bl	memset
	add	x0, sp, 20
	mov	x1, x0
	adrp	x0, .LC0
	add	x0, x0, :lo12:.LC0
	bl	__isoc99_scanf
	str	wzr, [sp, 828]
	b	.L17
.L18:
	mov	x0, 100
	bl	malloc
	mov	x2, x0
	ldrsw	x0, [sp, 828]
	lsl	x0, x0, 3
	add	x1, sp, 24
	str	x2, [x1, x0]
	ldrsw	x0, [sp, 828]
	lsl	x0, x0, 3
	add	x1, sp, 24
	ldr	x0, [x1, x0]
	mov	x1, x0
	adrp	x0, .LC1
	add	x0, x0, :lo12:.LC1
	bl	__isoc99_scanf
	ldr	w0, [sp, 828]
	add	w0, w0, 1
	str	w0, [sp, 828]
.L17:
	ldr	w0, [sp, 20]
	ldr	w1, [sp, 828]
	cmp	w1, w0
	blt	.L18
	ldr	w1, [sp, 20]
	add	x0, sp, 24
	bl	string_sort
	str	wzr, [sp, 828]
	b	.L19
.L20:
	ldrsw	x0, [sp, 828]
	lsl	x0, x0, 3
	add	x1, sp, 24
	ldr	x0, [x1, x0]
	bl	puts
	ldr	w0, [sp, 828]
	add	w0, w0, 1
	str	w0, [sp, 828]
.L19:
	ldr	w0, [sp, 20]
	ldr	w1, [sp, 828]
	cmp	w1, w0
	blt	.L20
	str	wzr, [sp, 824]
	b	.L21
.L22:
	ldrsw	x0, [sp, 824]
	lsl	x0, x0, 3
	add	x1, sp, 24
	ldr	x0, [x1, x0]
	bl	free
	ldr	w0, [sp, 824]
	add	w0, w0, 1
	str	w0, [sp, 824]
.L21:
	ldr	w0, [sp, 20]
	ldr	w1, [sp, 824]
	cmp	w1, w0
	blt	.L22
	mov	w0, 0
	ldp	x29, x30, [sp]
	add	sp, sp, 832
	.cfi_restore 29
	.cfi_restore 30
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
