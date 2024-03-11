;--------------------------------------------------
; char *ft_strdup(const char *s);
; Returns pointer to a new string (malloced) which is a duplicate of s
; Returns NULL on malloc error
; s in rdi
; return new string pointer in rax

section     .text
global      ft_strdup
extern      __errno_location
extern      malloc
extern      ft_strlen
extern      ft_strcpy

ft_strdup:
    ; Preserve callee registers
    push    rbx
    ; Copy rdi to rbx (callee preserved register)
    mov     rbx, rdi
    ; Get length of str
    call    ft_strlen
    ; Call malloc with argument strlen + 1
    inc     rax
    mov     rdi, rax
    call    malloc wrt ..plt
    ; Check if malloc returned NULL
    cmp     rax, 0
    jz      malloc_error
    ; Call ft_strcpy to copy data from str in rsi to rdi
    mov     rsi, rbx
    mov     rdi, rax
    call    ft_strcpy
    ; Return new pointer returned by strcpy (already in rax)
    pop     rbx
    ret

malloc_error:
    ; Set errno to ENOMEM (althoug malloc should have done this already)
    ; Return NULL
    mov     rax, 0
    pop     rbx
    ret
