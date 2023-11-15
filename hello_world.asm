section .data
msg	db 'hello world', 0xA

section	.text
global	_start

_start:
	mov eax, 1
	mov rdi, 1
	mov rsi, msg
	mov rdx, 12
	syscall
	mov eax, 0x3c
	mov rdi, 0
	syscall
