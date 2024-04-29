;--------------------------------------------------
; void ft_list_push_front(t_list **begin_list, void *data)
; Creates (malloc) a new t_list element containing data
; and pushes it to the front of the list pointed at begin_list
; begin_list in rdi
; data in rsi
; return nothing
; Could be improved by returning an int to indicate a malloc error

section     .text
global      ft_list_push_front
extern      ft_create_elem

ft_list_push_front:
    ;Store begin_list in rbx
    push    rbx
    mov     rbx, rdi
    ;Return if begin_list is NULL
    cmp     rbx, 0
    je      end
    ;Call ft_create_elem
    mov     rdi, rsi
    call    ft_create_elem
    cmp     rax, 0
    je      end
    ;Set new elem next to *begin_list
    mov     rcx, [rbx]
    mov     [rax], rcx
    ;Set *begin list to new elem
    mov     [rbx], rax
end:
    pop     rbx
    ret
