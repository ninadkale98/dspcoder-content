	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 2
	.globl	_routine                        ; -- Begin function routine
	.p2align	2
_routine:                               ; @routine
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	ldur	x8, [x29, #-8]
	ldr	w8, [x8]
	stur	w8, [x29, #-12]
	b	LBB0_1
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w9, [x29, #-12]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	ldur	w0, [x29, #-12]
	bl	_sleep
	b	LBB0_1
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #304
	.cfi_def_cfa_offset 304
	stp	x28, x27, [sp, #272]            ; 16-byte Folded Spill
	stp	x29, x30, [sp, #288]            ; 16-byte Folded Spill
	add	x29, sp, #288
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w27, -24
	.cfi_offset w28, -32
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-24]
	str	wzr, [sp, #132]
	str	w0, [sp, #128]
	str	x1, [sp, #120]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	ldr	w9, [sp, #128]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	add	x8, sp, #100
	str	x8, [sp, #40]                   ; 8-byte Folded Spill
	mov	w8, #1
	str	w8, [sp, #20]                   ; 4-byte Folded Spill
	str	w8, [sp, #100]
	add	x8, sp, #96
	str	x8, [sp, #64]                   ; 8-byte Folded Spill
	mov	w8, #2
	str	w8, [sp, #96]
	sub	x0, x29, #88
	str	x0, [sp, #32]                   ; 8-byte Folded Spill
	bl	_pthread_attr_init
	add	x0, sp, #136
	str	x0, [sp, #48]                   ; 8-byte Folded Spill
	bl	_pthread_attr_init
	ldr	w8, [sp, #20]                   ; 4-byte Folded Reload
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	add	x1, sp, #88
	str	w8, [sp, #88]
	add	x8, sp, #80
	str	x8, [sp, #24]                   ; 8-byte Folded Spill
	mov	w8, #99
	str	w8, [sp, #80]
	bl	_pthread_attr_setschedparam
	ldr	x1, [sp, #24]                   ; 8-byte Folded Reload
	ldr	x0, [sp, #48]                   ; 8-byte Folded Reload
	bl	_pthread_attr_setschedparam
	ldr	x1, [sp, #32]                   ; 8-byte Folded Reload
	ldr	x3, [sp, #40]                   ; 8-byte Folded Reload
	add	x0, sp, #112
	adrp	x2, _routine@PAGE
	add	x2, x2, _routine@PAGEOFF
	str	x2, [sp, #56]                   ; 8-byte Folded Spill
	bl	_pthread_create
	ldr	x1, [sp, #48]                   ; 8-byte Folded Reload
	ldr	x2, [sp, #56]                   ; 8-byte Folded Reload
	ldr	x3, [sp, #64]                   ; 8-byte Folded Reload
	add	x0, sp, #104
	bl	_pthread_create
	ldr	x0, [sp, #112]
	mov	x1, #0
	str	x1, [sp, #72]                   ; 8-byte Folded Spill
	bl	_pthread_join
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	ldr	x1, [sp, #72]                   ; 8-byte Folded Reload
	ldr	x0, [sp, #112]
	bl	_pthread_join
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	ldur	x9, [x29, #-24]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	cset	w8, eq
	tbnz	w8, #0, LBB1_2
	b	LBB1_1
LBB1_1:
	bl	___stack_chk_fail
LBB1_2:
	mov	w0, #0
	ldp	x29, x30, [sp, #288]            ; 16-byte Folded Reload
	ldp	x28, x27, [sp, #272]            ; 16-byte Folded Reload
	add	sp, sp, #304
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"Routine function from thread %d\n"

l_.str.1:                               ; @.str.1
	.asciz	"hello world\n"

l_.str.2:                               ; @.str.2
	.asciz	"Total argument passed : %d\n"

l_.str.3:                               ; @.str.3
	.asciz	"tp1"

l_.str.4:                               ; @.str.4
	.asciz	"tp2"

.subsections_via_symbols
