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

ft_write:
    ; Call write syscall 0x01
    mov     rax, 0x01
    syscall
    ret
