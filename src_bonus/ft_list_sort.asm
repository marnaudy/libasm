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
    ret
