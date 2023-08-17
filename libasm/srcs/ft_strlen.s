global ft_strlen

section .text

ft_strlen:
	xor rax, rax
	cmp byte [rdi], $0
	jne loop
	ret

loop:
	inc rax
	cmp byte [rdi+rax], $0
	jne loop
	ret
