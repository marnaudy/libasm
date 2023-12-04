;--------------------------------------------------
; exit(int code)
; Calls exit
exit:
    mov     rdi, rax
    mov     rax, 0x3c
    syscall
    ret

;--------------------------------------------------
; ft_strlen(string str)
; Calculates length of str
ft_strlen:
    push    rbx
    mov     rbx, rax

next_char:
    cmp     byte [rax], 0   ; check if byte at rax is null (end of string)
    jz      finished
    inc     rax
    jmp    next_char

finished:
    sub     rax, rbx        ; calculate length as difference in address of start and null
    pop     rbx
    ret

;--------------------------------------------------
; print(string str)
; Prints str to stdout
print:
    mov     rdi, 1          ; fd 1 is stdout
    mov     rsi, rax        ; str to print
    call    ft_strlen
    mov     rdx, rax
    mov     rax, 0x01       ; write sycall nbr
    syscall
    ret

;--------------------------------------------------
; print_nl(string str)
; Prints str to stdout followed by a newline
print_nl:
    call    print
    mov     rdi, 1          ; fd 1 is stdout
    mov     rax, 0xA        ; push newline to the stack
    push    rax
    mov     rsi, rsp
    mov     rdx, 1          ; write 1 byte
    mov     rax, 0x01       ; write sycall nbr
    syscall
    pop     rax
    ret
