;--------------------------------------------------
; ft_strlen(string str)
; Calculates length of str
section    .text
global     ft_strlen

ft_strlen:
    push    rbx
    mov     rbx, rdi
    mov     rax, rdi

next_char:
    cmp     byte [rax], 0   ; check if byte at rax is null (end of string)
    jz      finished
    inc     rax
    jmp     next_char

finished:
    sub     rax, rbx        ; calculate length as difference in address of start and null
    pop     rbx
    ret
