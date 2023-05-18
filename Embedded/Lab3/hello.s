	.cpu arm10tdmi
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 18, 4
	.file	"hello.c"
	.section	.rodata
	.align	2
.LC0:
	.ascii	"hello!\000"
	.text
	.align	2
	.global	_start
	.type	_start, %function
_start:
.LFB2:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	.save {fp, lr}
.LCFI0:
	.setfp fp, sp, #4
	add	fp, sp, #4
.LCFI1:
	ldr	r0, .L3
	bl	puts
	mov	r3, #0
	mov	r0, r3
	ldmfd	sp!, {fp, pc}
.L4:
	.align	2
.L3:
	.word	.LC0
.LFE2:
	.size	_start, .-_start
	.ident	"GCC: (Sourcery G++ Lite 2009q1-203) 4.3.3"
	.section	.note.GNU-stack,"",%progbits
