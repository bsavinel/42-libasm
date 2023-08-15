.globl ft_strlen

ft_strlen:
	xor %eax, %eax
	cmpb $0, (%rdi)
	jne loop
	ret

loop:
	inc %eax
	inc %rdi
	cmpb $0, (%rdi)
	jne loop
	ret
