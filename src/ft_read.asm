;--------------------------------------------------
; ssize_t ft_read(int fd, void *buf, size_t count)
; Reads count bytes from file descriptor fd to buf
; Returns number of bytes read or -1 on error
; fd in rdi
; buf in rsi
; count in rdx
; return in rax

section     .text
global      ft_read
extern      __errno_location

ft_read:
    ; Call read syscall 0x00
    mov     rax, 0x00
    syscall
    ; Check if return (rax) is strictly negative
    cmp     rax, 0x00
    js      error
    ret
error:
    ; Set errno to 0 - eax
    neg     rax
    push    rax
    call    __errno_location wrt ..plt
    pop     rcx
    mov     dword [rax], ecx
    ; Return -1
    mov     eax, 0x-1
    ret 
