;--------------------------------------------------
; int ft_strlen(char *str)
; Calculates length of str
; str in rdi
; return in rax

section     .text
global      ft_strlen

ft_strlen:
    ; Move str to rax and rcx
    mov     rcx, rdi
    mov     rax, rdi

next_char:
    ; Check if byte at rax is null (end of string)
    cmp     byte [rax], 0
    ; If null jump to end
    jz      finished
    ; Else go to next character
    inc     rax
    jmp     next_char

finished:
    ; Calculate length as difference in address of start and null
    ; Store in rax for return
    sub     rax, rcx
    ret
