global ft_strcmp

section .text

ft_strcmp:
	xor rax, rax
	xor r10, r10
	mov r10b, byte [rsi]
	cmp r10b, byte [rdi]
	je loop
	jmp end

loop:
	mov r10b, byte [rsi]
	cmp r10b, byte [rdi]
	jne end
	cmp byte [rsi], 0
	je end
	inc rsi
	inc rdi
	jmp loop

end:
	mov al, byte [rdi]
	sub rax, r10
	ret
