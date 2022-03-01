    section .data
TEST_DATA: real10 100.5
    section .text

; xmm1(double) ^ rsi (rsi ∈ Z+)
; result is in xmm0
_fexp:
    push rbp,
    push rbp, rsp

    cmp rsi, 0
    jne __fexp_init
    movdqa xmm1, dt 1.0
    mulsd xmm1, dt 2.0
    
    xor xmm0, xmm0
    movdqa xmm0, xmm1

    leave
    ret

    __fexp_init:
    xor r8, r8

    leave
    ret

; sin
_sin:
    push rbp
    push rbp, rsp



    leave
    ret