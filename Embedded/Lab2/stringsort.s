	.arch armv8-a
	.file	"stringsort.cpp"
	.text
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,8
	.align	2
	.global	_Z6strcmpPcS_
	.type	_Z6strcmpPcS_, %function
_Z6strcmpPcS_:
.LFB1727:
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
.LFE1727:
	.size	_Z6strcmpPcS_, .-_Z6strcmpPcS_
	.align	2
	.global	_Z11string_sortPPci
	.type	_Z11string_sortPPci, %function
_Z11string_sortPPci:
.LFB1728:
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
	bl	_Z6strcmpPcS_
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
.LFE1728:
	.size	_Z11string_sortPPci, .-_Z11string_sortPPci
	.section	.rodata
	.align	3
.LC0:
	.string	"%s"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
.LFB1729:
	.cfi_startproc
	sub	sp, sp, #848
	.cfi_def_cfa_offset 848
	stp	x29, x30, [sp]
	.cfi_offset 29, -848
	.cfi_offset 30, -840
	mov	x29, sp
	add	x0, sp, 32
	mov	x1, 800
	mov	x2, x1
	mov	w1, 0
	bl	memset
	add	x0, sp, 28
	mov	x1, x0
	adrp	x0, _ZSt3cin
	add	x0, x0, :lo12:_ZSt3cin
	bl	_ZNSirsERi
	str	wzr, [sp, 844]
	b	.L17
.L18:
	mov	x0, 100
	bl	malloc
	mov	x2, x0
	ldrsw	x0, [sp, 844]
	lsl	x0, x0, 3
	add	x1, sp, 32
	str	x2, [x1, x0]
	ldrsw	x0, [sp, 844]
	lsl	x0, x0, 3
	add	x1, sp, 32
	ldr	x0, [x1, x0]
	mov	x1, x0
	adrp	x0, .LC0
	add	x0, x0, :lo12:.LC0
	bl	__isoc99_scanf
	ldr	w0, [sp, 844]
	add	w0, w0, 1
	str	w0, [sp, 844]
.L17:
	ldr	w0, [sp, 28]
	ldr	w1, [sp, 844]
	cmp	w1, w0
	blt	.L18
	ldr	w1, [sp, 28]
	add	x0, sp, 32
	bl	_Z11string_sortPPci
	str	wzr, [sp, 840]
	b	.L19
.L20:
	ldrsw	x0, [sp, 840]
	lsl	x0, x0, 3
	add	x1, sp, 32
	ldr	x0, [x1, x0]
	bl	puts
	ldr	w0, [sp, 840]
	add	w0, w0, 1
	str	w0, [sp, 840]
.L19:
	ldr	w0, [sp, 28]
	ldr	w1, [sp, 840]
	cmp	w1, w0
	blt	.L20
	str	wzr, [sp, 836]
	b	.L21
.L22:
	ldrsw	x0, [sp, 836]
	lsl	x0, x0, 3
	add	x1, sp, 32
	ldr	x0, [x1, x0]
	bl	free
	ldr	w0, [sp, 836]
	add	w0, w0, 1
	str	w0, [sp, 836]
.L21:
	ldr	w0, [sp, 28]
	ldr	w1, [sp, 836]
	cmp	w1, w0
	blt	.L22
	mov	w0, 0
	ldp	x29, x30, [sp]
	add	sp, sp, 848
	.cfi_restore 29
	.cfi_restore 30
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1729:
	.size	main, .-main
	.align	2
	.type	_Z41__static_initialization_and_destruction_0ii, %function
_Z41__static_initialization_and_destruction_0ii:
.LFB2224:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	w0, [sp, 28]
	str	w1, [sp, 24]
	ldr	w0, [sp, 28]
	cmp	w0, 1
	bne	.L26
	ldr	w1, [sp, 24]
	mov	w0, 65535
	cmp	w1, w0
	bne	.L26
	adrp	x0, _ZStL8__ioinit
	add	x0, x0, :lo12:_ZStL8__ioinit
	bl	_ZNSt8ios_base4InitC1Ev
	adrp	x0, __dso_handle
	add	x2, x0, :lo12:__dso_handle
	adrp	x0, _ZStL8__ioinit
	add	x1, x0, :lo12:_ZStL8__ioinit
	adrp	x0, _ZNSt8ios_base4InitD1Ev
	add	x0, x0, :lo12:_ZNSt8ios_base4InitD1Ev
	bl	__cxa_atexit
.L26:
	nop
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE2224:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.align	2
	.type	_GLOBAL__sub_I__Z6strcmpPcS_, %function
_GLOBAL__sub_I__Z6strcmpPcS_:
.LFB2225:
	.cfi_startproc
	stp	x29, x30, [sp, -16]!
	.cfi_def_cfa_offset 16
	.cfi_offset 29, -16
	.cfi_offset 30, -8
	mov	x29, sp
	mov	w1, 65535
	mov	w0, 1
	bl	_Z41__static_initialization_and_destruction_0ii
	ldp	x29, x30, [sp], 16
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE2225:
	.size	_GLOBAL__sub_I__Z6strcmpPcS_, .-_GLOBAL__sub_I__Z6strcmpPcS_
	.section	.init_array,"aw",%init_array
	.align	3
	.xword	_GLOBAL__sub_I__Z6strcmpPcS_
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
