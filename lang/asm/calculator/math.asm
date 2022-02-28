section .text
    ;rsi + rdi
    _add:
        push rbp
        mov rbp, rsp

        mov rax, rsi
        add rax, rdi

        leave
        ret

    ;rsi - rdi
    _sub:
        push rbp
        mov rbp, rsp

        mov rax, rsi
        sub rax, rdi

        leave
        ret

    ;rsi * rdi 
    _mul:
        push rbp
        mov rbp, rsp

        mov rax, rsi
        imul rax, rdi ; signed multiply
        ; mul rax, rdi  ; unsigned multiply

        leave
        ret
    
    ;rsi / rdi
    _div:
        push rbp
        mov rbp, rsp

        xor rdx, rdx

        mov rax, rsi    ; copy dividend argument into rax
        mov r8, rdi     ; copy divisor to scratch register

        idiv r8         ;quotient is in rax and remainder is in rdx

        leave
        ret

    ; rsi % rdi   
    _mod:
        push rbp
        mov rbp, rsp

        xor rdx, rdx

        mov rax, rsi    ; copy dividend argument into rax
        mov r8, rdi     ; copy divisor to scratch register

        idiv r8         ;quotient is in rax and remainder is in rdx

        pop rbp
        ret

    ; factorial:  rsi!
    ; x * _fac(x - 1)
    _fac:
        push rbp
        mov rbp, rsp

        sub rsp, 16
        mov qword [rbp - 8H], rsi

        cmp qword [rbp - 8H], 1
        jne _fac_not_zero

        mov rax, 1
        leave
        ret

        _fac_not_zero:
        sub rsi, 1
        call _fac
        imul rax, qword [rbp - 8H]

        leave
        ret

    ; rsi ^ rdi (All integer)
    _exp:
        push rbp
        mov rbp, rsp

        cmp rdi, 0      
        jg __for__init ; begin the loop if rdi greater than zero

        mov rax, 1

        leave
        ret

        __for__init:

        mov r8, rsi     ;r8 = x
        mov r9, rdi     ;r9 = y
        mov r10, 1      ;r10 = 1

        __for__head:

        cmp r10, r9          ; compare r8 and rsi
        jge __after_for     ; if r8 >= rsi, then jump to after_for

        __for__body:
        
        imul r8, rsi       ; no jump and calculate its result

        inc r10
        jmp __for__head

        __after_for:
        mov rax, r8

        leave
        ret

    ;sin(rsi)
    _sin:
        push rbp
        mov rbp, rsp

        xor rax, rax

        _sin_for_init:
        xor r8, r8
     
        _sin_for_cmp:

        add rax, rbx
        _sin_for_end:
        ; result is already in rax
        leave
        ret

section .data
    TERMS: db 12