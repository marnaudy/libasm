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

ft_list_push_front:
    ret
