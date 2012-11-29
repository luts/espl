section .text

global _start
global read
global write
global open
global close
global strlen

extern main
_start:
	call main
	mov ebx,eax
	mov eax,1
	int 0x80
	mov eax, esp
	add eax, 4
	push eax
	push DWORD [esp+4]

read:
	mov eax, 3
	mov ebx, [esp+4]
	mov ecx, [esp+8]
	mov edx, [esp+12]
	int 0x80
	ret
write:
	mov eax, 4
	mov ebx, [esp+4]
	mov ecx, [esp+8]
	mov edx, [esp+12]
	int 0x80
	ret
open:
	mov eax, 5
	mov ebx, [esp+4]
	mov ecx, [esp+8]
	mov edx, [esp+12]
	int 0x80
	ret
close:
	mov eax, 6
	mov ebx, [esp+4]
	mov ecx, [esp+8]
	mov edx, [esp+12]
	int 0x80
	ret
strlen:
	mov eax, 0
.L1:
	mov ebx, DWORD [ebp+8]
	test bl, bl
	jne .L2
	ret

.L2:
	add eax, 1
	add DWORD [ebp+8], 1
	jmp .L1




