global ft_atoi_base
extern ft_strlen

section .text

;add check doublon in base <- chiant
;skip whitescpace <- facile
;find sign <- facile
;find key of base <- moyen
;convert to int <- moyen pour mettre en place comme il faut
;areter quand pas dans la base <- si les retour sont bien fait c'est facile


ft_atoi_base:
	xor rax, rax
	push rdi
	push rsi
	pop rdi
	push rdi
	call check_base
	pop rdi				; clear stack if this is not done we have a segfault
	pop rdi
	ret

check_base:
	cmp rdi, 0
	je bad_end
	push rdi
	call ft_strlen
	cmp rax, 2
	jl bad_end
	xor r10, r10
	pop r10
	jmp check_base_loop


check_base_loop:
	cmp byte [r10], 0
	je true
	xor rdi, rdi
	mov dil, byte [r10]
	call is_whitespace
	cmp rax, 1
	je false
	inc r10
	jmp check_base_loop


is_whitespace:
	cmp rdi, 9
	jl false
	cmp rdi, 14
	jl true
	cmp rdi, 32
	je true
	jmp false

bad_end:
	mov rax, 0
	ret

true:
	mov rax, 1
	ret

false:
	mov rax, 0
	ret