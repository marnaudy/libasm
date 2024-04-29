;--------------------------------------------------
; int ft_list_size(t_list *begin_list)
; Returns the number of elements in the list
; begin_list in rdi
; return size in rax

section     .text
global      ft_list_size

ft_list_size:
    ;Increment rax while iterating over links
    xor     rax, rax
next_elem:
    cmp     rdi, 0
    je      return
    mov     rdi, [rdi]
    inc     rax
    jmp     next_elem
return:
    ret
