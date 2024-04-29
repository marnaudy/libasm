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
    ; Calculate base size and store in r8
    call    base_len
    ; Set res (rax) and sign (r9b) to 0
    xor     rax, rax
    xor     r9b, r9b
    ; Return if base is not valid
    call    check_base
    cmp     rdx, 0
    je      end
    mov     rcx, rdi
    dec     rcx
next_char_whitespace:
    ; Skip any whitespace characters
    inc     rcx
    call    is_whitespace
    cmp     rdx, 0
    jne     next_char_whitespace
    ; Switch sign if '-' and skip if '+'
    ; R9b stores if number is negative
next_char_sign:
    call    is_sign
    cmp     rdx, 0
    je      read_nb
    ; If character is '-' (45) toggle sign (r9b)
    ; r9b = (char == 45) xor r9b
    cmp     byte [rcx], 45
    sete    dl
    cmp     dl, r9b
    setne   r9b
    inc     rcx
    jmp     next_char_sign
read_nb:
    ; Check position of character in base
    ; Current character pointer is in rdi, it must be updated to rcx
    ; Load current character in r10b
    ; Base pointer in rcx for position_in_base
    mov     rdi, rcx
    mov     rcx, rsi
read_nb_next_char:
    mov     r10b, byte [rdi]
    call    position_in_base
    ; If it isn't return
    cmp     r11, 0
    js      end
    ; Multiply res by base size (r8) and add position in base (r11)
    mul     r8
    add     rax, r11
    inc     rdi
    jmp     read_nb_next_char
end:
    ; If sign (r9b) is set, negate rax
    cmp     r9b, 0
    jne     end_negative
    ret
end_negative
    neg     rax
    ret

is_whitespace:
    ; Checks if byte pointed to by rcx is whitespace (9<= c < 14 and = 32)
    ; Returns in rdx
    cmp     byte [rcx], 9
    jl      is_whitespace_false
    cmp     byte [rcx], 14
    jl      is_whitespace_true
    cmp     byte [rcx], 32
    sete    dl
    ret
is_whitespace_true:
    mov     rdx, 1
    ret
is_whitespace_false:
    xor     rdx, rdx
    ret

is_sign:
    ; Checks if byte pointed to by rcx is a sign '+'=43 or '-'=45
    ; Returns in rdx
    cmp     byte [rcx], 43
    je      is_sign_true
    cmp     byte [rcx], 45
    sete    dl
    ret
is_sign_true:
    mov     rdx, 1
    ret

base_len:
    ; Calculates length of base (rsi)
    ; Returns in r8
    mov     r8, rsi
base_len_next_char:
    cmp     byte [r8], 0
    je      base_len_end
    inc     r8
    jmp     base_len_next_char
base_len_end:
    sub     r8, rsi
    ret

check_base:
    ; Checks if base is valid
    ; len >= 2; no whitespace; no signs and no repeats
    ; Check length (r8)
    cmp     r8, 1
    jle     check_base_false
    ; Check each character
    mov     rcx, rsi
check_base_next_char:
    cmp     byte [rcx], 0
    je      check_base_true
    call    is_whitespace
    cmp     rdx, 0
    jne     check_base_false
    call    is_sign
    cmp     rdx, 0
    jne     check_base_false
    ; Check if character is in the base (only check from current position)
    mov     r10b, byte [rcx]
    inc     rcx
    call    position_in_base
    cmp     r11, 0
    jns     check_base_false
    jmp     check_base_next_char
check_base_false:
    xor     rdx, rdx
    ret
check_base_true:
    mov     rdx, 1
    ret

position_in_base:
    ; Returns position of char in r10b in base pointed to by rcx
    ; Returns in r11
    ; Returns -1 if not found
    mov     r11, rcx
position_in_base_next_char:
    cmp     byte [r11], 0
    je      position_in_base_not_found
    cmp     r10b, byte [r11]
    je      position_in_base_found
    inc     r11
    jmp     position_in_base_next_char
position_in_base_found:
    sub     r11, rcx
    ret
position_in_base_not_found:
    mov     r11, -1;
    ret

