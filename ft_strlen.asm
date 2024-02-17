;--------------------------------------------------
; int ft_strlen(char *str)
; Calculates length of str
; str in rdi
; return in rax

section     .text
global      ft_strlen
extern      __errno_location

ft_strlen:
    ; Check if rdi is NULL, if it is return 0
    cmp     rdi, 0
    jz      ret_error
    ; Push rbx on stack
    push    rbx
    ; Move str to rax and rbx
    mov     rbx, rdi
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
    sub     rax, rbx
    ; Restore rbx
    pop     rbx
    ret

ret_error:
    ; Set errno to EFAULT (14)
    call    __errno_location wrt ..plt
    mov     dword [rax], 14
    mov     rax, 0
    ret
