;--------------------------------------------------
; int ft_strcmp(const char *s1, const char *s2)
; Returns the difference of the first differing byte in s1 and s2 or 0 if equal
; s1 in rdi
; s2 in rsi
; return difference in rax

section     .text
global      ft_strcmp

ft_strcmp:
    ; Check if byte at rdi (s1) is null (end of string)
    cmp     byte [rdi], 0
    ; If null jump to end
    jz      finished
    ; Move bytes at rdi and rsi to al and cl then compare them
    mov     al, byte [rdi]
    mov     cl, byte [rsi]
    cmp     al, cl
    ; If different jump to end
    jnz     finished
    ; Else increment rdi and rsi (s1 and s2) and go to next character
    inc     rdi
    inc     rsi
    jmp     ft_strcmp

finished:
    ; Return in rax difference between byte at rdi and rsi
    movzx   rax, byte [rdi]
    movzx   rcx, byte [rsi]
    sub     eax, ecx
    ret
