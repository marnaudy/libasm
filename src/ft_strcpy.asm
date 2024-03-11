;--------------------------------------------------
; char *ft_strcpy(char *dest, const char *src)
; Copies string in src incuding terminating byte to dest
; dest and src must not overlap
; dest in rdi
; src in rsi
; return dest in rax

section     .text
global      ft_strcpy

ft_strcpy:
    ; Move dest to rax
    mov     rax, rdi

next_char:
    ; Check if byte at rsi (src) is null (end of string)
    cmp     byte [rsi], 0
    ; Copies one byte from rsi to rdi and increments both (df flag is cleared according to C ABI)
    movsb
    ; If null jump to end
    jz      finished
    ; Else go to next character
    jmp     next_char

finished:
    ; Return dest which was copied to rax at start of function
    ret
