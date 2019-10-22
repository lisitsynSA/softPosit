; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc -verify-machineinstrs -fixup-byte-word-insts=1 -mtriple=x86_64-- < %s | FileCheck --check-prefix=X64 --check-prefix=BWON64 %s
; RUN: llc -verify-machineinstrs -fixup-byte-word-insts=0 -mtriple=x86_64-- < %s | FileCheck --check-prefix=X64 --check-prefix=BWOFF64 %s
; RUN: llc -verify-machineinstrs -fixup-byte-word-insts=1 -mtriple=i386-- < %s | FileCheck --check-prefix=X32 --check-prefix=BWON32 %s
; RUN: llc -verify-machineinstrs -fixup-byte-word-insts=0 -mtriple=i386-- < %s | FileCheck --check-prefix=X32 --check-prefix=BWOFF32 %s

target datalayout = "e-m:o-p:32:32-f64:32:64-f80:128-n8:16:32-S128"

define i8 @test_movb(i8 %a0) {
; X64-LABEL: test_movb:
; X64:       # %bb.0:
; X64-NEXT:    movl %edi, %eax
; X64-NEXT:    # kill: def $al killed $al killed $eax
; X64-NEXT:    retq
;
; X32-LABEL: test_movb:
; X32:       # %bb.0:
; X32-NEXT:    movb {{[0-9]+}}(%esp), %al
; X32-NEXT:    retl
  ret i8 %a0
}

define i16 @test_movw(i16 %a0) {
; X64-LABEL: test_movw:
; X64:       # %bb.0:
; X64-NEXT:    movl %edi, %eax
; X64-NEXT:    # kill: def $ax killed $ax killed $eax
; X64-NEXT:    retq
;
; BWON32-LABEL: test_movw:
; BWON32:       # %bb.0:
; BWON32-NEXT:    movzwl {{[0-9]+}}(%esp), %eax
; BWON32-NEXT:    retl
;
; BWOFF32-LABEL: test_movw:
; BWOFF32:       # %bb.0:
; BWOFF32-NEXT:    movw {{[0-9]+}}(%esp), %ax
; BWOFF32-NEXT:    retl
  ret i16 %a0
}

; Verify we don't mess with H-reg copies (only generated in 32-bit mode).
define i8 @test_movb_hreg(i16 %a0) {
; X64-LABEL: test_movb_hreg:
; X64:       # %bb.0:
; X64-NEXT:    # kill: def $edi killed $edi def $rdi
; X64-NEXT:    movl %edi, %eax
; X64-NEXT:    shrl $8, %eax
; X64-NEXT:    addl %edi, %eax
; X64-NEXT:    # kill: def $al killed $al killed $eax
; X64-NEXT:    retq
;
; X32-LABEL: test_movb_hreg:
; X32:       # %bb.0:
; X32-NEXT:    movl {{[0-9]+}}(%esp), %eax
; X32-NEXT:    addb %al, %ah
; X32-NEXT:    movb %ah, %al
; X32-NEXT:    retl
  %tmp0 = trunc i16 %a0 to i8
  %tmp1 = lshr i16 %a0, 8
  %tmp2 = trunc i16 %tmp1 to i8
  %tmp3 = add i8 %tmp0, %tmp2
  ret i8 %tmp3
}
