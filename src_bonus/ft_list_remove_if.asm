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

ft_list_remove_if:
    ret
