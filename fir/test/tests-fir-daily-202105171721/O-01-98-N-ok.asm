segment	.text
align	4
global	main:function
main:
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
	push	dword 1
	push	dword 2
	pop	ecx
	sal	dword [esp], cl
	lea	eax, [ebp+8]
	push	eax
	pop	eax
	push	dword [eax]
	pop	eax
	add	dword [esp], eax
	push	dword [esp]
	lea	eax, [ebp+-4]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
_L1:
        ;; after body 
_L2:
	lea	eax, [ebp+-4]
	push	eax
	pop	eax
	push	dword [eax]
	pop	eax
	leave
	ret
segment	.text
align	4
global	_main:function
_main:
	push	ebp
	mov	ebp, esp
	sub	esp, 12
	push	dword 0
	lea	eax, [ebp+-4]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
        ;; before body 
	push	dword 3
	push	dword 2
	pop	ecx
	sal	dword [esp], cl
	pop	eax
	sub	esp, eax
	push	esp
	lea	eax, [ebp+-8]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	push	dword 3
	push	dword [esp]
	lea	eax, [ebp+-8]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 0
	push	dword 3
	pop	ecx
	sal	dword [esp], cl
	pop	eax
	add	dword [esp], eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	push	dword 2
	push	dword [esp]
	lea	eax, [ebp+-8]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 1
	push	dword 3
	pop	ecx
	sal	dword [esp], cl
	pop	eax
	add	dword [esp], eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	push	dword 61
	push	dword [esp]
	lea	eax, [ebp+-8]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 2
	push	dword 3
	pop	ecx
	sal	dword [esp], cl
	pop	eax
	add	dword [esp], eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	lea	eax, [ebp+-8]
	push	eax
	pop	eax
	push	dword [eax]
	call	main
	add	esp, 4
	push	eax
	push	dword [esp]
	lea	eax, [ebp+-12]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	lea	eax, [ebp+-12]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 1
	push	dword 3
	pop	ecx
	sal	dword [esp], cl
	pop	eax
	add	dword [esp], eax
	pop	eax
	push	dword [eax]
	call	printi
	add	esp, 4
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
extern	printi
extern	println
