;--------------------------------------------------
; void ft_list_sort(t_list **begin_list, int (*cmp)())
; Sorts the lists elements by ascending order
; cmp will be used to compare element data as such
; (*cmp)(list_ptr->data, other_list_ptr->data)
; begin_list in rdi
; cmp in rsi
; return nothing

section     .text
global      ft_list_sort

ft_list_sort:
    ;Check arguments
    cmp     rdi, 0
    je      return
    cmp     rsi, 0
    je      return
    ;Return if size 0 or 1
    cmp     qword [rdi], 0
    je      return
    mov     rdx, [rdi]              ;first element
    mov     rdx, [rdx]              ;second element
    cmp     rdx, 0
    je      return
    mov     rax, [rdi]              ;first element
    mov     qword [rax], 0          ;first element -> next
    call    sort
return:
    ret

;--------------------------------------------------
; sort(t_list **sorted, (*cmp), t_list *unsorted)
; Inserts the first element in unsorted in sorted
; No arguments should be null
; begin_list in rdi
; cmp in rsi
; unsorted in rdx
sort:
    ;Create room on the stack
    sub     rsp, 0x30
    mov     [rsp], rdi              ;pointer to first element of sorted
    mov     rax, [rdi]
    mov     [rsp + 0x8], rax        ;first element of sorted
    mov     [rsp + 0x10], rsi       ;cmp
    mov     [rsp + 0x18], rdx       ;element to insert
    mov     rcx, [rdx]
    mov     [rsp + 0x20], rcx       ;rest of unsorted
    mov     [rsp + 0x28], rax       ;iterator over sorted
    ;Compare to first element
    mov     rsi, [rax + 8]
    mov     rdi, [rdx + 8]
    call    [rsp + 0x10]            ;cmp(to_insert->data, first_sorted->data)
    cmp     eax, 0
    jg      find_greater
insert_beginning:
    ;to_insert->next = first element
    mov     rax, [rsp + 0x8]        ;first elem of sorted
    mov     rcx, [rsp + 0x18]       ;to_insert
    mov     [rcx], rax
    ;set pointer to first element to to_insert
    mov     rax, [rsp]              ;address of pointer to first elem
    mov     [rax], rcx              ;*list_begin = to_insert
    jmp     call_sort
find_greater:
    ;Iterate over sorted until next is null or is greater or equal
    mov     rax, [rsp + 0x18]       ;to_insert
    mov     rdi, [rax + 8]          ;to_insert->data
    mov     rax, [rsp + 0x28]       ;iterator over sorted
    mov     rax, [rax]              ;it->next
    cmp     rax, 0
    je      insert
    mov     rsi, [rax + 8]          ;it->next->data
    call    [rsp + 0x10]            ;cmp(to_insert->data, it->next->data)
    cmp     eax, 0
    jle     insert
    ;Increment iterator. it = it->next
    mov     rax, [rsp + 0x28]
    mov     rax, [rax]
    mov     [rsp + 0x28], rax
    jmp     find_greater
insert:
    ;Insert element
    mov     rax, [rsp + 0x28]       ;iterator
    mov     rcx, [rsp + 0x18]       ;to_insert
    mov     rdx, [rax]              ;iterator->next
    mov     [rcx], rdx              ;to_insert->next = it->next
    mov     [rax], rcx              ;it->next = to_insert
call_sort:
    ;Recursive call if unsorted is not empty
    cmp     qword [rsp + 0x20], 0
    je      sort_return
    mov     rdi, [rsp]
    mov     rsi, [rsp + 0x10]
    mov     rdx, [rsp + 0x20]
    ;Release stack
    add     rsp, 0x30
    call    sort
    ret
sort_return:
    add     rsp, 0x30
    ret
