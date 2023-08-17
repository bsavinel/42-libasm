global ft_strcpy

section .text

ft_strcpy:
	mov rax, rdi
	cmp byte [rsi], 0
	jne loop
	ret

loop:
	mov r10b, byte [rsi]
	mov byte [rdi], r10b
	inc rsi
	inc rdi
	cmp byte [rsi], 0 
	jne loop
	ret
