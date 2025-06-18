	.file	"exceptions.cpp"
	.intel_syntax noprefix
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "goodbye cruel world!\0"
	.section	.text.unlikely,"x"
	.globl	_Z15throw_exceptionv
	.def	_Z15throw_exceptionv;	.scl	2;	.type	32;	.endef
_Z15throw_exceptionv:
.LFB1561:
	.cfi_startproc
	.cfi_personality 0x9b,.LDFCM0
	.cfi_lsda 0x1c,.LLSDA1561
	push	rsi
	.cfi_def_cfa_offset 16
	.cfi_offset 4, -16
	mov	ecx, 16
	push	rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	sub	rsp, 40
	.cfi_def_cfa_offset 64
	call	__cxa_allocate_exception
	lea	rdx, .LC0[rip]
	mov	rcx, rax
	mov	rbx, rax
.LEHB0:
	call	_ZNSt13runtime_errorC1EPKc
.LEHE0:
	lea	r8, _ZNSt13runtime_errorD1Ev[rip]
	lea	rdx, _ZTISt13runtime_error[rip]
	mov	rcx, rbx
.LEHB1:
	call	__cxa_throw
.L3:
	mov	rsi, rax
.L2:
	mov	rcx, rbx
	call	__cxa_free_exception
	mov	rcx, rsi
	call	_Unwind_Resume
.LEHE1:
	.cfi_endproc
.LFE1561:
	.section	.gcc_except_table,"w"
.LLSDA1561:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1561-.LLSDACSB1561
.LLSDACSB1561:
	.uleb128 .LEHB0-.LFB1561
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L3-.LFB1561
	.uleb128 0
	.uleb128 .LEHB1-.LFB1561
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE1561:
	.section	.text.unlikely,"x"
	.globl	_Z11with_exceptv
	.def	_Z11with_exceptv;	.scl	2;	.type	32;	.endef
_Z11with_exceptv:
.LFB1562:
	.cfi_startproc
	sub	rsp, 40
	.cfi_def_cfa_offset 48
	call	_Z15throw_exceptionv
	.cfi_endproc
.LFE1562:
	.globl	_Z14with_no_exceptv
	.def	_Z14with_no_exceptv;	.scl	2;	.type	32;	.endef
_Z14with_no_exceptv:
.LFB1563:
	.cfi_startproc
	.cfi_personality 0x9b,.LDFCM0
	.cfi_lsda 0x1c,.LLSDA1563
	sub	rsp, 40
	.cfi_def_cfa_offset 48
	call	_Z15throw_exceptionv
	.cfi_endproc
.LFE1563:
	.section	.gcc_except_table,"w"
.LLSDA1563:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1563-.LLSDACSB1563
.LLSDACSB1563:
.LLSDACSE1563:
	.section	.text.unlikely,"x"
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
main:
.LFB1564:
	.cfi_startproc
	sub	rsp, 40
	.cfi_def_cfa_offset 48
	call	__main
	call	_Z15throw_exceptionv
	.cfi_endproc
.LFE1564:
	.globl	_ZTSSt9exception
	.section	.rdata$_ZTSSt9exception,"dr"
	.linkonce same_size
	.align 8
_ZTSSt9exception:
	.ascii "St9exception\0"
	.globl	_ZTISt9exception
	.section	.rdata$_ZTISt9exception,"dr"
	.linkonce same_size
	.align 8
_ZTISt9exception:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTSSt9exception
	.globl	_ZTSSt13runtime_error
	.section	.rdata$_ZTSSt13runtime_error,"dr"
	.linkonce same_size
	.align 16
_ZTSSt13runtime_error:
	.ascii "St13runtime_error\0"
	.globl	_ZTISt13runtime_error
	.section	.rdata$_ZTISt13runtime_error,"dr"
	.linkonce same_size
	.align 8
_ZTISt13runtime_error:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTSSt13runtime_error
	.quad	_ZTISt9exception
	.data
	.align 8
.LDFCM0:
	.quad	__gxx_personality_v0
	.def	__main;	.scl	2;	.type	32;	.endef
	.def	__gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (MinGW-W64 x86_64-msvcrt-posix-seh, built by Brecht Sanders, r3) 14.2.0"
	.def	__cxa_allocate_exception;	.scl	2;	.type	32;	.endef
	.def	_ZNSt13runtime_errorC1EPKc;	.scl	2;	.type	32;	.endef
	.def	_ZNSt13runtime_errorD1Ev;	.scl	2;	.type	32;	.endef
	.def	__cxa_throw;	.scl	2;	.type	32;	.endef
	.def	__cxa_free_exception;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZNSt13runtime_errorD1Ev, "dr"
	.globl	.refptr._ZNSt13runtime_errorD1Ev
	.linkonce	discard
.refptr._ZNSt13runtime_errorD1Ev:
	.quad	_ZNSt13runtime_errorD1Ev
