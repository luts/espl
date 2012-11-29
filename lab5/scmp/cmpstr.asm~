section .text
	global cmpstr
cmpstr:  
	push	ebp
	mov	ebp, esp
.L2:
	mov	eax, DWORD [ ebp+8  ]
	mov	ebx, DWORD [ ebp+12 ]
	movzx	eax, BYTE [eax]
	movzx	ebx, BYTE [ebx]
	test	al, al
	je	.L3
	cmp al, bl
	jne	.L3

	add DWORD [ ebp+8  ], 1
	add DWORD [ ebp+12  ], 1
	jmp	.L2	


.L3:
	cmp	al, bl
	je .EQ
	jg .1BIG
	jl .2BIG

.EQ:
	mov	eax, 0
	jmp	.FINISH
.1BIG:
	mov	eax, 1
	jmp	.FINISH
.2BIG:
	mov	eax, 2
	jmp	.FINISH

.FINISH:
	mov esp, ebp
	pop ebp
	ret	
    