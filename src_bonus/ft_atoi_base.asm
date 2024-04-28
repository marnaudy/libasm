;--------------------------------------------------
; int ft_atoi_base(char *str, char *base)
; Returns the conversion as int of the initial portion of str using a custom base
; The string can start with an arbitrary amount of whitespace
; The number can be preceded by an arbitrary amount of '+' and '-'
; An odd number of preceding '-' indicates a negative number
; The number should only contain characters found in base
; The string is read to the end or until an unexpected character is found
; If the number can't be represented as a 32bit int the result is undefined
; Returns 0 on invalid argument :
; - Base is empty or size 1
; - Base contains the same character twice
; - Base contains '+' or '-' or whitespace
; str in rdi
; base in rsi
; return converted int in rax

section     .text
global      ft_atoi_base

ft_atoi_base:
    xor     rax, rax
    ret
