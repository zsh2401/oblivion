extern printf
extern sqrt
section .text

    ;mov rdi, [NUMBER TO PRINT]
    _pnum:
        pop rbp
        mov rbp, rsp
        
        mov rbx, rdi ;Save the argument.
        mov rdi, fmt ; arg 1 format
        mov rsi, rbx ; arg 2 number

        xor rax, rax ;empty the return space

        call printf
        
        xor rax, rax ;RETURN 0

        pop rbp
        ret

    ;mov rdi, [EXIT CODE]
    _exit:
        pop rbp
        mov rbp, rsp
        
        mov rax, 60                 ; system call for exit
        
        syscall
        pop rbp
        ret


section .data
    fmt: db "%d", 0