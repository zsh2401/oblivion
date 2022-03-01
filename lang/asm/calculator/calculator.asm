; usage:    calculator <type> <numA> <numB>
; This program will return the result as it's exit code
%include "f.asm"
%include "math.asm"
section .data
xyz:    dq 2.5e3
global   main
section .text
    main:
        push rbp
        mov rbp, rsp

        ; sub rsp, 16
        ; movdqa dt [rsp + 8], dt 1.5

        mov rsi, [xyz]
        ; mov rdi, 2
        call _pdouble

        mov rdi, rax
        call _pnum

        xor rax, rax
        pop rbp
        ret

section .data
fuck:   dd 20
pi:     dt  3.141