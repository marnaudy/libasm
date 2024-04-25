;--------------------------------------------------
; ssize_t ft_write(int fd, void *buf, size_t count)
; Write count bytes from buf to file descriptor fd
; Returns number of bytes written or -1 on error
; fd in rdi
; buf in rsi
; count in rdx
; return in rax

section     .text
global      ft_write
extern      __errno_location

ft_write:
    ; Call write syscall 0x01
    mov     rax, 0x01
    syscall
    ; Check if return (eax) is strictly negative
    cmp     eax, 0x00
    js      error
    ret
error:
    ; Set errno to 0 - eax
    xor     ecx, ecx
    sub     ecx, eax
    push    rcx
    call    __errno_location wrt ..plt
    pop     rcx
    mov     dword [rax], ecx
    ; Return -1
    mov     eax, 0x-1
    ret 

