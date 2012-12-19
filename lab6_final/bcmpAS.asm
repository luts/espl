section .text
	global main
	global old_main
	global compare
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
	mov 	ebx, [ebp + 12] 	; pointer to argv[0]*/
	mov 	ebx, [ebx + 4]	; value in argv[1] = "file1.txt"*/
	push romode ; "r" string
	push 	ebx ; "file1.txt"
	call 	fopen ; pointer to file1 will be in eax */
	mov 	[ebp -4], eax ; local variable file1 is now FILE *file1 = fopen( file1_name, "r");*/
	
	; fopen( file2_name, "r"); */
	mov 	ebx, [ebp + 12] 	; pointer to argv[0]*/
	mov 	ebx, [ebx + 8]	; value in argv[2] = "file2.txt"*/
	push romode ; "r" string
	push 	ebx ; "file2.txt"
	call 	fopen ; pointer to file2 will be in eax */
	mov 	[ebp -8], eax ; local variable file2 is now FILE *file2 = fopen( file2_name, "r");*/

	push 	DWORD[ebp-8] ; we need file2 for compare (var2 - void compare(FILE *file1, FILE *file2);) 
	push 	DWORD[ebp-4] ; we need file1 for compare (var1 - void compare(FILE *file1, FILE *file2);)
	call 	compare;
	; 3 last lines in every function*/
	mov 	esp, ebp
	pop 	ebp
	ret
 
;fopen:
	; 2 first lines in every function*/
;	push	ebp
;	mov 	ebp, esp
;	
;	mov 	eax, 3
;	mov 	ebx, [ebp+8] ; file1.txt / file2.txt
;	mov 	ecx, [ebp+12] ; "r"
;	int 	0x80
 ;	; 3 last lines in every function*/
;	mov 	esp, ebp
;	pop 	ebp
;	ret
;	
	
compare:
	; 3 first lines in every function*/
	push 	ebp
	mov 	ebp, esp
	sub 	esp, 12 ;local var counter, unsigned int letter1, unsigned int letter2*/   
	mov 	DWORD[ebp-12], 0; unsigned int letter2 = 0;
	mov 	DWORD[ebp-8], 0; unsigned int letter1 = 0;
	mov 	DWORD[ebp-4], 0;  int counter = 0;
.LOOP:
	; fread(&letter1, 1, 1, file1)
	;we need the address of ebp-8, but we can't write "mov ebx, ebp-8" - iligal
	; we can't write "mov ebx, [ebp-8]" --> value and not address
	; so we will use lea
	lea 	ebx, [ebp-8]; &letter1	
	push 	DWORD [ebp+8] ; file1
	push 	1	; 1
	push 	1	; 1
	push 	ebx ; file1
	call 	fread; eax will have the return value
	mov 	ecx, eax; ecx will keep the value

	; fread(&letter2, 1, 1, file2)
	;we need the address of ebp-12, but we can't write "mov ebx, ebp-12" - iligal
	; we can't write "mov ebx, [ebp-12]" --> value and not address
	; so we will use lea
	lea 	ebx, [ebp-12];&letter2	
	push 	DWORD [ebp+12] ; file2
	push 	1	; 1
	push 	1	; 1
	push 	ebx ; file1
	call 	fread; eax will have the return value
	mov 	edx, eax; edx will keep the value	
	
	; stop condition (while(fread(&letter1, 1, 1, file1) & fread(&letter2, 1, 1, file2)) {)
	test 	cl, cl ; if fread(&letter1, 1, 1, file1) == 0
	je 	.END_LOOP
	test 	dl, dl ; if fread(&letter1, 1, 1, file2) == 0
	je 	.END_LOOP
	; here is the loop
	mov 	eax, DWORD [ebp-12] ;letter2
	mov 	ebx, DWORD [ebp-8] ;letter1
	cmp 	eax, ebx 
	je    .AFTER_PRINT; if ( letter1 != letter2 ){
	;printf("byte %d -%d +%d\n",  counter+1, letter1, letter2 );
	push	eax ;letter2
	push	ebx ;letter1
	;counter+1
	mov 	ecx, DWORD [ebp-4]
	add 	ecx , 1
	push	ecx
	push	message ; "byte %d -%d +%d\n" 
	call printf
	
.AFTER_PRINT:	
	add 	DWORD [ebp-4], 1 ;counter ++;
	jmp .LOOP
	; end of loop
.END_LOOP:
 	; 3 last lines in every function*/
	mov 	esp, ebp
	pop 	ebp
	ret   

section .data
	romode 	db "r",0
	message db "byte %d -%d +%d", 0xa