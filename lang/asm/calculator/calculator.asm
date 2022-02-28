; usage:    calculator <type> <numA> <numB>
; This program will return the result as it's exit code
%include "f.asm"
%include "math.asm"

global   main
section .text
    main:
        push rbp
        mov rbp, rsp

        mov rsi, 3
        mov rdi, 3
        call _fac

        mov rdi, rax
        call _pnum

        xor rax, rax
        pop rbp
        ret

section .data
fuck: dd 20