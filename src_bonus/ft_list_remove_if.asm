;--------------------------------------------------
; void ft_list_remove_if(t_list **begin_list, void *data_ref,
;                           int (*cmp)(), void (*free_fct)(void *))
; Removes elements from the list whose data match data_ref using cmp function
; (*cmp)(list_ptr->data, data_ref)
; Data from removed elements will be freed using free_fct
; (*free_fct)(list_ptr->data)
; begin_list in rdi
; data_ref in rsi
; cmp in rdx
; free_fct in rcx
; return nothing

section     .text
global      ft_list_remove_if
extern      free

ft_list_remove_if:
    ;Create room on the stack to store arguments
    sub     rsp, 0x30
    mov     [rsp], rdi              ;address of pointer to first element
    mov     [rsp + 0x8], rsi        ;data_ref
    mov     [rsp + 0x10], rdx       ;cmp
    mov     [rsp + 0x18], rcx       ;free_fct
    ;Return if arguments are null (except data_ref)
    cmp     rdi, 0
    je      return
    cmp     rdx, 0
    je      return
    cmp     rcx, 0
    je      return
    ;Return if list is empty
    cmp     qword [rdi], 0
    je      return
    ;Store address of first element
    mov     rax, [rdi]
    mov     [rsp + 0x20], rax       ;address of first element
    ;Check if first element matches
    mov     rdi, [rax + 8]          ;data of first element
    call    rdx
    cmp     rax, 0
    jne     call_no_match
    ;Store next element address on the stack
    mov     rax, [rsp + 0x20]
    mov     rax, [rax]
    mov     [rsp + 0x28], rax       ;address of second element
    ;Remove first element
    ;Free data
    mov     rdi, [rsp + 0x20]       ;address of first elem
    mov     rdi, [rdi + 8]          ;data of first elem
    call    [rsp + 0x18]
    ;Free the link
    mov     rdi, [rsp + 0x20]
    call    free wrt ..plt
    ;Set pointer to first element to address of second elem
    mov     rax, [rsp + 0x28]
    mov     rcx, [rsp]
    mov     [rcx], rax
    ;Set rdi to pointer to first element
    mov     rdi, [rsp]
    jmp     recursive_call
call_no_match:
    ;Set rdi to address of first elements next pointer
    mov     rdi, [rsp + 0x20]
recursive_call:
    ;Recursive call on next element
    mov     rsi, [rsp + 0x8]
    mov     rdx, [rsp + 0x10]
    mov     rcx, [rsp + 0x18]
    call    ft_list_remove_if
return:
    ;Release stack
    add     rsp, 0x30
    ret
