segment	.text
align	4
f:
	push	ebp
	mov	ebp, esp
	sub	esp, 8
        ;; before body 
	lea	eax, [ebp+8]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword [esp]
	lea	eax, [ebp+-4]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	push	dword 4
	lea	eax, [ebp+-8]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
_L1:
	lea	eax, [ebp+-4]
	push	eax
	pop	eax
	push	dword [eax]
	call	printi
	add	esp, 4
        ;; after body 
_L2:
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
	push	dword 3
	call	f
	add	esp, 4
	add	esp, 0
	push	dword 8
	call	f
	add	esp, 4
	add	esp, 0
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
