	.arch armv5te
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"stringsort_io.c"
	.section	.rodata
	.align	2
.LC0:
	.ascii	"%d\000"
	.align	2
.LC1:
	.ascii	"%s\000"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	.fnstart
	@ args = 0, pretend = 0, frame = 408
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	.save {fp, lr}
	.setfp fp, sp, #4
	add	fp, sp, #4
	.pad #408
	sub	sp, sp, #408
	sub	r2, fp, #408
	mov	r3, #400
	mov	r0, r2
	mov	r1, #0
	mov	r2, r3
	bl	memset
	sub	r3, fp, #412
	ldr	r0, .L9
	mov	r1, r3
	bl	__isoc99_scanf
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L2
.L3:
	mov	r0, #100
	bl	malloc
	mov	r3, r0
	mov	r2, r3
	ldr	r1, [fp, #-8]
	ldr	r3, .L9+4
	mov	r1, r1, asl #2
	sub	r0, fp, #4
	add	r1, r0, r1
	add	r3, r1, r3
	str	r2, [r3]
	ldr	r2, [fp, #-8]
	ldr	r3, .L9+4
	mov	r2, r2, asl #2
	sub	r1, fp, #4
	add	r2, r1, r2
	add	r3, r2, r3
	ldr	r3, [r3]
	ldr	r0, .L9+8
	mov	r1, r3
	bl	__isoc99_scanf
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L2:
	ldr	r3, [fp, #-412]
	ldr	r2, [fp, #-8]
	cmp	r2, r3
	blt	.L3
	ldr	r3, [fp, #-412]
	sub	r2, fp, #408
	mov	r0, r2
	mov	r1, r3
	bl	string_sort
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L4
.L5:
	ldr	r2, [fp, #-8]
	ldr	r3, .L9+4
	mov	r2, r2, asl #2
	sub	r0, fp, #4
	add	r2, r0, r2
	add	r3, r2, r3
	ldr	r3, [r3]
	mov	r0, r3
	bl	puts
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L4:
	ldr	r3, [fp, #-412]
	ldr	r2, [fp, #-8]
	cmp	r2, r3
	blt	.L5
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L6
.L7:
	ldr	r2, [fp, #-8]
	ldr	r3, .L9+4
	mov	r2, r2, asl #2
	sub	r1, fp, #4
	add	r2, r1, r2
	add	r3, r2, r3
	ldr	r3, [r3]
	mov	r0, r3
	bl	free
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L6:
	ldr	r3, [fp, #-412]
	ldr	r2, [fp, #-8]
	cmp	r2, r3
	blt	.L7
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	ldmfd	sp!, {fp, pc}
.L10:
	.align	2
.L9:
	.word	.LC0
	.word	-404
	.word	.LC1
	.fnend
	.size	main, .-main
	.ident	"GCC: (Sourcery CodeBench Lite 2014.05-29) 4.8.3 20140320 (prerelease)"
	.section	.note.GNU-stack,"",%progbits
