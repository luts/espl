section .text
	global main
	global old_main
	extern compare
	extern fopen
	extern fread
	extern printf

main:
	push 	ebp
	mov 	ebp, esp
	push 	DWORD[ebp + 12]
	push 	DWORD[ebp + 8]
	call 	old_main
	mov 	esp, ebp
	pop 	ebp
	ret


old_main:
	; 3 first lines in every function*/
	push 	ebp
	mov 	ebp, esp
	sub 	esp, 8 	;local var file1 and file 2*/

	; fopen( file1_name, "r"); */
	mov 	ebx, DWORD[ebp + 12] 	; pointer to argv[0]*/
	mov 	ebx, DWORD[ebx + 4]	; value in argv[1] = "file1.txt"*/
	push romode
	push 	ebx
	call 	fopen ; pointer to file1 will be in eax */
	mov 	[ebp -4], eax ; local variable file1 is now FILE *file1 = fopen( file1_name, "r");*/
	
	; fopen( file2_name, "r"); */
	mov 	ebx, DWORD[ebp + 12] 	; pointer to argv[0]*/
	mov 	ebx, DWORD[ebx + 8]	; value in argv[2] = "file2.txt"*/
	push romode
	push 	ebx
	call 	fopen ; pointer to file2 will be in eax */
	mov 	[ebp -8], eax ; local variable file2 is now FILE *file2 = fopen( file2_name, "r");*/

	push 	DWORD[ebp-8]
	push 	DWORD[ebp-4]
	call 	compare;
	; 3 last lines in every function*/
	mov 	esp, ebp
	pop 	ebp
	ret
      

section .data
	romode 	db "r",0