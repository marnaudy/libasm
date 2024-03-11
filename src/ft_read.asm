;--------------------------------------------------
; ssize_t ft_read(int fd, void *buf, size_t count)
; Reads count bytes from file descriptor fd to buf
; Returns number of bytes read or -1 on error
; fd in rdi
; buf in rsi
; count in rdx
; return in rax

section    .text
global     ft_read

ft_read:
    ; Call read syscall 0x00
    mov     rax, 0x00
    syscall
    ret
