section .data
msg	db 'hello world!!!', 0xA, 0

section	.text
global	_start

_start:
	mov rax, msg
	mov rbx, msg
loop:
	cmp byte [rbx], 0
	jz loop_end
	inc rbx
	jmp loop
loop_end:
	sub rbx, rax; ebx now contains length of message

	mov rax, 1
	mov rdi, 1
	mov rsi, msg
	mov rdx, rbx
	syscall
	mov rax, 0x3c
	mov rdi, 0
	syscall
