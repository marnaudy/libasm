%include 'utils.asm'

section .data
msg	db      'hello world!!!', 0

section     .text
global      _start

_start:
    mov     rax, msg
    call    print_nl
    mov     rax, 0
    call    exit
