	.arch armv8-a
	.file	"stringsort.cpp"
	.text
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,8
	.align	2
	.global	_Z11string_sortPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi
	.type	_Z11string_sortPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi, %function
_Z11string_sortPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi:
.LFB1727:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	str	x0, [sp, 24]
	str	w1, [sp, 20]
	str	wzr, [sp, 44]
	b	.L2
.L6:
	str	wzr, [sp, 40]
	b	.L3
.L5:
	ldrsw	x0, [sp, 40]
	lsl	x0, x0, 5
	ldr	x1, [sp, 24]
	add	x2, x1, x0
	ldrsw	x0, [sp, 40]
	add	x0, x0, 1
	lsl	x0, x0, 5
	ldr	x1, [sp, 24]
	add	x0, x1, x0
	mov	x1, x0
	mov	x0, x2
	bl	_ZStgtIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EESA_
	and	w0, w0, 255
	cmp	w0, 0
	beq	.L4
	ldrsw	x0, [sp, 40]
	lsl	x0, x0, 5
	ldr	x1, [sp, 24]
	add	x2, x1, x0
	ldrsw	x0, [sp, 40]
	add	x0, x0, 1
	lsl	x0, x0, 5
	ldr	x1, [sp, 24]
	add	x0, x1, x0
	mov	x1, x0
	mov	x0, x2
	bl	_ZSt4swapIcSt11char_traitsIcESaIcEEvRNSt7__cxx1112basic_stringIT_T0_T1_EES9_
.L4:
	ldr	w0, [sp, 40]
	add	w0, w0, 1
	str	w0, [sp, 40]
.L3:
	ldr	w1, [sp, 20]
	ldr	w0, [sp, 44]
	sub	w0, w1, w0
	sub	w0, w0, #1
	ldr	w1, [sp, 40]
	cmp	w1, w0
	blt	.L5
	ldr	w0, [sp, 44]
	add	w0, w0, 1
	str	w0, [sp, 44]
.L2:
	ldr	w1, [sp, 44]
	ldr	w0, [sp, 20]
	cmp	w1, w0
	blt	.L6
	nop
	nop
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1727:
	.size	_Z11string_sortPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi, .-_Z11string_sortPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi
	.align	2
	.global	main
	.type	main, %function
main:
.LFB1732:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1732
	sub	sp, sp, #3248
	.cfi_def_cfa_offset 3248
	stp	x29, x30, [sp]
	.cfi_offset 29, -3248
	.cfi_offset 30, -3240
	mov	x29, sp
	stp	x19, x20, [sp, 16]
	.cfi_offset 19, -3232
	.cfi_offset 20, -3224
	add	x0, sp, 40
	mov	x19, 99
	mov	x20, x0
	b	.L8
.L9:
	mov	x0, x20
	bl	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
	add	x20, x20, 32
	sub	x19, x19, #1
.L8:
	cmp	x19, 0
	bge	.L9
	add	x0, sp, 36
	mov	x1, x0
	adrp	x0, _ZSt3cin
	add	x0, x0, :lo12:_ZSt3cin
.LEHB0:
	bl	_ZNSirsERi
	str	wzr, [sp, 3244]
	b	.L10
.L11:
	add	x1, sp, 40
	ldrsw	x0, [sp, 3244]
	lsl	x0, x0, 5
	add	x0, x1, x0
	mov	x1, x0
	adrp	x0, _ZSt3cin
	add	x0, x0, :lo12:_ZSt3cin
	bl	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
	ldr	w0, [sp, 3244]
	add	w0, w0, 1
	str	w0, [sp, 3244]
.L10:
	ldr	w0, [sp, 36]
	ldr	w1, [sp, 3244]
	cmp	w1, w0
	blt	.L11
	ldr	w1, [sp, 36]
	add	x0, sp, 40
	bl	_Z11string_sortPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi
	str	wzr, [sp, 3240]
	b	.L12
.L13:
	add	x1, sp, 40
	ldrsw	x0, [sp, 3240]
	lsl	x0, x0, 5
	add	x0, x1, x0
	mov	x1, x0
	adrp	x0, _ZSt4cout
	add	x0, x0, :lo12:_ZSt4cout
	bl	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE
	mov	x2, x0
	adrp	x0, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	add	x1, x0, :lo12:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	x0, x2
	bl	_ZNSolsEPFRSoS_E
.LEHE0:
	ldr	w0, [sp, 3240]
	add	w0, w0, 1
	str	w0, [sp, 3240]
.L12:
	ldr	w0, [sp, 36]
	ldr	w1, [sp, 3240]
	cmp	w1, w0
	blt	.L13
	mov	w20, 0
	add	x19, sp, 40
	add	x19, x19, 3200
.L15:
	add	x0, sp, 40
	cmp	x19, x0
	beq	.L22
	sub	x19, x19, #32
	mov	x0, x19
	bl	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	b	.L15
.L22:
	nop
	mov	w0, w20
	b	.L21
.L20:
	mov	x20, x0
	add	x19, sp, 40
	add	x19, x19, 3200
.L19:
	add	x0, sp, 40
	cmp	x19, x0
	beq	.L23
	sub	x19, x19, #32
	mov	x0, x19
	bl	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	b	.L19
.L23:
	nop
	mov	x0, x20
.LEHB1:
	bl	_Unwind_Resume
.LEHE1:
.L21:
	ldp	x19, x20, [sp, 16]
	ldp	x29, x30, [sp]
	add	sp, sp, 3248
	.cfi_restore 29
	.cfi_restore 30
	.cfi_restore 19
	.cfi_restore 20
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1732:
	.global	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA1732:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1732-.LLSDACSB1732
.LLSDACSB1732:
	.uleb128 .LEHB0-.LFB1732
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L20-.LFB1732
	.uleb128 0
	.uleb128 .LEHB1-.LFB1732
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE1732:
	.text
	.size	main, .-main
	.section	.text._ZStgtIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EESA_,"axG",@progbits,_ZStgtIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EESA_,comdat
	.align	2
	.weak	_ZStgtIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EESA_
	.type	_ZStgtIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EESA_, %function
_ZStgtIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EESA_:
.LFB1994:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1994
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	x0, [sp, 24]
	str	x1, [sp, 16]
	ldr	x1, [sp, 16]
	ldr	x0, [sp, 24]
	bl	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7compareERKS4_
	cmp	w0, 0
	cset	w0, gt
	and	w0, w0, 255
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1994:
	.section	.gcc_except_table
.LLSDA1994:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1994-.LLSDACSB1994
.LLSDACSB1994:
.LLSDACSE1994:
	.section	.text._ZStgtIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EESA_,"axG",@progbits,_ZStgtIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EESA_,comdat
	.size	_ZStgtIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EESA_, .-_ZStgtIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EESA_
	.section	.text._ZSt4swapIcSt11char_traitsIcESaIcEEvRNSt7__cxx1112basic_stringIT_T0_T1_EES9_,"axG",@progbits,_ZSt4swapIcSt11char_traitsIcESaIcEEvRNSt7__cxx1112basic_stringIT_T0_T1_EES9_,comdat
	.align	2
	.weak	_ZSt4swapIcSt11char_traitsIcESaIcEEvRNSt7__cxx1112basic_stringIT_T0_T1_EES9_
	.type	_ZSt4swapIcSt11char_traitsIcESaIcEEvRNSt7__cxx1112basic_stringIT_T0_T1_EES9_, %function
_ZSt4swapIcSt11char_traitsIcESaIcEEvRNSt7__cxx1112basic_stringIT_T0_T1_EES9_:
.LFB1995:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	x0, [sp, 24]
	str	x1, [sp, 16]
	ldr	x1, [sp, 16]
	ldr	x0, [sp, 24]
	bl	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4swapERS4_
	nop
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1995:
	.size	_ZSt4swapIcSt11char_traitsIcESaIcEEvRNSt7__cxx1112basic_stringIT_T0_T1_EES9_, .-_ZSt4swapIcSt11char_traitsIcESaIcEEvRNSt7__cxx1112basic_stringIT_T0_T1_EES9_
	.text
	.align	2
	.type	_Z41__static_initialization_and_destruction_0ii, %function
_Z41__static_initialization_and_destruction_0ii:
.LFB2242:
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
	bne	.L29
	ldr	w1, [sp, 24]
	mov	w0, 65535
	cmp	w1, w0
	bne	.L29
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
.L29:
	nop
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE2242:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.align	2
	.type	_GLOBAL__sub_I__Z11string_sortPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi, %function
_GLOBAL__sub_I__Z11string_sortPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi:
.LFB2243:
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
.LFE2243:
	.size	_GLOBAL__sub_I__Z11string_sortPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi, .-_GLOBAL__sub_I__Z11string_sortPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi
	.section	.init_array,"aw",%init_array
	.align	3
	.xword	_GLOBAL__sub_I__Z11string_sortPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEi
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align	3
	.type	DW.ref.__gxx_personality_v0, %object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.xword	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
