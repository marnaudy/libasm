section .data
msg	db 'hello world!!!', 0xA, 0

section	.text
global	_start

_start:
	mov		rax, msg
	call	strlen
	mov		rdx, rax; len 
	mov		rax, 1; write
	mov		rdi, 1; fd
	mov		rsi, msg; str pointer
	syscall
	mov		rax, 0x3c; exit
	mov		rdi, 0; return
	syscall

strlen:
	push	rbx
	mov		rbx, rax

loop:
	cmp		byte [rax], 0
	jz		loop_end
	inc		rax
	jmp		loop

loop_end:
	sub		rax, rbx; rax now contains length of message
	pop		rbx
	ret
