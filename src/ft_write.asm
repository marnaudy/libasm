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
    ; Check if return (rax) indicates an error (between -4095 and -1)
    cmp     rax, -0xFFF
    ; Jump above or equal -4095
    jae     error
    ret
error:
    ; Set errno to 0 - rax
    neg     rax
    push    rax
    call    __errno_location wrt ..plt
    pop     rcx
    mov     dword [rax], ecx
    ; Return -1
    mov     eax, 0x-1
    ret 

