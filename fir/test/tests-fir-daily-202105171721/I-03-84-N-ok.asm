segment	.text
align	4
f:
	push	ebp
	mov	ebp, esp
	sub	esp, 8
	push	dword 9
	fild	dword [esp]
	sub	esp, byte 4
	fstp	qword [esp]
	lea	eax, [ebp+-8]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	pop	eax
	mov	[ecx+4], eax
        ;; before body 
_L1:
        ;; after body 
_L2:
	lea	eax, [ebp+-8]
	push	eax
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
	fld	qword [esp]
	add	esp, byte 8
	leave
	ret
segment	.text
align	4
global	_main:function
_main:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
	push	dword 0
	lea	eax, [ebp+-4]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
        ;; before body 
	push	dword 10
	fild	dword [esp]
	sub	esp, byte 4
	fstp	qword [esp]
	call	f
	add	esp, 8
	sub	esp, byte 8
	fstp	qword [esp]
	call	printd
	add	esp, 8
	push	dword 2
	fild	dword [esp]
	sub	esp, byte 4
	fstp	qword [esp]
	call	f
	add	esp, 8
	sub	esp, byte 8
	fstp	qword [esp]
	call	printd
	add	esp, 8
	call	println
_L3:
        ;; after body 
_L4:
	lea	eax, [ebp+-4]
	push	eax
	pop	eax
	push	dword [eax]
	pop	eax
	leave
	ret
extern	printd
extern	println
