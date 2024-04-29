;--------------------------------------------------
; t_list *ft_create_elem(void *data)
; Creates (malloc) a new t_list element, stores data and returns its address
; data in rdi
; return pointer to new element in rax

section     .text
global      ft_create_elem
extern      malloc

ft_create_elem:
    ;Store data in rbx
    push    rbx
    mov     rbx, rdi
    ;Call malloc with sizeof t_list
    mov     rdi, 0x10
    call    malloc wrt ..plt
    cmp     rax, 0
    je      return
    ; Set next to null
    mov     qword [rax], 0
    mov     [rax + 8], rbx
return:
    pop     rbx
    ret
