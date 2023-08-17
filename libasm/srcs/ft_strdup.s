global ft_strdup

extern ft_strlen
extern malloc
extern ft_strcpy

section .text

ft_strdup:
	xor rax, rax
	call ft_strlen
	inc rax
	push rdi
	mov rdi, rax
	call malloc
	pop rsi
	mov rdi, rax
	call ft_strcpy
	ret